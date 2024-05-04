#ifndef DEAMER_DREGX_V2_CBStatemachine_H
#define DEAMER_DREGX_V2_CBStatemachine_H

#include "dregx/Statemachine/Statemachine.h"
#include <array>
#include <map>
#include <memory>
#include <set>
#include <string>
#include <vector>
#include <limits>
#include <stdexcept>
#include <type_traits>

namespace dregx::statemachine
{
	class Statemachine;
}

namespace deamer::dregx::v2
{
	/*!	\class CBStatemachine
	 * 
	 * \brief Defines a Compile-time Bounded Statemachine
	 */
	template<std::size_t flavorBitSpace, std::size_t typeBitSpace, typename alphabetIndexType>
	class CBStatemachine
	{
	private:
		using ThisType = CBStatemachine<flavorBitSpace, typeBitSpace, alphabetIndexType>;

		static constexpr std::size_t totalAlphabetSize = 1 << (sizeof(alphabetIndexType) * 8);

		static constexpr std::size_t reservedStateTypeSpace = typeBitSpace;
		static constexpr std::size_t reservedFlavorSpace = flavorBitSpace;
		static constexpr std::size_t reservedStateSpace = sizeof(std::size_t) * 8 - typeBitSpace - flavorBitSpace;

		// Masks are Inferred from reserved spaces
		static constexpr std::size_t stateMask = (static_cast<std::size_t>(1) << reservedStateSpace) - 1;
		static constexpr std::size_t stateTypeMask =  (static_cast<std::size_t>(1) << reservedStateSpace);
		static constexpr std::size_t stateFlavorMask = ~((static_cast<std::size_t>(1) << (reservedStateSpace + reservedStateTypeSpace)) - 1);

	private:
		// Transition Table, inner vector is scaled ahead of time
		// Indexing is always TT[Character][Current State] = Target State
		// I.e. TT[Current State * (1 << sizeof(Character)) + Character] = Target State
		std::vector<std::size_t> transitionTable;
		std::size_t totalStates;

		std::size_t startState;
		std::size_t sinkState;

		bool isCyclic;

	public:
		CBStatemachine(std::unique_ptr<::dregx::statemachine::Statemachine> v1Statemachine, std::size_t flavorValue = 0)
		{
			isCyclic = v1Statemachine->ContainsCycles();

			const auto& otherStates = v1Statemachine->GetStates();
			const auto& otherAlphabet = v1Statemachine->GetAlphabet();

			totalStates = otherStates.size();

			// Alphabet is always reduced to single Characters, V2 will be less expressive then V1,
			// but more performant
			auto findIndex = [&otherStates, this](::dregx::statemachine::State* targetState) -> std::size_t {
				for (std::size_t stateI = 0; stateI < totalStates; stateI++)
				{
					if (otherStates[stateI].get() == targetState)
					{
						return stateI;
					}
				}

				throw std::logic_error("Input Statemachine references non-captured state");
			};

			auto getStateInformation =
				[&](::dregx::statemachine::State* targetState) -> std::size_t {
				auto targetIndex = findIndex(targetState);

				// Guaranteed to be either 1 (accept) or 0 (non accept)
				auto targetAccept = static_cast<std::size_t>(targetState->IsAcceptState() && true);

				auto targetStateInformation = targetIndex | targetAccept << (reservedStateSpace) |
											  (flavorValue
												  << (reservedStateSpace + reservedStateTypeSpace));
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
				// non-conformance anyway. Flavor is not accepting and has no flavors Thus only
				// indicate that it is the final state
				sinkState = totalStates & stateMask |
							(flavorValue << (reservedStateSpace + reservedStateTypeSpace));

				// As a new state is added
				totalStates++;

				std::size_t totalVectorRequirement = totalStates * totalAlphabetSize;
				transitionTable.resize(totalVectorRequirement);

				// For all elements in alphabet make back-loops
				for (std::size_t alphaI = 0; alphaI < totalAlphabetSize; alphaI++)
				{
					transitionTable[(sinkState & stateMask) * totalAlphabetSize + alphaI] = sinkState;
				}
			}

			for (std::size_t alphaI = 0; alphaI < totalAlphabetSize; alphaI++)
			{
				for (std::size_t stateI = 0; stateI < totalStates && stateI < otherStates.size();
					 stateI++)
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
							throw std::logic_error(
								"Detected multiple sink states which is not allowed");
						}
					}

					// Move to Sink State, as there does not exist a proper transition
					transitionTable[stateI * totalAlphabetSize + alphaI] = sinkState;
				}
			}

			for (auto alpha : otherAlphabet)
			{
				for (std::size_t stateI = 0; stateI < totalStates && stateI < otherStates.size();
					 stateI++)
				{
					auto currentState = otherStates[stateI].get();
					auto currentStateInformation = getStateInformation(currentState);

					auto targetStates = currentState->GetConnectedStatesWithConditional(alpha);
					if (targetStates.empty())
					{
						continue;
					}

					// We assume that the input statemachine is a DFA, then only a single state is connected
					auto targetState = (*std::begin(targetStates));

					auto targetStateInformation = getStateInformation(targetState);

					transitionTable[(currentStateInformation & stateMask) * totalAlphabetSize +
									alpha[0].GetCharacter()[0]] = 
						targetStateInformation;
				}
			}
		}

		CBStatemachine(const ThisType& rhs)
			: transitionTable(rhs.transitionTable),
			  totalStates(rhs.totalStates),
			  startState(rhs.startState),
			  sinkState(rhs.sinkState),
			  isCyclic(rhs.isCyclic)
		{
		}

		CBStatemachine() = default;

		virtual ~CBStatemachine() = default;

	public:
		std::size_t GetTotalStates() const
		{
			return totalStates;
		}

		std::vector<std::size_t> GetTransitionTable() const
		{
			return transitionTable;
		}

		std::size_t GetStateIndex(std::size_t state) const
		{
			return state & stateMask;
		}

		bool GetStateAcceptance(std::size_t state) const
		{
			return (state & stateTypeMask) && true;
		}

		std::size_t GetStateFlavor(std::size_t state) const
		{
			return (state & stateFlavorMask) >> (reservedStateSpace + reservedStateTypeSpace);
		}

		std::size_t GetStartState() const
		{
			return startState;
		}

		std::size_t GetSinkState() const
		{
			return sinkState;
		}

	private:
		template<std::size_t evaluatedDepth>
		static constexpr std::size_t nearestLogOf2Impl(std::size_t input)
		{
			if (input <= (static_cast<std::size_t>(1) << evaluatedDepth))
			{
				return evaluatedDepth;
			}

			if constexpr (evaluatedDepth < (sizeof(std::size_t) * 8 - 1))
			{
				return nearestLogOf2Impl<evaluatedDepth + 1>(input);
			}
			else
			{
				throw std::logic_error("Input is too large");
			}
		}

		static constexpr std::size_t nearestLogOf2(std::size_t input)
		{
			return nearestLogOf2Impl<0>(input);
		}

		template<std::size_t evaluatedDepth>
		static constexpr std::size_t nearestPowerOf2Impl(std::size_t input)
		{
			if (input <= (static_cast<std::size_t>(1) << evaluatedDepth))
			{
				return static_cast<std::size_t>(1) << evaluatedDepth;
			}

			if constexpr (evaluatedDepth < (sizeof(std::size_t) * 8 - 1))
			{
				return nearestPowerOf2Impl<evaluatedDepth + 1>(input);
			}
			else
			{
				throw std::logic_error("Input is too large");
			}
		}

		static constexpr std::size_t nearestPowerOf2(std::size_t input)
		{
			return nearestPowerOf2Impl<0>(input);
		}

	public:
		std::unique_ptr<ThisType> Copy() const
		{
			return std::make_unique<ThisType>(*this);
		}

		template<std::size_t rhsFlavorBitSpace, std::size_t rhsTypeBitSpace, typename rhsAlphabetIndexType>
		bool Equal(const CBStatemachine<rhsFlavorBitSpace, rhsTypeBitSpace, rhsAlphabetIndexType>& rhs) const
		{
			if constexpr (
				(flavorBitSpace == rhsFlavorBitSpace) &&
				(typeBitSpace == rhsTypeBitSpace) &&
				(std::is_same_v<alphabetIndexType, rhsAlphabetIndexType>)
			)
			{
				return
					(this->IsCyclic() == rhs.IsCyclic()) &&
					(this->transitionTable == rhs.transitionTable) &&
					(this->totalStates == rhs.totalStates) &&
					(this->startState == rhs.startState) &&
					(this->sinkState == rhs.sinkState)
				;
			}
			else
			{
				return false;
			}
		}

		bool Match(const std::string& actions) const
		{
			if constexpr (std::is_same_v<alphabetIndexType, char>)
			{
				std::size_t currentState = startState;
				for (std::size_t actionI = 0; actionI < actions.size(); actionI++)
				{
					currentState = transitionTable[(currentState & stateMask) * totalAlphabetSize +
												   actions[actionI]];
				}

				// Positive if it is accepting
				const auto result = (currentState & stateTypeMask) && true;

				return result;
			}
			else
			{
				// Alphabets do not match, requires remapping
				return false;
			}
		}

		bool Match(const std::vector<alphabetIndexType>& actions) const
		{
			std::size_t currentState = startState;
			for (std::size_t actionI = 0; actionI < actions.size(); actionI++)
			{
				currentState = transitionTable[(currentState & stateMask) * totalAlphabetSize +
											   actions[actionI]];
			}

			// Positive if it is accepting
			const auto result = (currentState & stateTypeMask) && true;

			return result;
		}

		bool IsCyclic() const
		{
			return isCyclic;
		}

		// Operations
	public:
		template<std::size_t rhsFlavorBitSpace, std::size_t rhsTypeBitSpace, typename rhsAlphabetIndexType>
		std::unique_ptr<ThisType> Or(const CBStatemachine<rhsFlavorBitSpace, rhsTypeBitSpace, rhsAlphabetIndexType>& rhs_) const
		{
			std::unique_ptr<ThisType> result;

			if (this->IsCyclic() && rhs_.IsCyclic())
			{
				// If both are Cyclic only General OR is applicable
				result = GeneralOr(rhs_);
			}
			else if (!this->IsCyclic() && !rhs_.IsCyclic())
			{
				// Linear OR is guaranteed to always work when Linear Splitting is sufficient
				result = LinearOr(rhs_);

				if (result == nullptr)
				{
					// If Linear OR fails, try General OR instead
					result = GeneralOr(rhs_);
				}
			}
			else
			{
				// At least one is Cyclic
				// Linear OR only guarantees correctness if a new branch is produced
				if (this->IsCyclic())
				{
					result = LinearOr(rhs_);
				}
				else
				{
					result = rhs_.LinearOr(*this);
				}

				if (result == nullptr)
				{
					// If Linear OR fails, try General OR instead
					result = GeneralOr(rhs_);
				}
			}

			return result;
		}

		template<std::size_t rhsFlavorBitSpace, std::size_t rhsTypeBitSpace, typename rhsAlphabetIndexType>
		std::unique_ptr<ThisType> LinearOr(const CBStatemachine<rhsFlavorBitSpace, rhsTypeBitSpace, rhsAlphabetIndexType>& rhs_) const
		{
			static_assert(
				std::is_same_v<alphabetIndexType, rhsAlphabetIndexType>,
				"Cannot apply Linear OR on different Alphabetical Compile-time Bounded Automata");

			//
			// Initialize the new Statemachine
			//

			auto newStatemachine = std::make_unique<
				CBStatemachine<std::max(flavorBitSpace, rhsFlavorBitSpace),
							   std::max(typeBitSpace, rhsTypeBitSpace), alphabetIndexType>>();

			// [Non]-Finite Statemachine
			const auto& lhs = *this;
			const auto& rhs = rhs_;

			newStatemachine->isCyclic = lhs.IsCyclic() || rhs.IsCyclic();

			//
			// Fill in lhs states in the new statemachine
			//

			newStatemachine->totalStates = lhs.totalStates + rhs.totalStates;
			newStatemachine->transitionTable.resize((lhs.totalStates + rhs.totalStates) *
													newStatemachine->totalAlphabetSize);

			auto leftMirrorCombineStates = [&](std::size_t lhsState, std::size_t rhsState) -> std::size_t {
				std::size_t combinedStateIndex = lhsState & lhs.stateMask;
				std::size_t combinedStateType =
					(lhsState & lhs.stateTypeMask) | (rhsState & rhs.stateTypeMask);
				std::size_t combinedFlavorType = std::max(
					lhsState & lhs.stateFlavorMask,
					rhsState & rhs.stateFlavorMask
				);

				std::size_t combinedState = combinedStateIndex | combinedStateType | combinedFlavorType;
				return combinedState;
			};

			// The start and sinks are ORred on acceptance
			newStatemachine->startState = leftMirrorCombineStates(lhs.startState, rhs.startState);
			newStatemachine->sinkState = leftMirrorCombineStates(lhs.sinkState, rhs.sinkState);

			std::size_t stateCounter = 0;
			for (std::size_t stateI = 0; stateI < lhs.totalStates; stateI++)
			{
				for (std::size_t alphaI = 0; alphaI < newStatemachine->totalAlphabetSize; alphaI++)
				{
						newStatemachine->transitionTable[
							stateCounter *
							newStatemachine->totalAlphabetSize +
							alphaI
						] =	lhs.transitionTable[stateI * lhs.totalAlphabetSize + alphaI];
				}

				stateCounter++;
			}

			for (std::size_t stateI = 0; stateI < rhs.totalStates; stateI++)
			{
				for (std::size_t alphaI = 0; alphaI < newStatemachine->totalAlphabetSize; alphaI++)
				{
					newStatemachine->transitionTable[
						stateCounter *
						newStatemachine->totalAlphabetSize +
						alphaI
					] = rhs.transitionTable[stateI * rhs.totalAlphabetSize + alphaI] + lhs.totalStates;
				}

				stateCounter++;
			}

			//
			// Bi-simulate Start state
			//

			struct BisimulationPair
			{
				std::size_t lhsState;
				std::size_t rhsState;

				constexpr BisimulationPair(std::size_t lhsState_, std::size_t rhsState_)
					: lhsState(lhsState_),
					  rhsState(rhsState_)
				{
				}

				virtual ~BisimulationPair() = default;
			};

			// Projection is used to constantly check how many unique pairs exists
			std::vector<std::size_t> projection;
			projection.resize(lhs.totalStates);

			std::vector<std::size_t> bisimulativeProjection;
			bisimulativeProjection.resize(lhs.totalStates * rhs.totalStates);

			std::vector<BisimulationPair> bisimulationPairs;
			bisimulationPairs.reserve(lhs.totalStates * rhs.totalStates);

			std::vector<BisimulationPair> reBisimulationPairs;
			reBisimulationPairs.reserve(lhs.totalStates * rhs.totalStates);

			for (std::size_t alphaI = 0; alphaI < newStatemachine->totalAlphabetSize; alphaI++)
			{
				// Lhs does support
				// Rhs does support

				// There are four cases:
				//	Lhs goes to a sink state Rhs goes to a sink state [Nothing to do]
				//	Lhs goes to a sink state Rhs does not go to a sink state [Nothing to do]
				//	Lhs goes to a non sink state Rhs goes to a sink state [Move to Rhs]
				//	Lhs goes to a non sink state Rhs does not go to a sink state [Continue Simulation]
				//

				auto nextLhsState =
					newStatemachine->transitionTable[(newStatemachine->startState &
														newStatemachine->stateMask) *
															newStatemachine->totalAlphabetSize +
														alphaI];

				auto nextRhsState = rhs.transitionTable[(rhs.startState & rhs.stateMask) *
															rhs.totalAlphabetSize +
														alphaI];

				if (nextLhsState == newStatemachine->sinkState && nextRhsState == rhs.sinkState)
				{
					// Nothing to do
				}
				else if (nextLhsState == newStatemachine->sinkState &&
							nextRhsState != rhs.sinkState)
				{
					// Update to Rhs
					newStatemachine->transitionTable[(newStatemachine->startState &
														newStatemachine->stateMask) *
															newStatemachine->totalAlphabetSize +
														alphaI] =
						rhs.transitionTable[(rhs.startState & rhs.stateMask) *
												rhs.totalAlphabetSize +
											alphaI] +
						lhs.totalStates;
				}
				else if (nextLhsState != newStatemachine->sinkState &&
							nextRhsState == rhs.sinkState)
				{
					// Nothing to do
				}
				else
				{
					// Continue Simulation
					//
					// Two cases:
					//		- Projection is already filled, [Quadratic Splitting] (Error)
					//		- Projection is not filled,     [Linear Splitting]
					//

					std::size_t bisimulativeIndex =
						(nextLhsState & lhs.stateMask) * (nextRhsState & rhs.stateMask);

					newStatemachine->transitionTable[(newStatemachine->startState &
													  newStatemachine->stateMask) *
														 newStatemachine->totalAlphabetSize +
													 alphaI] =
						leftMirrorCombineStates(
							newStatemachine
								->transitionTable[(newStatemachine->startState &
												   newStatemachine->stateMask) *
													  newStatemachine->totalAlphabetSize +
												  alphaI],
							rhs.transitionTable[(rhs.startState & rhs.stateMask) *
													 rhs.totalAlphabetSize +
												 alphaI]);

					if (bisimulativeProjection[bisimulativeIndex] == 0)
					{
						bisimulativeProjection[bisimulativeIndex] |= 1;
						projection[nextLhsState & lhs.stateMask] += 1;
						bisimulationPairs.emplace_back(nextLhsState, nextRhsState);
					}

					if (projection[nextLhsState & lhs.stateMask] > 1)
					{
						// Requires Quadratic Splitting
						return nullptr;
					}
				}
			}

			while (!bisimulationPairs.empty())
			{
				reBisimulationPairs.clear();

				// Evaluate bisimulation pairs
				for (const auto& bisimulationPair : bisimulationPairs)
				{
					std::size_t bisimulativeIndex = (bisimulationPair.lhsState & lhs.stateMask) *
													(bisimulationPair.rhsState & rhs.stateMask);
					bisimulativeProjection[bisimulativeIndex] = 0;
					projection[bisimulationPair.lhsState & lhs.stateMask] = 0;
				}

				for (const auto& bisimulationPair : bisimulationPairs)
				{
					for (std::size_t alphaI = 0; alphaI < newStatemachine->totalAlphabetSize;
						 alphaI++)
					{
						// Lhs does support
						// Rhs does support
						//
						// There are four cases:
						//	Lhs goes to a sink state Rhs goes to a sink state [Nothing to do]
						//	Lhs goes to a sink state Rhs does not go to a sink state [Nothing todo]
						//  Lhs goes to a non sink state Rhs goes to a sink state [Move to Rhs]
						//  Lhs goes to a non sink state Rhs does not go to a sink state [Continue Simulation]
						//

						auto nextLhsState =
							newStatemachine
								->transitionTable[(bisimulationPair.lhsState &
													newStatemachine->stateMask) *
														newStatemachine->totalAlphabetSize +
													alphaI];

						auto nextRhsState =
							rhs.transitionTable[(bisimulationPair.rhsState & rhs.stateMask) *
													rhs.totalAlphabetSize +
												alphaI];

						if (nextLhsState == newStatemachine->sinkState &&
							nextRhsState == rhs.sinkState)
						{
							// Nothing to do
						}
						else if (nextLhsState == newStatemachine->sinkState &&
									nextRhsState != rhs.sinkState)
						{
							// Update to Rhs
							newStatemachine
								->transitionTable[(bisimulationPair.lhsState &
													newStatemachine->stateMask) *
														newStatemachine->totalAlphabetSize +
													alphaI] =
								rhs.transitionTable[(bisimulationPair.rhsState &
														rhs.stateMask) *
														rhs.totalAlphabetSize +
													alphaI] +
								lhs.totalStates;
						}
						else if (nextLhsState != newStatemachine->sinkState &&
									nextRhsState == rhs.sinkState)
						{
							// Only valid if original machine is not Cyclic to guarantee correctness
							// Possible to remove is there is a notion of cyclicity in state information
							// Then this is reducable to checking if the state is part of a cycle
							if (lhs.IsCyclic() || rhs.IsCyclic())
							{
								return nullptr;
							}
						}
						else
						{
							// Continue Simulation
							//
							// Two cases:
							//		- Projection is already filled, [Quadratic Splitting] (Error)
							//		- Projection is not filled,     [Linear Splitting]
							//

							if ((nextLhsState & lhs.stateMask) >= lhs.totalStates)
							{
								// It is a cycle and unrolling is not allowed
								return nullptr;
							}

							std::size_t bisimulativeIndex =
								(nextLhsState & lhs.stateMask) * (nextRhsState & rhs.stateMask);

							newStatemachine
								->transitionTable[(bisimulationPair.lhsState &
													newStatemachine->stateMask) *
														newStatemachine->totalAlphabetSize +
												  alphaI] =
								leftMirrorCombineStates(
									newStatemachine
										->transitionTable[(bisimulationPair.lhsState &
														   newStatemachine->stateMask) *
															  newStatemachine->totalAlphabetSize +
														  alphaI],
									rhs.transitionTable[(bisimulationPair.rhsState &
														   rhs.stateMask) *
															  rhs.totalAlphabetSize +
														  alphaI]);

							if (bisimulativeProjection[bisimulativeIndex] == 0)
							{
								bisimulativeProjection[bisimulativeIndex] |= 1;
								projection[nextLhsState & lhs.stateMask] += 1;
								reBisimulationPairs.emplace_back(nextLhsState, nextRhsState);
							}

							if (projection[nextLhsState & lhs.stateMask] > 1)
							{
								// Requires Quadratic Splitting
								return nullptr;
							}
						}
					}
				}

				bisimulationPairs = reBisimulationPairs;
			}

			// As the resulting machine is additively constructed,
			// It does not consume a lot of space that is squashable
			// So the result will not be Squashed
			// newStatemachine->Squash();

			return std::move(newStatemachine);
		}

		template<std::size_t rhsFlavorBitSpace, std::size_t rhsTypeBitSpace,
				 typename rhsAlphabetIndexType>
		std::unique_ptr<ThisType>
			GeneralOr(const CBStatemachine<rhsFlavorBitSpace, rhsTypeBitSpace, rhsAlphabetIndexType>& rhs_) const
		{
			static_assert(std::is_same_v<alphabetIndexType, rhsAlphabetIndexType>, "Cannot apply General OR on different Alphabetical Compile-time Bounded Automata");

			//
			// Initialize the new Statemachine
			//

			const auto& lhs = this->totalStates <= rhs_.totalStates ? *this : rhs_;
			const auto& rhs = rhs_.totalStates >= this->totalStates ? rhs_ : *this;

			auto newStatemachine = std::make_unique<CBStatemachine<
				std::max(flavorBitSpace, rhsFlavorBitSpace),
				std::max(typeBitSpace, rhsTypeBitSpace),
				alphabetIndexType
			>>();
			newStatemachine->isCyclic = lhs.IsCyclic() || rhs.IsCyclic();

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

			newStatemachine->transitionTable.resize(newStatemachine->totalStates *
													newStatemachine->totalAlphabetSize);

			//
			// Fill in state relations
			//

			auto combineState = [&](std::size_t lhsState, std::size_t rhsState) -> std::size_t {
				std::size_t combinedStateIndex =
					(lhsState & lhs.stateMask) | ((rhsState & rhs.stateMask) << log2LhsTotalStates);
				std::size_t combinedStateType =
					(lhsState & lhs.stateTypeMask) | (rhsState & rhs.stateTypeMask);
				std::size_t combinedFlavorType = std::max(
					lhsState & lhs.stateFlavorMask,
					rhsState & rhs.stateFlavorMask
				);

				std::size_t combinedState = combinedStateIndex | combinedStateType | combinedFlavorType;

				return combinedState;
			};

			newStatemachine->startState = combineState(lhs.startState, rhs.startState);
			newStatemachine->sinkState = combineState(lhs.sinkState, rhs.sinkState);

			for (std::size_t alphaI = 0; alphaI < newStatemachine->totalAlphabetSize; alphaI++)
			{
				for (std::size_t stateLhsI = 0; stateLhsI < lhs.totalStates; stateLhsI++)
				{
					std::size_t lhsTargetState =
						lhs.transitionTable[(stateLhsI * lhs.totalAlphabetSize) + alphaI];

					for (std::size_t stateRhsI = 0; stateRhsI < rhs.totalStates; stateRhsI++)
					{
						auto combinedCurrentState = combineState(stateLhsI, stateRhsI);
						
						std::size_t rhsTargetState =
							rhs.transitionTable[(stateRhsI * rhs.totalAlphabetSize) + alphaI];

						auto combinedTargetState = combineState(lhsTargetState, rhsTargetState);
						newStatemachine
							->transitionTable[(combinedCurrentState & newStatemachine->stateMask) *
												  newStatemachine->totalAlphabetSize +
											  alphaI] = combinedTargetState;
					}
				}
			}

			// Squash ensures total state space is closer to optimum
			newStatemachine->Squash();

			return std::move(newStatemachine);
		}

		template<std::size_t rhsFlavorBitSpace, std::size_t rhsTypeBitSpace, typename rhsAlphabetIndexType>
		std::unique_ptr<ThisType> And(const CBStatemachine<rhsFlavorBitSpace, rhsTypeBitSpace, rhsAlphabetIndexType>& rhs_)
		{
			std::unique_ptr<ThisType> result;

			result = GeneralAnd(rhs_);

			return result;
		}

		template<std::size_t rhsFlavorBitSpace, std::size_t rhsTypeBitSpace, typename rhsAlphabetIndexType>
		std::unique_ptr<ThisType> GeneralAnd(const CBStatemachine<rhsFlavorBitSpace, rhsTypeBitSpace, rhsAlphabetIndexType>& rhs_)
		{
			static_assert(
				std::is_same_v<alphabetIndexType, rhsAlphabetIndexType>,
				"Cannot apply General OR on different Alphabetical Compile-time Bounded Automata");

			//
			// Initialize the new Statemachine
			//

			const auto& lhs = this->totalStates <= rhs_.totalStates ? *this : rhs_;
			const auto& rhs = rhs_.totalStates >= this->totalStates ? rhs_ : *this;

			auto newStatemachine = std::make_unique<
				CBStatemachine<std::max(flavorBitSpace, rhsFlavorBitSpace),
							   std::max(typeBitSpace, rhsTypeBitSpace), alphabetIndexType>>();

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

			newStatemachine->transitionTable.resize(newStatemachine->totalStates *
													newStatemachine->totalAlphabetSize);

			//
			// Fill in state relations
			//

			auto combineState = [&](std::size_t lhsState, std::size_t rhsState) -> std::size_t {
				std::size_t combinedStateIndex =
					(lhsState & lhs.stateMask) | ((rhsState & rhs.stateMask) << log2LhsTotalStates);
				std::size_t combinedStateType =
					(lhsState & lhs.stateTypeMask) & (rhsState & rhs.stateTypeMask);
				std::size_t combinedFlavorType =
					std::max(lhsState & lhs.stateFlavorMask, rhsState & rhs.stateFlavorMask);

				std::size_t combinedState = combinedStateIndex | combinedStateType | combinedFlavorType;

				return combinedState;
			};

			newStatemachine->startState = combineState(lhs.startState, rhs.startState);
			newStatemachine->sinkState = combineState(lhs.sinkState, rhs.sinkState);

			for (std::size_t alphaI = 0; alphaI < newStatemachine->totalAlphabetSize; alphaI++)
			{
				for (std::size_t stateLhsI = 0; stateLhsI < lhs.totalStates; stateLhsI++)
				{
					std::size_t lhsTargetState =
						lhs.transitionTable[(stateLhsI * lhs.totalAlphabetSize) + alphaI];

					for (std::size_t stateRhsI = 0; stateRhsI < rhs.totalStates; stateRhsI++)
					{
						auto combinedCurrentState = combineState(stateLhsI, stateRhsI);

						std::size_t rhsTargetState =
							rhs.transitionTable[(stateRhsI * rhs.totalAlphabetSize) + alphaI];

						auto combinedTargetState = combineState(lhsTargetState, rhsTargetState);
						newStatemachine
							->transitionTable[(combinedCurrentState & newStatemachine->stateMask) *
												  newStatemachine->totalAlphabetSize +
											  alphaI] = combinedTargetState;
					}
				}
			}

			// Squash ensures total state space is closer to optimum
			newStatemachine->Squash();

			// And produces less alive branches thus this is more performant for AND in general
			newStatemachine->DeadBranchRemoval();

			return std::move(newStatemachine);
		}

		template<std::size_t rhsFlavorBitSpace, std::size_t rhsTypeBitSpace, typename rhsAlphabetIndexType>
		std::unique_ptr<ThisType> Concatenate(const CBStatemachine<rhsFlavorBitSpace, rhsTypeBitSpace, rhsAlphabetIndexType>& rhs)
		{
			auto newStatemachine = std::make_unique<ThisType>();
			return newStatemachine;
		}

	public:
		void ToDFA()
		{
			// Already in DFA
		}

		// Minimizes current state space
		//	- Removes unreachable states
		void Squash()
		{
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
						const auto targetState =
							transitionTable[currentState * totalAlphabetSize + alphaI] & stateMask;

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
			newTransitionTable.resize(stateCounter * totalAlphabetSize);

			startState = redirectionTable[startState & stateMask] |
						 ((startState & stateTypeMask) | (startState & stateFlavorMask));
			sinkState = redirectionTable[sinkState & stateMask] |
						((sinkState & stateTypeMask) | (sinkState & stateFlavorMask));

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
						((targetState & stateTypeMask) | (targetState & stateFlavorMask));
				}
			}

			totalStates = stateCounter;
			transitionTable = newTransitionTable;
		}

		/*!	\function DeadBranchRemoval
		 * 
		 *	\brief Removes states that will never reach an accepting state
		 */
		void DeadBranchRemoval()
		{
			// Make total x total, where previous[lhs x rhs] represents if lhs is before rhs
			std::vector<bool> previous;
			previous.resize(totalStates * totalStates);

			std::vector<bool> acceptProjection;
			acceptProjection.resize(totalStates);

			std::vector<std::size_t> acceptedStates;
			acceptedStates.reserve(totalStates);

			std::vector<std::size_t> unacceptedStates;
			unacceptedStates.reserve(totalStates);

			std::vector<std::size_t> reUnacceptedStates;
			reUnacceptedStates.reserve(totalStates);

			for (std::size_t stateI = 0; stateI < totalStates; stateI++)
			{
				for (std::size_t alphaI = 0; alphaI < totalAlphabetSize; alphaI++)
				{
					const std::size_t targetStateI =
						transitionTable[stateI * totalAlphabetSize + alphaI];
					const std::size_t targetStateIndex = targetStateI & stateMask;
					const std::size_t targetStateAccept = targetStateI & stateTypeMask;
					
					previous[stateI * totalStates + targetStateIndex] = true;
					
					if (targetStateAccept)
					{
						acceptProjection[targetStateIndex] = true;
						acceptProjection[stateI] = true; // As it is connected to something that is accepting
					}
				}
			}

			for (std::size_t stateI = 0; stateI < totalStates; stateI++)
			{
				if (!acceptProjection[stateI] && (stateI != (sinkState & stateMask)))
				{
					unacceptedStates.push_back(stateI);
				}
			}

			std::size_t lastStateSize = 0;
			std::size_t currentStateSize = unacceptedStates.size();
			while (!unacceptedStates.empty() && lastStateSize != currentStateSize)
			{
				reUnacceptedStates.clear();

				for (auto unacceptedState : unacceptedStates)
				{
					for (std::size_t alphaI = 0; alphaI < totalAlphabetSize; alphaI++)
					{
						const std::size_t targetStateI =
							transitionTable[unacceptedState * totalAlphabetSize + alphaI];
						const std::size_t targetStateIndex = targetStateI & stateMask;
						const std::size_t targetStateAccept = targetStateI & stateTypeMask;

						if (acceptProjection[targetStateI])
						{
							acceptProjection[unacceptedState] = true;
							break;
						}
					}
					
					if (!acceptProjection[unacceptedState])
					{
						reUnacceptedStates.push_back(unacceptedState);
					}
				}

				unacceptedStates = reUnacceptedStates;

				lastStateSize = currentStateSize;
				currentStateSize = unacceptedStates.size();
			}

			if (unacceptedStates.empty())
			{
				// Everything is eventually alive
				return;
			}

			// Sink state is always good, as it was not used as an excuse to pass previous test
			acceptProjection[sinkState & stateMask] = true;

			// Start state should be different than Sink state to ensure proper continuation
			acceptProjection[startState & stateMask] = true;

			// Unaccepted states now define the states that will never reach an accepting state
			std::vector<std::size_t> redirectionTable;
			redirectionTable.resize(totalStates);

			std::size_t stateCounter = 0;
			for (std::size_t stateI = 0; stateI < totalStates; stateI++)
			{
				if (acceptProjection[stateI])
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

			// Sink state influenced result
			if (totalStates == stateCounter)
			{
				return;
			}
			std::vector<std::size_t> newTransitionTable;
			newTransitionTable.resize(stateCounter * totalAlphabetSize);

			startState = redirectionTable[startState & stateMask] |
						 ((startState & stateTypeMask) | (startState & stateFlavorMask));
			sinkState = redirectionTable[sinkState & stateMask] |
						((sinkState & stateTypeMask) | (sinkState & stateFlavorMask));

			for (std::size_t stateI = 0; stateI < totalStates; stateI++)
			{
				if (redirectionTable[stateI] == std::numeric_limits<std::size_t>::max())
				{
					continue;
				}

				for (std::size_t alphaI = 0; alphaI < totalAlphabetSize; alphaI++)
				{
					const auto targetState = transitionTable[stateI * totalAlphabetSize + alphaI];
					if (!acceptProjection[targetState & stateMask])
					{
						// Go to sink state instead of going n states with no possibility of acceptance
						newTransitionTable[redirectionTable[stateI] * totalAlphabetSize + alphaI] =
							sinkState;
					}
					else
					{
						newTransitionTable[redirectionTable[stateI] * totalAlphabetSize + alphaI] =
							redirectionTable[targetState & stateMask] |
							((targetState & stateTypeMask) | (targetState & stateFlavorMask));
					}
				}
			}

			totalStates = stateCounter;
			transitionTable = newTransitionTable;
		}

		void Minimize()
		{
			Squash();
			DeadBranchRemoval();
		}

		bool IsEmptyLanguage() const noexcept
		{
			if (totalStates > 2)
			{
				// More states is not possible with Squash DBR
				return false;
			}

			if (sinkState & stateTypeMask)
			{
				// Sink state may not be accepting
				return false;
			}

			for (std::size_t stateAlphaI = 0; stateAlphaI < transitionTable.size(); stateAlphaI++)
			{
				if (transitionTable[stateAlphaI] != sinkState)
				{
					// Not pointing to sink state includes possibility of matching non-epsilon after Squash + DBR
					return false;
				}
			}

			// Guaranteed to be Epsilon
			return true;
		}
	};
}

#endif // DEAMER_DREGX_V2_CBStatemachine_H
