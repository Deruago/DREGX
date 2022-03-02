#include "dregx/Statemachine/TransitionTable.h"
#include <limits>

bool dregx::statemachine::TransitionTable::Match(const std::string& text) const
{
	std::size_t nextState = 0;
	for (auto character : text)
	{
		std::string charFormat;
		charFormat += character;
		auto iter = table[nextState].find(charFormat);
		if (iter == table[nextState].end())
		{
			return false;
		}
		nextState = iter->second;
	}

	if (acceptingState[nextState])
	{
		return true;
	}
	else
	{
		return false;
	}
}

#include <iostream>

void dregx::statemachine::TransitionTable::Print()
{
	for (auto i = 0; i < table.size(); i++)
	{
		auto currentStateEntry = table[i];
		std::cout << std::boolalpha;
		std::cout << "State: " << std::to_string(i) << " Accepting: " << acceptingState[i] << "\n";
		for (auto& [transition, state] : currentStateEntry)
		{
			std::cout << "\t"
					  << "Condition: " << transition << " -> State: " << std::to_string(state)
					  << "\n";
		}
	}
}
