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
	const auto capture1 = GetCapture("(a)");
	capture1->AddFlavor("abc");
	auto statemachine1 = statemachine::ConvertRegexToDFA::ConvertToStatemachine(capture1.get());
	const auto capture2 = GetCapture("(b)");
	capture2->AddFlavor("123");
	const auto statemachine2 =
		statemachine::ConvertRegexToDFA::ConvertToStatemachine(capture2.get());
	statemachine1->Or(*statemachine2);
	statemachine1->Minimize();

	const auto acceptStates = statemachine1->GetAcceptStates();

	EXPECT_EQ(2, acceptStates.size());
}
