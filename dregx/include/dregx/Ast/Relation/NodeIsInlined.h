#ifndef DREGX_AST_RELATION_NODEISINLINED_H
#define DREGX_AST_RELATION_NODEISINLINED_H

#include "dregx/Ast/Enum/Type.h"

namespace dregx { namespace ast { namespace relation { 

	constexpr static bool NodeIsInlined(::dregx::ast::Type t)
	{
		
		if (t == ::dregx::ast::Type::program)
		{
			return false;
		}

		if (t == ::dregx::ast::Type::deamerreserved_star__stmt__)
		{
			return true;
		}

		if (t == ::dregx::ast::Type::stmt)
		{
			return false;
		}

		if (t == ::dregx::ast::Type::word)
		{
			return false;
		}

		if (t == ::dregx::ast::Type::group)
		{
			return false;
		}

		if (t == ::dregx::ast::Type::deamerreserved_plus__word__)
		{
			return true;
		}

		if (t == ::dregx::ast::Type::or_concat)
		{
			return false;
		}

		if (t == ::dregx::ast::Type::deamerreserved_arrow__or_element__)
		{
			return true;
		}

		if (t == ::dregx::ast::Type::deamerreserved_star__opt_pad__OR__or_element__)
		{
			return true;
		}

		if (t == ::dregx::ast::Type::or_element)
		{
			return false;
		}

		if (t == ::dregx::ast::Type::square)
		{
			return false;
		}

		if (t == ::dregx::ast::Type::capture)
		{
			return false;
		}

		if (t == ::dregx::ast::Type::deamerreserved_star__capture_logic__)
		{
			return true;
		}

		if (t == ::dregx::ast::Type::capture_logic)
		{
			return false;
		}

		if (t == ::dregx::ast::Type::capture_symbols)
		{
			return false;
		}

		if (t == ::dregx::ast::Type::capture_whitespace)
		{
			return false;
		}

		if (t == ::dregx::ast::Type::capture_range)
		{
			return false;
		}

		if (t == ::dregx::ast::Type::capture_letter_range)
		{
			return false;
		}

		if (t == ::dregx::ast::Type::capture_number_range)
		{
			return false;
		}

		if (t == ::dregx::ast::Type::capture_number)
		{
			return false;
		}

		if (t == ::dregx::ast::Type::capture_letter)
		{
			return false;
		}

		if (t == ::dregx::ast::Type::capture_special_character)
		{
			return false;
		}

		if (t == ::dregx::ast::Type::extension_modifier)
		{
			return false;
		}

		if (t == ::dregx::ast::Type::min_repition)
		{
			return false;
		}

		if (t == ::dregx::ast::Type::deamerreserved_plus__NUMBER__)
		{
			return true;
		}

		if (t == ::dregx::ast::Type::max_repition)
		{
			return false;
		}

		if (t == ::dregx::ast::Type::standalone)
		{
			return false;
		}

		if (t == ::dregx::ast::Type::opt_pad)
		{
			return false;
		}

		if (t == ::dregx::ast::Type::optional_padding)
		{
			return false;
		}

		if (t == ::dregx::ast::Type::deamerreserved_star__padding__)
		{
			return true;
		}

		if (t == ::dregx::ast::Type::padding)
		{
			return false;
		}

		if (t == ::dregx::ast::Type::special_char_any)
		{
			return false;
		}

		if (t == ::dregx::ast::Type::any_number)
		{
			return false;
		}

		if (t == ::dregx::ast::Type::any_letter)
		{
			return false;
		}

		if (t == ::dregx::ast::Type::any_letter_exclude_underscore)
		{
			return false;
		}

		if (t == ::dregx::ast::Type::capture_structure)
		{
			return false;
		}

		if (t == ::dregx::ast::Type::any)
		{
			return false;
		}


		return false;
	}


}}}

#endif // DREGX_AST_RELATION_NODEISINLINED_H