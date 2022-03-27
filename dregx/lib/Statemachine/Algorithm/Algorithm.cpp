#include "dregx/Statemachine/Algorithm/Algorithm.h"
#include <stdexcept>

static constexpr bool debug = true;

void dregx::statemachine::Algorithm::Execute(Statemachine* lhs, Statemachine* rhs)
{
	Operation(lhs, rhs);

	lhs->flags = Flags(lhs, rhs);

	if constexpr (debug)
	{
		CheckStartState(lhs, rhs);
		CheckSinkState(lhs, rhs);
	}
}

void dregx::statemachine::Algorithm::Execute(Statemachine* lhs, Statemachine& rhs)
{
	Execute(lhs, &rhs);
}

void dregx::statemachine::Algorithm::CheckStartState(Statemachine* lhs, Statemachine* rhs)
{
	bool foundStartState = false;
	for (auto& state : lhs->GetStates())
	{
		if (state.get() == lhs->GetStartState())
		{
			foundStartState = true;
		}
	}

	if (lhs->GetStartState() == nullptr)
	{
		foundStartState = false;
	}

	if (!foundStartState)
	{
		throw std::logic_error("Algorithm is faulty, not implemented proper start state logic");
	}
}

void dregx::statemachine::Algorithm::CheckSinkState(Statemachine* lhs, Statemachine* rhs)
{
	bool foundSinkState = false;
	for (auto& state : lhs->GetStates())
	{
		if (state.get() == lhs->GetSinkState())
		{
			foundSinkState = true;
		}
	}

	if (lhs->GetSinkState() == nullptr)
	{
		foundSinkState = true;
	}

	if (!foundSinkState)
	{
		throw std::logic_error("Algorithm is faulty, not implemented proper sink state logic");
	}
}
