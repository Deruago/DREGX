#include "dregx/Statemachine/Transition.h"
#include "dregx/Statemachine/State.h"

dregx::statemachine::Transition::Transition(State* in_, std::vector<Conditional> condition_,
											State* out_)
	: in(in_),
	  condition(condition_),
	  out(out_)
{
	in->AddOutTransition(this);
	out->AddInTransition(this);
}

dregx::statemachine::Transition::~Transition()
{
	in->RemoveOutTransition(this);
	out->RemoveInTransition(this);
}

dregx::statemachine::State* dregx::statemachine::Transition::GetInState() const
{
	return in;
}

dregx::statemachine::State* dregx::statemachine::Transition::GetOutState() const
{
	return out;
}

std::vector<dregx::statemachine::Conditional> dregx::statemachine::Transition::GetConditions() const
{
	return condition;
}

bool dregx::statemachine::Transition::operator==(const Transition& rhs) const noexcept
{
	if (&rhs == this)
	{
		return true;
	}

	return rhs.GetInState() == this->in && rhs.GetConditions() == this->condition &&
		   rhs.GetOutState() == this->out;
}
