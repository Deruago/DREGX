#include "Deamer/Dregx/Fuzzer.h"
#include "Deamer/External/Cpp/Ast/Tree.h"
#include "dregx/Ast/Listener/User/TranslateToIr.h"
#include "dregx/Bison/Parser.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <memory>
#include <optional>

using namespace dregx;

class TestFuzzer : public testing::Test
{
public:
protected:
	TestFuzzer() = default;

	virtual ~TestFuzzer() = default;

public:
	parser::Parser parser;
	ast::listener::user::TranslateToIr translator;
	std::unique_ptr<deamer::external::cpp::ast::Tree> tree_;

public:
	std::optional<const deamer::external::cpp::ast::Node*> Parse(const std::string& text)
	{
		tree_ = std::unique_ptr<deamer::external::cpp::ast::Tree>(parser.Parse(text));

		if (tree_ == nullptr)
		{
			return std::nullopt;
		}

		if (tree_->GetStartNode() == nullptr)
		{
			return std::nullopt;
		}

		return tree_->GetStartNode();
	}
};

TEST_F(TestFuzzer, MinimalExample_Regex_A_Return_A)
{
	auto fuzzer = deamer::dregx::Fuzzer();
	fuzzer.SetRegex("a");
	const auto example = fuzzer.GetMinimalExample();

	EXPECT_EQ("a", example);
}

TEST_F(TestFuzzer, MinimalExample_Regex_AB_Return_AB)
{
	auto fuzzer = deamer::dregx::Fuzzer();
	fuzzer.SetRegex("ab");
	const auto example = fuzzer.GetMinimalExample();

	EXPECT_EQ("ab", example);
}

TEST_F(TestFuzzer, MinimalExample_Regex_ABC_Return_ABC)
{
	auto fuzzer = deamer::dregx::Fuzzer();
	fuzzer.SetRegex("abc");
	const auto example = fuzzer.GetMinimalExample();

	EXPECT_EQ("abc", example);
}

TEST_F(TestFuzzer, MinimalExample_Regex_A_OR_B_Return_A)
{
	auto fuzzer = deamer::dregx::Fuzzer();
	fuzzer.SetRegex("((a)|(b))");
	const auto example = fuzzer.GetMinimalExample();

	EXPECT_TRUE("a" == example || "b" == example);
}

TEST_F(TestFuzzer, MinimalExample_Regex_A_STAR_Return_Empty)
{
	auto fuzzer = deamer::dregx::Fuzzer();
	fuzzer.SetRegex("(a)*");
	const auto example = fuzzer.GetMinimalExample();

	EXPECT_EQ("", example);
}

TEST_F(TestFuzzer, MinimalExample_Regex_A_PLUS_Return_A)
{
	auto fuzzer = deamer::dregx::Fuzzer();
	fuzzer.SetRegex("(a)+");
	const auto example = fuzzer.GetMinimalExample();

	EXPECT_EQ("a", example);
}

TEST_F(TestFuzzer, MinimalExample_Regex_A_PLUS_AB_PLUS_Return_AAB)
{
	auto fuzzer = deamer::dregx::Fuzzer();
	fuzzer.SetRegex("(a)+(ab)+");
	const auto example = fuzzer.GetMinimalExample();

	EXPECT_EQ("aab", example);
}
