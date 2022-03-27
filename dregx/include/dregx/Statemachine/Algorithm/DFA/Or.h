#ifndef DREGX_STATEMACHINE_ALGORITHM_DFA_OR_H
#define DREGX_STATEMACHINE_ALGORITHM_DFA_OR_H

#include "dregx/Statemachine/Algorithm/Algorithm.h"

namespace dregx::statemachine::dfa
{
	class Or : public Algorithm
	{
	public:
		Or() = default;
		~Or() override = default;

	public:
		virtual Flag Flags(Statemachine* lhs, Statemachine* rhs) override;
		virtual void SinkState(State* state, Statemachine* lhs, Statemachine* rhs) override;
		virtual void StartState(State* state, Statemachine* lhs, Statemachine* rhs) override;
		virtual void Operation(Statemachine* lhs, Statemachine* rhs) override;
		virtual bool CheckPreconditions(Statemachine* lhs, Statemachine* rhs) override;

	private:
		void OptimizedOperation(Statemachine* lhs, Statemachine* rhs);
	};
}

#endif // DREGX_STATEMACHINE_ALGORITHM_DFA_OR_H
