#include "dregx/Statemachine/Algorithm/Flag.h"

dregx::statemachine::Flag::Flag(IsDfa isDfa_, ContainsCycles containsCycles_,
								EmbeddedAcceptState embeddedAcceptState_,
								AllTransitionDeterminized AllTransitionsDeterminized_)
	: containsCycles(containsCycles_),
	  IsDFA(isDfa_),
	  embeddedAcceptState(embeddedAcceptState_),
	  allTransitionDeterminized(AllTransitionsDeterminized_)
{
}
