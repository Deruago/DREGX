#include "dregx/Statemachine/Statemachine.h"
#include <algorithm>
#include <limits>
#include <map>
#include <memory>
#include <set>
#include <stdexcept>
#include <utility>

// Given two DFA construct NFA
// By creating new start state, with empty transitions to both DFA start states
void dregx::statemachine::Statemachine::Or(Statemachine& rhs)
{
	if (&rhs == this)
	{
		return;
	}

	if (IsDFA && rhs.IsDFA)
	{
		IsDFA = true;
		ProductionConstructionOR(rhs);
	}
	else
	{
		IsDFA = false;
		auto newStartState = std::make_unique<State>();
		auto lhsStartState = GetStartState();
		auto rhsStartState = rhs.GetStartState();

		newStartState->SetStart(true);
		lhsStartState->SetStart(false);
		rhsStartState->SetStart(false);

		auto linkWithLhsStartState = std::make_unique<Transition>(
			newStartState.get(), std::vector<Conditional>{}, lhsStartState);
		auto linkWithRhsStartState = std::make_unique<Transition>(
			newStartState.get(), std::vector<Conditional>{}, rhsStartState);

		AddState(std::move(newStartState));
		AddTransition(std::move(linkWithLhsStartState));
		AddTransition(std::move(linkWithRhsStartState));

		for (auto& rhsState : rhs.states)
		{
			AddState(std::move(rhsState));
		}

		for (auto& rhsTransition : rhs.transitions)
		{
			AddTransition(std::move(rhsTransition));
		}
	}

	rhs.states.clear();
	rhs.transitions.clear();
}

// Connect all lhs.acceptstates with rhs.startstate using empty transition
void dregx::statemachine::Statemachine::Concatenate(Statemachine& rhs)
{
	if (&rhs == this)
	{
		return;
	}

	if (IsDFA && !containsCycles && rhs.IsDFA && !rhs.containsCycles && false)
	{
	}
	else
	{
		auto rhsStartState = rhs.GetStartState();
		rhsStartState->SetStart(false);
		for (auto acceptState : GetAcceptStates())
		{
			auto linkWithRhsStartState = std::make_unique<Transition>(
				acceptState, std::vector<Conditional>{}, rhsStartState);
			AddTransition(std::move(linkWithRhsStartState));
			acceptState->SetAccept(false);
		}

		for (auto& rhsState : rhs.states)
		{
			AddState(std::move(rhsState));
		}

		for (auto& rhsTransition : rhs.transitions)
		{
			AddTransition(std::move(rhsTransition));
		}

		rhs.states.clear();
		rhs.transitions.clear();

		IsDFA = false;
	}
}

std::unique_ptr<dregx::statemachine::Statemachine> dregx::statemachine::Statemachine::Copy() const
{
	auto newStatemachine = std::make_unique<Statemachine>();

	std::map<State*, State*> mapExistingStateWithCopiedState;

	for (const auto& existingState : states)
	{
		auto copyState = std::make_unique<State>();
		copyState->SetAccept(existingState->IsAcceptState());
		copyState->SetStart(existingState->IsStartState());
		mapExistingStateWithCopiedState.insert({existingState.get(), copyState.get()});
		newStatemachine->AddState(std::move(copyState));
	}

	for (const auto& existingTransition : transitions)
	{
		auto in = mapExistingStateWithCopiedState.find(existingTransition->GetInState());
		auto out = mapExistingStateWithCopiedState.find(existingTransition->GetOutState());

		if (in == mapExistingStateWithCopiedState.end())
		{
			throw std::logic_error("In state is not contained in statemachine.");
		}
		if (out == mapExistingStateWithCopiedState.end())
		{
			throw std::logic_error("Out state is not contained in statemachine.");
		}
		auto copyTransition = std::make_unique<Transition>(
			in->second, existingTransition->GetConditions(), out->second);
		newStatemachine->AddTransition(std::move(copyTransition));
	}

	return std::move(newStatemachine);
}

dregx::statemachine::Statemachine& dregx::statemachine::Statemachine::operator|(Statemachine& rhs)
{
	if (&rhs == this)
	{
		return *this;
	}

	Or(rhs);

	return *this;
}

dregx::statemachine::Statemachine& dregx::statemachine::Statemachine::operator&(Statemachine& rhs)
{
	if (&rhs == this)
	{
		return *this;
	}

	Concatenate(rhs);

	return *this;
}

void dregx::statemachine::Statemachine::AddState(std::unique_ptr<State> state)
{
	states.push_back(std::move(state));
}

void dregx::statemachine::Statemachine::AddTransition(std::unique_ptr<Transition> transition)
{
	transitions.push_back(std::move(transition));
}

void dregx::statemachine::Statemachine::SetStates(std::vector<std::unique_ptr<State>> states_)
{
	states = std::move(states_);
}

void dregx::statemachine::Statemachine::SetTransitions(
	std::vector<std::unique_ptr<Transition>> transitions_)
{
	transitions = std::move(transitions_);
}

void dregx::statemachine::Statemachine::Extend(const ir::Extension& extension)
{
	// Extending some DFA is trivial
	// Upper bound specifies the copies of the current DFA.
	// Lower bound specifies when the start state of some copy is an accepting state.

	std::vector<std::unique_ptr<Statemachine>> copiedStatemachines;
	for (std::size_t i = 1; i < extension.GetUpperBound(); i++)
	{
		auto copiedStatemachine = Copy();
		if (i >= extension.GetLowerBound())
		{
			copiedStatemachine->GetStartState()->SetAccept(true);
		}
		copiedStatemachines.push_back(std::move(copiedStatemachine));
	}

	for (auto& copiedStatemachine : copiedStatemachines)
	{
		Concatenate(*copiedStatemachine);
	}

	// If the upper bound is infinite
	// Cycle should be embedded
	if (extension.IsUpperBoundInfinite())
	{
		// create new start state which is accepting
		// relink all acceptstates with new start state

		auto newStartState = std::make_unique<State>();
		newStartState->SetStart(true);
		auto oldStartState = GetStartState();
		oldStartState->SetStart(false);
		auto linkWithOldStartState = std::make_unique<Transition>(
			newStartState.get(), std::vector<Conditional>{}, oldStartState);
		for (auto acceptState : GetAcceptStates())
		{
			auto linkAcceptStateWithOldStartState = std::make_unique<Transition>(
				acceptState, std::vector<Conditional>{}, oldStartState);
			AddTransition(std::move(linkAcceptStateWithOldStartState));
		}
		AddTransition(std::move(linkWithOldStartState));
		AddState(std::move(newStartState));

		containsCycles = true;
		IsDFA = false;
	}

	if (extension.GetLowerBound() == 0)
	{
		GetStartState()->SetAccept(true);
	}
}

void dregx::statemachine::Statemachine::RemoveTransition(Transition* transition)
{
	for (auto iter = std::cbegin(transitions); iter != std::cend(transitions); ++iter)
	{
		if (iter->get() == transition)
		{
			transitions.erase(iter);
			return;
		}
	}
}

void dregx::statemachine::Statemachine::RemoveState(State* state)
{
	if (state == nullptr)
	{
		return;
	}

	for (auto iter = std::cbegin(states); iter != std::cend(states); ++iter)
	{
		if (iter->get() == state)
		{
			for (auto* inTransition : (*iter)->GetInTransitions())
			{
				RemoveTransition(inTransition);
			}
			for (auto* outTransition : (*iter)->GetOutTransitions())
			{
				RemoveTransition(outTransition);
			}
			states.erase(iter);
			return;
		}
	}
}

const std::vector<std::unique_ptr<dregx::statemachine::State>>&
dregx::statemachine::Statemachine::GetStates() const
{
	return states;
}

std::vector<dregx::statemachine::State*> dregx::statemachine::Statemachine::GetStates(
	std::vector<std::vector<Conditional>> inConditions,
	std::vector<std::vector<Conditional>> outConditions) const
{
	std::vector<dregx::statemachine::State*> outStates;

	for (auto& state : GetStates())
	{
		if (state->HasConditions(inConditions, outConditions))
		{
			outStates.push_back(state.get());
		}
	}

	return outStates;
}

const std::vector<std::unique_ptr<dregx::statemachine::Transition>>&
dregx::statemachine::Statemachine::GetTransitions() const
{
	return transitions;
}

dregx::statemachine::State* dregx::statemachine::Statemachine::GetStartState() const
{
	for (auto& state : states)
	{
		if (state->IsStartState())
		{
			return state.get();
		}
	}

	return nullptr;
}

std::vector<dregx::statemachine::State*> dregx::statemachine::Statemachine::GetAcceptStates() const
{
	std::vector<dregx::statemachine::State*> acceptStates;
	for (auto& state : states)
	{
		if (state->IsAcceptState())
		{
			acceptStates.push_back(state.get());
		}
	}

	return acceptStates;
}

#include <iostream>

std::string dregx::statemachine::Statemachine::Print() const
{
	std::string graph = "digraph DFA {\n";
	std::map<State*, std::size_t> mapStateWithIndex;

	for (auto& state : GetStates())
	{
		mapStateWithIndex.insert({state.get(), mapStateWithIndex.size()});
	}

	for (auto& transition : GetTransitions())
	{
		graph += std::to_string(mapStateWithIndex.find(transition->GetInState())->second);
		graph += " -> ";
		graph += std::to_string(mapStateWithIndex.find(transition->GetOutState())->second);
		graph += " [label = \"";
		if (transition->GetConditions().empty())
		{
			graph += "";
		}
		else
		{
			graph += transition->GetConditions()[0].GetCharacter();
		}
		graph += "\"];\n";
	}
	for (auto& state : GetStates())
	{
		graph += std::to_string(mapStateWithIndex.find(state.get())->second);

		if (state->IsAcceptState() && !state->IsStartState())
		{
			graph += " [label = \"Accept State: ";
		}
		else if (state->IsAcceptState() && state->IsStartState())
		{
			graph += " [label = \"Start Accept State: ";
		}
		else if (state->IsStartState())
		{
			graph += " [label = \"Start State: ";
		}
		else
		{
			graph += " [label = \"Inter State: ";
		}
		graph += std::to_string(mapStateWithIndex.find(state.get())->second);
		graph += "\"]";
		graph += ";\n";
	}

	return graph + "}\n";
}

void dregx::statemachine::Statemachine::GetStatesToSource(const std::vector<State*>& states,
														  std::set<State*>& embeddedStates)
{
	for (auto& state : states)
	{
		GetStatesToSource(state, embeddedStates);
	}
}

void dregx::statemachine::Statemachine::GetStatesToSource(const State* state,
														  std::set<State*>& embeddedStates)
{
	for (auto& inTransition : state->GetInTransitions())
	{
		auto inState = inTransition->GetInState();
		if (inState == nullptr)
		{
			continue;
		}

		const auto iter = embeddedStates.find(inState);
		if (iter == embeddedStates.end())
		{
			embeddedStates.insert({inState});
			GetStatesToSource(inState, embeddedStates);
		}
	}
}

dregx::statemachine::TransitionTable dregx::statemachine::Statemachine::ToTransitionTable()
{
	TransitionTable table;
	std::map<State*, std::size_t> mapStateWithIndex;

	std::vector<State*> unCategorizedStates = {GetStartState()};
	while (!unCategorizedStates.empty())
	{
		auto currentUncategorizedState = *unCategorizedStates.begin();
		unCategorizedStates.erase(unCategorizedStates.begin());

		if (mapStateWithIndex.find(currentUncategorizedState) == mapStateWithIndex.end())
		{
			mapStateWithIndex.insert({currentUncategorizedState, mapStateWithIndex.size()});
		}
		table.table.emplace_back();
		table.acceptingState.emplace_back();

		for (auto outTransition : currentUncategorizedState->GetOutTransitions())
		{
			if (mapStateWithIndex.find(outTransition->GetOutState()) == mapStateWithIndex.end())
			{
				mapStateWithIndex.insert({outTransition->GetOutState(), mapStateWithIndex.size()});
				unCategorizedStates.push_back(outTransition->GetOutState());
			}
		}
	}

	for (auto& [state, index] : mapStateWithIndex)
	{
		table.acceptingState[index] = state->IsAcceptState();

		for (auto* outTransition : state->GetOutTransitions())
		{
			table.table[index].insert(
				{outTransition->GetConditions()[0].GetCharacter(),
				 mapStateWithIndex.find(outTransition->GetOutState())->second});
		}
	}

	return table;
}

struct ProductionConstructionState
{
	dregx::statemachine::State* our;
	dregx::statemachine::State* their;

	ProductionConstructionState(dregx::statemachine::State* our_,
								dregx::statemachine::State* their_)
		: our(our_),
		  their(their_)
	{
	}

	bool IsStart = false;

	bool IsAccept()
	{
		return (our != nullptr && our->IsAcceptState()) ||
			   (their != nullptr && their->IsAcceptState());
	}

	std::map<std::vector<dregx::statemachine::Conditional>,
			 std::tuple<dregx::statemachine::Transition*, dregx::statemachine::Transition*>>
	Or()
	{
		std::map<std::vector<dregx::statemachine::Conditional>,
				 std::tuple<dregx::statemachine::Transition*, dregx::statemachine::Transition*>>
			mapConditionalWithTuple;

		if (our != nullptr)
		{
			for (auto transition : our->GetOutTransitions())
			{
				mapConditionalWithTuple.insert(
					{transition->GetConditions(), {transition, nullptr}});
			}
		}
		if (their != nullptr)
		{
			for (auto transition : their->GetOutTransitions())
			{
				auto iter = mapConditionalWithTuple.find(transition->GetConditions());
				if (iter == mapConditionalWithTuple.end())
				{
					mapConditionalWithTuple.insert(
						{transition->GetConditions(), {nullptr, transition}});
				}
				else
				{
					std::get<1>(iter->second) = transition;
				}
			}
		}

		return mapConditionalWithTuple;
	}
};

void dregx::statemachine::Statemachine::ProductionConstructionOR(Statemachine& rhs)
{
	auto& ourStates = GetStates();
	auto& theirStates = rhs.GetStates();

	std::vector<std::unique_ptr<ProductionConstructionState>> productStates;
	std::map<std::tuple<State*, State*>, ProductionConstructionState*>
		mapStatesWithProductConstructionState;
	bool first = true;
	for (auto& ourState : ourStates)
	{
		for (auto& theirState : theirStates)
		{
			auto newProductConstructionState =
				std::make_unique<ProductionConstructionState>(ourState.get(), theirState.get());
			mapStatesWithProductConstructionState.insert(
				{{ourState.get(), theirState.get()}, newProductConstructionState.get()});

			if (first)
			{
				newProductConstructionState->IsStart = true;
				first = false;
			}

			productStates.push_back(std::move(newProductConstructionState));
		}
	}

	for (auto& ourState : ourStates)
	{
		auto newProductConstructionState =
			std::make_unique<ProductionConstructionState>(ourState.get(), nullptr);
		mapStatesWithProductConstructionState.insert(
			{{ourState.get(), nullptr}, newProductConstructionState.get()});

		productStates.push_back(std::move(newProductConstructionState));
	}
	for (auto& theirState : theirStates)
	{
		auto newProductConstructionState =
			std::make_unique<ProductionConstructionState>(nullptr, theirState.get());
		mapStatesWithProductConstructionState.insert(
			{{nullptr, theirState.get()}, newProductConstructionState.get()});

		productStates.push_back(std::move(newProductConstructionState));
	}

	std::map<ProductionConstructionState*, State*> mapPCSwithStates;
	std::vector<std::unique_ptr<State>> newStates;
	std::vector<std::unique_ptr<Transition>> newTransitions;
	for (auto& productState : productStates)
	{
		auto newState = std::make_unique<State>();
		newState->SetStart(productState->IsStart);
		newState->SetAccept(productState->IsAccept());

		mapPCSwithStates.insert({productState.get(), newState.get()});

		newStates.push_back(std::move(newState));
	}

	for (auto& productionState : productStates)
	{
		auto thisState = mapPCSwithStates.find(productionState.get())->second;
		auto conditionalMap = productionState->Or();
		for (auto& [conditional, transitions] : conditionalMap)
		{
			auto firstTransition = std::get<0>(transitions);
			auto secondTransition = std::get<1>(transitions);
			State* firstState = nullptr;
			State* secondState = nullptr;
			if (firstTransition != nullptr)
			{
				firstState = firstTransition->GetOutState();
			}
			if (secondTransition != nullptr)
			{
				secondState = secondTransition->GetOutState();
			}
			auto otherProductState =
				mapStatesWithProductConstructionState.find({firstState, secondState})->second;
			auto otherState = mapPCSwithStates.find(otherProductState)->second;
			auto newTransition = std::make_unique<Transition>(thisState, conditional, otherState);

			newTransitions.push_back(std::move(newTransition));
		}
	}

	this->states = std::move(newStates);
	this->transitions = std::move(newTransitions);
}

void dregx::statemachine::Statemachine::OptimizeFinalAcceptStates()
{
	State* sharedAcceptState = nullptr;
	for (auto acceptState : GetAcceptStates())
	{
		if (acceptState->GetOutTransitions().empty() && sharedAcceptState == nullptr)
		{
			sharedAcceptState = acceptState;
		}
		else if (acceptState->GetOutTransitions().empty())
		{
			for (auto linkedTransition : acceptState->GetInTransitions())
			{
				auto newTransition = std::make_unique<Transition>(linkedTransition->GetInState(),
																  linkedTransition->GetConditions(),
																  sharedAcceptState);
				AddTransition(std::move(newTransition));

				RemoveTransition(linkedTransition);
			}

			RemoveState(acceptState);
		}
	}
}

struct PowersetState;

struct PowersetTransition
{
	PowersetState* in;
	PowersetState* out;
	std::vector<dregx::statemachine::Conditional> conditional;

	PowersetTransition(PowersetState* in_, PowersetState* out_,
					   std::vector<dregx::statemachine::Conditional> conditional_);
};

struct PowersetState
{
	std::set<dregx::statemachine::State*> states;
	std::map<std::vector<dregx::statemachine::Conditional>, PowersetTransition*> transitions;

	bool startState = false;

	bool IsAccept() const
	{
		for (auto state : states)
		{
			if (state->IsAcceptState())
			{
				return true;
			}
		}

		return false;
	}
};

PowersetTransition::PowersetTransition(PowersetState* in_, PowersetState* out_,
									   std::vector<dregx::statemachine::Conditional> conditional_)
	: in(in_),
	  out(out_),
	  conditional(conditional_)
{
	std::pair<std::vector<dregx::statemachine::Conditional>, PowersetTransition*> pair_;
	pair_.first = conditional_;
	pair_.second = this;
	in->transitions.insert(pair_);
	out->transitions.insert(pair_);
}

void dregx::statemachine::Statemachine::ToDFA()
{
	// Using powerset construction convert NFA to DFA
	std::vector<PowersetState*> unFinishedpowersetStates;
	std::map<std::set<State*>, std::unique_ptr<PowersetState>> allPowerStates;
	std::vector<std::unique_ptr<PowersetTransition>> allTransitions;

	auto startState = GetStartState();
	auto startPowerState = std::make_unique<PowersetState>();
	startPowerState->startState = true;
	startPowerState->states = startState->GetConnectedStatesWithConditional({});
	startPowerState->states.insert(startState);
	unFinishedpowersetStates.push_back(startPowerState.get());

	std::pair<std::set<State*>, std::unique_ptr<PowersetState>> startPowerState_;
	startPowerState_.first = {startPowerState->states};
	startPowerState_.second = std::move(startPowerState);
	allPowerStates.insert(std::move(startPowerState_));

	while (!unFinishedpowersetStates.empty())
	{
		auto currentPowerState = *unFinishedpowersetStates.begin();
		unFinishedpowersetStates.erase(unFinishedpowersetStates.begin());

		std::set<std::vector<Conditional>> conditionals;
		for (auto state : currentPowerState->states)
		{
			for (auto transition : state->GetOutTransitions())
			{
				if (transition->GetConditions().empty())
				{
					continue;
				}

				conditionals.insert(transition->GetConditions());
			}
		}

		for (auto conditional : conditionals)
		{
			std::set<State*> outStates;
			for (auto state : currentPowerState->states)
			{
				auto outTransition = state->GetOutTransitionWithSameCondition(conditional);
				if (outTransition == nullptr)
				{
					continue;
				}
				outStates.insert(outTransition->GetOutState());

				for (auto outStateConnected :
					 outTransition->GetOutState()->GetConnectedStatesWithConditional({}))
				{
					outStates.insert(outStateConnected);
				}
			}
			const auto iter = allPowerStates.find(outStates);
			PowersetState* outPowerState;
			if (iter == allPowerStates.end())
			{
				auto newPowerState = std::make_unique<PowersetState>();
				newPowerState->states = outStates;
				outPowerState = newPowerState.get();

				unFinishedpowersetStates.push_back(newPowerState.get());

				std::pair<std::set<State*>, std::unique_ptr<PowersetState>> newPowerStateSetEntry;
				newPowerStateSetEntry.first = {newPowerState->states};
				newPowerStateSetEntry.second = std::move(newPowerState);
				allPowerStates.insert(std::move(newPowerStateSetEntry));
			}
			else
			{
				outPowerState = iter->second.get();
			}

			auto newPowersetTransition =
				std::make_unique<PowersetTransition>(currentPowerState, outPowerState, conditional);

			allTransitions.push_back(std::move(newPowersetTransition));
		}
	}

	std::map<PowersetState*, State*> mapPowerToState;
	std::vector<std::unique_ptr<State>> newDfaStates;
	std::vector<std::unique_ptr<Transition>> newDfaTransitions;
	for (auto& [originalStates, powerState] : allPowerStates)
	{
		auto newDfaState = std::make_unique<State>();
		newDfaState->SetStart(powerState->startState);
		newDfaState->SetAccept(powerState->IsAccept());

		mapPowerToState.insert({powerState.get(), newDfaState.get()});
		newDfaStates.push_back(std::move(newDfaState));
	}

	for (auto& transition : allTransitions)
	{
		auto inState = mapPowerToState.find(transition->in)->second;
		auto outState = mapPowerToState.find(transition->out)->second;
		auto newTransition =
			std::make_unique<Transition>(inState, transition->conditional, outState);
		newDfaTransitions.push_back(std::move(newTransition));
	}

	this->states = std::move(newDfaStates);
	this->transitions = std::move(newDfaTransitions);

	IsDFA = true;
}
