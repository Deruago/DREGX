#ifndef DREGX_STATEMACHINE_STATE_H
#define DREGX_STATEMACHINE_STATE_H

#include "dregx/Statemachine/Conditional.h"
#include <set>
#include <vector>

namespace dregx::statemachine
{
	class Transition;

	class State
	{
	private:
		bool start = false;
		bool accept = false;
		bool sink = false;

		std::vector<Transition*> inTransitions;
		std::vector<Transition*> outTransitions;

	public:
		State() = default;
		~State();

	public:
		void SetStart(bool start_);
		void SetSink(bool sink_);
		void SetAccept(bool accept_);

		void SetInTransitions(std::vector<Transition*> inTransitions_);
		void SetOutTransitions(std::vector<Transition*> outTransitions_);

		void RemoveInTransition(Transition* transition);
		void RemoveOutTransition(Transition* transition);

		void AddOutTransition(Transition* transition);
		void AddInTransition(Transition* transition);

	public:
		bool IsStartState() const;
		bool IsSinkState() const;
		bool IsAcceptState() const;

		std::vector<Transition*> GetInTransitions() const;
		std::vector<Transition*> GetOutTransitions() const;

		bool DoesInTransitionExist(std::vector<Conditional> condition, State* state) const;
		bool DoesOutTransitionExist(std::vector<Conditional> condition, State* state) const;

		bool DoesInTransitionExist(Transition* rhs) const;
		bool DoesOutTransitionExist(Transition* rhs) const;

		Transition* GetInTransition(Transition* rhs) const;
		Transition* GetOutTransition(Transition* rhs) const;

		bool DoesInTransitionExistWithSameCondition(Transition* rhs) const;
		bool DoesOutTransitionExistWithSameCondition(Transition* rhs) const;

		bool DoesInTransitionExistWithSameCondition(std::vector<Conditional> condition) const;
		bool DoesOutTransitionExistWithSameCondition(std::vector<Conditional> condition) const;

		Transition* GetInTransitionWithSameCondition(Transition* rhs) const;
		Transition* GetOutTransitionWithSameCondition(Transition* rhs) const;

		Transition* GetInTransitionWithSameCondition(std::vector<Conditional> condition) const;
		Transition* GetOutTransitionWithSameCondition(std::vector<Conditional> condition) const;

		bool HasConditions(const std::vector<std::vector<Conditional>>& in,
						   const std::vector<std::vector<Conditional>>& out);

		std::set<State*> GetConnectedStatesWithConditional(std::vector<Conditional> condition);
		void
		GetConnectedStatesWithConditional(std::vector<Conditional> condition,
										  std::set<dregx::statemachine::State*>& visitedStates,
										  std::set<dregx::statemachine ::State*>& connectedStates);
	};
}

#endif // DREGX_STATEMACHINE_STATE_H
