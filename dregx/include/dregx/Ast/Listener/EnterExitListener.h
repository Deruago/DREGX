#ifndef DREGX_AST_LISTENER_ENTEREXITLISTENER_H
#define DREGX_AST_LISTENER_ENTEREXITLISTENER_H

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

#include <Deamer/External/Cpp/Ast/Listener.h>
#include <Deamer/Algorithm/Tree/DFS.h>

namespace dregx { namespace ast { namespace listener { 

	class EnterExitListener : public ::deamer::external::cpp::ast::Listener
	{
	private:
	public:
		EnterExitListener() = default;
		~EnterExitListener() override = default;

	public:
		void Dispatch(const ::deamer::external::cpp::ast::Node* node)  override
		{
			::deamer::algorithm::tree::DFS::Execute::Heap::Search(node,
				&::deamer::external::cpp::ast::Node::GetParent,
				&::deamer::external::cpp::ast::Node::GetNodes,
				&EnterExitListener::DispatchEntry,
				&EnterExitListener::DispatchExit,
				this);
		}

		void DispatchEntry(const ::deamer::external::cpp::ast::Node* node) 
		{
			const auto enumeratedValue = static_cast<dregx::ast::Type>(node->GetType());
			switch(enumeratedValue)
			{
			// Terminal cases
			
			case dregx::ast::Type::LEFT_CURLY_BRACKET:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const dregx::ast::node::LEFT_CURLY_BRACKET*>(node));
				break;
			}

			case dregx::ast::Type::RIGHT_CURLY_BRACKET:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const dregx::ast::node::RIGHT_CURLY_BRACKET*>(node));
				break;
			}

			case dregx::ast::Type::LEFT_SQUARE_BRACKET_NOT:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const dregx::ast::node::LEFT_SQUARE_BRACKET_NOT*>(node));
				break;
			}

			case dregx::ast::Type::LEFT_SQUARE_BRACKET:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const dregx::ast::node::LEFT_SQUARE_BRACKET*>(node));
				break;
			}

			case dregx::ast::Type::RIGHT_SQUARE_BRACKET:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const dregx::ast::node::RIGHT_SQUARE_BRACKET*>(node));
				break;
			}

			case dregx::ast::Type::LEFT_BRACKET:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const dregx::ast::node::LEFT_BRACKET*>(node));
				break;
			}

			case dregx::ast::Type::RIGHT_BRACKET:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const dregx::ast::node::RIGHT_BRACKET*>(node));
				break;
			}

			case dregx::ast::Type::COMMA:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const dregx::ast::node::COMMA*>(node));
				break;
			}

			case dregx::ast::Type::SLASH:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const dregx::ast::node::SLASH*>(node));
				break;
			}

			case dregx::ast::Type::OR:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const dregx::ast::node::OR*>(node));
				break;
			}

			case dregx::ast::Type::MIN:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const dregx::ast::node::MIN*>(node));
				break;
			}

			case dregx::ast::Type::UNDERSCORE:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const dregx::ast::node::UNDERSCORE*>(node));
				break;
			}

			case dregx::ast::Type::NOT:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const dregx::ast::node::NOT*>(node));
				break;
			}

			case dregx::ast::Type::PLUS:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const dregx::ast::node::PLUS*>(node));
				break;
			}

			case dregx::ast::Type::STAR:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const dregx::ast::node::STAR*>(node));
				break;
			}

			case dregx::ast::Type::OPTIONAL:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const dregx::ast::node::OPTIONAL*>(node));
				break;
			}

			case dregx::ast::Type::NUMBER:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const dregx::ast::node::NUMBER*>(node));
				break;
			}

			case dregx::ast::Type::T_:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const dregx::ast::node::T_*>(node));
				break;
			}

			case dregx::ast::Type::N_:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const dregx::ast::node::N_*>(node));
				break;
			}

			case dregx::ast::Type::R_:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const dregx::ast::node::R_*>(node));
				break;
			}

			case dregx::ast::Type::B_:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const dregx::ast::node::B_*>(node));
				break;
			}

			case dregx::ast::Type::V_:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const dregx::ast::node::V_*>(node));
				break;
			}

			case dregx::ast::Type::A_:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const dregx::ast::node::A_*>(node));
				break;
			}

			case dregx::ast::Type::LETTER:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const dregx::ast::node::LETTER*>(node));
				break;
			}

			case dregx::ast::Type::SPACE:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const dregx::ast::node::SPACE*>(node));
				break;
			}

			case dregx::ast::Type::TAB:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const dregx::ast::node::TAB*>(node));
				break;
			}

			case dregx::ast::Type::OTHER:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const dregx::ast::node::OTHER*>(node));
				break;
			}

			case dregx::ast::Type::DELETE_ESCAPE_CHARS:
			{
				// Entry terminal
				EnterAnything(node);
				EnterTerminal(node);
				ListenEntry(static_cast<const dregx::ast::node::DELETE_ESCAPE_CHARS*>(node));
				break;
			}


			// Nonterminal cases
			
			case dregx::ast::Type::program:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const dregx::ast::node::program*>(node));
				break;
			}

			case dregx::ast::Type::deamerreserved_star__stmt__:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const dregx::ast::node::deamerreserved_star__stmt__*>(node));
				break;
			}

			case dregx::ast::Type::stmt:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const dregx::ast::node::stmt*>(node));
				break;
			}

			case dregx::ast::Type::word:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const dregx::ast::node::word*>(node));
				break;
			}

			case dregx::ast::Type::group:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const dregx::ast::node::group*>(node));
				break;
			}

			case dregx::ast::Type::deamerreserved_plus__word__:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const dregx::ast::node::deamerreserved_plus__word__*>(node));
				break;
			}

			case dregx::ast::Type::or_concat:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const dregx::ast::node::or_concat*>(node));
				break;
			}

			case dregx::ast::Type::deamerreserved_arrow__or_element__:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const dregx::ast::node::deamerreserved_arrow__or_element__*>(node));
				break;
			}

			case dregx::ast::Type::deamerreserved_star__opt_pad__OR__or_element__:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const dregx::ast::node::deamerreserved_star__opt_pad__OR__or_element__*>(node));
				break;
			}

			case dregx::ast::Type::or_element:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const dregx::ast::node::or_element*>(node));
				break;
			}

			case dregx::ast::Type::square:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const dregx::ast::node::square*>(node));
				break;
			}

			case dregx::ast::Type::capture:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const dregx::ast::node::capture*>(node));
				break;
			}

			case dregx::ast::Type::deamerreserved_star__capture_logic__:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const dregx::ast::node::deamerreserved_star__capture_logic__*>(node));
				break;
			}

			case dregx::ast::Type::capture_logic:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const dregx::ast::node::capture_logic*>(node));
				break;
			}

			case dregx::ast::Type::capture_symbols:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const dregx::ast::node::capture_symbols*>(node));
				break;
			}

			case dregx::ast::Type::capture_whitespace:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const dregx::ast::node::capture_whitespace*>(node));
				break;
			}

			case dregx::ast::Type::capture_range:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const dregx::ast::node::capture_range*>(node));
				break;
			}

			case dregx::ast::Type::capture_letter_range:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const dregx::ast::node::capture_letter_range*>(node));
				break;
			}

			case dregx::ast::Type::capture_number_range:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const dregx::ast::node::capture_number_range*>(node));
				break;
			}

			case dregx::ast::Type::capture_number:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const dregx::ast::node::capture_number*>(node));
				break;
			}

			case dregx::ast::Type::capture_letter:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const dregx::ast::node::capture_letter*>(node));
				break;
			}

			case dregx::ast::Type::capture_special_character:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const dregx::ast::node::capture_special_character*>(node));
				break;
			}

			case dregx::ast::Type::extension_modifier:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const dregx::ast::node::extension_modifier*>(node));
				break;
			}

			case dregx::ast::Type::min_repition:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const dregx::ast::node::min_repition*>(node));
				break;
			}

			case dregx::ast::Type::deamerreserved_plus__NUMBER__:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const dregx::ast::node::deamerreserved_plus__NUMBER__*>(node));
				break;
			}

			case dregx::ast::Type::max_repition:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const dregx::ast::node::max_repition*>(node));
				break;
			}

			case dregx::ast::Type::standalone:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const dregx::ast::node::standalone*>(node));
				break;
			}

			case dregx::ast::Type::opt_pad:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const dregx::ast::node::opt_pad*>(node));
				break;
			}

			case dregx::ast::Type::optional_padding:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const dregx::ast::node::optional_padding*>(node));
				break;
			}

			case dregx::ast::Type::deamerreserved_star__padding__:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const dregx::ast::node::deamerreserved_star__padding__*>(node));
				break;
			}

			case dregx::ast::Type::padding:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const dregx::ast::node::padding*>(node));
				break;
			}

			case dregx::ast::Type::special_char_any:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const dregx::ast::node::special_char_any*>(node));
				break;
			}

			case dregx::ast::Type::any_number:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const dregx::ast::node::any_number*>(node));
				break;
			}

			case dregx::ast::Type::any_letter:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const dregx::ast::node::any_letter*>(node));
				break;
			}

			case dregx::ast::Type::any_letter_exclude_underscore:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const dregx::ast::node::any_letter_exclude_underscore*>(node));
				break;
			}

			case dregx::ast::Type::capture_structure:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const dregx::ast::node::capture_structure*>(node));
				break;
			}

			case dregx::ast::Type::any:
			{
				// Enter nonterminal
				EnterAnything(node);
				EnterNonTerminal(node);
				ListenEntry(static_cast<const dregx::ast::node::any*>(node));
				break;
			}

			}
		}

		void DispatchExit(const ::deamer::external::cpp::ast::Node* node) 
		{
			const auto enumeratedValue = static_cast<dregx::ast::Type>(node->GetType());
			switch(enumeratedValue)
			{
			// Terminal cases
			
			case dregx::ast::Type::LEFT_CURLY_BRACKET:
			{
				// Exit terminal
				ListenExit(static_cast<const dregx::ast::node::LEFT_CURLY_BRACKET*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case dregx::ast::Type::RIGHT_CURLY_BRACKET:
			{
				// Exit terminal
				ListenExit(static_cast<const dregx::ast::node::RIGHT_CURLY_BRACKET*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case dregx::ast::Type::LEFT_SQUARE_BRACKET_NOT:
			{
				// Exit terminal
				ListenExit(static_cast<const dregx::ast::node::LEFT_SQUARE_BRACKET_NOT*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case dregx::ast::Type::LEFT_SQUARE_BRACKET:
			{
				// Exit terminal
				ListenExit(static_cast<const dregx::ast::node::LEFT_SQUARE_BRACKET*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case dregx::ast::Type::RIGHT_SQUARE_BRACKET:
			{
				// Exit terminal
				ListenExit(static_cast<const dregx::ast::node::RIGHT_SQUARE_BRACKET*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case dregx::ast::Type::LEFT_BRACKET:
			{
				// Exit terminal
				ListenExit(static_cast<const dregx::ast::node::LEFT_BRACKET*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case dregx::ast::Type::RIGHT_BRACKET:
			{
				// Exit terminal
				ListenExit(static_cast<const dregx::ast::node::RIGHT_BRACKET*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case dregx::ast::Type::COMMA:
			{
				// Exit terminal
				ListenExit(static_cast<const dregx::ast::node::COMMA*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case dregx::ast::Type::SLASH:
			{
				// Exit terminal
				ListenExit(static_cast<const dregx::ast::node::SLASH*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case dregx::ast::Type::OR:
			{
				// Exit terminal
				ListenExit(static_cast<const dregx::ast::node::OR*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case dregx::ast::Type::MIN:
			{
				// Exit terminal
				ListenExit(static_cast<const dregx::ast::node::MIN*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case dregx::ast::Type::UNDERSCORE:
			{
				// Exit terminal
				ListenExit(static_cast<const dregx::ast::node::UNDERSCORE*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case dregx::ast::Type::NOT:
			{
				// Exit terminal
				ListenExit(static_cast<const dregx::ast::node::NOT*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case dregx::ast::Type::PLUS:
			{
				// Exit terminal
				ListenExit(static_cast<const dregx::ast::node::PLUS*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case dregx::ast::Type::STAR:
			{
				// Exit terminal
				ListenExit(static_cast<const dregx::ast::node::STAR*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case dregx::ast::Type::OPTIONAL:
			{
				// Exit terminal
				ListenExit(static_cast<const dregx::ast::node::OPTIONAL*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case dregx::ast::Type::NUMBER:
			{
				// Exit terminal
				ListenExit(static_cast<const dregx::ast::node::NUMBER*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case dregx::ast::Type::T_:
			{
				// Exit terminal
				ListenExit(static_cast<const dregx::ast::node::T_*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case dregx::ast::Type::N_:
			{
				// Exit terminal
				ListenExit(static_cast<const dregx::ast::node::N_*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case dregx::ast::Type::R_:
			{
				// Exit terminal
				ListenExit(static_cast<const dregx::ast::node::R_*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case dregx::ast::Type::B_:
			{
				// Exit terminal
				ListenExit(static_cast<const dregx::ast::node::B_*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case dregx::ast::Type::V_:
			{
				// Exit terminal
				ListenExit(static_cast<const dregx::ast::node::V_*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case dregx::ast::Type::A_:
			{
				// Exit terminal
				ListenExit(static_cast<const dregx::ast::node::A_*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case dregx::ast::Type::LETTER:
			{
				// Exit terminal
				ListenExit(static_cast<const dregx::ast::node::LETTER*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case dregx::ast::Type::SPACE:
			{
				// Exit terminal
				ListenExit(static_cast<const dregx::ast::node::SPACE*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case dregx::ast::Type::TAB:
			{
				// Exit terminal
				ListenExit(static_cast<const dregx::ast::node::TAB*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case dregx::ast::Type::OTHER:
			{
				// Exit terminal
				ListenExit(static_cast<const dregx::ast::node::OTHER*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}

			case dregx::ast::Type::DELETE_ESCAPE_CHARS:
			{
				// Exit terminal
				ListenExit(static_cast<const dregx::ast::node::DELETE_ESCAPE_CHARS*>(node));
				ExitTerminal(node);
				ExitAnything(node);
				break;
			}


			// Nonterminal cases
			
			case dregx::ast::Type::program:
			{
				// Exit nonterminal
				ListenExit(static_cast<const dregx::ast::node::program*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case dregx::ast::Type::deamerreserved_star__stmt__:
			{
				// Exit nonterminal
				ListenExit(static_cast<const dregx::ast::node::deamerreserved_star__stmt__*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case dregx::ast::Type::stmt:
			{
				// Exit nonterminal
				ListenExit(static_cast<const dregx::ast::node::stmt*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case dregx::ast::Type::word:
			{
				// Exit nonterminal
				ListenExit(static_cast<const dregx::ast::node::word*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case dregx::ast::Type::group:
			{
				// Exit nonterminal
				ListenExit(static_cast<const dregx::ast::node::group*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case dregx::ast::Type::deamerreserved_plus__word__:
			{
				// Exit nonterminal
				ListenExit(static_cast<const dregx::ast::node::deamerreserved_plus__word__*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case dregx::ast::Type::or_concat:
			{
				// Exit nonterminal
				ListenExit(static_cast<const dregx::ast::node::or_concat*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case dregx::ast::Type::deamerreserved_arrow__or_element__:
			{
				// Exit nonterminal
				ListenExit(static_cast<const dregx::ast::node::deamerreserved_arrow__or_element__*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case dregx::ast::Type::deamerreserved_star__opt_pad__OR__or_element__:
			{
				// Exit nonterminal
				ListenExit(static_cast<const dregx::ast::node::deamerreserved_star__opt_pad__OR__or_element__*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case dregx::ast::Type::or_element:
			{
				// Exit nonterminal
				ListenExit(static_cast<const dregx::ast::node::or_element*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case dregx::ast::Type::square:
			{
				// Exit nonterminal
				ListenExit(static_cast<const dregx::ast::node::square*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case dregx::ast::Type::capture:
			{
				// Exit nonterminal
				ListenExit(static_cast<const dregx::ast::node::capture*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case dregx::ast::Type::deamerreserved_star__capture_logic__:
			{
				// Exit nonterminal
				ListenExit(static_cast<const dregx::ast::node::deamerreserved_star__capture_logic__*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case dregx::ast::Type::capture_logic:
			{
				// Exit nonterminal
				ListenExit(static_cast<const dregx::ast::node::capture_logic*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case dregx::ast::Type::capture_symbols:
			{
				// Exit nonterminal
				ListenExit(static_cast<const dregx::ast::node::capture_symbols*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case dregx::ast::Type::capture_whitespace:
			{
				// Exit nonterminal
				ListenExit(static_cast<const dregx::ast::node::capture_whitespace*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case dregx::ast::Type::capture_range:
			{
				// Exit nonterminal
				ListenExit(static_cast<const dregx::ast::node::capture_range*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case dregx::ast::Type::capture_letter_range:
			{
				// Exit nonterminal
				ListenExit(static_cast<const dregx::ast::node::capture_letter_range*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case dregx::ast::Type::capture_number_range:
			{
				// Exit nonterminal
				ListenExit(static_cast<const dregx::ast::node::capture_number_range*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case dregx::ast::Type::capture_number:
			{
				// Exit nonterminal
				ListenExit(static_cast<const dregx::ast::node::capture_number*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case dregx::ast::Type::capture_letter:
			{
				// Exit nonterminal
				ListenExit(static_cast<const dregx::ast::node::capture_letter*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case dregx::ast::Type::capture_special_character:
			{
				// Exit nonterminal
				ListenExit(static_cast<const dregx::ast::node::capture_special_character*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case dregx::ast::Type::extension_modifier:
			{
				// Exit nonterminal
				ListenExit(static_cast<const dregx::ast::node::extension_modifier*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case dregx::ast::Type::min_repition:
			{
				// Exit nonterminal
				ListenExit(static_cast<const dregx::ast::node::min_repition*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case dregx::ast::Type::deamerreserved_plus__NUMBER__:
			{
				// Exit nonterminal
				ListenExit(static_cast<const dregx::ast::node::deamerreserved_plus__NUMBER__*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case dregx::ast::Type::max_repition:
			{
				// Exit nonterminal
				ListenExit(static_cast<const dregx::ast::node::max_repition*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case dregx::ast::Type::standalone:
			{
				// Exit nonterminal
				ListenExit(static_cast<const dregx::ast::node::standalone*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case dregx::ast::Type::opt_pad:
			{
				// Exit nonterminal
				ListenExit(static_cast<const dregx::ast::node::opt_pad*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case dregx::ast::Type::optional_padding:
			{
				// Exit nonterminal
				ListenExit(static_cast<const dregx::ast::node::optional_padding*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case dregx::ast::Type::deamerreserved_star__padding__:
			{
				// Exit nonterminal
				ListenExit(static_cast<const dregx::ast::node::deamerreserved_star__padding__*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case dregx::ast::Type::padding:
			{
				// Exit nonterminal
				ListenExit(static_cast<const dregx::ast::node::padding*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case dregx::ast::Type::special_char_any:
			{
				// Exit nonterminal
				ListenExit(static_cast<const dregx::ast::node::special_char_any*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case dregx::ast::Type::any_number:
			{
				// Exit nonterminal
				ListenExit(static_cast<const dregx::ast::node::any_number*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case dregx::ast::Type::any_letter:
			{
				// Exit nonterminal
				ListenExit(static_cast<const dregx::ast::node::any_letter*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case dregx::ast::Type::any_letter_exclude_underscore:
			{
				// Exit nonterminal
				ListenExit(static_cast<const dregx::ast::node::any_letter_exclude_underscore*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case dregx::ast::Type::capture_structure:
			{
				// Exit nonterminal
				ListenExit(static_cast<const dregx::ast::node::capture_structure*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			case dregx::ast::Type::any:
			{
				// Exit nonterminal
				ListenExit(static_cast<const dregx::ast::node::any*>(node));
				ExitNonTerminal(node);
				ExitAnything(node);
				break;
			}

			}
		}

		
		virtual void ListenEntry(const dregx::ast::node::LEFT_CURLY_BRACKET* node) 
		{
		}

		virtual void ListenEntry(const dregx::ast::node::RIGHT_CURLY_BRACKET* node) 
		{
		}

		virtual void ListenEntry(const dregx::ast::node::LEFT_SQUARE_BRACKET_NOT* node) 
		{
		}

		virtual void ListenEntry(const dregx::ast::node::LEFT_SQUARE_BRACKET* node) 
		{
		}

		virtual void ListenEntry(const dregx::ast::node::RIGHT_SQUARE_BRACKET* node) 
		{
		}

		virtual void ListenEntry(const dregx::ast::node::LEFT_BRACKET* node) 
		{
		}

		virtual void ListenEntry(const dregx::ast::node::RIGHT_BRACKET* node) 
		{
		}

		virtual void ListenEntry(const dregx::ast::node::COMMA* node) 
		{
		}

		virtual void ListenEntry(const dregx::ast::node::SLASH* node) 
		{
		}

		virtual void ListenEntry(const dregx::ast::node::OR* node) 
		{
		}

		virtual void ListenEntry(const dregx::ast::node::MIN* node) 
		{
		}

		virtual void ListenEntry(const dregx::ast::node::UNDERSCORE* node) 
		{
		}

		virtual void ListenEntry(const dregx::ast::node::NOT* node) 
		{
		}

		virtual void ListenEntry(const dregx::ast::node::PLUS* node) 
		{
		}

		virtual void ListenEntry(const dregx::ast::node::STAR* node) 
		{
		}

		virtual void ListenEntry(const dregx::ast::node::OPTIONAL* node) 
		{
		}

		virtual void ListenEntry(const dregx::ast::node::NUMBER* node) 
		{
		}

		virtual void ListenEntry(const dregx::ast::node::T_* node) 
		{
		}

		virtual void ListenEntry(const dregx::ast::node::N_* node) 
		{
		}

		virtual void ListenEntry(const dregx::ast::node::R_* node) 
		{
		}

		virtual void ListenEntry(const dregx::ast::node::B_* node) 
		{
		}

		virtual void ListenEntry(const dregx::ast::node::V_* node) 
		{
		}

		virtual void ListenEntry(const dregx::ast::node::A_* node) 
		{
		}

		virtual void ListenEntry(const dregx::ast::node::LETTER* node) 
		{
		}

		virtual void ListenEntry(const dregx::ast::node::SPACE* node) 
		{
		}

		virtual void ListenEntry(const dregx::ast::node::TAB* node) 
		{
		}

		virtual void ListenEntry(const dregx::ast::node::OTHER* node) 
		{
		}

		virtual void ListenEntry(const dregx::ast::node::DELETE_ESCAPE_CHARS* node) 
		{
		}

		
		virtual void ListenExit(const dregx::ast::node::LEFT_CURLY_BRACKET* node) 
		{
		}

		virtual void ListenExit(const dregx::ast::node::RIGHT_CURLY_BRACKET* node) 
		{
		}

		virtual void ListenExit(const dregx::ast::node::LEFT_SQUARE_BRACKET_NOT* node) 
		{
		}

		virtual void ListenExit(const dregx::ast::node::LEFT_SQUARE_BRACKET* node) 
		{
		}

		virtual void ListenExit(const dregx::ast::node::RIGHT_SQUARE_BRACKET* node) 
		{
		}

		virtual void ListenExit(const dregx::ast::node::LEFT_BRACKET* node) 
		{
		}

		virtual void ListenExit(const dregx::ast::node::RIGHT_BRACKET* node) 
		{
		}

		virtual void ListenExit(const dregx::ast::node::COMMA* node) 
		{
		}

		virtual void ListenExit(const dregx::ast::node::SLASH* node) 
		{
		}

		virtual void ListenExit(const dregx::ast::node::OR* node) 
		{
		}

		virtual void ListenExit(const dregx::ast::node::MIN* node) 
		{
		}

		virtual void ListenExit(const dregx::ast::node::UNDERSCORE* node) 
		{
		}

		virtual void ListenExit(const dregx::ast::node::NOT* node) 
		{
		}

		virtual void ListenExit(const dregx::ast::node::PLUS* node) 
		{
		}

		virtual void ListenExit(const dregx::ast::node::STAR* node) 
		{
		}

		virtual void ListenExit(const dregx::ast::node::OPTIONAL* node) 
		{
		}

		virtual void ListenExit(const dregx::ast::node::NUMBER* node) 
		{
		}

		virtual void ListenExit(const dregx::ast::node::T_* node) 
		{
		}

		virtual void ListenExit(const dregx::ast::node::N_* node) 
		{
		}

		virtual void ListenExit(const dregx::ast::node::R_* node) 
		{
		}

		virtual void ListenExit(const dregx::ast::node::B_* node) 
		{
		}

		virtual void ListenExit(const dregx::ast::node::V_* node) 
		{
		}

		virtual void ListenExit(const dregx::ast::node::A_* node) 
		{
		}

		virtual void ListenExit(const dregx::ast::node::LETTER* node) 
		{
		}

		virtual void ListenExit(const dregx::ast::node::SPACE* node) 
		{
		}

		virtual void ListenExit(const dregx::ast::node::TAB* node) 
		{
		}

		virtual void ListenExit(const dregx::ast::node::OTHER* node) 
		{
		}

		virtual void ListenExit(const dregx::ast::node::DELETE_ESCAPE_CHARS* node) 
		{
		}


		
		virtual void ListenEntry(const dregx::ast::node::program* node) 
		{
		}

		virtual void ListenEntry(const dregx::ast::node::deamerreserved_star__stmt__* node) 
		{
		}

		virtual void ListenEntry(const dregx::ast::node::stmt* node) 
		{
		}

		virtual void ListenEntry(const dregx::ast::node::word* node) 
		{
		}

		virtual void ListenEntry(const dregx::ast::node::group* node) 
		{
		}

		virtual void ListenEntry(const dregx::ast::node::deamerreserved_plus__word__* node) 
		{
		}

		virtual void ListenEntry(const dregx::ast::node::or_concat* node) 
		{
		}

		virtual void ListenEntry(const dregx::ast::node::deamerreserved_arrow__or_element__* node) 
		{
		}

		virtual void ListenEntry(const dregx::ast::node::deamerreserved_star__opt_pad__OR__or_element__* node) 
		{
		}

		virtual void ListenEntry(const dregx::ast::node::or_element* node) 
		{
		}

		virtual void ListenEntry(const dregx::ast::node::square* node) 
		{
		}

		virtual void ListenEntry(const dregx::ast::node::capture* node) 
		{
		}

		virtual void ListenEntry(const dregx::ast::node::deamerreserved_star__capture_logic__* node) 
		{
		}

		virtual void ListenEntry(const dregx::ast::node::capture_logic* node) 
		{
		}

		virtual void ListenEntry(const dregx::ast::node::capture_symbols* node) 
		{
		}

		virtual void ListenEntry(const dregx::ast::node::capture_whitespace* node) 
		{
		}

		virtual void ListenEntry(const dregx::ast::node::capture_range* node) 
		{
		}

		virtual void ListenEntry(const dregx::ast::node::capture_letter_range* node) 
		{
		}

		virtual void ListenEntry(const dregx::ast::node::capture_number_range* node) 
		{
		}

		virtual void ListenEntry(const dregx::ast::node::capture_number* node) 
		{
		}

		virtual void ListenEntry(const dregx::ast::node::capture_letter* node) 
		{
		}

		virtual void ListenEntry(const dregx::ast::node::capture_special_character* node) 
		{
		}

		virtual void ListenEntry(const dregx::ast::node::extension_modifier* node) 
		{
		}

		virtual void ListenEntry(const dregx::ast::node::min_repition* node) 
		{
		}

		virtual void ListenEntry(const dregx::ast::node::deamerreserved_plus__NUMBER__* node) 
		{
		}

		virtual void ListenEntry(const dregx::ast::node::max_repition* node) 
		{
		}

		virtual void ListenEntry(const dregx::ast::node::standalone* node) 
		{
		}

		virtual void ListenEntry(const dregx::ast::node::opt_pad* node) 
		{
		}

		virtual void ListenEntry(const dregx::ast::node::optional_padding* node) 
		{
		}

		virtual void ListenEntry(const dregx::ast::node::deamerreserved_star__padding__* node) 
		{
		}

		virtual void ListenEntry(const dregx::ast::node::padding* node) 
		{
		}

		virtual void ListenEntry(const dregx::ast::node::special_char_any* node) 
		{
		}

		virtual void ListenEntry(const dregx::ast::node::any_number* node) 
		{
		}

		virtual void ListenEntry(const dregx::ast::node::any_letter* node) 
		{
		}

		virtual void ListenEntry(const dregx::ast::node::any_letter_exclude_underscore* node) 
		{
		}

		virtual void ListenEntry(const dregx::ast::node::capture_structure* node) 
		{
		}

		virtual void ListenEntry(const dregx::ast::node::any* node) 
		{
		}

		
		virtual void ListenExit(const dregx::ast::node::program* node) 
		{
		}

		virtual void ListenExit(const dregx::ast::node::deamerreserved_star__stmt__* node) 
		{
		}

		virtual void ListenExit(const dregx::ast::node::stmt* node) 
		{
		}

		virtual void ListenExit(const dregx::ast::node::word* node) 
		{
		}

		virtual void ListenExit(const dregx::ast::node::group* node) 
		{
		}

		virtual void ListenExit(const dregx::ast::node::deamerreserved_plus__word__* node) 
		{
		}

		virtual void ListenExit(const dregx::ast::node::or_concat* node) 
		{
		}

		virtual void ListenExit(const dregx::ast::node::deamerreserved_arrow__or_element__* node) 
		{
		}

		virtual void ListenExit(const dregx::ast::node::deamerreserved_star__opt_pad__OR__or_element__* node) 
		{
		}

		virtual void ListenExit(const dregx::ast::node::or_element* node) 
		{
		}

		virtual void ListenExit(const dregx::ast::node::square* node) 
		{
		}

		virtual void ListenExit(const dregx::ast::node::capture* node) 
		{
		}

		virtual void ListenExit(const dregx::ast::node::deamerreserved_star__capture_logic__* node) 
		{
		}

		virtual void ListenExit(const dregx::ast::node::capture_logic* node) 
		{
		}

		virtual void ListenExit(const dregx::ast::node::capture_symbols* node) 
		{
		}

		virtual void ListenExit(const dregx::ast::node::capture_whitespace* node) 
		{
		}

		virtual void ListenExit(const dregx::ast::node::capture_range* node) 
		{
		}

		virtual void ListenExit(const dregx::ast::node::capture_letter_range* node) 
		{
		}

		virtual void ListenExit(const dregx::ast::node::capture_number_range* node) 
		{
		}

		virtual void ListenExit(const dregx::ast::node::capture_number* node) 
		{
		}

		virtual void ListenExit(const dregx::ast::node::capture_letter* node) 
		{
		}

		virtual void ListenExit(const dregx::ast::node::capture_special_character* node) 
		{
		}

		virtual void ListenExit(const dregx::ast::node::extension_modifier* node) 
		{
		}

		virtual void ListenExit(const dregx::ast::node::min_repition* node) 
		{
		}

		virtual void ListenExit(const dregx::ast::node::deamerreserved_plus__NUMBER__* node) 
		{
		}

		virtual void ListenExit(const dregx::ast::node::max_repition* node) 
		{
		}

		virtual void ListenExit(const dregx::ast::node::standalone* node) 
		{
		}

		virtual void ListenExit(const dregx::ast::node::opt_pad* node) 
		{
		}

		virtual void ListenExit(const dregx::ast::node::optional_padding* node) 
		{
		}

		virtual void ListenExit(const dregx::ast::node::deamerreserved_star__padding__* node) 
		{
		}

		virtual void ListenExit(const dregx::ast::node::padding* node) 
		{
		}

		virtual void ListenExit(const dregx::ast::node::special_char_any* node) 
		{
		}

		virtual void ListenExit(const dregx::ast::node::any_number* node) 
		{
		}

		virtual void ListenExit(const dregx::ast::node::any_letter* node) 
		{
		}

		virtual void ListenExit(const dregx::ast::node::any_letter_exclude_underscore* node) 
		{
		}

		virtual void ListenExit(const dregx::ast::node::capture_structure* node) 
		{
		}

		virtual void ListenExit(const dregx::ast::node::any* node) 
		{
		}


		
		virtual void EnterTerminal(const ::deamer::external::cpp::ast::Node* node) 
		{
		}
		
		virtual void ExitTerminal(const ::deamer::external::cpp::ast::Node* node) 
		{
		}
		
		virtual void EnterNonTerminal(const ::deamer::external::cpp::ast::Node* node) 
		{
		}
		
		virtual void ExitNonTerminal(const ::deamer::external::cpp::ast::Node* node) 
		{
		}
		
		virtual void EnterAnything(const ::deamer::external::cpp::ast::Node* node) 
		{
		}

		virtual void ExitAnything(const ::deamer::external::cpp::ast::Node* node) 
		{
		}
	};

}}}

#endif // DREGX_AST_LISTENER_ENTEREXITLISTENER_H