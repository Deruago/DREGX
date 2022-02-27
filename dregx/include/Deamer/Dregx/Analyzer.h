#ifndef DEAMER_DREGX_ANALYZER_H
#define DEAMER_DREGX_ANALYZER_H

#include "dregx/Statemachine/Statemachine.h"
#include <string>

namespace deamer::dregx
{
	class Analyzer
	{
	private:
		std::string regex;
		std::unique_ptr<::dregx::statemachine::Statemachine> statemachine;

	public:
		Analyzer(const std::string& regex_);
		Analyzer() = default;
		~Analyzer() = default;

	public:
		void SetRegex(const std::string& regex_);

	public:
		bool IsRegexSubsetOf(const std::string& rhs_regex_);
		bool IsRegexBasesetOf(const std::string& rhs_regex_);

	private:
		std::unique_ptr<::dregx::statemachine::Statemachine> CreateDFA(const std::string& regex_);
	};

}

#endif // DEAMER_DREGX_ANALYZER_H
