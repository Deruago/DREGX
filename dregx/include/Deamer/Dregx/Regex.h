#ifndef DEAMER_DREGX_REGEX_H
#define DEAMER_DREGX_REGEX_H

#include "dregx/Statemachine/Statemachine.h"
#include "dregx/Statemachine/TransitionTable.h"
#include <string>

namespace deamer::dregx
{
	class Regex
	{
	private:
		std::string regex;
		std::string flavor;
		std::unique_ptr<::dregx::statemachine::Statemachine> statemachine;
		::dregx::statemachine::TransitionTable transitionTable;

	public:
		Regex(const std::string& regex_, const std::string& flavor_ = "");
		~Regex() = default;

	public:
		bool Match(const std::string& text) const;

	public:
		std::string GetRegex() const;
		std::unique_ptr<::dregx::statemachine::Statemachine> GetStatemachine() const;

	public:
		void Or(const Regex& rhs);
		void Concatenate(const Regex& rhs);
		bool Equal(const Regex& rhs) const;

	public:
		Regex& operator|=(const Regex& rhs);
		Regex& operator+=(const Regex& rhs);
		Regex& operator|(const Regex& rhs);
		Regex& operator+(const Regex& rhs);
		bool operator==(const Regex& rhs);

	public:
		Regex& operator|=(const std::string& rhs);
		Regex& operator+=(const std::string& rhs);
		Regex& operator|(const std::string& rhs);
		Regex& operator+(const std::string& rhs);
		bool operator==(const std::string& rhs);

	private:
		void SetRegex(const std::string& regex_);
		std::unique_ptr<::dregx::statemachine::Statemachine> CreateDFA(const std::string& regex_);
	};

	bool operator==(const Regex& lhs, const Regex& rhs);
	bool operator==(const Regex& lhs, const std::string& rhs);
	bool operator==(const std::string& lhs, const Regex& rhs);
}

#endif // DEAMER_DREGX_REGEX_H
