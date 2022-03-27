#include "dregx/Statemachine/Algorithm/NDFA/Or.h"

dregx::statemachine::Flag dregx::statemachine::ndfa::Or::Flags(Statemachine* lhs, Statemachine* rhs)
{
	const Flag flags(
		Flag::IsDfa(false),
		Flag::ContainsCycles(lhs->flags.containsCycles || rhs->flags.containsCycles),
		Flag::EmbeddedAcceptState(lhs->flags.containsCycles || rhs->flags.containsCycles),
		Flag::AllTransitionDeterminized(false));

	return flags;
}

void dregx::statemachine::ndfa::Or::SinkState(State* state, Statemachine* lhs, Statemachine* rhs)
{
	lhs->sinkState = state;
}

void dregx::statemachine::ndfa::Or::StartState(State* state, Statemachine* lhs, Statemachine* rhs)
{
	lhs->SetStartState(state);
}

void dregx::statemachine::ndfa::Or::Operation(Statemachine* lhs, Statemachine* rhs)
{
	auto newStartState = std::make_unique<State>();
	auto* lhsStartState = lhs->GetStartState();
	auto* rhsStartState = rhs->GetStartState();

	newStartState->SetStart(true);
	lhsStartState->SetStart(false);
	rhsStartState->SetStart(false);

	auto linkWithLhsStartState = std::make_unique<Transition>(
		newStartState.get(), std::vector<Conditional>{}, lhsStartState);
	auto linkWithRhsStartState = std::make_unique<Transition>(
		newStartState.get(), std::vector<Conditional>{}, rhsStartState);

	StartState(newStartState.get(), lhs, rhs);
	lhs->AddState(std::move(newStartState));
	lhs->AddTransition(std::move(linkWithLhsStartState));
	lhs->AddTransition(std::move(linkWithRhsStartState));

	for (auto& rhsState : rhs->states)
	{
		lhs->AddState(std::move(rhsState));
	}

	for (auto& rhsTransition : rhs->transitions)
	{
		lhs->AddTransition(std::move(rhsTransition));
	}

	SinkState(nullptr, lhs, rhs);
}

bool dregx::statemachine::ndfa::Or::CheckPreconditions(Statemachine* lhs, Statemachine* rhs)
{
	return true;
}
