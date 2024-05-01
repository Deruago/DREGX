#include "Deamer/Dregx/V2/Statemachine.h"
#include "dregx/Statemachine/Statemachine.h"
#include <memory>
#include <stdexcept>
#include <limits>
#include <chrono>
#include <iostream>

::deamer::dregx::v2::Statemachine::Statemachine(
	std::unique_ptr<::dregx::statemachine::Statemachine> v1Statemachine,
	std::size_t reservedFlavorSpace_)
	: Statemachine(reservedFlavorSpace_)
{
	using std::chrono::system_clock;
	auto start = std::chrono::system_clock::now();

	const auto& otherStates = v1Statemachine->GetStates();
	const auto& otherAlphabet = v1Statemachine->GetAlphabet();

	totalStates = otherStates.size();

	// Alphabet is always reduced to single Characters, V2 will be less expressive then V1, but more performant
	totalAlphabetSize = otherAlphabet.size();
	auto findIndex = [&otherStates,
					  this](::dregx::statemachine::State* targetState) -> std::size_t {
		for (std::size_t stateI = 0; stateI < totalStates; stateI++)
		{
			if (otherStates[stateI].get() == targetState)
			{
				return stateI;
			}
		}

		throw std::logic_error("Input Statemachine references non-captured state");
	};

	auto indexFlavorSet = [this](std::set<std::string> flavorSet) -> std::size_t {
		auto iter = mapFlavorSetWithFlavorId.find(flavorSet);
		if (iter == mapFlavorSetWithFlavorId.end())
		{
			auto id = mapFlavorSetWithFlavorId.size();
			mapFlavorSetWithFlavorId.insert({flavorSet, id});
			mapFlavorIdWithFlavorSet.insert({id, flavorSet});

			return id;
		}

		return iter->second;
	};

	auto registerAlphabet =
		[this](std::size_t alphaIndex,
			   std::vector<::dregx::statemachine::Conditional> analyzedAlphabet) -> void {
		if (analyzedAlphabet.size() > 1)
		{
			throw std::logic_error("Original alphabet is not singular");
		}

		if (mapAlphabetIdWithCharacter.find(alphaIndex) == mapAlphabetIdWithCharacter.end())
		{
			auto character = analyzedAlphabet[0].GetCharacter();
			if (character.size() > 1)
			{
				throw std::logic_error("Character exists of more than 1 characters");
			}

			mapAlphabetIdWithCharacter.insert({alphaIndex, character[0]});
			mapCharacterWithAlphabetId.insert({character[0], alphaIndex});
		}
	};

	auto getStateInformation = [&](::dregx::statemachine::State* targetState) -> std::size_t {
		auto targetIndex = findIndex(targetState);
		auto targetAccept =
			static_cast<std::size_t>(targetState->IsAcceptState() &&
									 true); // Guaranteed to be either 1 (accept) or 0 (non accept)
		auto targetFlavor = indexFlavorSet(targetState->GetFlavors());

		auto targetStateInformation = targetIndex | targetAccept << (reservedStateSpace) |
									  targetFlavor << (reservedStateSpace + reservedStateTypeSpace);
		return targetStateInformation;
	};

	if (v1Statemachine->GetSinkState() != nullptr)
	{
		sinkState = getStateInformation(v1Statemachine->GetSinkState());

		auto totalVectorRequirement = totalStates * totalAlphabetSize;
		transitionTable.resize(totalVectorRequirement);
	}
	else
	{
		// The last state is always free unless maximum states is reached which will lead to
		// non-conformance anyway. Flavor is not accepting and has no flavors Thus only indicate
		// that it is the final state
		sinkState = totalStates & stateMask;

		// As a new state is added
		totalStates++;

		auto totalVectorRequirement = totalStates * totalAlphabetSize;
		transitionTable.resize(totalVectorRequirement);

		// For all elements in alphabet make back-loops
		for (std::size_t alphaI = 0; alphaI < totalAlphabetSize; alphaI++)
		{
			transitionTable[sinkState & stateMask * totalAlphabetSize + alphaI] = sinkState;
		}
	}
	
	auto alphabetIterator = std::begin(otherAlphabet);
	for (std::size_t alphaI = 0; alphaI < totalAlphabetSize; alphaI++)
	{
		auto analyzedAlphabet = *alphabetIterator;
		registerAlphabet(alphaI, analyzedAlphabet);

		for (std::size_t stateI = 0; stateI < totalStates && stateI < otherStates.size(); stateI++)
		{
			auto currentState = otherStates[stateI].get();
			auto currentStateInformation = getStateInformation(currentState);
			if (currentState->IsStartState())
			{
				startState = currentStateInformation;
			}

			if (currentState->IsSinkState())
			{
				if (currentStateInformation != sinkState)
				{
					// Multiple Sink States, which is not allowed
					throw std::logic_error("Detected multiple sink states which is not allowed");
				}
			}

			auto targetStates = currentState->GetConnectedStatesWithConditional(analyzedAlphabet);
			if (targetStates.empty())
			{
				// Move to Sink State, as there does not exist a proper transition
				transitionTable[stateI * totalAlphabetSize + alphaI] = sinkState;
				continue;
			}

			// We assume that the input statemachine is a DFA, then only a single state is connected
			auto targetState = (*std::begin(targetStates));
			
			auto targetStateInformation = getStateInformation(targetState);
			
			transitionTable[(currentStateInformation & stateMask) * totalAlphabetSize + alphaI] =
				targetStateInformation;
		}

		alphabetIterator++;
	}

	isCyclic = v1Statemachine->ContainsCycles();

	auto end = std::chrono::system_clock::now();
	std::chrono::duration<double> diff = end - start;
	std::cout << "Conversion V1 -> V2: " << diff.count() * 1000 << "ms\n";
}

::deamer::dregx::v2::Statemachine::Statemachine(const ::deamer::dregx::v2::Statemachine& rhs)
	:	transitionTable(rhs.transitionTable),
	  totalStates(rhs.totalStates),
	  totalAlphabetSize(rhs.totalAlphabetSize),
	  reservedStateTypeSpace(rhs.reservedStateTypeSpace),
	  reservedFlavorSpace(rhs.reservedFlavorSpace),
	  reservedStateSpace(rhs.reservedStateSpace),
	  stateMask(rhs.stateMask),
	  stateTypeMask(rhs.stateTypeMask),
	  stateFlavorMask(rhs.stateFlavorMask),
	  mapFlavorSetWithFlavorId(rhs.mapFlavorSetWithFlavorId),
	  mapFlavorIdWithFlavorSet(rhs.mapFlavorIdWithFlavorSet),
	  mapAlphabetIdWithCharacter(rhs.mapAlphabetIdWithCharacter),
	  mapCharacterWithAlphabetId(rhs.mapCharacterWithAlphabetId),
	  startState(rhs.startState),
	  sinkState(rhs.sinkState),
	  isCyclic(rhs.isCyclic)
{
}

::deamer::dregx::v2::Statemachine::Statemachine(std::size_t reservedFlavorSpace_)
	: reservedStateTypeSpace(1),
	  reservedFlavorSpace(reservedFlavorSpace_),
	  reservedStateSpace(sizeof(std::size_t) * 8 - reservedStateTypeSpace - reservedFlavorSpace)
{
	auto produceStateMask = [this]() -> void {
		stateMask = (static_cast<std::size_t>(1) << reservedStateSpace) - 1;
	};

	auto produceStateTypeMask = [this]() -> void {
		stateTypeMask = (static_cast<std::size_t>(1) << reservedStateSpace);
	};

	auto produceStateFlavorMask = [this]() -> void {
		stateFlavorMask =
			~((static_cast<std::size_t>(1) << (reservedStateSpace + reservedStateTypeSpace)) - 1);
	};

	produceStateMask();
	produceStateTypeMask();
	produceStateFlavorMask();
}

std::unique_ptr<::deamer::dregx::v2::Statemachine> deamer::dregx::v2::Statemachine::Copy() const
{
	return std::make_unique<::deamer::dregx::v2::Statemachine>(*this);
}

bool deamer::dregx::v2::Statemachine::Equal(const ::deamer::dregx::v2::Statemachine& rhs) const
{
	return this->transitionTable == rhs.transitionTable &&
		this->totalStates == rhs.totalStates &&
		this->totalAlphabetSize == rhs.totalAlphabetSize &&
		this->reservedStateTypeSpace == rhs.reservedStateTypeSpace &&
		this->reservedFlavorSpace == rhs.reservedFlavorSpace &&
		this->reservedStateSpace == rhs.reservedStateSpace &&
		this->mapFlavorSetWithFlavorId == rhs.mapFlavorSetWithFlavorId &&
		this->mapFlavorIdWithFlavorSet == rhs.mapFlavorIdWithFlavorSet &&
		this->mapAlphabetIdWithCharacter == rhs.mapAlphabetIdWithCharacter &&
		this->mapCharacterWithAlphabetId == rhs.mapCharacterWithAlphabetId &&
		this->startState == rhs.startState &&
		this->sinkState == rhs.sinkState
	;
}

bool deamer::dregx::v2::Statemachine::Match(const std::string& rhs) const
{
	using std::chrono::system_clock;
	auto start = std::chrono::system_clock::now();

	std::vector<std::size_t> actions;
	for (auto character : rhs)
	{
		auto iter = mapCharacterWithAlphabetId.find(character);
		if (iter == mapCharacterWithAlphabetId.end())
		{
			// Character does not belong to Alphabet
			return false;
		}

		actions.push_back(iter->second);
	}

	std::size_t currentState = startState;
	for (std::size_t actionI = 0; actionI < actions.size(); actionI++)
	{
		currentState =
			transitionTable[(currentState & stateMask) * totalAlphabetSize + actions[actionI]];
	}

	// Positive if it is accepting
	const auto result = (currentState & stateTypeMask) && true;

	auto end = std::chrono::system_clock::now();
	std::chrono::duration<double> diff = end - start;
	std::cout << "Matching a string: " << diff.count() * 1000 << "ms\n";

	return result;
}

template<std::size_t evaluatedDepth>
static std::size_t nearestLogOf2Impl(std::size_t input)
{
	if (input <= (1 << evaluatedDepth))
	{
		return evaluatedDepth;
	}

	if constexpr (sizeof(std::size_t) * 8 > evaluatedDepth)
	{
		return nearestLogOf2Impl<evaluatedDepth + 1>(input);
	}
	else
	{
		throw std::logic_error("Input is too large");
	}
}

static std::size_t nearestLogOf2(std::size_t input)
{
	return nearestLogOf2Impl<0>(input);
}

template<std::size_t evaluatedDepth>
std::size_t nearestPowerOf2Impl(std::size_t input)
{
	if (input <= (1 << evaluatedDepth))
	{
		return 1 << evaluatedDepth;
	}

	if constexpr (sizeof(std::size_t) * 8 > evaluatedDepth)
	{
		return nearestPowerOf2Impl<evaluatedDepth + 1>(input);
	}
	else
	{
		throw std::logic_error("Input is too large");
	}
}

std::size_t nearestPowerOf2(std::size_t input)
{
	return nearestPowerOf2Impl<0>(input);
}

bool deamer::dregx::v2::Statemachine::IsCyclic() const
{
	return isCyclic;
}

std::unique_ptr<::deamer::dregx::v2::Statemachine>
deamer::dregx::v2::Statemachine::Or(const Statemachine& rhs_) const
{
	std::unique_ptr<::deamer::dregx::v2::Statemachine> result;
	if (rhs_.IsCyclic() && this->IsCyclic())
	{
		result = GeneralOr(rhs_);
	}
	else
	{
		// Finite Regexes are ORrable in Linear time(States)
		if (rhs_.IsCyclic())
		{
			result = rhs_.LinearOr(*this);
		}
		else
		{
			result = LinearOr(rhs_);
		}
	}

	if (result == nullptr)
	{
		// Some internal failure occured
		// Use General method
		result = GeneralOr(rhs_);
	}

	if (rhs_.IsCyclic() || this->IsCyclic())
	{
		result->isCyclic = true;
	}

	return std::move(result);
}

std::unique_ptr<::deamer::dregx::v2::Statemachine>
deamer::dregx::v2::Statemachine::LinearOr(const Statemachine& rhs_) const
{
	using std::chrono::system_clock;
	auto start = std::chrono::system_clock::now();

	auto newStatemachine = std::make_unique<::deamer::dregx::v2::Statemachine>();

	// [Non]-Finite Statemachine
	const Statemachine& lhs = *this;
	const Statemachine& rhs = rhs_;

	const auto& lhsAlphabet = lhs.mapAlphabetIdWithCharacter;
	const auto& rhsAlphabet = rhs.mapAlphabetIdWithCharacter;

	const auto& lhsFlavor = lhs.mapFlavorIdWithFlavorSet;
	const auto& rhsFlavor = rhs.mapFlavorIdWithFlavorSet;

	// Unify Alphabets
	std::size_t commonAlphaCounter = 0;
	for (auto [lhsId, lhsAlpha] : lhsAlphabet)
	{
		auto iter = newStatemachine->mapCharacterWithAlphabetId.find(lhsAlpha);
		if (iter == newStatemachine->mapCharacterWithAlphabetId.end())
		{
			// New Alphabet
			newStatemachine->mapAlphabetIdWithCharacter.insert({commonAlphaCounter, lhsAlpha});
			newStatemachine->mapCharacterWithAlphabetId.insert({lhsAlpha, commonAlphaCounter});
			commonAlphaCounter++;
		}
	}

	for (auto [rhsId, rhsAlpha] : rhsAlphabet)
	{
		auto iter = newStatemachine->mapCharacterWithAlphabetId.find(rhsAlpha);
		if (iter == newStatemachine->mapCharacterWithAlphabetId.end())
		{
			// New Alphabet
			newStatemachine->mapAlphabetIdWithCharacter.insert({commonAlphaCounter, rhsAlpha});
			newStatemachine->mapCharacterWithAlphabetId.insert({rhsAlpha, commonAlphaCounter});
			commonAlphaCounter++;
		}
	}

	newStatemachine->totalAlphabetSize = commonAlphaCounter;

	std::size_t commonFlavorCounter = 0;
	for (auto [lhsId, lhsFlavor] : lhsFlavor)
	{
		auto iter = newStatemachine->mapFlavorSetWithFlavorId.find(lhsFlavor);
		if (iter == newStatemachine->mapFlavorSetWithFlavorId.end())
		{
			newStatemachine->mapFlavorIdWithFlavorSet.insert({commonFlavorCounter, lhsFlavor});
			newStatemachine->mapFlavorSetWithFlavorId.insert({lhsFlavor, commonFlavorCounter});
			commonFlavorCounter++;
		}
	}

	for (auto [rhsId, rhsFlavor] : rhsFlavor)
	{
		auto iter = newStatemachine->mapFlavorSetWithFlavorId.find(rhsFlavor);
		if (iter == newStatemachine->mapFlavorSetWithFlavorId.end())
		{
			newStatemachine->mapFlavorIdWithFlavorSet.insert({commonFlavorCounter, rhsFlavor});
			newStatemachine->mapFlavorSetWithFlavorId.insert({rhsFlavor, commonFlavorCounter});
			commonFlavorCounter++;
		}
	}

	auto unifySets = [](auto lhs, auto rhs) {
		for (auto element : rhs)
		{
			lhs.insert(element);
		}

		return lhs;
	};

	// Removeable if Flavorings have priority
	for (auto [lhsId, lhsFlavor] : lhsFlavor)
	{
		for (auto [rhsId, rhsFlavor] : rhsFlavor)
		{
			auto unifiedSet = unifySets(lhsFlavor, rhsFlavor);

			auto iter = newStatemachine->mapFlavorSetWithFlavorId.find(unifiedSet);
			if (iter == newStatemachine->mapFlavorSetWithFlavorId.end())
			{
				newStatemachine->mapFlavorIdWithFlavorSet.insert({commonFlavorCounter, unifiedSet});
				newStatemachine->mapFlavorSetWithFlavorId.insert({unifiedSet, commonFlavorCounter});
				commonFlavorCounter++;
			}
		}
	}

	//
	// Fill in lhs states in the new statemachine
	//

	newStatemachine->totalStates = lhs.totalStates + rhs.totalStates;
	newStatemachine->transitionTable.resize((lhs.totalStates + rhs.totalStates) * newStatemachine->totalAlphabetSize);

	newStatemachine->startState = lhs.startState;
	newStatemachine->sinkState = lhs.sinkState;

	std::size_t stateCounter = 0;

	for (std::size_t stateI = 0; stateI < lhs.totalStates; stateI++)
	{
		for (std::size_t alphaI = 0; alphaI < newStatemachine->totalAlphabetSize; alphaI++)
		{
			if (stateI < lhs.totalStates && alphaI < lhs.totalAlphabetSize)
			{
				newStatemachine->transitionTable[stateCounter * newStatemachine->totalAlphabetSize + alphaI] = lhs.transitionTable[stateI * lhs.totalAlphabetSize + alphaI];
			}
			else
			{
				newStatemachine->transitionTable[stateCounter * newStatemachine->totalAlphabetSize + alphaI] = newStatemachine->sinkState;
			}
		}

		stateCounter++;
	}

	for (std::size_t stateI = 0; stateI < rhs.totalStates; stateI++)
	{
		for (std::size_t alphaI = 0; alphaI < newStatemachine->totalAlphabetSize; alphaI++)
		{
			auto iter = rhs.mapCharacterWithAlphabetId.find(newStatemachine->mapAlphabetIdWithCharacter
							.find(alphaI)
							->second);

			if (stateI < rhs.totalStates && iter != rhs.mapCharacterWithAlphabetId.end())
			{
				auto rhsAlphaI = iter->second;
				newStatemachine
					->transitionTable[stateCounter * newStatemachine->totalAlphabetSize + alphaI] =
					rhs.transitionTable[stateI * rhs.totalAlphabetSize + rhsAlphaI] + lhs.totalStates;
			}
			else
			{
				newStatemachine
					->transitionTable[stateCounter * newStatemachine->totalAlphabetSize + alphaI] =
					newStatemachine->sinkState;
			}
		}

		stateCounter++;
	}

	//
	// Bi-simulate Start state
	//

	for (std::size_t alphaI = 0; alphaI < newStatemachine->totalAlphabetSize; alphaI++)
	{
		auto lhsSupportIter = lhs.mapCharacterWithAlphabetId.find(newStatemachine->mapAlphabetIdWithCharacter.find(alphaI)->second);
		auto rhsSupportIter = rhs.mapCharacterWithAlphabetId.find(newStatemachine->mapAlphabetIdWithCharacter.find(alphaI)->second);

		if (lhsSupportIter == lhs.mapCharacterWithAlphabetId.end() &&
			rhsSupportIter == rhs.mapCharacterWithAlphabetId.end())
		{
			// Both automatons do not support the transition
			// This is not possible [unreachable]
		}
		else if (lhsSupportIter == lhs.mapCharacterWithAlphabetId.end() &&
				 rhsSupportIter != rhs.mapCharacterWithAlphabetId.end())
		{
			// Lhs does not support
			// Rhs does support

			// The target state is equal to the rescaled right hand side state
			newStatemachine->transitionTable[
				(newStatemachine->startState & newStatemachine->stateMask) *
				newStatemachine->totalAlphabetSize +
				alphaI] = rhs.transitionTable[
					(rhs.startState & rhs.stateMask) *
					rhs.totalAlphabetSize +
					rhsSupportIter->second
				] + lhs.totalStates;
		}
		else if (lhsSupportIter != lhs.mapCharacterWithAlphabetId.end() &&
				 rhsSupportIter == rhs.mapCharacterWithAlphabetId.end())
		{
			// Lhs does support
			// Rhs does not support

			// Current logic is enough
			// This branch does not continue for Rhs
		}
		else if (lhsSupportIter != lhs.mapCharacterWithAlphabetId.end() &&
				 rhsSupportIter != rhs.mapCharacterWithAlphabetId.end())
		{
			// Lhs does support
			// Rhs does support

			// There are two cases:
			//	Lhs goes to a sink state
			//	Lhs goes to a non sink state
			//
			//	If it goes to a sink state, move to Rhs and done
			//	Otherwise Continue Simulation [Error]

			auto nextState = newStatemachine->transitionTable[
				(newStatemachine->startState & newStatemachine->stateMask) *
				newStatemachine->totalAlphabetSize +
				alphaI
			];

			if (nextState == newStatemachine->sinkState)
			{
				// Update to Rhs
				newStatemachine->transitionTable[
					(newStatemachine->startState & newStatemachine->stateMask) *
					newStatemachine->totalAlphabetSize +
					alphaI] = rhs.transitionTable[
						(rhs.startState & rhs.stateMask) *
						rhs.totalAlphabetSize +
						rhsSupportIter->second
					] + lhs.totalStates;
			}
			else
			{
				// Unsupported
				return nullptr;
			}
		}
	}

	auto end = std::chrono::system_clock::now();
	std::chrono::duration<double> diff = end - start;
	std::cout << "[Linear] Or operation: " << diff.count() * 1000 << "ms\n";

	newStatemachine->Squash();

	return std::move(newStatemachine);
}

std::unique_ptr<::deamer::dregx::v2::Statemachine>
deamer::dregx::v2::Statemachine::GeneralOr(const Statemachine& rhs_) const
{
	using std::chrono::system_clock;
	auto start = std::chrono::system_clock::now();
	//
	// With proper assumptions this can be improved:
	//	- Flavors have priority (Present in Lexers)
	//		- Only Linear loops are required with Log(n) lookup (n log n)
	//

	//
	// Initialize the new Statemachine
	//

	const Statemachine& lhs = this->totalStates <= rhs_.totalStates ? *this : rhs_;
	const Statemachine& rhs = rhs_.totalStates >= this->totalStates ? rhs_ : *this;

	auto newStatemachine = std::make_unique<Statemachine>();
	const auto& lhsAlphabet = lhs.mapAlphabetIdWithCharacter;
	const auto& rhsAlphabet = rhs.mapAlphabetIdWithCharacter;

	const auto& lhsFlavor = lhs.mapFlavorIdWithFlavorSet;
	const auto& rhsFlavor = rhs.mapFlavorIdWithFlavorSet;

	// Unify Alphabets
	std::size_t commonAlphaCounter = 0;
	for (auto [lhsId, lhsAlpha] : lhsAlphabet)
	{
		auto iter = newStatemachine->mapCharacterWithAlphabetId.find(lhsAlpha);
		if (iter == newStatemachine->mapCharacterWithAlphabetId.end())
		{
			// New Alphabet
			newStatemachine->mapAlphabetIdWithCharacter.insert({commonAlphaCounter, lhsAlpha});
			newStatemachine->mapCharacterWithAlphabetId.insert({lhsAlpha, commonAlphaCounter});
			commonAlphaCounter++;
		}
	}

	for (auto [rhsId, rhsAlpha] : rhsAlphabet)
	{
		auto iter = newStatemachine->mapCharacterWithAlphabetId.find(rhsAlpha);
		if (iter == newStatemachine->mapCharacterWithAlphabetId.end())
		{
			// New Alphabet
			newStatemachine->mapAlphabetIdWithCharacter.insert({commonAlphaCounter, rhsAlpha});
			newStatemachine->mapCharacterWithAlphabetId.insert({rhsAlpha, commonAlphaCounter});
			commonAlphaCounter++;
		}
	}

	newStatemachine->totalAlphabetSize = commonAlphaCounter;

	const auto roundedLhsTotalStates = nearestPowerOf2(lhs.totalStates);
	const auto roundedRhsTotalStates = nearestPowerOf2(rhs.totalStates);
	const auto log2LhsTotalStates = nearestLogOf2(roundedLhsTotalStates);
	const auto log2RhsTotalStates = nearestLogOf2(roundedRhsTotalStates);
	
	if (log2LhsTotalStates + log2RhsTotalStates + sizeof(char) >= sizeof(std::size_t) * 8)
	{
		throw std::logic_error("Expected target requirement is too large");
	}

	// The target is in safe range and thus more optimal construction is possible
	newStatemachine->totalStates = roundedLhsTotalStates * rhs.totalStates;

	newStatemachine->transitionTable.resize(newStatemachine->totalStates * newStatemachine->totalAlphabetSize);

	std::size_t commonFlavorCounter = 0;
	for (auto [lhsId, lhsFlavor] : lhsFlavor)
	{
		auto iter = newStatemachine->mapFlavorSetWithFlavorId.find(lhsFlavor);
		if (iter == newStatemachine->mapFlavorSetWithFlavorId.end())
		{
			newStatemachine->mapFlavorIdWithFlavorSet.insert({commonFlavorCounter, lhsFlavor});
			newStatemachine->mapFlavorSetWithFlavorId.insert({lhsFlavor, commonFlavorCounter});
			commonFlavorCounter++;
		}
	}

	for (auto [rhsId, rhsFlavor] : rhsFlavor)
	{
		auto iter = newStatemachine->mapFlavorSetWithFlavorId.find(rhsFlavor);
		if (iter == newStatemachine->mapFlavorSetWithFlavorId.end())
		{
			newStatemachine->mapFlavorIdWithFlavorSet.insert({commonFlavorCounter, rhsFlavor});
			newStatemachine->mapFlavorSetWithFlavorId.insert({rhsFlavor, commonFlavorCounter});
			commonFlavorCounter++;
		}
	}

	auto unifySets = [](auto lhs, auto rhs) {
		for (auto element : rhs)
		{
			lhs.insert(element);
		}

		return lhs;
	};

	// Removeable if Flavorings have priority
	for (auto [lhsId, lhsFlavor] : lhsFlavor)
	{
		for (auto [rhsId, rhsFlavor] : rhsFlavor)
		{
			auto unifiedSet = unifySets(lhsFlavor, rhsFlavor);

			auto iter = newStatemachine->mapFlavorSetWithFlavorId.find(unifiedSet);
			if (iter == newStatemachine->mapFlavorSetWithFlavorId.end())
			{
				newStatemachine->mapFlavorIdWithFlavorSet.insert({commonFlavorCounter, unifiedSet});
				newStatemachine->mapFlavorSetWithFlavorId.insert({unifiedSet, commonFlavorCounter});
				commonFlavorCounter++;
			}
		}
	}

	//
	// Fill in state relations
	//

	auto combineState = [&](std::size_t lhsState, std::size_t rhsState) -> std::size_t {
		std::size_t combinedStateIndex =
			(lhsState & lhs.stateMask) |
			((rhsState & rhs.stateMask) << log2LhsTotalStates);
		std::size_t combinedStateType =
			(lhsState & lhs.stateTypeMask) |
			(rhsState & rhs.stateTypeMask);
		std::size_t combinedFlavorType = 
			newStatemachine->mapFlavorSetWithFlavorId.find(unifySets(
			lhs.mapFlavorIdWithFlavorSet.find((
				(lhsState & lhs.stateFlavorMask) >>
				(lhs.reservedStateSpace + lhs.reservedStateTypeSpace)))->second,
			
			rhs.mapFlavorIdWithFlavorSet.find((
				(rhsState & rhs.stateFlavorMask) >>
				(rhs.reservedStateSpace + rhs.reservedStateTypeSpace)))->second
			))->second;

		std::size_t combinedState =
			combinedStateIndex |
			combinedStateType |
			combinedFlavorType <<
				(newStatemachine->reservedStateSpace + newStatemachine->reservedStateTypeSpace)
		;

		return combinedState;
	};

	newStatemachine->startState = combineState(lhs.startState, rhs.startState);
	newStatemachine->sinkState = combineState(lhs.sinkState, rhs.sinkState);

	for (std::size_t alphaI = 0; alphaI < newStatemachine->totalAlphabetSize; alphaI++)
	{
		auto character = newStatemachine->mapAlphabetIdWithCharacter.find(alphaI)->second;
		for (std::size_t stateLhsI = 0; stateLhsI < lhs.totalStates; stateLhsI++)
		{
			auto lhsIter = lhs.mapCharacterWithAlphabetId.find(character);
			std::size_t lhsTargetState = lhs.sinkState;
			
			if (lhsIter != lhs.mapCharacterWithAlphabetId.end())
			{
				lhsTargetState = lhs.transitionTable[(stateLhsI * lhs.totalAlphabetSize) + lhsIter->second];
			}

			for (std::size_t stateRhsI = 0; stateRhsI < rhs.totalStates; stateRhsI++)
			{
				auto combinedCurrentState = combineState(stateLhsI, stateRhsI);

				auto rhsIter = rhs.mapCharacterWithAlphabetId.find(character);
				std::size_t rhsTargetState = rhs.sinkState;

				if (rhsIter != rhs.mapCharacterWithAlphabetId.end())
				{
					rhsTargetState =
						rhs.transitionTable[(stateRhsI * rhs.totalAlphabetSize) + rhsIter->second];
				}
				
				auto combinedTargetState = combineState(lhsTargetState, rhsTargetState);
				newStatemachine
					->transitionTable[(combinedCurrentState & newStatemachine->stateMask) *
										  newStatemachine->totalAlphabetSize +
									  alphaI] = combinedTargetState;
			}
		}
	}

	auto end = std::chrono::system_clock::now();
	std::chrono::duration<double> diff = end - start;
	std::cout << "[General] Or operation: " << diff.count() * 1000 << "ms\n";

	// Squash ensures total state space is closer to optimum
	newStatemachine->Squash();
	return std::move(newStatemachine);
}

void deamer::dregx::v2::Statemachine::And(const Statemachine& rhs)
{
}

void deamer::dregx::v2::Statemachine::Concatenate(const Statemachine& rhs)
{
}

void deamer::dregx::v2::Statemachine::ToDFA()
{
}

void deamer::dregx::v2::Statemachine::Squash()
{
	using std::chrono::system_clock;
	auto start = std::chrono::system_clock::now();
	std::vector<std::size_t> reachedStates;
	reachedStates.resize(totalStates);

	std::vector<std::size_t> evaluatedStates;
	evaluatedStates.reserve(totalStates);
	reachedStates[startState & stateMask] |= static_cast<std::size_t>(1);
	evaluatedStates.push_back(startState & stateMask);

	std::vector<std::size_t> newEvaluatedStates;
	newEvaluatedStates.reserve(totalStates);

	while (!evaluatedStates.empty())
	{
		newEvaluatedStates.clear();

		for (auto currentState : evaluatedStates)
		{
			for (std::size_t alphaI = 0; alphaI < totalAlphabetSize; alphaI++)
			{
				const auto targetState = transitionTable[currentState * totalAlphabetSize + alphaI] & stateMask;

				if (!reachedStates[targetState])
				{
					reachedStates[targetState] |= static_cast<std::size_t>(1);
					newEvaluatedStates.push_back(targetState);
				}
			}
		}

		evaluatedStates = newEvaluatedStates;
	}

	std::vector<std::size_t> redirectionTable;
	redirectionTable.resize(totalStates);

	std::size_t stateCounter = 0;
	for (std::size_t stateI = 0; stateI < totalStates; stateI++)
	{
		if (reachedStates[stateI])
		{
			redirectionTable[stateI] = stateCounter;
			stateCounter++;
		}
		else
		{
			// Will never be used
			redirectionTable[stateI] = std::numeric_limits<std::size_t>::max();
		}
	}

	std::vector<std::size_t> newTransitionTable;
	newTransitionTable.resize(totalStates * totalAlphabetSize);

	startState = redirectionTable[startState & stateMask] |
		(
			(startState & stateTypeMask) |
			(startState & stateFlavorMask)
		);
	sinkState = redirectionTable[sinkState & stateMask] |
		(
			(sinkState & stateTypeMask) |
			(sinkState & stateFlavorMask)
		);

	for (std::size_t stateI = 0; stateI < totalStates; stateI++)
	{
		if (redirectionTable[stateI] == std::numeric_limits<std::size_t>::max())
		{
			continue;
		}

		for (std::size_t alphaI = 0; alphaI < totalAlphabetSize; alphaI++)
		{
			const auto targetState = transitionTable[stateI * totalAlphabetSize + alphaI];
			newTransitionTable[redirectionTable[stateI] * totalAlphabetSize + alphaI] = 
				redirectionTable[targetState & stateMask] |
				(
					(targetState & stateTypeMask) |
					(targetState & stateFlavorMask)
				);
		}
	}

	totalStates = stateCounter;
	transitionTable = newTransitionTable;

	auto end = std::chrono::system_clock::now();
	std::chrono::duration<double> diff = end - start;
	std::cout << "Squash operation: " << diff.count() * 1000 << "ms\n";
}

void deamer::dregx::v2::Statemachine::Minimize()
{
}