#include "Deamer/Dregx/Regex.h"
#include "dregx/Ast/Listener/User/TranslateToIr.h"
#include "dregx/Bison/Parser.h"
#include "dregx/Statemachine/ConvertRegexToDFA.h"
#include <limits>

deamer::dregx::Regex::Regex(const std::string& regex_, const std::string& flavor_)
{
	flavor = flavor_;
	SetRegex(regex_);
}

bool deamer::dregx::Regex::Match(const std::string& text) const
{
	return statemachine->ToTransitionTable().Match(text);
}

std::string deamer::dregx::Regex::GetRegex() const
{
	return regex;
}

std::unique_ptr<::dregx::statemachine::Statemachine> deamer::dregx::Regex::GetStatemachine() const
{
	auto copy = statemachine->Copy();
	return std::move(copy);
}

void deamer::dregx::Regex::Or(const Regex& rhs)
{
	if (this == &rhs)
	{
		return;
	}

	const std::string copy = "(" + this->regex + "|" + rhs.regex + ")";
	this->regex = copy;

	const auto rhsCopy = rhs.GetStatemachine()->Copy();
	statemachine->Or(*rhsCopy);
	statemachine->ToDFA();
}

void deamer::dregx::Regex::Concatenate(const Regex& rhs)
{
	if (this == &rhs)
	{
		this->regex += this->regex;
	}
	else
	{
		this->regex += rhs.regex;
	}

	const auto rhsCopy = rhs.GetStatemachine()->Copy();
	statemachine->Concatenate(*rhsCopy);
	statemachine->ToDFA();
}

bool deamer::dregx::Regex::Equal(const Regex& rhs) const
{
	rhs.statemachine->Minimize();
	statemachine->Minimize();

	return statemachine->Equal(*rhs.statemachine);
}

void deamer::dregx::Regex::Minimize()
{
	this->statemachine->Minimize();
}


deamer::dregx::Regex& deamer::dregx::Regex::operator|=(const Regex& rhs)
{
	Or(rhs);
	return *this;
}

deamer::dregx::Regex& deamer::dregx::Regex::operator+=(const Regex& rhs)
{
	Concatenate(rhs);
	return *this;
}

deamer::dregx::Regex& deamer::dregx::Regex::operator|(const Regex& rhs)
{
	Or(rhs);
	return *this;
}

deamer::dregx::Regex& deamer::dregx::Regex::operator+(const Regex& rhs)
{
	Concatenate(rhs);
	return *this;
}

bool deamer::dregx::Regex::operator==(const Regex& rhs)
{
	return Equal(rhs);
}

deamer::dregx::Regex& deamer::dregx::Regex::operator|=(const std::string& rhs)
{
	return (*this) |= Regex(rhs);
}

deamer::dregx::Regex& deamer::dregx::Regex::operator+=(const std::string& rhs)
{
	return (*this) += Regex(rhs);
}

deamer::dregx::Regex& deamer::dregx::Regex::operator|(const std::string& rhs)
{
	return (*this) |= Regex(rhs);
}

deamer::dregx::Regex& deamer::dregx::Regex::operator+(const std::string& rhs)
{
	return (*this) += Regex(rhs);
}

bool deamer::dregx::Regex::operator==(const std::string& rhs)
{
	auto regex = Regex(rhs);
	return *this == regex;
}

void deamer::dregx::Regex::SetRegex(const std::string& regex_)
{
	regex = regex_;
	
	auto newStatemachine = CreateDFA(regex);
	newStatemachine->Minimize();

	statemachine = std::move(newStatemachine);
}

std::unique_ptr<::dregx::statemachine::Statemachine>
deamer::dregx::Regex::CreateDFA(const std::string& regex_)
{
	const auto parser = ::dregx::parser::Parser();
	const auto tree = std::unique_ptr<::deamer::external::cpp::ast::Tree>(parser.Parse(regex_));
	if (tree == nullptr || tree->GetStartNode() == nullptr)
	{
		throw std::logic_error("Regex: " + regex_ + " is invalid");
	}
	auto listener = ::dregx::ast::listener::user::TranslateToIr();
	listener.Dispatch(tree->GetStartNode());

	auto ir = listener.GetOutput();
	ir->AddFlavor(flavor);

	return std::move(::dregx::statemachine::ConvertRegexToDFA::ConvertToStatemachine(ir.get()));
}

bool deamer::dregx::operator==(const Regex& lhs, const Regex& rhs)
{
	return lhs.Equal(rhs);
}

bool deamer::dregx::operator==(const Regex& lhs, const std::string& rhs)
{
	return lhs.Equal(Regex(rhs));
}

bool deamer::dregx::operator==(const std::string& lhs, const Regex& rhs)
{
	return Regex(lhs).Equal(rhs);
}
