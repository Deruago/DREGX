#include "dregx/Statemachine/Algorithm/DFA/Or.h"
#include "dregx/Statemachine/Algorithm/DFA/Type/ProductionConstructionState.h"

dregx::statemachine::Flag dregx::statemachine::dfa::Or::Flags(Statemachine* lhs, Statemachine* rhs)
{
	const Flag flags(
		Flag::IsDfa(true),
		Flag::ContainsCycles(lhs->flags.containsCycles || rhs->flags.containsCycles),
		Flag::EmbeddedAcceptState(lhs->flags.containsCycles || rhs->flags.containsCycles),
		Flag::AllTransitionDeterminized(false));

	return flags;
}

void dregx::statemachine::dfa::Or::SinkState(State* state, Statemachine* lhs, Statemachine* rhs)
{
	lhs->sinkState = state;
}

void dregx::statemachine::dfa::Or::StartState(State* state, Statemachine* lhs, Statemachine* rhs)
{
	lhs->SetStartState(state);
}

void dregx::statemachine::dfa::Or::Operation(Statemachine* lhs, Statemachine* rhs)
{
	OptimizedOperation(lhs, rhs);
}

bool dregx::statemachine::dfa::Or::CheckPreconditions(Statemachine* lhs, Statemachine* rhs)
{
	return (lhs->flags.IsDFA == true) && (rhs->flags.IsDFA == true);
}

void dregx::statemachine::dfa::Or::OptimizedOperation(Statemachine* lhs, Statemachine* rhs)
{
	lhs->UpdateIndex();
	rhs->UpdateIndex();

	const std::size_t stateArrayMaxSize =
		lhs->states.size() * rhs->states.size() + lhs->states.size() + rhs->states.size();

	// [ [lhs, rhs], [lhs, null], [null, rhs] ]
	std::vector<std::unique_ptr<State>> stateArray;
	stateArray.reserve(stateArrayMaxSize);
	std::vector<std::unique_ptr<Transition>> newTransitions;
	std::vector<State*> newAcceptedStates;
	std::vector<State*> newNonAcceptedStates;

	for (std::size_t i = 0; i < stateArrayMaxSize; i++)
	{
		stateArray.push_back(std::make_unique<State>());
	}

	// [lhs: index, rhs: index]
	auto GetStateViaIndex = [&](std::size_t lhsIndex, std::size_t rhsIndex) {
		return stateArray[lhsIndex * rhs->states.size() + rhsIndex].get();
	};

	// [lhs: index, rhs: null]
	auto GetNullStateViaLhsIndex = [&](std::size_t lhsIndex) {
		return stateArray[lhs->states.size() * rhs->states.size() + lhsIndex].get();
	};

	// [lhs: null, rhs: index]
	auto GetNullStateViaRhsIndex = [&](std::size_t rhsIndex) {
		return stateArray[lhs->states.size() * rhs->states.size() + lhs->states.size() + rhsIndex]
			.get();
	};

	auto ApplyMetaData = [&](State* state, State* lhsState = nullptr, State* rhsState = nullptr) {
		if (lhsState != nullptr)
		{
			state->AddFlavors(lhsState->GetFlavors());
		}
		if (rhsState != nullptr)
		{
			state->AddFlavors(rhsState->GetFlavors());
		}

		if ((lhsState != nullptr && lhsState->IsAcceptState()) ||
			(rhsState != nullptr && rhsState->IsAcceptState()))
		{
			state->SetAccept(true);
			newAcceptedStates.push_back(state);
		}
		else
		{
			newNonAcceptedStates.push_back(state);
		}

		if (lhsState != nullptr && rhsState != nullptr && lhsState->IsStartState() &&
			rhsState->IsStartState())
		{
			state->SetStart(true);
			StartState(state, lhs, rhs);
		}
	};

	for (std::size_t lhsIndex = 0; lhsIndex < lhs->states.size(); lhsIndex++)
	{
		auto* const lhsState = lhs->states[lhsIndex].get();
		auto* state = GetNullStateViaLhsIndex(lhsIndex);
		ApplyMetaData(state, lhsState, nullptr);

		for (auto* transition : lhsState->GetOutTransitions())
		{
			auto* targetState = GetNullStateViaLhsIndex(transition->GetOutState()->GetIndex());
			auto newTransition =
				std::make_unique<Transition>(state, transition->GetConditions(), targetState);
			newTransitions.push_back(std::move(newTransition));
		}
	}
	for (std::size_t rhsIndex = 0; rhsIndex < rhs->states.size(); rhsIndex++)
	{
		auto* const rhsState = rhs->states[rhsIndex].get();
		auto* state = GetNullStateViaRhsIndex(rhsIndex);
		ApplyMetaData(state, nullptr, rhsState);

		for (auto* transition : rhsState->GetOutTransitions())
		{
			auto* targetState = GetNullStateViaRhsIndex(transition->GetOutState()->GetIndex());
			auto newTransition =
				std::make_unique<Transition>(state, transition->GetConditions(), targetState);
			newTransitions.push_back(std::move(newTransition));
		}
	}

	for (std::size_t lhsIndex = 0; lhsIndex < lhs->states.size(); lhsIndex++)
	{
		for (std::size_t rhsIndex = 0; rhsIndex < rhs->states.size(); rhsIndex++)
		{
			auto* currentState = GetStateViaIndex(lhsIndex, rhsIndex);
			auto* const lhsState = lhs->states[lhsIndex].get();
			auto* const rhsState = rhs->states[rhsIndex].get();
			auto* state = GetStateViaIndex(lhsIndex, rhsIndex);

			ApplyMetaData(state, lhsState, rhsState);

			// a b c d f g
			// a c d g
			std::size_t lhsTransitionIndex = 0;
			std::size_t rhsTransitionIndex = 0;
			auto lhsFinished = [&]() {
				return lhsTransitionIndex == lhsState->GetOutTransitions().size();
			};
			auto rhsFinished = [&]() {
				return rhsTransitionIndex == rhsState->GetOutTransitions().size();
			};
			while (!(lhsFinished() && rhsFinished()))
			{
				if (lhsFinished() && !rhsFinished())
				{
					for (; rhsTransitionIndex < rhsState->GetOutTransitions().size();
						 rhsTransitionIndex++)
					{
						// lhs == empty
						// rhs == outstate
						auto* transition = rhsState->GetOutTransitions()[rhsTransitionIndex];
						auto* nullState =
							GetNullStateViaRhsIndex(transition->GetOutState()->GetIndex());
						auto newTransition = std::make_unique<Transition>(
							currentState, transition->GetConditions(), nullState);
						newTransitions.push_back(std::move(newTransition));
					}
					break;
				}

				if (!lhsFinished() && rhsFinished())
				{
					for (; lhsTransitionIndex < lhsState->GetOutTransitions().size();
						 lhsTransitionIndex++)
					{
						// lhs == outstate
						// rhs == empty
						auto* transition = lhsState->GetOutTransitions()[lhsTransitionIndex];
						auto* nullState =
							GetNullStateViaLhsIndex(transition->GetOutState()->GetIndex());
						auto newTransition = std::make_unique<Transition>(
							currentState, transition->GetConditions(), nullState);
						newTransitions.push_back(std::move(newTransition));
					}
					break;
				}

				Transition* currentLhs = lhsState->GetOutTransitions()[lhsTransitionIndex];
				Transition* currentRhs = rhsState->GetOutTransitions()[rhsTransitionIndex];

				if (currentLhs->GetConditions() ==
					currentRhs->GetConditions()) // i.e. both have same transition cond
				{
					auto lhsOutState = currentLhs->GetOutState()->GetIndex();
					auto rhsOutState = currentRhs->GetOutState()->GetIndex();

					auto newTransition =
						std::make_unique<Transition>(currentState, currentLhs->GetConditions(),
													 GetStateViaIndex(lhsOutState, rhsOutState));
					newTransitions.push_back(std::move(newTransition));

					lhsTransitionIndex++;
					rhsTransitionIndex++;
				}
				if (currentLhs->GetConditions() <
					currentRhs->GetConditions()) // i.e. rhs does not have same transition cond
				{
					auto* nullState =
						GetNullStateViaLhsIndex(currentLhs->GetOutState()->GetIndex());
					auto newTransition = std::make_unique<Transition>(
						currentState, currentLhs->GetConditions(), nullState);
					newTransitions.push_back(std::move(newTransition));

					lhsTransitionIndex++;
				}
				if (currentRhs->GetConditions() <
					currentLhs->GetConditions()) // i.e. lhs does not have same transition cond
				{
					auto* nullState =
						GetNullStateViaRhsIndex(currentRhs->GetOutState()->GetIndex());
					auto newTransition = std::make_unique<Transition>(
						currentState, currentRhs->GetConditions(), nullState);
					newTransitions.push_back(std::move(newTransition));

					rhsTransitionIndex++;
				}
			}
		}
	}

	SinkState(nullptr, lhs, rhs);
	lhs->acceptedStates = std::move(newAcceptedStates);
	lhs->nonAcceptedStates = std::move(newNonAcceptedStates);
	lhs->states = std::move(stateArray);
	lhs->transitions = std::move(newTransitions);
}
