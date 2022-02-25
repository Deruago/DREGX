#ifndef DREGX_AST_RELATION_NODEISTERMINAL_H
#define DREGX_AST_RELATION_NODEISTERMINAL_H

#include "dregx/Ast/Enum/Type.h"

namespace dregx { namespace ast { namespace relation { 

	constexpr static bool NodeIsTerminal(::dregx::ast::Type t)
	{
		
		if (t == ::dregx::ast::Type::LEFT_CURLY_BRACKET)
		{
			return true;
		}

		if (t == ::dregx::ast::Type::RIGHT_CURLY_BRACKET)
		{
			return true;
		}

		if (t == ::dregx::ast::Type::LEFT_SQUARE_BRACKET_NOT)
		{
			return true;
		}

		if (t == ::dregx::ast::Type::LEFT_SQUARE_BRACKET)
		{
			return true;
		}

		if (t == ::dregx::ast::Type::RIGHT_SQUARE_BRACKET)
		{
			return true;
		}

		if (t == ::dregx::ast::Type::LEFT_BRACKET)
		{
			return true;
		}

		if (t == ::dregx::ast::Type::RIGHT_BRACKET)
		{
			return true;
		}

		if (t == ::dregx::ast::Type::COMMA)
		{
			return true;
		}

		if (t == ::dregx::ast::Type::SLASH)
		{
			return true;
		}

		if (t == ::dregx::ast::Type::OR)
		{
			return true;
		}

		if (t == ::dregx::ast::Type::MIN)
		{
			return true;
		}

		if (t == ::dregx::ast::Type::UNDERSCORE)
		{
			return true;
		}

		if (t == ::dregx::ast::Type::NOT)
		{
			return true;
		}

		if (t == ::dregx::ast::Type::PLUS)
		{
			return true;
		}

		if (t == ::dregx::ast::Type::STAR)
		{
			return true;
		}

		if (t == ::dregx::ast::Type::OPTIONAL)
		{
			return true;
		}

		if (t == ::dregx::ast::Type::NUMBER)
		{
			return true;
		}

		if (t == ::dregx::ast::Type::T_)
		{
			return true;
		}

		if (t == ::dregx::ast::Type::N_)
		{
			return true;
		}

		if (t == ::dregx::ast::Type::R_)
		{
			return true;
		}

		if (t == ::dregx::ast::Type::B_)
		{
			return true;
		}

		if (t == ::dregx::ast::Type::V_)
		{
			return true;
		}

		if (t == ::dregx::ast::Type::A_)
		{
			return true;
		}

		if (t == ::dregx::ast::Type::LETTER)
		{
			return true;
		}

		if (t == ::dregx::ast::Type::SPACE)
		{
			return true;
		}

		if (t == ::dregx::ast::Type::TAB)
		{
			return true;
		}

		if (t == ::dregx::ast::Type::OTHER)
		{
			return true;
		}

		if (t == ::dregx::ast::Type::DELETE_ESCAPE_CHARS)
		{
			return true;
		}


		return false;
	}


}}}

#endif // DREGX_AST_RELATION_NODEISTERMINAL_H