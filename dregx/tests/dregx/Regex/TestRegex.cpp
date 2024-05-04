#include "Deamer/Dregx/Regex.h"
#include "Deamer/Dregx/V2/Regex.h"
#include "Deamer/Dregx/V2/CBRegex.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <memory>
#include <optional>

using namespace dregx;

class TestRegex : public testing::Test
{
public:
protected:
	TestRegex() = default;
	virtual ~TestRegex() = default;
};

TEST_F(TestRegex, V2_CBRegex_Comment)
{
	auto regex = ::deamer::dregx::v2::CBRegex("[/][^\\n\\r]*[\\n\\r]{0,1}", 100);
	regex.Match("/\n");
	regex.Match("/ \n");
	regex.Match("/  \n");
	regex.Match("/  ***\n");
	regex.Match("/  **// / *\n");
}

TEST_F(TestRegex, RegexOperatorOr_OrTwoRegexes)
{
	auto regex = ::deamer::dregx::Regex("[a]");
	regex |= "b";

	const auto expectedRegex = ::deamer::dregx::Regex("[ab]");

	EXPECT_EQ(expectedRegex, regex);
	EXPECT_EQ("[ab]", regex);
}

TEST_F(TestRegex, RegexOperatorConcatenate_ConcatenateTwoRegexes)
{
	auto regex = ::deamer::dregx::Regex("[a]");
	regex += "a";

	const auto expectedRegex = ::deamer::dregx::Regex("[a][a]");

	EXPECT_EQ(expectedRegex, regex);
	EXPECT_EQ("[a][a]", regex);
}

TEST_F(TestRegex, V2Regex_Or_A_B_Match)
{
	auto regex = ::deamer::dregx::v2::Regex("[a]");
	regex.Or(::deamer::dregx::v2::Regex("[b]"));

	EXPECT_TRUE(regex.Match("a"));
	EXPECT_TRUE(regex.Match("b"));

	EXPECT_FALSE(regex.Match(""));
	EXPECT_FALSE(regex.Match("aa"));
	EXPECT_FALSE(regex.Match("ab"));
	EXPECT_FALSE(regex.Match("ba"));
	EXPECT_FALSE(regex.Match("bb"));
}

TEST_F(TestRegex, V2Regex_Or_CelesteFirst3_NoMatch)
{
	auto regex = ::deamer::dregx::v2::Regex("[/][^\\n\\r]*[\\n\\r]{0,1}");
	regex.Or(::deamer::dregx::v2::Regex("[/][*][^*]*[*][/]{0,1}"));
	regex.Or(::deamer::dregx::v2::Regex("[Cc][Oo][Nn][Ss][Tt]([Aa][Nn][Tt]){0,1}"));
}

TEST_F(TestRegex, V2Regex_Or_CelesteFirst3_Match)
{
	auto regex = ::deamer::dregx::v2::Regex("[/][^\\n\\r]*[\\n\\r]{0,1}");
	regex.Or(::deamer::dregx::v2::Regex("[/][*][^*]*[*][/]{0,1}"));
	regex.Or(::deamer::dregx::v2::Regex("[Cc][Oo][Nn][Ss][Tt]([Aa][Nn][Tt]){0,1}"));

	EXPECT_TRUE(regex.Match("constant"));
	EXPECT_TRUE(regex.Match("/**/"));
	EXPECT_TRUE(regex.Match("/\n"));

	EXPECT_FALSE(regex.Match(""));
	EXPECT_FALSE(regex.Match("aa"));
	EXPECT_FALSE(regex.Match("ab"));
	EXPECT_FALSE(regex.Match("ba"));
	EXPECT_FALSE(regex.Match("bb"));
}

TEST_F(TestRegex, V2Regex_Or_CelesteFirst15_Match)
{
	auto regex = ::deamer::dregx::v2::Regex("[Nn][Aa][Mm][Ee][Ss][Pp][Aa][Cc][Ee]");
	regex.Or(::deamer::dregx::v2::Regex("[Ff][Uu][Nn][Cc][Tt][Ii][Oo][Nn]"));
	regex.Or(::deamer::dregx::v2::Regex("[Cc][Ll][Aa][Ss][Ss]"));
	regex.Or(::deamer::dregx::v2::Regex("[Ee][Nn][Uu][Mm]"));
	regex.Or(::deamer::dregx::v2::Regex("[Cc][Oo][Nn][Dd][Ii][Tt][Ii][Oo][Nn][Aa][Ll]"));
	regex.Or(::deamer::dregx::v2::Regex("[Cc][Oo][Dd][Ee]"));
	regex.Or(::deamer::dregx::v2::Regex("[Aa][Tt][Tt][Rr][Ii][Bb][Uu][Tt][Ee]"));
	regex.Or(::deamer::dregx::v2::Regex("[Rr][Uu][Nn][Tt][Ii][Mm][Ee]"));
	regex.Or(::deamer::dregx::v2::Regex("[Ss][Tt][Aa][Tt][Ii][Cc]"));
	regex.Or(::deamer::dregx::v2::Regex("[Aa][Uu][Tt][Oo]"));
	regex.Or(::deamer::dregx::v2::Regex("[Aa][Uu][Tt][Oo][Tt][Yy][Pp][Ee]"));
	regex.Or(::deamer::dregx::v2::Regex("[Tt][Ee][Mm][Pp][Ll][Aa][Tt][Ee]"));
	regex.Or(::deamer::dregx::v2::Regex("[Cc][Oo][Nn][Ss][Tt]([Aa][Nn][Tt]){0,1}"));
	regex.Or(::deamer::dregx::v2::Regex("[/][^\\n\\r]*[\\n\\r]{0,1}"));
	regex.Or(::deamer::dregx::v2::Regex("[/][*][^*]*[*][/]{0,1}"));

	EXPECT_TRUE(regex.Match("constant"));
	EXPECT_TRUE(regex.Match("function"));
	EXPECT_TRUE(regex.Match("class"));
	EXPECT_TRUE(regex.Match("enum"));
	EXPECT_TRUE(regex.Match("conditional"));
	EXPECT_TRUE(regex.Match("attribute"));
	EXPECT_TRUE(regex.Match("static"));
	EXPECT_TRUE(regex.Match("auto"));
	EXPECT_TRUE(regex.Match("autotype"));
	EXPECT_TRUE(regex.Match("template"));
	EXPECT_TRUE(regex.Match("namespace"));
	EXPECT_TRUE(regex.Match("/**/"));
	EXPECT_TRUE(regex.Match("/\n"));

	EXPECT_FALSE(regex.Match(""));
	EXPECT_FALSE(regex.Match("aa"));
	EXPECT_FALSE(regex.Match("ab"));
	EXPECT_FALSE(regex.Match("ba"));
	EXPECT_FALSE(regex.Match("bb"));
}

TEST_F(TestRegex, V2Regex_Or_CelesteFirst65_Match)
{
	auto regex = ::deamer::dregx::v2::Regex("[Nn][Aa][Mm][Ee][Ss][Pp][Aa][Cc][Ee]");
	regex.Or(::deamer::dregx::v2::Regex("[Ff][Uu][Nn][Cc][Tt][Ii][Oo][Nn]"));
	regex.Or(::deamer::dregx::v2::Regex("[Cc][Ll][Aa][Ss][Ss]"));
	regex.Or(::deamer::dregx::v2::Regex("[Ee][Nn][Uu][Mm]"));
	regex.Or(::deamer::dregx::v2::Regex("[Cc][Oo][Nn][Dd][Ii][Tt][Ii][Oo][Nn][Aa][Ll]"));
	regex.Or(::deamer::dregx::v2::Regex("[Cc][Oo][Dd][Ee]"));
	regex.Or(::deamer::dregx::v2::Regex("[Aa][Tt][Tt][Rr][Ii][Bb][Uu][Tt][Ee]"));
	regex.Or(::deamer::dregx::v2::Regex("[Rr][Uu][Nn][Tt][Ii][Mm][Ee]"));
	regex.Or(::deamer::dregx::v2::Regex("[Ss][Tt][Aa][Tt][Ii][Cc]"));
	regex.Or(::deamer::dregx::v2::Regex("[Aa][Uu][Tt][Oo]"));
	regex.Or(::deamer::dregx::v2::Regex("[Aa][Uu][Tt][Oo][Tt][Yy][Pp][Ee]"));
	regex.Or(::deamer::dregx::v2::Regex("[Tt][Ee][Mm][Pp][Ll][Aa][Tt][Ee]"));
	regex.Or(::deamer::dregx::v2::Regex("[Cc][Oo][Nn][Ss][Tt]([Aa][Nn][Tt]){0,1}"));
	regex.Or(::deamer::dregx::v2::Regex("[Oo][Vv][Ee][Rr][Rr][Ii][Dd][Ee]"));
	regex.Or(::deamer::dregx::v2::Regex("[Vv][Ii][Rr][Tt][Uu][Aa][Ll]"));
	regex.Or(::deamer::dregx::v2::Regex("(([Pp][Uu][Rr][Ee])|([Aa][Bb][Ss][Tt][Rr][Aa][Cc][Tt]))"));
	regex.Or(::deamer::dregx::v2::Regex("[Aa][Ss]"));
	regex.Or(::deamer::dregx::v2::Regex("[Ii][Nn]"));
	regex.Or(::deamer::dregx::v2::Regex("[Dd][Ii][Ss][Pp][Ll][Aa][Yy]"));
	regex.Or(::deamer::dregx::v2::Regex("[Rr][Ee][Tt][Uu][Rr][Nn]"));
	regex.Or(::deamer::dregx::v2::Regex("[Ff][Oo][Rr]"));
	regex.Or(::deamer::dregx::v2::Regex("[Ii][Ff]"));
	regex.Or(::deamer::dregx::v2::Regex("[Ee][Ll][Ss][Ee]"));
	regex.Or(::deamer::dregx::v2::Regex("[Ii][Nn][Ll][Ii][Nn][Ee]"));
	regex.Or(::deamer::dregx::v2::Regex("[Cc][Oo][Nn][Ss][Tt][Rr][Uu][Cc][Tt][Oo][Rr]"));
	regex.Or(::deamer::dregx::v2::Regex("[Ff][Ii][Ll][Ee]"));
	regex.Or(::deamer::dregx::v2::Regex("[Pp][Rr][Oo][Gg][Rr][Aa][Mm]"));
	regex.Or(::deamer::dregx::v2::Regex("[Ii][Mm][Pp][Oo][Rr][Tt]"));
	regex.Or(::deamer::dregx::v2::Regex("[Aa][Ll][Ii][Aa][Ss]"));
	regex.Or(::deamer::dregx::v2::Regex("[Pp][Uu][Bb][Ll][Ii][Cc]"));
	regex.Or(::deamer::dregx::v2::Regex("[Pp][Rr][Oo][Tt][Ee][Cc][Tt][Ee][Dd]"));
	regex.Or(::deamer::dregx::v2::Regex("[Pp][Rr][Ii][Vv][Aa][Tt][Ee]"));
	regex.Or(::deamer::dregx::v2::Regex("[Ii][Nn][Hh][Ee][Rr][Ii][Tt]"));
	regex.Or(::deamer::dregx::v2::Regex("[Cc][Oo][Mm][Pp][Oo][Ss][Ii][Tt][Ee]"));
	regex.Or(::deamer::dregx::v2::Regex("[{]"));
	regex.Or(::deamer::dregx::v2::Regex("[}]"));
	regex.Or(::deamer::dregx::v2::Regex("[\\[]"));
	regex.Or(::deamer::dregx::v2::Regex("[\\]]"));
	regex.Or(::deamer::dregx::v2::Regex("[(]"));
	regex.Or(::deamer::dregx::v2::Regex("[)]"));
	regex.Or(::deamer::dregx::v2::Regex("[:]"));
	regex.Or(::deamer::dregx::v2::Regex("[;]"));
	regex.Or(::deamer::dregx::v2::Regex("[,]"));
	regex.Or(::deamer::dregx::v2::Regex("[.]"));
	regex.Or(::deamer::dregx::v2::Regex("[<][=]"));
	regex.Or(::deamer::dregx::v2::Regex("[>][=]"));
	regex.Or(::deamer::dregx::v2::Regex("[<]"));
	regex.Or(::deamer::dregx::v2::Regex("[>]"));
	regex.Or(::deamer::dregx::v2::Regex("[+][=]"));
	regex.Or(::deamer::dregx::v2::Regex("[\\-][=]"));
	regex.Or(::deamer::dregx::v2::Regex("[*][=]"));
	regex.Or(::deamer::dregx::v2::Regex("[\\\\][=]"));
	regex.Or(::deamer::dregx::v2::Regex("[=][=]"));
	regex.Or(::deamer::dregx::v2::Regex("[=]"));
	regex.Or(::deamer::dregx::v2::Regex("[!][=]"));
	regex.Or(::deamer::dregx::v2::Regex("[!]"));
	regex.Or(::deamer::dregx::v2::Regex("[+][+]"));
	regex.Or(::deamer::dregx::v2::Regex("[+]"));
	regex.Or(::deamer::dregx::v2::Regex("[\\-][\\-]"));
	regex.Or(::deamer::dregx::v2::Regex("[\\-]"));
	regex.Or(::deamer::dregx::v2::Regex("[\\\\]"));
	regex.Or(::deamer::dregx::v2::Regex("[*]"));
	regex.Or(::deamer::dregx::v2::Regex("[/][^\\n\\r]*[\\n\\r]{0,1}"));
	regex.Or(::deamer::dregx::v2::Regex("[/][*][^*]*[*][/]{0,1}"));
	regex.Or(::deamer::dregx::v2::Regex("[Ee][Ll]([Ss][Ee][ ]*){0,1}[Ii][Ff]"));

	EXPECT_TRUE(regex.Match("constant"));
	EXPECT_TRUE(regex.Match("function"));
	EXPECT_TRUE(regex.Match("class"));
	EXPECT_TRUE(regex.Match("enum"));
	EXPECT_TRUE(regex.Match("conditional"));
	EXPECT_TRUE(regex.Match("attribute"));
	EXPECT_TRUE(regex.Match("static"));
	EXPECT_TRUE(regex.Match("auto"));
	EXPECT_TRUE(regex.Match("autotype"));
	EXPECT_TRUE(regex.Match("template"));
	EXPECT_TRUE(regex.Match("namespace"));
	EXPECT_TRUE(regex.Match("/**/"));
	EXPECT_TRUE(regex.Match("/\n"));

	EXPECT_TRUE(regex.Match("<="));
	EXPECT_TRUE(regex.Match(">="));
	EXPECT_TRUE(regex.Match(">"));
	EXPECT_TRUE(regex.Match("<"));

	EXPECT_FALSE(regex.Match(""));
	EXPECT_FALSE(regex.Match("aa"));
	EXPECT_FALSE(regex.Match("ab"));
	EXPECT_FALSE(regex.Match("ba"));
	EXPECT_FALSE(regex.Match("bb"));
}

TEST_F(TestRegex, V2Regex_Or_CelesteFull_Match)
{
	auto regex = ::deamer::dregx::v2::Regex("[Nn][Aa][Mm][Ee][Ss][Pp][Aa][Cc][Ee]");
	regex.Or(::deamer::dregx::v2::Regex("[Ff][Uu][Nn][Cc][Tt][Ii][Oo][Nn]"));
	regex.Or(::deamer::dregx::v2::Regex("[Cc][Ll][Aa][Ss][Ss]"));
	regex.Or(::deamer::dregx::v2::Regex("[Ee][Nn][Uu][Mm]"));
	regex.Or(::deamer::dregx::v2::Regex("[Cc][Oo][Nn][Dd][Ii][Tt][Ii][Oo][Nn][Aa][Ll]"));
	regex.Or(::deamer::dregx::v2::Regex("[Cc][Oo][Dd][Ee]"));
	regex.Or(::deamer::dregx::v2::Regex("[Aa][Tt][Tt][Rr][Ii][Bb][Uu][Tt][Ee]"));
	regex.Or(::deamer::dregx::v2::Regex("[Rr][Uu][Nn][Tt][Ii][Mm][Ee]"));
	regex.Or(::deamer::dregx::v2::Regex("[Ss][Tt][Aa][Tt][Ii][Cc]"));
	regex.Or(::deamer::dregx::v2::Regex("[Aa][Uu][Tt][Oo]"));
	regex.Or(::deamer::dregx::v2::Regex("[Aa][Uu][Tt][Oo][Tt][Yy][Pp][Ee]"));
	regex.Or(::deamer::dregx::v2::Regex("[Tt][Ee][Mm][Pp][Ll][Aa][Tt][Ee]"));
	regex.Or(::deamer::dregx::v2::Regex("[Cc][Oo][Nn][Ss][Tt]([Aa][Nn][Tt]){0,1}"));
	regex.Or(::deamer::dregx::v2::Regex("[Oo][Vv][Ee][Rr][Rr][Ii][Dd][Ee]"));
	regex.Or(::deamer::dregx::v2::Regex("[Vv][Ii][Rr][Tt][Uu][Aa][Ll]"));
	regex.Or(::deamer::dregx::v2::Regex("(([Pp][Uu][Rr][Ee])|([Aa][Bb][Ss][Tt][Rr][Aa][Cc][Tt]))"));
	regex.Or(::deamer::dregx::v2::Regex("[Aa][Ss]"));
	regex.Or(::deamer::dregx::v2::Regex("[Ii][Nn]"));
	regex.Or(::deamer::dregx::v2::Regex("[Dd][Ii][Ss][Pp][Ll][Aa][Yy]"));
	regex.Or(::deamer::dregx::v2::Regex("[Rr][Ee][Tt][Uu][Rr][Nn]"));
	regex.Or(::deamer::dregx::v2::Regex("[Ff][Oo][Rr]"));
	regex.Or(::deamer::dregx::v2::Regex("[Ii][Ff]"));
	regex.Or(::deamer::dregx::v2::Regex("[Ee][Ll][Ss][Ee]"));
	regex.Or(::deamer::dregx::v2::Regex("[Ii][Nn][Ll][Ii][Nn][Ee]"));
	regex.Or(::deamer::dregx::v2::Regex("[Cc][Oo][Nn][Ss][Tt][Rr][Uu][Cc][Tt][Oo][Rr]"));
	regex.Or(::deamer::dregx::v2::Regex("[Ff][Ii][Ll][Ee]"));
	regex.Or(::deamer::dregx::v2::Regex("[Pp][Rr][Oo][Gg][Rr][Aa][Mm]"));
	regex.Or(::deamer::dregx::v2::Regex("[Ii][Mm][Pp][Oo][Rr][Tt]"));
	regex.Or(::deamer::dregx::v2::Regex("[Aa][Ll][Ii][Aa][Ss]"));
	regex.Or(::deamer::dregx::v2::Regex("[Pp][Uu][Bb][Ll][Ii][Cc]"));
	regex.Or(::deamer::dregx::v2::Regex("[Pp][Rr][Oo][Tt][Ee][Cc][Tt][Ee][Dd]"));
	regex.Or(::deamer::dregx::v2::Regex("[Pp][Rr][Ii][Vv][Aa][Tt][Ee]"));
	regex.Or(::deamer::dregx::v2::Regex("[Ii][Nn][Hh][Ee][Rr][Ii][Tt]"));
	regex.Or(::deamer::dregx::v2::Regex("[Cc][Oo][Mm][Pp][Oo][Ss][Ii][Tt][Ee]"));
	regex.Or(::deamer::dregx::v2::Regex("[{]"));
	regex.Or(::deamer::dregx::v2::Regex("[}]"));
	regex.Or(::deamer::dregx::v2::Regex("[\\[]"));
	regex.Or(::deamer::dregx::v2::Regex("[\\]]"));
	regex.Or(::deamer::dregx::v2::Regex("[(]"));
	regex.Or(::deamer::dregx::v2::Regex("[)]"));
	regex.Or(::deamer::dregx::v2::Regex("[:]"));
	regex.Or(::deamer::dregx::v2::Regex("[;]"));
	regex.Or(::deamer::dregx::v2::Regex("[,]"));
	regex.Or(::deamer::dregx::v2::Regex("[.]"));
	regex.Or(::deamer::dregx::v2::Regex("[<][=]"));
	regex.Or(::deamer::dregx::v2::Regex("[>][=]"));
	regex.Or(::deamer::dregx::v2::Regex("[<]"));
	regex.Or(::deamer::dregx::v2::Regex("[>]"));
	regex.Or(::deamer::dregx::v2::Regex("[+][=]"));
	regex.Or(::deamer::dregx::v2::Regex("[\\-][=]"));
	regex.Or(::deamer::dregx::v2::Regex("[*][=]"));
	regex.Or(::deamer::dregx::v2::Regex("[\\\\][=]"));
	regex.Or(::deamer::dregx::v2::Regex("[=][=]"));
	regex.Or(::deamer::dregx::v2::Regex("[=]"));
	regex.Or(::deamer::dregx::v2::Regex("[!][=]"));
	regex.Or(::deamer::dregx::v2::Regex("[!]"));
	regex.Or(::deamer::dregx::v2::Regex("[+][+]"));
	regex.Or(::deamer::dregx::v2::Regex("[+]"));
	regex.Or(::deamer::dregx::v2::Regex("[\\-][\\-]"));
	regex.Or(::deamer::dregx::v2::Regex("[\\-]"));
	regex.Or(::deamer::dregx::v2::Regex("[\\\\]"));
	regex.Or(::deamer::dregx::v2::Regex("[*]"));
	regex.Or(::deamer::dregx::v2::Regex("[/][^\\n\\r]*[\\n\\r]{0,1}"));
	regex.Or(::deamer::dregx::v2::Regex("[/][*][^*]*[*][/]{0,1}"));
	regex.Or(::deamer::dregx::v2::Regex("[Ee][Ll]([Ss][Ee][ ]*){0,1}[Ii][Ff]"));
	regex.Or(::deamer::dregx::v2::Regex(
		"[Oo][Pp][Ee][Rr][Aa][Tt][Oo][Rr][\\\\+\\-?!*%@#$\\^<>=:|\\[\\]]+"));
	regex.Or(::deamer::dregx::v2::Regex("[a-zA-Z_][a-zA-Z_0-9]*"));
	regex.Or(::deamer::dregx::v2::Regex("[\\-]{0,1}[0-9]+"));
	regex.Or(::deamer::dregx::v2::Regex("[\\-]{0,1}[0-9]+[\\.][0-9]+"));
	regex.Or(::deamer::dregx::v2::Regex("[\\\"]([\\\\][\\\"]|[\\\\][\\\\]|[^\\\"])*[\\\"]"));
	regex.Or(::deamer::dregx::v2::Regex("[\\n\\r\\t ]+"));


	EXPECT_TRUE(regex.Match("constant"));
	EXPECT_TRUE(regex.Match("function"));
	EXPECT_TRUE(regex.Match("class"));
	EXPECT_TRUE(regex.Match("enum"));
	EXPECT_TRUE(regex.Match("conditional"));
	EXPECT_TRUE(regex.Match("attribute"));
	EXPECT_TRUE(regex.Match("static"));
	EXPECT_TRUE(regex.Match("auto"));
	EXPECT_TRUE(regex.Match("autotype"));
	EXPECT_TRUE(regex.Match("template"));
	EXPECT_TRUE(regex.Match("namespace"));
	EXPECT_TRUE(regex.Match("/**/"));
	EXPECT_TRUE(regex.Match("/\n"));

	EXPECT_TRUE(regex.Match("<="));
	EXPECT_TRUE(regex.Match(">="));
	EXPECT_TRUE(regex.Match(">"));
	EXPECT_TRUE(regex.Match("<"));

	EXPECT_FALSE(regex.Match(""));
	EXPECT_TRUE(regex.Match("aa"));
	EXPECT_TRUE(regex.Match("ab"));
	EXPECT_TRUE(regex.Match("ba"));
	EXPECT_TRUE(regex.Match("bb"));
}

TEST_F(TestRegex, V2CBRegex_Or_A_B_Match)
{
	auto regex = ::deamer::dregx::v2::CBRegex("[a]");
	regex.Or(::deamer::dregx::v2::CBRegex("[b]"));

	EXPECT_TRUE(regex.Match("a"));
	EXPECT_TRUE(regex.Match("b"));

	EXPECT_FALSE(regex.Match(""));
	EXPECT_FALSE(regex.Match("aa"));
	EXPECT_FALSE(regex.Match("ab"));
	EXPECT_FALSE(regex.Match("ba"));
	EXPECT_FALSE(regex.Match("bb"));
}

TEST_F(TestRegex, V2CBRegex_Or_CelesteFirst3_Match)
{
	auto regex = ::deamer::dregx::v2::CBRegex("[/][^\\n\\r]*[\\n\\r]{0,1}");
	regex.Or(::deamer::dregx::v2::CBRegex("[/][*][^*]*[*][/]{0,1}"));
	regex.Or(::deamer::dregx::v2::CBRegex("[Cc][Oo][Nn][Ss][Tt]([Aa][Nn][Tt]){0,1}"));

	EXPECT_TRUE(regex.Match("constant"));
	EXPECT_TRUE(regex.Match("/**/"));
	EXPECT_TRUE(regex.Match("/\n"));

	EXPECT_FALSE(regex.Match(""));
	EXPECT_FALSE(regex.Match("aa"));
	EXPECT_FALSE(regex.Match("ab"));
	EXPECT_FALSE(regex.Match("ba"));
	EXPECT_FALSE(regex.Match("bb"));
}

TEST_F(TestRegex, V2CBRegex_Or_CelesteFirst15_Match)
{
	auto regex = ::deamer::dregx::v2::CBRegex("[Nn][Aa][Mm][Ee][Ss][Pp][Aa][Cc][Ee]");
	regex.Or(::deamer::dregx::v2::CBRegex("[Ff][Uu][Nn][Cc][Tt][Ii][Oo][Nn]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[Cc][Ll][Aa][Ss][Ss]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[Ee][Nn][Uu][Mm]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[Cc][Oo][Nn][Dd][Ii][Tt][Ii][Oo][Nn][Aa][Ll]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[Cc][Oo][Dd][Ee]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[Aa][Tt][Tt][Rr][Ii][Bb][Uu][Tt][Ee]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[Rr][Uu][Nn][Tt][Ii][Mm][Ee]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[Ss][Tt][Aa][Tt][Ii][Cc]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[Aa][Uu][Tt][Oo]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[Aa][Uu][Tt][Oo][Tt][Yy][Pp][Ee]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[Tt][Ee][Mm][Pp][Ll][Aa][Tt][Ee]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[Cc][Oo][Nn][Ss][Tt]([Aa][Nn][Tt]){0,1}"));
	regex.Or(::deamer::dregx::v2::CBRegex("[/][^\\n\\r]*[\\n\\r]{0,1}"));
	regex.Or(::deamer::dregx::v2::CBRegex("[/][*][^*]*[*][/]{0,1}"));

	EXPECT_TRUE(regex.Match("constant"));
	EXPECT_TRUE(regex.Match("function"));
	EXPECT_TRUE(regex.Match("class"));
	EXPECT_TRUE(regex.Match("enum"));
	EXPECT_TRUE(regex.Match("conditional"));
	EXPECT_TRUE(regex.Match("attribute"));
	EXPECT_TRUE(regex.Match("static"));
	EXPECT_TRUE(regex.Match("auto"));
	EXPECT_TRUE(regex.Match("autotype"));
	EXPECT_TRUE(regex.Match("template"));
	EXPECT_TRUE(regex.Match("namespace"));
	EXPECT_TRUE(regex.Match("/**/"));
	EXPECT_TRUE(regex.Match("/\n"));

	EXPECT_FALSE(regex.Match(""));
	EXPECT_FALSE(regex.Match("aa"));
	EXPECT_FALSE(regex.Match("ab"));
	EXPECT_FALSE(regex.Match("ba"));
	EXPECT_FALSE(regex.Match("bb"));
}

TEST_F(TestRegex, V2CBRegex_Or_CelesteFirst65_Match)
{
	auto regex = ::deamer::dregx::v2::CBRegex("[Nn][Aa][Mm][Ee][Ss][Pp][Aa][Cc][Ee]");
	regex.Or(::deamer::dregx::v2::CBRegex("[Ff][Uu][Nn][Cc][Tt][Ii][Oo][Nn]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[Cc][Ll][Aa][Ss][Ss]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[Ee][Nn][Uu][Mm]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[Cc][Oo][Nn][Dd][Ii][Tt][Ii][Oo][Nn][Aa][Ll]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[Cc][Oo][Dd][Ee]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[Aa][Tt][Tt][Rr][Ii][Bb][Uu][Tt][Ee]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[Rr][Uu][Nn][Tt][Ii][Mm][Ee]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[Ss][Tt][Aa][Tt][Ii][Cc]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[Aa][Uu][Tt][Oo]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[Aa][Uu][Tt][Oo][Tt][Yy][Pp][Ee]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[Tt][Ee][Mm][Pp][Ll][Aa][Tt][Ee]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[Cc][Oo][Nn][Ss][Tt]([Aa][Nn][Tt]){0,1}"));
	regex.Or(::deamer::dregx::v2::CBRegex("[Oo][Vv][Ee][Rr][Rr][Ii][Dd][Ee]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[Vv][Ii][Rr][Tt][Uu][Aa][Ll]"));
	regex.Or(::deamer::dregx::v2::CBRegex("(([Pp][Uu][Rr][Ee])|([Aa][Bb][Ss][Tt][Rr][Aa][Cc][Tt]))"));
	regex.Or(::deamer::dregx::v2::CBRegex("[Aa][Ss]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[Ii][Nn]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[Dd][Ii][Ss][Pp][Ll][Aa][Yy]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[Rr][Ee][Tt][Uu][Rr][Nn]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[Ff][Oo][Rr]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[Ii][Ff]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[Ee][Ll][Ss][Ee]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[Ii][Nn][Ll][Ii][Nn][Ee]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[Cc][Oo][Nn][Ss][Tt][Rr][Uu][Cc][Tt][Oo][Rr]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[Ff][Ii][Ll][Ee]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[Pp][Rr][Oo][Gg][Rr][Aa][Mm]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[Ii][Mm][Pp][Oo][Rr][Tt]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[Aa][Ll][Ii][Aa][Ss]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[Pp][Uu][Bb][Ll][Ii][Cc]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[Pp][Rr][Oo][Tt][Ee][Cc][Tt][Ee][Dd]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[Pp][Rr][Ii][Vv][Aa][Tt][Ee]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[Ii][Nn][Hh][Ee][Rr][Ii][Tt]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[Cc][Oo][Mm][Pp][Oo][Ss][Ii][Tt][Ee]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[{]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[}]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[\\[]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[\\]]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[(]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[)]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[:]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[;]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[,]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[.]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[<][=]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[>][=]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[<]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[>]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[+][=]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[\\-][=]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[*][=]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[\\\\][=]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[=][=]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[=]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[!][=]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[!]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[+][+]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[+]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[\\-][\\-]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[\\-]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[\\\\]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[*]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[/][^\\n\\r]*[\\n\\r]{0,1}"));
	regex.Or(::deamer::dregx::v2::CBRegex("[/][*][^*]*[*][/]{0,1}"));
	regex.Or(::deamer::dregx::v2::CBRegex("[Ee][Ll]([Ss][Ee][ ]*){0,1}[Ii][Ff]"));

	EXPECT_TRUE(regex.Match("constant"));
	EXPECT_TRUE(regex.Match("function"));
	EXPECT_TRUE(regex.Match("class"));
	EXPECT_TRUE(regex.Match("enum"));
	EXPECT_TRUE(regex.Match("conditional"));
	EXPECT_TRUE(regex.Match("attribute"));
	EXPECT_TRUE(regex.Match("static"));
	EXPECT_TRUE(regex.Match("auto"));
	EXPECT_TRUE(regex.Match("autotype"));
	EXPECT_TRUE(regex.Match("template"));
	EXPECT_TRUE(regex.Match("namespace"));
	EXPECT_TRUE(regex.Match("/**/"));
	EXPECT_TRUE(regex.Match("/\n"));

	EXPECT_TRUE(regex.Match("<="));
	EXPECT_TRUE(regex.Match(">="));
	EXPECT_TRUE(regex.Match(">"));
	EXPECT_TRUE(regex.Match("<"));

	EXPECT_FALSE(regex.Match(""));
	EXPECT_FALSE(regex.Match("aa"));
	EXPECT_FALSE(regex.Match("ab"));
	EXPECT_FALSE(regex.Match("ba"));
	EXPECT_FALSE(regex.Match("bb"));
}

TEST_F(TestRegex, V2CBRegex_Or_CelesteFull_Match)
{
	auto regex = ::deamer::dregx::v2::CBRegex("[Nn][Aa][Mm][Ee][Ss][Pp][Aa][Cc][Ee]");
	regex.Or(::deamer::dregx::v2::CBRegex("[Ff][Uu][Nn][Cc][Tt][Ii][Oo][Nn]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[Cc][Ll][Aa][Ss][Ss]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[Ee][Nn][Uu][Mm]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[Cc][Oo][Nn][Dd][Ii][Tt][Ii][Oo][Nn][Aa][Ll]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[Cc][Oo][Dd][Ee]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[Aa][Tt][Tt][Rr][Ii][Bb][Uu][Tt][Ee]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[Rr][Uu][Nn][Tt][Ii][Mm][Ee]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[Ss][Tt][Aa][Tt][Ii][Cc]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[Aa][Uu][Tt][Oo]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[Aa][Uu][Tt][Oo][Tt][Yy][Pp][Ee]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[Tt][Ee][Mm][Pp][Ll][Aa][Tt][Ee]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[Cc][Oo][Nn][Ss][Tt]([Aa][Nn][Tt]){0,1}"));
	regex.Or(::deamer::dregx::v2::CBRegex("[Oo][Vv][Ee][Rr][Rr][Ii][Dd][Ee]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[Vv][Ii][Rr][Tt][Uu][Aa][Ll]"));
	regex.Or(::deamer::dregx::v2::CBRegex("(([Pp][Uu][Rr][Ee])|([Aa][Bb][Ss][Tt][Rr][Aa][Cc][Tt]))"));
	regex.Or(::deamer::dregx::v2::CBRegex("[Aa][Ss]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[Ii][Nn]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[Dd][Ii][Ss][Pp][Ll][Aa][Yy]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[Rr][Ee][Tt][Uu][Rr][Nn]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[Ff][Oo][Rr]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[Ii][Ff]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[Ee][Ll][Ss][Ee]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[Ii][Nn][Ll][Ii][Nn][Ee]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[Cc][Oo][Nn][Ss][Tt][Rr][Uu][Cc][Tt][Oo][Rr]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[Ff][Ii][Ll][Ee]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[Pp][Rr][Oo][Gg][Rr][Aa][Mm]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[Ii][Mm][Pp][Oo][Rr][Tt]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[Aa][Ll][Ii][Aa][Ss]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[Pp][Uu][Bb][Ll][Ii][Cc]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[Pp][Rr][Oo][Tt][Ee][Cc][Tt][Ee][Dd]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[Pp][Rr][Ii][Vv][Aa][Tt][Ee]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[Ii][Nn][Hh][Ee][Rr][Ii][Tt]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[Cc][Oo][Mm][Pp][Oo][Ss][Ii][Tt][Ee]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[{]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[}]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[\\[]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[\\]]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[(]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[)]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[:]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[;]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[,]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[.]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[<][=]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[>][=]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[<]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[>]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[+][=]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[\\-][=]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[*][=]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[\\\\][=]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[=][=]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[=]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[!][=]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[!]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[+][+]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[+]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[\\-][\\-]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[\\-]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[\\\\]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[*]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[/][^\\n\\r]*[\\n\\r]{0,1}"));
	regex.Or(::deamer::dregx::v2::CBRegex("[/][*][^*]*[*][/]{0,1}"));
	regex.Or(::deamer::dregx::v2::CBRegex("[Ee][Ll]([Ss][Ee][ ]*){0,1}[Ii][Ff]"));
	regex.Or(::deamer::dregx::v2::CBRegex(
		"[Oo][Pp][Ee][Rr][Aa][Tt][Oo][Rr][\\\\+\\-?!*%@#$\\^<>=:|\\[\\]]+"));
	regex.Or(::deamer::dregx::v2::CBRegex("[a-zA-Z_][a-zA-Z_0-9]*"));
	regex.Or(::deamer::dregx::v2::CBRegex("[\\-]{0,1}[0-9]+"));
	regex.Or(::deamer::dregx::v2::CBRegex("[\\-]{0,1}[0-9]+[\\.][0-9]+"));
	regex.Or(::deamer::dregx::v2::CBRegex("[\\\"]([\\\\][\\\"]|[\\\\][\\\\]|[^\\\"])*[\\\"]"));
	regex.Or(::deamer::dregx::v2::CBRegex("[\\n\\r\\t ]+"));

	EXPECT_TRUE(regex.Match("constant"));
	EXPECT_TRUE(regex.Match("function"));
	EXPECT_TRUE(regex.Match("class"));
	EXPECT_TRUE(regex.Match("enum"));
	EXPECT_TRUE(regex.Match("conditional"));
	EXPECT_TRUE(regex.Match("attribute"));
	EXPECT_TRUE(regex.Match("static"));
	EXPECT_TRUE(regex.Match("auto"));
	EXPECT_TRUE(regex.Match("autotype"));
	EXPECT_TRUE(regex.Match("template"));
	EXPECT_TRUE(regex.Match("namespace"));
	EXPECT_TRUE(regex.Match("/**/"));
	EXPECT_TRUE(regex.Match("/\n"));

	EXPECT_TRUE(regex.Match("<="));
	EXPECT_TRUE(regex.Match(">="));
	EXPECT_TRUE(regex.Match(">"));
	EXPECT_TRUE(regex.Match("<"));

	EXPECT_FALSE(regex.Match(""));
	EXPECT_TRUE(regex.Match("aa"));
	EXPECT_TRUE(regex.Match("ab"));
	EXPECT_TRUE(regex.Match("ba"));
	EXPECT_TRUE(regex.Match("bb"));
}

TEST_F(TestRegex, V1Regex_Or_CelesteFirst3_NoMatch)
{
	auto regex = ::deamer::dregx::Regex("[/][^\\n\\r]*[\\n\\r]{0,1}");
	regex.Or(::deamer::dregx::Regex("[/][*][^*]*[*][/]{0,1}"));
	regex.Or(::deamer::dregx::Regex("[Cc][Oo][Nn][Ss][Tt]([Aa][Nn][Tt]){0,1}"));
}

TEST_F(TestRegex, V1Regex_Or_CelesteFirst3_Match)
{
	auto regex = ::deamer::dregx::Regex("[/][^\\n\\r]*[\\n\\r]{0,1}");
	regex.Or(::deamer::dregx::Regex("[/][*][^*]*[*][/]{0,1}"));
	regex.Or(::deamer::dregx::Regex("[Cc][Oo][Nn][Ss][Tt]([Aa][Nn][Tt]){0,1}"));

	EXPECT_TRUE(regex.Match("constant"));
	EXPECT_TRUE(regex.Match("/**/"));
	EXPECT_TRUE(regex.Match("/\n"));

	EXPECT_FALSE(regex.Match(""));
	EXPECT_FALSE(regex.Match("aa"));
	EXPECT_FALSE(regex.Match("ab"));
	EXPECT_FALSE(regex.Match("ba"));
	EXPECT_FALSE(regex.Match("bb"));
}


TEST_F(TestRegex, RegexOperatorOr_CelesteLexiconFirst15)
{
	auto regex = ::deamer::dregx::Regex("[/][^\\n\\r]*[\\n\\r]{0,1}");
	regex.Or(::deamer::dregx::Regex("[/][*][^*]*[*][/]{0,1}"));
	regex.Or(::deamer::dregx::Regex("[Cc][Oo][Nn][Ss][Tt]([Aa][Nn][Tt]){0,1}"));
	regex.Or(::deamer::dregx::Regex("[Ff][Uu][Nn][Cc][Tt][Ii][Oo][Nn]"));
	regex.Or(::deamer::dregx::Regex("[Cc][Ll][Aa][Ss][Ss]"));
	regex.Or(::deamer::dregx::Regex("[Ee][Nn][Uu][Mm]"));
	regex.Or(::deamer::dregx::Regex("[Cc][Oo][Nn][Dd][Ii][Tt][Ii][Oo][Nn][Aa][Ll]"));
	regex.Or(::deamer::dregx::Regex("[Cc][Oo][Dd][Ee]"));
	regex.Or(::deamer::dregx::Regex("[Aa][Tt][Tt][Rr][Ii][Bb][Uu][Tt][Ee]"));
	regex.Or(::deamer::dregx::Regex("[Rr][Uu][Nn][Tt][Ii][Mm][Ee]"));
	regex.Or(::deamer::dregx::Regex("[Ss][Tt][Aa][Tt][Ii][Cc]"));
	regex.Or(::deamer::dregx::Regex("[Aa][Uu][Tt][Oo]"));
	regex.Or(::deamer::dregx::Regex("[Aa][Uu][Tt][Oo][Tt][Yy][Pp][Ee]"));
	regex.Or(::deamer::dregx::Regex("[Tt][Ee][Mm][Pp][Ll][Aa][Tt][Ee]"));
	regex.Or(::deamer::dregx::Regex("[Nn][Aa][Mm][Ee][Ss][Pp][Aa][Cc][Ee]"));
	return;
	regex.Or(
		::deamer::dregx::Regex("[Oo][Pp][Ee][Rr][Aa][Tt][Oo][Rr][\\\\+\\-?!*%@#$\\^<>=:|\\[\\]]+"));
	regex.Or(::deamer::dregx::Regex("[Oo][Vv][Ee][Rr][Rr][Ii][Dd][Ee]"));
	regex.Or(::deamer::dregx::Regex("[Vv][Ii][Rr][Tt][Uu][Aa][Ll]"));
	regex.Or(::deamer::dregx::Regex("(([Pp][Uu][Rr][Ee])|([Aa][Bb][Ss][Tt][Rr][Aa][Cc][Tt]))"));
	regex.Or(::deamer::dregx::Regex("[Aa][Ss]"));
	regex.Or(::deamer::dregx::Regex("[Ii][Nn]"));
	regex.Or(::deamer::dregx::Regex("[Dd][Ii][Ss][Pp][Ll][Aa][Yy]"));
	regex.Or(::deamer::dregx::Regex("[Rr][Ee][Tt][Uu][Rr][Nn]"));
	regex.Or(::deamer::dregx::Regex("[Ff][Oo][Rr]"));
	regex.Or(::deamer::dregx::Regex("[Ii][Ff]"));
	regex.Or(::deamer::dregx::Regex("[Ee][Ll]([Ss][Ee][ ]*){0,1}[Ii][Ff]"));
	regex.Or(::deamer::dregx::Regex("[Ee][Ll][Ss][Ee]"));
	regex.Or(::deamer::dregx::Regex("[Ii][Nn][Ll][Ii][Nn][Ee]"));
	regex.Or(::deamer::dregx::Regex("[Cc][Oo][Nn][Ss][Tt][Rr][Uu][Cc][Tt][Oo][Rr]"));
	regex.Or(::deamer::dregx::Regex("[Ff][Ii][Ll][Ee]"));
	regex.Or(::deamer::dregx::Regex("[Pp][Rr][Oo][Gg][Rr][Aa][Mm]"));
	regex.Or(::deamer::dregx::Regex("[Ii][Mm][Pp][Oo][Rr][Tt]"));
	regex.Or(::deamer::dregx::Regex("[Aa][Ll][Ii][Aa][Ss]"));
	regex.Or(::deamer::dregx::Regex("[Pp][Uu][Bb][Ll][Ii][Cc]"));
	regex.Or(::deamer::dregx::Regex("[Pp][Rr][Oo][Tt][Ee][Cc][Tt][Ee][Dd]"));
	regex.Or(::deamer::dregx::Regex("[Pp][Rr][Ii][Vv][Aa][Tt][Ee]"));
	regex.Or(::deamer::dregx::Regex("[Ii][Nn][Hh][Ee][Rr][Ii][Tt]"));
	regex.Or(::deamer::dregx::Regex("[Cc][Oo][Mm][Pp][Oo][Ss][Ii][Tt][Ee]"));
	regex.Or(::deamer::dregx::Regex("[{]"));
	regex.Or(::deamer::dregx::Regex("[}]"));
	regex.Or(::deamer::dregx::Regex("[\\[]"));
	regex.Or(::deamer::dregx::Regex("[\\]]"));
	regex.Or(::deamer::dregx::Regex("[(]"));
	regex.Or(::deamer::dregx::Regex("[)]"));
	regex.Or(::deamer::dregx::Regex("[:]"));
	regex.Or(::deamer::dregx::Regex("[;]"));
	regex.Or(::deamer::dregx::Regex("[,]"));
	regex.Or(::deamer::dregx::Regex("[.]"));
	regex.Or(::deamer::dregx::Regex("[<][=]"));
	regex.Or(::deamer::dregx::Regex("[>][=]"));
	regex.Or(::deamer::dregx::Regex("[<]"));
	regex.Or(::deamer::dregx::Regex("[>]"));
	regex.Or(::deamer::dregx::Regex("[+][=]"));
	regex.Or(::deamer::dregx::Regex("[\\-][=]"));
	regex.Or(::deamer::dregx::Regex("[*][=]"));
	regex.Or(::deamer::dregx::Regex("[\\\\][=]"));
	regex.Or(::deamer::dregx::Regex("[=][=]"));
	regex.Or(::deamer::dregx::Regex("[=]"));
	regex.Or(::deamer::dregx::Regex("[!][=]"));
	regex.Or(::deamer::dregx::Regex("[!]"));
	regex.Or(::deamer::dregx::Regex("[+][+]"));
	regex.Or(::deamer::dregx::Regex("[+]"));
	regex.Or(::deamer::dregx::Regex("[\\-][\\-]"));
	regex.Or(::deamer::dregx::Regex("[\\-]"));
	regex.Or(::deamer::dregx::Regex("[\\\\]"));
	regex.Or(::deamer::dregx::Regex("[*]"));
	regex.Or(::deamer::dregx::Regex("[a-zA-Z_][a-zA-Z_0-9]*"));
	regex.Or(::deamer::dregx::Regex("[\\-]{0,1}[0-9]+"));
	regex.Or(::deamer::dregx::Regex("[\\-]{0,1}[0-9]+[\\.][0-9]+"));
	regex.Or(::deamer::dregx::Regex("[\\\"]([\\\\][\\\"]|[\\\\][\\\\]|[^\\\"])*[\\\"]"));
	regex.Or(::deamer::dregx::Regex("[\\n\\r\\t ]+"));
}

TEST_F(TestRegex, RegexOperatorOr_CelesteLexiconFirst65)
{
	auto regex = ::deamer::dregx::Regex("[Cc][Oo][Nn][Ss][Tt]([Aa][Nn][Tt]){0,1}");
	regex.Or(::deamer::dregx::Regex("[Ff][Uu][Nn][Cc][Tt][Ii][Oo][Nn]"));
	regex.Or(::deamer::dregx::Regex("[Cc][Ll][Aa][Ss][Ss]"));
	regex.Or(::deamer::dregx::Regex("[Ee][Nn][Uu][Mm]"));
	regex.Or(::deamer::dregx::Regex("[Cc][Oo][Nn][Dd][Ii][Tt][Ii][Oo][Nn][Aa][Ll]"));
	regex.Or(::deamer::dregx::Regex("[Cc][Oo][Dd][Ee]"));
	regex.Or(::deamer::dregx::Regex("[Aa][Tt][Tt][Rr][Ii][Bb][Uu][Tt][Ee]"));
	regex.Or(::deamer::dregx::Regex("[Rr][Uu][Nn][Tt][Ii][Mm][Ee]"));
	regex.Or(::deamer::dregx::Regex("[Ss][Tt][Aa][Tt][Ii][Cc]"));
	regex.Or(::deamer::dregx::Regex("[Aa][Uu][Tt][Oo]"));
	regex.Or(::deamer::dregx::Regex("[Aa][Uu][Tt][Oo][Tt][Yy][Pp][Ee]"));
	regex.Or(::deamer::dregx::Regex("[Tt][Ee][Mm][Pp][Ll][Aa][Tt][Ee]"));
	regex.Or(::deamer::dregx::Regex("[Nn][Aa][Mm][Ee][Ss][Pp][Aa][Cc][Ee]"));
	regex.Or(::deamer::dregx::Regex("[Oo][Vv][Ee][Rr][Rr][Ii][Dd][Ee]"));
	regex.Or(::deamer::dregx::Regex("[Vv][Ii][Rr][Tt][Uu][Aa][Ll]"));
	regex.Or(::deamer::dregx::Regex("(([Pp][Uu][Rr][Ee])|([Aa][Bb][Ss][Tt][Rr][Aa][Cc][Tt]))"));
	regex.Or(::deamer::dregx::Regex("[Aa][Ss]"));
	regex.Or(::deamer::dregx::Regex("[Ii][Nn]"));
	regex.Or(::deamer::dregx::Regex("[Dd][Ii][Ss][Pp][Ll][Aa][Yy]"));
	regex.Or(::deamer::dregx::Regex("[Rr][Ee][Tt][Uu][Rr][Nn]"));
	regex.Or(::deamer::dregx::Regex("[Ff][Oo][Rr]"));
	regex.Or(::deamer::dregx::Regex("[Ii][Ff]"));
	regex.Or(::deamer::dregx::Regex("[Ee][Ll][Ss][Ee]"));
	regex.Or(::deamer::dregx::Regex("[Ii][Nn][Ll][Ii][Nn][Ee]"));
	regex.Or(::deamer::dregx::Regex("[Cc][Oo][Nn][Ss][Tt][Rr][Uu][Cc][Tt][Oo][Rr]"));
	regex.Or(::deamer::dregx::Regex("[Ff][Ii][Ll][Ee]"));
	regex.Or(::deamer::dregx::Regex("[Pp][Rr][Oo][Gg][Rr][Aa][Mm]"));
	regex.Or(::deamer::dregx::Regex("[Ii][Mm][Pp][Oo][Rr][Tt]"));
	regex.Or(::deamer::dregx::Regex("[Aa][Ll][Ii][Aa][Ss]"));
	regex.Or(::deamer::dregx::Regex("[Pp][Uu][Bb][Ll][Ii][Cc]"));
	regex.Or(::deamer::dregx::Regex("[Pp][Rr][Oo][Tt][Ee][Cc][Tt][Ee][Dd]"));
	regex.Or(::deamer::dregx::Regex("[Pp][Rr][Ii][Vv][Aa][Tt][Ee]"));
	regex.Or(::deamer::dregx::Regex("[Ii][Nn][Hh][Ee][Rr][Ii][Tt]"));
	regex.Or(::deamer::dregx::Regex("[Cc][Oo][Mm][Pp][Oo][Ss][Ii][Tt][Ee]"));
	regex.Or(::deamer::dregx::Regex("[{]"));
	regex.Or(::deamer::dregx::Regex("[}]"));
	regex.Or(::deamer::dregx::Regex("[\\[]"));
	regex.Or(::deamer::dregx::Regex("[\\]]"));
	regex.Or(::deamer::dregx::Regex("[(]"));
	regex.Or(::deamer::dregx::Regex("[)]"));
	regex.Or(::deamer::dregx::Regex("[:]"));
	regex.Or(::deamer::dregx::Regex("[;]"));
	regex.Or(::deamer::dregx::Regex("[,]"));
	regex.Or(::deamer::dregx::Regex("[.]"));
	regex.Or(::deamer::dregx::Regex("[<][=]"));
	regex.Or(::deamer::dregx::Regex("[>][=]"));
	regex.Or(::deamer::dregx::Regex("[<]"));
	regex.Or(::deamer::dregx::Regex("[>]"));
	regex.Or(::deamer::dregx::Regex("[+][=]"));
	regex.Or(::deamer::dregx::Regex("[\\-][=]"));
	regex.Or(::deamer::dregx::Regex("[*][=]"));
	regex.Or(::deamer::dregx::Regex("[\\\\][=]"));
	regex.Or(::deamer::dregx::Regex("[=][=]"));
	regex.Or(::deamer::dregx::Regex("[=]"));
	regex.Or(::deamer::dregx::Regex("[!][=]"));
	regex.Or(::deamer::dregx::Regex("[!]"));
	regex.Or(::deamer::dregx::Regex("[+][+]"));
	regex.Or(::deamer::dregx::Regex("[+]"));
	regex.Or(::deamer::dregx::Regex("[\\-][\\-]"));
	regex.Or(::deamer::dregx::Regex("[\\-]"));
	regex.Or(::deamer::dregx::Regex("[\\\\]"));
	regex.Or(::deamer::dregx::Regex("[*]"));
	regex.Or(::deamer::dregx::Regex("[/][*][^*]*[*][/]{0,1}"));
	regex.Or(::deamer::dregx::Regex("[/][^\\n\\r]*[\\n\\r]{0,1}"));
	regex.Or(::deamer::dregx::Regex("[Ee][Ll]([Ss][Ee][ ]*){0,1}[Ii][Ff]"));
	return;
	regex.Or(
		::deamer::dregx::Regex("[Oo][Pp][Ee][Rr][Aa][Tt][Oo][Rr][\\\\+\\-?!*%@#$\\^<>=:|\\[\\]]+"));
	regex.Or(::deamer::dregx::Regex("[a-zA-Z_][a-zA-Z_0-9]*"));
	regex.Or(::deamer::dregx::Regex("[\\-]{0,1}[0-9]+"));
	regex.Or(::deamer::dregx::Regex("[\\-]{0,1}[0-9]+[\\.][0-9]+"));
	regex.Or(::deamer::dregx::Regex("[\\\"]([\\\\][\\\"]|[\\\\][\\\\]|[^\\\"])*[\\\"]"));
	regex.Or(::deamer::dregx::Regex("[\\n\\r\\t ]+"));
}

TEST_F(TestRegex, RegexOperatorOr_CelesteLexiconFull)
{
	auto regex = ::deamer::dregx::Regex("[Cc][Oo][Nn][Ss][Tt]([Aa][Nn][Tt]){0,1}");
	regex.Or(::deamer::dregx::Regex("[Ff][Uu][Nn][Cc][Tt][Ii][Oo][Nn]"));
	regex.Or(::deamer::dregx::Regex("[Cc][Ll][Aa][Ss][Ss]"));
	regex.Or(::deamer::dregx::Regex("[Ee][Nn][Uu][Mm]"));
	regex.Or(::deamer::dregx::Regex("[Cc][Oo][Nn][Dd][Ii][Tt][Ii][Oo][Nn][Aa][Ll]"));
	regex.Or(::deamer::dregx::Regex("[Cc][Oo][Dd][Ee]"));
	regex.Or(::deamer::dregx::Regex("[Aa][Tt][Tt][Rr][Ii][Bb][Uu][Tt][Ee]"));
	regex.Or(::deamer::dregx::Regex("[Rr][Uu][Nn][Tt][Ii][Mm][Ee]"));
	regex.Or(::deamer::dregx::Regex("[Ss][Tt][Aa][Tt][Ii][Cc]"));
	regex.Or(::deamer::dregx::Regex("[Aa][Uu][Tt][Oo]"));
	regex.Or(::deamer::dregx::Regex("[Aa][Uu][Tt][Oo][Tt][Yy][Pp][Ee]"));
	regex.Or(::deamer::dregx::Regex("[Tt][Ee][Mm][Pp][Ll][Aa][Tt][Ee]"));
	regex.Or(::deamer::dregx::Regex("[Nn][Aa][Mm][Ee][Ss][Pp][Aa][Cc][Ee]"));
	regex.Or(::deamer::dregx::Regex("[Oo][Vv][Ee][Rr][Rr][Ii][Dd][Ee]"));
	regex.Or(::deamer::dregx::Regex("[Vv][Ii][Rr][Tt][Uu][Aa][Ll]"));
	regex.Or(::deamer::dregx::Regex("(([Pp][Uu][Rr][Ee])|([Aa][Bb][Ss][Tt][Rr][Aa][Cc][Tt]))"));
	regex.Or(::deamer::dregx::Regex("[Aa][Ss]"));
	regex.Or(::deamer::dregx::Regex("[Ii][Nn]"));
	regex.Or(::deamer::dregx::Regex("[Dd][Ii][Ss][Pp][Ll][Aa][Yy]"));
	regex.Or(::deamer::dregx::Regex("[Rr][Ee][Tt][Uu][Rr][Nn]"));
	regex.Or(::deamer::dregx::Regex("[Ff][Oo][Rr]"));
	regex.Or(::deamer::dregx::Regex("[Ii][Ff]"));
	regex.Or(::deamer::dregx::Regex("[Ee][Ll][Ss][Ee]"));
	regex.Or(::deamer::dregx::Regex("[Ii][Nn][Ll][Ii][Nn][Ee]"));
	regex.Or(::deamer::dregx::Regex("[Cc][Oo][Nn][Ss][Tt][Rr][Uu][Cc][Tt][Oo][Rr]"));
	regex.Or(::deamer::dregx::Regex("[Ff][Ii][Ll][Ee]"));
	regex.Or(::deamer::dregx::Regex("[Pp][Rr][Oo][Gg][Rr][Aa][Mm]"));
	regex.Or(::deamer::dregx::Regex("[Ii][Mm][Pp][Oo][Rr][Tt]"));
	regex.Or(::deamer::dregx::Regex("[Aa][Ll][Ii][Aa][Ss]"));
	regex.Or(::deamer::dregx::Regex("[Pp][Uu][Bb][Ll][Ii][Cc]"));
	regex.Or(::deamer::dregx::Regex("[Pp][Rr][Oo][Tt][Ee][Cc][Tt][Ee][Dd]"));
	regex.Or(::deamer::dregx::Regex("[Pp][Rr][Ii][Vv][Aa][Tt][Ee]"));
	regex.Or(::deamer::dregx::Regex("[Ii][Nn][Hh][Ee][Rr][Ii][Tt]"));
	regex.Or(::deamer::dregx::Regex("[Cc][Oo][Mm][Pp][Oo][Ss][Ii][Tt][Ee]"));
	regex.Or(::deamer::dregx::Regex("[{]"));
	regex.Or(::deamer::dregx::Regex("[}]"));
	regex.Or(::deamer::dregx::Regex("[\\[]"));
	regex.Or(::deamer::dregx::Regex("[\\]]"));
	regex.Or(::deamer::dregx::Regex("[(]"));
	regex.Or(::deamer::dregx::Regex("[)]"));
	regex.Or(::deamer::dregx::Regex("[:]"));
	regex.Or(::deamer::dregx::Regex("[;]"));
	regex.Or(::deamer::dregx::Regex("[,]"));
	regex.Or(::deamer::dregx::Regex("[.]"));
	regex.Or(::deamer::dregx::Regex("[<][=]"));
	regex.Or(::deamer::dregx::Regex("[>][=]"));
	regex.Or(::deamer::dregx::Regex("[<]"));
	regex.Or(::deamer::dregx::Regex("[>]"));
	regex.Or(::deamer::dregx::Regex("[+][=]"));
	regex.Or(::deamer::dregx::Regex("[\\-][=]"));
	regex.Or(::deamer::dregx::Regex("[*][=]"));
	regex.Or(::deamer::dregx::Regex("[\\\\][=]"));
	regex.Or(::deamer::dregx::Regex("[=][=]"));
	regex.Or(::deamer::dregx::Regex("[=]"));
	regex.Or(::deamer::dregx::Regex("[!][=]"));
	regex.Or(::deamer::dregx::Regex("[!]"));
	regex.Or(::deamer::dregx::Regex("[+][+]"));
	regex.Or(::deamer::dregx::Regex("[+]"));
	regex.Or(::deamer::dregx::Regex("[\\-][\\-]"));
	regex.Or(::deamer::dregx::Regex("[\\-]"));
	regex.Or(::deamer::dregx::Regex("[\\\\]"));
	regex.Or(::deamer::dregx::Regex("[*]"));
	regex.Or(::deamer::dregx::Regex("[/][*][^*]*[*][/]{0,1}"));
	regex.Or(::deamer::dregx::Regex("[/][^\\n\\r]*[\\n\\r]{0,1}"));
	regex.Or(::deamer::dregx::Regex("[Ee][Ll]([Ss][Ee][ ]*){0,1}[Ii][Ff]"));
	regex.Or(
		::deamer::dregx::Regex("[Oo][Pp][Ee][Rr][Aa][Tt][Oo][Rr][\\\\+\\-?!*%@#$\\^<>=:|\\[\\]]+"));
	regex.Or(::deamer::dregx::Regex("[a-zA-Z_][a-zA-Z_0-9]*"));
	regex.Or(::deamer::dregx::Regex("[\\-]{0,1}[0-9]+"));
	regex.Or(::deamer::dregx::Regex("[\\-]{0,1}[0-9]+[\\.][0-9]+"));
	regex.Or(::deamer::dregx::Regex("[\\\"]([\\\\][\\\"]|[\\\\][\\\\]|[^\\\"])*[\\\"]"));
	regex.Or(::deamer::dregx::Regex("[\\n\\r\\t ]+"));
}
