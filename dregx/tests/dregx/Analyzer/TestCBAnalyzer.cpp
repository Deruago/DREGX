#include "Deamer/Dregx/V2/CBAnalyzer.h"
#include "Deamer/External/Cpp/Ast/Tree.h"
#include "dregx/Ast/Listener/User/TranslateToIr.h"
#include "dregx/Bison/Parser.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <memory>
#include <optional>

using namespace dregx;

class TestCBAnalyzer : public testing::Test
{
public:
protected:
	TestCBAnalyzer() = default;

	virtual ~TestCBAnalyzer() = default;

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

TEST_F(TestCBAnalyzer, IsRegexSubsetOf_GiveBaseSetab_ReturnTrue)
{
	auto analyzer = deamer::dregx::v2::CBAnalyzer();
	analyzer.SetRegex("[a]+");

	EXPECT_TRUE(analyzer.IsRegexSubsetOf("[ab]+"));
}

TEST_F(TestCBAnalyzer, IsRegexSubsetOf_GiveBaseSetaA_ReturnTrue)
{
	auto analyzer = deamer::dregx::v2::CBAnalyzer();
	analyzer.SetRegex("[a]+");

	EXPECT_TRUE(analyzer.IsRegexSubsetOf("[aA]+"));
}

TEST_F(TestCBAnalyzer, IsRegexSubsetOf_GiveBaseSetaB_ReturnTrue)
{
	auto analyzer = deamer::dregx::v2::CBAnalyzer();
	analyzer.SetRegex("[a]+");

	EXPECT_TRUE(analyzer.IsRegexSubsetOf("[aB]+"));
}

TEST_F(TestCBAnalyzer, IsRegexSubsetOf_GiveBaseSetazAZ_ReturnTrue)
{
	auto analyzer = deamer::dregx::v2::CBAnalyzer();
	analyzer.SetRegex("[a]+");

	EXPECT_TRUE(analyzer.IsRegexSubsetOf("[a-zA-Z]+"));
}

TEST_F(TestCBAnalyzer, IsRegexSubsetOf_GiveSubSet_ReturnFalse)
{
	auto analyzer = deamer::dregx::v2::CBAnalyzer();
	analyzer.SetRegex("[a-zA-Z]+");

	EXPECT_FALSE(analyzer.IsRegexSubsetOf("[a]+"));
}

TEST_F(TestCBAnalyzer, IsRegexBasesetOf_GiveSubSet_ReturnTrue)
{
	auto analyzer = deamer::dregx::v2::CBAnalyzer();
	analyzer.SetRegex("[a-zA-Z]+");

	EXPECT_TRUE(analyzer.IsRegexBasesetOf("[a]+"));
}

TEST_F(TestCBAnalyzer, IsRegexBasesetOf_GiveBaseSet_ReturnFalse)
{
	auto analyzer = deamer::dregx::v2::CBAnalyzer();
	analyzer.SetRegex("[a]+");

	EXPECT_FALSE(analyzer.IsRegexBasesetOf("[a-zA-Z]+"));
}

TEST_F(TestCBAnalyzer, IsRegexBasesetOf_GiveDisjointSet_ReturnFalse)
{
	auto analyzer = deamer::dregx::v2::CBAnalyzer();
	analyzer.SetRegex("[a]+");

	EXPECT_FALSE(analyzer.IsRegexBasesetOf("[b]+"));
}

TEST_F(TestCBAnalyzer, IsRegexSubsetOf_GiveDisjointSet_ReturnFalse)
{
	auto analyzer = deamer::dregx::v2::CBAnalyzer();
	analyzer.SetRegex("[a]+");

	EXPECT_FALSE(analyzer.IsRegexSubsetOf("[b]+"));
}

TEST_F(TestCBAnalyzer, IsRegexDisjointOf_GiveSubSet_ReturnFalse)
{
	auto analyzer = deamer::dregx::v2::CBAnalyzer();
	analyzer.SetRegex("[a-zA-Z]+");

	EXPECT_FALSE(analyzer.IsRegexDisjointOf("[a]+"));
}

TEST_F(TestCBAnalyzer, IsRegexDisjointOf_GiveBaseSet_ReturnFalse)
{
	auto analyzer = deamer::dregx::v2::CBAnalyzer();
	analyzer.SetRegex("[a]+");

	EXPECT_FALSE(analyzer.IsRegexDisjointOf("[a-zA-Z]+"));
}

TEST_F(TestCBAnalyzer, IsRegexDisjointOf_GiveDisjointSet_ReturnTrue)
{
	auto analyzer = deamer::dregx::v2::CBAnalyzer();
	analyzer.SetRegex("[a]+");

	EXPECT_TRUE(analyzer.IsRegexDisjointOf("[b]+"));
}
