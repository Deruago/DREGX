#include "Deamer/External/Cpp/Ast/Tree.h"
#include "dregx/Ast/Listener/User/TranslateToIr.h"
#include "dregx/Bison/Parser.h"
#include "dregx/Statemachine/ConvertRegexToDFA.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <memory>
#include <optional>

using namespace dregx;

class TestAndDFA : public testing::Test
{
public:
protected:
	TestAndDFA() = default;

	virtual ~TestAndDFA() = default;

public:
	parser::Parser parser;
	ast::listener::user::TranslateToIr translator;
	std::unique_ptr<deamer::external::cpp::ast::Tree> tree_;

public:
	std::unique_ptr<ir::Capture> GetCapture(const std::string& text)
	{
		tree_ = std::unique_ptr<deamer::external::cpp::ast::Tree>(parser.Parse(text));

		if (tree_ == nullptr)
		{
			throw std::logic_error(
				"Text could not get parsed, parser related unit tests should fail.");
		}

		if (tree_->GetStartNode() == nullptr)
		{
			throw std::logic_error(
				"Text could not get parsed, parser related unit tests should fail.");
		}

		translator.Dispatch(tree_->GetStartNode());

		auto capture = translator.GetOutput();
		if (capture == nullptr)
		{
			throw std::logic_error(
				"AST could not get converted, AST translator related unit tests should fail.");
		}

		return capture;
	}
};

TEST_F(TestAndDFA, CompareDFA_REG1_A_REG2_A_RETURN_TRUE)
{
	const auto capture1 = GetCapture("a");
	auto statemachine1 = statemachine::ConvertRegexToDFA::ConvertToStatemachine(capture1.get());
	const auto capture2 = GetCapture("a");
	auto statemachine2 = statemachine::ConvertRegexToDFA::ConvertToStatemachine(capture2.get());

	auto statemachine1Copy = statemachine1->Copy();
	statemachine1Copy->ToTransitionTable().Print();
	statemachine1Copy->And(*statemachine2->Copy());
	statemachine1Copy->ToTransitionTable().Print();

	auto statemachine2Copy = statemachine2->Copy();
	statemachine2Copy->And(*statemachine1->Copy());

	statemachine1->ToTransitionTable().Print();
	statemachine1->Minimize();
	statemachine1->ToTransitionTable().Print();

	statemachine2->ToTransitionTable().Print();
	statemachine2->Minimize();
	statemachine2->ToTransitionTable().Print();

	statemachine1Copy->Minimize();
	statemachine1Copy->ToTransitionTable().Print();

	statemachine2Copy->ToTransitionTable().Print();
	statemachine2Copy->Minimize();
	statemachine2Copy->ToTransitionTable().Print();

	auto statemachine1MinimizedCopy = statemachine1->Copy();
	statemachine1MinimizedCopy->And(*statemachine2->Copy());
	statemachine1MinimizedCopy->ToTransitionTable().Print();
	statemachine1MinimizedCopy->Minimize();
	statemachine1MinimizedCopy->ToTransitionTable().Print();

	auto statemachine2MinimizedCopy = statemachine2->Copy();
	statemachine2MinimizedCopy->And(*statemachine1->Copy());
	statemachine2MinimizedCopy->ToTransitionTable().Print();
	statemachine2MinimizedCopy->Minimize();
	statemachine2MinimizedCopy->ToTransitionTable().Print();

	EXPECT_TRUE(statemachine1->Equal(*statemachine1Copy));
	EXPECT_TRUE(statemachine2->Equal(*statemachine2Copy));
	EXPECT_TRUE(statemachine1->Equal(*statemachine1MinimizedCopy));
	EXPECT_TRUE(statemachine2->Equal(*statemachine2MinimizedCopy));
}
