#include "Deamer/Dregx/Analyzer.h"
#include "dregx/Ast/Listener/User/TranslateToIr.h"
#include "dregx/Bison/Parser.h"
#include "dregx/Statemachine/ConvertRegexToDFA.h"

deamer::dregx::Analyzer::Analyzer(const std::string& regex_)
{
	SetRegex(regex_);
}

void deamer::dregx::Analyzer::SetRegex(const std::string& regex_)
{
	regex = regex_;
	auto newStatemachine = CreateDFA(regex);
	newStatemachine->Minimize();

	statemachine = std::move(newStatemachine);
}

bool deamer::dregx::Analyzer::IsRegexSubsetOf(const std::string& rhs_regex_)
{
	// Copy rhs and our
	// rhs union our
	// check if rhs == rhs union our
	// If true, our is subset of rhs
	const auto rhsStatemachine = CreateDFA(rhs_regex_);
	rhsStatemachine->Minimize();
	auto copyRhsStatemachine = rhsStatemachine->Copy();

	const auto copyOur = statemachine->Copy();

	copyRhsStatemachine->Or(*copyOur);
	copyRhsStatemachine->Minimize();

	return rhsStatemachine->Equal(*copyRhsStatemachine);
}

bool deamer::dregx::Analyzer::IsRegexBasesetOf(const std::string& rhs_regex_)
{
	// Copy rhs and our
	// rhs union our
	// check if our == our union rhs
	// If true, rhs is subset of our
	const auto rhsStatemachine = CreateDFA(rhs_regex_);
	rhsStatemachine->Minimize();
	auto copyRhsStatemachine = rhsStatemachine->Copy();

	const auto copyOur = statemachine->Copy();

	copyOur->Or(*copyRhsStatemachine);
	copyOur->Minimize();

	return statemachine->Equal(*copyOur);
}

std::unique_ptr<::dregx::statemachine::Statemachine>
deamer::dregx::Analyzer::CreateDFA(const std::string& regex_)
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

	return std::move(::dregx::statemachine::ConvertRegexToDFA::ConvertToStatemachine(ir.get()));
}
