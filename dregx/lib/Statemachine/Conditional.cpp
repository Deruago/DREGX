#include "dregx/Statemachine/Conditional.h"

dregx::statemachine::Conditional::Conditional(const std::string& character_) : character(character_)
{
}

std::string dregx::statemachine::Conditional::GetCharacter() const
{
	return character;
}

bool dregx::statemachine::Conditional::operator==(const Conditional& rhs) const noexcept
{
	if (&rhs == this)
	{
		return true;
	}

	return rhs.GetCharacter() == this->GetCharacter();
}

bool dregx::statemachine::Conditional::operator<(const Conditional& rhs) const noexcept
{
	if (&rhs == this)
	{
		return false;
	}

	return rhs.GetCharacter() < this->GetCharacter();
}

bool dregx::statemachine::Conditional::operator>(const Conditional& rhs) const noexcept
{
	if (&rhs == this)
	{
		return false;
	}

	return rhs.GetCharacter() > this->GetCharacter();
}

dregx::statemachine::Conditional&
dregx::statemachine::Conditional::operator=(const Conditional& rhs)
{
	if (&rhs == this)
	{
		return *this;
	}

	this->character = rhs.character;

	return *this;
}
