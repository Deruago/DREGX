#include "Deamer/External/Cpp/Ast/Tree.h"
#include "dregx/Ast/Listener/User/TranslateToIr.h"
#include "dregx/Bison/Parser.h"
#include "dregx/Statemachine/ConvertRegexToDFA.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <memory>
#include <optional>

using namespace dregx;

class TestEqualDFA : public testing::Test
{
public:
protected:
	TestEqualDFA() = default;

	virtual ~TestEqualDFA() = default;

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

TEST_F(TestEqualDFA, CompareDFA_REG1_A_REG2_A_RETURN_TRUE)
{
	const auto capture1 = GetCapture("a");
	auto statemachine1 = statemachine::ConvertRegexToDFA::ConvertToStatemachine(capture1.get());
	const auto capture2 = GetCapture("a");
	auto statemachine2 = statemachine::ConvertRegexToDFA::ConvertToStatemachine(capture2.get());

	EXPECT_TRUE(statemachine1->Equal(*statemachine2));
	EXPECT_TRUE(statemachine2->Equal(*statemachine1));

	statemachine1->Minimize();
	statemachine2->Minimize();

	EXPECT_TRUE(statemachine1->Equal(*statemachine2));
	EXPECT_TRUE(statemachine2->Equal(*statemachine1));
}

TEST_F(TestEqualDFA, CompareDFA_REG1_A_REG2_B_RETURN_FALSE)
{
	const auto capture1 = GetCapture("a");
	auto statemachine1 = statemachine::ConvertRegexToDFA::ConvertToStatemachine(capture1.get());
	const auto capture2 = GetCapture("b");
	auto statemachine2 = statemachine::ConvertRegexToDFA::ConvertToStatemachine(capture2.get());

	EXPECT_FALSE(statemachine1->Equal(*statemachine2));
	EXPECT_FALSE(statemachine2->Equal(*statemachine1));

	statemachine1->Minimize();
	statemachine2->Minimize();

	EXPECT_FALSE(statemachine1->Equal(*statemachine2));
	EXPECT_FALSE(statemachine2->Equal(*statemachine1));
}

TEST_F(TestEqualDFA, CompareDFA_REG1_AB_REG2_AB_RETURN_TRUE)
{
	const auto capture1 = GetCapture("ab");
	auto statemachine1 = statemachine::ConvertRegexToDFA::ConvertToStatemachine(capture1.get());
	const auto capture2 = GetCapture("ab");
	auto statemachine2 = statemachine::ConvertRegexToDFA::ConvertToStatemachine(capture2.get());

	EXPECT_TRUE(statemachine1->Equal(*statemachine2));
	EXPECT_TRUE(statemachine2->Equal(*statemachine1));

	statemachine1->Minimize();
	statemachine2->Minimize();

	EXPECT_TRUE(statemachine1->Equal(*statemachine2));
	EXPECT_TRUE(statemachine2->Equal(*statemachine1));
}

TEST_F(TestEqualDFA, CompareDFA_REG1_AB_REG2_AC_RETURN_FALSE)
{
	const auto capture1 = GetCapture("ab");
	auto statemachine1 = statemachine::ConvertRegexToDFA::ConvertToStatemachine(capture1.get());
	const auto capture2 = GetCapture("ac");
	auto statemachine2 = statemachine::ConvertRegexToDFA::ConvertToStatemachine(capture2.get());

	EXPECT_FALSE(statemachine1->Equal(*statemachine2));
	EXPECT_FALSE(statemachine2->Equal(*statemachine1));

	statemachine1->Minimize();
	statemachine2->Minimize();

	EXPECT_FALSE(statemachine1->Equal(*statemachine2));
	EXPECT_FALSE(statemachine2->Equal(*statemachine1));
}

TEST_F(TestEqualDFA, CompareDFA_REG1_AC_OPT_PLUS_D_STAR_E_REG2_AC_OPT_PLUS_D_STAR_E_RETURN_TRUE)
{
	const auto capture1 = GetCapture("(((ac)?)+d)*e");
	auto statemachine1 = statemachine::ConvertRegexToDFA::ConvertToStatemachine(capture1.get());
	const auto capture2 = GetCapture("(((ac)?)+d)*e");
	auto statemachine2 = statemachine::ConvertRegexToDFA::ConvertToStatemachine(capture2.get());

	EXPECT_TRUE(statemachine1->Equal(*statemachine2));
	EXPECT_TRUE(statemachine2->Equal(*statemachine1));

	statemachine1->Minimize();
	statemachine2->Minimize();

	EXPECT_TRUE(statemachine1->Equal(*statemachine2));
	EXPECT_TRUE(statemachine2->Equal(*statemachine1));
}

TEST_F(TestEqualDFA, CompareDFA_REG1_AC_OPT_PLUS_D_STAR_E_REG2_AC_OPT_PLUS_D_STAR_F_RETURN_FALSE)
{
	const auto capture1 = GetCapture("(((ac)?)+d)*e");
	auto statemachine1 = statemachine::ConvertRegexToDFA::ConvertToStatemachine(capture1.get());
	const auto capture2 = GetCapture("(((ac)?)+d)*f");
	auto statemachine2 = statemachine::ConvertRegexToDFA::ConvertToStatemachine(capture2.get());

	EXPECT_FALSE(statemachine1->Equal(*statemachine2));
	EXPECT_FALSE(statemachine2->Equal(*statemachine1));

	statemachine1->Minimize();
	statemachine2->Minimize();

	EXPECT_FALSE(statemachine1->Equal(*statemachine2));
	EXPECT_FALSE(statemachine2->Equal(*statemachine1));
}

TEST_F(TestEqualDFA, CompareDFA_REG1_A_STAR_REG2_A_STAR_STAR_RETURN_TRUE)
{
	const auto capture1 = GetCapture("(a)*");
	auto statemachine1 = statemachine::ConvertRegexToDFA::ConvertToStatemachine(capture1.get());
	const auto capture2 = GetCapture("((a)*)*");
	auto statemachine2 = statemachine::ConvertRegexToDFA::ConvertToStatemachine(capture2.get());

	EXPECT_TRUE(statemachine1->Equal(*statemachine2));
	EXPECT_TRUE(statemachine2->Equal(*statemachine1));

	statemachine1->Minimize();
	statemachine2->Minimize();

	EXPECT_TRUE(statemachine1->Equal(*statemachine2));
	EXPECT_TRUE(statemachine2->Equal(*statemachine1));
}

TEST_F(TestEqualDFA, CompareDFA_REG1_AB_OPT_D_REG2_D_OR_ABD_RETURN_TRUE)
{
	const auto capture1 = GetCapture("(ab)?d");
	auto statemachine1 = statemachine::ConvertRegexToDFA::ConvertToStatemachine(capture1.get());
	const auto capture2 = GetCapture("((d)|(abd))");
	auto statemachine2 = statemachine::ConvertRegexToDFA::ConvertToStatemachine(capture2.get());

	statemachine1->Minimize();
	statemachine2->Minimize();

	EXPECT_TRUE(statemachine1->Equal(*statemachine2));
	EXPECT_TRUE(statemachine2->Equal(*statemachine1));
}

TEST_F(TestEqualDFA, CompareDFA_REG1_AB_OPT_D_REG2_AB_OR_EMPTY_D_ABD_RETURN_FALSE)
{
	const auto capture1 = GetCapture("(ab)?d");
	auto statemachine1 = statemachine::ConvertRegexToDFA::ConvertToStatemachine(capture1.get());
	const auto capture2 = GetCapture("((ab)|([])|(d)|(abd))");
	auto statemachine2 = statemachine::ConvertRegexToDFA::ConvertToStatemachine(capture2.get());

	EXPECT_FALSE(statemachine1->Equal(*statemachine2));
	EXPECT_FALSE(statemachine2->Equal(*statemachine1));

	statemachine1->Minimize();
	statemachine2->Minimize();

	EXPECT_FALSE(statemachine1->Equal(*statemachine2));
	EXPECT_FALSE(statemachine2->Equal(*statemachine1));
}
