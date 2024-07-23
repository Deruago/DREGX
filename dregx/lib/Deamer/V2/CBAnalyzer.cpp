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

bool deamer::dregx::v2::CBAnalyzer::IsFinite() const
{
	return !IsInfinite();
}

bool deamer::dregx::v2::CBAnalyzer::IsInfinite() const
{
	// As DFS is generally expensive for large statemachines
	// A BFS is performed, this approach can only proof if something is finite
	// Though not all finite regexes pass
	// For (possibly) false-positives the DFS approach is used to truly proof infiniteness

	auto copyStatemachine = statemachine->Copy();
	copyStatemachine->ToDFA();

	auto transitionTable = copyStatemachine->GetTransitionTable();
	std::set<std::size_t> visitedStates = {};
	std::set<std::size_t> states = {
		copyStatemachine->GetStateIndex(copyStatemachine->GetStartState())};

	while (!states.empty())
	{
		std::set<std::size_t> newStates;
		
		for (auto state : states)
		{
			visitedStates.insert(state);
		}

		for (auto state : states)
		{
			for (std::size_t index = 0; index < 256; index++)
			{
				auto nextState = copyStatemachine->GetStateIndex(
					transitionTable[state * copyStatemachine->totalAlphabetSize + index]);

				if (nextState == copyStatemachine->GetStateIndex(copyStatemachine->GetSinkState()))
				{
					continue;
				}

				auto iter = visitedStates.find(nextState);
				auto newIter = newStates.find(nextState);
				if (iter != visitedStates.end() && newIter == newStates.end())
				{
					// Check if from the next state we can reach itself
					// If so then it is guaranteed to be a cycle
					return CheckInfiniteDFS(
						nextState, {}, copyStatemachine, transitionTable);
				}

				if (nextState != state)
				{
					newStates.insert(nextState);
				}
			}
		}

		states = newStates;
	}

	// It is guaranteed to be non-cyclic
	return false;
}

bool deamer::dregx::v2::CBAnalyzer::CheckInfiniteDFS(
	std::size_t currentState, std::vector<std::size_t> stack,
	std::unique_ptr<deamer::dregx::v2::CBRegex::CBStatemachineType>& statemachine,
	std::vector<std::size_t> transitionTable) const
{
	for (auto state : stack)
	{
		if (state == currentState)
		{
			return true;
		}
	}

	auto newStack = stack;
	newStack.push_back(currentState);

	for (std::size_t index = 0; index < 256; index++)
	{
		auto nextState = statemachine->GetStateIndex(
			transitionTable[currentState * statemachine->totalAlphabetSize + index]);

		if (nextState == statemachine->GetStateIndex(statemachine->GetSinkState()))
		{
			continue;
		}

		if (CheckInfiniteDFS(nextState, newStack, statemachine, transitionTable))
		{
			return true;
		}
	}

	return false;
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

std::string deamer::dregx::v2::CBAnalyzer::ToDot()
{
	auto copyStatemachine = statemachine->Copy();
	copyStatemachine->ToDFA();
	auto transitionTable = copyStatemachine->GetTransitionTable();

	std::map<std::size_t, std::set<std::size_t>> mapStateWithTargets;

	for (std::size_t stateIndex = 0; stateIndex < copyStatemachine->GetTotalStates(); stateIndex++)
	{
		for (std::size_t index = 0; index < 256; index++)
		{
			auto nextState = copyStatemachine->GetStateIndex(
				transitionTable[stateIndex * copyStatemachine->totalAlphabetSize + index]);
			auto iter = mapStateWithTargets.find(stateIndex);
			if (iter == mapStateWithTargets.end())
			{
				mapStateWithTargets.insert({stateIndex, {}});
				iter = mapStateWithTargets.find(stateIndex);
			}

			iter->second.insert(nextState);
		}
	}

	std::string result = "digraph statemachine {\n";
	for (auto [state, targets] : mapStateWithTargets)
	{
		for (auto target : targets)
		{
			result += "\t";
			result += std::to_string(state) + " -> " + std::to_string(target) + "\n";
		}
	}
	result += "}\n";

	return result;
}


std::set<std::string> deamer::dregx::v2::CBAnalyzer::GetAllFiniteMatches()
{
	if (IsInfinite())
	{
		throw std::logic_error(
			"As the Regex is infinite it is impossible to enumerate all matches.");
	}

	const auto copyOur = statemachine->Copy();
	std::set<std::string> result;
	for (std::size_t index = 0; index < 256; index++)
	{
		auto localResult = GetAllFiniteMatchesImplementation(
			copyOur.get(),
			copyOur->GetTransitionTable()[copyOur->GetStartState() * copyOur->totalAlphabetSize +
										  index]);

		for (auto element : localResult)
		{
			result.insert(static_cast<char>(index) + element);
		}
	}
	return result;
}

std::set<std::string> deamer::dregx::v2::CBAnalyzer::GetAllFiniteMatchesImplementation(
	::deamer::dregx::v2::CBRegex::CBStatemachineType* copiedStatemachine, std::size_t stateIndex)
{
	std::set<std::string> output;

	if (copiedStatemachine->GetStateIndex(copiedStatemachine->GetStartState()) ==
		copiedStatemachine->GetStateIndex(stateIndex))
	{
		return {};
	}

	if (copiedStatemachine->GetStateAcceptance(stateIndex))
	{
		// If it is an accept state
		// Add an empty string to allow callers to append the conditional.
		output.insert("");
	}

	for (std::size_t index = 0; index < 256; index++)
	{
		auto nextState =
			copiedStatemachine->GetTransitionTable()[copiedStatemachine->GetStateIndex(stateIndex) *
														 copiedStatemachine->totalAlphabetSize +
													 index];

		if (copiedStatemachine->GetStateIndex(nextState) ==
			copiedStatemachine->GetStateIndex(copiedStatemachine->GetSinkState()))
		{
			continue;
		}

		const auto results = GetAllFiniteMatchesImplementation(copiedStatemachine, nextState);
		for (const auto& result : results)
		{
			output.insert(static_cast<char>(index) + result);
		}
	}

	return output;
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
