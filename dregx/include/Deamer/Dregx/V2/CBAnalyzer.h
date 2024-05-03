#ifndef DEAMER_DREGX_V2_CBANALYZER_H
#define DEAMER_DREGX_V2_CBANALYZER_H

#include "Deamer/Dregx/V2/CBRegex.h"
#include <string>
#include <memory>

namespace deamer::dregx::v2
{
	class CBAnalyzer
	{
	private:
		std::string regex;
		std::unique_ptr<::deamer::dregx::v2::CBRegex::CBStatemachineType> statemachine;

	public:
		CBAnalyzer(const std::string& regex_);
		CBAnalyzer() = default;
		~CBAnalyzer() = default;

	public:
		void SetRegex(const std::string& regex_);

	public:
		bool IsRegexSubsetOf(const std::string& rhs_regex_);
		bool IsRegexBasesetOf(const std::string& rhs_regex_);
		bool IsRegexDisjointOf(const std::string& rhs_regex_);

	private:
		std::unique_ptr<::deamer::dregx::v2::CBRegex::CBStatemachineType>
		CreateDFA(const std::string& regex_);
	};

}

#endif // DEAMER_DREGX_V2_CBANALYZER_H
