#include "dregx/Ir/NotCapture.h"
#include "dregx/Ir/Character.h"
#include <memory>

dregx::ir::NotCapture::NotCapture()
	: Capture(CaptureType::notcapture)
{
}


std::string dregx::ir::NotCapture::GetFormattedRegex()
{
	return "^";
}

std::set<char> dregx::ir::NotCapture::GetCapturedCharacters() const
{
	std::set<char> combined;
	for (auto subGroup : dregx::ir::Capture::GetSubGroups())
	{
		for (auto element : subGroup->GetCapturedCharacters())
		{
			combined.insert({element});
		}
	}

	std::set<char> except;
	for (std::size_t i = 0; i < (static_cast<std::size_t>(1) << (sizeof(char) * 8 - 1)); i++)
	{
		if (combined.find(static_cast<char>(i)) == combined.end())
		{
			except.insert({static_cast<char>(i)});
		}
	}

	return except;
}

std::vector<dregx::ir::Capture*> dregx::ir::NotCapture::GetSubGroups() const
{
	if (!newSubGroups.empty())
	{
		return newSubGroups;
	}

	for (auto character : GetCapturedCharacters())
	{
		std::string result;
		result += character;

		auto newCharacter = std::make_unique<dregx::ir::Character>(result);
		newSubGroups.push_back(newCharacter.get());
		newSubGroupsOwned.push_back(std::move(newCharacter));
	}

	return newSubGroups;
}
