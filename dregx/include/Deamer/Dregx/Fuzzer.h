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
		bool IsRegexFinite() const;

		/*!	\fn GetAllFiniteMatches
		 *
		 *	\brief Gets all finite matches of a regex.
		 *
		 *	\note If the regex is infinite, this function will return "GetMinimalExample"
		 *	As it is not possible to give all possibilities of something that is infinite.
		 */
		std::vector<std::string> GetAllFiniteMatches() const;

	private:
		std::unique_ptr<::dregx::statemachine::Statemachine> CreateDFA(const std::string& regex_);

		std::set<std::string>
		GetAllFiniteMatchesImplementation(::dregx::statemachine::State* state) const;
	};

}

#endif // DEAMER_DREGX_FUZZER_H
