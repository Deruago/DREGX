#include "Deamer/Dregx/Analyzer.h"
#include "Deamer/External/Cpp/Ast/Tree.h"
#include "dregx/Ast/Listener/User/TranslateToIr.h"
#include "dregx/Bison/Parser.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <memory>
#include <optional>

using namespace dregx;

class TestAnalyzer : public testing::Test
{
public:
protected:
	TestAnalyzer() = default;

	virtual ~TestAnalyzer() = default;

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

TEST_F(TestAnalyzer, IsRegexSubsetOf_GiveBaseSet_ReturnTrue)
{
	auto analyzer = deamer::dregx::Analyzer();
	analyzer.SetRegex("[a]+");

	EXPECT_TRUE(analyzer.IsRegexSubsetOf("[a-zA-Z]+"));
}

TEST_F(TestAnalyzer, IsRegexSubsetOf_GiveSubSet_ReturnFalse)
{
	auto analyzer = deamer::dregx::Analyzer();
	analyzer.SetRegex("[a-zA-Z]+");

	EXPECT_FALSE(analyzer.IsRegexSubsetOf("[a]+"));
}

TEST_F(TestAnalyzer, IsRegexBasesetOf_GiveSubSet_ReturnTrue)
{
	auto analyzer = deamer::dregx::Analyzer();
	analyzer.SetRegex("[a-zA-Z]+");

	EXPECT_TRUE(analyzer.IsRegexBasesetOf("[a]+"));
}

TEST_F(TestAnalyzer, IsRegexBasesetOf_GiveBaseSet_ReturnFalse)
{
	auto analyzer = deamer::dregx::Analyzer();
	analyzer.SetRegex("[a]+");

	EXPECT_FALSE(analyzer.IsRegexBasesetOf("[a-zA-Z]+"));
}

TEST_F(TestAnalyzer, IsRegexBasesetOf_GiveDisjointSet_ReturnFalse)
{
	auto analyzer = deamer::dregx::Analyzer();
	analyzer.SetRegex("[a]+");

	EXPECT_FALSE(analyzer.IsRegexBasesetOf("[b]+"));
}

TEST_F(TestAnalyzer, IsRegexSubsetOf_GiveDisjointSet_ReturnFalse)
{
	auto analyzer = deamer::dregx::Analyzer();
	analyzer.SetRegex("[a]+");

	EXPECT_FALSE(analyzer.IsRegexSubsetOf("[b]+"));
}

TEST_F(TestAnalyzer, IsRegexDisjointOf_GiveSubSet_ReturnFalse)
{
	auto analyzer = deamer::dregx::Analyzer();
	analyzer.SetRegex("[a-zA-Z]+");

	EXPECT_FALSE(analyzer.IsRegexDisjointOf("[a]+"));
}

TEST_F(TestAnalyzer, IsRegexDisjointOf_GiveBaseSet_ReturnFalse)
{
	auto analyzer = deamer::dregx::Analyzer();
	analyzer.SetRegex("[a]+");

	EXPECT_FALSE(analyzer.IsRegexDisjointOf("[a-zA-Z]+"));
}

TEST_F(TestAnalyzer, IsRegexDisjointOf_GiveDisjointSet_ReturnTrue)
{
	auto analyzer = deamer::dregx::Analyzer();
	analyzer.SetRegex("[a]+");

	EXPECT_TRUE(analyzer.IsRegexDisjointOf("[b]+"));
}
