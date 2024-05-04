#include "dregx/Ir/CaptureRange.h"

dregx::ir::CaptureRange::CaptureRange(const std::string& lowerBoundCharacter_,
									  const std::string& upperBoundCharacter_)
	: Capture(CaptureType::capturerange),
	  lowerBoundCharacter(lowerBoundCharacter_),
	  upperBoundCharacter(upperBoundCharacter_)
{
}

std::string dregx::ir::CaptureRange::GetLowerBoundCharacter() const
{
	return lowerBoundCharacter;
}

std::string dregx::ir::CaptureRange::GetUpperBoundCharacter() const
{
	return upperBoundCharacter;
}

std::string dregx::ir::CaptureRange::GetFormattedRegex()
{
	return lowerBoundCharacter + "-" + upperBoundCharacter;
}

std::set<char> dregx::ir::CaptureRange::GetCapturedCharacters() const
{
	std::set<char> result;

	for (char lower = lowerBoundCharacter[0]; lower < upperBoundCharacter[0]; lower++)
	{
		result.insert({lower});
	}

	return result;
}
