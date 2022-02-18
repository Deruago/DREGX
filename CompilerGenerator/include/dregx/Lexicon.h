/* 
 * This file is auto-generated and auto-maintained by DLDL
 * Do not change code in this as it can be overwritten.
 *
 * For more information see the DLDL repo: https://github.com/Deruago/DLDL
 * For more information about Deamer: https://github.com/Deruago/theDeamerProject
 */

#ifndef DREGX_LEXICON_H
#define DREGX_LEXICON_H

#include "Deamer/Language/Generator/Definition/Property/User/Main/Lexicon.h"

namespace dregx
{
	class Language;

	class Lexicon : public ::deamer::language::generator::definition::property::user::Lexicon<
								::dregx::Language>
	{
	public:
		// Terminal declarations
		::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::Terminal> LEFT_CURLY_BRACKET;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::Terminal> RIGHT_CURLY_BRACKET;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::Terminal> LEFT_SQUARE_BRACKET_NOT;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::Terminal> LEFT_SQUARE_BRACKET;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::Terminal> RIGHT_SQUARE_BRACKET;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::Terminal> LEFT_BRACKET;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::Terminal> RIGHT_BRACKET;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::Terminal> COMMA;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::Terminal> SLASH;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::Terminal> OR;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::Terminal> MIN;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::Terminal> UNDERSCORE;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::Terminal> NOT;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::Terminal> PLUS;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::Terminal> STAR;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::Terminal> NUMBER;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::Terminal> T_;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::Terminal> N_;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::Terminal> R_;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::Terminal> B_;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::Terminal> V_;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::Terminal> A_;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::Terminal> LETTER;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::Terminal> SPACE;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::Terminal> TAB;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::Terminal> OTHER;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::Terminal> DELETE_ESCAPE_CHARS;

	
	public:
		Lexicon(dregx::Language* language)
			:	::deamer::language::generator::definition::property::user::Lexicon<
					::dregx::Language>(language)
		{
		}

		void GenerateObjects() override
		{
			// Terminals
			LEFT_CURLY_BRACKET.Set(deamer::language::type::definition::object::main::Terminal("LEFT_CURLY_BRACKET", "[(]", ::deamer::language::type::definition::object::main::SpecialType::Standard));
RIGHT_CURLY_BRACKET.Set(deamer::language::type::definition::object::main::Terminal("RIGHT_CURLY_BRACKET", "[)]", ::deamer::language::type::definition::object::main::SpecialType::Standard));
LEFT_SQUARE_BRACKET_NOT.Set(deamer::language::type::definition::object::main::Terminal("LEFT_SQUARE_BRACKET_NOT", "[\\[][\\^]", ::deamer::language::type::definition::object::main::SpecialType::Standard));
LEFT_SQUARE_BRACKET.Set(deamer::language::type::definition::object::main::Terminal("LEFT_SQUARE_BRACKET", "[\\[]", ::deamer::language::type::definition::object::main::SpecialType::Standard));
RIGHT_SQUARE_BRACKET.Set(deamer::language::type::definition::object::main::Terminal("RIGHT_SQUARE_BRACKET", "[\\]]", ::deamer::language::type::definition::object::main::SpecialType::Standard));
LEFT_BRACKET.Set(deamer::language::type::definition::object::main::Terminal("LEFT_BRACKET", "[\\{]", ::deamer::language::type::definition::object::main::SpecialType::Standard));
RIGHT_BRACKET.Set(deamer::language::type::definition::object::main::Terminal("RIGHT_BRACKET", "[\\}]", ::deamer::language::type::definition::object::main::SpecialType::Standard));
COMMA.Set(deamer::language::type::definition::object::main::Terminal("COMMA", "[,]", ::deamer::language::type::definition::object::main::SpecialType::Standard));
SLASH.Set(deamer::language::type::definition::object::main::Terminal("SLASH", "[\\\\]", ::deamer::language::type::definition::object::main::SpecialType::Standard));
OR.Set(deamer::language::type::definition::object::main::Terminal("OR", "[|]", ::deamer::language::type::definition::object::main::SpecialType::Standard));
MIN.Set(deamer::language::type::definition::object::main::Terminal("MIN", "[\\-]", ::deamer::language::type::definition::object::main::SpecialType::Standard));
UNDERSCORE.Set(deamer::language::type::definition::object::main::Terminal("UNDERSCORE", "[_]", ::deamer::language::type::definition::object::main::SpecialType::Standard));
NOT.Set(deamer::language::type::definition::object::main::Terminal("NOT", "[\\^]", ::deamer::language::type::definition::object::main::SpecialType::Standard));
PLUS.Set(deamer::language::type::definition::object::main::Terminal("PLUS", "[+]", ::deamer::language::type::definition::object::main::SpecialType::Standard));
STAR.Set(deamer::language::type::definition::object::main::Terminal("STAR", "[*]", ::deamer::language::type::definition::object::main::SpecialType::Standard));
NUMBER.Set(deamer::language::type::definition::object::main::Terminal("NUMBER", "[0-9]", ::deamer::language::type::definition::object::main::SpecialType::Standard));
T_.Set(deamer::language::type::definition::object::main::Terminal("T_", "[t]", ::deamer::language::type::definition::object::main::SpecialType::Standard));
N_.Set(deamer::language::type::definition::object::main::Terminal("N_", "[n]", ::deamer::language::type::definition::object::main::SpecialType::Standard));
R_.Set(deamer::language::type::definition::object::main::Terminal("R_", "[r]", ::deamer::language::type::definition::object::main::SpecialType::Standard));
B_.Set(deamer::language::type::definition::object::main::Terminal("B_", "[b]", ::deamer::language::type::definition::object::main::SpecialType::Standard));
V_.Set(deamer::language::type::definition::object::main::Terminal("V_", "[v]", ::deamer::language::type::definition::object::main::SpecialType::Standard));
A_.Set(deamer::language::type::definition::object::main::Terminal("A_", "[a]", ::deamer::language::type::definition::object::main::SpecialType::Standard));
LETTER.Set(deamer::language::type::definition::object::main::Terminal("LETTER", "[a-zA-Z]", ::deamer::language::type::definition::object::main::SpecialType::Standard));
SPACE.Set(deamer::language::type::definition::object::main::Terminal("SPACE", "[ ]", ::deamer::language::type::definition::object::main::SpecialType::Standard));
TAB.Set(deamer::language::type::definition::object::main::Terminal("TAB", "[\\t]", ::deamer::language::type::definition::object::main::SpecialType::Standard));
OTHER.Set(deamer::language::type::definition::object::main::Terminal("OTHER", "[^0-9a-zA-Z+*,\\n\\r\\t\\b\\v\\a_ ]", ::deamer::language::type::definition::object::main::SpecialType::Standard));
DELETE_ESCAPE_CHARS.Set(deamer::language::type::definition::object::main::Terminal("DELETE_ESCAPE_CHARS", "[\\n\\r\\b\\v\\a]", ::deamer::language::type::definition::object::main::SpecialType::Delete));


			// Add object calls
			// AddObject(...)
			AddObject(LEFT_CURLY_BRACKET);
AddObject(RIGHT_CURLY_BRACKET);
AddObject(LEFT_SQUARE_BRACKET_NOT);
AddObject(LEFT_SQUARE_BRACKET);
AddObject(RIGHT_SQUARE_BRACKET);
AddObject(LEFT_BRACKET);
AddObject(RIGHT_BRACKET);
AddObject(COMMA);
AddObject(SLASH);
AddObject(OR);
AddObject(MIN);
AddObject(UNDERSCORE);
AddObject(NOT);
AddObject(PLUS);
AddObject(STAR);
AddObject(NUMBER);
AddObject(T_);
AddObject(N_);
AddObject(R_);
AddObject(B_);
AddObject(V_);
AddObject(A_);
AddObject(LETTER);
AddObject(SPACE);
AddObject(TAB);
AddObject(OTHER);
AddObject(DELETE_ESCAPE_CHARS);


			// Place higher level operations here.
			// ReplaceObject(..., ...)
			// DeleteObject(..., ...)
			
		}
	};
}

#endif // DREGX_LEXICON_H
