#include "dregx/Ir/Extension.h"

dregx::ir::Extension::Extension(std::size_t lowerBound_, std::size_t upperBound_,
								bool infiniteUpperBound_)
	: lowerBound(lowerBound_),
	  upperBound(upperBound_),
	  infiniteUpperBound(infiniteUpperBound_)
{
}

std::size_t dregx::ir::Extension::GetLowerBound() const
{
	return lowerBound;
}

std::size_t dregx::ir::Extension::GetUpperBound() const
{
	return upperBound;
}

bool dregx::ir::Extension::IsUpperBoundInfinite() const
{
	return infiniteUpperBound;
}

std::string dregx::ir::Extension::GetFormattedRegex() const
{
	if (IsUpperBoundInfinite())
	{
		if (lowerBound == 0)
		{
			return "*";
		}
		if (lowerBound == 1)
		{
			return "+";
		}

		return "{" + std::to_string(lowerBound) + ",}";
	}
	if (lowerBound == 1 && upperBound == 1)
	{
		return "";
	}

	return "{" + std::to_string(lowerBound) + "," + std::to_string(upperBound) + "}";
}
