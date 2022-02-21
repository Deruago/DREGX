#ifndef DREGX_STATEMACHINE_STATEMACHINE_H
#define DREGX_STATEMACHINE_STATEMACHINE_H

#include "dregx/Ir/Extension.h"
#include "dregx/Statemachine/State.h"
#include "dregx/Statemachine/Transition.h"
#include <vector>

namespace dregx::statemachine
{
	class Statemachine
	{
	private:
		std::vector<State*> states;
		std::vector<Transition*> transitions;

	public:
		Statemachine() = default;
		~Statemachine();

	public:
		void Or(Statemachine& rhs);
		void Concatenate(Statemachine& rhs);

	public:
		Statemachine& operator|(Statemachine& rhs);
		Statemachine& operator&(Statemachine& rhs);

	public:
		void AddState(State* value);
		void AddTransition(Transition* transition);
		void SetStates(std::vector<State*> states_);
		void SetTransitions(std::vector<Transition*> transitions_);
		void Extend(const ir::Extension& extension);

		void RemoveTransition(Transition* transition);
		void RemoveState(State* state);

	public:
		std::vector<State*> GetStates() const;
		std::vector<State*> GetStates(std::vector<std::vector<Conditional>> inConditions,
									  std::vector<std::vector<Conditional>> outConditions) const;
		std::vector<Transition*> GetTransitions() const;
		State* GetStartState() const;
		std::vector<State*> GetAcceptStates() const;

	public:
		std::string Print() const;

		void OptimizeFinalAcceptStates();

	private:
		void OrSpecificState(State* state, State* getStartState, Transition* transition,
							 Statemachine& rhs);
	};
}

#endif // DREGX_STATEMACHINE_STATEMACHINE_H
