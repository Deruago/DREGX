#ifndef DEAMER_DREGX_V2_CBREGEX_H
#define DEAMER_DREGX_V2_CBREGEX_H

#include "Deamer/Dregx/V2/CBStatemachine.h"
#include "dregx/Statemachine/TransitionTable.h"
#include <memory>
#include <string>

namespace deamer::dregx::v2
{
	class CBRegex
	{
	public:
		using CBStatemachineType = ::deamer::dregx::v2::CBStatemachine<10, 1, char>;

	private:
		std::string regex;
		std::size_t flavor;
		std::unique_ptr<CBStatemachineType> statemachine;

	public:
		CBRegex(const std::string& regex_, const std::size_t& flavor_ = 0);
		~CBRegex() = default;

	public:
		bool Match(const std::string& text) const;

	public:
		std::string GetRegex() const;
		std::unique_ptr<CBStatemachineType> GetStatemachine() const;

	public:
		void Or(const CBRegex& rhs);
		void Concatenate(const CBRegex& rhs);
		bool Equal(const CBRegex& rhs) const;

	public:
		void Minimize();

	public:
		CBRegex& operator|=(const CBRegex& rhs);
		CBRegex& operator+=(const CBRegex& rhs);
		CBRegex& operator|(const CBRegex& rhs);
		CBRegex& operator+(const CBRegex& rhs);
		bool operator==(const CBRegex& rhs);

	public:
		CBRegex& operator|=(const std::string& rhs);
		CBRegex& operator+=(const std::string& rhs);
		CBRegex& operator|(const std::string& rhs);
		CBRegex& operator+(const std::string& rhs);
		bool operator==(const std::string& rhs);

	private:
		void SetRegex(const std::string& regex_);
		std::unique_ptr<CBStatemachineType> CreateDFA(const std::string& regex_);
	};

	bool operator==(const ::deamer::dregx::v2::CBRegex& lhs, const ::deamer::dregx::v2::CBRegex& rhs);
	bool operator==(const ::deamer::dregx::v2::CBRegex& lhs, const std::string& rhs);
	bool operator==(const std::string& lhs, const ::deamer::dregx::v2::CBRegex& rhs);
}

#endif // DEAMER_DREGX_V2_CBREGEX_H
