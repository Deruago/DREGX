#include "dregx/Ir/EscapeCharacter.h"

dregx::ir::EscapeCharacter::EscapeCharacter(const std::string& letter_)
	: Capture(CaptureType::escapecharacter),
	  letter(letter_)
{
}

std::string dregx::ir::EscapeCharacter::GetEscapedCharacter() const
{
	if (letter == "n")
	{
		return "\n";
	}
	if (letter == "r")
	{
		return "\r";
	}
	if (letter == "t")
	{
		return "\t";
	}

	return letter;
}

std::string dregx::ir::EscapeCharacter::GetFormattedRegex()
{
	return "\\" + letter;
}
