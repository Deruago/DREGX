%define parse.error verbose

%glr-parser

%{
#include <iostream>
#include <vector>
#include <cstring>
#include <stdio.h>
#include <Deamer/External/Cpp/Lexer/TerminalObject.h>
#include <Deamer/External/Cpp/Ast/Node.h>
#include "dregx/Bison/Parser.h"
#define YY_NO_UNISTD_H
#include "Flex/dregx_lexer.h"
#undef YY_NO_UNISTD_H
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
#include "dregx/Ast/Node/any.h"


#ifndef YY_parse_NERRS
#define YY_parse_NERRS dregxnerrs
#endif //YY_parse_NERRS
#ifndef YY_parse_LLOC
#define YY_parse_LLOC dregxlloc
#endif //YY_parse_LLOC
#define YYERROR_VERBOSE

void dregxerror(const char* s);
int dregxlex();
static ::deamer::external::cpp::ast::Tree* outputTree = nullptr;
%}

%token<Terminal> LEFT_CURLY_BRACKET
%token<Terminal> RIGHT_CURLY_BRACKET
%token<Terminal> LEFT_SQUARE_BRACKET_NOT
%token<Terminal> LEFT_SQUARE_BRACKET
%token<Terminal> RIGHT_SQUARE_BRACKET
%token<Terminal> LEFT_BRACKET
%token<Terminal> RIGHT_BRACKET
%token<Terminal> COMMA
%token<Terminal> SLASH
%token<Terminal> OR
%token<Terminal> MIN
%token<Terminal> UNDERSCORE
%token<Terminal> NOT
%token<Terminal> PLUS
%token<Terminal> STAR
%token<Terminal> OPTIONAL
%token<Terminal> NUMBER
%token<Terminal> T_
%token<Terminal> N_
%token<Terminal> R_
%token<Terminal> B_
%token<Terminal> V_
%token<Terminal> A_
%token<Terminal> LETTER
%token<Terminal> SPACE
%token<Terminal> TAB
%token<Terminal> OTHER
%token<Terminal> DELETE_ESCAPE_CHARS


%nterm<dregx_program> program
%nterm<dregx_deamerreserved_star__stmt__> deamerreserved_star__stmt__
%nterm<dregx_stmt> stmt
%nterm<dregx_word> word
%nterm<dregx_group> group
%nterm<dregx_deamerreserved_plus__word__> deamerreserved_plus__word__
%nterm<dregx_or_concat> or_concat
%nterm<dregx_deamerreserved_arrow__word__> deamerreserved_arrow__word__
%nterm<dregx_deamerreserved_star__opt_pad__OR__word__> deamerreserved_star__opt_pad__OR__word__
%nterm<dregx_square> square
%nterm<dregx_capture> capture
%nterm<dregx_deamerreserved_star__capture_logic__> deamerreserved_star__capture_logic__
%nterm<dregx_capture_logic> capture_logic
%nterm<dregx_capture_symbols> capture_symbols
%nterm<dregx_capture_whitespace> capture_whitespace
%nterm<dregx_capture_range> capture_range
%nterm<dregx_capture_letter_range> capture_letter_range
%nterm<dregx_capture_number_range> capture_number_range
%nterm<dregx_capture_number> capture_number
%nterm<dregx_capture_letter> capture_letter
%nterm<dregx_capture_special_character> capture_special_character
%nterm<dregx_extension_modifier> extension_modifier
%nterm<dregx_min_repition> min_repition
%nterm<dregx_deamerreserved_plus__NUMBER__> deamerreserved_plus__NUMBER__
%nterm<dregx_max_repition> max_repition
%nterm<dregx_standalone> standalone
%nterm<dregx_opt_pad> opt_pad
%nterm<dregx_optional_padding> optional_padding
%nterm<dregx_deamerreserved_star__padding__> deamerreserved_star__padding__
%nterm<dregx_padding> padding
%nterm<dregx_special_char_any> special_char_any
%nterm<dregx_any_number> any_number
%nterm<dregx_any_letter> any_letter
%nterm<dregx_any_letter_exclude_underscore> any_letter_exclude_underscore
%nterm<dregx_any> any


%union{
	::deamer::external::cpp::lexer::TerminalObject* Terminal;
	::dregx::ast::node::LEFT_CURLY_BRACKET* dregx_LEFT_CURLY_BRACKET;
	::dregx::ast::node::RIGHT_CURLY_BRACKET* dregx_RIGHT_CURLY_BRACKET;
	::dregx::ast::node::LEFT_SQUARE_BRACKET_NOT* dregx_LEFT_SQUARE_BRACKET_NOT;
	::dregx::ast::node::LEFT_SQUARE_BRACKET* dregx_LEFT_SQUARE_BRACKET;
	::dregx::ast::node::RIGHT_SQUARE_BRACKET* dregx_RIGHT_SQUARE_BRACKET;
	::dregx::ast::node::LEFT_BRACKET* dregx_LEFT_BRACKET;
	::dregx::ast::node::RIGHT_BRACKET* dregx_RIGHT_BRACKET;
	::dregx::ast::node::COMMA* dregx_COMMA;
	::dregx::ast::node::SLASH* dregx_SLASH;
	::dregx::ast::node::OR* dregx_OR;
	::dregx::ast::node::MIN* dregx_MIN;
	::dregx::ast::node::UNDERSCORE* dregx_UNDERSCORE;
	::dregx::ast::node::NOT* dregx_NOT;
	::dregx::ast::node::PLUS* dregx_PLUS;
	::dregx::ast::node::STAR* dregx_STAR;
	::dregx::ast::node::OPTIONAL* dregx_OPTIONAL;
	::dregx::ast::node::NUMBER* dregx_NUMBER;
	::dregx::ast::node::T_* dregx_T_;
	::dregx::ast::node::N_* dregx_N_;
	::dregx::ast::node::R_* dregx_R_;
	::dregx::ast::node::B_* dregx_B_;
	::dregx::ast::node::V_* dregx_V_;
	::dregx::ast::node::A_* dregx_A_;
	::dregx::ast::node::LETTER* dregx_LETTER;
	::dregx::ast::node::SPACE* dregx_SPACE;
	::dregx::ast::node::TAB* dregx_TAB;
	::dregx::ast::node::OTHER* dregx_OTHER;
	::dregx::ast::node::DELETE_ESCAPE_CHARS* dregx_DELETE_ESCAPE_CHARS;
	::dregx::ast::node::program* dregx_program;
	::dregx::ast::node::deamerreserved_star__stmt__* dregx_deamerreserved_star__stmt__;
	::dregx::ast::node::stmt* dregx_stmt;
	::dregx::ast::node::word* dregx_word;
	::dregx::ast::node::group* dregx_group;
	::dregx::ast::node::deamerreserved_plus__word__* dregx_deamerreserved_plus__word__;
	::dregx::ast::node::or_concat* dregx_or_concat;
	::dregx::ast::node::deamerreserved_arrow__word__* dregx_deamerreserved_arrow__word__;
	::dregx::ast::node::deamerreserved_star__opt_pad__OR__word__* dregx_deamerreserved_star__opt_pad__OR__word__;
	::dregx::ast::node::square* dregx_square;
	::dregx::ast::node::capture* dregx_capture;
	::dregx::ast::node::deamerreserved_star__capture_logic__* dregx_deamerreserved_star__capture_logic__;
	::dregx::ast::node::capture_logic* dregx_capture_logic;
	::dregx::ast::node::capture_symbols* dregx_capture_symbols;
	::dregx::ast::node::capture_whitespace* dregx_capture_whitespace;
	::dregx::ast::node::capture_range* dregx_capture_range;
	::dregx::ast::node::capture_letter_range* dregx_capture_letter_range;
	::dregx::ast::node::capture_number_range* dregx_capture_number_range;
	::dregx::ast::node::capture_number* dregx_capture_number;
	::dregx::ast::node::capture_letter* dregx_capture_letter;
	::dregx::ast::node::capture_special_character* dregx_capture_special_character;
	::dregx::ast::node::extension_modifier* dregx_extension_modifier;
	::dregx::ast::node::min_repition* dregx_min_repition;
	::dregx::ast::node::deamerreserved_plus__NUMBER__* dregx_deamerreserved_plus__NUMBER__;
	::dregx::ast::node::max_repition* dregx_max_repition;
	::dregx::ast::node::standalone* dregx_standalone;
	::dregx::ast::node::opt_pad* dregx_opt_pad;
	::dregx::ast::node::optional_padding* dregx_optional_padding;
	::dregx::ast::node::deamerreserved_star__padding__* dregx_deamerreserved_star__padding__;
	::dregx::ast::node::padding* dregx_padding;
	::dregx::ast::node::special_char_any* dregx_special_char_any;
	::dregx::ast::node::any_number* dregx_any_number;
	::dregx::ast::node::any_letter* dregx_any_letter;
	::dregx::ast::node::any_letter_exclude_underscore* dregx_any_letter_exclude_underscore;
	::dregx::ast::node::any* dregx_any;

}

%%


program:
	deamerreserved_star__stmt__ opt_pad  {
		auto* const newNode = new dregx::ast::node::program({::dregx::ast::Type::program, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1, $2 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
		outputTree = new ::deamer::external::cpp::ast::Tree(newNode);
	}
;


deamerreserved_star__stmt__:
	stmt deamerreserved_star__stmt__  {
		auto* const newNode = new dregx::ast::node::deamerreserved_star__stmt__({::dregx::ast::Type::deamerreserved_star__stmt__, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, { $1, $2 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	|  {
		auto* const newNode = new dregx::ast::node::deamerreserved_star__stmt__({::dregx::ast::Type::deamerreserved_star__stmt__, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, {  });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


stmt:
	word  {
		auto* const newNode = new dregx::ast::node::stmt({::dregx::ast::Type::stmt, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


word:
	group  {
		auto* const newNode = new dregx::ast::node::word({::dregx::ast::Type::word, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	| square  {
		auto* const newNode = new dregx::ast::node::word({::dregx::ast::Type::word, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	| standalone  {
		auto* const newNode = new dregx::ast::node::word({::dregx::ast::Type::word, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 2, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


group:
	opt_pad LEFT_CURLY_BRACKET or_concat opt_pad RIGHT_CURLY_BRACKET OPTIONAL  {
		auto* const newNode = new dregx::ast::node::group({::dregx::ast::Type::group, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1, new dregx::ast::node::LEFT_CURLY_BRACKET({::dregx::ast::Type::LEFT_CURLY_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, $2 }), $3, $4, new dregx::ast::node::RIGHT_CURLY_BRACKET({::dregx::ast::Type::RIGHT_CURLY_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, $5 }), new dregx::ast::node::OPTIONAL({::dregx::ast::Type::OPTIONAL, ::deamer::external::cpp::ast::NodeValue::terminal, $6 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	| opt_pad LEFT_CURLY_BRACKET or_concat opt_pad RIGHT_CURLY_BRACKET STAR  {
		auto* const newNode = new dregx::ast::node::group({::dregx::ast::Type::group, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1, new dregx::ast::node::LEFT_CURLY_BRACKET({::dregx::ast::Type::LEFT_CURLY_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, $2 }), $3, $4, new dregx::ast::node::RIGHT_CURLY_BRACKET({::dregx::ast::Type::RIGHT_CURLY_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, $5 }), new dregx::ast::node::STAR({::dregx::ast::Type::STAR, ::deamer::external::cpp::ast::NodeValue::terminal, $6 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	| opt_pad LEFT_CURLY_BRACKET or_concat opt_pad RIGHT_CURLY_BRACKET PLUS  {
		auto* const newNode = new dregx::ast::node::group({::dregx::ast::Type::group, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 2, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1, new dregx::ast::node::LEFT_CURLY_BRACKET({::dregx::ast::Type::LEFT_CURLY_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, $2 }), $3, $4, new dregx::ast::node::RIGHT_CURLY_BRACKET({::dregx::ast::Type::RIGHT_CURLY_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, $5 }), new dregx::ast::node::PLUS({::dregx::ast::Type::PLUS, ::deamer::external::cpp::ast::NodeValue::terminal, $6 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	| opt_pad LEFT_CURLY_BRACKET or_concat opt_pad RIGHT_CURLY_BRACKET extension_modifier  {
		auto* const newNode = new dregx::ast::node::group({::dregx::ast::Type::group, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 3, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1, new dregx::ast::node::LEFT_CURLY_BRACKET({::dregx::ast::Type::LEFT_CURLY_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, $2 }), $3, $4, new dregx::ast::node::RIGHT_CURLY_BRACKET({::dregx::ast::Type::RIGHT_CURLY_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, $5 }), $6 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	| opt_pad LEFT_CURLY_BRACKET or_concat opt_pad RIGHT_CURLY_BRACKET  {
		auto* const newNode = new dregx::ast::node::group({::dregx::ast::Type::group, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 4, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1, new dregx::ast::node::LEFT_CURLY_BRACKET({::dregx::ast::Type::LEFT_CURLY_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, $2 }), $3, $4, new dregx::ast::node::RIGHT_CURLY_BRACKET({::dregx::ast::Type::RIGHT_CURLY_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, $5 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	| opt_pad LEFT_CURLY_BRACKET deamerreserved_plus__word__ opt_pad RIGHT_CURLY_BRACKET OPTIONAL  {
		auto* const newNode = new dregx::ast::node::group({::dregx::ast::Type::group, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 5, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1, new dregx::ast::node::LEFT_CURLY_BRACKET({::dregx::ast::Type::LEFT_CURLY_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, $2 }), $3, $4, new dregx::ast::node::RIGHT_CURLY_BRACKET({::dregx::ast::Type::RIGHT_CURLY_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, $5 }), new dregx::ast::node::OPTIONAL({::dregx::ast::Type::OPTIONAL, ::deamer::external::cpp::ast::NodeValue::terminal, $6 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	| opt_pad LEFT_CURLY_BRACKET deamerreserved_plus__word__ opt_pad RIGHT_CURLY_BRACKET STAR  {
		auto* const newNode = new dregx::ast::node::group({::dregx::ast::Type::group, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 6, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1, new dregx::ast::node::LEFT_CURLY_BRACKET({::dregx::ast::Type::LEFT_CURLY_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, $2 }), $3, $4, new dregx::ast::node::RIGHT_CURLY_BRACKET({::dregx::ast::Type::RIGHT_CURLY_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, $5 }), new dregx::ast::node::STAR({::dregx::ast::Type::STAR, ::deamer::external::cpp::ast::NodeValue::terminal, $6 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	| opt_pad LEFT_CURLY_BRACKET deamerreserved_plus__word__ opt_pad RIGHT_CURLY_BRACKET PLUS  {
		auto* const newNode = new dregx::ast::node::group({::dregx::ast::Type::group, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 7, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1, new dregx::ast::node::LEFT_CURLY_BRACKET({::dregx::ast::Type::LEFT_CURLY_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, $2 }), $3, $4, new dregx::ast::node::RIGHT_CURLY_BRACKET({::dregx::ast::Type::RIGHT_CURLY_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, $5 }), new dregx::ast::node::PLUS({::dregx::ast::Type::PLUS, ::deamer::external::cpp::ast::NodeValue::terminal, $6 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	| opt_pad LEFT_CURLY_BRACKET deamerreserved_plus__word__ opt_pad RIGHT_CURLY_BRACKET extension_modifier  {
		auto* const newNode = new dregx::ast::node::group({::dregx::ast::Type::group, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 8, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1, new dregx::ast::node::LEFT_CURLY_BRACKET({::dregx::ast::Type::LEFT_CURLY_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, $2 }), $3, $4, new dregx::ast::node::RIGHT_CURLY_BRACKET({::dregx::ast::Type::RIGHT_CURLY_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, $5 }), $6 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	| opt_pad LEFT_CURLY_BRACKET deamerreserved_plus__word__ opt_pad RIGHT_CURLY_BRACKET  {
		auto* const newNode = new dregx::ast::node::group({::dregx::ast::Type::group, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 9, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1, new dregx::ast::node::LEFT_CURLY_BRACKET({::dregx::ast::Type::LEFT_CURLY_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, $2 }), $3, $4, new dregx::ast::node::RIGHT_CURLY_BRACKET({::dregx::ast::Type::RIGHT_CURLY_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, $5 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


deamerreserved_plus__word__:
	word  {
		auto* const newNode = new dregx::ast::node::deamerreserved_plus__word__({::dregx::ast::Type::deamerreserved_plus__word__, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, { $1 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	| word deamerreserved_plus__word__  {
		auto* const newNode = new dregx::ast::node::deamerreserved_plus__word__({::dregx::ast::Type::deamerreserved_plus__word__, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, { $1, $2 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


or_concat:
	word opt_pad OR deamerreserved_arrow__word__  {
		auto* const newNode = new dregx::ast::node::or_concat({::dregx::ast::Type::or_concat, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1, $2, new dregx::ast::node::OR({::dregx::ast::Type::OR, ::deamer::external::cpp::ast::NodeValue::terminal, $3 }), $4 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


deamerreserved_arrow__word__:
	word deamerreserved_star__opt_pad__OR__word__  {
		auto* const newNode = new dregx::ast::node::deamerreserved_arrow__word__({::dregx::ast::Type::deamerreserved_arrow__word__, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, { $1, $2 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


deamerreserved_star__opt_pad__OR__word__:
	opt_pad OR word deamerreserved_star__opt_pad__OR__word__  {
		auto* const newNode = new dregx::ast::node::deamerreserved_star__opt_pad__OR__word__({::dregx::ast::Type::deamerreserved_star__opt_pad__OR__word__, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, { $1, new dregx::ast::node::OR({::dregx::ast::Type::OR, ::deamer::external::cpp::ast::NodeValue::terminal, $2 }), $3, $4 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	|  {
		auto* const newNode = new dregx::ast::node::deamerreserved_star__opt_pad__OR__word__({::dregx::ast::Type::deamerreserved_star__opt_pad__OR__word__, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, {  });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


square:
	capture extension_modifier  {
		auto* const newNode = new dregx::ast::node::square({::dregx::ast::Type::square, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1, $2 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	| capture PLUS  {
		auto* const newNode = new dregx::ast::node::square({::dregx::ast::Type::square, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1, new dregx::ast::node::PLUS({::dregx::ast::Type::PLUS, ::deamer::external::cpp::ast::NodeValue::terminal, $2 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	| capture STAR  {
		auto* const newNode = new dregx::ast::node::square({::dregx::ast::Type::square, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 2, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1, new dregx::ast::node::STAR({::dregx::ast::Type::STAR, ::deamer::external::cpp::ast::NodeValue::terminal, $2 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	| capture OPTIONAL  {
		auto* const newNode = new dregx::ast::node::square({::dregx::ast::Type::square, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 3, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1, new dregx::ast::node::OPTIONAL({::dregx::ast::Type::OPTIONAL, ::deamer::external::cpp::ast::NodeValue::terminal, $2 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	| capture  {
		auto* const newNode = new dregx::ast::node::square({::dregx::ast::Type::square, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 4, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


capture:
	opt_pad LEFT_SQUARE_BRACKET_NOT deamerreserved_star__capture_logic__ RIGHT_SQUARE_BRACKET  {
		auto* const newNode = new dregx::ast::node::capture({::dregx::ast::Type::capture, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1, new dregx::ast::node::LEFT_SQUARE_BRACKET_NOT({::dregx::ast::Type::LEFT_SQUARE_BRACKET_NOT, ::deamer::external::cpp::ast::NodeValue::terminal, $2 }), $3, new dregx::ast::node::RIGHT_SQUARE_BRACKET({::dregx::ast::Type::RIGHT_SQUARE_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, $4 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	| opt_pad LEFT_SQUARE_BRACKET deamerreserved_star__capture_logic__ RIGHT_SQUARE_BRACKET  {
		auto* const newNode = new dregx::ast::node::capture({::dregx::ast::Type::capture, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1, new dregx::ast::node::LEFT_SQUARE_BRACKET({::dregx::ast::Type::LEFT_SQUARE_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, $2 }), $3, new dregx::ast::node::RIGHT_SQUARE_BRACKET({::dregx::ast::Type::RIGHT_SQUARE_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, $4 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


deamerreserved_star__capture_logic__:
	capture_logic deamerreserved_star__capture_logic__  {
		auto* const newNode = new dregx::ast::node::deamerreserved_star__capture_logic__({::dregx::ast::Type::deamerreserved_star__capture_logic__, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, { $1, $2 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	|  {
		auto* const newNode = new dregx::ast::node::deamerreserved_star__capture_logic__({::dregx::ast::Type::deamerreserved_star__capture_logic__, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, {  });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


capture_logic:
	capture_range  {
		auto* const newNode = new dregx::ast::node::capture_logic({::dregx::ast::Type::capture_logic, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	| capture_special_character  {
		auto* const newNode = new dregx::ast::node::capture_logic({::dregx::ast::Type::capture_logic, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	| capture_letter  {
		auto* const newNode = new dregx::ast::node::capture_logic({::dregx::ast::Type::capture_logic, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 2, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	| capture_number  {
		auto* const newNode = new dregx::ast::node::capture_logic({::dregx::ast::Type::capture_logic, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 3, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	| capture_whitespace  {
		auto* const newNode = new dregx::ast::node::capture_logic({::dregx::ast::Type::capture_logic, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 4, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	| capture_symbols  {
		auto* const newNode = new dregx::ast::node::capture_logic({::dregx::ast::Type::capture_logic, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 5, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


capture_symbols:
	OTHER  {
		auto* const newNode = new dregx::ast::node::capture_symbols({::dregx::ast::Type::capture_symbols, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::OTHER({::dregx::ast::Type::OTHER, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	| PLUS  {
		auto* const newNode = new dregx::ast::node::capture_symbols({::dregx::ast::Type::capture_symbols, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::PLUS({::dregx::ast::Type::PLUS, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	| STAR  {
		auto* const newNode = new dregx::ast::node::capture_symbols({::dregx::ast::Type::capture_symbols, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 2, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::STAR({::dregx::ast::Type::STAR, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	| COMMA  {
		auto* const newNode = new dregx::ast::node::capture_symbols({::dregx::ast::Type::capture_symbols, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 3, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::COMMA({::dregx::ast::Type::COMMA, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	| OR  {
		auto* const newNode = new dregx::ast::node::capture_symbols({::dregx::ast::Type::capture_symbols, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 4, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::OR({::dregx::ast::Type::OR, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	| OPTIONAL  {
		auto* const newNode = new dregx::ast::node::capture_symbols({::dregx::ast::Type::capture_symbols, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 5, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::OPTIONAL({::dregx::ast::Type::OPTIONAL, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


capture_whitespace:
	SPACE  {
		auto* const newNode = new dregx::ast::node::capture_whitespace({::dregx::ast::Type::capture_whitespace, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::SPACE({::dregx::ast::Type::SPACE, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	| TAB  {
		auto* const newNode = new dregx::ast::node::capture_whitespace({::dregx::ast::Type::capture_whitespace, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::TAB({::dregx::ast::Type::TAB, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


capture_range:
	capture_letter_range  {
		auto* const newNode = new dregx::ast::node::capture_range({::dregx::ast::Type::capture_range, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	| capture_number_range  {
		auto* const newNode = new dregx::ast::node::capture_range({::dregx::ast::Type::capture_range, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


capture_letter_range:
	any_letter_exclude_underscore MIN any_letter_exclude_underscore  {
		auto* const newNode = new dregx::ast::node::capture_letter_range({::dregx::ast::Type::capture_letter_range, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1, new dregx::ast::node::MIN({::dregx::ast::Type::MIN, ::deamer::external::cpp::ast::NodeValue::terminal, $2 }), $3 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


capture_number_range:
	NUMBER MIN NUMBER  {
		auto* const newNode = new dregx::ast::node::capture_number_range({::dregx::ast::Type::capture_number_range, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::NUMBER({::dregx::ast::Type::NUMBER, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }), new dregx::ast::node::MIN({::dregx::ast::Type::MIN, ::deamer::external::cpp::ast::NodeValue::terminal, $2 }), new dregx::ast::node::NUMBER({::dregx::ast::Type::NUMBER, ::deamer::external::cpp::ast::NodeValue::terminal, $3 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


capture_number:
	any_number  {
		auto* const newNode = new dregx::ast::node::capture_number({::dregx::ast::Type::capture_number, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


capture_letter:
	any_letter  {
		auto* const newNode = new dregx::ast::node::capture_letter({::dregx::ast::Type::capture_letter, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


capture_special_character:
	special_char_any  {
		auto* const newNode = new dregx::ast::node::capture_special_character({::dregx::ast::Type::capture_special_character, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


extension_modifier:
	opt_pad LEFT_BRACKET min_repition opt_pad COMMA max_repition opt_pad RIGHT_BRACKET  {
		auto* const newNode = new dregx::ast::node::extension_modifier({::dregx::ast::Type::extension_modifier, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1, new dregx::ast::node::LEFT_BRACKET({::dregx::ast::Type::LEFT_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, $2 }), $3, $4, new dregx::ast::node::COMMA({::dregx::ast::Type::COMMA, ::deamer::external::cpp::ast::NodeValue::terminal, $5 }), $6, $7, new dregx::ast::node::RIGHT_BRACKET({::dregx::ast::Type::RIGHT_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, $8 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


min_repition:
	opt_pad deamerreserved_plus__NUMBER__  {
		auto* const newNode = new dregx::ast::node::min_repition({::dregx::ast::Type::min_repition, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1, $2 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


deamerreserved_plus__NUMBER__:
	NUMBER  {
		auto* const newNode = new dregx::ast::node::deamerreserved_plus__NUMBER__({::dregx::ast::Type::deamerreserved_plus__NUMBER__, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, { new dregx::ast::node::NUMBER({::dregx::ast::Type::NUMBER, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	| NUMBER deamerreserved_plus__NUMBER__  {
		auto* const newNode = new dregx::ast::node::deamerreserved_plus__NUMBER__({::dregx::ast::Type::deamerreserved_plus__NUMBER__, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, { new dregx::ast::node::NUMBER({::dregx::ast::Type::NUMBER, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }), $2 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


max_repition:
	opt_pad deamerreserved_plus__NUMBER__  {
		auto* const newNode = new dregx::ast::node::max_repition({::dregx::ast::Type::max_repition, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1, $2 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


standalone:
	opt_pad any_letter  {
		auto* const newNode = new dregx::ast::node::standalone({::dregx::ast::Type::standalone, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1, $2 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	| opt_pad any_number  {
		auto* const newNode = new dregx::ast::node::standalone({::dregx::ast::Type::standalone, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1, $2 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


opt_pad:
	optional_padding  {
		auto* const newNode = new dregx::ast::node::opt_pad({::dregx::ast::Type::opt_pad, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


optional_padding:
	deamerreserved_star__padding__  {
		auto* const newNode = new dregx::ast::node::optional_padding({::dregx::ast::Type::optional_padding, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


deamerreserved_star__padding__:
	padding deamerreserved_star__padding__  {
		auto* const newNode = new dregx::ast::node::deamerreserved_star__padding__({::dregx::ast::Type::deamerreserved_star__padding__, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, { $1, $2 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	|  {
		auto* const newNode = new dregx::ast::node::deamerreserved_star__padding__({::dregx::ast::Type::deamerreserved_star__padding__, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, {  });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


padding:
	SPACE  {
		auto* const newNode = new dregx::ast::node::padding({::dregx::ast::Type::padding, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::SPACE({::dregx::ast::Type::SPACE, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	| TAB  {
		auto* const newNode = new dregx::ast::node::padding({::dregx::ast::Type::padding, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::TAB({::dregx::ast::Type::TAB, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


special_char_any:
	SLASH any  {
		auto* const newNode = new dregx::ast::node::special_char_any({::dregx::ast::Type::special_char_any, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::SLASH({::dregx::ast::Type::SLASH, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }), $2 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


any_number:
	NUMBER  {
		auto* const newNode = new dregx::ast::node::any_number({::dregx::ast::Type::any_number, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::NUMBER({::dregx::ast::Type::NUMBER, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


any_letter:
	any_letter_exclude_underscore  {
		auto* const newNode = new dregx::ast::node::any_letter({::dregx::ast::Type::any_letter, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { $1 });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	| UNDERSCORE  {
		auto* const newNode = new dregx::ast::node::any_letter({::dregx::ast::Type::any_letter, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::UNDERSCORE({::dregx::ast::Type::UNDERSCORE, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


any_letter_exclude_underscore:
	T_  {
		auto* const newNode = new dregx::ast::node::any_letter_exclude_underscore({::dregx::ast::Type::any_letter_exclude_underscore, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::T_({::dregx::ast::Type::T_, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	| R_  {
		auto* const newNode = new dregx::ast::node::any_letter_exclude_underscore({::dregx::ast::Type::any_letter_exclude_underscore, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::R_({::dregx::ast::Type::R_, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	| N_  {
		auto* const newNode = new dregx::ast::node::any_letter_exclude_underscore({::dregx::ast::Type::any_letter_exclude_underscore, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 2, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::N_({::dregx::ast::Type::N_, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	| B_  {
		auto* const newNode = new dregx::ast::node::any_letter_exclude_underscore({::dregx::ast::Type::any_letter_exclude_underscore, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 3, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::B_({::dregx::ast::Type::B_, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	| V_  {
		auto* const newNode = new dregx::ast::node::any_letter_exclude_underscore({::dregx::ast::Type::any_letter_exclude_underscore, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 4, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::V_({::dregx::ast::Type::V_, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	| A_  {
		auto* const newNode = new dregx::ast::node::any_letter_exclude_underscore({::dregx::ast::Type::any_letter_exclude_underscore, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 5, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::A_({::dregx::ast::Type::A_, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	| LETTER  {
		auto* const newNode = new dregx::ast::node::any_letter_exclude_underscore({::dregx::ast::Type::any_letter_exclude_underscore, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 6, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::LETTER({::dregx::ast::Type::LETTER, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;


any:
	LEFT_CURLY_BRACKET  {
		auto* const newNode = new dregx::ast::node::any({::dregx::ast::Type::any, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::LEFT_CURLY_BRACKET({::dregx::ast::Type::LEFT_CURLY_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	| RIGHT_CURLY_BRACKET  {
		auto* const newNode = new dregx::ast::node::any({::dregx::ast::Type::any, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::RIGHT_CURLY_BRACKET({::dregx::ast::Type::RIGHT_CURLY_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	| LEFT_SQUARE_BRACKET  {
		auto* const newNode = new dregx::ast::node::any({::dregx::ast::Type::any, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 2, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::LEFT_SQUARE_BRACKET({::dregx::ast::Type::LEFT_SQUARE_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	| RIGHT_SQUARE_BRACKET  {
		auto* const newNode = new dregx::ast::node::any({::dregx::ast::Type::any, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 3, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::RIGHT_SQUARE_BRACKET({::dregx::ast::Type::RIGHT_SQUARE_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	| LEFT_BRACKET  {
		auto* const newNode = new dregx::ast::node::any({::dregx::ast::Type::any, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 4, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::LEFT_BRACKET({::dregx::ast::Type::LEFT_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	| RIGHT_BRACKET  {
		auto* const newNode = new dregx::ast::node::any({::dregx::ast::Type::any, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 5, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::RIGHT_BRACKET({::dregx::ast::Type::RIGHT_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	| COMMA  {
		auto* const newNode = new dregx::ast::node::any({::dregx::ast::Type::any, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 6, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::COMMA({::dregx::ast::Type::COMMA, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	| OR  {
		auto* const newNode = new dregx::ast::node::any({::dregx::ast::Type::any, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 7, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::OR({::dregx::ast::Type::OR, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	| MIN  {
		auto* const newNode = new dregx::ast::node::any({::dregx::ast::Type::any, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 8, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::MIN({::dregx::ast::Type::MIN, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	| OPTIONAL  {
		auto* const newNode = new dregx::ast::node::any({::dregx::ast::Type::any, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 9, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::OPTIONAL({::dregx::ast::Type::OPTIONAL, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	| UNDERSCORE  {
		auto* const newNode = new dregx::ast::node::any({::dregx::ast::Type::any, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 10, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::UNDERSCORE({::dregx::ast::Type::UNDERSCORE, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	| NOT  {
		auto* const newNode = new dregx::ast::node::any({::dregx::ast::Type::any, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 11, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::NOT({::dregx::ast::Type::NOT, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	| NUMBER  {
		auto* const newNode = new dregx::ast::node::any({::dregx::ast::Type::any, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 12, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::NUMBER({::dregx::ast::Type::NUMBER, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	| T_  {
		auto* const newNode = new dregx::ast::node::any({::dregx::ast::Type::any, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 13, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::T_({::dregx::ast::Type::T_, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	| N_  {
		auto* const newNode = new dregx::ast::node::any({::dregx::ast::Type::any, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 14, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::N_({::dregx::ast::Type::N_, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	| R_  {
		auto* const newNode = new dregx::ast::node::any({::dregx::ast::Type::any, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 15, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::R_({::dregx::ast::Type::R_, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	| B_  {
		auto* const newNode = new dregx::ast::node::any({::dregx::ast::Type::any, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 16, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::B_({::dregx::ast::Type::B_, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	| V_  {
		auto* const newNode = new dregx::ast::node::any({::dregx::ast::Type::any, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 17, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::V_({::dregx::ast::Type::V_, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	| A_  {
		auto* const newNode = new dregx::ast::node::any({::dregx::ast::Type::any, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 18, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::A_({::dregx::ast::Type::A_, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	| LETTER  {
		auto* const newNode = new dregx::ast::node::any({::dregx::ast::Type::any, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 19, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::LETTER({::dregx::ast::Type::LETTER, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	| SPACE  {
		auto* const newNode = new dregx::ast::node::any({::dregx::ast::Type::any, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 20, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::SPACE({::dregx::ast::Type::SPACE, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	| TAB  {
		auto* const newNode = new dregx::ast::node::any({::dregx::ast::Type::any, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 21, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::TAB({::dregx::ast::Type::TAB, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	| PLUS  {
		auto* const newNode = new dregx::ast::node::any({::dregx::ast::Type::any, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 22, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::PLUS({::dregx::ast::Type::PLUS, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	| STAR  {
		auto* const newNode = new dregx::ast::node::any({::dregx::ast::Type::any, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 23, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::STAR({::dregx::ast::Type::STAR, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	| OTHER  {
		auto* const newNode = new dregx::ast::node::any({::dregx::ast::Type::any, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 24, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::OTHER({::dregx::ast::Type::OTHER, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
	| SLASH  {
		auto* const newNode = new dregx::ast::node::any({::dregx::ast::Type::any, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 25, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::SLASH({::dregx::ast::Type::SLASH, ::deamer::external::cpp::ast::NodeValue::terminal, $1 }) });
		$$ = newNode;

		// Ignored, Deleted, tokens are deleted
	}
;



%%

void dregxerror(const char* s)
{
	std::cout << "Syntax error on line: " << s << '\n';
}

deamer::external::cpp::ast::Tree* dregx::parser::Parser::Parse(const std::string& text) const
{
	outputTree = nullptr;
	YY_BUFFER_STATE buf;
	buf = dregx_scan_string(text.c_str());
	dregxparse();
	dregx_delete_buffer(buf);
	dregxlex_destroy();

	return outputTree;
}
