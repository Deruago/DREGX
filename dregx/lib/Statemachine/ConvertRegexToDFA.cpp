#include "dregx/Statemachine/ConvertRegexToDFA.h"
#include "dregx/Ir/Capture.h"
#include "dregx/Ir/CaptureRange.h"
#include "dregx/Ir/Character.h"
#include "dregx/Ir/Group.h"
#include "dregx/Ir/OrGroup.h"
#include "dregx/Ir/Square.h"
#include "dregx/Ir/Word.h"

std::unique_ptr<dregx::statemachine::Statemachine>
dregx::statemachine::ConvertRegexToDFA::ConvertToStatemachine(ir::Capture* capture, bool embed)
{
	std::unique_ptr<dregx::statemachine::Statemachine> newStatemachine = nullptr;
	switch (capture->GetCaptureType())
	{
	case ir::CaptureType::group: {
		newStatemachine = ConvertToStatemachine(static_cast<ir::Group*>(capture), true);
		break;
	}
	case ir::CaptureType::square: {
		newStatemachine = ConvertToStatemachine(static_cast<ir::Square*>(capture), true);
		break;
	}
	case ir::CaptureType::word: {
		newStatemachine = ConvertToStatemachine(static_cast<ir::Word*>(capture), true);
		break;
	}
	case ir::CaptureType::orgroup: {
		newStatemachine = ConvertToStatemachine(static_cast<ir::OrGroup*>(capture), true);
		break;
	}
	case ir::CaptureType::character:
	case ir::CaptureType::escapecharacter:
	case ir::CaptureType::capturerange: {
		auto tmpSquare = std::make_unique<ir::Square>();
		tmpSquare->AddSubCapture(capture);
		auto newStatemachine_ = ConvertToStatemachine(tmpSquare.get(), true);
		tmpSquare->ClearSubGroups();
		newStatemachine = std::move(newStatemachine_);
		break;
	}
	case ir::CaptureType::unknown: {
		newStatemachine = nullptr;
		break;
	}
	}

	if (!embed && newStatemachine != nullptr)
	{
		newStatemachine->ToDFA();
		// newStatemachine->OptimizeFinalAcceptStates();
	}

	return newStatemachine;
}

std::unique_ptr<dregx::statemachine::Statemachine>
dregx::statemachine::ConvertRegexToDFA::ConvertToStatemachine(ir::Group* group, bool embed)
{
	if (group->GetSubGroups().empty())
	{
		return std::make_unique<dregx::statemachine::Statemachine>();
	}

	std::unique_ptr<dregx::statemachine::Statemachine> currentStatemachine =
		ConvertToStatemachine(group->GetSubGroups()[0], true);
	for (auto i = 1; i < group->GetSubGroups().size(); i++)
	{
		const auto currentCapture = group->GetSubGroups()[i];
		auto newStatemachine = ConvertToStatemachine(currentCapture, true);
		currentStatemachine->Concatenate(*newStatemachine);
	}
	currentStatemachine->Extend(group->GetExtension());

	return currentStatemachine;
}

std::unique_ptr<dregx::statemachine::Statemachine>
dregx::statemachine::ConvertRegexToDFA::ConvertToStatemachine(ir::OrGroup* orGroup, bool embed)
{
	if (orGroup->GetSubGroups().empty())
	{
		return std::make_unique<dregx::statemachine::Statemachine>();
	}

	std::unique_ptr<dregx::statemachine::Statemachine> currentStatemachine =
		ConvertToStatemachine(orGroup->GetSubGroups()[0], true);
	for (auto i = 1; i < orGroup->GetSubGroups().size(); i++)
	{
		const auto currentCapture = orGroup->GetSubGroups()[i];
		auto newStatemachine = ConvertToStatemachine(currentCapture, true);
		currentStatemachine->Or(*newStatemachine);
	}

	return currentStatemachine;
}

std::unique_ptr<dregx::statemachine::Statemachine>
dregx::statemachine::ConvertRegexToDFA::ConvertToStatemachine(ir::Square* square, bool embed)
{
	auto statemachine = std::make_unique<dregx::statemachine::Statemachine>();
	auto states = std::vector<std::unique_ptr<State>>();
	auto transitions = std::vector<std::unique_ptr<Transition>>();
	auto startState = std::make_unique<State>();
	startState->SetStart(true);

	// Multiple transitions to 1 accept state
	auto acceptState = std::make_unique<State>();
	acceptState->SetAccept(true);

	for (auto* capture : square->GetSubGroups())
	{
		if (capture->GetCaptureType() == ir::CaptureType::capturerange)
		{
			const auto captureRange = static_cast<ir::CaptureRange*>(capture);
			if (captureRange->GetLowerBoundCharacter().size() != 1 ||
				captureRange->GetUpperBoundCharacter().size() != 1)
			{
				continue;
			}

			for (char i = captureRange->GetLowerBoundCharacter().c_str()[0];
				 i < captureRange->GetUpperBoundCharacter().c_str()[0]; i++)
			{
				std::string regex;
				regex += i;

				if (startState->DoesOutTransitionExist({regex}, acceptState.get()))
				{
					continue;
				}
				auto newTransition = std::make_unique<Transition>(
					startState.get(), std::vector<Conditional>{regex}, acceptState.get());
				transitions.push_back(std::move(newTransition));
			}
		}
		else
		{
			if (startState->DoesOutTransitionExist({capture->GetFormattedRegex()},
												   acceptState.get()))
			{
				continue;
			}
			auto newTransition = std::make_unique<Transition>(
				startState.get(), std::vector<Conditional>{capture->GetFormattedRegex()},
				acceptState.get());
			transitions.push_back(std::move(newTransition));
		}
	}

	states.push_back(std::move(startState));
	states.push_back(std::move(acceptState));
	statemachine->SetStates(std::move(states));
	statemachine->SetTransitions(std::move(transitions));
	statemachine->Extend(square->GetExtension());

	return std::move(statemachine);
}

std::unique_ptr<dregx::statemachine::Statemachine>
dregx::statemachine::ConvertRegexToDFA::ConvertToStatemachine(ir::Word* word, bool embed)
{
	if (word->GetWord().empty())
	{
		return std::make_unique<dregx::statemachine::Statemachine>();
	}

	std::string regex;
	regex += word->GetWord()[0];
	ir::Character character(regex);
	std::unique_ptr<dregx::statemachine::Statemachine> currentStatemachine =
		ConvertToStatemachine(&character, true);
	for (auto i = 1; i < word->GetSubGroups().size(); i++)
	{
		std::string regex_;
		regex += word->GetWord()[i];
		ir::Character character_(regex);

		auto newStatemachine = ConvertToStatemachine(&character_, true);
		currentStatemachine->Concatenate(*newStatemachine);
	}

	return currentStatemachine;
}
