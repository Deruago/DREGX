#ifndef DREGX_AST_RELATION_NODETYPETOENUM_H
#define DREGX_AST_RELATION_NODETYPETOENUM_H

#include "dregx/Ast/Enum/Type.h"

namespace dregx { namespace ast { namespace node {

class program;
class deamerreserved_star__stmt__;
class stmt;
class word;
class group;
class deamerreserved_plus__word__;
class or_concat;
class deamerreserved_arrow__word__;
class deamerreserved_star__opt_pad__OR__word__;
class square;
class capture;
class deamerreserved_plus__capture_logic__;
class capture_logic;
class capture_symbols;
class capture_whitespace;
class capture_range;
class capture_letter_range;
class capture_number_range;
class capture_letter;
class capture_special_character;
class extension_modifier;
class min_repition;
class deamerreserved_plus__NUMBER__;
class max_repition;
class standalone;
class deamerreserved_plus__any_letter__;
class opt_pad;
class optional_padding;
class deamerreserved_star__padding__;
class padding;
class special_char_any;
class any_letter;
class any_letter_exclude_underscore;
class any;
class LEFT_CURLY_BRACKET;
class RIGHT_CURLY_BRACKET;
class LEFT_SQUARE_BRACKET_NOT;
class LEFT_SQUARE_BRACKET;
class RIGHT_SQUARE_BRACKET;
class LEFT_BRACKET;
class RIGHT_BRACKET;
class COMMA;
class SLASH;
class OR;
class MIN;
class UNDERSCORE;
class NOT;
class PLUS;
class STAR;
class NUMBER;
class T_;
class N_;
class R_;
class B_;
class V_;
class A_;
class LETTER;
class SPACE;
class TAB;
class OTHER;
class DELETE_ESCAPE_CHARS;

}}}

namespace dregx { namespace ast { namespace relation { 

	template<typename T>
	struct NodeTypeToEnum
	{
		constexpr static auto value = ::dregx::ast::Type::deamerreserved_unknown;
		using type = void;
	};


	template<>
	struct NodeTypeToEnum<::dregx::ast::node::program>
	{
		constexpr static auto value = ::dregx::ast::Type::program;
		using type = ::dregx::ast::node::program;
	};

	template<>
	struct NodeTypeToEnum<::dregx::ast::node::deamerreserved_star__stmt__>
	{
		constexpr static auto value = ::dregx::ast::Type::deamerreserved_star__stmt__;
		using type = ::dregx::ast::node::deamerreserved_star__stmt__;
	};

	template<>
	struct NodeTypeToEnum<::dregx::ast::node::stmt>
	{
		constexpr static auto value = ::dregx::ast::Type::stmt;
		using type = ::dregx::ast::node::stmt;
	};

	template<>
	struct NodeTypeToEnum<::dregx::ast::node::word>
	{
		constexpr static auto value = ::dregx::ast::Type::word;
		using type = ::dregx::ast::node::word;
	};

	template<>
	struct NodeTypeToEnum<::dregx::ast::node::group>
	{
		constexpr static auto value = ::dregx::ast::Type::group;
		using type = ::dregx::ast::node::group;
	};

	template<>
	struct NodeTypeToEnum<::dregx::ast::node::deamerreserved_plus__word__>
	{
		constexpr static auto value = ::dregx::ast::Type::deamerreserved_plus__word__;
		using type = ::dregx::ast::node::deamerreserved_plus__word__;
	};

	template<>
	struct NodeTypeToEnum<::dregx::ast::node::or_concat>
	{
		constexpr static auto value = ::dregx::ast::Type::or_concat;
		using type = ::dregx::ast::node::or_concat;
	};

	template<>
	struct NodeTypeToEnum<::dregx::ast::node::deamerreserved_arrow__word__>
	{
		constexpr static auto value = ::dregx::ast::Type::deamerreserved_arrow__word__;
		using type = ::dregx::ast::node::deamerreserved_arrow__word__;
	};

	template<>
	struct NodeTypeToEnum<::dregx::ast::node::deamerreserved_star__opt_pad__OR__word__>
	{
		constexpr static auto value = ::dregx::ast::Type::deamerreserved_star__opt_pad__OR__word__;
		using type = ::dregx::ast::node::deamerreserved_star__opt_pad__OR__word__;
	};

	template<>
	struct NodeTypeToEnum<::dregx::ast::node::square>
	{
		constexpr static auto value = ::dregx::ast::Type::square;
		using type = ::dregx::ast::node::square;
	};

	template<>
	struct NodeTypeToEnum<::dregx::ast::node::capture>
	{
		constexpr static auto value = ::dregx::ast::Type::capture;
		using type = ::dregx::ast::node::capture;
	};

	template<>
	struct NodeTypeToEnum<::dregx::ast::node::deamerreserved_plus__capture_logic__>
	{
		constexpr static auto value = ::dregx::ast::Type::deamerreserved_plus__capture_logic__;
		using type = ::dregx::ast::node::deamerreserved_plus__capture_logic__;
	};

	template<>
	struct NodeTypeToEnum<::dregx::ast::node::capture_logic>
	{
		constexpr static auto value = ::dregx::ast::Type::capture_logic;
		using type = ::dregx::ast::node::capture_logic;
	};

	template<>
	struct NodeTypeToEnum<::dregx::ast::node::capture_symbols>
	{
		constexpr static auto value = ::dregx::ast::Type::capture_symbols;
		using type = ::dregx::ast::node::capture_symbols;
	};

	template<>
	struct NodeTypeToEnum<::dregx::ast::node::capture_whitespace>
	{
		constexpr static auto value = ::dregx::ast::Type::capture_whitespace;
		using type = ::dregx::ast::node::capture_whitespace;
	};

	template<>
	struct NodeTypeToEnum<::dregx::ast::node::capture_range>
	{
		constexpr static auto value = ::dregx::ast::Type::capture_range;
		using type = ::dregx::ast::node::capture_range;
	};

	template<>
	struct NodeTypeToEnum<::dregx::ast::node::capture_letter_range>
	{
		constexpr static auto value = ::dregx::ast::Type::capture_letter_range;
		using type = ::dregx::ast::node::capture_letter_range;
	};

	template<>
	struct NodeTypeToEnum<::dregx::ast::node::capture_number_range>
	{
		constexpr static auto value = ::dregx::ast::Type::capture_number_range;
		using type = ::dregx::ast::node::capture_number_range;
	};

	template<>
	struct NodeTypeToEnum<::dregx::ast::node::capture_letter>
	{
		constexpr static auto value = ::dregx::ast::Type::capture_letter;
		using type = ::dregx::ast::node::capture_letter;
	};

	template<>
	struct NodeTypeToEnum<::dregx::ast::node::capture_special_character>
	{
		constexpr static auto value = ::dregx::ast::Type::capture_special_character;
		using type = ::dregx::ast::node::capture_special_character;
	};

	template<>
	struct NodeTypeToEnum<::dregx::ast::node::extension_modifier>
	{
		constexpr static auto value = ::dregx::ast::Type::extension_modifier;
		using type = ::dregx::ast::node::extension_modifier;
	};

	template<>
	struct NodeTypeToEnum<::dregx::ast::node::min_repition>
	{
		constexpr static auto value = ::dregx::ast::Type::min_repition;
		using type = ::dregx::ast::node::min_repition;
	};

	template<>
	struct NodeTypeToEnum<::dregx::ast::node::deamerreserved_plus__NUMBER__>
	{
		constexpr static auto value = ::dregx::ast::Type::deamerreserved_plus__NUMBER__;
		using type = ::dregx::ast::node::deamerreserved_plus__NUMBER__;
	};

	template<>
	struct NodeTypeToEnum<::dregx::ast::node::max_repition>
	{
		constexpr static auto value = ::dregx::ast::Type::max_repition;
		using type = ::dregx::ast::node::max_repition;
	};

	template<>
	struct NodeTypeToEnum<::dregx::ast::node::standalone>
	{
		constexpr static auto value = ::dregx::ast::Type::standalone;
		using type = ::dregx::ast::node::standalone;
	};

	template<>
	struct NodeTypeToEnum<::dregx::ast::node::deamerreserved_plus__any_letter__>
	{
		constexpr static auto value = ::dregx::ast::Type::deamerreserved_plus__any_letter__;
		using type = ::dregx::ast::node::deamerreserved_plus__any_letter__;
	};

	template<>
	struct NodeTypeToEnum<::dregx::ast::node::opt_pad>
	{
		constexpr static auto value = ::dregx::ast::Type::opt_pad;
		using type = ::dregx::ast::node::opt_pad;
	};

	template<>
	struct NodeTypeToEnum<::dregx::ast::node::optional_padding>
	{
		constexpr static auto value = ::dregx::ast::Type::optional_padding;
		using type = ::dregx::ast::node::optional_padding;
	};

	template<>
	struct NodeTypeToEnum<::dregx::ast::node::deamerreserved_star__padding__>
	{
		constexpr static auto value = ::dregx::ast::Type::deamerreserved_star__padding__;
		using type = ::dregx::ast::node::deamerreserved_star__padding__;
	};

	template<>
	struct NodeTypeToEnum<::dregx::ast::node::padding>
	{
		constexpr static auto value = ::dregx::ast::Type::padding;
		using type = ::dregx::ast::node::padding;
	};

	template<>
	struct NodeTypeToEnum<::dregx::ast::node::special_char_any>
	{
		constexpr static auto value = ::dregx::ast::Type::special_char_any;
		using type = ::dregx::ast::node::special_char_any;
	};

	template<>
	struct NodeTypeToEnum<::dregx::ast::node::any_letter>
	{
		constexpr static auto value = ::dregx::ast::Type::any_letter;
		using type = ::dregx::ast::node::any_letter;
	};

	template<>
	struct NodeTypeToEnum<::dregx::ast::node::any_letter_exclude_underscore>
	{
		constexpr static auto value = ::dregx::ast::Type::any_letter_exclude_underscore;
		using type = ::dregx::ast::node::any_letter_exclude_underscore;
	};

	template<>
	struct NodeTypeToEnum<::dregx::ast::node::any>
	{
		constexpr static auto value = ::dregx::ast::Type::any;
		using type = ::dregx::ast::node::any;
	};

	template<>
	struct NodeTypeToEnum<::dregx::ast::node::LEFT_CURLY_BRACKET>
	{
		constexpr static auto value = ::dregx::ast::Type::LEFT_CURLY_BRACKET;
		using type = ::dregx::ast::node::LEFT_CURLY_BRACKET;
	};

	template<>
	struct NodeTypeToEnum<::dregx::ast::node::RIGHT_CURLY_BRACKET>
	{
		constexpr static auto value = ::dregx::ast::Type::RIGHT_CURLY_BRACKET;
		using type = ::dregx::ast::node::RIGHT_CURLY_BRACKET;
	};

	template<>
	struct NodeTypeToEnum<::dregx::ast::node::LEFT_SQUARE_BRACKET_NOT>
	{
		constexpr static auto value = ::dregx::ast::Type::LEFT_SQUARE_BRACKET_NOT;
		using type = ::dregx::ast::node::LEFT_SQUARE_BRACKET_NOT;
	};

	template<>
	struct NodeTypeToEnum<::dregx::ast::node::LEFT_SQUARE_BRACKET>
	{
		constexpr static auto value = ::dregx::ast::Type::LEFT_SQUARE_BRACKET;
		using type = ::dregx::ast::node::LEFT_SQUARE_BRACKET;
	};

	template<>
	struct NodeTypeToEnum<::dregx::ast::node::RIGHT_SQUARE_BRACKET>
	{
		constexpr static auto value = ::dregx::ast::Type::RIGHT_SQUARE_BRACKET;
		using type = ::dregx::ast::node::RIGHT_SQUARE_BRACKET;
	};

	template<>
	struct NodeTypeToEnum<::dregx::ast::node::LEFT_BRACKET>
	{
		constexpr static auto value = ::dregx::ast::Type::LEFT_BRACKET;
		using type = ::dregx::ast::node::LEFT_BRACKET;
	};

	template<>
	struct NodeTypeToEnum<::dregx::ast::node::RIGHT_BRACKET>
	{
		constexpr static auto value = ::dregx::ast::Type::RIGHT_BRACKET;
		using type = ::dregx::ast::node::RIGHT_BRACKET;
	};

	template<>
	struct NodeTypeToEnum<::dregx::ast::node::COMMA>
	{
		constexpr static auto value = ::dregx::ast::Type::COMMA;
		using type = ::dregx::ast::node::COMMA;
	};

	template<>
	struct NodeTypeToEnum<::dregx::ast::node::SLASH>
	{
		constexpr static auto value = ::dregx::ast::Type::SLASH;
		using type = ::dregx::ast::node::SLASH;
	};

	template<>
	struct NodeTypeToEnum<::dregx::ast::node::OR>
	{
		constexpr static auto value = ::dregx::ast::Type::OR;
		using type = ::dregx::ast::node::OR;
	};

	template<>
	struct NodeTypeToEnum<::dregx::ast::node::MIN>
	{
		constexpr static auto value = ::dregx::ast::Type::MIN;
		using type = ::dregx::ast::node::MIN;
	};

	template<>
	struct NodeTypeToEnum<::dregx::ast::node::UNDERSCORE>
	{
		constexpr static auto value = ::dregx::ast::Type::UNDERSCORE;
		using type = ::dregx::ast::node::UNDERSCORE;
	};

	template<>
	struct NodeTypeToEnum<::dregx::ast::node::NOT>
	{
		constexpr static auto value = ::dregx::ast::Type::NOT;
		using type = ::dregx::ast::node::NOT;
	};

	template<>
	struct NodeTypeToEnum<::dregx::ast::node::PLUS>
	{
		constexpr static auto value = ::dregx::ast::Type::PLUS;
		using type = ::dregx::ast::node::PLUS;
	};

	template<>
	struct NodeTypeToEnum<::dregx::ast::node::STAR>
	{
		constexpr static auto value = ::dregx::ast::Type::STAR;
		using type = ::dregx::ast::node::STAR;
	};

	template<>
	struct NodeTypeToEnum<::dregx::ast::node::NUMBER>
	{
		constexpr static auto value = ::dregx::ast::Type::NUMBER;
		using type = ::dregx::ast::node::NUMBER;
	};

	template<>
	struct NodeTypeToEnum<::dregx::ast::node::T_>
	{
		constexpr static auto value = ::dregx::ast::Type::T_;
		using type = ::dregx::ast::node::T_;
	};

	template<>
	struct NodeTypeToEnum<::dregx::ast::node::N_>
	{
		constexpr static auto value = ::dregx::ast::Type::N_;
		using type = ::dregx::ast::node::N_;
	};

	template<>
	struct NodeTypeToEnum<::dregx::ast::node::R_>
	{
		constexpr static auto value = ::dregx::ast::Type::R_;
		using type = ::dregx::ast::node::R_;
	};

	template<>
	struct NodeTypeToEnum<::dregx::ast::node::B_>
	{
		constexpr static auto value = ::dregx::ast::Type::B_;
		using type = ::dregx::ast::node::B_;
	};

	template<>
	struct NodeTypeToEnum<::dregx::ast::node::V_>
	{
		constexpr static auto value = ::dregx::ast::Type::V_;
		using type = ::dregx::ast::node::V_;
	};

	template<>
	struct NodeTypeToEnum<::dregx::ast::node::A_>
	{
		constexpr static auto value = ::dregx::ast::Type::A_;
		using type = ::dregx::ast::node::A_;
	};

	template<>
	struct NodeTypeToEnum<::dregx::ast::node::LETTER>
	{
		constexpr static auto value = ::dregx::ast::Type::LETTER;
		using type = ::dregx::ast::node::LETTER;
	};

	template<>
	struct NodeTypeToEnum<::dregx::ast::node::SPACE>
	{
		constexpr static auto value = ::dregx::ast::Type::SPACE;
		using type = ::dregx::ast::node::SPACE;
	};

	template<>
	struct NodeTypeToEnum<::dregx::ast::node::TAB>
	{
		constexpr static auto value = ::dregx::ast::Type::TAB;
		using type = ::dregx::ast::node::TAB;
	};

	template<>
	struct NodeTypeToEnum<::dregx::ast::node::OTHER>
	{
		constexpr static auto value = ::dregx::ast::Type::OTHER;
		using type = ::dregx::ast::node::OTHER;
	};

	template<>
	struct NodeTypeToEnum<::dregx::ast::node::DELETE_ESCAPE_CHARS>
	{
		constexpr static auto value = ::dregx::ast::Type::DELETE_ESCAPE_CHARS;
		using type = ::dregx::ast::node::DELETE_ESCAPE_CHARS;
	};


template<typename T>
constexpr static auto NodeTypeToEnum_v = ::dregx::ast::relation::NodeTypeToEnum<T>::value;

template<typename T>
using NodeTypeToEnum_t = typename ::dregx::ast::relation::NodeTypeToEnum<T>::type;

}}}

#endif // DREGX_AST_RELATION_NODETYPETOENUM_H