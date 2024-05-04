#include "dregx/Ir/Capture.h"

dregx::ir::Capture::Capture(CaptureType captureType_)
	: captureType(captureType_),
	  extension(1, 1, false)
{
}

dregx::ir::Capture::~Capture()
{
	for (auto* subGroup : subGroups)
	{
		delete subGroup;
	}
}

void dregx::ir::Capture::SetExtension(Extension extension_)
{
	extension = extension_;
}

void dregx::ir::Capture::AddSubCapture(Capture* subGroup_)
{
	subGroups.push_back(subGroup_);
}

void dregx::ir::Capture::ClearSubGroups()
{
	subGroups.clear();
}

dregx::ir::CaptureType dregx::ir::Capture::GetCaptureType() const
{
	return captureType;
}

dregx::ir::Extension dregx::ir::Capture::GetExtension() const
{
	return extension;
}

std::vector<dregx::ir::Capture*> dregx::ir::Capture::GetSubGroups() const
{
	return subGroups;
}

std::string dregx::ir::Capture::GetFormattedRegex()
{
	std::string formatted;
	for (auto* subGroup : subGroups)
	{
		formatted += subGroup->GetFormattedRegex();
	}

	return formatted;
}

void dregx::ir::Capture::AddFlavor(const std::string& flavor)
{
	if (flavor.empty())
	{
		return;
	}
	flavors.insert(flavor);
}

void dregx::ir::Capture::RemoveFlavor(const std::string& flavor)
{
	flavors.erase(flavor);
}

std::set<std::string> dregx::ir::Capture::GetFlavors() const
{
	return flavors;
}

std::set<char> dregx::ir::Capture::GetCapturedCharacters() const
{
	std::set<char> combined;
	for (auto subGroup : GetSubGroups())
	{
		for (auto element : subGroup->GetCapturedCharacters())
		{
			combined.insert({element});
		}
	}
	return combined;
}
