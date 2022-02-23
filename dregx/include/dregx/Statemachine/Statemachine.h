#ifndef DREGX_STATEMACHINE_STATEMACHINE_H
#define DREGX_STATEMACHINE_STATEMACHINE_H

#include "dregx/Ir/Extension.h"
#include "dregx/Statemachine/State.h"
#include "dregx/Statemachine/Transition.h"
#include <memory>
#include <set>
#include <vector>

namespace dregx::statemachine
{
	class Statemachine
	{
	private:
		std::vector<std::unique_ptr<State>> states;
		std::vector<std::unique_ptr<Transition>> transitions;

	public:
		Statemachine() = default;
		~Statemachine() = default;

	public:
		void Or(Statemachine& rhs);
		void Concatenate(Statemachine& rhs);
		std::unique_ptr<Statemachine> Copy() const;

	public:
		Statemachine& operator|(Statemachine& rhs);
		Statemachine& operator&(Statemachine& rhs);

	public:
		void AddState(std::unique_ptr<State> value);
		void AddTransition(std::unique_ptr<Transition> transition);
		void SetStates(std::vector<std::unique_ptr<State>> states_);
		void SetTransitions(std::vector<std::unique_ptr<Transition>> transitions_);
		void Extend(const ir::Extension& extension);

		void RemoveTransition(Transition* transition);
		void RemoveState(State* state);

	public:
		const std::vector<std::unique_ptr<State>>& GetStates() const;
		std::vector<dregx::statemachine::State*>
		GetStates(std::vector<std::vector<Conditional>> inConditions,
				  std::vector<std::vector<Conditional>> outConditions) const;
		const std::vector<std::unique_ptr<Transition>>& GetTransitions() const;
		State* GetStartState() const;
		std::vector<State*> GetAcceptStates() const;

	public:
		std::string Print() const;

		void OptimizeFinalAcceptStates();

	private:
		void OrSpecificState(State* state, State* rhsState, Transition* transition,
							 Statemachine& rhs, std::set<State*>& visitedStates);

		void ConcatenateSpecificState(State* state, State* rhsState, Transition* transition,
									  Statemachine& rhs, std::size_t depth,
									  std::tuple<std::size_t, std::vector<State*>>& linkStates,
									  std::set<State*>& visitedStates);
		void GetStatesToSource(const std::vector<State*>& states, std::set<State*>& embeddedStates);
		void GetStatesToSource(const State* state, std::set<State*>& embeddedStates);
		void MergeInfiniteCycle(State* originalState, State* acceptState, State* startState,
								Transition* startTransition,
								std::set<State*> visitedStates);
	};
}

#endif // DREGX_STATEMACHINE_STATEMACHINE_H
