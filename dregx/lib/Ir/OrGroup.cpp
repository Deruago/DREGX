#include "dregx/Ir/OrGroup.h"

dregx::ir::OrGroup::OrGroup() : Capture(CaptureType::orgroup)
{
}

std::string dregx::ir::OrGroup::GetFormattedRegex()
{
	std::string formatted;
	bool first = true;
	for (auto* subGroup : GetSubGroups())
	{
		if (first)
		{
			first = false;
		}
		else
		{
			formatted += "|";
		}
		formatted += subGroup->GetFormattedRegex();
	}

	return formatted;
}
