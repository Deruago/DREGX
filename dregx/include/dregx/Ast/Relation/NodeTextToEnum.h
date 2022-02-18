#ifndef DREGX_AST_RELATION_NODETEXTTOENUM_H
#define DREGX_AST_RELATION_NODETEXTTOENUM_H

#include "dregx/Ast/Enum/Type.h"
#include <string>
#include <map>

namespace dregx { namespace ast { namespace relation { 

	static constexpr ::dregx::ast::Type ConvertTextToEnum(const std::string& text)
	{
		static const std::map<std::string, ::dregx::ast::Type> mapTextWithType = {
			{"", ::dregx::ast::Type::deamerreserved_unknown },
			
		{ "program", ::dregx::ast::Type::program },
	

		{ "deamerreserved_star__stmt__", ::dregx::ast::Type::deamerreserved_star__stmt__ },
	

		{ "stmt", ::dregx::ast::Type::stmt },
	

		{ "word", ::dregx::ast::Type::word },
	

		{ "group", ::dregx::ast::Type::group },
	

		{ "deamerreserved_plus__word__", ::dregx::ast::Type::deamerreserved_plus__word__ },
	

		{ "or_concat", ::dregx::ast::Type::or_concat },
	

		{ "square", ::dregx::ast::Type::square },
	

		{ "capture", ::dregx::ast::Type::capture },
	

		{ "deamerreserved_plus__capture_logic__", ::dregx::ast::Type::deamerreserved_plus__capture_logic__ },
	

		{ "capture_logic", ::dregx::ast::Type::capture_logic },
	

		{ "capture_symbols", ::dregx::ast::Type::capture_symbols },
	

		{ "capture_whitespace", ::dregx::ast::Type::capture_whitespace },
	

		{ "capture_range", ::dregx::ast::Type::capture_range },
	

		{ "capture_letter_range", ::dregx::ast::Type::capture_letter_range },
	

		{ "capture_number_range", ::dregx::ast::Type::capture_number_range },
	

		{ "capture_letter", ::dregx::ast::Type::capture_letter },
	

		{ "capture_special_character", ::dregx::ast::Type::capture_special_character },
	

		{ "extension_modifier", ::dregx::ast::Type::extension_modifier },
	

		{ "min_repition", ::dregx::ast::Type::min_repition },
	

		{ "deamerreserved_plus__NUMBER__", ::dregx::ast::Type::deamerreserved_plus__NUMBER__ },
	

		{ "max_repition", ::dregx::ast::Type::max_repition },
	

		{ "standalone", ::dregx::ast::Type::standalone },
	

		{ "deamerreserved_plus__any_letter__", ::dregx::ast::Type::deamerreserved_plus__any_letter__ },
	

		{ "opt_pad", ::dregx::ast::Type::opt_pad },
	

		{ "optional_padding", ::dregx::ast::Type::optional_padding },
	

		{ "deamerreserved_star__padding__", ::dregx::ast::Type::deamerreserved_star__padding__ },
	

		{ "padding", ::dregx::ast::Type::padding },
	

		{ "special_char_any", ::dregx::ast::Type::special_char_any },
	

		{ "any_letter", ::dregx::ast::Type::any_letter },
	

		{ "any_letter_exclude_underscore", ::dregx::ast::Type::any_letter_exclude_underscore },
	

		{ "any", ::dregx::ast::Type::any },
	

		{ "LEFT_CURLY_BRACKET", ::dregx::ast::Type::LEFT_CURLY_BRACKET },
	

		{ "RIGHT_CURLY_BRACKET", ::dregx::ast::Type::RIGHT_CURLY_BRACKET },
	

		{ "LEFT_SQUARE_BRACKET_NOT", ::dregx::ast::Type::LEFT_SQUARE_BRACKET_NOT },
	

		{ "LEFT_SQUARE_BRACKET", ::dregx::ast::Type::LEFT_SQUARE_BRACKET },
	

		{ "RIGHT_SQUARE_BRACKET", ::dregx::ast::Type::RIGHT_SQUARE_BRACKET },
	

		{ "LEFT_BRACKET", ::dregx::ast::Type::LEFT_BRACKET },
	

		{ "RIGHT_BRACKET", ::dregx::ast::Type::RIGHT_BRACKET },
	

		{ "COMMA", ::dregx::ast::Type::COMMA },
	

		{ "SLASH", ::dregx::ast::Type::SLASH },
	

		{ "OR", ::dregx::ast::Type::OR },
	

		{ "MIN", ::dregx::ast::Type::MIN },
	

		{ "UNDERSCORE", ::dregx::ast::Type::UNDERSCORE },
	

		{ "NOT", ::dregx::ast::Type::NOT },
	

		{ "PLUS", ::dregx::ast::Type::PLUS },
	

		{ "STAR", ::dregx::ast::Type::STAR },
	

		{ "NUMBER", ::dregx::ast::Type::NUMBER },
	

		{ "T_", ::dregx::ast::Type::T_ },
	

		{ "N_", ::dregx::ast::Type::N_ },
	

		{ "R_", ::dregx::ast::Type::R_ },
	

		{ "B_", ::dregx::ast::Type::B_ },
	

		{ "V_", ::dregx::ast::Type::V_ },
	

		{ "A_", ::dregx::ast::Type::A_ },
	

		{ "LETTER", ::dregx::ast::Type::LETTER },
	

		{ "SPACE", ::dregx::ast::Type::SPACE },
	

		{ "TAB", ::dregx::ast::Type::TAB },
	

		{ "OTHER", ::dregx::ast::Type::OTHER },
	

		{ "DELETE_ESCAPE_CHARS", ::dregx::ast::Type::DELETE_ESCAPE_CHARS },
	

		};

		return mapTextWithType[text];
	}

}}}

#endif // DREGX_AST_RELATION_NODETEXTTOENUM_H