#ifndef DREGX_STATEMACHINE_STATEMACHINE_H
#define DREGX_STATEMACHINE_STATEMACHINE_H

#include "dregx/Ir/Extension.h"
#include "dregx/Statemachine/State.h"
#include "dregx/Statemachine/Transition.h"
#include "dregx/Statemachine/TransitionTable.h"
#include <memory>
#include <set>
#include <vector>

namespace dregx::statemachine
{
	class Statemachine
	{
	private:
		// Caching variables
		std::vector<State*> acceptedStates;	   // Not implemented
		std::vector<State*> nonAcceptedStates; // Not implemented
		State* startState = nullptr;		   // Not implemented
		State* sinkState = nullptr;

		std::vector<std::unique_ptr<Conditional>> conditionals;
		std::vector<std::unique_ptr<State>> states;
		std::vector<std::unique_ptr<Transition>> transitions;
		bool containsCycles = false;
		bool IsDFA = true;
		bool EmbeddedAcceptState = false;
		bool AllTransitionDeterminized = false;

	public:
		Statemachine() = default;
		~Statemachine() = default;

	public:
		void ToDFA();
		void Minimize();
		void DeterminizeAllTransitions();
		void Or(Statemachine& rhs);
		void And(Statemachine& rhs);
		void Concatenate(Statemachine& rhs);
		bool Equal(const Statemachine& rhs) const;
		bool InEqual(const Statemachine& rhs) const;

		std::unique_ptr<Statemachine> Copy() const;

	public:
		Statemachine& operator|(Statemachine& rhs);
		Statemachine& operator&(Statemachine& rhs);
		bool operator==(Statemachine& rhs);
		bool operator==(const Statemachine& rhs) const;

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
		std::set<std::vector<dregx::statemachine::Conditional>> GetAlphabet();

	public:
		std::string Print() const;

		void OptimizeFinalAcceptStates();

		void GetStatesToSource(const std::vector<State*>& states, std::set<State*>& embeddedStates);
		void GetStatesToSource(const State* state, std::set<State*>& embeddedStates);

		TransitionTable ToTransitionTable();

	private:
		void ProductConstructionOR(Statemachine& rhs);
		void ProductConstructionAND(const Statemachine& rhs);
	};
}

#endif // DREGX_STATEMACHINE_STATEMACHINE_H
