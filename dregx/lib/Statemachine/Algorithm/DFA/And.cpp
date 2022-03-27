#include "dregx/Statemachine/Algorithm/DFA/And.h"
#include "dregx/Statemachine/Algorithm/DFA/Type/ProductionConstructionState.h"

dregx::statemachine::Flag dregx::statemachine::dfa::And::Flags(Statemachine* lhs, Statemachine* rhs)
{
	const Flag flags(
		Flag::IsDfa(true),
		Flag::ContainsCycles(lhs->flags.containsCycles || rhs->flags.containsCycles),
		Flag::EmbeddedAcceptState(lhs->flags.containsCycles || rhs->flags.containsCycles),
		Flag::AllTransitionDeterminized(false));

	return flags;
}

void dregx::statemachine::dfa::And::SinkState(State* state, Statemachine* lhs, Statemachine* rhs)
{
	lhs->sinkState = state;
}

void dregx::statemachine::dfa::And::StartState(State* state, Statemachine* lhs, Statemachine* rhs)
{
	lhs->SetStartState(state);
}

void dregx::statemachine::dfa::And::Operation(Statemachine* lhs, Statemachine* rhs)
{
	const auto& ourStates = lhs->GetStates();
	const auto& theirStates = rhs->GetStates();

	std::vector<std::unique_ptr<type::ProductionConstructionState>> productStates;
	std::map<std::tuple<State*, State*>, type::ProductionConstructionState*>
		mapStatesWithProductConstructionState;

	for (const auto& ourState : ourStates)
	{
		for (const auto& theirState : theirStates)
		{
			auto newProductConstructionState = std::make_unique<type::ProductionConstructionState>(
				ourState.get(), theirState.get());
			mapStatesWithProductConstructionState.insert(
				{{ourState.get(), theirState.get()}, newProductConstructionState.get()});

			productStates.push_back(std::move(newProductConstructionState));
		}
	}

	std::map<type::ProductionConstructionState*, State*> mapPCSwithStates;
	std::vector<std::unique_ptr<State>> newStates;
	std::vector<std::unique_ptr<Transition>> newTransitions;
	State* newStartState = nullptr;
	std::vector<State*> newAcceptedStates;
	std::vector<State*> newNonAcceptedStates;
	for (auto& productState : productStates)
	{
		auto newState = std::make_unique<State>();
		newState->SetFlavors(productState->GetFlavors());
		if (productState->IsStart())
		{
			newState->SetStart(true);
			newStartState = newState.get();
		}
		if (productState->IsAcceptAND())
		{
			newState->SetAccept(true);
			newAcceptedStates.push_back(newState.get());
		}
		else
		{
			newNonAcceptedStates.push_back(newState.get());
		}

		mapPCSwithStates.insert({productState.get(), newState.get()});

		newStates.push_back(std::move(newState));
	}

	for (auto& productionState : productStates)
	{
		auto* thisState = mapPCSwithStates.find(productionState.get())->second;
		auto conditionalMap = productionState->And();
		for (auto& [conditional, transitions] : conditionalMap)
		{
			auto* const firstTransition = std::get<0>(transitions);
			auto* const secondTransition = std::get<1>(transitions);
			State* firstState = firstTransition->GetOutState();
			State* secondState = secondTransition->GetOutState();
			auto* otherProductState =
				mapStatesWithProductConstructionState.find({firstState, secondState})->second;
			auto* otherState = mapPCSwithStates.find(otherProductState)->second;
			auto newTransition = std::make_unique<Transition>(thisState, conditional, otherState);

			newTransitions.push_back(std::move(newTransition));
		}
	}

	SinkState(nullptr, lhs, rhs);
	StartState(newStartState, lhs, rhs);
	lhs->acceptedStates = std::move(newAcceptedStates);
	lhs->nonAcceptedStates = std::move(newNonAcceptedStates);
	lhs->states = std::move(newStates);
	lhs->transitions = std::move(newTransitions);
}

bool dregx::statemachine::dfa::And::CheckPreconditions(Statemachine* lhs, Statemachine* rhs)
{
	return false;
}
