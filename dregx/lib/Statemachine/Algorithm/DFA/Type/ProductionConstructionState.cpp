#include "dregx/Statemachine/Algorithm/DFA/Type/ProductionConstructionState.h"

dregx::statemachine::dfa::type::ProductionConstructionState::ProductionConstructionState(
	dregx::statemachine::State* our_, dregx::statemachine::State* their_): our(our_),
	                                                                       their(their_)
{
}

std::set<std::string> dregx::statemachine::dfa::type::ProductionConstructionState::GetFlavors() const
{
	std::set<std::string> flavors;
	if (our != nullptr)
	{
		for (const auto& flavor : our->GetFlavors())
		{
			flavors.insert(flavor);
		}
	}
	if (their != nullptr)
	{
		for (const auto& theirFlavor : their->GetFlavors())
		{
			flavors.insert(theirFlavor);
		}
	}
	return flavors;
}

bool dregx::statemachine::dfa::type::ProductionConstructionState::IsAcceptOR()
{
	return (our != nullptr && our->IsAcceptState()) ||
			(their != nullptr && their->IsAcceptState());
}

bool dregx::statemachine::dfa::type::ProductionConstructionState::IsAcceptAND()
{
	return (our != nullptr && our->IsAcceptState()) &&
			(their != nullptr && their->IsAcceptState());
}

std::map<std::vector<dregx::statemachine::Conditional>, std::tuple<dregx::statemachine::Transition*, dregx::statemachine
                                                                   ::Transition*>>
dregx::statemachine::dfa::type::ProductionConstructionState::Or()
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

std::map<std::vector<dregx::statemachine::Conditional>, std::tuple<dregx::statemachine::Transition*, dregx::statemachine
                                                                   ::Transition*>>
dregx::statemachine::dfa::type::ProductionConstructionState::And()
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

bool dregx::statemachine::dfa::type::ProductionConstructionState::IsSink()
{
	return (our != nullptr && our->IsSinkState()) ||
			(their != nullptr && their->IsSinkState());
}

bool dregx::statemachine::dfa::type::ProductionConstructionState::IsStart()
{
	return (our != nullptr && our->IsStartState()) &&
			(their != nullptr && their->IsStartState());
}
