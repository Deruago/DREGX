#ifndef DREGX_IR_CAPTURERANGE_H
#define DREGX_IR_CAPTURERANGE_H

#include "dregx/Ir/Capture.h"
#include <string>

namespace dregx::ir
{
	class CaptureRange : public Capture
	{
	private:
		std::string lowerBoundCharacter;
		std::string upperBoundCharacter;

	public:
		CaptureRange(const std::string& lowerBoundCharacter_,
					 const std::string& upperBoundCharacter_);

	public:
		std::string GetLowerBoundCharacter() const;
		std::string GetUpperBoundCharacter() const;

		std::string GetFormattedRegex() override;

		std::set<char> GetCapturedCharacters() const override;

	private:
	};
}

#endif // DREGX_IR_CAPTURERANGE_H
