#include "dregx/Ir/Group.h"

dregx::ir::Group::Group() : Capture(CaptureType::group)
{
}

std::string dregx::ir::Group::GetFormattedRegex()
{
	std::string formatted;
	for (auto* subGroup : GetSubGroups())
	{
		formatted += subGroup->GetFormattedRegex();
	}

	return "(" + formatted + ")" + GetExtension().GetFormattedRegex();
}
