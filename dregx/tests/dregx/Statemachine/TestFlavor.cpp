#include "Deamer/External/Cpp/Ast/Tree.h"
#include "dregx/Ast/Listener/User/TranslateToIr.h"
#include "dregx/Bison/Parser.h"
#include "dregx/Statemachine/ConvertRegexToDFA.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <memory>
#include <optional>

using namespace dregx;

class TestFlavor : public testing::Test
{
public:
protected:
	TestFlavor() = default;

	virtual ~TestFlavor() = default;

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

TEST_F(TestFlavor, AddFlavor_AcceptStatesShouldBeSplit)
{
	auto flavor1 = std::set<std::string>{"abc"};
	auto flavor2 = std::set<std::string>{"123"};
	const auto capture1 = GetCapture("(a)");
	capture1->AddFlavor(*flavor1.begin());
	auto statemachine1 = statemachine::ConvertRegexToDFA::ConvertToStatemachine(capture1.get());
	const auto capture2 = GetCapture("(b)");
	capture2->AddFlavor(*flavor2.begin());
	const auto statemachine2 =
		statemachine::ConvertRegexToDFA::ConvertToStatemachine(capture2.get());
	statemachine1->Or(*statemachine2);
	statemachine1->Minimize();

	const auto acceptStates = statemachine1->GetAcceptStates();

	EXPECT_EQ(2, acceptStates.size());
	EXPECT_TRUE(flavor1 == acceptStates.at(0)->GetFlavors() ||
				flavor1 == acceptStates.at(1)->GetFlavors());
	EXPECT_TRUE(flavor2 == acceptStates.at(0)->GetFlavors() ||
				flavor2 == acceptStates.at(1)->GetFlavors());
}

TEST_F(TestFlavor, AddFlavor_MinimizeTwice_AcceptStatesShouldBeSplit)
{
	auto flavor1 = std::set<std::string>{"abc"};
	auto flavor2 = std::set<std::string>{"123"};
	const auto capture1 = GetCapture("(a)");
	capture1->AddFlavor(*flavor1.begin());
	auto statemachine1 = statemachine::ConvertRegexToDFA::ConvertToStatemachine(capture1.get());
	const auto capture2 = GetCapture("(b)");
	capture2->AddFlavor(*flavor2.begin());
	const auto statemachine2 =
		statemachine::ConvertRegexToDFA::ConvertToStatemachine(capture2.get());
	statemachine1->Or(*statemachine2);
	statemachine1->Minimize();
	statemachine1->Minimize();

	const auto acceptStates = statemachine1->GetAcceptStates();

	EXPECT_EQ(2, acceptStates.size());
	EXPECT_TRUE(flavor1 == acceptStates.at(0)->GetFlavors() ||
				flavor1 == acceptStates.at(1)->GetFlavors());
	EXPECT_TRUE(flavor2 == acceptStates.at(0)->GetFlavors() ||
				flavor2 == acceptStates.at(1)->GetFlavors());
}

TEST_F(TestFlavor, AddFlavor_OrSequenceOf3_AcceptStatesShouldBeSplit)
{
	auto flavor1 = std::set<std::string>{"abc"};
	auto flavor2 = std::set<std::string>{"123"};
	auto flavor3 = std::set<std::string>{"qwerty"};
	const auto capture1 = GetCapture("(a)");
	capture1->AddFlavor(*flavor1.begin());
	auto statemachine1 = statemachine::ConvertRegexToDFA::ConvertToStatemachine(capture1.get());
	const auto capture2 = GetCapture("(b)");
	capture2->AddFlavor(*flavor2.begin());
	const auto statemachine2 =
		statemachine::ConvertRegexToDFA::ConvertToStatemachine(capture2.get());
	const auto capture3 = GetCapture("(c)");
	capture3->AddFlavor(*flavor3.begin());
	const auto statemachine3 =
		statemachine::ConvertRegexToDFA::ConvertToStatemachine(capture3.get());
	statemachine1->Or(*statemachine2);
	statemachine1->Or(*statemachine3);
	statemachine1->Minimize();

	const auto acceptStates = statemachine1->GetAcceptStates();

	EXPECT_EQ(3, acceptStates.size());
	EXPECT_TRUE(flavor1 == acceptStates.at(0)->GetFlavors() ||
				flavor1 == acceptStates.at(1)->GetFlavors() ||
				flavor1 == acceptStates.at(2)->GetFlavors());
	EXPECT_TRUE(flavor2 == acceptStates.at(0)->GetFlavors() ||
				flavor2 == acceptStates.at(1)->GetFlavors() ||
				flavor2 == acceptStates.at(2)->GetFlavors());
	EXPECT_TRUE(flavor3 == acceptStates.at(0)->GetFlavors() ||
				flavor3 == acceptStates.at(1)->GetFlavors() ||
				flavor3 == acceptStates.at(2)->GetFlavors());
}
