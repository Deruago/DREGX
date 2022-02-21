#ifndef DREGX_AST_RELATION_NODEISNONTERMINAL_H
#define DREGX_AST_RELATION_NODEISNONTERMINAL_H

#include "dregx/Ast/Enum/Type.h"

namespace dregx { namespace ast { namespace relation { 

	constexpr static bool NodeIsNonTerminal(::dregx::ast::Type t)
	{
		
		if (t == ::dregx::ast::Type::program)
		{
			return true;
		}

		if (t == ::dregx::ast::Type::deamerreserved_star__stmt__)
		{
			return true;
		}

		if (t == ::dregx::ast::Type::stmt)
		{
			return true;
		}

		if (t == ::dregx::ast::Type::word)
		{
			return true;
		}

		if (t == ::dregx::ast::Type::group)
		{
			return true;
		}

		if (t == ::dregx::ast::Type::deamerreserved_plus__word__)
		{
			return true;
		}

		if (t == ::dregx::ast::Type::or_concat)
		{
			return true;
		}

		if (t == ::dregx::ast::Type::deamerreserved_arrow__word__)
		{
			return true;
		}

		if (t == ::dregx::ast::Type::deamerreserved_star__opt_pad__OR__word__)
		{
			return true;
		}

		if (t == ::dregx::ast::Type::square)
		{
			return true;
		}

		if (t == ::dregx::ast::Type::capture)
		{
			return true;
		}

		if (t == ::dregx::ast::Type::deamerreserved_plus__capture_logic__)
		{
			return true;
		}

		if (t == ::dregx::ast::Type::capture_logic)
		{
			return true;
		}

		if (t == ::dregx::ast::Type::capture_symbols)
		{
			return true;
		}

		if (t == ::dregx::ast::Type::capture_whitespace)
		{
			return true;
		}

		if (t == ::dregx::ast::Type::capture_range)
		{
			return true;
		}

		if (t == ::dregx::ast::Type::capture_letter_range)
		{
			return true;
		}

		if (t == ::dregx::ast::Type::capture_number_range)
		{
			return true;
		}

		if (t == ::dregx::ast::Type::capture_letter)
		{
			return true;
		}

		if (t == ::dregx::ast::Type::capture_special_character)
		{
			return true;
		}

		if (t == ::dregx::ast::Type::extension_modifier)
		{
			return true;
		}

		if (t == ::dregx::ast::Type::min_repition)
		{
			return true;
		}

		if (t == ::dregx::ast::Type::deamerreserved_plus__NUMBER__)
		{
			return true;
		}

		if (t == ::dregx::ast::Type::max_repition)
		{
			return true;
		}

		if (t == ::dregx::ast::Type::standalone)
		{
			return true;
		}

		if (t == ::dregx::ast::Type::opt_pad)
		{
			return true;
		}

		if (t == ::dregx::ast::Type::optional_padding)
		{
			return true;
		}

		if (t == ::dregx::ast::Type::deamerreserved_star__padding__)
		{
			return true;
		}

		if (t == ::dregx::ast::Type::padding)
		{
			return true;
		}

		if (t == ::dregx::ast::Type::special_char_any)
		{
			return true;
		}

		if (t == ::dregx::ast::Type::any_letter)
		{
			return true;
		}

		if (t == ::dregx::ast::Type::any_letter_exclude_underscore)
		{
			return true;
		}

		if (t == ::dregx::ast::Type::any)
		{
			return true;
		}


		return false;
	}


}}}

#endif // DREGX_AST_RELATION_NODEISNONTERMINAL_H