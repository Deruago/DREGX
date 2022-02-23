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

	auto newStartState = std::make_unique<State>();
	auto lhsStartState = GetStartState();
	auto rhsStartState = rhs.GetStartState();

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
		rhs.RemoveState(rhsState.get());
	}

	for (auto& rhsTransition : rhs.transitions)
	{
		AddTransition(std::move(rhsTransition));
		rhs.RemoveTransition(rhsTransition.get());
	}

	ToDFA();
}

// Connect all lhs.acceptstates with rhs.startstate using empty transition
void dregx::statemachine::Statemachine::Concatenate(Statemachine& rhs)
{
	if (&rhs == this)
	{
		return;
	}

	auto rhsStartState = rhs.GetStartState();
	for (auto acceptState : GetAcceptStates())
	{
		auto linkWithRhsStartState =
			std::make_unique<Transition>(acceptState, std::vector<Conditional>{}, rhsStartState);
		AddTransition(std::move(linkWithRhsStartState));
	}

	for (auto& rhsState : rhs.states)
	{
		AddState(std::move(rhsState));
		rhs.RemoveState(rhsState.get());
	}

	for (auto& rhsTransition : rhs.transitions)
	{
		AddTransition(std::move(rhsTransition));
		rhs.RemoveTransition(rhsTransition.get());
	}

	ToDFA();
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

	if (extension.GetLowerBound() == 0)
	{
		GetStartState()->SetAccept(true);
	}

	// If the upper bound is infinite
	// Cycle should be embedded
	if (extension.IsUpperBoundInfinite())
	{
		// create new start state which is accepting
		// relink all acceptstates with new start state

		auto newStartState = std::make_unique<State>();
		newStartState->SetStart(true);
		newStartState->SetAccept(true);
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

		ToDFA();
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
		graph += transition->GetConditions()[0].GetCharacter();
		graph += "\"];\n";
	}
	for (auto& state : GetStates())
	{
		graph += std::to_string(mapStateWithIndex.find(state.get())->second);

		if (state->IsAcceptState())
		{
			graph += " [label = \"Accept State: ";
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

void dregx::statemachine::Statemachine::ToDFA()
{
	// Using powerset construction convert NFA to DFA
}
