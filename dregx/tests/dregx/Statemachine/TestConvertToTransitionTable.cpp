#include "Deamer/External/Cpp/Ast/Tree.h"
#include "dregx/Ast/Listener/User/TranslateToIr.h"
#include "dregx/Bison/Parser.h"
#include "dregx/Statemachine/ConvertRegexToDFA.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <memory>
#include <optional>

using namespace dregx;

class TestConvertToTransitionTable : public testing::Test
{
public:
protected:
	TestConvertToTransitionTable() = default;

	virtual ~TestConvertToTransitionTable() = default;

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

TEST_F(TestConvertToTransitionTable, A_ValidInput_ShouldMatchLanguageA)
{
	const auto capture = GetCapture("a");
	auto statemachine = statemachine::ConvertRegexToDFA::ConvertToStatemachine(capture.get());
	auto table = statemachine->ToTransitionTable();

	EXPECT_TRUE(table.Match("a"));
}

TEST_F(TestConvertToTransitionTable, A_InvalidInput_ShouldMatchLanguageA)
{
	const auto capture = GetCapture("a");
	auto statemachine = statemachine::ConvertRegexToDFA::ConvertToStatemachine(capture.get());
	auto table = statemachine->ToTransitionTable();

	EXPECT_FALSE(table.Match("b"));
	EXPECT_FALSE(table.Match("c"));
	EXPECT_FALSE(table.Match("d"));
	EXPECT_FALSE(table.Match("aa"));
	EXPECT_FALSE(table.Match("ab"));
	EXPECT_FALSE(table.Match("abc"));
}

TEST_F(TestConvertToTransitionTable, N0_ValidInput_ShouldMatchLanguageA)
{
	const auto capture = GetCapture("[0]");
	auto statemachine = statemachine::ConvertRegexToDFA::ConvertToStatemachine(capture.get());
	auto table = statemachine->ToTransitionTable();

	EXPECT_TRUE(table.Match("0"));
}

TEST_F(TestConvertToTransitionTable, N0_InvalidInput_ShouldMatchLanguageA)
{
	const auto capture = GetCapture("[0]");
	auto statemachine = statemachine::ConvertRegexToDFA::ConvertToStatemachine(capture.get());
	auto table = statemachine->ToTransitionTable();

	EXPECT_FALSE(table.Match(""));
	EXPECT_FALSE(table.Match("a"));
	EXPECT_FALSE(table.Match("d"));
	EXPECT_FALSE(table.Match("aa"));
	EXPECT_FALSE(table.Match("1"));
	EXPECT_FALSE(table.Match("2"));
	EXPECT_FALSE(table.Match("3"));
	EXPECT_FALSE(table.Match("11"));
	EXPECT_FALSE(table.Match("01"));
	EXPECT_FALSE(table.Match("10"));
}

TEST_F(TestConvertToTransitionTable, N01_ValidInput_ShouldMatchLanguageA)
{
	const auto capture = GetCapture("[01]");
	auto statemachine = statemachine::ConvertRegexToDFA::ConvertToStatemachine(capture.get());
	auto table = statemachine->ToTransitionTable();

	EXPECT_TRUE(table.Match("0"));
	EXPECT_TRUE(table.Match("1"));
}

TEST_F(TestConvertToTransitionTable, N01_InvalidInput_ShouldMatchLanguageA)
{
	const auto capture = GetCapture("[01]");
	auto statemachine = statemachine::ConvertRegexToDFA::ConvertToStatemachine(capture.get());
	auto table = statemachine->ToTransitionTable();

	EXPECT_FALSE(table.Match(""));
	EXPECT_FALSE(table.Match("a"));
	EXPECT_FALSE(table.Match("d"));
	EXPECT_FALSE(table.Match("aa"));
	EXPECT_FALSE(table.Match("2"));
	EXPECT_FALSE(table.Match("3"));
	EXPECT_FALSE(table.Match("4"));
	EXPECT_FALSE(table.Match("11"));
	EXPECT_FALSE(table.Match("01"));
	EXPECT_FALSE(table.Match("10"));
}

TEST_F(TestConvertToTransitionTable, ABC_ValidInput_ShouldMatchLanguageA)
{
	const auto capture = GetCapture("abc");
	auto statemachine = statemachine::ConvertRegexToDFA::ConvertToStatemachine(capture.get());
	auto table = statemachine->ToTransitionTable();

	EXPECT_TRUE(table.Match("abc"));
}

TEST_F(TestConvertToTransitionTable, ABC_InvalidInput_ShouldMatchLanguageA)
{
	const auto capture = GetCapture("abc");
	auto statemachine = statemachine::ConvertRegexToDFA::ConvertToStatemachine(capture.get());
	auto table = statemachine->ToTransitionTable();

	EXPECT_FALSE(table.Match("b"));
	EXPECT_FALSE(table.Match("c"));
	EXPECT_FALSE(table.Match("d"));
	EXPECT_FALSE(table.Match("aa"));
	EXPECT_FALSE(table.Match("ab"));
	EXPECT_FALSE(table.Match("bca"));
}

TEST_F(TestConvertToTransitionTable, A_OR_B_OR_C_D_ValidInput_ShouldMatchLanguageA)
{
	const auto capture = GetCapture("(a|b|c)d");
	auto statemachine = statemachine::ConvertRegexToDFA::ConvertToStatemachine(capture.get());
	auto table = statemachine->ToTransitionTable();

	EXPECT_TRUE(table.Match("ad"));
	EXPECT_TRUE(table.Match("bd"));
	EXPECT_TRUE(table.Match("cd"));
}

TEST_F(TestConvertToTransitionTable, A_OR_B_OR_C_D_InvalidInput_ShouldMatchLanguageA)
{
	const auto capture = GetCapture("(a|b|c)d");
	auto statemachine = statemachine::ConvertRegexToDFA::ConvertToStatemachine(capture.get());
	auto table = statemachine->ToTransitionTable();

	EXPECT_FALSE(table.Match("a"));
	EXPECT_FALSE(table.Match("b"));
	EXPECT_FALSE(table.Match("c"));
	EXPECT_FALSE(table.Match("d"));
	EXPECT_FALSE(table.Match("aa"));
	EXPECT_FALSE(table.Match("bb"));
	EXPECT_FALSE(table.Match("cc"));
	EXPECT_FALSE(table.Match("dd"));
}

TEST_F(TestConvertToTransitionTable, A_STAR_ValidInput_ShouldMatchLanguageA)
{
	const auto capture = GetCapture("[a]*");
	auto statemachine = statemachine::ConvertRegexToDFA::ConvertToStatemachine(capture.get());
	auto table = statemachine->ToTransitionTable();

	EXPECT_TRUE(table.Match(""));
	EXPECT_TRUE(table.Match("a"));
	EXPECT_TRUE(table.Match("aa"));
	EXPECT_TRUE(table.Match("aaa"));
	EXPECT_TRUE(table.Match("aaaa"));
	EXPECT_TRUE(table.Match("aaaaa"));
}

TEST_F(TestConvertToTransitionTable, A_STAR_InvalidInput_ShouldMatchLanguageA)
{
	const auto capture = GetCapture("[a]*");
	auto statemachine = statemachine::ConvertRegexToDFA::ConvertToStatemachine(capture.get());
	auto table = statemachine->ToTransitionTable();

	EXPECT_FALSE(table.Match("b"));
	EXPECT_FALSE(table.Match("c"));
	EXPECT_FALSE(table.Match("d"));
	EXPECT_FALSE(table.Match("ab"));
	EXPECT_FALSE(table.Match("aab"));
	EXPECT_FALSE(table.Match("bb"));
	EXPECT_FALSE(table.Match("cc"));
	EXPECT_FALSE(table.Match("dd"));
}

TEST_F(TestConvertToTransitionTable, A_PLUS_ValidInput_ShouldMatchLanguageA)
{
	const auto capture = GetCapture("[a]+");
	auto statemachine = statemachine::ConvertRegexToDFA::ConvertToStatemachine(capture.get());
	auto table = statemachine->ToTransitionTable();

	EXPECT_TRUE(table.Match("a"));
	EXPECT_TRUE(table.Match("aa"));
	EXPECT_TRUE(table.Match("aaa"));
	EXPECT_TRUE(table.Match("aaaa"));
	EXPECT_TRUE(table.Match("aaaaa"));
}

TEST_F(TestConvertToTransitionTable, A_PLUS_InvalidInput_ShouldMatchLanguageA)
{
	const auto capture = GetCapture("[a]+");
	auto statemachine = statemachine::ConvertRegexToDFA::ConvertToStatemachine(capture.get());
	auto table = statemachine->ToTransitionTable();

	EXPECT_FALSE(table.Match(""));
	EXPECT_FALSE(table.Match("c"));
	EXPECT_FALSE(table.Match("d"));
	EXPECT_FALSE(table.Match("ab"));
	EXPECT_FALSE(table.Match("aab"));
	EXPECT_FALSE(table.Match("bb"));
	EXPECT_FALSE(table.Match("cc"));
	EXPECT_FALSE(table.Match("dd"));
}

TEST_F(TestConvertToTransitionTable, A_B_PLUS_D_STAR_ValidInput_ShouldMatchLanguageA)
{
	const auto capture = GetCapture("((ab)+d)*");
	auto statemachine = statemachine::ConvertRegexToDFA::ConvertToStatemachine(capture.get());
	auto table = statemachine->ToTransitionTable();

	EXPECT_TRUE(table.Match(""));
	EXPECT_TRUE(table.Match("abd"));
	EXPECT_TRUE(table.Match("ababd"));
	EXPECT_TRUE(table.Match("abababd"));
	EXPECT_TRUE(table.Match("abdabd"));
	EXPECT_TRUE(table.Match("ababdabd"));
}

TEST_F(TestConvertToTransitionTable, A_B_PLUS_D_STAR_InvalidInput_ShouldMatchLanguageA)
{
	const auto capture = GetCapture("((ab)+d)*");
	auto statemachine = statemachine::ConvertRegexToDFA::ConvertToStatemachine(capture.get());
	auto table = statemachine->ToTransitionTable();

	EXPECT_FALSE(table.Match("ab"));
	EXPECT_FALSE(table.Match("abab"));
	EXPECT_FALSE(table.Match("ababab"));
	EXPECT_FALSE(table.Match("abdab"));
	EXPECT_FALSE(table.Match("d"));
	EXPECT_FALSE(table.Match("dd"));
	EXPECT_FALSE(table.Match("dab"));
	EXPECT_FALSE(table.Match("dabd"));
}

TEST_F(TestConvertToTransitionTable, OPTIONAL_A_ValidInput_ShouldMatchLanguageA)
{
	const auto capture = GetCapture("[a]?");
	auto statemachine = statemachine::ConvertRegexToDFA::ConvertToStatemachine(capture.get());
	auto table = statemachine->ToTransitionTable();

	EXPECT_TRUE(table.Match(""));
	EXPECT_TRUE(table.Match("a"));
}

TEST_F(TestConvertToTransitionTable, OPTIONAL_A_InvalidInput_ShouldMatchLanguageA)
{
	const auto capture = GetCapture("[a]?");
	auto statemachine = statemachine::ConvertRegexToDFA::ConvertToStatemachine(capture.get());
	auto table = statemachine->ToTransitionTable();

	EXPECT_FALSE(table.Match("aa"));
	EXPECT_FALSE(table.Match("abab"));
	EXPECT_FALSE(table.Match("ababab"));
	EXPECT_FALSE(table.Match("abdab"));
	EXPECT_FALSE(table.Match("d"));
	EXPECT_FALSE(table.Match("dd"));
	EXPECT_FALSE(table.Match("dab"));
	EXPECT_FALSE(table.Match("dabd"));
}

TEST_F(TestConvertToTransitionTable, OPTIONAL_A_B_ValidInput_ShouldMatchLanguageA)
{
	const auto capture = GetCapture("[a]?b");
	auto statemachine = statemachine::ConvertRegexToDFA::ConvertToStatemachine(capture.get());
	auto table = statemachine->ToTransitionTable();

	EXPECT_TRUE(table.Match("b"));
	EXPECT_TRUE(table.Match("ab"));
}

TEST_F(TestConvertToTransitionTable, OPTIONAL_A_B_InvalidInput_ShouldMatchLanguageA)
{
	const auto capture = GetCapture("[a]?b");
	auto statemachine = statemachine::ConvertRegexToDFA::ConvertToStatemachine(capture.get());
	auto table = statemachine->ToTransitionTable();

	EXPECT_FALSE(table.Match(""));
	EXPECT_FALSE(table.Match("a"));
	EXPECT_FALSE(table.Match("abb"));
	EXPECT_FALSE(table.Match("bb"));
	EXPECT_FALSE(table.Match("d"));
	EXPECT_FALSE(table.Match("dd"));
	EXPECT_FALSE(table.Match("dab"));
	EXPECT_FALSE(table.Match("dabd"));
}

TEST_F(TestConvertToTransitionTable, OPTIONAL_AB_OR_CD_ValidInput_ShouldMatchLanguageA)
{
	const auto capture = GetCapture("((cd)|([ab]?))");
	auto statemachine = statemachine::ConvertRegexToDFA::ConvertToStatemachine(capture.get());
	auto table = statemachine->ToTransitionTable();

	EXPECT_TRUE(table.Match(""));
	EXPECT_TRUE(table.Match("cd"));
	EXPECT_TRUE(table.Match("a"));
	EXPECT_TRUE(table.Match("b"));
}

TEST_F(TestConvertToTransitionTable, OPTIONAL_AB_AND_AV_OR_ABC_ValidInput_ShouldMatchLanguageA)
{
	const auto capture = GetCapture("((abc)|([ab]?av))");
	auto statemachine = statemachine::ConvertRegexToDFA::ConvertToStatemachine(capture.get());
	auto table = statemachine->ToTransitionTable();

	EXPECT_TRUE(table.Match("av"));
	EXPECT_TRUE(table.Match("aav"));
	EXPECT_TRUE(table.Match("bav"));
	EXPECT_TRUE(table.Match("abc"));
}

TEST_F(TestConvertToTransitionTable, OPTIONAL_AB_AND_AV_ValidInput_ShouldMatchLanguageA)
{
	const auto capture = GetCapture("[ab]?av");
	auto statemachine = statemachine::ConvertRegexToDFA::ConvertToStatemachine(capture.get());
	auto table = statemachine->ToTransitionTable();

	EXPECT_TRUE(table.Match("av"));
	EXPECT_TRUE(table.Match("aav"));
	EXPECT_TRUE(table.Match("bav"));
}

TEST_F(TestConvertToTransitionTable, IPV4_NUMBER_ValidInput_ShouldMatchLanguageA)
{
	const auto capture = GetCapture("((25[0-5])|(2[0-4][0-9])|([01]?[0-9][0-9]?))");
	auto statemachine = statemachine::ConvertRegexToDFA::ConvertToStatemachine(capture.get());
	auto table = statemachine->ToTransitionTable();

	EXPECT_TRUE(table.Match("0"));
	EXPECT_TRUE(table.Match("1"));
	EXPECT_TRUE(table.Match("9"));
	EXPECT_TRUE(table.Match("10"));
	EXPECT_TRUE(table.Match("11"));
	EXPECT_TRUE(table.Match("19"));
	EXPECT_TRUE(table.Match("00"));
	EXPECT_TRUE(table.Match("01"));
	EXPECT_TRUE(table.Match("09"));
	EXPECT_TRUE(table.Match("010"));
	EXPECT_TRUE(table.Match("011"));
	EXPECT_TRUE(table.Match("019"));
	EXPECT_TRUE(table.Match("000"));
	EXPECT_TRUE(table.Match("001"));
	EXPECT_TRUE(table.Match("009"));
	EXPECT_TRUE(table.Match("010"));
	EXPECT_TRUE(table.Match("011"));
	EXPECT_TRUE(table.Match("019"));
	EXPECT_TRUE(table.Match("100"));
	EXPECT_TRUE(table.Match("110"));
	EXPECT_TRUE(table.Match("111"));
	EXPECT_TRUE(table.Match("119"));
	EXPECT_TRUE(table.Match("191"));
	EXPECT_TRUE(table.Match("200"));
	EXPECT_TRUE(table.Match("201"));
	EXPECT_TRUE(table.Match("210"));
	EXPECT_TRUE(table.Match("211"));
	EXPECT_TRUE(table.Match("212"));
	EXPECT_TRUE(table.Match("222"));
	EXPECT_TRUE(table.Match("250"));
	EXPECT_TRUE(table.Match("255"));
}

TEST_F(TestConvertToTransitionTable, IPV4_ValidInput_ShouldMatchLanguageA)
{
	const auto capture = GetCapture(
		"((25[0-5])|(2[0-4][0-9])|([01]?[0-9][0-9]?))([\\.]((25[0-5])|(2[0-4][0-9])|([01]?[0-9][0-"
		"9]"
		"?)"
		")){"
		"3,3}");
	auto statemachine = statemachine::ConvertRegexToDFA::ConvertToStatemachine(capture.get());
	auto table = statemachine->ToTransitionTable();

	EXPECT_TRUE(table.Match("192.1.1.2"));
	EXPECT_TRUE(table.Match("255.255.255.255"));
	EXPECT_TRUE(table.Match("1.12.240.254"));
}

TEST_F(TestConvertToTransitionTable, IPV4_InvalidInput_ShouldMatchLanguageA)
{
	const auto capture = GetCapture(
		"((25[0-5])|(2[0-4][0-9])|([01]?[0-9][0-9]?))([\\.]((25[0-5])|(2[0-4][0-9])|([01]?[0-9][0-"
		"9]"
		"?)"
		")){"
		"3,3}");
	auto statemachine = statemachine::ConvertRegexToDFA::ConvertToStatemachine(capture.get());
	auto table = statemachine->ToTransitionTable();

	EXPECT_FALSE(table.Match("392.1.1.2"));
	EXPECT_FALSE(table.Match("255.300.1.2"));
	EXPECT_FALSE(table.Match("256.1.1.2"));
}
