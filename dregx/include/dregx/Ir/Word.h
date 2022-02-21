#ifndef DREGX_IR_WORD_H
#define DREGX_IR_WORD_H

#include "dregx/Ir/Capture.h"

namespace dregx::ir
{
	class Word : public Capture
	{
	private:
		std::string word;

	public:
		Word();
		void SetWord(const std::string& word_);
		std::string GetWord() const;

		std::string GetFormattedRegex() override;
	};
}

#endif // DREGX_IR_WORD_H
