#ifndef DEAMER_DREGX_V2_CBANALYZER_H
#define DEAMER_DREGX_V2_CBANALYZER_H

#include "Deamer/Dregx/V2/CBRegex.h"
#include <memory>
#include <string>

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
		bool IsFinite() const;
		bool IsInfinite() const;
		bool CheckInfiniteDFS(
			std::size_t currentState, std::vector<std::size_t> stack,
			std::unique_ptr<deamer::dregx::v2::CBRegex::CBStatemachineType>& statemachine,
			std::vector<std::size_t> transitionTable) const;
		bool IsRegexSubsetOf(const std::string& rhs_regex_);
		bool IsRegexBasesetOf(const std::string& rhs_regex_);
		bool IsRegexDisjointOf(const std::string& rhs_regex_);

	public:
		std::string ToDot();

	public:
		std::set<std::string> GetAllFiniteMatches();

	private:
		std::set<std::string> GetAllFiniteMatchesImplementation(
			::deamer::dregx::v2::CBRegex::CBStatemachineType* copiedStatemachine,
			std::size_t stateIndex);

	private:
		std::unique_ptr<::deamer::dregx::v2::CBRegex::CBStatemachineType>
		CreateDFA(const std::string& regex_);
	};

}

#endif // DEAMER_DREGX_V2_CBANALYZER_H
