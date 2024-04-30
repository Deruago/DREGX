#include "Deamer/Dregx/V2/Regex.h"
#include "dregx/Ast/Listener/User/TranslateToIr.h"
#include "dregx/Bison/Parser.h"
#include "dregx/Statemachine/ConvertRegexToDFA.h"
#include "dregx/Statemachine/Statemachine.h"
#include <limits>
#include <chrono>
#include <iostream>

deamer::dregx::v2::Regex::Regex(const std::string& regex_, const std::string& flavor_)
{
	flavor = flavor_;
	SetRegex(regex_);
}

bool deamer::dregx::v2::Regex::Match(const std::string& text) const
{
	return statemachine->Match(text);
}

std::string deamer::dregx::v2::Regex::GetRegex() const
{
	return regex;
}

std::unique_ptr<::deamer::dregx::v2::Statemachine>
deamer::dregx::v2::Regex::GetStatemachine() const
{
	auto copy = statemachine->Copy();
	return std::move(copy);
}

void deamer::dregx::v2::Regex::Or(const Regex& rhs)
{
	if (this == &rhs)
	{
		return;
	}

	const std::string copy = "(" + this->regex + "|" + rhs.regex + ")";
	this->regex = copy;

	const auto rhsCopy = rhs.GetStatemachine()->Copy();
	statemachine = statemachine->Or(*rhsCopy);
	// statemachine->ToDFA();
}

void deamer::dregx::v2::Regex::Concatenate(const Regex& rhs)
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

bool deamer::dregx::v2::Regex::Equal(const Regex& rhs) const
{
	rhs.statemachine->Minimize();
	statemachine->Minimize();

	return statemachine->Equal(*rhs.statemachine);
}

void deamer::dregx::v2::Regex::Minimize()
{
	this->statemachine->Minimize();
}


deamer::dregx::v2::Regex& deamer::dregx::v2::Regex::operator|=(const Regex& rhs)
{
	Or(rhs);
	return *this;
}

deamer::dregx::v2::Regex& deamer::dregx::v2::Regex::operator+=(const Regex& rhs)
{
	Concatenate(rhs);
	return *this;
}

deamer::dregx::v2::Regex& deamer::dregx::v2::Regex::operator|(const Regex& rhs)
{
	Or(rhs);
	return *this;
}

deamer::dregx::v2::Regex& deamer::dregx::v2::Regex::operator+(const Regex& rhs)
{
	Concatenate(rhs);
	return *this;
}

bool deamer::dregx::v2::Regex::operator==(const Regex& rhs)
{
	return Equal(rhs);
}

deamer::dregx::v2::Regex& deamer::dregx::v2::Regex::operator|=(const std::string& rhs)
{
	return (*this) |= Regex(rhs);
}

deamer::dregx::v2::Regex& deamer::dregx::v2::Regex::operator+=(const std::string& rhs)
{
	return (*this) += Regex(rhs);
}

deamer::dregx::v2::Regex& deamer::dregx::v2::Regex::operator|(const std::string& rhs)
{
	return (*this) |= Regex(rhs);
}

deamer::dregx::v2::Regex& deamer::dregx::v2::Regex::operator+(const std::string& rhs)
{
	return (*this) += Regex(rhs);
}

bool deamer::dregx::v2::Regex::operator==(const std::string& rhs)
{
	auto regex = Regex(rhs);
	return *this == regex;
}

void deamer::dregx::v2::Regex::SetRegex(const std::string& regex_)
{
	regex = regex_;
	auto newStatemachine = CreateDFA(regex);

	statemachine = std::move(newStatemachine);
}

std::unique_ptr<::deamer::dregx::v2::Statemachine>
deamer::dregx::v2::Regex::CreateDFA(const std::string& regex_)
{
	using std::chrono::system_clock;
	auto startParsing = std::chrono::system_clock::now();

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

	auto end = std::chrono::system_clock::now();
	std::chrono::duration<double> diff = end - startParsing;
	std::cout << "Parsing: " << diff.count() * 1000 << "ms\n";
	
	auto startV1 = std::chrono::system_clock::now();
	auto v1Statemachine = ::dregx::statemachine::ConvertRegexToDFA::ConvertToStatemachine(ir.get());

	end = std::chrono::system_clock::now();
	diff = end - startV1;
	std::cout << "V1 construction: " << diff.count() * 1000 << "ms\n";

	auto startV2 = std::chrono::system_clock::now();

	auto v2Statemachine = std::make_unique<::deamer::dregx::v2::Statemachine>(std::move(v1Statemachine));
	end = std::chrono::system_clock::now();
	diff = end - startV1;
	
	std::cout << "V2 construction: " << diff.count() * 1000 << "ms\n";

	return std::move(v2Statemachine);
}

bool deamer::dregx::v2::operator==(const ::deamer::dregx::v2::Regex& lhs,
							   const ::deamer::dregx::v2::Regex& rhs)
{
	return lhs.Equal(rhs);
}

bool deamer::dregx::v2::operator==(const ::deamer::dregx::v2::Regex& lhs, const std::string& rhs)
{
	return lhs.Equal(::deamer::dregx::v2::Regex(rhs));
}

bool deamer::dregx::v2::operator==(const std::string& lhs, const ::deamer::dregx::v2::Regex& rhs)
{
	return ::deamer::dregx::v2::Regex(lhs).Equal(rhs);
}
