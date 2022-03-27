#include "dregx/Statemachine/Algorithm/DFA/Concatenate.h"

dregx::statemachine::Flag dregx::statemachine::dfa::Concatenate::Flags(Statemachine* lhs,
																	   Statemachine* rhs)
{
	const Flag flags(
		Flag::IsDfa(true),
		Flag::ContainsCycles(lhs->flags.containsCycles || rhs->flags.containsCycles),
		Flag::EmbeddedAcceptState(lhs->flags.containsCycles || rhs->flags.containsCycles),
		Flag::AllTransitionDeterminized(false));

	return flags;
}

void dregx::statemachine::dfa::Concatenate::SinkState(State* state, Statemachine* lhs,
													  Statemachine* rhs)
{
	// Untouched
}

void dregx::statemachine::dfa::Concatenate::StartState(State* state, Statemachine* lhs,
													   Statemachine* rhs)
{
	// Untouched
}

void dregx::statemachine::dfa::Concatenate::Operation(Statemachine* lhs, Statemachine* rhs)
{
	// This utilizes an optimized algorithm
	// The algorithm will merge the DFA at every accept state.
	// The merge will prefer existing transitions and only create new transitions
	// if no transition exists.
	std::size_t depth = std::numeric_limits<std::size_t>::max();
	std::tuple<std::size_t, std::set<State*>> deleteTillStates;
	for (auto& acceptState : lhs->GetAcceptStates())
	{
		std::size_t localDepth = 1;
		std::vector<std::tuple<State*, State*>> unconcatenatedStates;
		acceptState->SetAccept(rhs->GetStartState()->IsAcceptState());
		unconcatenatedStates.emplace_back(acceptState, rhs->GetStartState());
		while (!unconcatenatedStates.empty())
		{
			localDepth++;
			auto currentUnconcatenatedState = *unconcatenatedStates.begin();
			unconcatenatedStates.erase(unconcatenatedStates.begin());

			State* lhsState = std::get<0>(currentUnconcatenatedState);
			State* rhsState = std::get<1>(currentUnconcatenatedState);

			for (auto* transition : rhsState->GetOutTransitions())
			{
				if (lhsState->DoesOutTransitionExistWithSameCondition(transition))
				{
					// Each overlapping transition must be remapped to a new state.
					// All transitions of this transition must be
					// relinked with the new state
					// recurse...
					// If not implemented embedded accept states
					// can not benefit from this optimized algorithm

					auto* lhsStateOutTransitionState =
						lhsState->GetOutTransitionWithSameCondition(transition)->GetOutState();
					unconcatenatedStates.emplace_back(lhsStateOutTransitionState,
													  transition->GetOutState());
				}
				else
				{
					auto newTransition = std::make_unique<Transition>(
						lhsState, transition->GetConditions(), transition->GetOutState());
					lhs->AddTransition(std::move(newTransition));

					if (localDepth <= depth)
					{
						std::get<0>(deleteTillStates) = localDepth;
						std::get<1>(deleteTillStates).clear();
						std::get<1>(deleteTillStates).insert(transition->GetOutState());
						depth = localDepth;
					}
					else if (localDepth == depth)
					{
						std::get<1>(deleteTillStates).insert(transition->GetOutState());
					}
				}
			}
			if (rhsState->GetOutTransitions().empty())
			{
				lhsState->SetAccept(true);
			}
		}
	}

	std::set<State*> toBeDeletedStates;
	std::set<State*> nextDeletionSources;
	std::set<State*> currentDeleteSourceStates = std::get<1>(deleteTillStates);
	while (!currentDeleteSourceStates.empty() && depth > 0)
	{
		auto* deleteState = *currentDeleteSourceStates.begin();
		currentDeleteSourceStates.erase(currentDeleteSourceStates.begin());

		// As there are no cycles
		// Each in transition eventually goes to start state.

		for (auto* inTransition : deleteState->GetInTransitions())
		{
			toBeDeletedStates.insert(inTransition->GetInState());
			nextDeletionSources.insert(inTransition->GetInState());
			rhs->RemoveTransition(inTransition);
		}

		if (currentDeleteSourceStates.empty())
		{
			depth--;
			currentDeleteSourceStates = nextDeletionSources;
			nextDeletionSources.clear();
		}
	}

	for (auto* deleteState : toBeDeletedStates)
	{
		rhs->RemoveState(deleteState);
	}

	for (auto& state : rhs->states)
	{
		// Any sink state is set to false
		state->SetSink(false);
		lhs->AddState(std::move(state));
	}

	for (auto& transition : rhs->transitions)
	{
		lhs->AddTransition(std::move(transition));
	}

	rhs->states.clear();
	rhs->transitions.clear();
}

bool dregx::statemachine::dfa::Concatenate::CheckPreconditions(Statemachine* lhs, Statemachine* rhs)
{
	return lhs->flags.IsDFA && !lhs->flags.containsCycles && rhs->flags.IsDFA &&
		   !rhs->flags.containsCycles && !lhs->flags.embeddedAcceptState &&
		   !rhs->flags.embeddedAcceptState;
}
