#ifndef dregx_AST_LISTENER_DEAMER_LISTENER_H
#define dregx_AST_LISTENER_DEAMER_LISTENER_H

#include <Deamer/External/Cpp/Ast/Listener.h>
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
#include "dregx/Ast/Node/deamerreserved_arrow__or_element__.h"
#include "dregx/Ast/Node/deamerreserved_star__opt_pad__OR__or_element__.h"
#include "dregx/Ast/Node/or_element.h"
#include "dregx/Ast/Node/square.h"
#include "dregx/Ast/Node/capture.h"
#include "dregx/Ast/Node/deamerreserved_star__capture_logic__.h"
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
#include "dregx/Ast/Node/capture_structure.h"
#include "dregx/Ast/Node/any.h"

namespace dregx { namespace ast { namespace listener { 

	class Listener : public ::deamer::external::cpp::ast::Listener
	{
	private:
	public:
		Listener() = default;
		~Listener() override = default;
	public:
		void Dispatch(const ::deamer::external::cpp::ast::Node* node) override
		{
			const auto enumeratedValue = static_cast<dregx::ast::Type>(node->GetType());
			switch(enumeratedValue)
			{
			case dregx::ast::Type::LEFT_CURLY_BRACKET:
			{
				Listen(static_cast<const dregx::ast::node::LEFT_CURLY_BRACKET*>(node));
				break;
			}
			case dregx::ast::Type::RIGHT_CURLY_BRACKET:
			{
				Listen(static_cast<const dregx::ast::node::RIGHT_CURLY_BRACKET*>(node));
				break;
			}
			case dregx::ast::Type::LEFT_SQUARE_BRACKET_NOT:
			{
				Listen(static_cast<const dregx::ast::node::LEFT_SQUARE_BRACKET_NOT*>(node));
				break;
			}
			case dregx::ast::Type::LEFT_SQUARE_BRACKET:
			{
				Listen(static_cast<const dregx::ast::node::LEFT_SQUARE_BRACKET*>(node));
				break;
			}
			case dregx::ast::Type::RIGHT_SQUARE_BRACKET:
			{
				Listen(static_cast<const dregx::ast::node::RIGHT_SQUARE_BRACKET*>(node));
				break;
			}
			case dregx::ast::Type::LEFT_BRACKET:
			{
				Listen(static_cast<const dregx::ast::node::LEFT_BRACKET*>(node));
				break;
			}
			case dregx::ast::Type::RIGHT_BRACKET:
			{
				Listen(static_cast<const dregx::ast::node::RIGHT_BRACKET*>(node));
				break;
			}
			case dregx::ast::Type::COMMA:
			{
				Listen(static_cast<const dregx::ast::node::COMMA*>(node));
				break;
			}
			case dregx::ast::Type::SLASH:
			{
				Listen(static_cast<const dregx::ast::node::SLASH*>(node));
				break;
			}
			case dregx::ast::Type::OR:
			{
				Listen(static_cast<const dregx::ast::node::OR*>(node));
				break;
			}
			case dregx::ast::Type::MIN:
			{
				Listen(static_cast<const dregx::ast::node::MIN*>(node));
				break;
			}
			case dregx::ast::Type::UNDERSCORE:
			{
				Listen(static_cast<const dregx::ast::node::UNDERSCORE*>(node));
				break;
			}
			case dregx::ast::Type::NOT:
			{
				Listen(static_cast<const dregx::ast::node::NOT*>(node));
				break;
			}
			case dregx::ast::Type::PLUS:
			{
				Listen(static_cast<const dregx::ast::node::PLUS*>(node));
				break;
			}
			case dregx::ast::Type::STAR:
			{
				Listen(static_cast<const dregx::ast::node::STAR*>(node));
				break;
			}
			case dregx::ast::Type::OPTIONAL:
			{
				Listen(static_cast<const dregx::ast::node::OPTIONAL*>(node));
				break;
			}
			case dregx::ast::Type::NUMBER:
			{
				Listen(static_cast<const dregx::ast::node::NUMBER*>(node));
				break;
			}
			case dregx::ast::Type::T_:
			{
				Listen(static_cast<const dregx::ast::node::T_*>(node));
				break;
			}
			case dregx::ast::Type::N_:
			{
				Listen(static_cast<const dregx::ast::node::N_*>(node));
				break;
			}
			case dregx::ast::Type::R_:
			{
				Listen(static_cast<const dregx::ast::node::R_*>(node));
				break;
			}
			case dregx::ast::Type::B_:
			{
				Listen(static_cast<const dregx::ast::node::B_*>(node));
				break;
			}
			case dregx::ast::Type::V_:
			{
				Listen(static_cast<const dregx::ast::node::V_*>(node));
				break;
			}
			case dregx::ast::Type::A_:
			{
				Listen(static_cast<const dregx::ast::node::A_*>(node));
				break;
			}
			case dregx::ast::Type::LETTER:
			{
				Listen(static_cast<const dregx::ast::node::LETTER*>(node));
				break;
			}
			case dregx::ast::Type::SPACE:
			{
				Listen(static_cast<const dregx::ast::node::SPACE*>(node));
				break;
			}
			case dregx::ast::Type::TAB:
			{
				Listen(static_cast<const dregx::ast::node::TAB*>(node));
				break;
			}
			case dregx::ast::Type::OTHER:
			{
				Listen(static_cast<const dregx::ast::node::OTHER*>(node));
				break;
			}
			case dregx::ast::Type::DELETE_ESCAPE_CHARS:
			{
				Listen(static_cast<const dregx::ast::node::DELETE_ESCAPE_CHARS*>(node));
				break;
			}

			case dregx::ast::Type::program:
			{
				Listen(static_cast<const dregx::ast::node::program*>(node));
				DefaultAction(node);
				break;
			}
			case dregx::ast::Type::deamerreserved_star__stmt__:
			{
				Listen(static_cast<const dregx::ast::node::deamerreserved_star__stmt__*>(node));
				DefaultAction(node);
				break;
			}
			case dregx::ast::Type::stmt:
			{
				Listen(static_cast<const dregx::ast::node::stmt*>(node));
				DefaultAction(node);
				break;
			}
			case dregx::ast::Type::word:
			{
				Listen(static_cast<const dregx::ast::node::word*>(node));
				DefaultAction(node);
				break;
			}
			case dregx::ast::Type::group:
			{
				Listen(static_cast<const dregx::ast::node::group*>(node));
				DefaultAction(node);
				break;
			}
			case dregx::ast::Type::deamerreserved_plus__word__:
			{
				Listen(static_cast<const dregx::ast::node::deamerreserved_plus__word__*>(node));
				DefaultAction(node);
				break;
			}
			case dregx::ast::Type::or_concat:
			{
				Listen(static_cast<const dregx::ast::node::or_concat*>(node));
				DefaultAction(node);
				break;
			}
			case dregx::ast::Type::deamerreserved_arrow__or_element__:
			{
				Listen(static_cast<const dregx::ast::node::deamerreserved_arrow__or_element__*>(node));
				DefaultAction(node);
				break;
			}
			case dregx::ast::Type::deamerreserved_star__opt_pad__OR__or_element__:
			{
				Listen(static_cast<const dregx::ast::node::deamerreserved_star__opt_pad__OR__or_element__*>(node));
				DefaultAction(node);
				break;
			}
			case dregx::ast::Type::or_element:
			{
				Listen(static_cast<const dregx::ast::node::or_element*>(node));
				DefaultAction(node);
				break;
			}
			case dregx::ast::Type::square:
			{
				Listen(static_cast<const dregx::ast::node::square*>(node));
				DefaultAction(node);
				break;
			}
			case dregx::ast::Type::capture:
			{
				Listen(static_cast<const dregx::ast::node::capture*>(node));
				DefaultAction(node);
				break;
			}
			case dregx::ast::Type::deamerreserved_star__capture_logic__:
			{
				Listen(static_cast<const dregx::ast::node::deamerreserved_star__capture_logic__*>(node));
				DefaultAction(node);
				break;
			}
			case dregx::ast::Type::capture_logic:
			{
				Listen(static_cast<const dregx::ast::node::capture_logic*>(node));
				DefaultAction(node);
				break;
			}
			case dregx::ast::Type::capture_symbols:
			{
				Listen(static_cast<const dregx::ast::node::capture_symbols*>(node));
				DefaultAction(node);
				break;
			}
			case dregx::ast::Type::capture_whitespace:
			{
				Listen(static_cast<const dregx::ast::node::capture_whitespace*>(node));
				DefaultAction(node);
				break;
			}
			case dregx::ast::Type::capture_range:
			{
				Listen(static_cast<const dregx::ast::node::capture_range*>(node));
				DefaultAction(node);
				break;
			}
			case dregx::ast::Type::capture_letter_range:
			{
				Listen(static_cast<const dregx::ast::node::capture_letter_range*>(node));
				DefaultAction(node);
				break;
			}
			case dregx::ast::Type::capture_number_range:
			{
				Listen(static_cast<const dregx::ast::node::capture_number_range*>(node));
				DefaultAction(node);
				break;
			}
			case dregx::ast::Type::capture_number:
			{
				Listen(static_cast<const dregx::ast::node::capture_number*>(node));
				DefaultAction(node);
				break;
			}
			case dregx::ast::Type::capture_letter:
			{
				Listen(static_cast<const dregx::ast::node::capture_letter*>(node));
				DefaultAction(node);
				break;
			}
			case dregx::ast::Type::capture_special_character:
			{
				Listen(static_cast<const dregx::ast::node::capture_special_character*>(node));
				DefaultAction(node);
				break;
			}
			case dregx::ast::Type::extension_modifier:
			{
				Listen(static_cast<const dregx::ast::node::extension_modifier*>(node));
				DefaultAction(node);
				break;
			}
			case dregx::ast::Type::min_repition:
			{
				Listen(static_cast<const dregx::ast::node::min_repition*>(node));
				DefaultAction(node);
				break;
			}
			case dregx::ast::Type::deamerreserved_plus__NUMBER__:
			{
				Listen(static_cast<const dregx::ast::node::deamerreserved_plus__NUMBER__*>(node));
				DefaultAction(node);
				break;
			}
			case dregx::ast::Type::max_repition:
			{
				Listen(static_cast<const dregx::ast::node::max_repition*>(node));
				DefaultAction(node);
				break;
			}
			case dregx::ast::Type::standalone:
			{
				Listen(static_cast<const dregx::ast::node::standalone*>(node));
				DefaultAction(node);
				break;
			}
			case dregx::ast::Type::opt_pad:
			{
				Listen(static_cast<const dregx::ast::node::opt_pad*>(node));
				DefaultAction(node);
				break;
			}
			case dregx::ast::Type::optional_padding:
			{
				Listen(static_cast<const dregx::ast::node::optional_padding*>(node));
				DefaultAction(node);
				break;
			}
			case dregx::ast::Type::deamerreserved_star__padding__:
			{
				Listen(static_cast<const dregx::ast::node::deamerreserved_star__padding__*>(node));
				DefaultAction(node);
				break;
			}
			case dregx::ast::Type::padding:
			{
				Listen(static_cast<const dregx::ast::node::padding*>(node));
				DefaultAction(node);
				break;
			}
			case dregx::ast::Type::special_char_any:
			{
				Listen(static_cast<const dregx::ast::node::special_char_any*>(node));
				DefaultAction(node);
				break;
			}
			case dregx::ast::Type::any_number:
			{
				Listen(static_cast<const dregx::ast::node::any_number*>(node));
				DefaultAction(node);
				break;
			}
			case dregx::ast::Type::any_letter:
			{
				Listen(static_cast<const dregx::ast::node::any_letter*>(node));
				DefaultAction(node);
				break;
			}
			case dregx::ast::Type::any_letter_exclude_underscore:
			{
				Listen(static_cast<const dregx::ast::node::any_letter_exclude_underscore*>(node));
				DefaultAction(node);
				break;
			}
			case dregx::ast::Type::capture_structure:
			{
				Listen(static_cast<const dregx::ast::node::capture_structure*>(node));
				DefaultAction(node);
				break;
			}
			case dregx::ast::Type::any:
			{
				Listen(static_cast<const dregx::ast::node::any*>(node));
				DefaultAction(node);
				break;
			}
			}
		}
		virtual void Listen(const dregx::ast::node::LEFT_CURLY_BRACKET* node)
		{
		}
		virtual void Listen(const dregx::ast::node::RIGHT_CURLY_BRACKET* node)
		{
		}
		virtual void Listen(const dregx::ast::node::LEFT_SQUARE_BRACKET_NOT* node)
		{
		}
		virtual void Listen(const dregx::ast::node::LEFT_SQUARE_BRACKET* node)
		{
		}
		virtual void Listen(const dregx::ast::node::RIGHT_SQUARE_BRACKET* node)
		{
		}
		virtual void Listen(const dregx::ast::node::LEFT_BRACKET* node)
		{
		}
		virtual void Listen(const dregx::ast::node::RIGHT_BRACKET* node)
		{
		}
		virtual void Listen(const dregx::ast::node::COMMA* node)
		{
		}
		virtual void Listen(const dregx::ast::node::SLASH* node)
		{
		}
		virtual void Listen(const dregx::ast::node::OR* node)
		{
		}
		virtual void Listen(const dregx::ast::node::MIN* node)
		{
		}
		virtual void Listen(const dregx::ast::node::UNDERSCORE* node)
		{
		}
		virtual void Listen(const dregx::ast::node::NOT* node)
		{
		}
		virtual void Listen(const dregx::ast::node::PLUS* node)
		{
		}
		virtual void Listen(const dregx::ast::node::STAR* node)
		{
		}
		virtual void Listen(const dregx::ast::node::OPTIONAL* node)
		{
		}
		virtual void Listen(const dregx::ast::node::NUMBER* node)
		{
		}
		virtual void Listen(const dregx::ast::node::T_* node)
		{
		}
		virtual void Listen(const dregx::ast::node::N_* node)
		{
		}
		virtual void Listen(const dregx::ast::node::R_* node)
		{
		}
		virtual void Listen(const dregx::ast::node::B_* node)
		{
		}
		virtual void Listen(const dregx::ast::node::V_* node)
		{
		}
		virtual void Listen(const dregx::ast::node::A_* node)
		{
		}
		virtual void Listen(const dregx::ast::node::LETTER* node)
		{
		}
		virtual void Listen(const dregx::ast::node::SPACE* node)
		{
		}
		virtual void Listen(const dregx::ast::node::TAB* node)
		{
		}
		virtual void Listen(const dregx::ast::node::OTHER* node)
		{
		}
		virtual void Listen(const dregx::ast::node::DELETE_ESCAPE_CHARS* node)
		{
		}

		virtual void Listen(const dregx::ast::node::program* node)
		{
		}
		virtual void Listen(const dregx::ast::node::deamerreserved_star__stmt__* node)
		{
		}
		virtual void Listen(const dregx::ast::node::stmt* node)
		{
		}
		virtual void Listen(const dregx::ast::node::word* node)
		{
		}
		virtual void Listen(const dregx::ast::node::group* node)
		{
		}
		virtual void Listen(const dregx::ast::node::deamerreserved_plus__word__* node)
		{
		}
		virtual void Listen(const dregx::ast::node::or_concat* node)
		{
		}
		virtual void Listen(const dregx::ast::node::deamerreserved_arrow__or_element__* node)
		{
		}
		virtual void Listen(const dregx::ast::node::deamerreserved_star__opt_pad__OR__or_element__* node)
		{
		}
		virtual void Listen(const dregx::ast::node::or_element* node)
		{
		}
		virtual void Listen(const dregx::ast::node::square* node)
		{
		}
		virtual void Listen(const dregx::ast::node::capture* node)
		{
		}
		virtual void Listen(const dregx::ast::node::deamerreserved_star__capture_logic__* node)
		{
		}
		virtual void Listen(const dregx::ast::node::capture_logic* node)
		{
		}
		virtual void Listen(const dregx::ast::node::capture_symbols* node)
		{
		}
		virtual void Listen(const dregx::ast::node::capture_whitespace* node)
		{
		}
		virtual void Listen(const dregx::ast::node::capture_range* node)
		{
		}
		virtual void Listen(const dregx::ast::node::capture_letter_range* node)
		{
		}
		virtual void Listen(const dregx::ast::node::capture_number_range* node)
		{
		}
		virtual void Listen(const dregx::ast::node::capture_number* node)
		{
		}
		virtual void Listen(const dregx::ast::node::capture_letter* node)
		{
		}
		virtual void Listen(const dregx::ast::node::capture_special_character* node)
		{
		}
		virtual void Listen(const dregx::ast::node::extension_modifier* node)
		{
		}
		virtual void Listen(const dregx::ast::node::min_repition* node)
		{
		}
		virtual void Listen(const dregx::ast::node::deamerreserved_plus__NUMBER__* node)
		{
		}
		virtual void Listen(const dregx::ast::node::max_repition* node)
		{
		}
		virtual void Listen(const dregx::ast::node::standalone* node)
		{
		}
		virtual void Listen(const dregx::ast::node::opt_pad* node)
		{
		}
		virtual void Listen(const dregx::ast::node::optional_padding* node)
		{
		}
		virtual void Listen(const dregx::ast::node::deamerreserved_star__padding__* node)
		{
		}
		virtual void Listen(const dregx::ast::node::padding* node)
		{
		}
		virtual void Listen(const dregx::ast::node::special_char_any* node)
		{
		}
		virtual void Listen(const dregx::ast::node::any_number* node)
		{
		}
		virtual void Listen(const dregx::ast::node::any_letter* node)
		{
		}
		virtual void Listen(const dregx::ast::node::any_letter_exclude_underscore* node)
		{
		}
		virtual void Listen(const dregx::ast::node::capture_structure* node)
		{
		}
		virtual void Listen(const dregx::ast::node::any* node)
		{
		}
	private:
		void DefaultAction(const ::deamer::external::cpp::ast::Node* node)
		{
			for(const auto* child : node->GetNodes())
			{
				Dispatch(child);
			}
		}
	};

}}}

#endif // dregx_AST_LISTENER_DEAMER_LISTENER_H
