%option yylineno
%option noyywrap
%option never-interactive
%option nounistd

%{
#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <Deamer/External/Cpp/Lexer/TerminalObject.h>
#include "dregx/Flex/Lexer.h"
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
#include "dregx/Ast/Node/any_letter.h"
#include "dregx/Ast/Node/any_letter_exclude_underscore.h"
#include "dregx/Ast/Node/any.h"
#include "Bison/dregx_parser.tab.h"
void showError();
extern int dregxlex();

static bool local_store = false;
static int column = 0;
static int handleColumn(const std::string& text);
static void store(const deamer::external::cpp::lexer::TerminalObject* const newObject);
static std::vector<const deamer::external::cpp::lexer::TerminalObject*> local_objects;
#ifndef yyval
#define yyval yytext
#endif //yyval
%}

LEFT_CURLY_BRACKET	([(])
RIGHT_CURLY_BRACKET	([)])
LEFT_SQUARE_BRACKET_NOT	([\[][\^])
LEFT_SQUARE_BRACKET	([\[])
RIGHT_SQUARE_BRACKET	([\]])
LEFT_BRACKET	([\{])
RIGHT_BRACKET	([\}])
COMMA	([,])
SLASH	([\\])
OR	([|])
MIN	([\-])
UNDERSCORE	([_])
NOT	([\^])
PLUS	([+])
STAR	([*])
NUMBER	([0-9])
T_	([t])
N_	([n])
R_	([r])
B_	([b])
V_	([v])
A_	([a])
LETTER	([a-zA-Z])
SPACE	([ ])
TAB	([\t])
OTHER	([^0-9a-zA-Z+*,\n\r\t\b\v\a_ ])
DELETE_ESCAPE_CHARS	([\n\r\b\v\a])

%%

{LEFT_CURLY_BRACKET}	{if (local_store) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(1)));else dregxlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(1));;handleColumn(yyval);if (!local_store) return (LEFT_CURLY_BRACKET);;}
{RIGHT_CURLY_BRACKET}	{if (local_store) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(2)));else dregxlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(2));;handleColumn(yyval);if (!local_store) return (RIGHT_CURLY_BRACKET);;}
{LEFT_SQUARE_BRACKET_NOT}	{if (local_store) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(3)));else dregxlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(3));;handleColumn(yyval);if (!local_store) return (LEFT_SQUARE_BRACKET_NOT);;}
{LEFT_SQUARE_BRACKET}	{if (local_store) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(4)));else dregxlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(4));;handleColumn(yyval);if (!local_store) return (LEFT_SQUARE_BRACKET);;}
{RIGHT_SQUARE_BRACKET}	{if (local_store) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(5)));else dregxlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(5));;handleColumn(yyval);if (!local_store) return (RIGHT_SQUARE_BRACKET);;}
{LEFT_BRACKET}	{if (local_store) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(6)));else dregxlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(6));;handleColumn(yyval);if (!local_store) return (LEFT_BRACKET);;}
{RIGHT_BRACKET}	{if (local_store) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(7)));else dregxlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(7));;handleColumn(yyval);if (!local_store) return (RIGHT_BRACKET);;}
{COMMA}	{if (local_store) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(8)));else dregxlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(8));;handleColumn(yyval);if (!local_store) return (COMMA);;}
{SLASH}	{if (local_store) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(9)));else dregxlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(9));;handleColumn(yyval);if (!local_store) return (SLASH);;}
{OR}	{if (local_store) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(10)));else dregxlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(10));;handleColumn(yyval);if (!local_store) return (OR);;}
{MIN}	{if (local_store) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(11)));else dregxlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(11));;handleColumn(yyval);if (!local_store) return (MIN);;}
{UNDERSCORE}	{if (local_store) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(12)));else dregxlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(12));;handleColumn(yyval);if (!local_store) return (UNDERSCORE);;}
{NOT}	{if (local_store) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(13)));else dregxlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(13));;handleColumn(yyval);if (!local_store) return (NOT);;}
{PLUS}	{if (local_store) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(14)));else dregxlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(14));;handleColumn(yyval);if (!local_store) return (PLUS);;}
{STAR}	{if (local_store) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(15)));else dregxlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(15));;handleColumn(yyval);if (!local_store) return (STAR);;}
{NUMBER}	{if (local_store) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(16)));else dregxlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(16));;handleColumn(yyval);if (!local_store) return (NUMBER);;}
{T_}	{if (local_store) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(17)));else dregxlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(17));;handleColumn(yyval);if (!local_store) return (T_);;}
{N_}	{if (local_store) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(18)));else dregxlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(18));;handleColumn(yyval);if (!local_store) return (N_);;}
{R_}	{if (local_store) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(19)));else dregxlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(19));;handleColumn(yyval);if (!local_store) return (R_);;}
{B_}	{if (local_store) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(20)));else dregxlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(20));;handleColumn(yyval);if (!local_store) return (B_);;}
{V_}	{if (local_store) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(21)));else dregxlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(21));;handleColumn(yyval);if (!local_store) return (V_);;}
{A_}	{if (local_store) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(22)));else dregxlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(22));;handleColumn(yyval);if (!local_store) return (A_);;}
{LETTER}	{if (local_store) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(23)));else dregxlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(23));;handleColumn(yyval);if (!local_store) return (LETTER);;}
{SPACE}	{if (local_store) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(24)));else dregxlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(24));;handleColumn(yyval);if (!local_store) return (SPACE);;}
{TAB}	{if (local_store) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(25)));else dregxlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(25));;handleColumn(yyval);if (!local_store) return (TAB);;}
{OTHER}	{if (local_store) store(new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(26)));else dregxlval.Terminal = new deamer::external::cpp::lexer::TerminalObject(yyval, yylineno, column, std::size_t(26));;handleColumn(yyval);if (!local_store) return (OTHER);;}
{DELETE_ESCAPE_CHARS}	{handleColumn(yyval);if (!local_store) ;}

%%
static void store(const deamer::external::cpp::lexer::TerminalObject* const newObject)
{
	local_objects.push_back(newObject);
}

static void clear()
{
	local_objects.clear();
}

static int handleColumn(const std::string& text)
{
	int currentColumn = column;
	currentColumn += text.size();
	for (auto character : text)
	{
		if (character == '\n')
		{
			currentColumn = 0;
			break;
		}
	}
	
	return currentColumn;
}

std::vector<const deamer::external::cpp::lexer::TerminalObject*> dregx::lexer::Lexer::Tokenize(const std::string& text) const
{
	local_store = true;
	column = 0;

	YY_BUFFER_STATE buf;
	buf = yy_scan_string(text.c_str());
	yylex();
	yy_delete_buffer(buf);
	yylex_destroy();

	local_store = false;

	auto local_objects_copy = local_objects;
	clear();

	return local_objects_copy;
}


