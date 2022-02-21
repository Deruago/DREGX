#include "dregx/Ir/Square.h"

dregx::ir::Square::Square() : Capture(CaptureType::square)
{
}

std::string dregx::ir::Square::GetFormattedRegex()
{
	std::string formatted;
	for (auto* subGroup : GetSubGroups())
	{
		formatted += subGroup->GetFormattedRegex();
	}

	return "[" + formatted + "]" + GetExtension().GetFormattedRegex();
}
