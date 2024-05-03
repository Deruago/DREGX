#include "Deamer/Dregx/V2/CBRegex.h"
#include "dregx/Ast/Listener/User/TranslateToIr.h"
#include "dregx/Bison/Parser.h"
#include "dregx/Statemachine/ConvertRegexToDFA.h"
#include "dregx/Statemachine/Statemachine.h"
#include <chrono>
#include <iostream>
#include <limits>

deamer::dregx::v2::CBRegex::CBRegex(const std::string& regex_, const std::size_t& flavor_)
	: flavor(flavor_)
{
	SetRegex(regex_);
}

bool deamer::dregx::v2::CBRegex::Match(const std::string& text) const
{
	return statemachine->Match(text);
}

std::string deamer::dregx::v2::CBRegex::GetRegex() const
{
	return regex;
}

std::unique_ptr<::deamer::dregx::v2::CBRegex::CBStatemachineType> deamer::dregx::v2::CBRegex::GetStatemachine() const
{
	auto copy = statemachine->Copy();
	return std::move(copy);
}

void deamer::dregx::v2::CBRegex::Or(const CBRegex& rhs)
{
	if (this == &rhs)
	{
		return;
	}

	const std::string copy = "(" + this->regex + "|" + rhs.regex + ")";
	this->regex = copy;

	const auto rhsCopy = rhs.GetStatemachine()->Copy();
	statemachine = statemachine->Or(*rhsCopy);
}

void deamer::dregx::v2::CBRegex::Concatenate(const CBRegex& rhs)
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

bool deamer::dregx::v2::CBRegex::Equal(const CBRegex& rhs) const
{
	rhs.statemachine->Minimize();
	statemachine->Minimize();

	return statemachine->Equal(*rhs.statemachine);
}

void deamer::dregx::v2::CBRegex::Minimize()
{
	this->statemachine->Minimize();
}

deamer::dregx::v2::CBRegex& deamer::dregx::v2::CBRegex::operator|=(const CBRegex& rhs)
{
	Or(rhs);
	return *this;
}

deamer::dregx::v2::CBRegex& deamer::dregx::v2::CBRegex::operator+=(const CBRegex& rhs)
{
	Concatenate(rhs);
	return *this;
}

deamer::dregx::v2::CBRegex& deamer::dregx::v2::CBRegex::operator|(const CBRegex& rhs)
{
	Or(rhs);
	return *this;
}

deamer::dregx::v2::CBRegex& deamer::dregx::v2::CBRegex::operator+(const CBRegex& rhs)
{
	Concatenate(rhs);
	return *this;
}

bool deamer::dregx::v2::CBRegex::operator==(const CBRegex& rhs)
{
	return Equal(rhs);
}

deamer::dregx::v2::CBRegex& deamer::dregx::v2::CBRegex::operator|=(const std::string& rhs)
{
	return (*this) |= CBRegex(rhs);
}

deamer::dregx::v2::CBRegex& deamer::dregx::v2::CBRegex::operator+=(const std::string& rhs)
{
	return (*this) += CBRegex(rhs);
}

deamer::dregx::v2::CBRegex& deamer::dregx::v2::CBRegex::operator|(const std::string& rhs)
{
	return (*this) |= CBRegex(rhs);
}

deamer::dregx::v2::CBRegex& deamer::dregx::v2::CBRegex::operator+(const std::string& rhs)
{
	return (*this) += CBRegex(rhs);
}

bool deamer::dregx::v2::CBRegex::operator==(const std::string& rhs)
{
	auto regex = CBRegex(rhs);
	return *this == regex;
}

void deamer::dregx::v2::CBRegex::SetRegex(const std::string& regex_)
{
	regex = regex_;
	auto newStatemachine = CreateDFA(regex);

	statemachine = std::move(newStatemachine);
}

std::unique_ptr<::deamer::dregx::v2::CBRegex::CBStatemachineType>
deamer::dregx::v2::CBRegex::CreateDFA(const std::string& regex_)
{
	using std::chrono::system_clock;
	auto startParsing = std::chrono::system_clock::now();

	const auto parser = ::dregx::parser::Parser();
	const auto tree = std::unique_ptr<::deamer::external::cpp::ast::Tree>(parser.Parse(regex_));
	if (tree == nullptr || tree->GetStartNode() == nullptr)
	{
		throw std::logic_error("CBRegex: " + regex_ + " is invalid");
	}
	auto listener = ::dregx::ast::listener::user::TranslateToIr();
	listener.Dispatch(tree->GetStartNode());

	auto ir = listener.GetOutput();
	ir->AddFlavor(std::to_string(flavor));

	auto end = std::chrono::system_clock::now();
	std::chrono::duration<double> diff = end - startParsing;
	// std::cout << "Parsing: " << diff.count() * 1000 << "ms\n";

	auto startV1 = std::chrono::system_clock::now();
	auto v1Statemachine = ::dregx::statemachine::ConvertRegexToDFA::ConvertToStatemachine(ir.get());

	end = std::chrono::system_clock::now();
	diff = end - startV1;
	// std::cout << "V1 construction: " << diff.count() * 1000 << "ms\n";

	auto startV2 = std::chrono::system_clock::now();

	auto v2Statemachine =
		std::make_unique<::deamer::dregx::v2::CBRegex::CBStatemachineType>(std::move(v1Statemachine), flavor);
	end = std::chrono::system_clock::now();
	diff = end - startV1;

	// std::cout << "V2 construction: " << diff.count() * 1000 << "ms\n";

	return std::move(v2Statemachine);
}

bool deamer::dregx::v2::operator==(const ::deamer::dregx::v2::CBRegex& lhs,
								   const ::deamer::dregx::v2::CBRegex& rhs)
{
	return lhs.Equal(rhs);
}

bool deamer::dregx::v2::operator==(const ::deamer::dregx::v2::CBRegex& lhs, const std::string& rhs)
{
	return lhs.Equal(::deamer::dregx::v2::CBRegex(rhs));
}

bool deamer::dregx::v2::operator==(const std::string& lhs, const ::deamer::dregx::v2::CBRegex& rhs)
{
	return ::deamer::dregx::v2::CBRegex(lhs).Equal(rhs);
}
