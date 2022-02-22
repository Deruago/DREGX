#include "dregx/Statemachine/State.h"
#include "dregx/Statemachine/Transition.h"
#include <algorithm>

dregx::statemachine::State::~State()
{
	for (auto inTransition : inTransitions)
	{
		inTransition->SetOutState(nullptr);
		delete inTransition;
	}
	for (auto outTransition : outTransitions)
	{
		outTransition->SetInState(nullptr);
		delete outTransition;
	}

	inTransitions.clear();
	outTransitions.clear();
}

void dregx::statemachine::State::SetStart(bool start_)
{
	start = start_;
}

void dregx::statemachine::State::SetAccept(bool accept_)
{
	accept = accept_;
}

void dregx::statemachine::State::SetInTransitions(std::vector<Transition*> inTransitions_)
{
	inTransitions = inTransitions_;
}

void dregx::statemachine::State::SetOutTransitions(std::vector<Transition*> outTransitions_)
{
	outTransitions = outTransitions_;
}

void dregx::statemachine::State::RemoveInTransition(Transition* transition)
{
	const auto iter = std::find(std::cbegin(inTransitions), std::cend(inTransitions), transition);
	if (iter == std::cend(inTransitions))
	{
		return;
	}

	inTransitions.erase(iter);
}

void dregx::statemachine::State::RemoveOutTransition(Transition* transition)
{
	const auto iter = std::find(std::cbegin(outTransitions), std::cend(outTransitions), transition);
	if (iter == std::cend(outTransitions))
	{
		return;
	}

	outTransitions.erase(iter);
}

void dregx::statemachine::State::AddOutTransition(Transition* transition)
{
	if (DoesOutTransitionExist(transition))
	{
		return;
	}

	outTransitions.push_back(transition);
}

void dregx::statemachine::State::AddInTransition(Transition* transition)
{
	if (DoesInTransitionExist(transition))
	{
		return;
	}

	inTransitions.push_back(transition);
}

bool dregx::statemachine::State::IsStartState() const
{
	return start;
}

bool dregx::statemachine::State::IsAcceptState() const
{
	return accept;
}

std::vector<dregx::statemachine::Transition*> dregx::statemachine::State::GetInTransitions() const
{
	return inTransitions;
}

std::vector<dregx::statemachine::Transition*> dregx::statemachine::State::GetOutTransitions() const
{
	return outTransitions;
}

bool dregx::statemachine::State::DoesInTransitionExist(std::vector<Conditional> condition,
													   State* state) const
{
	for (auto transition : inTransitions)
	{
		if (transition->GetInState() == state && transition->GetConditions() == condition)
		{
			return true;
		}
	}

	return false;
}

bool dregx::statemachine::State::DoesOutTransitionExist(std::vector<Conditional> condition,
														State* state) const
{
	for (auto transition : outTransitions)
	{
		if (transition->GetOutState() == state && transition->GetConditions() == condition)
		{
			return true;
		}
	}

	return false;
}

bool dregx::statemachine::State::DoesInTransitionExist(Transition* rhs) const
{
	for (auto transition : inTransitions)
	{
		if (*transition == *rhs)
		{
			return true;
		}
	}

	return false;
}

bool dregx::statemachine::State::DoesOutTransitionExist(Transition* rhs) const
{
	for (auto transition : outTransitions)
	{
		if (*transition == *rhs)
		{
			return true;
		}
	}

	return false;
}

dregx::statemachine::Transition* dregx::statemachine::State::GetInTransition(Transition* rhs) const
{
	for (auto transition : inTransitions)
	{
		if (*transition == *rhs)
		{
			return transition;
		}
	}

	return nullptr;
}

dregx::statemachine::Transition* dregx::statemachine::State::GetOutTransition(Transition* rhs) const
{
	for (auto transition : outTransitions)
	{
		if (*transition == *rhs)
		{
			return transition;
		}
	}

	return nullptr;
}

bool dregx::statemachine::State::DoesInTransitionExistWithSameCondition(Transition* rhs) const
{
	for (auto transition : inTransitions)
	{
		if (transition->GetConditions() == rhs->GetConditions())
		{
			return true;
		}
	}

	return false;
}

bool dregx::statemachine::State::DoesOutTransitionExistWithSameCondition(Transition* rhs) const
{
	for (auto transition : outTransitions)
	{
		if (transition->GetConditions() == rhs->GetConditions())
		{
			return true;
		}
	}

	return false;
}

dregx::statemachine::Transition*
dregx::statemachine::State::GetInTransitionWithSameCondition(Transition* rhs) const
{
	for (auto transition : inTransitions)
	{
		if (transition->GetConditions() == rhs->GetConditions())
		{
			return transition;
		}
	}

	return nullptr;
}

dregx::statemachine::Transition*
dregx::statemachine::State::GetOutTransitionWithSameCondition(Transition* rhs) const
{
	for (auto transition : outTransitions)
	{
		if (transition->GetConditions() == rhs->GetConditions())
		{
			return transition;
		}
	}

	return nullptr;
}

bool dregx::statemachine::State::HasConditions(const std::vector<std::vector<Conditional>>& in,
											   const std::vector<std::vector<Conditional>>& out)
{
	for (auto inCondition : in)
	{
		bool found = false;
		for (auto transition : inTransitions)
		{
			if (transition->GetConditions() == inCondition)
			{
				found = true;
				break;
			}
		}

		if (!found)
		{
			return false;
		}
	}

	for (auto outCondition : out)
	{
		bool found = false;
		for (auto transition : outTransitions)
		{
			if (transition->GetConditions() == outCondition)
			{
				found = true;
				break;
			}
		}

		if (!found)
		{
			return false;
		}
	}

	return true;
}
