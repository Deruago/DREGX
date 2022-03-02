#include "Deamer/Dregx/Regex.h"
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
