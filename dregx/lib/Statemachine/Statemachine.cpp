#include "dregx/Statemachine/Statemachine.h"
#include <algorithm>
#include <iostream>
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
		ProductConstructionOR(rhs);
	}
	else
	{
		IsDFA = false;
		auto newStartState = std::make_unique<State>();
		auto* lhsStartState = GetStartState();
		auto* rhsStartState = rhs.GetStartState();

		newStartState->SetStart(true);
		lhsStartState->SetStart(false);
		rhsStartState->SetStart(false);

		auto linkWithLhsStartState = std::make_unique<Transition>(
			newStartState.get(), std::vector<Conditional>{}, lhsStartState);
		auto linkWithRhsStartState = std::make_unique<Transition>(
			newStartState.get(), std::vector<Conditional>{}, rhsStartState);

		SetStartState(newStartState.get());
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

void dregx::statemachine::Statemachine::And(Statemachine& rhs)
{
	// Currently Product Construction only works for DFA
	// There are options for NFAs, but not yet implemented.
	if (!IsDFA)
	{
		ToDFA();
	}

	if (!rhs.IsDFA)
	{
		rhs.ToDFA();
	}

	ProductConstructionAND(rhs);
}

// Connect all lhs.acceptstates with rhs.startstate using empty transition
void dregx::statemachine::Statemachine::Concatenate(Statemachine& rhs)
{
	if (&rhs == this)
	{
		return;
	}

	if (IsDFA && !containsCycles && rhs.IsDFA && !rhs.containsCycles && !EmbeddedAcceptState &&
		!rhs.EmbeddedAcceptState)
	{
		// This utilizes an optimized algorithm
		// The algorithm will merge the DFA at every accept state.
		// The merge will prefer existing transitions and only create new transitions
		// if no transition exists.
		std::size_t depth = std::numeric_limits<std::size_t>::max();
		std::tuple<std::size_t, std::set<State*>> deleteTillStates;
		for (auto& acceptState : GetAcceptStates())
		{
			std::size_t localDepth = 1;
			std::vector<std::tuple<State*, State*>> unconcatenatedStates;
			acceptState->SetAccept(rhs.GetStartState()->IsAcceptState());
			unconcatenatedStates.emplace_back(acceptState, rhs.GetStartState());
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
						AddTransition(std::move(newTransition));

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
				rhs.RemoveTransition(inTransition);
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
			rhs.RemoveState(deleteState);
		}

		for (auto& state : rhs.states)
		{
			AddState(std::move(state));
		}

		for (auto& transition : rhs.transitions)
		{
			AddTransition(std::move(transition));
		}

		rhs.states.clear();
		rhs.transitions.clear();
	}
	else
	{
		auto* rhsStartState = rhs.GetStartState();
		rhsStartState->SetStart(false);
		for (auto* acceptState : GetAcceptStates())
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
	for (const auto& existingState : states)
	{
		auto copyState = std::make_unique<State>();
		copyState->SetAccept(existingState->IsAcceptState());
		if (existingState->IsStartState())
		{
			copyState->SetStart(true);
			copyStartState = copyState.get();
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

	newStatemachine->startState = copyStartState;
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
			EmbeddedAcceptState = true;
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

		containsCycles = true;
		IsDFA = false;
	}

	if (extension.GetLowerBound() == 0)
	{
		EmbeddedAcceptState = true;
		GetStartState()->SetAccept(true);
	}
}

void dregx::statemachine::Statemachine::SetStartState(State* startState_)
{
	startState = startState_;
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
			graph += transition->GetConditions()[0].GetCharacter();
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

	bool IsAcceptOR()
	{
		return (our != nullptr && our->IsAcceptState()) ||
			   (their != nullptr && their->IsAcceptState());
	}

	bool IsAcceptAND()
	{
		return (our != nullptr && our->IsAcceptState()) &&
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
			for (auto* transition : our->GetOutTransitions())
			{
				mapConditionalWithTuple.insert(
					{transition->GetConditions(), {transition, nullptr}});
			}
		}
		if (their != nullptr)
		{
			for (auto* transition : their->GetOutTransitions())
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

	std::map<std::vector<dregx::statemachine::Conditional>,
			 std::tuple<dregx::statemachine::Transition*, dregx::statemachine::Transition*>>
	And()
	{
		std::map<std::vector<dregx::statemachine::Conditional>,
				 std::tuple<dregx::statemachine::Transition*, dregx::statemachine::Transition*>>
			mapConditionalWithTuple;

		for (auto* lhsTransition : our->GetOutTransitions())
		{
			for (auto* rhsTransition : their->GetOutTransitions())
			{
				if (lhsTransition->GetConditions() == rhsTransition->GetConditions())
				{
					mapConditionalWithTuple.insert(
						{lhsTransition->GetConditions(), {lhsTransition, rhsTransition}});
					break;
				}
			}
		}

		return mapConditionalWithTuple;
	}
};

void dregx::statemachine::Statemachine::ProductConstructionOR(Statemachine& rhs)
{
	const auto& ourStates = GetStates();
	const auto& theirStates = rhs.GetStates();

	std::vector<std::unique_ptr<ProductionConstructionState>> productStates;
	std::map<std::tuple<State*, State*>, ProductionConstructionState*>
		mapStatesWithProductConstructionState;
	for (const auto& ourState : ourStates)
	{
		for (const auto& theirState : theirStates)
		{
			auto newProductConstructionState =
				std::make_unique<ProductionConstructionState>(ourState.get(), theirState.get());
			mapStatesWithProductConstructionState.insert(
				{{ourState.get(), theirState.get()}, newProductConstructionState.get()});

			if (ourState->IsStartState() && theirState->IsStartState())
			{
				newProductConstructionState->IsStart = true;
			}

			productStates.push_back(std::move(newProductConstructionState));
		}
	}

	for (const auto& ourState : ourStates)
	{
		auto newProductConstructionState =
			std::make_unique<ProductionConstructionState>(ourState.get(), nullptr);
		mapStatesWithProductConstructionState.insert(
			{{ourState.get(), nullptr}, newProductConstructionState.get()});

		productStates.push_back(std::move(newProductConstructionState));
	}

	for (const auto& theirState : theirStates)
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
	State* newStartState = nullptr;
	for (auto& productState : productStates)
	{
		auto newState = std::make_unique<State>();
		if (productState->IsStart)
		{
			newState->SetStart(true);
			newStartState = newState.get();
		}
		newState->SetAccept(productState->IsAcceptOR());

		mapPCSwithStates.insert({productState.get(), newState.get()});

		newStates.push_back(std::move(newState));
	}

	for (auto& productionState : productStates)
	{
		auto* thisState = mapPCSwithStates.find(productionState.get())->second;
		auto conditionalMap = productionState->Or();
		for (auto& [conditional, transitions] : conditionalMap)
		{
			auto* firstTransition = std::get<0>(transitions);
			auto* secondTransition = std::get<1>(transitions);
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
			auto* otherProductState =
				mapStatesWithProductConstructionState.find({firstState, secondState})->second;
			auto* otherState = mapPCSwithStates.find(otherProductState)->second;
			auto newTransition = std::make_unique<Transition>(thisState, conditional, otherState);

			newTransitions.push_back(std::move(newTransition));
		}
	}

	SetStartState(newStartState);
	this->states = std::move(newStates);
	this->transitions = std::move(newTransitions);
}

void dregx::statemachine::Statemachine::ProductConstructionAND(const Statemachine& rhs)
{
	const auto& ourStates = GetStates();
	const auto& theirStates = rhs.GetStates();

	std::vector<std::unique_ptr<ProductionConstructionState>> productStates;
	std::map<std::tuple<State*, State*>, ProductionConstructionState*>
		mapStatesWithProductConstructionState;

	for (const auto& ourState : ourStates)
	{
		for (const auto& theirState : theirStates)
		{
			auto newProductConstructionState =
				std::make_unique<ProductionConstructionState>(ourState.get(), theirState.get());
			mapStatesWithProductConstructionState.insert(
				{{ourState.get(), theirState.get()}, newProductConstructionState.get()});

			if (ourState->IsStartState() && theirState->IsStartState())
			{
				newProductConstructionState->IsStart = true;
			}

			productStates.push_back(std::move(newProductConstructionState));
		}
	}

	std::map<ProductionConstructionState*, State*> mapPCSwithStates;
	std::vector<std::unique_ptr<State>> newStates;
	std::vector<std::unique_ptr<Transition>> newTransitions;
	State* newStartState = nullptr;
	for (auto& productState : productStates)
	{
		auto newState = std::make_unique<State>();
		if (productState->IsStart)
		{
			newState->SetStart(true);
			newStartState = newState.get();
		}
		newState->SetAccept(productState->IsAcceptAND());

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

	SetStartState(newStartState);
	this->states = std::move(newStates);
	this->transitions = std::move(newTransitions);
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

	IsDFA = true;
}

void dregx::statemachine::Statemachine::Minimize()
{
	if (!IsDFA)
	{
		return;
	}

	if (!AllTransitionDeterminized)
	{
		DeterminizeAllTransitions();
	}

	std::set<State*> acceptedPartition;
	std::set<State*> nonAcceptedPartition;
	for (auto& state : states)
	{
		if (state->IsAcceptState())
		{
			acceptedPartition.insert(state.get());
		}
		else
		{
			nonAcceptedPartition.insert(state.get());
		}
	}

	std::vector<std::set<State*>> lastEquivalenceSets;
	lastEquivalenceSets.push_back(std::move(nonAcceptedPartition));
	lastEquivalenceSets.push_back(std::move(acceptedPartition));

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
					auto* outState = state->GetOutTransitionWithSameCondition(alpha)->GetOutState();
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

	SetStartState(newStartState);
	this->states = std::move(newStates);
	this->transitions = std::move(newTransitions);
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

void dregx::statemachine::Statemachine::DeterminizeAllTransitions()
{
	if (!IsDFA)
	{
		return;
	}

	AllTransitionDeterminized = true;
	EmbeddedAcceptState = true;
	containsCycles = true; // Sink introduces cycles
	std::set<std::vector<Conditional>> alphabet = GetAlphabet();

	std::unique_ptr<State> newSinkState;
	if (sinkState == nullptr)
	{
		newSinkState = std::make_unique<State>();
		sinkState = newSinkState.get();
		sinkState->SetSink(true);
	}

	std::size_t unMappedLinks = 0;
	for (const auto& alpha : alphabet)
	{
		for (auto& state : states)
		{
			if (state->DoesOutTransitionExistWithSameCondition(alpha))
			{
				continue;
			}
			unMappedLinks++;
			auto newTransition = std::make_unique<Transition>(state.get(), alpha, sinkState);
			AddTransition(std::move(newTransition));
		}
	}

	if (unMappedLinks != 0)
	{
		AddState(std::move(newSinkState));
		for (const auto& alpha : alphabet)
		{
			auto newTransition = std::make_unique<Transition>(sinkState, alpha, sinkState);
			AddTransition(std::move(newTransition));
		}
	}
	else
	{
		sinkState = nullptr;
	}
}
