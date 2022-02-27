#include "Deamer/External/Cpp/Ast/Tree.h"
#include "dregx/Ast/Listener/User/TranslateToIr.h"
#include "dregx/Bison/Parser.h"
#include "dregx/Statemachine/ConvertRegexToDFA.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <memory>
#include <optional>

using namespace dregx;

class TestConvertRegexToDFA : public testing::Test
{
public:
protected:
	TestConvertRegexToDFA() = default;

	virtual ~TestConvertRegexToDFA() = default;

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

TEST_F(TestConvertRegexToDFA, ConvertSquareWith1CharacterToDfa_DfaIsCorrectAndMinimal)
{
	const auto capture = GetCapture("[a]");
	auto statemachine = statemachine::ConvertRegexToDFA::ConvertToStatemachine(capture.get());

	const auto& states = statemachine->GetStates();
	const auto& transitions = statemachine->GetTransitions();

	EXPECT_EQ(2, states.size());
	EXPECT_EQ(1, transitions.size());

	auto startState = statemachine->GetStates({}, {{statemachine::Conditional("a")}}).at(0);
	auto acceptState = statemachine->GetStates({{statemachine::Conditional("a")}}, {}).at(0);

	EXPECT_TRUE(startState->IsStartState());
	EXPECT_FALSE(startState->IsAcceptState());

	EXPECT_EQ(1, startState->GetOutTransitions().size());
	EXPECT_EQ(transitions.at(0).get(), startState->GetOutTransitions().at(0));
	EXPECT_EQ(0, startState->GetInTransitions().size());

	EXPECT_FALSE(acceptState->IsStartState());
	EXPECT_TRUE(acceptState->IsAcceptState());

	EXPECT_EQ(1, acceptState->GetInTransitions().size());
	EXPECT_EQ(transitions.at(0).get(), acceptState->GetInTransitions().at(0));
	EXPECT_EQ(0, acceptState->GetOutTransitions().size());

	EXPECT_EQ(startState, transitions.at(0)->GetInState());
	EXPECT_EQ(acceptState, transitions.at(0)->GetOutState());
}

TEST_F(TestConvertRegexToDFA, ConvertSquareWith2CharactersToDfa_DfaIsCorrectAndMinimal)
{
	const auto capture = GetCapture("[ab]");
	auto statemachine = statemachine::ConvertRegexToDFA::ConvertToStatemachine(capture.get());

	const auto& states = statemachine->GetStates();
	const auto& transitions = statemachine->GetTransitions();

	EXPECT_EQ(2, states.size());
	EXPECT_EQ(2, transitions.size());

	auto startState = statemachine->GetStates({}, {{statemachine::Conditional("a")}}).at(0);
	auto acceptState = statemachine->GetStates({{statemachine::Conditional("a")}}, {}).at(0);

	EXPECT_TRUE(startState->IsStartState());
	EXPECT_FALSE(startState->IsAcceptState());

	EXPECT_EQ(2, startState->GetOutTransitions().size());
	EXPECT_EQ(transitions.at(0).get(), startState->GetOutTransitions().at(0));
	EXPECT_EQ(0, startState->GetInTransitions().size());

	EXPECT_FALSE(acceptState->IsStartState());
	EXPECT_TRUE(acceptState->IsAcceptState());

	EXPECT_EQ(2, acceptState->GetInTransitions().size());
	EXPECT_EQ(transitions.at(0).get(), acceptState->GetInTransitions().at(0));
	EXPECT_EQ(0, acceptState->GetOutTransitions().size());

	EXPECT_EQ(startState, transitions.at(0)->GetInState());
	EXPECT_EQ(acceptState, transitions.at(0)->GetOutState());
}

TEST_F(TestConvertRegexToDFA, ConvertSquareWith3CharactersToDfa_DfaIsCorrectAndMinimal)
{
	const auto capture = GetCapture("[abc]");
	auto statemachine = statemachine::ConvertRegexToDFA::ConvertToStatemachine(capture.get());

	const auto& states = statemachine->GetStates();
	const auto& transitions = statemachine->GetTransitions();

	EXPECT_EQ(2, states.size());
	EXPECT_EQ(3, transitions.size());

	auto startState = statemachine->GetStates({}, {{statemachine::Conditional("a")}}).at(0);
	auto acceptState = statemachine->GetStates({{statemachine::Conditional("a")}}, {}).at(0);

	EXPECT_TRUE(startState->IsStartState());
	EXPECT_FALSE(startState->IsAcceptState());

	EXPECT_EQ(3, startState->GetOutTransitions().size());
	EXPECT_EQ(transitions.at(0).get(), startState->GetOutTransitions().at(0));
	EXPECT_EQ(0, startState->GetInTransitions().size());

	EXPECT_FALSE(acceptState->IsStartState());
	EXPECT_TRUE(acceptState->IsAcceptState());

	EXPECT_EQ(3, acceptState->GetInTransitions().size());
	EXPECT_EQ(transitions.at(0).get(), acceptState->GetInTransitions().at(0));
	EXPECT_EQ(0, acceptState->GetOutTransitions().size());

	EXPECT_EQ(startState, transitions.at(0)->GetInState());
	EXPECT_EQ(acceptState, transitions.at(0)->GetOutState());
}

TEST_F(TestConvertRegexToDFA, ConvertSquareWith3TheSameCharactersToDfa_DfaIsCorrectAndMinimal)
{
	const auto capture = GetCapture("[aaa]");
	auto statemachine = statemachine::ConvertRegexToDFA::ConvertToStatemachine(capture.get());

	const auto& states = statemachine->GetStates();
	const auto& transitions = statemachine->GetTransitions();

	EXPECT_EQ(2, states.size());
	EXPECT_EQ(1, transitions.size());

	auto startState = statemachine->GetStates({}, {{statemachine::Conditional("a")}}).at(0);
	auto acceptState = statemachine->GetStates({{statemachine::Conditional("a")}}, {}).at(0);

	EXPECT_TRUE(startState->IsStartState());
	EXPECT_FALSE(startState->IsAcceptState());

	EXPECT_EQ(1, startState->GetOutTransitions().size());
	EXPECT_EQ(transitions.at(0).get(), startState->GetOutTransitions().at(0));
	EXPECT_EQ(0, startState->GetInTransitions().size());

	EXPECT_FALSE(acceptState->IsStartState());
	EXPECT_TRUE(acceptState->IsAcceptState());

	EXPECT_EQ(1, acceptState->GetInTransitions().size());
	EXPECT_EQ(transitions.at(0).get(), acceptState->GetInTransitions().at(0));
	EXPECT_EQ(0, acceptState->GetOutTransitions().size());

	EXPECT_EQ(startState, transitions.at(0)->GetInState());
	EXPECT_EQ(acceptState, transitions.at(0)->GetOutState());
}

TEST_F(TestConvertRegexToDFA, ConvertWordWith1CharacterToDfa_DfaIsCorrectAndMinimal)
{
	const auto capture = GetCapture("a");
	auto statemachine = statemachine::ConvertRegexToDFA::ConvertToStatemachine(capture.get());

	const auto& states = statemachine->GetStates();
	const auto& transitions = statemachine->GetTransitions();

	EXPECT_EQ(2, states.size());
	EXPECT_EQ(1, transitions.size());

	auto startState = statemachine->GetStates({}, {{statemachine::Conditional("a")}}).at(0);
	auto acceptState = statemachine->GetStates({{statemachine::Conditional("a")}}, {}).at(0);

	EXPECT_TRUE(startState->IsStartState());
	EXPECT_FALSE(startState->IsAcceptState());

	EXPECT_EQ(1, startState->GetOutTransitions().size());
	EXPECT_EQ(transitions.at(0).get(), startState->GetOutTransitions().at(0));
	EXPECT_EQ(0, startState->GetInTransitions().size());

	EXPECT_FALSE(acceptState->IsStartState());
	EXPECT_TRUE(acceptState->IsAcceptState());

	EXPECT_EQ(1, acceptState->GetInTransitions().size());
	EXPECT_EQ(transitions.at(0).get(), acceptState->GetInTransitions().at(0));
	EXPECT_EQ(0, acceptState->GetOutTransitions().size());

	EXPECT_EQ(startState, transitions.at(0)->GetInState());
	EXPECT_EQ(acceptState, transitions.at(0)->GetOutState());
}

TEST_F(TestConvertRegexToDFA, ConvertWordWith2CharactersToDfa_DfaIsCorrectAndMinimal)
{
	const auto capture = GetCapture("ab");
	auto statemachine = statemachine::ConvertRegexToDFA::ConvertToStatemachine(capture.get());

	const auto& states = statemachine->GetStates();
	const auto& transitions = statemachine->GetTransitions();

	EXPECT_EQ(3, states.size());
	EXPECT_EQ(2, transitions.size());

	auto startState = statemachine->GetStates({}, {{statemachine::Conditional("a")}}).at(0);
	auto intermediateState =
		statemachine
			->GetStates({{statemachine::Conditional("a")}}, {{statemachine::Conditional("b")}})
			.at(0);
	auto acceptState = statemachine->GetStates({{statemachine::Conditional("b")}}, {}).at(0);

	EXPECT_TRUE(startState->IsStartState());
	EXPECT_FALSE(startState->IsAcceptState());

	EXPECT_EQ(1, startState->GetOutTransitions().size());
	EXPECT_EQ(transitions.at(0).get(), startState->GetOutTransitions().at(0));
	EXPECT_EQ(0, startState->GetInTransitions().size());

	EXPECT_FALSE(intermediateState->IsStartState());
	EXPECT_FALSE(intermediateState->IsAcceptState());

	EXPECT_EQ(1, intermediateState->GetInTransitions().size());
	EXPECT_EQ(transitions.at(0).get(), intermediateState->GetInTransitions().at(0));
	EXPECT_EQ(transitions.at(1).get(), intermediateState->GetOutTransitions().at(0));
	EXPECT_EQ(1, intermediateState->GetOutTransitions().size());

	EXPECT_FALSE(acceptState->IsStartState());
	EXPECT_TRUE(acceptState->IsAcceptState());

	EXPECT_EQ(1, acceptState->GetInTransitions().size());
	EXPECT_EQ(transitions.at(1).get(), acceptState->GetInTransitions().at(0));
	EXPECT_EQ(0, acceptState->GetOutTransitions().size());

	EXPECT_EQ(startState, transitions.at(0)->GetInState());
	EXPECT_EQ(intermediateState, transitions.at(0)->GetOutState());
	EXPECT_EQ(intermediateState, transitions.at(1)->GetInState());
	EXPECT_EQ(acceptState, transitions.at(1)->GetOutState());
}

TEST_F(TestConvertRegexToDFA, ConvertWordWith3CharactersToDfa_DfaIsCorrectAndMinimal)
{
	const auto capture = GetCapture("abc");
	auto statemachine = statemachine::ConvertRegexToDFA::ConvertToStatemachine(capture.get());

	const auto& states = statemachine->GetStates();
	const auto& transitions = statemachine->GetTransitions();

	EXPECT_EQ(4, states.size());
	EXPECT_EQ(3, transitions.size());

	auto startState = statemachine->GetStates({}, {{statemachine::Conditional("a")}}).at(0);
	auto intermediateState1 =
		statemachine
			->GetStates({{statemachine::Conditional("a")}}, {{statemachine::Conditional("b")}})
			.at(0);
	auto intermediateState2 =
		statemachine
			->GetStates({{statemachine::Conditional("b")}}, {{statemachine::Conditional("c")}})
			.at(0);
	auto acceptState = statemachine->GetStates({{statemachine::Conditional("c")}}, {}).at(0);

	EXPECT_TRUE(startState->IsStartState());
	EXPECT_FALSE(startState->IsAcceptState());

	EXPECT_EQ(1, startState->GetOutTransitions().size());
	EXPECT_EQ(transitions.at(0).get(), startState->GetOutTransitions().at(0));
	EXPECT_EQ(0, startState->GetInTransitions().size());

	EXPECT_FALSE(intermediateState1->IsStartState());
	EXPECT_FALSE(intermediateState1->IsAcceptState());

	EXPECT_EQ(1, intermediateState1->GetInTransitions().size());
	EXPECT_EQ(transitions.at(0).get(), intermediateState1->GetInTransitions().at(0));
	EXPECT_EQ(transitions.at(1).get(), intermediateState1->GetOutTransitions().at(0));
	EXPECT_EQ(1, intermediateState1->GetOutTransitions().size());

	EXPECT_EQ(1, intermediateState2->GetInTransitions().size());
	EXPECT_EQ(transitions.at(1).get(), intermediateState2->GetInTransitions().at(0));
	EXPECT_EQ(transitions.at(2).get(), intermediateState2->GetOutTransitions().at(0));
	EXPECT_EQ(1, intermediateState2->GetOutTransitions().size());

	EXPECT_FALSE(acceptState->IsStartState());
	EXPECT_TRUE(acceptState->IsAcceptState());

	EXPECT_EQ(1, acceptState->GetInTransitions().size());
	EXPECT_EQ(transitions.at(2).get(), acceptState->GetInTransitions().at(0));
	EXPECT_EQ(0, acceptState->GetOutTransitions().size());

	EXPECT_EQ(startState, transitions.at(0)->GetInState());
	EXPECT_EQ(intermediateState1, transitions.at(0)->GetOutState());
	EXPECT_EQ(intermediateState1, transitions.at(1)->GetInState());
	EXPECT_EQ(intermediateState2, transitions.at(1)->GetOutState());
	EXPECT_EQ(intermediateState2, transitions.at(2)->GetInState());
	EXPECT_EQ(acceptState, transitions.at(2)->GetOutState());
}

TEST_F(TestConvertRegexToDFA,
	   ConvertSquareWith3CharactersConcatenatedWordWith1CharacterToDfa_DfaIsCorrectAndMinimal)
{
	const auto capture = GetCapture("[abc]d");
	auto statemachine = statemachine::ConvertRegexToDFA::ConvertToStatemachine(capture.get());

	const auto& states = statemachine->GetStates();
	const auto& transitions = statemachine->GetTransitions();

	EXPECT_EQ(3, states.size());
	EXPECT_EQ(4, transitions.size());
}

TEST_F(TestConvertRegexToDFA,
	   ConvertSquareWith3CharactersConcatenatedWordWith2CharactersToDfa_DfaIsCorrectAndMinimal)
{
	const auto capture = GetCapture("[abc](de)");
	auto statemachine = statemachine::ConvertRegexToDFA::ConvertToStatemachine(capture.get());
	statemachine->Minimize();

	const auto& states = statemachine->GetStates();
	const auto& transitions = statemachine->GetTransitions();

	EXPECT_EQ(5, states.size());
	EXPECT_EQ(25, transitions.size());
}

TEST_F(TestConvertRegexToDFA, Convert2GroupOrWith1ConcatenationsToDfa_DfaIsCorrectAndMinimal)
{
	const auto capture = GetCapture("([a]|[c])");
	auto statemachine = statemachine::ConvertRegexToDFA::ConvertToStatemachine(capture.get());
	statemachine->Minimize();

	const auto& states = statemachine->GetStates();
	const auto& transitions = statemachine->GetTransitions();

	EXPECT_EQ(3, states.size());
	EXPECT_EQ(6, transitions.size());
}

TEST_F(TestConvertRegexToDFA, Convert2GroupOrWith2ConcatenationsToDfa_DfaIsCorrectAndMinimal)
{
	const auto capture = GetCapture("(([a][b])|([c][d]))");
	auto statemachine = statemachine::ConvertRegexToDFA::ConvertToStatemachine(capture.get());
	statemachine->Minimize();

	const auto& states = statemachine->GetStates();
	const auto& transitions = statemachine->GetTransitions();

	EXPECT_EQ(5, states.size());
	EXPECT_EQ(20, transitions.size());

	const auto startState = statemachine->GetStartState();
	const auto state_a_b =
		statemachine
			->GetStates({{statemachine::Conditional("a")}}, {{statemachine::Conditional("b")}})
			.at(0);
	const auto state_c_d =
		statemachine
			->GetStates({{statemachine::Conditional("c")}}, {{statemachine::Conditional("d")}})
			.at(0);
	const auto state_accept = statemachine->GetAcceptStates().at(0);

	EXPECT_TRUE(startState->IsStartState());
	EXPECT_FALSE(state_a_b->IsStartState());
	EXPECT_FALSE(state_c_d->IsStartState());
	EXPECT_FALSE(state_accept->IsStartState());

	EXPECT_FALSE(startState->IsAcceptState());
	EXPECT_FALSE(state_a_b->IsAcceptState());
	EXPECT_FALSE(state_c_d->IsAcceptState());
	EXPECT_TRUE(state_accept->IsAcceptState());
}

TEST_F(TestConvertRegexToDFA, Convert2GroupOrWith2SquaresBeingSubsetsToDfa_DfaIsCorrectAndMinimal)
{
	const auto capture = GetCapture("(([a])|([a][b])|([a][b][c]))");
	auto statemachine = statemachine::ConvertRegexToDFA::ConvertToStatemachine(capture.get());
	statemachine->Minimize();

	const auto& states = statemachine->GetStates();
	const auto& transitions = statemachine->GetTransitions();

	EXPECT_EQ(5, states.size());
	EXPECT_EQ(15, transitions.size());

	const auto startState = statemachine->GetStartState();

	EXPECT_TRUE(startState->IsStartState());

	EXPECT_FALSE(startState->IsAcceptState());
}

TEST_F(TestConvertRegexToDFA, Convert2GroupOrWith1SquareBeingSubsetToDfa_DfaIsCorrectAndMinimal)
{
	const auto capture = GetCapture("(([a])|([a][b]))");
	auto statemachine = statemachine::ConvertRegexToDFA::ConvertToStatemachine(capture.get());

	const auto& states = statemachine->GetStates();
	const auto& transitions = statemachine->GetTransitions();

	EXPECT_EQ(3, states.size());
	EXPECT_EQ(2, transitions.size());

	const auto startState = statemachine->GetStartState();
	const auto state_a_b =
		statemachine
			->GetStates({{statemachine::Conditional("a")}}, {{statemachine::Conditional("b")}})
			.at(0);
	const auto state_accept = statemachine->GetAcceptStates().at(0);

	EXPECT_TRUE(startState->IsStartState());
	EXPECT_FALSE(state_a_b->IsStartState());
	EXPECT_FALSE(state_accept->IsStartState());

	EXPECT_FALSE(startState->IsAcceptState());
	EXPECT_TRUE(state_a_b->IsAcceptState());
	EXPECT_TRUE(state_accept->IsAcceptState());
}

TEST_F(TestConvertRegexToDFA, Convert3GroupOrWith3ConcatenationsToDfa_DfaIsCorrectAndMinimal)
{
	const auto capture = GetCapture("(([a][b])|([c][d])|([a][b][d]))");
	auto statemachine = statemachine::ConvertRegexToDFA::ConvertToStatemachine(capture.get());
	statemachine->Minimize();

	const auto& states = statemachine->GetStates();
	const auto& transitions = statemachine->GetTransitions();

	EXPECT_EQ(6, states.size());
	EXPECT_EQ(24, transitions.size());

	const auto startState = statemachine->GetStartState();

	EXPECT_TRUE(startState->IsStartState());

	EXPECT_FALSE(startState->IsAcceptState());
}

TEST_F(TestConvertRegexToDFA,
	   Convert3GroupOrWith3ConcatenationsToDfa_Inverted_DfaIsCorrectAndMinimal)
{
	const auto capture = GetCapture("(([a][b][d])|([c][d])|([a][b]))");
	auto statemachine = statemachine::ConvertRegexToDFA::ConvertToStatemachine(capture.get());
	statemachine->Minimize();

	const auto& states = statemachine->GetStates();
	const auto& transitions = statemachine->GetTransitions();

	EXPECT_EQ(6, states.size());
	EXPECT_EQ(24, transitions.size());

	const auto startState = statemachine->GetStartState();
	const auto state_accept = statemachine->GetAcceptStates().at(0);

	EXPECT_TRUE(startState->IsStartState());
	EXPECT_FALSE(state_accept->IsStartState());

	EXPECT_FALSE(startState->IsAcceptState());
	EXPECT_TRUE(state_accept->IsAcceptState());
}

TEST_F(TestConvertRegexToDFA, Convert3SquaresWith1CharacterToDfa_DfaIsCorrectAndMinimal)
{
	const auto capture = GetCapture("[a][b][d]");
	auto statemachine = statemachine::ConvertRegexToDFA::ConvertToStatemachine(capture.get());

	const auto& states = statemachine->GetStates();
	const auto& transitions = statemachine->GetTransitions();

	EXPECT_EQ(4, states.size());
	EXPECT_EQ(3, transitions.size());

	const auto startState = statemachine->GetStartState();
	const auto state_a_b =
		statemachine
			->GetStates({{statemachine::Conditional("a")}}, {{statemachine::Conditional("b")}})
			.at(0);
	const auto state_b_d =
		statemachine
			->GetStates({{statemachine::Conditional("b")}}, {{statemachine::Conditional("d")}})
			.at(0);
	const auto state_accept = statemachine->GetAcceptStates().at(0);

	EXPECT_TRUE(startState->IsStartState());
	EXPECT_FALSE(state_a_b->IsStartState());
	EXPECT_FALSE(state_b_d->IsStartState());
	EXPECT_FALSE(state_accept->IsStartState());

	EXPECT_FALSE(startState->IsAcceptState());
	EXPECT_FALSE(state_a_b->IsAcceptState());
	EXPECT_FALSE(state_b_d->IsAcceptState());
	EXPECT_TRUE(state_accept->IsAcceptState());
}

TEST_F(TestConvertRegexToDFA, Convert3SquaresWith1CharacterOR2SquaresToDfa_DfaIsCorrectAndMinimal)
{
	const auto capture = GetCapture("(([a][b][d])|([c][d]))");
	auto statemachine = statemachine::ConvertRegexToDFA::ConvertToStatemachine(capture.get());

	const auto& states = statemachine->GetStates();
	const auto& transitions = statemachine->GetTransitions();

	EXPECT_EQ(6, states.size());
	EXPECT_EQ(5, transitions.size());

	const auto startState = statemachine->GetStartState();
	const auto state_a_b =
		statemachine
			->GetStates({{statemachine::Conditional("a")}}, {{statemachine::Conditional("b")}})
			.at(0);
	const auto state_b_d =
		statemachine
			->GetStates({{statemachine::Conditional("b")}}, {{statemachine::Conditional("d")}})
			.at(0);
	const auto state_accept = statemachine->GetAcceptStates().at(0);

	EXPECT_TRUE(startState->IsStartState());
	EXPECT_FALSE(state_a_b->IsStartState());
	EXPECT_FALSE(state_b_d->IsStartState());
	EXPECT_FALSE(state_accept->IsStartState());

	EXPECT_FALSE(startState->IsAcceptState());
	EXPECT_FALSE(state_a_b->IsAcceptState());
	EXPECT_FALSE(state_b_d->IsAcceptState());
	EXPECT_TRUE(state_accept->IsAcceptState());
}

TEST_F(TestConvertRegexToDFA,
	   Convert2EqualSquaresWith2ConcatenationsORredToDfa_DfaIsCorrectAndMinimal)
{
	const auto capture = GetCapture("(([a][b])|([a][b]))");
	auto statemachine = statemachine::ConvertRegexToDFA::ConvertToStatemachine(capture.get());

	const auto& states = statemachine->GetStates();
	const auto& transitions = statemachine->GetTransitions();

	EXPECT_EQ(3, states.size());
	EXPECT_EQ(2, transitions.size());

	const auto startState = statemachine->GetStartState();
	const auto state_a_b =
		statemachine
			->GetStates({{statemachine::Conditional("a")}}, {{statemachine::Conditional("b")}})
			.at(0);
	const auto state_accept = statemachine->GetAcceptStates().at(0);

	EXPECT_TRUE(startState->IsStartState());
	EXPECT_FALSE(state_a_b->IsStartState());
	EXPECT_FALSE(state_accept->IsStartState());

	EXPECT_FALSE(startState->IsAcceptState());
	EXPECT_FALSE(state_a_b->IsAcceptState());
	EXPECT_TRUE(state_accept->IsAcceptState());
}

TEST_F(TestConvertRegexToDFA, ConvertToDfaCycle_SquareMin1Max2_DfaIsCorrectAndMinimal)
{
	const auto capture = GetCapture("[a]{1,2}");
	auto statemachine = statemachine::ConvertRegexToDFA::ConvertToStatemachine(capture.get());

	const auto& states = statemachine->GetStates();
	const auto& transitions = statemachine->GetTransitions();

	EXPECT_EQ(3, states.size());
	EXPECT_EQ(2, transitions.size());
	EXPECT_EQ(2, statemachine->GetAcceptStates().size());
}

TEST_F(TestConvertRegexToDFA, ConvertToDfaCycle_SquareMin2Max2_DfaIsCorrectAndMinimal)
{
	const auto capture = GetCapture("[a]{2,2}");
	auto statemachine = statemachine::ConvertRegexToDFA::ConvertToStatemachine(capture.get());

	const auto& states = statemachine->GetStates();
	const auto& transitions = statemachine->GetTransitions();

	EXPECT_EQ(3, states.size());
	EXPECT_EQ(2, transitions.size());
	EXPECT_EQ(1, statemachine->GetAcceptStates().size());
}

TEST_F(TestConvertRegexToDFA, ConvertToDfaCycle_SquareMin0Max1_DfaIsCorrectAndMinimal)
{
	const auto capture = GetCapture("[a]{0,1}");
	auto statemachine = statemachine::ConvertRegexToDFA::ConvertToStatemachine(capture.get());

	const auto& states = statemachine->GetStates();
	const auto& transitions = statemachine->GetTransitions();

	EXPECT_EQ(2, states.size());
	EXPECT_EQ(1, transitions.size());
	EXPECT_EQ(2, statemachine->GetAcceptStates().size());
	EXPECT_TRUE(statemachine->GetStartState()->IsAcceptState());
}

TEST_F(TestConvertRegexToDFA, ConvertToDfaCycle_SquareMin0Max2_DfaIsCorrectAndMinimal)
{
	const auto capture = GetCapture("[a]{0,2}");
	auto statemachine = statemachine::ConvertRegexToDFA::ConvertToStatemachine(capture.get());

	const auto& states = statemachine->GetStates();
	const auto& transitions = statemachine->GetTransitions();

	EXPECT_EQ(3, states.size());
	EXPECT_EQ(2, transitions.size());
	EXPECT_EQ(3, statemachine->GetAcceptStates().size());
	EXPECT_TRUE(statemachine->GetStartState()->IsAcceptState());
}

TEST_F(TestConvertRegexToDFA, ConvertToDfaCycle_Group2SquaresMin0Max3ORred_DfaIsCorrectAndMinimal)
{
	const auto capture = GetCapture("(([a]{0,3})|([b]{0,3}))");
	auto statemachine = statemachine::ConvertRegexToDFA::ConvertToStatemachine(capture.get());
	statemachine->Minimize();

	const auto& states = statemachine->GetStates();
	const auto& transitions = statemachine->GetTransitions();

	EXPECT_EQ(7, states.size());
	EXPECT_EQ(14, transitions.size());
	EXPECT_EQ(6, statemachine->GetAcceptStates().size());
	EXPECT_TRUE(statemachine->GetStartState()->IsAcceptState());
}

TEST_F(TestConvertRegexToDFA, ConvertToDfaCycle_Group2SquaresORredMin0Max3_DfaIsCorrectAndMinimal)
{
	const auto capture = GetCapture("(([a])|([b])){0,3}");
	auto statemachine = statemachine::ConvertRegexToDFA::ConvertToStatemachine(capture.get());
	statemachine->Minimize();

	const auto& states = statemachine->GetStates();
	const auto& transitions = statemachine->GetTransitions();

	EXPECT_EQ(5, states.size());
	EXPECT_EQ(10, transitions.size());
	EXPECT_EQ(4, statemachine->GetAcceptStates().size());
	EXPECT_TRUE(statemachine->GetStartState()->IsAcceptState());
}

TEST_F(TestConvertRegexToDFA, ConvertToDfaCycle_Group3SquaresORredMin0Max3_DfaIsCorrectAndMinimal)
{
	const auto capture = GetCapture("(([a])|([b])|([c])){0,3}");
	auto statemachine = statemachine::ConvertRegexToDFA::ConvertToStatemachine(capture.get());
	statemachine->Minimize();

	const auto& states = statemachine->GetStates();
	const auto& transitions = statemachine->GetTransitions();

	EXPECT_EQ(5, states.size());
	EXPECT_EQ(15, transitions.size());
	EXPECT_EQ(4, statemachine->GetAcceptStates().size());
	EXPECT_TRUE(statemachine->GetStartState()->IsAcceptState());
}

TEST_F(TestConvertRegexToDFA, ConvertToDfaCycle_Group3SquaresORredMin1Max3_DfaIsCorrectAndMinimal)
{
	const auto capture = GetCapture("(([a])|([b])|([c])){1,3}");
	auto statemachine = statemachine::ConvertRegexToDFA::ConvertToStatemachine(capture.get());
	statemachine->Minimize();

	const auto& states = statemachine->GetStates();
	const auto& transitions = statemachine->GetTransitions();

	EXPECT_EQ(5, states.size());
	EXPECT_EQ(15, transitions.size());
	EXPECT_EQ(3, statemachine->GetAcceptStates().size());
	EXPECT_FALSE(statemachine->GetStartState()->IsAcceptState());
}

TEST_F(TestConvertRegexToDFA, ConvertToDfaCycle_Group3SquaresORredMin2Max3_DfaIsCorrectAndMinimal)
{
	const auto capture = GetCapture("(([a])|([b])|([c])){2,3}");
	auto statemachine = statemachine::ConvertRegexToDFA::ConvertToStatemachine(capture.get());
	statemachine->Minimize();

	const auto& states = statemachine->GetStates();
	const auto& transitions = statemachine->GetTransitions();

	EXPECT_EQ(5, states.size());
	EXPECT_EQ(15, transitions.size());
	EXPECT_EQ(2, statemachine->GetAcceptStates().size());
	EXPECT_FALSE(statemachine->GetStartState()->IsAcceptState());
}

TEST_F(TestConvertRegexToDFA, ConvertToDfaCycleStar_GroupWith1Square_DfaIsCorrectAndMinimal)
{
	const auto capture = GetCapture("([a])*");
	auto statemachine = statemachine::ConvertRegexToDFA::ConvertToStatemachine(capture.get());
	statemachine->Minimize();

	const auto& states = statemachine->GetStates();
	const auto& transitions = statemachine->GetTransitions();

	EXPECT_EQ(1, states.size());
	EXPECT_EQ(1, transitions.size());
	EXPECT_EQ(1, statemachine->GetAcceptStates().size());
	EXPECT_TRUE(statemachine->GetStartState()->IsAcceptState());
}

TEST_F(TestConvertRegexToDFA, ConvertToDfaCycleStar_GroupWith2Square_DfaIsCorrectAndMinimal)
{
	const auto capture = GetCapture("([a][b])*");
	auto statemachine = statemachine::ConvertRegexToDFA::ConvertToStatemachine(capture.get());
	statemachine->Minimize();

	const auto& states = statemachine->GetStates();
	const auto& transitions = statemachine->GetTransitions();

	EXPECT_EQ(3, states.size());
	EXPECT_EQ(6, transitions.size());
	EXPECT_EQ(1, statemachine->GetAcceptStates().size());
	EXPECT_TRUE(statemachine->GetStartState()->IsAcceptState());
}

TEST_F(TestConvertRegexToDFA, ConvertToDfaCycleStar_GroupWith3Square_DfaIsCorrectAndMinimal)
{
	const auto capture = GetCapture("([a][b][c])*");
	auto statemachine = statemachine::ConvertRegexToDFA::ConvertToStatemachine(capture.get());
	statemachine->Minimize();

	const auto& states = statemachine->GetStates();
	const auto& transitions = statemachine->GetTransitions();

	EXPECT_EQ(4, states.size());
	EXPECT_EQ(12, transitions.size());
	EXPECT_EQ(1, statemachine->GetAcceptStates().size());
	EXPECT_TRUE(statemachine->GetStartState()->IsAcceptState());
}

TEST_F(TestConvertRegexToDFA, ConvertToDfaCycleStar_GroupWith4Square_DfaIsCorrectAndMinimal)
{
	const auto capture = GetCapture("([a][b][c][d])*");
	auto statemachine = statemachine::ConvertRegexToDFA::ConvertToStatemachine(capture.get());

	const auto& states = statemachine->GetStates();
	const auto& transitions = statemachine->GetTransitions();

	EXPECT_EQ(5, states.size());
	EXPECT_EQ(5, transitions.size());
	EXPECT_EQ(2, statemachine->GetAcceptStates().size());
	EXPECT_TRUE(statemachine->GetStartState()->IsAcceptState());
}

TEST_F(TestConvertRegexToDFA,
	   ConvertToDfaCycleStar_GroupWith2SquaresORredWith1Character_DfaIsCorrectAndMinimal)
{
	const auto capture = GetCapture("(([a])|([b]))*");
	auto statemachine = statemachine::ConvertRegexToDFA::ConvertToStatemachine(capture.get());

	const auto& states = statemachine->GetStates();
	const auto& transitions = statemachine->GetTransitions();

	EXPECT_EQ(3, states.size());
	EXPECT_EQ(6, transitions.size());
	EXPECT_EQ(3, statemachine->GetAcceptStates().size());
	EXPECT_TRUE(statemachine->GetStartState()->IsAcceptState());
}

TEST_F(TestConvertRegexToDFA,
	   ConvertToDfaCycleStar_GroupWith3SquaresORredWith1Character_DfaIsCorrectAndMinimal)
{
	const auto capture = GetCapture("(([a])|([b])|([c]))*");
	auto statemachine = statemachine::ConvertRegexToDFA::ConvertToStatemachine(capture.get());

	const auto& states = statemachine->GetStates();
	const auto& transitions = statemachine->GetTransitions();

	EXPECT_EQ(4, states.size());
	EXPECT_EQ(12, transitions.size());
	EXPECT_EQ(4, statemachine->GetAcceptStates().size());
	EXPECT_TRUE(statemachine->GetStartState()->IsAcceptState());
}

TEST_F(TestConvertRegexToDFA,
	   ConvertToDfaCycleStar_GroupWith4SquaresORredWith1Character_DfaIsCorrectAndMinimal)
{
	const auto capture = GetCapture("(([a])|([b])|([c])|([d]))*");
	auto statemachine = statemachine::ConvertRegexToDFA::ConvertToStatemachine(capture.get());

	const auto& states = statemachine->GetStates();
	const auto& transitions = statemachine->GetTransitions();

	EXPECT_EQ(5, states.size());
	EXPECT_EQ(20, transitions.size());
	EXPECT_EQ(5, statemachine->GetAcceptStates().size());
	EXPECT_TRUE(statemachine->GetStartState()->IsAcceptState());
}

TEST_F(TestConvertRegexToDFA,
	   ConvertToDfaCycleStar_GroupWith2SquaresORredWith3Character_DfaIsCorrectAndMinimal)
{
	const auto capture = GetCapture("(([a][b][c])|([a][b][d]))*");
	auto statemachine = statemachine::ConvertRegexToDFA::ConvertToStatemachine(capture.get());

	const auto& states = statemachine->GetStates();
	const auto& transitions = statemachine->GetTransitions();

	EXPECT_EQ(5, states.size());
	EXPECT_EQ(6, transitions.size());
	EXPECT_EQ(3, statemachine->GetAcceptStates().size());
	EXPECT_TRUE(statemachine->GetStartState()->IsAcceptState());
}

TEST_F(TestConvertRegexToDFA, ConvertToDfaCycleStar_2A_or_5A_DfaIsCorrectAndMinimal)
{
	const auto capture = GetCapture("((aa)|(aaaaa))*");
	auto statemachine = statemachine::ConvertRegexToDFA::ConvertToStatemachine(capture.get());
	statemachine->Minimize();

	const auto& states = statemachine->GetStates();
	const auto& transitions = statemachine->GetTransitions();

	EXPECT_EQ(5, states.size());
	EXPECT_EQ(5, transitions.size());
	EXPECT_EQ(3, statemachine->GetAcceptStates().size());
	EXPECT_TRUE(statemachine->GetStartState()->IsAcceptState());
}

TEST_F(TestConvertRegexToDFA, ConvertToDfaCycleStar_2A_or_7A_DfaIsCorrectAndMinimal)
{
	const auto capture = GetCapture("((aa)|(aaaaaaa))*");
	auto statemachine = statemachine::ConvertRegexToDFA::ConvertToStatemachine(capture.get());
	statemachine->Minimize();

	const auto& states = statemachine->GetStates();
	const auto& transitions = statemachine->GetTransitions();

	EXPECT_EQ(7, states.size());
	EXPECT_EQ(7, transitions.size());
	EXPECT_EQ(4, statemachine->GetAcceptStates().size());
	EXPECT_TRUE(statemachine->GetStartState()->IsAcceptState());
}

TEST_F(TestConvertRegexToDFA, ConvertToDfa_DLDLv1RegexMatcher_DfaIsCorrectAndMinimal)
{
	const auto capture = GetCapture(
		"(([\\[][^\\]]+[\\]\\s\\\\a-zA-Z_0-9\\}\\{\\&\\#\\@\\%\\$]*[\\]](([\\{][\\s]*[0-9]+[\\s]*[,"
		"]["
		"\\s]*[0-9]+[\\s]*[\\}])|([+*]{0,1}))([\\)]*)[|]{0,1})|([\\^]{0,1}[\\(][^\\)]+[\\)\\sa-"
		"zA-Z_0-9\\[\\]\\}\\{\\&\\#\\@\\%\\$]*[\\)][\\]]{0,1}(([\\{][\\s]*[0-9]+[\\s]*[,][\\s]*[0-"
		"9]+"
		"[\\s]*[\\}])|([+*]{0,1}))((([|\\)]*))[+*]{0,1}[$]{0,1}))|([a-zA-Z_0-9]+))+");
	auto statemachine = statemachine::ConvertRegexToDFA::ConvertToStatemachine(capture.get());

	const auto& states = statemachine->GetStates();
	const auto& transitions = statemachine->GetTransitions();
}
