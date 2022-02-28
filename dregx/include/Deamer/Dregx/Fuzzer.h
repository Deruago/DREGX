#ifndef DEAMER_DREGX_FUZZER_H
#define DEAMER_DREGX_FUZZER_H

#include "dregx/Statemachine/Statemachine.h"
#include <string>

namespace deamer::dregx
{
	class Fuzzer
	{
	private:
		std::string regex;
		std::unique_ptr<::dregx::statemachine::Statemachine> statemachine;

	public:
		Fuzzer(const std::string& regex_);
		Fuzzer() = default;
		~Fuzzer() = default;

	public:
		void SetRegex(const std::string& regex_);

	public:
		std::string GetMinimalExample() const;

	private:
		std::unique_ptr<::dregx::statemachine::Statemachine> CreateDFA(const std::string& regex_);
	};

}

#endif // DEAMER_DREGX_FUZZER_H
