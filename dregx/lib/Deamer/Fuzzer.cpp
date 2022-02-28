#include "Deamer/Dregx/Fuzzer.h"
#include "dregx/Ast/Listener/User/TranslateToIr.h"
#include "dregx/Bison/Parser.h"
#include "dregx/Statemachine/ConvertRegexToDFA.h"
#include <limits>

deamer::dregx::Fuzzer::Fuzzer(const std::string& regex_)
{
	SetRegex(regex_);
}

void deamer::dregx::Fuzzer::SetRegex(const std::string& regex_)
{
	regex = regex_;
	auto newStatemachine = CreateDFA(regex);
	newStatemachine->Minimize();

	statemachine = std::move(newStatemachine);
}

std::string deamer::dregx::Fuzzer::GetMinimalExample() const
{
	statemachine->UpdateDepth();

	std::size_t lowestDepth = std::numeric_limits<std::size_t>::max();
	::dregx::statemachine::State* acceptStateWithLowestDepth = nullptr;
	for (auto* acceptState : statemachine->GetAcceptStates())
	{
		if (acceptState->GetDepth() < lowestDepth)
		{
			lowestDepth = acceptState->GetDepth();
			acceptStateWithLowestDepth = acceptState;
		}
	}

	if (acceptStateWithLowestDepth == nullptr)
	{
		throw std::logic_error("There are no accept states in statemachine!");
	}

	std::vector<::dregx::statemachine::State*> pathToAcceptState(lowestDepth);
	std::vector<::dregx::statemachine::Transition*> transitionPathToAcceptState(lowestDepth);

	auto* currentState = acceptStateWithLowestDepth;
	while (currentState != nullptr)
	{
		std::size_t lowestTransitionDepth = currentState->GetDepth();
		::dregx::statemachine::State* inStateWithLowestDepth = nullptr;
		::dregx::statemachine::Transition* inTransitionWithLowestDepth = nullptr;
		for (auto* transition : currentState->GetInTransitions())
		{
			auto* inState = transition->GetInState();
			if (inState->GetDepth() < lowestTransitionDepth)
			{
				lowestTransitionDepth = inState->GetDepth();
				inStateWithLowestDepth = inState;
				inTransitionWithLowestDepth = transition;
			}
		}
		if (inTransitionWithLowestDepth == nullptr || inStateWithLowestDepth == nullptr)
		{
			break;
		}

		transitionPathToAcceptState[lowestTransitionDepth] = inTransitionWithLowestDepth;
		pathToAcceptState[lowestTransitionDepth] = inStateWithLowestDepth;
		currentState = inStateWithLowestDepth;
	}

	std::string minimalExample;
	for (auto* transition : transitionPathToAcceptState)
	{
		minimalExample += transition->GetConditions()[0].GetCharacter();
	}

	return minimalExample;
}

std::unique_ptr<::dregx::statemachine::Statemachine>
deamer::dregx::Fuzzer::CreateDFA(const std::string& regex_)
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
