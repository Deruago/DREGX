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

TEST_F(TestCBAnalyzer, IsRegexInfinite)
{
	EXPECT_TRUE(deamer::dregx::v2::CBAnalyzer("[a]+").IsInfinite());
	EXPECT_TRUE(deamer::dregx::v2::CBAnalyzer("[ab]+").IsInfinite());
	EXPECT_TRUE(deamer::dregx::v2::CBAnalyzer("[ac]+").IsInfinite());
	EXPECT_TRUE(deamer::dregx::v2::CBAnalyzer("[abc]+").IsInfinite());
	EXPECT_TRUE(deamer::dregx::v2::CBAnalyzer("[abc][as]*").IsInfinite());
	EXPECT_TRUE(deamer::dregx::v2::CBAnalyzer("[abc]*[as]*").IsInfinite());
	EXPECT_TRUE(deamer::dregx::v2::CBAnalyzer("[abc]+[as]*").IsInfinite());
	EXPECT_TRUE(deamer::dregx::v2::CBAnalyzer("[abc]+[as]+").IsInfinite());
	EXPECT_TRUE(deamer::dregx::v2::CBAnalyzer("([abc][as])+").IsInfinite());

	EXPECT_FALSE(deamer::dregx::v2::CBAnalyzer("([abc][as])").IsInfinite());
	EXPECT_FALSE(deamer::dregx::v2::CBAnalyzer("[abc][as]").IsInfinite());
	EXPECT_FALSE(deamer::dregx::v2::CBAnalyzer("[abc]").IsInfinite());
	EXPECT_FALSE(deamer::dregx::v2::CBAnalyzer("[a]").IsInfinite());
	EXPECT_FALSE(deamer::dregx::v2::CBAnalyzer("[b]").IsInfinite());
	EXPECT_FALSE(deamer::dregx::v2::CBAnalyzer("[Ee][Ll]([Ss][Ee]){0,1}[Ii][Ff]").IsInfinite());
}

TEST_F(TestCBAnalyzer, IsRegexFinite)
{
	EXPECT_FALSE(deamer::dregx::v2::CBAnalyzer("[a]+").IsFinite());
	EXPECT_FALSE(deamer::dregx::v2::CBAnalyzer("[ab]+").IsFinite());
	EXPECT_FALSE(deamer::dregx::v2::CBAnalyzer("[ac]+").IsFinite());
	EXPECT_FALSE(deamer::dregx::v2::CBAnalyzer("[abc]+").IsFinite());
	EXPECT_FALSE(deamer::dregx::v2::CBAnalyzer("[abc][as]*").IsFinite());
	EXPECT_FALSE(deamer::dregx::v2::CBAnalyzer("[abc]*[as]*").IsFinite());
	EXPECT_FALSE(deamer::dregx::v2::CBAnalyzer("[abc]+[as]*").IsFinite());
	EXPECT_FALSE(deamer::dregx::v2::CBAnalyzer("[abc]+[as]+").IsFinite());
	EXPECT_FALSE(deamer::dregx::v2::CBAnalyzer("([abc][as])+").IsFinite());

	EXPECT_TRUE(deamer::dregx::v2::CBAnalyzer("([abc][as])").IsFinite());
	EXPECT_TRUE(deamer::dregx::v2::CBAnalyzer("[abc][as]").IsFinite());
	EXPECT_TRUE(deamer::dregx::v2::CBAnalyzer("[abc]").IsFinite());
	EXPECT_TRUE(deamer::dregx::v2::CBAnalyzer("[a]").IsFinite());
	EXPECT_TRUE(deamer::dregx::v2::CBAnalyzer("[b]").IsFinite());
}

TEST_F(TestCBAnalyzer, FuzzFiniteMatches_CaseInsenstive)
{
	auto allMatches =
		deamer::dregx::v2::CBAnalyzer("[Ff][Uu][Nn][Cc][Tt][Ii][Oo][Nn]").GetAllFiniteMatches();

	EXPECT_NE(allMatches.find("function"), allMatches.end());
	EXPECT_NE(allMatches.find("functioN"), allMatches.end());
	EXPECT_NE(allMatches.find("functiOn"), allMatches.end());
	EXPECT_NE(allMatches.find("functiON"), allMatches.end());
	EXPECT_NE(allMatches.find("functIon"), allMatches.end());
	EXPECT_NE(allMatches.find("functIoN"), allMatches.end());
	EXPECT_NE(allMatches.find("functIOn"), allMatches.end());
	EXPECT_NE(allMatches.find("functION"), allMatches.end());
	EXPECT_NE(allMatches.find("funcTion"), allMatches.end());
	EXPECT_NE(allMatches.find("funcTioN"), allMatches.end());
	EXPECT_NE(allMatches.find("funcTIOn"), allMatches.end());
	EXPECT_NE(allMatches.find("funcTION"), allMatches.end());
	EXPECT_NE(allMatches.find("funcTIon"), allMatches.end());
	EXPECT_NE(allMatches.find("funcTIon"), allMatches.end());
	EXPECT_NE(allMatches.find("funcTION"), allMatches.end());
	EXPECT_NE(allMatches.find("funcTION"), allMatches.end());

	EXPECT_EQ(allMatches.size(), 256);
}
