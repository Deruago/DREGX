#ifndef DREGX_IR_CHARACTER_H
#define DREGX_IR_CHARACTER_H

#include "dregx/Ir/Capture.h"
#include <string>

namespace dregx::ir
{
	class Character : public Capture
	{
	private:
		std::string letter;

	public:
		Character(const std::string& letter_);

	public:
		std::string GetFormattedRegex() override;

	private:
	};
}

#endif // DREGX_IR_CHARACTER_H
