#ifndef DEAMER_DREGX_V2_REGEX_H
#define DEAMER_DREGX_V2_REGEX_H

#include "Deamer/Dregx/V2/Statemachine.h"
#include "dregx/Statemachine/TransitionTable.h"
#include <string>
#include <memory>

namespace deamer::dregx::v2
{
	class Regex
	{
	private:
		std::string regex;
		std::string flavor;
		std::unique_ptr<::deamer::dregx::v2::Statemachine> statemachine;

	public:
		Regex(const std::string& regex_, const std::string& flavor_ = "");
		~Regex() = default;

	public:
		bool Match(const std::string& text) const;

	public:
		std::string GetRegex() const;
		std::unique_ptr<::deamer::dregx::v2::Statemachine> GetStatemachine() const;

	public:
		void Or(const Regex& rhs);
		void Concatenate(const Regex& rhs);
		bool Equal(const Regex& rhs) const;

	public:
		void Minimize();

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
		std::unique_ptr<::deamer::dregx::v2::Statemachine>
		CreateDFA(const std::string& regex_);
	};

	bool operator==(const ::deamer::dregx::v2::Regex& lhs, const ::deamer::dregx::v2::Regex& rhs);
	bool operator==(const ::deamer::dregx::v2::Regex& lhs, const std::string& rhs);
	bool operator==(const std::string& lhs, const ::deamer::dregx::v2::Regex& rhs);
}

#endif // DEAMER_DREGX_V2_REGEX_H
