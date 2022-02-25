#ifndef dregx_AST_VISITOR_DEAMER_VISITOR_H
#define dregx_AST_VISITOR_DEAMER_VISITOR_H

#include <Deamer/External/Cpp/Ast/Visitor.h>
#include "dregx/Ast/Node/dregx.h"
#include "dregx/Ast/Enum/Type.h"
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
#include "dregx/Ast/Node/OPTIONAL.h"
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
#include "dregx/Ast/Node/capture_number.h"
#include "dregx/Ast/Node/capture_letter.h"
#include "dregx/Ast/Node/capture_special_character.h"
#include "dregx/Ast/Node/extension_modifier.h"
#include "dregx/Ast/Node/min_repition.h"
#include "dregx/Ast/Node/deamerreserved_plus__NUMBER__.h"
#include "dregx/Ast/Node/max_repition.h"
#include "dregx/Ast/Node/standalone.h"
#include "dregx/Ast/Node/opt_pad.h"
#include "dregx/Ast/Node/optional_padding.h"
#include "dregx/Ast/Node/deamerreserved_star__padding__.h"
#include "dregx/Ast/Node/padding.h"
#include "dregx/Ast/Node/special_char_any.h"
#include "dregx/Ast/Node/any_number.h"
#include "dregx/Ast/Node/any_letter.h"
#include "dregx/Ast/Node/any_letter_exclude_underscore.h"
#include "dregx/Ast/Node/any.h"

namespace dregx { namespace ast { namespace Visitor { 

	class Visitor : public ::deamer::external::cpp::ast::Visitor
	{
	private:
	public:
		Visitor() = default;
		~Visitor() override = default;
	public:
		void Dispatch(const ::deamer::external::cpp::ast::Node* node) override
		{
			const auto enumeratedValue = static_cast<dregx::ast::Type>(node->GetType());
			switch(enumeratedValue)
			{
			case dregx::ast::Type::LEFT_CURLY_BRACKET:
			{
				Visit(static_cast<const dregx::ast::node::LEFT_CURLY_BRACKET*>(node));
				break;
			}
			case dregx::ast::Type::RIGHT_CURLY_BRACKET:
			{
				Visit(static_cast<const dregx::ast::node::RIGHT_CURLY_BRACKET*>(node));
				break;
			}
			case dregx::ast::Type::LEFT_SQUARE_BRACKET_NOT:
			{
				Visit(static_cast<const dregx::ast::node::LEFT_SQUARE_BRACKET_NOT*>(node));
				break;
			}
			case dregx::ast::Type::LEFT_SQUARE_BRACKET:
			{
				Visit(static_cast<const dregx::ast::node::LEFT_SQUARE_BRACKET*>(node));
				break;
			}
			case dregx::ast::Type::RIGHT_SQUARE_BRACKET:
			{
				Visit(static_cast<const dregx::ast::node::RIGHT_SQUARE_BRACKET*>(node));
				break;
			}
			case dregx::ast::Type::LEFT_BRACKET:
			{
				Visit(static_cast<const dregx::ast::node::LEFT_BRACKET*>(node));
				break;
			}
			case dregx::ast::Type::RIGHT_BRACKET:
			{
				Visit(static_cast<const dregx::ast::node::RIGHT_BRACKET*>(node));
				break;
			}
			case dregx::ast::Type::COMMA:
			{
				Visit(static_cast<const dregx::ast::node::COMMA*>(node));
				break;
			}
			case dregx::ast::Type::SLASH:
			{
				Visit(static_cast<const dregx::ast::node::SLASH*>(node));
				break;
			}
			case dregx::ast::Type::OR:
			{
				Visit(static_cast<const dregx::ast::node::OR*>(node));
				break;
			}
			case dregx::ast::Type::MIN:
			{
				Visit(static_cast<const dregx::ast::node::MIN*>(node));
				break;
			}
			case dregx::ast::Type::UNDERSCORE:
			{
				Visit(static_cast<const dregx::ast::node::UNDERSCORE*>(node));
				break;
			}
			case dregx::ast::Type::NOT:
			{
				Visit(static_cast<const dregx::ast::node::NOT*>(node));
				break;
			}
			case dregx::ast::Type::PLUS:
			{
				Visit(static_cast<const dregx::ast::node::PLUS*>(node));
				break;
			}
			case dregx::ast::Type::STAR:
			{
				Visit(static_cast<const dregx::ast::node::STAR*>(node));
				break;
			}
			case dregx::ast::Type::OPTIONAL:
			{
				Visit(static_cast<const dregx::ast::node::OPTIONAL*>(node));
				break;
			}
			case dregx::ast::Type::NUMBER:
			{
				Visit(static_cast<const dregx::ast::node::NUMBER*>(node));
				break;
			}
			case dregx::ast::Type::T_:
			{
				Visit(static_cast<const dregx::ast::node::T_*>(node));
				break;
			}
			case dregx::ast::Type::N_:
			{
				Visit(static_cast<const dregx::ast::node::N_*>(node));
				break;
			}
			case dregx::ast::Type::R_:
			{
				Visit(static_cast<const dregx::ast::node::R_*>(node));
				break;
			}
			case dregx::ast::Type::B_:
			{
				Visit(static_cast<const dregx::ast::node::B_*>(node));
				break;
			}
			case dregx::ast::Type::V_:
			{
				Visit(static_cast<const dregx::ast::node::V_*>(node));
				break;
			}
			case dregx::ast::Type::A_:
			{
				Visit(static_cast<const dregx::ast::node::A_*>(node));
				break;
			}
			case dregx::ast::Type::LETTER:
			{
				Visit(static_cast<const dregx::ast::node::LETTER*>(node));
				break;
			}
			case dregx::ast::Type::SPACE:
			{
				Visit(static_cast<const dregx::ast::node::SPACE*>(node));
				break;
			}
			case dregx::ast::Type::TAB:
			{
				Visit(static_cast<const dregx::ast::node::TAB*>(node));
				break;
			}
			case dregx::ast::Type::OTHER:
			{
				Visit(static_cast<const dregx::ast::node::OTHER*>(node));
				break;
			}
			case dregx::ast::Type::DELETE_ESCAPE_CHARS:
			{
				Visit(static_cast<const dregx::ast::node::DELETE_ESCAPE_CHARS*>(node));
				break;
			}

			case dregx::ast::Type::program:
			{
				Visit(static_cast<const dregx::ast::node::program*>(node));
				break;
			}
			case dregx::ast::Type::deamerreserved_star__stmt__:
			{
				Visit(static_cast<const dregx::ast::node::deamerreserved_star__stmt__*>(node));
				break;
			}
			case dregx::ast::Type::stmt:
			{
				Visit(static_cast<const dregx::ast::node::stmt*>(node));
				break;
			}
			case dregx::ast::Type::word:
			{
				Visit(static_cast<const dregx::ast::node::word*>(node));
				break;
			}
			case dregx::ast::Type::group:
			{
				Visit(static_cast<const dregx::ast::node::group*>(node));
				break;
			}
			case dregx::ast::Type::deamerreserved_plus__word__:
			{
				Visit(static_cast<const dregx::ast::node::deamerreserved_plus__word__*>(node));
				break;
			}
			case dregx::ast::Type::or_concat:
			{
				Visit(static_cast<const dregx::ast::node::or_concat*>(node));
				break;
			}
			case dregx::ast::Type::deamerreserved_arrow__word__:
			{
				Visit(static_cast<const dregx::ast::node::deamerreserved_arrow__word__*>(node));
				break;
			}
			case dregx::ast::Type::deamerreserved_star__opt_pad__OR__word__:
			{
				Visit(static_cast<const dregx::ast::node::deamerreserved_star__opt_pad__OR__word__*>(node));
				break;
			}
			case dregx::ast::Type::square:
			{
				Visit(static_cast<const dregx::ast::node::square*>(node));
				break;
			}
			case dregx::ast::Type::capture:
			{
				Visit(static_cast<const dregx::ast::node::capture*>(node));
				break;
			}
			case dregx::ast::Type::deamerreserved_plus__capture_logic__:
			{
				Visit(static_cast<const dregx::ast::node::deamerreserved_plus__capture_logic__*>(node));
				break;
			}
			case dregx::ast::Type::capture_logic:
			{
				Visit(static_cast<const dregx::ast::node::capture_logic*>(node));
				break;
			}
			case dregx::ast::Type::capture_symbols:
			{
				Visit(static_cast<const dregx::ast::node::capture_symbols*>(node));
				break;
			}
			case dregx::ast::Type::capture_whitespace:
			{
				Visit(static_cast<const dregx::ast::node::capture_whitespace*>(node));
				break;
			}
			case dregx::ast::Type::capture_range:
			{
				Visit(static_cast<const dregx::ast::node::capture_range*>(node));
				break;
			}
			case dregx::ast::Type::capture_letter_range:
			{
				Visit(static_cast<const dregx::ast::node::capture_letter_range*>(node));
				break;
			}
			case dregx::ast::Type::capture_number_range:
			{
				Visit(static_cast<const dregx::ast::node::capture_number_range*>(node));
				break;
			}
			case dregx::ast::Type::capture_number:
			{
				Visit(static_cast<const dregx::ast::node::capture_number*>(node));
				break;
			}
			case dregx::ast::Type::capture_letter:
			{
				Visit(static_cast<const dregx::ast::node::capture_letter*>(node));
				break;
			}
			case dregx::ast::Type::capture_special_character:
			{
				Visit(static_cast<const dregx::ast::node::capture_special_character*>(node));
				break;
			}
			case dregx::ast::Type::extension_modifier:
			{
				Visit(static_cast<const dregx::ast::node::extension_modifier*>(node));
				break;
			}
			case dregx::ast::Type::min_repition:
			{
				Visit(static_cast<const dregx::ast::node::min_repition*>(node));
				break;
			}
			case dregx::ast::Type::deamerreserved_plus__NUMBER__:
			{
				Visit(static_cast<const dregx::ast::node::deamerreserved_plus__NUMBER__*>(node));
				break;
			}
			case dregx::ast::Type::max_repition:
			{
				Visit(static_cast<const dregx::ast::node::max_repition*>(node));
				break;
			}
			case dregx::ast::Type::standalone:
			{
				Visit(static_cast<const dregx::ast::node::standalone*>(node));
				break;
			}
			case dregx::ast::Type::opt_pad:
			{
				Visit(static_cast<const dregx::ast::node::opt_pad*>(node));
				break;
			}
			case dregx::ast::Type::optional_padding:
			{
				Visit(static_cast<const dregx::ast::node::optional_padding*>(node));
				break;
			}
			case dregx::ast::Type::deamerreserved_star__padding__:
			{
				Visit(static_cast<const dregx::ast::node::deamerreserved_star__padding__*>(node));
				break;
			}
			case dregx::ast::Type::padding:
			{
				Visit(static_cast<const dregx::ast::node::padding*>(node));
				break;
			}
			case dregx::ast::Type::special_char_any:
			{
				Visit(static_cast<const dregx::ast::node::special_char_any*>(node));
				break;
			}
			case dregx::ast::Type::any_number:
			{
				Visit(static_cast<const dregx::ast::node::any_number*>(node));
				break;
			}
			case dregx::ast::Type::any_letter:
			{
				Visit(static_cast<const dregx::ast::node::any_letter*>(node));
				break;
			}
			case dregx::ast::Type::any_letter_exclude_underscore:
			{
				Visit(static_cast<const dregx::ast::node::any_letter_exclude_underscore*>(node));
				break;
			}
			case dregx::ast::Type::any:
			{
				Visit(static_cast<const dregx::ast::node::any*>(node));
				break;
			}
			}
		}
		virtual void Visit(const dregx::ast::node::LEFT_CURLY_BRACKET* node)
		{
		}
		virtual void Visit(const dregx::ast::node::RIGHT_CURLY_BRACKET* node)
		{
		}
		virtual void Visit(const dregx::ast::node::LEFT_SQUARE_BRACKET_NOT* node)
		{
		}
		virtual void Visit(const dregx::ast::node::LEFT_SQUARE_BRACKET* node)
		{
		}
		virtual void Visit(const dregx::ast::node::RIGHT_SQUARE_BRACKET* node)
		{
		}
		virtual void Visit(const dregx::ast::node::LEFT_BRACKET* node)
		{
		}
		virtual void Visit(const dregx::ast::node::RIGHT_BRACKET* node)
		{
		}
		virtual void Visit(const dregx::ast::node::COMMA* node)
		{
		}
		virtual void Visit(const dregx::ast::node::SLASH* node)
		{
		}
		virtual void Visit(const dregx::ast::node::OR* node)
		{
		}
		virtual void Visit(const dregx::ast::node::MIN* node)
		{
		}
		virtual void Visit(const dregx::ast::node::UNDERSCORE* node)
		{
		}
		virtual void Visit(const dregx::ast::node::NOT* node)
		{
		}
		virtual void Visit(const dregx::ast::node::PLUS* node)
		{
		}
		virtual void Visit(const dregx::ast::node::STAR* node)
		{
		}
		virtual void Visit(const dregx::ast::node::OPTIONAL* node)
		{
		}
		virtual void Visit(const dregx::ast::node::NUMBER* node)
		{
		}
		virtual void Visit(const dregx::ast::node::T_* node)
		{
		}
		virtual void Visit(const dregx::ast::node::N_* node)
		{
		}
		virtual void Visit(const dregx::ast::node::R_* node)
		{
		}
		virtual void Visit(const dregx::ast::node::B_* node)
		{
		}
		virtual void Visit(const dregx::ast::node::V_* node)
		{
		}
		virtual void Visit(const dregx::ast::node::A_* node)
		{
		}
		virtual void Visit(const dregx::ast::node::LETTER* node)
		{
		}
		virtual void Visit(const dregx::ast::node::SPACE* node)
		{
		}
		virtual void Visit(const dregx::ast::node::TAB* node)
		{
		}
		virtual void Visit(const dregx::ast::node::OTHER* node)
		{
		}
		virtual void Visit(const dregx::ast::node::DELETE_ESCAPE_CHARS* node)
		{
		}

		virtual void Visit(const dregx::ast::node::program* node)
		{
		}
		virtual void Visit(const dregx::ast::node::deamerreserved_star__stmt__* node)
		{
		}
		virtual void Visit(const dregx::ast::node::stmt* node)
		{
		}
		virtual void Visit(const dregx::ast::node::word* node)
		{
		}
		virtual void Visit(const dregx::ast::node::group* node)
		{
		}
		virtual void Visit(const dregx::ast::node::deamerreserved_plus__word__* node)
		{
		}
		virtual void Visit(const dregx::ast::node::or_concat* node)
		{
		}
		virtual void Visit(const dregx::ast::node::deamerreserved_arrow__word__* node)
		{
		}
		virtual void Visit(const dregx::ast::node::deamerreserved_star__opt_pad__OR__word__* node)
		{
		}
		virtual void Visit(const dregx::ast::node::square* node)
		{
		}
		virtual void Visit(const dregx::ast::node::capture* node)
		{
		}
		virtual void Visit(const dregx::ast::node::deamerreserved_plus__capture_logic__* node)
		{
		}
		virtual void Visit(const dregx::ast::node::capture_logic* node)
		{
		}
		virtual void Visit(const dregx::ast::node::capture_symbols* node)
		{
		}
		virtual void Visit(const dregx::ast::node::capture_whitespace* node)
		{
		}
		virtual void Visit(const dregx::ast::node::capture_range* node)
		{
		}
		virtual void Visit(const dregx::ast::node::capture_letter_range* node)
		{
		}
		virtual void Visit(const dregx::ast::node::capture_number_range* node)
		{
		}
		virtual void Visit(const dregx::ast::node::capture_number* node)
		{
		}
		virtual void Visit(const dregx::ast::node::capture_letter* node)
		{
		}
		virtual void Visit(const dregx::ast::node::capture_special_character* node)
		{
		}
		virtual void Visit(const dregx::ast::node::extension_modifier* node)
		{
		}
		virtual void Visit(const dregx::ast::node::min_repition* node)
		{
		}
		virtual void Visit(const dregx::ast::node::deamerreserved_plus__NUMBER__* node)
		{
		}
		virtual void Visit(const dregx::ast::node::max_repition* node)
		{
		}
		virtual void Visit(const dregx::ast::node::standalone* node)
		{
		}
		virtual void Visit(const dregx::ast::node::opt_pad* node)
		{
		}
		virtual void Visit(const dregx::ast::node::optional_padding* node)
		{
		}
		virtual void Visit(const dregx::ast::node::deamerreserved_star__padding__* node)
		{
		}
		virtual void Visit(const dregx::ast::node::padding* node)
		{
		}
		virtual void Visit(const dregx::ast::node::special_char_any* node)
		{
		}
		virtual void Visit(const dregx::ast::node::any_number* node)
		{
		}
		virtual void Visit(const dregx::ast::node::any_letter* node)
		{
		}
		virtual void Visit(const dregx::ast::node::any_letter_exclude_underscore* node)
		{
		}
		virtual void Visit(const dregx::ast::node::any* node)
		{
		}
	};

}}}

#endif // dregx_AST_VISITOR_DEAMER_VISITOR_H
