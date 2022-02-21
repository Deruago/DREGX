#ifndef DREGX_STATEMACHINE_TRANSITION_H
#define DREGX_STATEMACHINE_TRANSITION_H

#include "dregx/Statemachine/Conditional.h"
#include <vector>

namespace dregx::statemachine
{
	class State;

	struct Transition
	{
	private:
		State* const in;
		const std::vector<Conditional> condition;
		State* const out;

	public:
		Transition(State* in_, std::vector<Conditional> condition_, State* out_);
		~Transition();

	public:
		State* GetInState() const;
		State* GetOutState() const;
		std::vector<Conditional> GetConditions() const;

		bool operator==(const Transition& rhs) const noexcept;
	};
}

#endif // DREGX_STATEMACHINE_TRANSITION_H
