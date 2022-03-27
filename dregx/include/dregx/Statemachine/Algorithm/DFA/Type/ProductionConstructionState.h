#ifndef DREGX_STATEMACHINE_ALGORITHM_DFA_TYPE_PRODUCTIONCONSTRUCTIONSTATE_H
#define DREGX_STATEMACHINE_ALGORITHM_DFA_TYPE_PRODUCTIONCONSTRUCTIONSTATE_H

#include <map>

#include "dregx/Statemachine/State.h"
#include "dregx/Statemachine/Transition.h"

namespace dregx::statemachine::dfa::type
{
	struct ProductionConstructionState
	{
		dregx::statemachine::State* our;
		dregx::statemachine::State* their;

		ProductionConstructionState(dregx::statemachine::State* our_,
		                            dregx::statemachine::State* their_);

		std::set<std::string> GetFlavors() const;

		bool IsAcceptOR();

		bool IsAcceptAND();

		std::map<std::vector<dregx::statemachine::Conditional>,
		         std::tuple<dregx::statemachine::Transition*, dregx::statemachine::Transition*>> Or();

		std::map<std::vector<dregx::statemachine::Conditional>,
		         std::tuple<dregx::statemachine::Transition*, dregx::statemachine::Transition*>> And();

		bool IsSink();

		bool IsStart();
	};
}

#endif // DREGX_STATEMACHINE_ALGORITHM_DFA_TYPE_PRODUCTIONCONSTRUCTIONSTATE_H