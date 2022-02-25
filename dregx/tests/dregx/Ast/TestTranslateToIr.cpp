#include "Deamer/External/Cpp/Ast/Tree.h"
#include "dregx/Ast/Listener/User/TranslateToIr.h"
#include "dregx/Bison/Parser.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <memory>
#include <optional>

using namespace dregx;

class TestTranslateToIr : public testing::Test
{
public:
protected:
	TestTranslateToIr() = default;

	virtual ~TestTranslateToIr() = default;

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

TEST_F(TestTranslateToIr, RegexWithSquareCapture_ShouldConvertToSimpleSquareIr)
{
	auto tree = Parse("[a]");
	translator.Dispatch(tree.value());

	const auto ir = translator.GetOutput();
	ASSERT_NE(nullptr, ir);

	auto subGroups = ir->GetSubGroups();
	EXPECT_EQ(1, subGroups.size());

	const auto square = subGroups.at(0);
	subGroups = square->GetSubGroups();
	EXPECT_EQ(ir::CaptureType::square, square->GetCaptureType());
	EXPECT_EQ(1, subGroups.size());
	EXPECT_EQ("[a]", square->GetFormattedRegex());

	const auto character = subGroups.at(0);
	subGroups = character->GetSubGroups();
	EXPECT_EQ(ir::CaptureType::character, character->GetCaptureType());
	EXPECT_EQ(0, subGroups.size());
	EXPECT_EQ("a", character->GetFormattedRegex());
}

TEST_F(TestTranslateToIr, RegexWithSquare2LetterCaptures_ShouldConvertToSimpleSquareIr)
{
	auto tree = Parse("[ab]");
	translator.Dispatch(tree.value());

	const auto ir = translator.GetOutput();
	ASSERT_NE(nullptr, ir);

	auto subGroups = ir->GetSubGroups();
	EXPECT_EQ(1, subGroups.size());

	const auto square = subGroups.at(0);
	subGroups = square->GetSubGroups();
	EXPECT_EQ(ir::CaptureType::square, square->GetCaptureType());
	EXPECT_EQ(2, subGroups.size());
	EXPECT_EQ("[ab]", square->GetFormattedRegex());

	const auto character1 = subGroups.at(0);
	EXPECT_EQ(ir::CaptureType::character, character1->GetCaptureType());
	EXPECT_EQ("a", character1->GetFormattedRegex());

	const auto character2 = subGroups.at(1);
	EXPECT_EQ(ir::CaptureType::character, character2->GetCaptureType());
	EXPECT_EQ("b", character2->GetFormattedRegex());
}

TEST_F(TestTranslateToIr, RegexWithSquare3LetterCaptures_ShouldConvertToSimpleSquareIr)
{
	auto tree = Parse("[abc]");
	translator.Dispatch(tree.value());

	const auto ir = translator.GetOutput();
	ASSERT_NE(nullptr, ir);

	auto subGroups = ir->GetSubGroups();
	EXPECT_EQ(1, subGroups.size());

	const auto square = subGroups.at(0);
	subGroups = square->GetSubGroups();
	EXPECT_EQ(ir::CaptureType::square, square->GetCaptureType());
	EXPECT_EQ(3, subGroups.size());
	EXPECT_EQ("[abc]", square->GetFormattedRegex());

	const auto character1 = subGroups.at(0);
	EXPECT_EQ(ir::CaptureType::character, character1->GetCaptureType());
	EXPECT_EQ("a", character1->GetFormattedRegex());

	const auto character2 = subGroups.at(1);
	EXPECT_EQ(ir::CaptureType::character, character2->GetCaptureType());
	EXPECT_EQ("b", character2->GetFormattedRegex());

	const auto character3 = subGroups.at(2);
	EXPECT_EQ(ir::CaptureType::character, character3->GetCaptureType());
	EXPECT_EQ("c", character3->GetFormattedRegex());
}

TEST_F(TestTranslateToIr, RegexWithSquare1EscapeCharacterCaptures_ShouldConvertToSimpleSquareIr)
{
	auto tree = Parse("[\\n]");
	translator.Dispatch(tree.value());

	const auto ir = translator.GetOutput();
	ASSERT_NE(nullptr, ir);

	auto subGroups = ir->GetSubGroups();
	EXPECT_EQ(1, subGroups.size());

	const auto square = subGroups.at(0);
	subGroups = square->GetSubGroups();
	EXPECT_EQ(ir::CaptureType::square, square->GetCaptureType());
	EXPECT_EQ(1, subGroups.size());
	EXPECT_EQ("[\n]", square->GetFormattedRegex());

	const auto character1 = subGroups.at(0);
	EXPECT_EQ(ir::CaptureType::escapecharacter, character1->GetCaptureType());
	EXPECT_EQ("\n", character1->GetFormattedRegex());
}

TEST_F(TestTranslateToIr,
	   RegexWithSquare1EscapeCharacter1LetterCaptures_ShouldConvertToSimpleSquareIr)
{
	auto tree = Parse("[\\nb]");
	translator.Dispatch(tree.value());

	const auto ir = translator.GetOutput();
	ASSERT_NE(nullptr, ir);

	auto subGroups = ir->GetSubGroups();
	EXPECT_EQ(1, subGroups.size());

	const auto square = subGroups.at(0);
	subGroups = square->GetSubGroups();
	EXPECT_EQ(ir::CaptureType::square, square->GetCaptureType());
	EXPECT_EQ(2, subGroups.size());
	EXPECT_EQ("[\nb]", square->GetFormattedRegex());

	const auto character1 = subGroups.at(0);
	EXPECT_EQ(ir::CaptureType::escapecharacter, character1->GetCaptureType());
	EXPECT_EQ("\n", character1->GetFormattedRegex());

	const auto character2 = subGroups.at(1);
	EXPECT_EQ(ir::CaptureType::character, character2->GetCaptureType());
	EXPECT_EQ("b", character2->GetFormattedRegex());
}

TEST_F(TestTranslateToIr,
	   RegexWithSquare1EscapeCharacter1SpaceCaptures_ShouldConvertToSimpleSquareIr)
{
	auto tree = Parse("[\\n ]");
	translator.Dispatch(tree.value());

	const auto ir = translator.GetOutput();
	ASSERT_NE(nullptr, ir);

	auto subGroups = ir->GetSubGroups();
	EXPECT_EQ(1, subGroups.size());

	const auto square = subGroups.at(0);
	subGroups = square->GetSubGroups();
	EXPECT_EQ(ir::CaptureType::square, square->GetCaptureType());
	EXPECT_EQ(2, subGroups.size());
	EXPECT_EQ("[\n ]", square->GetFormattedRegex());

	const auto character1 = subGroups.at(0);
	EXPECT_EQ(ir::CaptureType::escapecharacter, character1->GetCaptureType());
	EXPECT_EQ("\n", character1->GetFormattedRegex());

	const auto character2 = subGroups.at(1);
	EXPECT_EQ(ir::CaptureType::character, character2->GetCaptureType());
	EXPECT_EQ(" ", character2->GetFormattedRegex());
}

TEST_F(TestTranslateToIr, RegexWithSquare1EscapeCharacter1TabCaptures_ShouldConvertToSimpleSquareIr)
{
	auto tree = Parse("[\\n\t]");
	translator.Dispatch(tree.value());

	const auto ir = translator.GetOutput();
	ASSERT_NE(nullptr, ir);

	auto subGroups = ir->GetSubGroups();
	EXPECT_EQ(1, subGroups.size());

	const auto square = subGroups.at(0);
	subGroups = square->GetSubGroups();
	EXPECT_EQ(ir::CaptureType::square, square->GetCaptureType());
	EXPECT_EQ(2, subGroups.size());
	EXPECT_EQ("[\n\t]", square->GetFormattedRegex());

	const auto character1 = subGroups.at(0);
	EXPECT_EQ(ir::CaptureType::escapecharacter, character1->GetCaptureType());
	EXPECT_EQ("\n", character1->GetFormattedRegex());

	const auto character2 = subGroups.at(1);
	EXPECT_EQ(ir::CaptureType::character, character2->GetCaptureType());
	EXPECT_EQ("\t", character2->GetFormattedRegex());
}

TEST_F(TestTranslateToIr,
	   RegexWithSquare1EscapeCharacter2TabsCaptures_ShouldConvertToSimpleSquareIr)
{
	auto tree = Parse("[\\n\t\t]");
	translator.Dispatch(tree.value());

	const auto ir = translator.GetOutput();
	ASSERT_NE(nullptr, ir);

	auto subGroups = ir->GetSubGroups();
	EXPECT_EQ(1, subGroups.size());

	const auto square = subGroups.at(0);
	subGroups = square->GetSubGroups();
	EXPECT_EQ(ir::CaptureType::square, square->GetCaptureType());
	EXPECT_EQ(3, subGroups.size());
	EXPECT_EQ("[\n\t\t]", square->GetFormattedRegex());

	const auto character1 = subGroups.at(0);
	EXPECT_EQ(ir::CaptureType::escapecharacter, character1->GetCaptureType());
	EXPECT_EQ("\n", character1->GetFormattedRegex());

	const auto character2 = subGroups.at(1);
	EXPECT_EQ(ir::CaptureType::character, character2->GetCaptureType());
	EXPECT_EQ("\t", character2->GetFormattedRegex());

	const auto character3 = subGroups.at(2);
	EXPECT_EQ(ir::CaptureType::character, character3->GetCaptureType());
	EXPECT_EQ("\t", character3->GetFormattedRegex());
}

TEST_F(TestTranslateToIr,
	   RegexWithSquare1EscapeCharacter1Space1TabsCaptures_ShouldConvertToSimpleSquareIr)
{
	auto tree = Parse("[\\n \t]");
	translator.Dispatch(tree.value());

	const auto ir = translator.GetOutput();
	ASSERT_NE(nullptr, ir);

	auto subGroups = ir->GetSubGroups();
	EXPECT_EQ(1, subGroups.size());

	const auto square = subGroups.at(0);
	subGroups = square->GetSubGroups();
	EXPECT_EQ(ir::CaptureType::square, square->GetCaptureType());
	EXPECT_EQ(3, subGroups.size());
	EXPECT_EQ("[\n \t]", square->GetFormattedRegex());

	const auto character1 = subGroups.at(0);
	EXPECT_EQ(ir::CaptureType::escapecharacter, character1->GetCaptureType());
	EXPECT_EQ("\n", character1->GetFormattedRegex());

	const auto character2 = subGroups.at(1);
	EXPECT_EQ(ir::CaptureType::character, character2->GetCaptureType());
	EXPECT_EQ(" ", character2->GetFormattedRegex());

	const auto character3 = subGroups.at(2);
	EXPECT_EQ(ir::CaptureType::character, character3->GetCaptureType());
	EXPECT_EQ("\t", character3->GetFormattedRegex());
}

TEST_F(TestTranslateToIr,
	   RegexWithSquareWithExtensionModifierPlusCaptures_ShouldConvertToSimpleSquareIr)
{
	auto tree = Parse("[abcde]+");
	translator.Dispatch(tree.value());

	const auto ir = translator.GetOutput();
	ASSERT_NE(nullptr, ir);

	const auto square = ir->GetSubGroups().at(0);
	EXPECT_EQ(ir::CaptureType::square, square->GetCaptureType());
	EXPECT_EQ("[abcde]+", square->GetFormattedRegex());
	EXPECT_EQ(1, square->GetExtension().GetLowerBound());
	EXPECT_TRUE(square->GetExtension().IsUpperBoundInfinite());
	EXPECT_EQ("+", square->GetExtension().GetFormattedRegex());
}

TEST_F(TestTranslateToIr,
	   RegexWithSquareWithExtensionModifierStarCaptures_ShouldConvertToSimpleSquareIr)
{
	auto tree = Parse("[abcde]*");
	translator.Dispatch(tree.value());

	const auto ir = translator.GetOutput();
	ASSERT_NE(nullptr, ir);

	const auto square = ir->GetSubGroups().at(0);
	EXPECT_EQ(ir::CaptureType::square, square->GetCaptureType());
	EXPECT_EQ("[abcde]*", square->GetFormattedRegex());
	EXPECT_EQ(0, square->GetExtension().GetLowerBound());
	EXPECT_TRUE(square->GetExtension().IsUpperBoundInfinite());
	EXPECT_EQ("*", square->GetExtension().GetFormattedRegex());
}

TEST_F(TestTranslateToIr,
	   RegexWithSquareWithExtensionModifierCustomCaptures_ShouldConvertToSimpleSquareIr)
{
	auto tree = Parse("[abcde]{4,10}");
	translator.Dispatch(tree.value());

	const auto ir = translator.GetOutput();
	ASSERT_NE(nullptr, ir);

	const auto square = ir->GetSubGroups().at(0);
	EXPECT_EQ(ir::CaptureType::square, square->GetCaptureType());
	EXPECT_EQ("[abcde]{4,10}", square->GetFormattedRegex());
	EXPECT_EQ(4, square->GetExtension().GetLowerBound());
	EXPECT_EQ(10, square->GetExtension().GetUpperBound());
	EXPECT_FALSE(square->GetExtension().IsUpperBoundInfinite());
	EXPECT_EQ("{4,10}", square->GetExtension().GetFormattedRegex());
}

TEST_F(TestTranslateToIr, RegexWithSquareWithRangeCapture_ShouldConvertToSimpleSquareIr)
{
	auto tree = Parse("[a-z]");
	translator.Dispatch(tree.value());

	const auto ir = translator.GetOutput();
	ASSERT_NE(nullptr, ir);

	auto subGroups = ir->GetSubGroups();
	EXPECT_EQ(1, subGroups.size());

	const auto square = subGroups.at(0);
	subGroups = square->GetSubGroups();
	EXPECT_EQ(ir::CaptureType::square, square->GetCaptureType());
	EXPECT_EQ(1, subGroups.size());
	EXPECT_EQ("[a-z]", square->GetFormattedRegex());

	const auto character = subGroups.at(0);
	subGroups = character->GetSubGroups();
	EXPECT_EQ(ir::CaptureType::capturerange, character->GetCaptureType());
	EXPECT_EQ(0, subGroups.size());
	EXPECT_EQ("a-z", character->GetFormattedRegex());
}

TEST_F(TestTranslateToIr, RegexWithSquareWith2RangeCapture_ShouldConvertToSimpleSquareIr)
{
	auto tree = Parse("[a-zA-Z]");
	translator.Dispatch(tree.value());

	const auto ir = translator.GetOutput();
	ASSERT_NE(nullptr, ir);

	auto subGroups = ir->GetSubGroups();
	EXPECT_EQ(1, subGroups.size());

	const auto square = subGroups.at(0);
	subGroups = square->GetSubGroups();
	EXPECT_EQ(ir::CaptureType::square, square->GetCaptureType());
	EXPECT_EQ(2, subGroups.size());
	EXPECT_EQ("[a-zA-Z]", square->GetFormattedRegex());

	const auto character = subGroups.at(0);
	EXPECT_EQ(ir::CaptureType::capturerange, character->GetCaptureType());
	EXPECT_EQ("a-z", character->GetFormattedRegex());

	const auto character2 = subGroups.at(1);
	EXPECT_EQ(ir::CaptureType::capturerange, character2->GetCaptureType());
	EXPECT_EQ("A-Z", character2->GetFormattedRegex());
}

TEST_F(TestTranslateToIr, RegexWithSquareWith3RangeCapture_ShouldConvertToSimpleSquareIr)
{
	auto tree = Parse("[a-zA-Z0-9]");
	translator.Dispatch(tree.value());

	const auto ir = translator.GetOutput();
	ASSERT_NE(nullptr, ir);

	auto subGroups = ir->GetSubGroups();
	EXPECT_EQ(1, subGroups.size());

	const auto square = subGroups.at(0);
	subGroups = square->GetSubGroups();
	EXPECT_EQ(ir::CaptureType::square, square->GetCaptureType());
	EXPECT_EQ(3, subGroups.size());
	EXPECT_EQ("[a-zA-Z0-9]", square->GetFormattedRegex());

	const auto character = subGroups.at(0);
	EXPECT_EQ(ir::CaptureType::capturerange, character->GetCaptureType());
	EXPECT_EQ("a-z", character->GetFormattedRegex());

	const auto character2 = subGroups.at(1);
	EXPECT_EQ(ir::CaptureType::capturerange, character2->GetCaptureType());
	EXPECT_EQ("A-Z", character2->GetFormattedRegex());

	const auto character3 = subGroups.at(2);
	EXPECT_EQ(ir::CaptureType::capturerange, character3->GetCaptureType());
	EXPECT_EQ("0-9", character3->GetFormattedRegex());
}

TEST_F(TestTranslateToIr, RegexWith2Squares_ShouldConvertToSimpleSquareIr)
{
	auto tree = Parse("[abcde][fghi]");
	translator.Dispatch(tree.value());

	const auto ir = translator.GetOutput();
	ASSERT_NE(nullptr, ir);

	const auto subGroups = ir->GetSubGroups();
	EXPECT_EQ(2, subGroups.size());

	const auto square1 = subGroups.at(0);
	EXPECT_EQ(ir::CaptureType::square, square1->GetCaptureType());
	EXPECT_EQ("[abcde]", square1->GetFormattedRegex());

	const auto square2 = subGroups.at(1);
	EXPECT_EQ(ir::CaptureType::square, square2->GetCaptureType());
	EXPECT_EQ("[fghi]", square2->GetFormattedRegex());
}

TEST_F(TestTranslateToIr, RegexWith3Squares_ShouldConvertToSimpleSquareIr)
{
	auto tree = Parse("[abcde][fghi][qqqqq]");
	translator.Dispatch(tree.value());

	const auto ir = translator.GetOutput();
	ASSERT_NE(nullptr, ir);

	const auto subGroups = ir->GetSubGroups();
	EXPECT_EQ(3, subGroups.size());

	const auto square1 = subGroups.at(0);
	EXPECT_EQ(ir::CaptureType::square, square1->GetCaptureType());
	EXPECT_EQ("[abcde]", square1->GetFormattedRegex());

	const auto square2 = subGroups.at(1);
	EXPECT_EQ(ir::CaptureType::square, square2->GetCaptureType());
	EXPECT_EQ("[fghi]", square2->GetFormattedRegex());

	const auto square3 = subGroups.at(2);
	EXPECT_EQ(ir::CaptureType::square, square3->GetCaptureType());
	EXPECT_EQ("[qqqqq]", square3->GetFormattedRegex());
}

TEST_F(TestTranslateToIr, RegexWith3SquaresVariousExtensionModifiers_ShouldConvertToSimpleSquareIr)
{
	auto tree = Parse("[abcde]*[fghi]+[qqqqq]{123,789}");
	translator.Dispatch(tree.value());

	const auto ir = translator.GetOutput();
	ASSERT_NE(nullptr, ir);

	const auto subGroups = ir->GetSubGroups();
	EXPECT_EQ(3, subGroups.size());

	const auto square1 = subGroups.at(0);
	EXPECT_EQ(ir::CaptureType::square, square1->GetCaptureType());
	EXPECT_EQ("[abcde]*", square1->GetFormattedRegex());

	const auto square2 = subGroups.at(1);
	EXPECT_EQ(ir::CaptureType::square, square2->GetCaptureType());
	EXPECT_EQ("[fghi]+", square2->GetFormattedRegex());

	const auto square3 = subGroups.at(2);
	EXPECT_EQ(ir::CaptureType::square, square3->GetCaptureType());
	EXPECT_EQ("[qqqqq]{123,789}", square3->GetFormattedRegex());
}

TEST_F(TestTranslateToIr, RegexWith1GroupEmbedding2Squares_ShouldConvertToSimpleSquareIr)
{
	auto tree = Parse("([abc][cvd])");
	translator.Dispatch(tree.value());

	const auto ir = translator.GetOutput();
	ASSERT_NE(nullptr, ir);

	auto subGroups = ir->GetSubGroups();
	EXPECT_EQ(1, subGroups.size());

	const auto group = subGroups.at(0);
	EXPECT_EQ(ir::CaptureType::group, group->GetCaptureType());
	EXPECT_EQ("([abc][cvd])", group->GetFormattedRegex());
	subGroups = group->GetSubGroups();

	const auto square1 = subGroups.at(0);
	EXPECT_EQ(ir::CaptureType::square, square1->GetCaptureType());
	EXPECT_EQ("[abc]", square1->GetFormattedRegex());

	const auto square2 = subGroups.at(1);
	EXPECT_EQ(ir::CaptureType::square, square2->GetCaptureType());
	EXPECT_EQ("[cvd]", square2->GetFormattedRegex());
}

TEST_F(TestTranslateToIr, RegexWith1GroupEmbeddingOr2Squares_ShouldConvertToSimpleSquareIr)
{
	auto tree = Parse("([abc]|[cvd])");
	translator.Dispatch(tree.value());

	const auto ir = translator.GetOutput();
	ASSERT_NE(nullptr, ir);

	auto subGroups = ir->GetSubGroups();
	EXPECT_EQ(1, subGroups.size());

	const auto group = subGroups.at(0);
	EXPECT_EQ(ir::CaptureType::group, group->GetCaptureType());
	EXPECT_EQ("([abc]|[cvd])", group->GetFormattedRegex());
	subGroups = group->GetSubGroups();

	const auto orGroup = subGroups.at(0);
	EXPECT_EQ(ir::CaptureType::orgroup, orGroup->GetCaptureType());
	EXPECT_EQ("[abc]|[cvd]", orGroup->GetFormattedRegex());
	EXPECT_EQ(1, subGroups.size());

	subGroups = orGroup->GetSubGroups();
	EXPECT_EQ(2, subGroups.size());

	const auto square1 = subGroups.at(0);
	EXPECT_EQ(ir::CaptureType::square, square1->GetCaptureType());
	EXPECT_EQ("[abc]", square1->GetFormattedRegex());

	const auto square2 = subGroups.at(1);
	EXPECT_EQ(ir::CaptureType::square, square2->GetCaptureType());
	EXPECT_EQ("[cvd]", square2->GetFormattedRegex());
}

TEST_F(TestTranslateToIr, RegexWith1GroupEmbeddingOr3Squares_ShouldConvertToSimpleSquareIr)
{
	auto tree = Parse("([abc]|[cvd]|[\teax])");
	translator.Dispatch(tree.value());

	const auto ir = translator.GetOutput();
	ASSERT_NE(nullptr, ir);

	auto subGroups = ir->GetSubGroups();
	EXPECT_EQ(1, subGroups.size());

	const auto group = subGroups.at(0);
	EXPECT_EQ(ir::CaptureType::group, group->GetCaptureType());
	EXPECT_EQ("([abc]|[cvd]|[\teax])", group->GetFormattedRegex());
	subGroups = group->GetSubGroups();

	const auto orGroup = subGroups.at(0);
	EXPECT_EQ(ir::CaptureType::orgroup, orGroup->GetCaptureType());
	EXPECT_EQ("[abc]|[cvd]|[\teax]", orGroup->GetFormattedRegex());
	EXPECT_EQ(1, subGroups.size());

	subGroups = orGroup->GetSubGroups();
	EXPECT_EQ(3, subGroups.size());

	const auto square1 = subGroups.at(0);
	EXPECT_EQ(ir::CaptureType::square, square1->GetCaptureType());
	EXPECT_EQ("[abc]", square1->GetFormattedRegex());

	const auto square2 = subGroups.at(1);
	EXPECT_EQ(ir::CaptureType::square, square2->GetCaptureType());
	EXPECT_EQ("[cvd]", square2->GetFormattedRegex());

	const auto square3 = subGroups.at(2);
	EXPECT_EQ(ir::CaptureType::square, square3->GetCaptureType());
	EXPECT_EQ("[\teax]", square3->GetFormattedRegex());
}
