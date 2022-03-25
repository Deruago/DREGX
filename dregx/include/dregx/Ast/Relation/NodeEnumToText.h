#ifndef DREGX_AST_RELATION_NODEENUMTOTEXT_H
#define DREGX_AST_RELATION_NODEENUMTOTEXT_H

#include "dregx/Ast/Enum/Type.h"

namespace dregx { namespace ast { namespace relation { 

	static constexpr const char* ConvertEnumToText(::dregx::ast::Type type)
	{
		switch(type)
		{
			
	case ::dregx::ast::Type::program: {
		return "program";
	}
	

	case ::dregx::ast::Type::deamerreserved_star__stmt__: {
		return "deamerreserved_star__stmt__";
	}
	

	case ::dregx::ast::Type::stmt: {
		return "stmt";
	}
	

	case ::dregx::ast::Type::word: {
		return "word";
	}
	

	case ::dregx::ast::Type::group: {
		return "group";
	}
	

	case ::dregx::ast::Type::deamerreserved_plus__word__: {
		return "deamerreserved_plus__word__";
	}
	

	case ::dregx::ast::Type::or_concat: {
		return "or_concat";
	}
	

	case ::dregx::ast::Type::deamerreserved_arrow__or_element__: {
		return "deamerreserved_arrow__or_element__";
	}
	

	case ::dregx::ast::Type::deamerreserved_star__opt_pad__OR__or_element__: {
		return "deamerreserved_star__opt_pad__OR__or_element__";
	}
	

	case ::dregx::ast::Type::or_element: {
		return "or_element";
	}
	

	case ::dregx::ast::Type::square: {
		return "square";
	}
	

	case ::dregx::ast::Type::capture: {
		return "capture";
	}
	

	case ::dregx::ast::Type::deamerreserved_star__capture_logic__: {
		return "deamerreserved_star__capture_logic__";
	}
	

	case ::dregx::ast::Type::capture_logic: {
		return "capture_logic";
	}
	

	case ::dregx::ast::Type::capture_symbols: {
		return "capture_symbols";
	}
	

	case ::dregx::ast::Type::capture_whitespace: {
		return "capture_whitespace";
	}
	

	case ::dregx::ast::Type::capture_range: {
		return "capture_range";
	}
	

	case ::dregx::ast::Type::capture_letter_range: {
		return "capture_letter_range";
	}
	

	case ::dregx::ast::Type::capture_number_range: {
		return "capture_number_range";
	}
	

	case ::dregx::ast::Type::capture_number: {
		return "capture_number";
	}
	

	case ::dregx::ast::Type::capture_letter: {
		return "capture_letter";
	}
	

	case ::dregx::ast::Type::capture_special_character: {
		return "capture_special_character";
	}
	

	case ::dregx::ast::Type::extension_modifier: {
		return "extension_modifier";
	}
	

	case ::dregx::ast::Type::min_repition: {
		return "min_repition";
	}
	

	case ::dregx::ast::Type::deamerreserved_plus__NUMBER__: {
		return "deamerreserved_plus__NUMBER__";
	}
	

	case ::dregx::ast::Type::max_repition: {
		return "max_repition";
	}
	

	case ::dregx::ast::Type::standalone: {
		return "standalone";
	}
	

	case ::dregx::ast::Type::opt_pad: {
		return "opt_pad";
	}
	

	case ::dregx::ast::Type::optional_padding: {
		return "optional_padding";
	}
	

	case ::dregx::ast::Type::deamerreserved_star__padding__: {
		return "deamerreserved_star__padding__";
	}
	

	case ::dregx::ast::Type::padding: {
		return "padding";
	}
	

	case ::dregx::ast::Type::special_char_any: {
		return "special_char_any";
	}
	

	case ::dregx::ast::Type::any_number: {
		return "any_number";
	}
	

	case ::dregx::ast::Type::any_letter: {
		return "any_letter";
	}
	

	case ::dregx::ast::Type::any_letter_exclude_underscore: {
		return "any_letter_exclude_underscore";
	}
	

	case ::dregx::ast::Type::capture_structure: {
		return "capture_structure";
	}
	

	case ::dregx::ast::Type::any: {
		return "any";
	}
	

	case ::dregx::ast::Type::LEFT_CURLY_BRACKET: {
		return "LEFT_CURLY_BRACKET";
	}
	

	case ::dregx::ast::Type::RIGHT_CURLY_BRACKET: {
		return "RIGHT_CURLY_BRACKET";
	}
	

	case ::dregx::ast::Type::LEFT_SQUARE_BRACKET_NOT: {
		return "LEFT_SQUARE_BRACKET_NOT";
	}
	

	case ::dregx::ast::Type::LEFT_SQUARE_BRACKET: {
		return "LEFT_SQUARE_BRACKET";
	}
	

	case ::dregx::ast::Type::RIGHT_SQUARE_BRACKET: {
		return "RIGHT_SQUARE_BRACKET";
	}
	

	case ::dregx::ast::Type::LEFT_BRACKET: {
		return "LEFT_BRACKET";
	}
	

	case ::dregx::ast::Type::RIGHT_BRACKET: {
		return "RIGHT_BRACKET";
	}
	

	case ::dregx::ast::Type::COMMA: {
		return "COMMA";
	}
	

	case ::dregx::ast::Type::SLASH: {
		return "SLASH";
	}
	

	case ::dregx::ast::Type::OR: {
		return "OR";
	}
	

	case ::dregx::ast::Type::MIN: {
		return "MIN";
	}
	

	case ::dregx::ast::Type::UNDERSCORE: {
		return "UNDERSCORE";
	}
	

	case ::dregx::ast::Type::NOT: {
		return "NOT";
	}
	

	case ::dregx::ast::Type::PLUS: {
		return "PLUS";
	}
	

	case ::dregx::ast::Type::STAR: {
		return "STAR";
	}
	

	case ::dregx::ast::Type::OPTIONAL: {
		return "OPTIONAL";
	}
	

	case ::dregx::ast::Type::NUMBER: {
		return "NUMBER";
	}
	

	case ::dregx::ast::Type::T_: {
		return "T_";
	}
	

	case ::dregx::ast::Type::N_: {
		return "N_";
	}
	

	case ::dregx::ast::Type::R_: {
		return "R_";
	}
	

	case ::dregx::ast::Type::B_: {
		return "B_";
	}
	

	case ::dregx::ast::Type::V_: {
		return "V_";
	}
	

	case ::dregx::ast::Type::A_: {
		return "A_";
	}
	

	case ::dregx::ast::Type::LETTER: {
		return "LETTER";
	}
	

	case ::dregx::ast::Type::SPACE: {
		return "SPACE";
	}
	

	case ::dregx::ast::Type::TAB: {
		return "TAB";
	}
	

	case ::dregx::ast::Type::OTHER: {
		return "OTHER";
	}
	

	case ::dregx::ast::Type::DELETE_ESCAPE_CHARS: {
		return "DELETE_ESCAPE_CHARS";
	}
	

		}
		
		return "";
	}

}}}

#endif // DREGX_AST_RELATION_NODEENUMTOTEXT_H