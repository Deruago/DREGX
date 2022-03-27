#include "dregx/Statemachine/Statemachine.h"
#include "dregx/Statemachine/Algorithm/DFA/And.h"
#include "dregx/Statemachine/Algorithm/DFA/Concatenate.h"
#include "dregx/Statemachine/Algorithm/DFA/Or.h"
#include "dregx/Statemachine/Algorithm/NDFA/Concatenate.h"
#include "dregx/Statemachine/Algorithm/NDFA/Or.h"
#include <algorithm>
#include <iostream>
#include <limits>
#include <map>
#include <memory>
#include <set>
#include <stdexcept>
#include <utility>

/*
 * Each algorithm must implement the following logic:
 * - Flag logic
 * - Sink State Handling
 * - Start State Handling
 * - Flavor Handling
 */

// Given two DFA construct NFA
// By creating new start state, with empty transitions to both DFA start states
void dregx::statemachine::Statemachine::Or(Statemachine& rhs)
{
	if (&rhs == this)
	{
		return;
	}

	auto dfaOr = dfa::Or();
	auto ndfaOr = ndfa::Or();

	if (dfaOr.CheckPreconditions(this, &rhs))
	{
		dfaOr.Execute(this, rhs);
		if (states.size() > 50)
		{
			Minimize();
		}
	}
	else if (ndfaOr.CheckPreconditions(this, &rhs))
	{
		ndfaOr.Execute(this, rhs);
	}
	else
	{
		throw std::logic_error("No suitable OR operation algorithm.");
	}

	rhs.states.clear();
	rhs.transitions.clear();
}

void dregx::statemachine::Statemachine::And(Statemachine& rhs)
{
	// Currently Product Construction only works for DFA
	// There are options for NFAs, but not yet implemented.
	if (!flags.IsDFA)
	{
		ToDFA();
	}

	if (!rhs.flags.IsDFA)
	{
		rhs.ToDFA();
	}

	auto dfaAnd = dfa::And();
	dfaAnd.Execute(this, rhs);
}

// Connect all lhs.acceptstates with rhs.startstate using empty transition
void dregx::statemachine::Statemachine::Concatenate(Statemachine& rhs)
{
	if (&rhs == this)
	{
		return;
	}

	auto dfaConcatenate = dfa::Concatenate();
	auto ndfaConcatenate = ndfa::Concatenate();

	if (dfaConcatenate.CheckPreconditions(this, &rhs))
	{
		dfaConcatenate.Execute(this, rhs);
	}
	else if (ndfaConcatenate.CheckPreconditions(this, &rhs))
	{
		ndfaConcatenate.Execute(this, rhs);
	}
	else
	{
		throw std::logic_error("No suitable Concatenate operation algorithm.");
	}
}

bool dregx::statemachine::Statemachine::Equal(const Statemachine& rhs) const
{
	// Simple DFS search which compares transitions between lhs and rhs.
	std::set<State*> ourVisitedStates = {
		this->GetStartState()}; // If we know the depth of each state we can compare depth instead
	std::set<State*> theirVisitedStates = {rhs.GetStartState()};
	std::vector<State*> ourStates = {this->GetStartState()};
	std::vector<State*> theirStates = {rhs.GetStartState()};

	while (!ourStates.empty() && !theirStates.empty())
	{
		auto* const ourState = *ourStates.begin();
		ourStates.erase(ourStates.begin());
		auto* const theirState = *theirStates.begin();
		theirStates.erase(theirStates.begin());

		if (!(ourState->IsAcceptState() == theirState->IsAcceptState()))
		{
			return false;
		}

		if (ourState->GetOutTransitions().size() != theirState->GetOutTransitions().size() ||
			ourState->GetInTransitions().size() != theirState->GetInTransitions().size())
		{
			return false;
		}

		for (const auto& ourTransition : ourState->GetOutTransitions())
		{
			auto* const theirTransition =
				theirState->GetOutTransitionWithSameCondition(ourTransition->GetConditions());
			if (theirTransition == nullptr)
			{
				return false;
			}

			auto ourIter = ourVisitedStates.find(ourTransition->GetOutState());
			auto theirIter = theirVisitedStates.find(theirTransition->GetOutState());
			if (ourIter == ourVisitedStates.end() && theirIter == theirVisitedStates.end())
			{
				ourVisitedStates.insert(ourTransition->GetOutState());
				theirVisitedStates.insert(theirTransition->GetOutState());
				ourStates.push_back(ourTransition->GetOutState());
				theirStates.push_back(theirTransition->GetOutState());
			}
			else if (ourIter != ourVisitedStates.end() && theirIter != theirVisitedStates.end())
			{
				continue;
			}
			else
			{
				return false;
			}
		}
	}

	return ourStates.empty() && theirStates.empty();
}

bool dregx::statemachine::Statemachine::InEqual(const Statemachine& rhs) const
{
	return !Equal(rhs);
}

std::unique_ptr<dregx::statemachine::Statemachine> dregx::statemachine::Statemachine::Copy() const
{
	auto newStatemachine = std::make_unique<Statemachine>();

	std::map<State*, State*> mapExistingStateWithCopiedState;
	State* copyStartState = nullptr;
	std::vector<State*> newAcceptedStates;
	std::vector<State*> newNonAcceptedStates;
	for (const auto& existingState : states)
	{
		auto copyState = std::make_unique<State>();
		copyState->SetFlavors(existingState->GetFlavors());
		if (existingState->IsAcceptState())
		{
			copyState->SetAccept(true);
			newAcceptedStates.push_back(copyState.get());
		}
		else
		{
			newNonAcceptedStates.push_back(copyState.get());
		}

		if (existingState->IsStartState())
		{
			copyState->SetStart(true);
			newStatemachine->startState = copyState.get();
		}
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

	newStatemachine->flags = this->flags;
	newStatemachine->acceptedStates = std::move(newAcceptedStates);
	newStatemachine->nonAcceptedStates = std::move(newNonAcceptedStates);
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

bool dregx::statemachine::Statemachine::operator==(const Statemachine& rhs) const
{
	if (&rhs == this)
	{
		return true;
	}

	auto lhsCopy = this->Copy();
	auto rhsCopy = rhs.Copy();

	lhsCopy->Minimize();
	rhsCopy->Minimize();

	return lhsCopy->Equal(*rhsCopy);
}

bool dregx::statemachine::Statemachine::operator==(Statemachine& rhs)
{
	this->Minimize();
	rhs.Minimize();

	return Equal(rhs);
}

bool dregx::statemachine::Statemachine::operator!=(Statemachine& rhs)
{
	return !(*this == rhs);
}

bool dregx::statemachine::Statemachine::operator!=(const Statemachine& rhs) const
{
	return !(*this == rhs);
}

void dregx::statemachine::Statemachine::AddState(std::unique_ptr<State> state)
{
	if (state->IsAcceptState())
	{
		acceptedStates.push_back(state.get());
	}
	else
	{
		nonAcceptedStates.push_back(state.get());
	}
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
			flags.embeddedAcceptState = true;
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
		auto* oldStartState = GetStartState();
		oldStartState->SetStart(false);
		auto linkWithOldStartState = std::make_unique<Transition>(
			newStartState.get(), std::vector<Conditional>{}, oldStartState);
		for (auto* acceptState : GetAcceptStates())
		{
			auto linkAcceptStateWithOldStartState = std::make_unique<Transition>(
				acceptState, std::vector<Conditional>{}, oldStartState);
			AddTransition(std::move(linkAcceptStateWithOldStartState));
		}
		SetStartState(newStartState.get());
		AddTransition(std::move(linkWithOldStartState));
		AddState(std::move(newStartState));

		flags.containsCycles = true;
		flags.IsDFA = false;
	}

	if (extension.GetLowerBound() == 0)
	{
		flags.embeddedAcceptState = true;
		GetStartState()->SetAccept(true);
	}
}

void dregx::statemachine::Statemachine::Group(const std::set<std::string>& set)
{
	for (auto acceptingState : GetAcceptStates())
	{
		acceptingState->SetFlavors(set);
	}
}

void dregx::statemachine::Statemachine::SetStartState(State* startState_)
{
	startState = startState_;
}

void dregx::statemachine::Statemachine::UpdateDepth()
{
	// For each transition
	// If transition is unvisited insert in unvisited states
	// And assign depth + 1
	// Otherwise
	// Check if the output state depth is more than our depth + 1
	// If True update with lower depth
	std::map<State*, std::size_t> mapStateWithDepth = {{GetStartState(), 0}};
	std::set<State*> unVisitedStates = {GetStartState()};

	while (!unVisitedStates.empty())
	{
		auto* const currentState = *unVisitedStates.begin();
		unVisitedStates.erase(unVisitedStates.begin());
		const auto ourDepth = mapStateWithDepth.find(currentState)->second;

		for (const auto* const transition : currentState->GetOutTransitions())
		{
			auto* const outState = transition->GetOutState();
			auto iter = mapStateWithDepth.find(outState);
			if (iter == mapStateWithDepth.end())
			{
				unVisitedStates.insert(outState);
				mapStateWithDepth.insert({outState, ourDepth + 1});
			}
			else
			{
				if (iter->second > (ourDepth + 1))
				{
					iter->second = ourDepth + 1;
				}
			}
		}
	}

	for (auto& [state, depth] : mapStateWithDepth)
	{
		state->SetDepth(depth);
	}
}

void dregx::statemachine::Statemachine::UpdateIndex()
{
	std::size_t index = 0;
	for (auto& state : states)
	{
		state->SetIndex(index);
		index++;
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

	for (const auto& state : GetStates())
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
	if (startState != nullptr)
	{
		return startState;
	}

	for (const auto& state : states)
	{
		if (state->IsStartState())
		{
			return state.get();
		}
	}

	return nullptr;
}

dregx::statemachine::State* dregx::statemachine::Statemachine::GetSinkState() const
{
	if (sinkState != nullptr)
	{
		return sinkState;
	}

	for (const auto& state : states)
	{
		if (state->IsSinkState())
		{
			return state.get();
		}
	}

	return nullptr;
}

std::vector<dregx::statemachine::State*> dregx::statemachine::Statemachine::GetAcceptStates() const
{
	std::vector<dregx::statemachine::State*> acceptStates;
	for (const auto& state : states)
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
	std::map<State*, std::size_t> mapStateWithIndex;

	for (const auto& state : GetStates())
	{
		mapStateWithIndex.insert({state.get(), mapStateWithIndex.size()});
	}

	for (const auto& transition : GetTransitions())
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
			const auto character = transition->GetConditions()[0].GetCharacter()[0];
			switch (character)
			{
			case '"': {
				graph += "\\\"";
				break;
			}
			case '\\': {
				graph += "\\\\";
				break;
			}
			case '\n': {
				graph += "\\n";
				break;
			}
			case '\r': {
				graph += "\\r";
				break;
			}
			case '\t': {
				graph += "\\t";
				break;
			}
			case '\b': {
				graph += "\\b";
				break;
			}
			case '\v': {
				graph += "\\v";
				break;
			}
			case '\f': {
				graph += "\\f";
				break;
			}
			default: {
				graph += character;
				break;
			}
			}
		}
		graph += "\"];\n";
	}
	for (const auto& state : GetStates())
	{
		graph += std::to_string(mapStateWithIndex.find(state.get())->second);

		graph += " [label = \"State";

		if (state->IsStartState())
		{
			graph += " Start";
		}
		if (state->IsSinkState())
		{
			graph += " Sink";
		}
		if (state->IsAcceptState())
		{
			graph += " Accept";
		}
		graph += ": ";

		graph += std::to_string(mapStateWithIndex.find(state.get())->second);
		graph += "\"]";
		graph += ";\n";
	}

	return graph + "}\n";
}

void dregx::statemachine::Statemachine::GetStatesToSource(const std::vector<State*>& states,
														  std::set<State*>& embeddedStates)
{
	for (const auto& state : states)
	{
		GetStatesToSource(state, embeddedStates);
	}
}

void dregx::statemachine::Statemachine::GetStatesToSource(const State* state,
														  std::set<State*>& embeddedStates)
{
	for (auto& inTransition : state->GetInTransitions())
	{
		auto* inState = inTransition->GetInState();
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
	if (!flags.allTransitionDeterminized)
	{
		DeterminizeAllTransitions();
	}

	TransitionTable table;
	std::map<State*, std::size_t> mapStateWithIndex;

	std::vector<State*> unCategorizedStates = {GetStartState()};
	while (!unCategorizedStates.empty())
	{
		auto* currentUncategorizedState = *unCategorizedStates.begin();
		unCategorizedStates.erase(unCategorizedStates.begin());

		if (mapStateWithIndex.find(currentUncategorizedState) == mapStateWithIndex.end())
		{
			mapStateWithIndex.insert({currentUncategorizedState, mapStateWithIndex.size()});
		}
		table.table.emplace_back();
		table.acceptingState.emplace_back();
		table.flavorState.emplace_back();

		for (auto* outTransition : currentUncategorizedState->GetOutTransitions())
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
		table.flavorState[index] = state->GetFlavors();

		for (auto* outTransition : state->GetOutTransitions())
		{
			table.table[index].insert(
				{outTransition->GetConditions()[0].GetCharacter(),
				 mapStateWithIndex.find(outTransition->GetOutState())->second});
		}
	}

	return table;
}

void dregx::statemachine::Statemachine::FillSinkState()
{
	if (sinkState == nullptr)
	{
		auto newSinkState = std::make_unique<State>();
		newSinkState->SetSink(true);
		sinkState = newSinkState.get();
		AddState(std::move(newSinkState));
	}

	for (auto condition : GetAlphabet())
	{
		if (sinkState->DoesOutTransitionExistWithSameCondition(condition))
		{
			continue;
		}

		// Only new transitions
		auto newTransition = std::make_unique<Transition>(sinkState, condition, sinkState);
		AddTransition(std::move(newTransition));
	}
}

void dregx::statemachine::Statemachine::OptimizeFinalAcceptStates()
{
	State* sharedAcceptState = nullptr;
	for (auto* acceptState : GetAcceptStates())
	{
		if (acceptState->GetOutTransitions().empty() && sharedAcceptState == nullptr)
		{
			sharedAcceptState = acceptState;
		}
		else if (acceptState->GetOutTransitions().empty())
		{
			for (auto* linkedTransition : acceptState->GetInTransitions())
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
		for (auto* state : states)
		{
			if (state->IsAcceptState())
			{
				return true;
			}
		}

		return false;
	}

	std::set<std::string> GetFlavors() const
	{
		std::set<std::string> flavors;
		for (auto state : states)
		{
			for (auto flavor : state->GetFlavors())
			{
				flavors.insert(flavor);
			}
		}
		return flavors;
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
	if (flags.IsDFA)
	{
		return; // It is already a DFA
	}

	// Using powerset construction convert NFA to DFA
	std::vector<PowersetState*> unFinishedpowersetStates;
	std::map<std::set<State*>, std::unique_ptr<PowersetState>> allPowerStates;
	std::vector<std::unique_ptr<PowersetTransition>> allTransitions;

	auto* startState = GetStartState();
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
		auto* currentPowerState = *unFinishedpowersetStates.begin();
		unFinishedpowersetStates.erase(unFinishedpowersetStates.begin());

		std::set<std::vector<Conditional>> conditionals;
		for (auto* state : currentPowerState->states)
		{
			for (auto* transition : state->GetOutTransitions())
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
			for (auto* state : currentPowerState->states)
			{
				auto* outTransition = state->GetOutTransitionWithSameCondition(conditional);
				if (outTransition == nullptr)
				{
					continue;
				}
				outStates.insert(outTransition->GetOutState());

				for (auto* outStateConnected :
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
	State* newStartState = nullptr;
	for (auto& [originalStates, powerState] : allPowerStates)
	{
		auto newDfaState = std::make_unique<State>();
		newDfaState->SetFlavors(powerState->GetFlavors());
		if (powerState->startState)
		{
			newDfaState->SetStart(true);
			newStartState = newDfaState.get();
		}
		newDfaState->SetAccept(powerState->IsAccept());

		mapPowerToState.insert({powerState.get(), newDfaState.get()});
		newDfaStates.push_back(std::move(newDfaState));
	}

	for (auto& transition : allTransitions)
	{
		auto* inState = mapPowerToState.find(transition->in)->second;
		auto* outState = mapPowerToState.find(transition->out)->second;
		auto newTransition =
			std::make_unique<Transition>(inState, transition->conditional, outState);
		newDfaTransitions.push_back(std::move(newTransition));
	}

	SetStartState(newStartState);
	this->states = std::move(newDfaStates);
	this->transitions = std::move(newDfaTransitions);

	flags.IsDFA = true;
}

void dregx::statemachine::Statemachine::Minimize(bool splitFlavoredAcceptStates)
{
	ToDFA();

	if (!flags.allTransitionDeterminized)
	{
		DeterminizeAllTransitions();
	}

	std::vector<std::set<State*>> acceptedPartitions;
	std::set<State*> nonAcceptedPartition;
	std::map<std::set<std::string>, std::size_t> mapFlavorWithIndex;
	for (auto& state : states)
	{
		if (state->IsAcceptState())
		{
			std::size_t index = 0;
			if (splitFlavoredAcceptStates)
			{
				auto iter = mapFlavorWithIndex.find(state->GetFlavors());
				if (iter == mapFlavorWithIndex.end())
				{
					index = mapFlavorWithIndex.size();
					mapFlavorWithIndex.insert({state->GetFlavors(), index});
					acceptedPartitions.emplace_back();
				}
				else
				{
					index = iter->second;
				}
			}
			acceptedPartitions[index].insert(state.get());
		}
		else
		{
			nonAcceptedPartition.insert(state.get());
		}
	}

	std::vector<std::set<State*>> lastEquivalenceSets;
	lastEquivalenceSets.push_back(std::move(nonAcceptedPartition));
	for (auto acceptedPartition : acceptedPartitions)
	{
		lastEquivalenceSets.push_back(std::move(acceptedPartition));
	}

	std::vector<std::set<State*>> equivalenceSets = lastEquivalenceSets;
	std::vector<std::set<State*>> nextEquivalenceSets;
	bool success = false; // If True we have the minimal partitions

	const auto alphabet = GetAlphabet();
	while (!equivalenceSets.empty())
	{
		auto currentSet = *equivalenceSets.begin();
		equivalenceSets.erase(equivalenceSets.begin());

		if (currentSet.size() == 1)
		{
			nextEquivalenceSets.push_back(currentSet);
		}
		else
		{
			std::set<State*> currentPartition;
			std::set<State*> otherPartition;

			for (const auto& alpha : alphabet)
			{
				currentPartition.clear();

				std::size_t mainPartition = 0;
				bool first = true;
				for (const auto& state : currentSet)
				{
					std::size_t partition = 0;
					auto* outTransition = state->GetOutTransitionWithSameCondition(alpha);
					auto* outState = outTransition->GetOutState();
					for (auto& set : lastEquivalenceSets)
					{
						if (set.find(outState) == set.end())
						{
							partition++;
							continue;
						}

						if (first)
						{
							currentPartition.insert(state);
							mainPartition = partition;
							first = false;
						}
						else if (mainPartition == partition)
						{
							currentPartition.insert(state);
						}
						else
						{
							otherPartition.insert(state);
						}
						break;
					}
				}

				if (!otherPartition.empty())
				{
					// we have separated the states
					// further specialization is done in the next iteration of the main loop
					break;
				}
			}

			if (!currentPartition.empty())
			{
				nextEquivalenceSets.push_back(std::move(currentPartition));
			}
			if (!otherPartition.empty())
			{
				nextEquivalenceSets.push_back(std::move(otherPartition));
			}
		}

		if (equivalenceSets.empty())
		{
			if (lastEquivalenceSets == nextEquivalenceSets)
			{
				success = true;
				break;
			}
			else
			{
				lastEquivalenceSets = nextEquivalenceSets;
				equivalenceSets = std::move(nextEquivalenceSets);
				nextEquivalenceSets = {};
			}
		}
	}

	if (!success)
	{
		throw std::logic_error("Statemachine::Minimize: Programmer error should never throw");
	}

	std::vector<std::unique_ptr<State>> newStates;
	std::vector<std::unique_ptr<State>> removedStates;
	std::set<State*> unreachableStates;
	std::map<State*, State*> mapSetWithState;
	std::vector<std::unique_ptr<Transition>> newTransitions;
	State* newStartState = nullptr;
	for (auto& set : nextEquivalenceSets)
	{
		auto newState = std::make_unique<State>();
		newState->SetAccept((*set.begin())->IsAcceptState());
		for (const auto& state : set)
		{
			mapSetWithState.insert({state, newState.get()});

			newState->AddFlavors(state->GetFlavors());

			if (state->IsStartState())
			{
				newState->SetStart(true);
				newStartState = newState.get();
			}
		}

		newStates.push_back(std::move(newState));
	}

	for (auto& set : nextEquivalenceSets)
	{
		auto* someStateInPartition = *set.begin();
		auto* setState = mapSetWithState.find(someStateInPartition)->second;

		for (auto& transition : someStateInPartition->GetOutTransitions())
		{
			auto iter = mapSetWithState.find(transition->GetOutState());
			auto* outState = iter->second;
			auto newTransition =
				std::make_unique<Transition>(setState, transition->GetConditions(), outState);
			newTransitions.push_back(std::move(newTransition));
		}
	}

	sinkState = nullptr;
	SetStartState(newStartState);
	this->states = std::move(newStates);
	this->transitions = std::move(newTransitions);
	if (newStartState != nullptr)
	{
		RemoveUnreachableStates();
	}
}

std::set<std::vector<dregx::statemachine::Conditional>>
dregx::statemachine::Statemachine::GetAlphabet()
{
	std::set<std::vector<Conditional>> alphabet;
	for (const auto& transition : transitions)
	{
		alphabet.insert(transition->GetConditions());
	}

	return alphabet;
}

void dregx::statemachine::Statemachine::RemoveUnreachableStates()
{
	GetStartState()->any = true;
	std::size_t lastVisited = 0;
	std::size_t newVisited = 1;
	std::set<State*> currentStates = {GetStartState()};
	while (lastVisited != newVisited)
	{
		lastVisited = newVisited;
		std::set<State*> newStates;

		for (auto state : currentStates)
		{
			for (auto outTransition : state->GetOutTransitions())
			{
				newStates.insert(outTransition->GetOutState());
				if (!outTransition->GetOutState()->any)
				{
					outTransition->GetOutState()->any = true;
					newVisited++;
				}
			}
		}

		currentStates = newStates;
	}

	std::vector<State*> toBeRemoved;
	for (auto& state : states)
	{
		if (!state->any)
		{
			toBeRemoved.push_back(state.get());
		}
	}
	for (auto state : toBeRemoved)
	{
		RemoveState(state);
	}
	std::vector<State*> acceptedStates_;
	std::vector<State*> nonAcceptedStates_;
	for (auto& state : states)
	{
		state->any = false;
		if (state->IsAcceptState())
		{
			acceptedStates_.push_back(state.get());
		}
		else
		{
			nonAcceptedStates_.push_back(state.get());
		}
	}
	this->acceptedStates = acceptedStates_;
	this->nonAcceptedStates = nonAcceptedStates_;
}

void dregx::statemachine::Statemachine::DeterminizeAllTransitions()
{
	ToDFA();

	flags.allTransitionDeterminized = false;
	flags.embeddedAcceptState = true;
	flags.containsCycles = true; // Sink introduces cycles
	std::set<std::vector<Conditional>> alphabet = GetAlphabet();

	FillSinkState();

	bool connectionsWithSinkState = false;
	for (const auto& alpha : alphabet)
	{
		for (auto& state : states)
		{
			if (state->DoesOutTransitionExistWithSameCondition(alpha))
			{
				if (state->GetOutTransitionWithSameCondition(alpha)->GetOutState() == sinkState &&
					state.get() != sinkState)
				{
					connectionsWithSinkState = true;
				}
				continue;
			}
			connectionsWithSinkState = true;
			auto newTransition = std::make_unique<Transition>(state.get(), alpha, sinkState);
			AddTransition(std::move(newTransition));
		}
	}

	if (!connectionsWithSinkState)
	{
		RemoveState(sinkState);
		sinkState = nullptr;
	}
}
