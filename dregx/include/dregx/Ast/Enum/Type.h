#ifndef DREGX_AST_ENUM_TYPE_H
#define DREGX_AST_ENUM_TYPE_H

#include <cstddef>

namespace dregx { namespace ast { 

	enum class Type : std::size_t
	{
		// Reserved
		deamerreserved_unknown,

		// Terminal
		LEFT_CURLY_BRACKET,
		RIGHT_CURLY_BRACKET,
		LEFT_SQUARE_BRACKET_NOT,
		LEFT_SQUARE_BRACKET,
		RIGHT_SQUARE_BRACKET,
		LEFT_BRACKET,
		RIGHT_BRACKET,
		COMMA,
		SLASH,
		OR,
		MIN,
		UNDERSCORE,
		NOT,
		PLUS,
		STAR,
		NUMBER,
		T_,
		N_,
		R_,
		B_,
		V_,
		A_,
		LETTER,
		SPACE,
		TAB,
		OTHER,
		DELETE_ESCAPE_CHARS,


		// NonTerminal
		program,
		deamerreserved_star__stmt__,
		stmt,
		word,
		group,
		deamerreserved_plus__word__,
		or_concat,
		square,
		capture,
		deamerreserved_plus__capture_logic__,
		capture_logic,
		capture_symbols,
		capture_whitespace,
		capture_range,
		capture_letter_range,
		capture_number_range,
		capture_letter,
		capture_special_character,
		extension_modifier,
		min_repition,
		deamerreserved_plus__NUMBER__,
		max_repition,
		standalone,
		deamerreserved_plus__any_letter__,
		opt_pad,
		optional_padding,
		deamerreserved_star__padding__,
		padding,
		special_char_any,
		any_letter,
		any_letter_exclude_underscore,
		any,

	};

	static inline bool operator==(std::size_t lhs, ::dregx::ast::Type rhs)
	{
		return lhs == static_cast<std::size_t>(rhs);
	}

	static inline bool operator==(::dregx::ast::Type lhs, std::size_t rhs)
	{
		return static_cast<std::size_t>(lhs) == rhs;
	}

	static inline bool operator==(int lhs, ::dregx::ast::Type rhs)
	{
		return lhs == static_cast<std::size_t>(rhs);
	}

	static inline bool operator==(::dregx::ast::Type lhs, int rhs)
	{
		return static_cast<std::size_t>(lhs) == rhs;
	}
}}

#endif // DREGX_AST_ENUM_TYPE_H