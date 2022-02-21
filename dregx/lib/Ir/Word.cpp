#include "dregx/Ir/Word.h"

dregx::ir::Word::Word() : Capture(CaptureType::word)
{
}

void dregx::ir::Word::SetWord(const std::string& word_)
{
	word = word_;
}

std::string dregx::ir::Word::GetWord() const
{
	return word;
}

std::string dregx::ir::Word::GetFormattedRegex()
{
	return GetWord();
}
