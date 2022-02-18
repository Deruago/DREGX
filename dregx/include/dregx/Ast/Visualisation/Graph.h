#ifndef DREGX_AST_VISUALISATION_GRAPH_H
#define DREGX_AST_VISUALISATION_GRAPH_H

#include "dregx/Ast/Listener/EnterExitListener.h"

namespace dregx { namespace ast { namespace listener { namespace deamer { namespace visualisation {

	class Graph : public EnterExitListener
	{
	private:
		std::string output;

		void Init()
		{
			output += "digraph dregx_AST {\n";
		}

		void End()
		{
			output += "}\n";
		}

		void AddConnection(const  ::deamer::external::cpp::ast::Node* source, const  ::deamer::external::cpp::ast::Node* target)
		{
			output += "\t" + std::to_string(::std::size_t(source)) + " -> " + std::to_string(::std::size_t(target)) + ";\n";
		}

		
		void ListenEntry(const ::dregx::ast::node::program* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"program\"];\n";
		}

		void ListenEntry(const ::dregx::ast::node::deamerreserved_star__stmt__* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"deamerreserved_star__stmt__\"];\n";
		}

		void ListenEntry(const ::dregx::ast::node::stmt* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"stmt\"];\n";
		}

		void ListenEntry(const ::dregx::ast::node::word* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"word\"];\n";
		}

		void ListenEntry(const ::dregx::ast::node::group* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"group\"];\n";
		}

		void ListenEntry(const ::dregx::ast::node::deamerreserved_plus__word__* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"deamerreserved_plus__word__\"];\n";
		}

		void ListenEntry(const ::dregx::ast::node::or_concat* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"or_concat\"];\n";
		}

		void ListenEntry(const ::dregx::ast::node::square* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"square\"];\n";
		}

		void ListenEntry(const ::dregx::ast::node::capture* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"capture\"];\n";
		}

		void ListenEntry(const ::dregx::ast::node::deamerreserved_plus__capture_logic__* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"deamerreserved_plus__capture_logic__\"];\n";
		}

		void ListenEntry(const ::dregx::ast::node::capture_logic* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"capture_logic\"];\n";
		}

		void ListenEntry(const ::dregx::ast::node::capture_symbols* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"capture_symbols\"];\n";
		}

		void ListenEntry(const ::dregx::ast::node::capture_whitespace* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"capture_whitespace\"];\n";
		}

		void ListenEntry(const ::dregx::ast::node::capture_range* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"capture_range\"];\n";
		}

		void ListenEntry(const ::dregx::ast::node::capture_letter_range* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"capture_letter_range\"];\n";
		}

		void ListenEntry(const ::dregx::ast::node::capture_number_range* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"capture_number_range\"];\n";
		}

		void ListenEntry(const ::dregx::ast::node::capture_letter* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"capture_letter\"];\n";
		}

		void ListenEntry(const ::dregx::ast::node::capture_special_character* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"capture_special_character\"];\n";
		}

		void ListenEntry(const ::dregx::ast::node::extension_modifier* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"extension_modifier\"];\n";
		}

		void ListenEntry(const ::dregx::ast::node::min_repition* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"min_repition\"];\n";
		}

		void ListenEntry(const ::dregx::ast::node::deamerreserved_plus__NUMBER__* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"deamerreserved_plus__NUMBER__\"];\n";
		}

		void ListenEntry(const ::dregx::ast::node::max_repition* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"max_repition\"];\n";
		}

		void ListenEntry(const ::dregx::ast::node::standalone* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"standalone\"];\n";
		}

		void ListenEntry(const ::dregx::ast::node::deamerreserved_plus__any_letter__* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"deamerreserved_plus__any_letter__\"];\n";
		}

		void ListenEntry(const ::dregx::ast::node::opt_pad* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"opt_pad\"];\n";
		}

		void ListenEntry(const ::dregx::ast::node::optional_padding* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"optional_padding\"];\n";
		}

		void ListenEntry(const ::dregx::ast::node::deamerreserved_star__padding__* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"deamerreserved_star__padding__\"];\n";
		}

		void ListenEntry(const ::dregx::ast::node::padding* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"padding\"];\n";
		}

		void ListenEntry(const ::dregx::ast::node::special_char_any* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"special_char_any\"];\n";
		}

		void ListenEntry(const ::dregx::ast::node::any_letter* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"any_letter\"];\n";
		}

		void ListenEntry(const ::dregx::ast::node::any_letter_exclude_underscore* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"any_letter_exclude_underscore\"];\n";
		}

		void ListenEntry(const ::dregx::ast::node::any* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"any\"];\n";
		}

		void ListenEntry(const ::dregx::ast::node::LEFT_CURLY_BRACKET* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"LEFT_CURLY_BRACKET\"];\n";
		}

		void ListenEntry(const ::dregx::ast::node::RIGHT_CURLY_BRACKET* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"RIGHT_CURLY_BRACKET\"];\n";
		}

		void ListenEntry(const ::dregx::ast::node::LEFT_SQUARE_BRACKET_NOT* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"LEFT_SQUARE_BRACKET_NOT\"];\n";
		}

		void ListenEntry(const ::dregx::ast::node::LEFT_SQUARE_BRACKET* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"LEFT_SQUARE_BRACKET\"];\n";
		}

		void ListenEntry(const ::dregx::ast::node::RIGHT_SQUARE_BRACKET* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"RIGHT_SQUARE_BRACKET\"];\n";
		}

		void ListenEntry(const ::dregx::ast::node::LEFT_BRACKET* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"LEFT_BRACKET\"];\n";
		}

		void ListenEntry(const ::dregx::ast::node::RIGHT_BRACKET* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"RIGHT_BRACKET\"];\n";
		}

		void ListenEntry(const ::dregx::ast::node::COMMA* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"COMMA\"];\n";
		}

		void ListenEntry(const ::dregx::ast::node::SLASH* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"SLASH\"];\n";
		}

		void ListenEntry(const ::dregx::ast::node::OR* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"OR\"];\n";
		}

		void ListenEntry(const ::dregx::ast::node::MIN* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"MIN\"];\n";
		}

		void ListenEntry(const ::dregx::ast::node::UNDERSCORE* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"UNDERSCORE\"];\n";
		}

		void ListenEntry(const ::dregx::ast::node::NOT* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"NOT\"];\n";
		}

		void ListenEntry(const ::dregx::ast::node::PLUS* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"PLUS\"];\n";
		}

		void ListenEntry(const ::dregx::ast::node::STAR* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"STAR\"];\n";
		}

		void ListenEntry(const ::dregx::ast::node::NUMBER* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"NUMBER\"];\n";
		}

		void ListenEntry(const ::dregx::ast::node::T_* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"T_\"];\n";
		}

		void ListenEntry(const ::dregx::ast::node::N_* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"N_\"];\n";
		}

		void ListenEntry(const ::dregx::ast::node::R_* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"R_\"];\n";
		}

		void ListenEntry(const ::dregx::ast::node::B_* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"B_\"];\n";
		}

		void ListenEntry(const ::dregx::ast::node::V_* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"V_\"];\n";
		}

		void ListenEntry(const ::dregx::ast::node::A_* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"A_\"];\n";
		}

		void ListenEntry(const ::dregx::ast::node::LETTER* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"LETTER\"];\n";
		}

		void ListenEntry(const ::dregx::ast::node::SPACE* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"SPACE\"];\n";
		}

		void ListenEntry(const ::dregx::ast::node::TAB* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"TAB\"];\n";
		}

		void ListenEntry(const ::dregx::ast::node::OTHER* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"OTHER\"];\n";
		}

		void ListenEntry(const ::dregx::ast::node::DELETE_ESCAPE_CHARS* node) override
		{
			for (const auto* child : node->GetNodes())
			{
				AddConnection(node, child);
			}

			output += "\t" + std::to_string(::std::size_t(node)) + " [label=\"DELETE_ESCAPE_CHARS\"];\n";
		}

		
		void ListenExit(const ::dregx::ast::node::program* node) override
		{
		}

		void ListenExit(const ::dregx::ast::node::deamerreserved_star__stmt__* node) override
		{
		}

		void ListenExit(const ::dregx::ast::node::stmt* node) override
		{
		}

		void ListenExit(const ::dregx::ast::node::word* node) override
		{
		}

		void ListenExit(const ::dregx::ast::node::group* node) override
		{
		}

		void ListenExit(const ::dregx::ast::node::deamerreserved_plus__word__* node) override
		{
		}

		void ListenExit(const ::dregx::ast::node::or_concat* node) override
		{
		}

		void ListenExit(const ::dregx::ast::node::square* node) override
		{
		}

		void ListenExit(const ::dregx::ast::node::capture* node) override
		{
		}

		void ListenExit(const ::dregx::ast::node::deamerreserved_plus__capture_logic__* node) override
		{
		}

		void ListenExit(const ::dregx::ast::node::capture_logic* node) override
		{
		}

		void ListenExit(const ::dregx::ast::node::capture_symbols* node) override
		{
		}

		void ListenExit(const ::dregx::ast::node::capture_whitespace* node) override
		{
		}

		void ListenExit(const ::dregx::ast::node::capture_range* node) override
		{
		}

		void ListenExit(const ::dregx::ast::node::capture_letter_range* node) override
		{
		}

		void ListenExit(const ::dregx::ast::node::capture_number_range* node) override
		{
		}

		void ListenExit(const ::dregx::ast::node::capture_letter* node) override
		{
		}

		void ListenExit(const ::dregx::ast::node::capture_special_character* node) override
		{
		}

		void ListenExit(const ::dregx::ast::node::extension_modifier* node) override
		{
		}

		void ListenExit(const ::dregx::ast::node::min_repition* node) override
		{
		}

		void ListenExit(const ::dregx::ast::node::deamerreserved_plus__NUMBER__* node) override
		{
		}

		void ListenExit(const ::dregx::ast::node::max_repition* node) override
		{
		}

		void ListenExit(const ::dregx::ast::node::standalone* node) override
		{
		}

		void ListenExit(const ::dregx::ast::node::deamerreserved_plus__any_letter__* node) override
		{
		}

		void ListenExit(const ::dregx::ast::node::opt_pad* node) override
		{
		}

		void ListenExit(const ::dregx::ast::node::optional_padding* node) override
		{
		}

		void ListenExit(const ::dregx::ast::node::deamerreserved_star__padding__* node) override
		{
		}

		void ListenExit(const ::dregx::ast::node::padding* node) override
		{
		}

		void ListenExit(const ::dregx::ast::node::special_char_any* node) override
		{
		}

		void ListenExit(const ::dregx::ast::node::any_letter* node) override
		{
		}

		void ListenExit(const ::dregx::ast::node::any_letter_exclude_underscore* node) override
		{
		}

		void ListenExit(const ::dregx::ast::node::any* node) override
		{
		}


	public:
		Graph()
		{
			Init();
		}


		std::string GetGraph()
		{
			End();
			return output;
		}
	};

}}}}}

#endif // DREGX_AST_VISUALISATION_GRAPH_H