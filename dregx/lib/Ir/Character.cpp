#include "dregx/Ir/Character.h"

dregx::ir::Character::Character(const std::string& letter_)
	: Capture(CaptureType::character),
	  letter(letter_)
{
}

std::string dregx::ir::Character::GetFormattedRegex()
{
	return letter;
}

std::set<char> dregx::ir::Character::GetCapturedCharacters() const
{
	return {letter[0]};
}
