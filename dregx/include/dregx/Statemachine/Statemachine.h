#ifndef DREGX_STATEMACHINE_STATEMACHINE_H
#define DREGX_STATEMACHINE_STATEMACHINE_H

#include "dregx/Ir/Extension.h"
#include "dregx/Statemachine/Algorithm/Flag.h"
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
	public:
		std::vector<State*> acceptedStates;	   // Not implemented: Caching Variable(Do not alter)
		std::vector<State*> nonAcceptedStates; // Not implemented: Caching Variable(Do not alter)
		State* startState = nullptr;		   // Not implemented: Caching Variable(Do not alter)
		State* sinkState = nullptr;			   // Caching Variable(Do not alter)

		std::vector<std::unique_ptr<State>> states;			  // Caching Variable(Do not alter)
		std::vector<std::unique_ptr<Transition>> transitions; // Caching Variable(Do not alter)

	public:
		Flag flags{false, false, false, false}; // Caching Variable(Do not alter)

	public:
		Statemachine() = default;
		~Statemachine() = default;

	public:
		void ToDFA();
		void Minimize(bool splitFlavoredAcceptStates = true);
		void RemoveUnreachableStates();
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
		bool operator!=(Statemachine& rhs);
		bool operator!=(const Statemachine& rhs) const;

	public:
		void AddState(std::unique_ptr<State> value);
		void AddTransition(std::unique_ptr<Transition> transition);
		void SetStates(std::vector<std::unique_ptr<State>> states_);
		void SetTransitions(std::vector<std::unique_ptr<Transition>> transitions_);
		void Extend(const ir::Extension& extension);
		void Group(const std::set<std::string>& set);
		void SetStartState(State* startState_);
		void UpdateDepth();
		void UpdateIndex();

		void RemoveTransition(Transition* transition);
		void RemoveState(State* state);

	public:
		const std::vector<std::unique_ptr<State>>& GetStates() const;
		std::vector<dregx::statemachine::State*>
		GetStates(std::vector<std::vector<Conditional>> inConditions,
				  std::vector<std::vector<Conditional>> outConditions) const;
		const std::vector<std::unique_ptr<Transition>>& GetTransitions() const;
		State* GetStartState() const;
		State* GetSinkState() const;
		std::vector<State*> GetAcceptStates() const;
		std::set<std::vector<dregx::statemachine::Conditional>> GetAlphabet();

	public:
		std::string Print() const;

		void OptimizeFinalAcceptStates();

		void GetStatesToSource(const std::vector<State*>& states, std::set<State*>& embeddedStates);
		void GetStatesToSource(const State* state, std::set<State*>& embeddedStates);

		TransitionTable ToTransitionTable();

	private:
		void FillSinkState();
	};
}

#endif // DREGX_STATEMACHINE_STATEMACHINE_H
