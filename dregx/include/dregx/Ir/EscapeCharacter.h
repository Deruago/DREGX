#ifndef DREGX_IR_ESCAPECHARACTER_H
#define DREGX_IR_ESCAPECHARACTER_H

#include "dregx/Ir/Capture.h"
#include <string>

namespace dregx::ir
{
	class EscapeCharacter : public Capture
	{
	private:
		std::string letter;

	public:
		EscapeCharacter(const std::string& letter_);

	public:
		/*!	\fn GetEscapedCharacter
		 *
		 *	\brief Returns the escaped character.
		 *	\details
		 *		The escaped character '\n' will return a linefeed character
		 *		The escaped character '\q' will return a 'q'
		 */
		std::string GetEscapedCharacter() const;

		std::string GetFormattedRegex() override;

	private:
	};
}

#endif // DREGX_IR_ESCAPECHARACTER_H
