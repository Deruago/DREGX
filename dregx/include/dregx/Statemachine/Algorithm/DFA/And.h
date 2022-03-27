#ifndef DREGX_STATEMACHINE_ALGANDITHM_DFA_AND_H
#define DREGX_STATEMACHINE_ALGANDITHM_DFA_AND_H

#include "dregx/Statemachine/Algorithm/Algorithm.h"

namespace dregx::statemachine::dfa
{
	class And : public Algorithm
	{
	public:
		And() = default;
		~And() override = default;

	public:
		virtual Flag Flags(Statemachine* lhs, Statemachine* rhs) override;
		virtual void SinkState(State* state, Statemachine* lhs, Statemachine* rhs) override;
		virtual void StartState(State* state, Statemachine* lhs, Statemachine* rhs) override;
		virtual void Operation(Statemachine* lhs, Statemachine* rhs) override;
		virtual bool CheckPreconditions(Statemachine* lhs, Statemachine* rhs) override;
	};
}

#endif // DREGX_STATEMACHINE_ALGANDITHM_DFA_AND_H
