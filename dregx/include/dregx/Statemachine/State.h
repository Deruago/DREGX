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
	public:
		bool any = false; // Cache variable usable for anything

	private:
		bool start = false;
		bool accept = false;
		bool sink = false;
		std::size_t depth = 0;
		std::size_t index = 0;

		// Transitions are always sorted by condition
		std::vector<Transition*> inTransitions;
		std::vector<Transition*> outTransitions;
		std::set<std::string> flavors;

	public:
		State() = default;
		~State();

	public:
		void SetStart(bool start_);
		void SetSink(bool sink_);
		void SetAccept(bool accept_);
		void SetDepth(std::size_t depth_);
		void SetFlavors(const std::set<std::string>& set);
		void AddFlavors(const std::set<std::string>& set);
		void SetIndex(std::size_t size);

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
		std::set<std::string> GetFlavors() const;
		std::size_t GetIndex() const;

		std::size_t GetDepth() const;

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
