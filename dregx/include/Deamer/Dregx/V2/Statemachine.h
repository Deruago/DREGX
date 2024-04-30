#ifndef DEAMER_DREGX_V2_STATEMACHINE_H
#define DEAMER_DREGX_V2_STATEMACHINE_H

#include <memory>
#include <vector>
#include <array>
#include <map>
#include <set>
#include <string>

namespace dregx::statemachine
{
	class Statemachine;
}

namespace deamer::dregx::v2
{
	class Statemachine
	{
	private:
		// Transition Table, inner vector is scaled ahead of time
		// Indexing is always TT[Character][Current State] = Target State
		// I.e. TT[Current State * (1 << sizeof(Character)) + Character] = Target State
		std::vector<std::size_t> transitionTable;
		std::size_t totalStates;
		std::size_t totalAlphabetSize;
		std::size_t reservedStateTypeSpace;
		std::size_t reservedFlavorSpace;
		std::size_t reservedStateSpace;

		// Masks are Inferred from reserved spaces
		std::size_t stateMask;
		std::size_t stateTypeMask;
		std::size_t stateFlavorMask;

		std::size_t startState;
		std::size_t sinkState;

		std::map<std::set<std::string>, std::size_t> mapFlavorSetWithFlavorId;
		std::map<std::size_t, std::set<std::string>> mapFlavorIdWithFlavorSet;

		std::map<std::size_t, char> mapAlphabetIdWithCharacter;
		std::map<char, std::size_t> mapCharacterWithAlphabetId;

	public:
		Statemachine(std::unique_ptr<::dregx::statemachine::Statemachine> v1Statemachine,
					 std::size_t reservedFlavorSpace_ = 10);

		Statemachine(const Statemachine& rhs);

		Statemachine(std::size_t reservedFlavorSpace_ = 10);

		virtual ~Statemachine() = default;

	public:
		std::unique_ptr<Statemachine> Copy() const;

		bool Equal(const ::deamer::dregx::v2::Statemachine& rhs) const;

		bool Match(const std::string& rhs) const;

	// Operations
	public:
		std::unique_ptr<::deamer::dregx::v2::Statemachine> Or(const Statemachine& rhs_);

		void And(const Statemachine& rhs);

		void Concatenate(const Statemachine& rhs);

	public:
		void ToDFA();

		// Minimizes current state space
		//	- Removes unreachable states
		void Squash();

		void Minimize();
		
	};
}

#endif // DEAMER_DREGX_V2_STATEMACHINE_H
