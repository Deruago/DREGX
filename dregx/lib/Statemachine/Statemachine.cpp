#include "dregx/Statemachine/Statemachine.h"
#include <algorithm>
#include <utility>

dregx::statemachine::Statemachine::~Statemachine()
{
	for (auto* transition : transitions)
	{
		delete transition;
	}

	for (auto* state : states)
	{
		delete state;
	}
}

void dregx::statemachine::Statemachine::Or(Statemachine& rhs)
{
	if (&rhs == this)
	{
		return;
	}

	// Does not support extension cases

	// In case there are no cycles in the Statemachine
	// Each transition of the rhs.startstate can be set to each accept states

	// a -> b -> c OR a -> d -> e
	//      -> b -> c
	// a -<
	//      -> d -> e

	for (auto* currentTransition : rhs.GetStartState()->GetOutTransitions())
	{
		OrSpecificState(this->GetStartState(), rhs.GetStartState(), currentTransition, rhs);
	}

	for (auto* existingState : rhs.GetStates())
	{
		AddState(existingState);
	}

	for (auto* existingTransition : rhs.GetTransitions())
	{
		AddTransition(existingTransition);
	}

	delete rhs.GetStartState();
	rhs.SetTransitions({});
	rhs.SetStates({});
}

void dregx::statemachine::Statemachine::Concatenate(Statemachine& rhs)
{
	if (&rhs == this)
	{
		return;
	}
	auto rhs_startStateOutTransitions = rhs.GetStartState()->GetOutTransitions();
	auto rhs_startStateInTransitions = rhs.GetStartState()->GetInTransitions();

	// Does not support extension cases

	// In case there are no cycles in the Statemachine
	// Each transition of the rhs.startstate can be set to each accept states
	for (auto* acceptState : GetAcceptStates())
	{
		acceptState->SetAccept(false);
		for (auto* transition : rhs_startStateOutTransitions)
		{
			auto* const newTransition =
				new Transition(acceptState, transition->GetConditions(), transition->GetOutState());
			AddTransition(newTransition);
		}
		for (auto* transition : rhs_startStateInTransitions)
		{
			auto* const newTransition =
				new Transition(transition->GetInState(), transition->GetConditions(), acceptState);
			AddTransition(newTransition);
		}
	}

	for (auto* newState : rhs.GetStates())
	{
		if (newState == rhs.GetStartState())
		{
			continue;
		}

		AddState(newState);
	}

	for (auto* newTransition : rhs.GetTransitions())
	{
		if (newTransition->GetInState() == rhs.GetStartState() ||
			newTransition->GetOutState() == rhs.GetStartState())
		{
			continue;
		}

		bool exist = false;
		for (auto* existingTransition : transitions)
		{
			if (newTransition == existingTransition)
			{
				exist = true;
				break;
			}
		}
		if (exist)
		{
			continue;
		}
		AddTransition(newTransition);
	}

	for (auto* transition : rhs_startStateOutTransitions)
	{
		delete transition;
	}

	for (auto* transition : rhs_startStateInTransitions)
	{
		delete transition;
	}

	rhs.GetStartState()->SetInTransitions({});
	rhs.GetStartState()->SetOutTransitions({});
	rhs.transitions.clear();
	rhs.states.clear();

	delete rhs.GetStartState();
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

void dregx::statemachine::Statemachine::AddState(State* state)
{
	states.push_back(state);
}

void dregx::statemachine::Statemachine::AddTransition(Transition* transition)
{
	transitions.push_back(transition);
}

void dregx::statemachine::Statemachine::SetStates(std::vector<State*> states_)
{
	states = std::move(states_);
}

void dregx::statemachine::Statemachine::SetTransitions(std::vector<Transition*> transitions_)
{
	transitions = std::move(transitions_);
}

void dregx::statemachine::Statemachine::Extend(const ir::Extension& extension)
{
	if (extension.GetLowerBound() == 1 && extension.GetUpperBound() == 1)
	{
		return; // Default statemachine
	}

	// Not yet implemented
}

void dregx::statemachine::Statemachine::RemoveTransition(Transition* transition)
{
	const auto iter = std::find(std::cbegin(transitions), std::cend(transitions), transition);
	if (iter == std::cend(transitions))
	{
		return;
	}

	transitions.erase(iter);
}

void dregx::statemachine::Statemachine::RemoveState(State* state)
{
	const auto iter = std::find(std::cbegin(states), std::cend(states), state);
	if (iter == std::cend(states))
	{
		return;
	}

	states.erase(iter);
}

std::vector<dregx::statemachine::State*> dregx::statemachine::Statemachine::GetStates() const
{
	return states;
}

std::vector<dregx::statemachine::State*> dregx::statemachine::Statemachine::GetStates(
	std::vector<std::vector<Conditional>> inConditions,
	std::vector<std::vector<Conditional>> outConditions) const
{
	std::vector<dregx::statemachine::State*> outStates;

	for (auto state : GetStates())
	{
		if (state->HasConditions(inConditions, outConditions))
		{
			outStates.push_back(state);
		}
	}

	return outStates;
}

std::vector<dregx::statemachine::Transition*>
dregx::statemachine::Statemachine::GetTransitions() const
{
	return transitions;
}

dregx::statemachine::State* dregx::statemachine::Statemachine::GetStartState() const
{
	for (auto* state : states)
	{
		if (state->IsStartState())
		{
			return state;
		}
	}

	return nullptr;
}

std::vector<dregx::statemachine::State*> dregx::statemachine::Statemachine::GetAcceptStates() const
{
	std::vector<dregx::statemachine::State*> acceptStates;
	for (auto* state : states)
	{
		if (state->IsAcceptState())
		{
			acceptStates.push_back(state);
		}
	}

	return acceptStates;
}

std::string dregx::statemachine::Statemachine::Print() const
{
	std::string graph = "digraph DFA {\n";

	for (auto transition : GetTransitions())
	{
		graph += std::to_string((std::size_t)transition->GetInState());
		graph += " -> ";
		graph += std::to_string((std::size_t)transition->GetOutState());
		graph += " [label = \"";
		graph += transition->GetConditions()[0].GetCharacter();
		graph += "\"];\n";
	}

	for (auto state : GetStates())
	{
		graph += std::to_string((std::size_t)state);

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
		graph += std::to_string((std::size_t)state);
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
		delete transition;

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
		rhs.RemoveState(getStartState);
		delete getStartState;
	}
	else
	{
		// The state reference state logic not captured in our DFA
		// Copy the transition and relink to our DFA

		auto newTransition =
			new Transition(state, transition->GetConditions(), transition->GetOutState());
		AddTransition(newTransition);

		rhs.RemoveTransition(transition);
		rhs.RemoveState(getStartState);
		delete transition;
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
				auto newTransition =
					new Transition(linkedTransition->GetInState(),
								   linkedTransition->GetConditions(), sharedAcceptState);
				AddTransition(newTransition);

				RemoveTransition(linkedTransition);
				delete linkedTransition;
			}

			RemoveState(acceptState);
			delete acceptState;
		}
	}
}
