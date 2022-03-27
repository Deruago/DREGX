#ifndef DREGX_STATEMACHINE_TRANSITIONTABLE_H
#define DREGX_STATEMACHINE_TRANSITIONTABLE_H

#include "dregx/Statemachine/Conditional.h"
#include <map>
#include <set>
#include <vector>

namespace dregx::statemachine
{
	class TransitionTable
	{
	public:
		// The map allows the user to get the appropiate transition to some new state.
		// The indexes represent the various states.
		// A different table is utilized for checking if some state is accepting.
		// std::size_t::max is used for rejecting states
		std::vector<std::map<std::string, std::size_t>> table;
		std::vector<bool> acceptingState;
		std::vector<std::set<std::string>> flavorState;

		bool Match(const std::string& text) const;
		void Print();
	};
}

#endif // DREGX_STATEMACHINE_TRANSITIONTABLE_H
