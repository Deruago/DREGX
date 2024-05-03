#include "Deamer/Dregx/V2/CBAnalyzer.h"
#include "dregx/Ast/Listener/User/TranslateToIr.h"
#include "dregx/Bison/Parser.h"
#include "dregx/Statemachine/ConvertRegexToDFA.h"

deamer::dregx::v2::CBAnalyzer::CBAnalyzer(const std::string& regex_)
{
	SetRegex(regex_);
}

void deamer::dregx::v2::CBAnalyzer::SetRegex(const std::string& regex_)
{
	regex = regex_;
	auto newStatemachine = CreateDFA(regex);
	newStatemachine->Minimize();

	statemachine = std::move(newStatemachine);
}

bool deamer::dregx::v2::CBAnalyzer::IsRegexSubsetOf(const std::string& rhs_regex_)
{
	// Copy rhs and our
	// rhs union our
	// check if rhs == rhs union our
	// If true, our is subset of rhs
	const auto rhsStatemachine = CreateDFA(rhs_regex_);
	rhsStatemachine->Minimize();
	auto copyRhsStatemachine = rhsStatemachine->Copy();

	const auto copyOur = statemachine->Copy();

	auto result = copyRhsStatemachine->Or(*copyOur);
	result->Minimize();

	return rhsStatemachine->Equal(*copyRhsStatemachine);
}

bool deamer::dregx::v2::CBAnalyzer::IsRegexBasesetOf(const std::string& rhs_regex_)
{
	// Copy rhs and our
	// rhs union our
	// check if our == our union rhs
	// If true, rhs is subset of our
	const auto rhsStatemachine = CreateDFA(rhs_regex_);
	rhsStatemachine->Minimize();
	auto copyRhsStatemachine = rhsStatemachine->Copy();

	const auto copyOur = statemachine->Copy();

	auto result = copyOur->Or(*copyRhsStatemachine);
	result->Minimize();

	return statemachine->Equal(*copyOur);
}

bool deamer::dregx::v2::CBAnalyzer::IsRegexDisjointOf(const std::string& rhs_regex_)
{
	const auto rhsStatemachine = CreateDFA(rhs_regex_);
	rhsStatemachine->Minimize();
	auto copyRhsStatemachine = rhsStatemachine->Copy();

	const auto copyOur = statemachine->Copy();

	auto result = copyOur->And(*copyRhsStatemachine);
 	result->Minimize();

	return result->IsEmptyLanguage();
}

std::unique_ptr<::deamer::dregx::v2::CBRegex::CBStatemachineType>
deamer::dregx::v2::CBAnalyzer::CreateDFA(const std::string& regex_)
{
	const auto parser = ::dregx::parser::Parser();
	const auto tree = std::unique_ptr<::deamer::external::cpp::ast::Tree>(parser.Parse(regex_));
	if (tree == nullptr || tree->GetStartNode() == nullptr)
	{
		throw std::logic_error("CBRegex: " + regex_ + " is invalid");
	}
	auto listener = ::dregx::ast::listener::user::TranslateToIr();
	listener.Dispatch(tree->GetStartNode());

	auto ir = listener.GetOutput();
	
	auto v1Statemachine = ::dregx::statemachine::ConvertRegexToDFA::ConvertToStatemachine(ir.get());

	auto v2Statemachine = std::make_unique<::deamer::dregx::v2::CBRegex::CBStatemachineType>(
		std::move(v1Statemachine));

	return std::move(v2Statemachine);
}
