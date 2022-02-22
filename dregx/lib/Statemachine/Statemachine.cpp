#include "dregx/Statemachine/Statemachine.h"
#include <algorithm>
#include <limits>
#include <map>
#include <memory>
#include <set>
#include <stdexcept>
#include <utility>

void dregx::statemachine::Statemachine::Or(Statemachine& rhs)
{
	if (&rhs == this)
	{
		return;
	}

	// Does not support extension cases

	// In case there are no cycles in the Statemachine
	// Each state logic of the rhs.DFA is merged with this.DFA

	// a -> b -> c OR a -> d -> e
	//      -> b -> c
	// a -<
	//      -> d -> e

	for (auto* currentTransition : rhs.GetStartState()->GetOutTransitions())
	{
		OrSpecificState(this->GetStartState(), rhs.GetStartState(), currentTransition, rhs);
	}
	rhs.RemoveState(rhs.GetStartState());

	for (auto& existingState : rhs.states)
	{
		AddState(std::move(existingState));
	}

	for (auto& existingTransition : rhs.transitions)
	{
		AddTransition(std::move(existingTransition));
	}

	rhs.transitions.clear();
	rhs.states.clear();
}

void dregx::statemachine::Statemachine::Concatenate(Statemachine& rhs)
{
	if (&rhs == this)
	{
		return;
	}
	// Does not support extension cases

	// In case there are no cycles in the Statemachine
	// Each transition of the rhs.startstate can be set to each accept states

	// If start state is accepted, our accepted state will still be accepted
	const bool ourAcceptStateStillAccepted = rhs.GetStartState()->IsAcceptState();

	std::tuple<std::size_t, std::vector<State*>> linkedStates = {
		std::numeric_limits<std::size_t>::max(), {}};

	for (auto& acceptState : GetAcceptStates())
	{
		for (auto* currentTransition : rhs.GetStartState()->GetOutTransitions())
		{
			acceptState->SetAccept(ourAcceptStateStillAccepted);
			ConcatenateSpecificState(acceptState, rhs.GetStartState(), currentTransition, rhs, 0,
									 linkedStates);
		}
	}

	std::set<State*> removeStates;
	GetStatesToSource(std::get<std::vector<State*>>(linkedStates), removeStates);
	for (auto& removeState : removeStates)
	{
		rhs.RemoveState(removeState);
	}

	for (auto& existingState : rhs.states)
	{
		AddState(std::move(existingState));
	}

	for (auto& existingTransition : rhs.transitions)
	{
		AddTransition(std::move(existingTransition));
	}

	rhs.transitions.clear();
	rhs.states.clear();
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
	}
}

void dregx::statemachine::Statemachine::RemoveTransition(Transition* transition)
{
	for (auto iter = std::cbegin(transitions); iter != std::cend(transitions); iter++)
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
	for (auto iter = std::cbegin(states); iter != std::cend(states); iter++)
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

std::string dregx::statemachine::Statemachine::Print() const
{
	std::string graph = "digraph DFA {\n";

	for (auto& transition : GetTransitions())
	{
		graph += std::to_string((std::size_t)transition->GetInState());
		graph += " -> ";
		graph += std::to_string((std::size_t)transition->GetOutState());
		graph += " [label = \"";
		graph += transition->GetConditions()[0].GetCharacter();
		graph += "\"];\n";
	}

	for (auto& state : GetStates())
	{
		graph += std::to_string((std::size_t)state.get());

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
		graph += std::to_string((std::size_t)state.get());
		graph += "\"]";
		graph += ";\n";
	}

	return graph + "}\n";
}

// Follow our transitions for each rhs.transition.
void dregx::statemachine::Statemachine::OrSpecificState(State* state, State* getStartState,
														Transition* transition, Statemachine& rhs)
{
	if (state->DoesOutTransitionExistWithSameCondition(transition))
	{
		// There exists a route to equal state logic.
		// Follow the path,
		auto* ourTransition = state->GetOutTransitionWithSameCondition(transition);
		state = ourTransition->GetOutState();
		auto* const newRhsState = transition->GetOutState();

		// Transition is no longer further required
		rhs.RemoveTransition(transition);

		if (newRhsState->IsAcceptState())
		{
			// We reached the end of the state logic.
			// The current state is an accepting state.
			state->SetAccept(true);
		}
		for (auto* newTransition : newRhsState->GetOutTransitions())
		{
			OrSpecificState(state, newRhsState, newTransition, rhs);
		}

		// The state was covered fully
		// We do not require the state anymore
		rhs.RemoveState(newRhsState);
	}
	else
	{
		// The state reference state logic not captured in our DFA
		// Copy the transition and relink to our DFA

		auto newTransition = std::make_unique<Transition>(state, transition->GetConditions(),
														  transition->GetOutState());
		AddTransition(std::move(newTransition));

		rhs.RemoveTransition(transition);
	}
}

void dregx::statemachine::Statemachine::ConcatenateSpecificState(
	State* state, State* rhsState, Transition* transition, Statemachine& rhs, std::size_t depth,
	std::tuple<std::size_t, std::vector<State*>>& linkStates)
{
	if (state->DoesOutTransitionExistWithSameCondition(transition))
	{
		// There exists a route to equal state logic.
		// Follow the path,
		auto* ourTransition = state->GetOutTransitionWithSameCondition(transition);
		state = ourTransition->GetOutState();
		auto* const newRhsState = transition->GetOutState();

		for (auto* newTransition : newRhsState->GetOutTransitions())
		{
			ConcatenateSpecificState(state, newRhsState, newTransition, rhs, depth + 1, linkStates);
		}
	}
	else
	{
		// The state reference state logic not captured in our DFA
		// Copy the transition and relink to our DFA

		auto newTransition = std::make_unique<Transition>(state, transition->GetConditions(),
														  transition->GetOutState());

		if (depth == std::get<std::size_t>(linkStates))
		{
			std::get<std::vector<State*>>(linkStates).push_back(transition->GetOutState());
		}
		else if (depth <= std::get<std::size_t>(linkStates))
		{
			std::get<std::vector<State*>>(linkStates).clear();
			std::get<std::size_t>(linkStates) = depth;
			std::get<std::vector<State*>>(linkStates).push_back(transition->GetOutState());
		}

		// Current state should be linked with rest of the state logic
		AddTransition(std::move(newTransition));
	}
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
