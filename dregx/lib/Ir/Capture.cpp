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
