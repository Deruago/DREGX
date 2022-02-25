/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Skeleton interface for Bison GLR parsers in C

   Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_DREGX_DREGX_PARSER_TAB_H_INCLUDED
# define YY_DREGX_DREGX_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int dregxdebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    LEFT_CURLY_BRACKET = 258,      /* LEFT_CURLY_BRACKET  */
    RIGHT_CURLY_BRACKET = 259,     /* RIGHT_CURLY_BRACKET  */
    LEFT_SQUARE_BRACKET_NOT = 260, /* LEFT_SQUARE_BRACKET_NOT  */
    LEFT_SQUARE_BRACKET = 261,     /* LEFT_SQUARE_BRACKET  */
    RIGHT_SQUARE_BRACKET = 262,    /* RIGHT_SQUARE_BRACKET  */
    LEFT_BRACKET = 263,            /* LEFT_BRACKET  */
    RIGHT_BRACKET = 264,           /* RIGHT_BRACKET  */
    COMMA = 265,                   /* COMMA  */
    SLASH = 266,                   /* SLASH  */
    OR = 267,                      /* OR  */
    MIN = 268,                     /* MIN  */
    UNDERSCORE = 269,              /* UNDERSCORE  */
    NOT = 270,                     /* NOT  */
    PLUS = 271,                    /* PLUS  */
    STAR = 272,                    /* STAR  */
    OPTIONAL = 273,                /* OPTIONAL  */
    NUMBER = 274,                  /* NUMBER  */
    T_ = 275,                      /* T_  */
    N_ = 276,                      /* N_  */
    R_ = 277,                      /* R_  */
    B_ = 278,                      /* B_  */
    V_ = 279,                      /* V_  */
    A_ = 280,                      /* A_  */
    LETTER = 281,                  /* LETTER  */
    SPACE = 282,                   /* SPACE  */
    TAB = 283,                     /* TAB  */
    OTHER = 284,                   /* OTHER  */
    DELETE_ESCAPE_CHARS = 285      /* DELETE_ESCAPE_CHARS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 163 "./dregx_parser.y"

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
	::dregx::ast::node::deamerreserved_plus__capture_logic__* dregx_deamerreserved_plus__capture_logic__;
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


#line 157 "dregx_parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE dregxlval;

int dregxparse (void);

#endif /* !YY_DREGX_DREGX_PARSER_TAB_H_INCLUDED  */
