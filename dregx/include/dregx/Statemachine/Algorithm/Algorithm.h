#ifndef DREGX_STATEMACHINE_ALGORITHM_ALGORITHM_H
#define DREGX_STATEMACHINE_ALGORITHM_ALGORITHM_H

#include "dregx/Statemachine/Algorithm/Flag.h"
#include "dregx/Statemachine/Statemachine.h"

namespace dregx::statemachine
{
	class Algorithm
	{
	public:
		Algorithm() = default;
		virtual ~Algorithm() = default;

	public:
		void Execute(Statemachine* lhs, Statemachine* rhs);
		void Execute(Statemachine* lhs, Statemachine& rhs);
		virtual Flag Flags(Statemachine* lhs, Statemachine* rhs) = 0;
		virtual void SinkState(State* state, Statemachine* lhs, Statemachine* rhs) = 0;
		virtual void StartState(State* state, Statemachine* lhs, Statemachine* rhs) = 0;
		virtual void Operation(Statemachine* lhs, Statemachine* rhs) = 0;
		virtual bool CheckPreconditions(Statemachine* lhs, Statemachine* rhs) = 0;

	private:
		void CheckStartState(Statemachine* lhs, Statemachine* rhs);
		void CheckSinkState(Statemachine* lhs, Statemachine* rhs);
	};
}

#endif // DREGX_STATEMACHINE_ALGORITHM_ALGORITHM_H
