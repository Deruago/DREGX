#include "Deamer/Dregx/Fuzzer.h"
#include "Deamer/External/Cpp/Ast/Tree.h"
#include "dregx/Ast/Listener/User/TranslateToIr.h"
#include "dregx/Bison/Parser.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <memory>
#include <optional>

// clang-format off
#define EXPECT_ONCE_IN(var, vars) do { int total = 0; for (auto _ : vars) { if (var == _) { total++; } } EXPECT_EQ(1, total); } while(0);
#define EXPECT_IN(var, vars) do { int total = 0; for (auto _ : vars) { if (var == _) { total++; } } EXPECT_LE(1, total); } while(0);
#define EXPECT_NOT_IN(var, vars) do { int total = 0; for (auto _ : vars) { if (var == _) { total++; } } EXPECT_EQ(0, total); } while(0);
// clang-format on

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

TEST_F(TestFuzzer, GetAllFiniteMatches_REGEX_A_ShouldReturnAllMatches)
{
	auto fuzzer = deamer::dregx::Fuzzer();
	fuzzer.SetRegex("[a]");
	const auto result = fuzzer.GetAllFiniteMatches();

	EXPECT_EQ(1, result.size());
	EXPECT_IN("a", result);

	EXPECT_NOT_IN("b", result);
}

TEST_F(TestFuzzer, GetAllFiniteMatches_REGEX_AB_ShouldReturnAllMatches)
{
	auto fuzzer = deamer::dregx::Fuzzer();
	fuzzer.SetRegex("[a][b]");
	const auto result = fuzzer.GetAllFiniteMatches();

	EXPECT_EQ(1, result.size());
	EXPECT_IN("ab", result);

	EXPECT_NOT_IN("a", result);
}

TEST_F(TestFuzzer, GetAllFiniteMatches_REGEX_AB_OR_A_B_C_D_ShouldReturnAllMatches)
{
	auto fuzzer = deamer::dregx::Fuzzer();
	fuzzer.SetRegex("[a][b]([a]|[b]|[c]|[d])");
	const auto result = fuzzer.GetAllFiniteMatches();

	EXPECT_EQ(4, result.size());
	EXPECT_IN("aba", result);
	EXPECT_IN("abb", result);
	EXPECT_IN("abc", result);
	EXPECT_IN("abd", result);

	EXPECT_NOT_IN("a", result);
	EXPECT_NOT_IN("ab", result);
	EXPECT_NOT_IN("abe", result);
}

TEST_F(TestFuzzer, GetAllFiniteMatches_REGEX_AB_OR_A_B_C_D_0_TILL_2_ShouldReturnAllMatches)
{
	auto fuzzer = deamer::dregx::Fuzzer();
	fuzzer.SetRegex("[a][b]([a]|[b]|[c]|[d]){0,2}");
	const auto result = fuzzer.GetAllFiniteMatches();

	EXPECT_EQ(21, result.size());
	EXPECT_IN("ab", result);

	EXPECT_IN("aba", result);
	EXPECT_IN("abb", result);
	EXPECT_IN("abc", result);
	EXPECT_IN("abd", result);

	EXPECT_IN("abaa", result);
	EXPECT_IN("abba", result);
	EXPECT_IN("abca", result);
	EXPECT_IN("abda", result);
	EXPECT_IN("abab", result);
	EXPECT_IN("abbb", result);
	EXPECT_IN("abcb", result);
	EXPECT_IN("abdb", result);
	EXPECT_IN("abac", result);
	EXPECT_IN("abbc", result);
	EXPECT_IN("abcc", result);
	EXPECT_IN("abdc", result);
	EXPECT_IN("abad", result);
	EXPECT_IN("abbd", result);
	EXPECT_IN("abcd", result);
	EXPECT_IN("abdd", result);

	EXPECT_NOT_IN("a", result);
	EXPECT_NOT_IN("ad", result);
	EXPECT_NOT_IN("abe", result);
	EXPECT_NOT_IN("abae", result);
}

TEST_F(TestFuzzer, GetAllFiniteMatches_REGEX_A_A_0_TILL_2_OR_A_OR_AA_ShouldReturnAllMatches)
{
	auto fuzzer = deamer::dregx::Fuzzer();
	fuzzer.SetRegex("[a]([a]{0,2}|[a]|[a][a])");
	const auto result = fuzzer.GetAllFiniteMatches();

	EXPECT_EQ(3, result.size());
	EXPECT_IN("a", result);
	EXPECT_IN("aa", result);
	EXPECT_IN("aaa", result);
}

TEST_F(TestFuzzer, GetAllFiniteMatches_REGEX_A_0_2_B_0_3_C_0_4_D_1_4_ShouldReturnAllMatches)
{
	auto fuzzer = deamer::dregx::Fuzzer();
	fuzzer.SetRegex("[a]{0,2}[b]{0,3}[c]{0,4}[d]{1,4}");
	const auto result = fuzzer.GetAllFiniteMatches();

	EXPECT_EQ(240, result.size());
}

TEST_F(TestFuzzer, GetAllFiniteMatches_REGEX_A_START_ShouldReturnMinimalMatch)
{
	auto fuzzer = deamer::dregx::Fuzzer();
	fuzzer.SetRegex("[a]+");
	const auto expected = fuzzer.GetMinimalExample();
	const auto result = fuzzer.GetAllFiniteMatches();

	EXPECT_EQ(expected, result[0]);
}
