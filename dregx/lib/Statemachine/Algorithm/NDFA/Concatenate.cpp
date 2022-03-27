#include "dregx/Statemachine/Algorithm/NDFA/Concatenate.h"

dregx::statemachine::Flag dregx::statemachine::ndfa::Concatenate::Flags(Statemachine* lhs,
																		Statemachine* rhs)
{
	const Flag flags(
		Flag::IsDfa(false),
		Flag::ContainsCycles(lhs->flags.containsCycles || rhs->flags.containsCycles),
		Flag::EmbeddedAcceptState(lhs->flags.containsCycles || rhs->flags.containsCycles),
		Flag::AllTransitionDeterminized(false));

	return flags;
}

void dregx::statemachine::ndfa::Concatenate::SinkState(State* state, Statemachine* lhs,
													   Statemachine* rhs)
{
	// untouched
}

void dregx::statemachine::ndfa::Concatenate::StartState(State* state, Statemachine* lhs,
														Statemachine* rhs)
{
	// untouched
}

void dregx::statemachine::ndfa::Concatenate::Operation(Statemachine* lhs, Statemachine* rhs)
{
	auto* rhsStartState = rhs->GetStartState();
	rhsStartState->SetStart(false);
	for (auto* acceptState : lhs->GetAcceptStates())
	{
		auto linkWithRhsStartState =
			std::make_unique<Transition>(acceptState, std::vector<Conditional>{}, rhsStartState);
		lhs->AddTransition(std::move(linkWithRhsStartState));
		acceptState->SetAccept(false);
		lhs->nonAcceptedStates.push_back(acceptState);
	}
	lhs->acceptedStates.clear();

	for (auto& rhsState : rhs->states)
	{
		// Any sink state is set to false
		rhsState->SetSink(false);
		lhs->AddState(std::move(rhsState));
	}

	for (auto& rhsTransition : rhs->transitions)
	{
		lhs->AddTransition(std::move(rhsTransition));
	}

	rhs->states.clear();
	rhs->transitions.clear();
}

bool dregx::statemachine::ndfa::Concatenate::CheckPreconditions(Statemachine* lhs,
																Statemachine* rhs)
{
	return true;
}
