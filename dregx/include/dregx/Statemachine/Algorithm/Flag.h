#ifndef DREGX_STATEMACHINE_ALGORITHM_FLAG_H
#define DREGX_STATEMACHINE_ALGORITHM_FLAG_H

namespace dregx::statemachine
{
	struct Flag
	{
	public:
		using IsDfa = bool;
		using ContainsCycles = bool;
		using EmbeddedAcceptState = bool;
		using AllTransitionDeterminized = bool;

	public:
		IsDfa containsCycles = false;
		ContainsCycles IsDFA = true;
		EmbeddedAcceptState embeddedAcceptState = false;
		AllTransitionDeterminized allTransitionDeterminized = false;

	public:
		Flag(IsDfa containsCycles_, ContainsCycles isDfa_, EmbeddedAcceptState embeddedAcceptState_,
			 AllTransitionDeterminized AllTransitionsDeterminized_);
		~Flag() = default;
	};
}

#endif // DREGX_STATEMACHINE_ALGORITHM_FLAG_H
