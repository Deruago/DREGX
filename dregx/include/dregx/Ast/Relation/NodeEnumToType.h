#ifndef DREGX_AST_RELATION_NODEENUMTOTYPE_H
#define DREGX_AST_RELATION_NODEENUMTOTYPE_H

#include "dregx/Ast/Enum/Type.h"

#include "dregx/Ast/Node/program.h"
#include "dregx/Ast/Node/deamerreserved_star__stmt__.h"
#include "dregx/Ast/Node/stmt.h"
#include "dregx/Ast/Node/word.h"
#include "dregx/Ast/Node/group.h"
#include "dregx/Ast/Node/deamerreserved_plus__word__.h"
#include "dregx/Ast/Node/or_concat.h"
#include "dregx/Ast/Node/deamerreserved_arrow__word__.h"
#include "dregx/Ast/Node/deamerreserved_star__opt_pad__OR__word__.h"
#include "dregx/Ast/Node/square.h"
#include "dregx/Ast/Node/capture.h"
#include "dregx/Ast/Node/deamerreserved_plus__capture_logic__.h"
#include "dregx/Ast/Node/capture_logic.h"
#include "dregx/Ast/Node/capture_symbols.h"
#include "dregx/Ast/Node/capture_whitespace.h"
#include "dregx/Ast/Node/capture_range.h"
#include "dregx/Ast/Node/capture_letter_range.h"
#include "dregx/Ast/Node/capture_number_range.h"
#include "dregx/Ast/Node/capture_letter.h"
#include "dregx/Ast/Node/capture_special_character.h"
#include "dregx/Ast/Node/extension_modifier.h"
#include "dregx/Ast/Node/min_repition.h"
#include "dregx/Ast/Node/deamerreserved_plus__NUMBER__.h"
#include "dregx/Ast/Node/max_repition.h"
#include "dregx/Ast/Node/standalone.h"
#include "dregx/Ast/Node/deamerreserved_plus__any_letter__.h"
#include "dregx/Ast/Node/opt_pad.h"
#include "dregx/Ast/Node/optional_padding.h"
#include "dregx/Ast/Node/deamerreserved_star__padding__.h"
#include "dregx/Ast/Node/padding.h"
#include "dregx/Ast/Node/special_char_any.h"
#include "dregx/Ast/Node/any_letter.h"
#include "dregx/Ast/Node/any_letter_exclude_underscore.h"
#include "dregx/Ast/Node/any.h"
#include "dregx/Ast/Node/LEFT_CURLY_BRACKET.h"
#include "dregx/Ast/Node/RIGHT_CURLY_BRACKET.h"
#include "dregx/Ast/Node/LEFT_SQUARE_BRACKET_NOT.h"
#include "dregx/Ast/Node/LEFT_SQUARE_BRACKET.h"
#include "dregx/Ast/Node/RIGHT_SQUARE_BRACKET.h"
#include "dregx/Ast/Node/LEFT_BRACKET.h"
#include "dregx/Ast/Node/RIGHT_BRACKET.h"
#include "dregx/Ast/Node/COMMA.h"
#include "dregx/Ast/Node/SLASH.h"
#include "dregx/Ast/Node/OR.h"
#include "dregx/Ast/Node/MIN.h"
#include "dregx/Ast/Node/UNDERSCORE.h"
#include "dregx/Ast/Node/NOT.h"
#include "dregx/Ast/Node/PLUS.h"
#include "dregx/Ast/Node/STAR.h"
#include "dregx/Ast/Node/NUMBER.h"
#include "dregx/Ast/Node/T_.h"
#include "dregx/Ast/Node/N_.h"
#include "dregx/Ast/Node/R_.h"
#include "dregx/Ast/Node/B_.h"
#include "dregx/Ast/Node/V_.h"
#include "dregx/Ast/Node/A_.h"
#include "dregx/Ast/Node/LETTER.h"
#include "dregx/Ast/Node/SPACE.h"
#include "dregx/Ast/Node/TAB.h"
#include "dregx/Ast/Node/OTHER.h"
#include "dregx/Ast/Node/DELETE_ESCAPE_CHARS.h"


namespace dregx { namespace ast { namespace relation { 

	template<::dregx::ast::Type T>
	struct NodeEnumToType
	{
		constexpr static auto value = T;
		using type = void;
	};


	template<>
	struct NodeEnumToType<::dregx::ast::Type::program>
	{
		constexpr static auto value = ::dregx::ast::Type::program;
		using type = ::dregx::ast::node::program;
	};

	template<>
	struct NodeEnumToType<::dregx::ast::Type::deamerreserved_star__stmt__>
	{
		constexpr static auto value = ::dregx::ast::Type::deamerreserved_star__stmt__;
		using type = ::dregx::ast::node::deamerreserved_star__stmt__;
	};

	template<>
	struct NodeEnumToType<::dregx::ast::Type::stmt>
	{
		constexpr static auto value = ::dregx::ast::Type::stmt;
		using type = ::dregx::ast::node::stmt;
	};

	template<>
	struct NodeEnumToType<::dregx::ast::Type::word>
	{
		constexpr static auto value = ::dregx::ast::Type::word;
		using type = ::dregx::ast::node::word;
	};

	template<>
	struct NodeEnumToType<::dregx::ast::Type::group>
	{
		constexpr static auto value = ::dregx::ast::Type::group;
		using type = ::dregx::ast::node::group;
	};

	template<>
	struct NodeEnumToType<::dregx::ast::Type::deamerreserved_plus__word__>
	{
		constexpr static auto value = ::dregx::ast::Type::deamerreserved_plus__word__;
		using type = ::dregx::ast::node::deamerreserved_plus__word__;
	};

	template<>
	struct NodeEnumToType<::dregx::ast::Type::or_concat>
	{
		constexpr static auto value = ::dregx::ast::Type::or_concat;
		using type = ::dregx::ast::node::or_concat;
	};

	template<>
	struct NodeEnumToType<::dregx::ast::Type::deamerreserved_arrow__word__>
	{
		constexpr static auto value = ::dregx::ast::Type::deamerreserved_arrow__word__;
		using type = ::dregx::ast::node::deamerreserved_arrow__word__;
	};

	template<>
	struct NodeEnumToType<::dregx::ast::Type::deamerreserved_star__opt_pad__OR__word__>
	{
		constexpr static auto value = ::dregx::ast::Type::deamerreserved_star__opt_pad__OR__word__;
		using type = ::dregx::ast::node::deamerreserved_star__opt_pad__OR__word__;
	};

	template<>
	struct NodeEnumToType<::dregx::ast::Type::square>
	{
		constexpr static auto value = ::dregx::ast::Type::square;
		using type = ::dregx::ast::node::square;
	};

	template<>
	struct NodeEnumToType<::dregx::ast::Type::capture>
	{
		constexpr static auto value = ::dregx::ast::Type::capture;
		using type = ::dregx::ast::node::capture;
	};

	template<>
	struct NodeEnumToType<::dregx::ast::Type::deamerreserved_plus__capture_logic__>
	{
		constexpr static auto value = ::dregx::ast::Type::deamerreserved_plus__capture_logic__;
		using type = ::dregx::ast::node::deamerreserved_plus__capture_logic__;
	};

	template<>
	struct NodeEnumToType<::dregx::ast::Type::capture_logic>
	{
		constexpr static auto value = ::dregx::ast::Type::capture_logic;
		using type = ::dregx::ast::node::capture_logic;
	};

	template<>
	struct NodeEnumToType<::dregx::ast::Type::capture_symbols>
	{
		constexpr static auto value = ::dregx::ast::Type::capture_symbols;
		using type = ::dregx::ast::node::capture_symbols;
	};

	template<>
	struct NodeEnumToType<::dregx::ast::Type::capture_whitespace>
	{
		constexpr static auto value = ::dregx::ast::Type::capture_whitespace;
		using type = ::dregx::ast::node::capture_whitespace;
	};

	template<>
	struct NodeEnumToType<::dregx::ast::Type::capture_range>
	{
		constexpr static auto value = ::dregx::ast::Type::capture_range;
		using type = ::dregx::ast::node::capture_range;
	};

	template<>
	struct NodeEnumToType<::dregx::ast::Type::capture_letter_range>
	{
		constexpr static auto value = ::dregx::ast::Type::capture_letter_range;
		using type = ::dregx::ast::node::capture_letter_range;
	};

	template<>
	struct NodeEnumToType<::dregx::ast::Type::capture_number_range>
	{
		constexpr static auto value = ::dregx::ast::Type::capture_number_range;
		using type = ::dregx::ast::node::capture_number_range;
	};

	template<>
	struct NodeEnumToType<::dregx::ast::Type::capture_letter>
	{
		constexpr static auto value = ::dregx::ast::Type::capture_letter;
		using type = ::dregx::ast::node::capture_letter;
	};

	template<>
	struct NodeEnumToType<::dregx::ast::Type::capture_special_character>
	{
		constexpr static auto value = ::dregx::ast::Type::capture_special_character;
		using type = ::dregx::ast::node::capture_special_character;
	};

	template<>
	struct NodeEnumToType<::dregx::ast::Type::extension_modifier>
	{
		constexpr static auto value = ::dregx::ast::Type::extension_modifier;
		using type = ::dregx::ast::node::extension_modifier;
	};

	template<>
	struct NodeEnumToType<::dregx::ast::Type::min_repition>
	{
		constexpr static auto value = ::dregx::ast::Type::min_repition;
		using type = ::dregx::ast::node::min_repition;
	};

	template<>
	struct NodeEnumToType<::dregx::ast::Type::deamerreserved_plus__NUMBER__>
	{
		constexpr static auto value = ::dregx::ast::Type::deamerreserved_plus__NUMBER__;
		using type = ::dregx::ast::node::deamerreserved_plus__NUMBER__;
	};

	template<>
	struct NodeEnumToType<::dregx::ast::Type::max_repition>
	{
		constexpr static auto value = ::dregx::ast::Type::max_repition;
		using type = ::dregx::ast::node::max_repition;
	};

	template<>
	struct NodeEnumToType<::dregx::ast::Type::standalone>
	{
		constexpr static auto value = ::dregx::ast::Type::standalone;
		using type = ::dregx::ast::node::standalone;
	};

	template<>
	struct NodeEnumToType<::dregx::ast::Type::deamerreserved_plus__any_letter__>
	{
		constexpr static auto value = ::dregx::ast::Type::deamerreserved_plus__any_letter__;
		using type = ::dregx::ast::node::deamerreserved_plus__any_letter__;
	};

	template<>
	struct NodeEnumToType<::dregx::ast::Type::opt_pad>
	{
		constexpr static auto value = ::dregx::ast::Type::opt_pad;
		using type = ::dregx::ast::node::opt_pad;
	};

	template<>
	struct NodeEnumToType<::dregx::ast::Type::optional_padding>
	{
		constexpr static auto value = ::dregx::ast::Type::optional_padding;
		using type = ::dregx::ast::node::optional_padding;
	};

	template<>
	struct NodeEnumToType<::dregx::ast::Type::deamerreserved_star__padding__>
	{
		constexpr static auto value = ::dregx::ast::Type::deamerreserved_star__padding__;
		using type = ::dregx::ast::node::deamerreserved_star__padding__;
	};

	template<>
	struct NodeEnumToType<::dregx::ast::Type::padding>
	{
		constexpr static auto value = ::dregx::ast::Type::padding;
		using type = ::dregx::ast::node::padding;
	};

	template<>
	struct NodeEnumToType<::dregx::ast::Type::special_char_any>
	{
		constexpr static auto value = ::dregx::ast::Type::special_char_any;
		using type = ::dregx::ast::node::special_char_any;
	};

	template<>
	struct NodeEnumToType<::dregx::ast::Type::any_letter>
	{
		constexpr static auto value = ::dregx::ast::Type::any_letter;
		using type = ::dregx::ast::node::any_letter;
	};

	template<>
	struct NodeEnumToType<::dregx::ast::Type::any_letter_exclude_underscore>
	{
		constexpr static auto value = ::dregx::ast::Type::any_letter_exclude_underscore;
		using type = ::dregx::ast::node::any_letter_exclude_underscore;
	};

	template<>
	struct NodeEnumToType<::dregx::ast::Type::any>
	{
		constexpr static auto value = ::dregx::ast::Type::any;
		using type = ::dregx::ast::node::any;
	};

	template<>
	struct NodeEnumToType<::dregx::ast::Type::LEFT_CURLY_BRACKET>
	{
		constexpr static auto value = ::dregx::ast::Type::LEFT_CURLY_BRACKET;
		using type = ::dregx::ast::node::LEFT_CURLY_BRACKET;
	};

	template<>
	struct NodeEnumToType<::dregx::ast::Type::RIGHT_CURLY_BRACKET>
	{
		constexpr static auto value = ::dregx::ast::Type::RIGHT_CURLY_BRACKET;
		using type = ::dregx::ast::node::RIGHT_CURLY_BRACKET;
	};

	template<>
	struct NodeEnumToType<::dregx::ast::Type::LEFT_SQUARE_BRACKET_NOT>
	{
		constexpr static auto value = ::dregx::ast::Type::LEFT_SQUARE_BRACKET_NOT;
		using type = ::dregx::ast::node::LEFT_SQUARE_BRACKET_NOT;
	};

	template<>
	struct NodeEnumToType<::dregx::ast::Type::LEFT_SQUARE_BRACKET>
	{
		constexpr static auto value = ::dregx::ast::Type::LEFT_SQUARE_BRACKET;
		using type = ::dregx::ast::node::LEFT_SQUARE_BRACKET;
	};

	template<>
	struct NodeEnumToType<::dregx::ast::Type::RIGHT_SQUARE_BRACKET>
	{
		constexpr static auto value = ::dregx::ast::Type::RIGHT_SQUARE_BRACKET;
		using type = ::dregx::ast::node::RIGHT_SQUARE_BRACKET;
	};

	template<>
	struct NodeEnumToType<::dregx::ast::Type::LEFT_BRACKET>
	{
		constexpr static auto value = ::dregx::ast::Type::LEFT_BRACKET;
		using type = ::dregx::ast::node::LEFT_BRACKET;
	};

	template<>
	struct NodeEnumToType<::dregx::ast::Type::RIGHT_BRACKET>
	{
		constexpr static auto value = ::dregx::ast::Type::RIGHT_BRACKET;
		using type = ::dregx::ast::node::RIGHT_BRACKET;
	};

	template<>
	struct NodeEnumToType<::dregx::ast::Type::COMMA>
	{
		constexpr static auto value = ::dregx::ast::Type::COMMA;
		using type = ::dregx::ast::node::COMMA;
	};

	template<>
	struct NodeEnumToType<::dregx::ast::Type::SLASH>
	{
		constexpr static auto value = ::dregx::ast::Type::SLASH;
		using type = ::dregx::ast::node::SLASH;
	};

	template<>
	struct NodeEnumToType<::dregx::ast::Type::OR>
	{
		constexpr static auto value = ::dregx::ast::Type::OR;
		using type = ::dregx::ast::node::OR;
	};

	template<>
	struct NodeEnumToType<::dregx::ast::Type::MIN>
	{
		constexpr static auto value = ::dregx::ast::Type::MIN;
		using type = ::dregx::ast::node::MIN;
	};

	template<>
	struct NodeEnumToType<::dregx::ast::Type::UNDERSCORE>
	{
		constexpr static auto value = ::dregx::ast::Type::UNDERSCORE;
		using type = ::dregx::ast::node::UNDERSCORE;
	};

	template<>
	struct NodeEnumToType<::dregx::ast::Type::NOT>
	{
		constexpr static auto value = ::dregx::ast::Type::NOT;
		using type = ::dregx::ast::node::NOT;
	};

	template<>
	struct NodeEnumToType<::dregx::ast::Type::PLUS>
	{
		constexpr static auto value = ::dregx::ast::Type::PLUS;
		using type = ::dregx::ast::node::PLUS;
	};

	template<>
	struct NodeEnumToType<::dregx::ast::Type::STAR>
	{
		constexpr static auto value = ::dregx::ast::Type::STAR;
		using type = ::dregx::ast::node::STAR;
	};

	template<>
	struct NodeEnumToType<::dregx::ast::Type::NUMBER>
	{
		constexpr static auto value = ::dregx::ast::Type::NUMBER;
		using type = ::dregx::ast::node::NUMBER;
	};

	template<>
	struct NodeEnumToType<::dregx::ast::Type::T_>
	{
		constexpr static auto value = ::dregx::ast::Type::T_;
		using type = ::dregx::ast::node::T_;
	};

	template<>
	struct NodeEnumToType<::dregx::ast::Type::N_>
	{
		constexpr static auto value = ::dregx::ast::Type::N_;
		using type = ::dregx::ast::node::N_;
	};

	template<>
	struct NodeEnumToType<::dregx::ast::Type::R_>
	{
		constexpr static auto value = ::dregx::ast::Type::R_;
		using type = ::dregx::ast::node::R_;
	};

	template<>
	struct NodeEnumToType<::dregx::ast::Type::B_>
	{
		constexpr static auto value = ::dregx::ast::Type::B_;
		using type = ::dregx::ast::node::B_;
	};

	template<>
	struct NodeEnumToType<::dregx::ast::Type::V_>
	{
		constexpr static auto value = ::dregx::ast::Type::V_;
		using type = ::dregx::ast::node::V_;
	};

	template<>
	struct NodeEnumToType<::dregx::ast::Type::A_>
	{
		constexpr static auto value = ::dregx::ast::Type::A_;
		using type = ::dregx::ast::node::A_;
	};

	template<>
	struct NodeEnumToType<::dregx::ast::Type::LETTER>
	{
		constexpr static auto value = ::dregx::ast::Type::LETTER;
		using type = ::dregx::ast::node::LETTER;
	};

	template<>
	struct NodeEnumToType<::dregx::ast::Type::SPACE>
	{
		constexpr static auto value = ::dregx::ast::Type::SPACE;
		using type = ::dregx::ast::node::SPACE;
	};

	template<>
	struct NodeEnumToType<::dregx::ast::Type::TAB>
	{
		constexpr static auto value = ::dregx::ast::Type::TAB;
		using type = ::dregx::ast::node::TAB;
	};

	template<>
	struct NodeEnumToType<::dregx::ast::Type::OTHER>
	{
		constexpr static auto value = ::dregx::ast::Type::OTHER;
		using type = ::dregx::ast::node::OTHER;
	};

	template<>
	struct NodeEnumToType<::dregx::ast::Type::DELETE_ESCAPE_CHARS>
	{
		constexpr static auto value = ::dregx::ast::Type::DELETE_ESCAPE_CHARS;
		using type = ::dregx::ast::node::DELETE_ESCAPE_CHARS;
	};


template<::dregx::ast::Type T>
constexpr static auto NodeEnumToType_v = ::dregx::ast::relation::NodeEnumToType<T>::value;

template<::dregx::ast::Type T>
using NodeEnumToType_t = typename ::dregx::ast::relation::NodeEnumToType<T>::type;

}}}

#endif // DREGX_AST_RELATION_NODEENUMTOTYPE_H