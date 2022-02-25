/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Skeleton implementation for Bison GLR parsers in C

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

/* C GLR parser skeleton written by Paul Hilfinger.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "glr.c"

/* Pure parsers.  */
#define YYPURE 0




/* Substitute the variable and function names.  */
#define yyparse dregxparse
#define yylex   dregxlex
#define yyerror dregxerror
#define yydebug dregxdebug
#define yylval  dregxlval
#define yychar  dregxchar
#define yynerrs dregxnerrs

/* First part of user prologue.  */
#line 4 "./dregx_parser.y"

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

#line 157 "dregx_parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "dregx_parser.tab.h"

/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_LEFT_CURLY_BRACKET = 3,         /* LEFT_CURLY_BRACKET  */
  YYSYMBOL_RIGHT_CURLY_BRACKET = 4,        /* RIGHT_CURLY_BRACKET  */
  YYSYMBOL_LEFT_SQUARE_BRACKET_NOT = 5,    /* LEFT_SQUARE_BRACKET_NOT  */
  YYSYMBOL_LEFT_SQUARE_BRACKET = 6,        /* LEFT_SQUARE_BRACKET  */
  YYSYMBOL_RIGHT_SQUARE_BRACKET = 7,       /* RIGHT_SQUARE_BRACKET  */
  YYSYMBOL_LEFT_BRACKET = 8,               /* LEFT_BRACKET  */
  YYSYMBOL_RIGHT_BRACKET = 9,              /* RIGHT_BRACKET  */
  YYSYMBOL_COMMA = 10,                     /* COMMA  */
  YYSYMBOL_SLASH = 11,                     /* SLASH  */
  YYSYMBOL_OR = 12,                        /* OR  */
  YYSYMBOL_MIN = 13,                       /* MIN  */
  YYSYMBOL_UNDERSCORE = 14,                /* UNDERSCORE  */
  YYSYMBOL_NOT = 15,                       /* NOT  */
  YYSYMBOL_PLUS = 16,                      /* PLUS  */
  YYSYMBOL_STAR = 17,                      /* STAR  */
  YYSYMBOL_OPTIONAL = 18,                  /* OPTIONAL  */
  YYSYMBOL_NUMBER = 19,                    /* NUMBER  */
  YYSYMBOL_T_ = 20,                        /* T_  */
  YYSYMBOL_N_ = 21,                        /* N_  */
  YYSYMBOL_R_ = 22,                        /* R_  */
  YYSYMBOL_B_ = 23,                        /* B_  */
  YYSYMBOL_V_ = 24,                        /* V_  */
  YYSYMBOL_A_ = 25,                        /* A_  */
  YYSYMBOL_LETTER = 26,                    /* LETTER  */
  YYSYMBOL_SPACE = 27,                     /* SPACE  */
  YYSYMBOL_TAB = 28,                       /* TAB  */
  YYSYMBOL_OTHER = 29,                     /* OTHER  */
  YYSYMBOL_DELETE_ESCAPE_CHARS = 30,       /* DELETE_ESCAPE_CHARS  */
  YYSYMBOL_YYACCEPT = 31,                  /* $accept  */
  YYSYMBOL_program = 32,                   /* program  */
  YYSYMBOL_deamerreserved_star__stmt__ = 33, /* deamerreserved_star__stmt__  */
  YYSYMBOL_stmt = 34,                      /* stmt  */
  YYSYMBOL_word = 35,                      /* word  */
  YYSYMBOL_group = 36,                     /* group  */
  YYSYMBOL_deamerreserved_plus__word__ = 37, /* deamerreserved_plus__word__  */
  YYSYMBOL_or_concat = 38,                 /* or_concat  */
  YYSYMBOL_deamerreserved_arrow__word__ = 39, /* deamerreserved_arrow__word__  */
  YYSYMBOL_deamerreserved_star__opt_pad__OR__word__ = 40, /* deamerreserved_star__opt_pad__OR__word__  */
  YYSYMBOL_square = 41,                    /* square  */
  YYSYMBOL_capture = 42,                   /* capture  */
  YYSYMBOL_deamerreserved_plus__capture_logic__ = 43, /* deamerreserved_plus__capture_logic__  */
  YYSYMBOL_capture_logic = 44,             /* capture_logic  */
  YYSYMBOL_capture_symbols = 45,           /* capture_symbols  */
  YYSYMBOL_capture_whitespace = 46,        /* capture_whitespace  */
  YYSYMBOL_capture_range = 47,             /* capture_range  */
  YYSYMBOL_capture_letter_range = 48,      /* capture_letter_range  */
  YYSYMBOL_capture_number_range = 49,      /* capture_number_range  */
  YYSYMBOL_capture_number = 50,            /* capture_number  */
  YYSYMBOL_capture_letter = 51,            /* capture_letter  */
  YYSYMBOL_capture_special_character = 52, /* capture_special_character  */
  YYSYMBOL_extension_modifier = 53,        /* extension_modifier  */
  YYSYMBOL_min_repition = 54,              /* min_repition  */
  YYSYMBOL_deamerreserved_plus__NUMBER__ = 55, /* deamerreserved_plus__NUMBER__  */
  YYSYMBOL_max_repition = 56,              /* max_repition  */
  YYSYMBOL_standalone = 57,                /* standalone  */
  YYSYMBOL_opt_pad = 58,                   /* opt_pad  */
  YYSYMBOL_optional_padding = 59,          /* optional_padding  */
  YYSYMBOL_deamerreserved_star__padding__ = 60, /* deamerreserved_star__padding__  */
  YYSYMBOL_padding = 61,                   /* padding  */
  YYSYMBOL_special_char_any = 62,          /* special_char_any  */
  YYSYMBOL_any_number = 63,                /* any_number  */
  YYSYMBOL_any_letter = 64,                /* any_letter  */
  YYSYMBOL_any_letter_exclude_underscore = 65, /* any_letter_exclude_underscore  */
  YYSYMBOL_any = 66                        /* any  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;


/* Default (constant) value used for initialization for null
   right-hand sides.  Unlike the standard yacc.c template, here we set
   the default value of $$ to a zeroed-out value.  Since the default
   value is undefined, this behavior is technically correct.  */
static YYSTYPE yyval_default;



#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif
#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YYFREE
# define YYFREE free
#endif
#ifndef YYMALLOC
# define YYMALLOC malloc
#endif
#ifndef YYREALLOC
# define YYREALLOC realloc
#endif

#ifdef __cplusplus
  typedef bool yybool;
# define yytrue true
# define yyfalse false
#else
  /* When we move to stdbool, get rid of the various casts to yybool.  */
  typedef signed char yybool;
# define yytrue 1
# define yyfalse 0
#endif

#ifndef YYSETJMP
# include <setjmp.h>
# define YYJMP_BUF jmp_buf
# define YYSETJMP(Env) setjmp (Env)
/* Pacify Clang and ICC.  */
# define YYLONGJMP(Env, Val)                    \
 do {                                           \
   longjmp (Env, Val);                          \
   YY_ASSERT (0);                               \
 } while (yyfalse)
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* The _Noreturn keyword of C11.  */
#ifndef _Noreturn
# if (defined __cplusplus \
      && ((201103 <= __cplusplus && !(__GNUC__ == 4 && __GNUC_MINOR__ == 7)) \
          || (defined _MSC_VER && 1900 <= _MSC_VER)))
#  define _Noreturn [[noreturn]]
# elif ((!defined __cplusplus || defined __clang__) \
        && (201112 <= (defined __STDC_VERSION__ ? __STDC_VERSION__ : 0) \
            || (!defined __STRICT_ANSI__ \
                && (4 < __GNUC__ + (7 <= __GNUC_MINOR__) \
                    || (defined __apple_build_version__ \
                        ? 6000000 <= __apple_build_version__ \
                        : 3 < __clang_major__ + (5 <= __clang_minor__))))))
   /* _Noreturn works as-is.  */
# elif (2 < __GNUC__ + (8 <= __GNUC_MINOR__) || defined __clang__ \
        || 0x5110 <= __SUNPRO_C)
#  define _Noreturn __attribute__ ((__noreturn__))
# elif 1200 <= (defined _MSC_VER ? _MSC_VER : 0)
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  15
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   196

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  31
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  104
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  137
/* YYMAXRHS -- Maximum number of symbols on right-hand side of rule.  */
#define YYMAXRHS 8
/* YYMAXLEFT -- Maximum number of symbols to the left of a handle
   accessed by $0, $-1, etc., in any rule.  */
#define YYMAXLEFT 0

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   285

/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30
};

#if YYDEBUG
/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   235,   235,   246,   252,   262,   272,   278,   284,   294,
     300,   306,   312,   318,   324,   330,   336,   342,   348,   358,
     364,   374,   384,   394,   400,   410,   416,   422,   428,   434,
     444,   450,   460,   466,   476,   482,   488,   494,   500,   506,
     516,   522,   528,   534,   540,   546,   556,   562,   572,   578,
     588,   598,   608,   618,   628,   638,   648,   658,   664,   674,
     684,   690,   700,   710,   720,   726,   736,   742,   752,   762,
     772,   778,   788,   794,   800,   806,   812,   818,   824,   834,
     840,   846,   852,   858,   864,   870,   876,   882,   888,   894,
     900,   906,   912,   918,   924,   930,   936,   942,   948,   954,
     960,   966,   972,   978,   984
};
#endif

#define YYPACT_NINF (-100)
#define YYTABLE_NINF (-66)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      12,  -100,  -100,    11,    -6,    14,  -100,  -100,  -100,     0,
    -100,    77,  -100,  -100,    -6,  -100,  -100,  -100,  -100,  -100,
    -100,  -100,     5,    -6,   167,   167,  -100,  -100,  -100,  -100,
    -100,  -100,  -100,  -100,  -100,  -100,  -100,  -100,  -100,    -6,
       3,    -6,    -6,  -100,   126,  -100,  -100,  -100,  -100,     2,
    -100,  -100,  -100,    13,   167,  -100,  -100,  -100,  -100,  -100,
    -100,  -100,  -100,  -100,  -100,  -100,    32,    18,    -6,     7,
       6,  -100,    49,    40,    42,  -100,  -100,  -100,  -100,  -100,
    -100,  -100,  -100,  -100,  -100,  -100,  -100,  -100,  -100,  -100,
    -100,  -100,  -100,  -100,  -100,  -100,  -100,  -100,  -100,  -100,
    -100,  -100,    28,  -100,  -100,   137,  -100,    38,     7,  -100,
      -6,    98,   148,  -100,  -100,    -6,  -100,    31,  -100,  -100,
    -100,  -100,  -100,  -100,  -100,  -100,  -100,    -6,     7,  -100,
      39,    41,  -100,    -6,  -100,    65,  -100
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
      65,    66,    67,     0,    65,    65,     5,     6,     7,    29,
       8,     0,    62,    63,    65,     1,     2,     3,    26,    27,
      28,    25,     0,    65,     0,     0,    71,    69,    72,    74,
      73,    75,    76,    77,    78,    61,    60,    70,    64,    65,
      65,    65,    65,    43,     0,    44,    41,    42,    45,    69,
      46,    47,    40,     0,    32,    39,    38,    34,    48,    49,
      37,    36,    35,    54,    52,    53,    70,     0,    65,     0,
      65,    20,     0,     0,     0,    79,    80,    81,    82,    83,
      84,    85,   104,    86,    87,    89,    90,   101,   102,    88,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     103,    68,     0,    30,    33,     0,    31,     0,    57,    56,
      65,    18,    13,    51,    50,    65,    58,    24,    21,    16,
      15,    14,    17,    11,    10,     9,    12,    65,     0,    22,
       0,     0,    59,    65,    55,    24,    23
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -100,  -100,    48,  -100,   -21,  -100,    33,  -100,  -100,   -78,
    -100,  -100,   -22,  -100,  -100,  -100,  -100,  -100,  -100,  -100,
    -100,  -100,   -88,  -100,   -99,  -100,  -100,    -4,  -100,    46,
    -100,  -100,    -7,    -5,   -10,  -100
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     3,     4,     5,     6,     7,    71,    42,   118,   129,
       8,     9,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    21,    68,   109,   127,    10,    11,    12,    13,
      14,    63,    64,    65,    66,   101
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      16,    37,    40,    67,    35,    22,    36,   -19,   -65,   116,
     -19,    15,    -4,    39,    -4,   102,    18,    19,    20,    70,
     103,     1,     2,   122,   126,   106,   108,     1,     2,   132,
       1,     2,   104,     1,     2,    69,    72,    73,    74,     1,
       2,     1,     2,   -65,   111,   105,   112,   113,   115,    70,
     134,   133,    23,    17,    24,    25,    41,   136,     1,     2,
      38,   110,    37,    26,   107,    35,     0,    36,    27,    28,
      29,    30,    31,    32,    33,    34,     0,   -65,     0,     0,
      23,     0,    24,    25,     0,     0,     0,     0,     0,   117,
       0,    26,     1,     2,     0,   114,    27,    28,    29,    30,
      31,    32,    33,    34,     0,     0,   -65,    22,    22,     0,
       0,   128,   135,   130,   119,   120,   121,     0,     0,     0,
       0,     0,     0,   131,     0,     1,     2,     0,     0,    75,
      76,   130,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   -65,    28,    29,    30,
      31,    32,    33,    34,   123,   124,   125,     0,     0,     0,
       0,     0,     0,     0,     0,     1,     2,    43,    44,    45,
       0,    26,     0,    46,    47,    48,    49,    28,    29,    30,
      31,    32,    33,    34,    50,    51,    52
};

static const yytype_int16 yycheck[] =
{
       4,    11,    23,    25,    11,     9,    11,     4,     8,   108,
       4,     0,     0,     8,     0,    13,    16,    17,    18,    40,
       7,    27,    28,   111,   112,     7,    19,    27,    28,   128,
      27,    28,    54,    27,    28,    39,    40,    41,    42,    27,
      28,    27,    28,    12,     4,    13,     4,    19,    10,    70,
       9,    12,     3,     5,     5,     6,    23,   135,    27,    28,
      14,    12,    72,    14,    68,    72,    -1,    72,    19,    20,
      21,    22,    23,    24,    25,    26,    -1,    12,    -1,    -1,
       3,    -1,     5,     6,    -1,    -1,    -1,    -1,    -1,   110,
      -1,    14,    27,    28,    -1,   105,    19,    20,    21,    22,
      23,    24,    25,    26,    -1,    -1,     8,   111,   112,    -1,
      -1,   115,   133,   117,    16,    17,    18,    -1,    -1,    -1,
      -1,    -1,    -1,   127,    -1,    27,    28,    -1,    -1,     3,
       4,   135,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,     8,    20,    21,    22,
      23,    24,    25,    26,    16,    17,    18,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    27,    28,    10,    11,    12,
      -1,    14,    -1,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    27,    28,    32,    33,    34,    35,    36,    41,    42,
      57,    58,    59,    60,    61,     0,    58,    33,    16,    17,
      18,    53,    58,     3,     5,     6,    14,    19,    20,    21,
      22,    23,    24,    25,    26,    63,    64,    65,    60,     8,
      35,    37,    38,    10,    11,    12,    16,    17,    18,    19,
      27,    28,    29,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    62,    63,    64,    65,    43,    54,    58,
      35,    37,    58,    58,    58,     3,     4,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    66,    13,     7,    43,    13,     7,    58,    19,    55,
      12,     4,     4,    19,    65,    10,    55,    35,    39,    16,
      17,    18,    53,    16,    17,    18,    53,    56,    58,    40,
      58,    58,    55,    12,     9,    35,    40
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    31,    32,    33,    33,    34,    35,    35,    35,    36,
      36,    36,    36,    36,    36,    36,    36,    36,    36,    37,
      37,    38,    39,    40,    40,    41,    41,    41,    41,    41,
      42,    42,    43,    43,    44,    44,    44,    44,    44,    44,
      45,    45,    45,    45,    45,    45,    46,    46,    47,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    55,    56,
      57,    57,    58,    59,    60,    60,    61,    61,    62,    63,
      64,    64,    65,    65,    65,    65,    65,    65,    65,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    66
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     0,     1,     1,     1,     1,     6,
       6,     6,     6,     5,     6,     6,     6,     6,     5,     1,
       2,     4,     2,     4,     0,     2,     2,     2,     2,     1,
       4,     4,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     3,     1,     1,     1,     8,     2,     1,     2,     2,
       2,     2,     1,     1,     2,     0,     1,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1
};


/* YYDPREC[RULE-NUM] -- Dynamic precedence of rule #RULE-NUM (0 if none).  */
static const yytype_int8 yydprec[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0
};

/* YYMERGER[RULE-NUM] -- Index of merging function for rule #RULE-NUM.  */
static const yytype_int8 yymerger[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0
};

/* YYIMMEDIATE[RULE-NUM] -- True iff rule #RULE-NUM is not to be deferred, as
   in the case of predicates.  */
static const yybool yyimmediate[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0
};

/* YYCONFLP[YYPACT[STATE-NUM]] -- Pointer into YYCONFL of start of
   list of conflicting reductions corresponding to action entry for
   state STATE-NUM in yytable.  0 means no conflicts.  The list in
   yyconfl is terminated by a rule number of 0.  */
static const yytype_int8 yyconflp[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     9,    11,     0,
      13,    15,     0,    17,    19,     0,     0,     0,     0,     1,
       3,     5,     7,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    29,    31,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    33,    35,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    21,    23,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    25,    27,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0
};

/* YYCONFL[I] -- lists of conflicting rule numbers, each terminated by
   0, pointed into by YYCONFLP.  */
static const short yyconfl[] =
{
       0,     4,     0,     4,     0,     4,     0,     4,     0,    29,
       0,    29,     0,    19,     0,    19,     0,    19,     0,    19,
       0,    18,     0,    18,     0,    13,     0,    13,     0,    24,
       0,    24,     0,    24,     0,    24,     0
};



YYSTYPE yylval;

int yynerrs;
int yychar;

enum { YYENOMEM = -2 };

typedef enum { yyok, yyaccept, yyabort, yyerr, yynomem } YYRESULTTAG;

#define YYCHK(YYE)                              \
  do {                                          \
    YYRESULTTAG yychk_flag = YYE;               \
    if (yychk_flag != yyok)                     \
      return yychk_flag;                        \
  } while (0)

/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   SIZE_MAX < YYMAXDEPTH * sizeof (GLRStackItem)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif

/* Minimum number of free items on the stack allowed after an
   allocation.  This is to allow allocation and initialization
   to be completed by functions that call yyexpandGLRStack before the
   stack is expanded, thus insuring that all necessary pointers get
   properly redirected to new data.  */
#define YYHEADROOM 2

#ifndef YYSTACKEXPANDABLE
#  define YYSTACKEXPANDABLE 1
#endif

#if YYSTACKEXPANDABLE
# define YY_RESERVE_GLRSTACK(Yystack)                   \
  do {                                                  \
    if (Yystack->yyspaceLeft < YYHEADROOM)              \
      yyexpandGLRStack (Yystack);                       \
  } while (0)
#else
# define YY_RESERVE_GLRSTACK(Yystack)                   \
  do {                                                  \
    if (Yystack->yyspaceLeft < YYHEADROOM)              \
      yyMemoryExhausted (Yystack);                      \
  } while (0)
#endif

/** State numbers. */
typedef int yy_state_t;

/** Rule numbers. */
typedef int yyRuleNum;

/** Item references. */
typedef short yyItemNum;

typedef struct yyGLRState yyGLRState;
typedef struct yyGLRStateSet yyGLRStateSet;
typedef struct yySemanticOption yySemanticOption;
typedef union yyGLRStackItem yyGLRStackItem;
typedef struct yyGLRStack yyGLRStack;

struct yyGLRState
{
  /** Type tag: always true.  */
  yybool yyisState;
  /** Type tag for yysemantics.  If true, yyval applies, otherwise
   *  yyfirstVal applies.  */
  yybool yyresolved;
  /** Number of corresponding LALR(1) machine state.  */
  yy_state_t yylrState;
  /** Preceding state in this stack */
  yyGLRState* yypred;
  /** Source position of the last token produced by my symbol */
  YYPTRDIFF_T yyposn;
  union {
    /** First in a chain of alternative reductions producing the
     *  nonterminal corresponding to this state, threaded through
     *  yynext.  */
    yySemanticOption* yyfirstVal;
    /** Semantic value for this state.  */
    YYSTYPE yyval;
  } yysemantics;
};

struct yyGLRStateSet
{
  yyGLRState** yystates;
  /** During nondeterministic operation, yylookaheadNeeds tracks which
   *  stacks have actually needed the current lookahead.  During deterministic
   *  operation, yylookaheadNeeds[0] is not maintained since it would merely
   *  duplicate yychar != YYEMPTY.  */
  yybool* yylookaheadNeeds;
  YYPTRDIFF_T yysize;
  YYPTRDIFF_T yycapacity;
};

struct yySemanticOption
{
  /** Type tag: always false.  */
  yybool yyisState;
  /** Rule number for this reduction */
  yyRuleNum yyrule;
  /** The last RHS state in the list of states to be reduced.  */
  yyGLRState* yystate;
  /** The lookahead for this reduction.  */
  int yyrawchar;
  YYSTYPE yyval;
  /** Next sibling in chain of options.  To facilitate merging,
   *  options are chained in decreasing order by address.  */
  yySemanticOption* yynext;
};

/** Type of the items in the GLR stack.  The yyisState field
 *  indicates which item of the union is valid.  */
union yyGLRStackItem {
  yyGLRState yystate;
  yySemanticOption yyoption;
};

struct yyGLRStack {
  int yyerrState;


  YYJMP_BUF yyexception_buffer;
  yyGLRStackItem* yyitems;
  yyGLRStackItem* yynextFree;
  YYPTRDIFF_T yyspaceLeft;
  yyGLRState* yysplitPoint;
  yyGLRState* yylastDeleted;
  yyGLRStateSet yytops;
};

#if YYSTACKEXPANDABLE
static void yyexpandGLRStack (yyGLRStack* yystackp);
#endif

_Noreturn static void
yyFail (yyGLRStack* yystackp, const char* yymsg)
{
  if (yymsg != YY_NULLPTR)
    yyerror (yymsg);
  YYLONGJMP (yystackp->yyexception_buffer, 1);
}

_Noreturn static void
yyMemoryExhausted (yyGLRStack* yystackp)
{
  YYLONGJMP (yystackp->yyexception_buffer, 2);
}

/** Accessing symbol of state YYSTATE.  */
static inline yysymbol_kind_t
yy_accessing_symbol (yy_state_t yystate)
{
  return YY_CAST (yysymbol_kind_t, yystos[yystate]);
}

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "LEFT_CURLY_BRACKET",
  "RIGHT_CURLY_BRACKET", "LEFT_SQUARE_BRACKET_NOT", "LEFT_SQUARE_BRACKET",
  "RIGHT_SQUARE_BRACKET", "LEFT_BRACKET", "RIGHT_BRACKET", "COMMA",
  "SLASH", "OR", "MIN", "UNDERSCORE", "NOT", "PLUS", "STAR", "OPTIONAL",
  "NUMBER", "T_", "N_", "R_", "B_", "V_", "A_", "LETTER", "SPACE", "TAB",
  "OTHER", "DELETE_ESCAPE_CHARS", "$accept", "program",
  "deamerreserved_star__stmt__", "stmt", "word", "group",
  "deamerreserved_plus__word__", "or_concat",
  "deamerreserved_arrow__word__",
  "deamerreserved_star__opt_pad__OR__word__", "square", "capture",
  "deamerreserved_plus__capture_logic__", "capture_logic",
  "capture_symbols", "capture_whitespace", "capture_range",
  "capture_letter_range", "capture_number_range", "capture_number",
  "capture_letter", "capture_special_character", "extension_modifier",
  "min_repition", "deamerreserved_plus__NUMBER__", "max_repition",
  "standalone", "opt_pad", "optional_padding",
  "deamerreserved_star__padding__", "padding", "special_char_any",
  "any_number", "any_letter", "any_letter_exclude_underscore", "any", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

/** Left-hand-side symbol for rule #YYRULE.  */
static inline yysymbol_kind_t
yylhsNonterm (yyRuleNum yyrule)
{
  return YY_CAST (yysymbol_kind_t, yyr1[yyrule]);
}

#if YYDEBUG

# ifndef YYFPRINTF
#  define YYFPRINTF fprintf
# endif

# define YY_FPRINTF                             \
  YY_IGNORE_USELESS_CAST_BEGIN YY_FPRINTF_

# define YY_FPRINTF_(Args)                      \
  do {                                          \
    YYFPRINTF Args;                             \
    YY_IGNORE_USELESS_CAST_END                  \
  } while (0)

# define YY_DPRINTF                             \
  YY_IGNORE_USELESS_CAST_BEGIN YY_DPRINTF_

# define YY_DPRINTF_(Args)                      \
  do {                                          \
    if (yydebug)                                \
      YYFPRINTF Args;                           \
    YY_IGNORE_USELESS_CAST_END                  \
  } while (0)





/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                  \
  do {                                                                  \
    if (yydebug)                                                        \
      {                                                                 \
        YY_FPRINTF ((stderr, "%s ", Title));                            \
        yy_symbol_print (stderr, Kind, Value);        \
        YY_FPRINTF ((stderr, "\n"));                                    \
      }                                                                 \
  } while (0)

static inline void
yy_reduce_print (yybool yynormal, yyGLRStackItem* yyvsp, YYPTRDIFF_T yyk,
                 yyRuleNum yyrule);

# define YY_REDUCE_PRINT(Args)          \
  do {                                  \
    if (yydebug)                        \
      yy_reduce_print Args;             \
  } while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;

static void yypstack (yyGLRStack* yystackp, YYPTRDIFF_T yyk)
  YY_ATTRIBUTE_UNUSED;
static void yypdumpstack (yyGLRStack* yystackp)
  YY_ATTRIBUTE_UNUSED;

#else /* !YYDEBUG */

# define YY_DPRINTF(Args) do {} while (yyfalse)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_REDUCE_PRINT(Args)

#endif /* !YYDEBUG */

#ifndef yystrlen
# define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


/** Fill in YYVSP[YYLOW1 .. YYLOW0-1] from the chain of states starting
 *  at YYVSP[YYLOW0].yystate.yypred.  Leaves YYVSP[YYLOW1].yystate.yypred
 *  containing the pointer to the next state in the chain.  */
static void yyfillin (yyGLRStackItem *, int, int) YY_ATTRIBUTE_UNUSED;
static void
yyfillin (yyGLRStackItem *yyvsp, int yylow0, int yylow1)
{
  int i;
  yyGLRState *s = yyvsp[yylow0].yystate.yypred;
  for (i = yylow0-1; i >= yylow1; i -= 1)
    {
#if YYDEBUG
      yyvsp[i].yystate.yylrState = s->yylrState;
#endif
      yyvsp[i].yystate.yyresolved = s->yyresolved;
      if (s->yyresolved)
        yyvsp[i].yystate.yysemantics.yyval = s->yysemantics.yyval;
      else
        /* The effect of using yyval or yyloc (in an immediate rule) is
         * undefined.  */
        yyvsp[i].yystate.yysemantics.yyfirstVal = YY_NULLPTR;
      s = yyvsp[i].yystate.yypred = s->yypred;
    }
}


/** If yychar is empty, fetch the next token.  */
static inline yysymbol_kind_t
yygetToken (int *yycharp)
{
  yysymbol_kind_t yytoken;
  if (*yycharp == YYEMPTY)
    {
      YY_DPRINTF ((stderr, "Reading a token\n"));
      *yycharp = yylex ();
    }
  if (*yycharp <= YYEOF)
    {
      *yycharp = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YY_DPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (*yycharp);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }
  return yytoken;
}

/* Do nothing if YYNORMAL or if *YYLOW <= YYLOW1.  Otherwise, fill in
 * YYVSP[YYLOW1 .. *YYLOW-1] as in yyfillin and set *YYLOW = YYLOW1.
 * For convenience, always return YYLOW1.  */
static inline int yyfill (yyGLRStackItem *, int *, int, yybool)
     YY_ATTRIBUTE_UNUSED;
static inline int
yyfill (yyGLRStackItem *yyvsp, int *yylow, int yylow1, yybool yynormal)
{
  if (!yynormal && yylow1 < *yylow)
    {
      yyfillin (yyvsp, *yylow, yylow1);
      *yylow = yylow1;
    }
  return yylow1;
}

/** Perform user action for rule number YYN, with RHS length YYRHSLEN,
 *  and top stack item YYVSP.  YYLVALP points to place to put semantic
 *  value ($$), and yylocp points to place for location information
 *  (@$).  Returns yyok for normal return, yyaccept for YYACCEPT,
 *  yyerr for YYERROR, yyabort for YYABORT, yynomem for YYNOMEM.  */
static YYRESULTTAG
yyuserAction (yyRuleNum yyrule, int yyrhslen, yyGLRStackItem* yyvsp,
              yyGLRStack* yystackp, YYPTRDIFF_T yyk,
              YYSTYPE* yyvalp)
{
  const yybool yynormal YY_ATTRIBUTE_UNUSED = yystackp->yysplitPoint == YY_NULLPTR;
  int yylow = 1;
  YY_USE (yyvalp);
  YY_USE (yyk);
  YY_USE (yyrhslen);
# undef yyerrok
# define yyerrok (yystackp->yyerrState = 0)
# undef YYACCEPT
# define YYACCEPT return yyaccept
# undef YYABORT
# define YYABORT return yyabort
# undef YYNOMEM
# define YYNOMEM return yynomem
# undef YYERROR
# define YYERROR return yyerrok, yyerr
# undef YYRECOVERING
# define YYRECOVERING() (yystackp->yyerrState != 0)
# undef yyclearin
# define yyclearin (yychar = YYEMPTY)
# undef YYFILL
# define YYFILL(N) yyfill (yyvsp, &yylow, (N), yynormal)
# undef YYBACKUP
# define YYBACKUP(Token, Value)                                              \
  return yyerror (YY_("syntax error: cannot back up")),     \
         yyerrok, yyerr

  if (yyrhslen == 0)
    *yyvalp = yyval_default;
  else
    *yyvalp = yyvsp[YYFILL (1-yyrhslen)].yystate.yysemantics.yyval;
  /* If yyk == -1, we are running a deferred action on a temporary
     stack.  In that case, YY_REDUCE_PRINT must not play with YYFILL,
     so pretend the stack is "normal". */
  YY_REDUCE_PRINT ((yynormal || yyk == -1, yyvsp, yyk, yyrule));
  switch (yyrule)
    {
  case 2: /* program: deamerreserved_star__stmt__ opt_pad  */
#line 235 "./dregx_parser.y"
                                             {
		auto* const newNode = new dregx::ast::node::program({::dregx::ast::Type::program, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.dregx_deamerreserved_star__stmt__), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.dregx_opt_pad) });
		((*yyvalp).dregx_program) = newNode;

		// Ignored, Deleted, tokens are deleted
		outputTree = new ::deamer::external::cpp::ast::Tree(newNode);
	}
#line 1356 "dregx_parser.tab.c"
    break;

  case 3: /* deamerreserved_star__stmt__: stmt deamerreserved_star__stmt__  */
#line 246 "./dregx_parser.y"
                                          {
		auto* const newNode = new dregx::ast::node::deamerreserved_star__stmt__({::dregx::ast::Type::deamerreserved_star__stmt__, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, { (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.dregx_stmt), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.dregx_deamerreserved_star__stmt__) });
		((*yyvalp).dregx_deamerreserved_star__stmt__) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 1367 "dregx_parser.tab.c"
    break;

  case 4: /* deamerreserved_star__stmt__: %empty  */
#line 252 "./dregx_parser.y"
           {
		auto* const newNode = new dregx::ast::node::deamerreserved_star__stmt__({::dregx::ast::Type::deamerreserved_star__stmt__, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, {  });
		((*yyvalp).dregx_deamerreserved_star__stmt__) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 1378 "dregx_parser.tab.c"
    break;

  case 5: /* stmt: word  */
#line 262 "./dregx_parser.y"
              {
		auto* const newNode = new dregx::ast::node::stmt({::dregx::ast::Type::stmt, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.dregx_word) });
		((*yyvalp).dregx_stmt) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 1389 "dregx_parser.tab.c"
    break;

  case 6: /* word: group  */
#line 272 "./dregx_parser.y"
               {
		auto* const newNode = new dregx::ast::node::word({::dregx::ast::Type::word, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.dregx_group) });
		((*yyvalp).dregx_word) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 1400 "dregx_parser.tab.c"
    break;

  case 7: /* word: square  */
#line 278 "./dregx_parser.y"
                  {
		auto* const newNode = new dregx::ast::node::word({::dregx::ast::Type::word, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.dregx_square) });
		((*yyvalp).dregx_word) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 1411 "dregx_parser.tab.c"
    break;

  case 8: /* word: standalone  */
#line 284 "./dregx_parser.y"
                      {
		auto* const newNode = new dregx::ast::node::word({::dregx::ast::Type::word, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 2, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.dregx_standalone) });
		((*yyvalp).dregx_word) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 1422 "dregx_parser.tab.c"
    break;

  case 9: /* group: opt_pad LEFT_CURLY_BRACKET or_concat opt_pad RIGHT_CURLY_BRACKET OPTIONAL  */
#line 294 "./dregx_parser.y"
                                                                                   {
		auto* const newNode = new dregx::ast::node::group({::dregx::ast::Type::group, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.dregx_opt_pad), new dregx::ast::node::LEFT_CURLY_BRACKET({::dregx::ast::Type::LEFT_CURLY_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Terminal) }), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.dregx_or_concat), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.dregx_opt_pad), new dregx::ast::node::RIGHT_CURLY_BRACKET({::dregx::ast::Type::RIGHT_CURLY_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Terminal) }), new dregx::ast::node::OPTIONAL({::dregx::ast::Type::OPTIONAL, ::deamer::external::cpp::ast::NodeValue::terminal, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Terminal) }) });
		((*yyvalp).dregx_group) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 1433 "dregx_parser.tab.c"
    break;

  case 10: /* group: opt_pad LEFT_CURLY_BRACKET or_concat opt_pad RIGHT_CURLY_BRACKET STAR  */
#line 300 "./dregx_parser.y"
                                                                                 {
		auto* const newNode = new dregx::ast::node::group({::dregx::ast::Type::group, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.dregx_opt_pad), new dregx::ast::node::LEFT_CURLY_BRACKET({::dregx::ast::Type::LEFT_CURLY_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Terminal) }), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.dregx_or_concat), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.dregx_opt_pad), new dregx::ast::node::RIGHT_CURLY_BRACKET({::dregx::ast::Type::RIGHT_CURLY_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Terminal) }), new dregx::ast::node::STAR({::dregx::ast::Type::STAR, ::deamer::external::cpp::ast::NodeValue::terminal, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Terminal) }) });
		((*yyvalp).dregx_group) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 1444 "dregx_parser.tab.c"
    break;

  case 11: /* group: opt_pad LEFT_CURLY_BRACKET or_concat opt_pad RIGHT_CURLY_BRACKET PLUS  */
#line 306 "./dregx_parser.y"
                                                                                 {
		auto* const newNode = new dregx::ast::node::group({::dregx::ast::Type::group, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 2, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.dregx_opt_pad), new dregx::ast::node::LEFT_CURLY_BRACKET({::dregx::ast::Type::LEFT_CURLY_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Terminal) }), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.dregx_or_concat), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.dregx_opt_pad), new dregx::ast::node::RIGHT_CURLY_BRACKET({::dregx::ast::Type::RIGHT_CURLY_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Terminal) }), new dregx::ast::node::PLUS({::dregx::ast::Type::PLUS, ::deamer::external::cpp::ast::NodeValue::terminal, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Terminal) }) });
		((*yyvalp).dregx_group) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 1455 "dregx_parser.tab.c"
    break;

  case 12: /* group: opt_pad LEFT_CURLY_BRACKET or_concat opt_pad RIGHT_CURLY_BRACKET extension_modifier  */
#line 312 "./dregx_parser.y"
                                                                                               {
		auto* const newNode = new dregx::ast::node::group({::dregx::ast::Type::group, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 3, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.dregx_opt_pad), new dregx::ast::node::LEFT_CURLY_BRACKET({::dregx::ast::Type::LEFT_CURLY_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Terminal) }), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.dregx_or_concat), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.dregx_opt_pad), new dregx::ast::node::RIGHT_CURLY_BRACKET({::dregx::ast::Type::RIGHT_CURLY_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Terminal) }), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.dregx_extension_modifier) });
		((*yyvalp).dregx_group) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 1466 "dregx_parser.tab.c"
    break;

  case 13: /* group: opt_pad LEFT_CURLY_BRACKET or_concat opt_pad RIGHT_CURLY_BRACKET  */
#line 318 "./dregx_parser.y"
                                                                            {
		auto* const newNode = new dregx::ast::node::group({::dregx::ast::Type::group, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 4, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.dregx_opt_pad), new dregx::ast::node::LEFT_CURLY_BRACKET({::dregx::ast::Type::LEFT_CURLY_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Terminal) }), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.dregx_or_concat), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.dregx_opt_pad), new dregx::ast::node::RIGHT_CURLY_BRACKET({::dregx::ast::Type::RIGHT_CURLY_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Terminal) }) });
		((*yyvalp).dregx_group) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 1477 "dregx_parser.tab.c"
    break;

  case 14: /* group: opt_pad LEFT_CURLY_BRACKET deamerreserved_plus__word__ opt_pad RIGHT_CURLY_BRACKET OPTIONAL  */
#line 324 "./dregx_parser.y"
                                                                                                       {
		auto* const newNode = new dregx::ast::node::group({::dregx::ast::Type::group, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 5, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.dregx_opt_pad), new dregx::ast::node::LEFT_CURLY_BRACKET({::dregx::ast::Type::LEFT_CURLY_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Terminal) }), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.dregx_deamerreserved_plus__word__), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.dregx_opt_pad), new dregx::ast::node::RIGHT_CURLY_BRACKET({::dregx::ast::Type::RIGHT_CURLY_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Terminal) }), new dregx::ast::node::OPTIONAL({::dregx::ast::Type::OPTIONAL, ::deamer::external::cpp::ast::NodeValue::terminal, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Terminal) }) });
		((*yyvalp).dregx_group) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 1488 "dregx_parser.tab.c"
    break;

  case 15: /* group: opt_pad LEFT_CURLY_BRACKET deamerreserved_plus__word__ opt_pad RIGHT_CURLY_BRACKET STAR  */
#line 330 "./dregx_parser.y"
                                                                                                   {
		auto* const newNode = new dregx::ast::node::group({::dregx::ast::Type::group, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 6, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.dregx_opt_pad), new dregx::ast::node::LEFT_CURLY_BRACKET({::dregx::ast::Type::LEFT_CURLY_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Terminal) }), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.dregx_deamerreserved_plus__word__), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.dregx_opt_pad), new dregx::ast::node::RIGHT_CURLY_BRACKET({::dregx::ast::Type::RIGHT_CURLY_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Terminal) }), new dregx::ast::node::STAR({::dregx::ast::Type::STAR, ::deamer::external::cpp::ast::NodeValue::terminal, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Terminal) }) });
		((*yyvalp).dregx_group) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 1499 "dregx_parser.tab.c"
    break;

  case 16: /* group: opt_pad LEFT_CURLY_BRACKET deamerreserved_plus__word__ opt_pad RIGHT_CURLY_BRACKET PLUS  */
#line 336 "./dregx_parser.y"
                                                                                                   {
		auto* const newNode = new dregx::ast::node::group({::dregx::ast::Type::group, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 7, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.dregx_opt_pad), new dregx::ast::node::LEFT_CURLY_BRACKET({::dregx::ast::Type::LEFT_CURLY_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Terminal) }), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.dregx_deamerreserved_plus__word__), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.dregx_opt_pad), new dregx::ast::node::RIGHT_CURLY_BRACKET({::dregx::ast::Type::RIGHT_CURLY_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Terminal) }), new dregx::ast::node::PLUS({::dregx::ast::Type::PLUS, ::deamer::external::cpp::ast::NodeValue::terminal, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Terminal) }) });
		((*yyvalp).dregx_group) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 1510 "dregx_parser.tab.c"
    break;

  case 17: /* group: opt_pad LEFT_CURLY_BRACKET deamerreserved_plus__word__ opt_pad RIGHT_CURLY_BRACKET extension_modifier  */
#line 342 "./dregx_parser.y"
                                                                                                                 {
		auto* const newNode = new dregx::ast::node::group({::dregx::ast::Type::group, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 8, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.dregx_opt_pad), new dregx::ast::node::LEFT_CURLY_BRACKET({::dregx::ast::Type::LEFT_CURLY_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.Terminal) }), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.dregx_deamerreserved_plus__word__), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.dregx_opt_pad), new dregx::ast::node::RIGHT_CURLY_BRACKET({::dregx::ast::Type::RIGHT_CURLY_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Terminal) }), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.dregx_extension_modifier) });
		((*yyvalp).dregx_group) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 1521 "dregx_parser.tab.c"
    break;

  case 18: /* group: opt_pad LEFT_CURLY_BRACKET deamerreserved_plus__word__ opt_pad RIGHT_CURLY_BRACKET  */
#line 348 "./dregx_parser.y"
                                                                                              {
		auto* const newNode = new dregx::ast::node::group({::dregx::ast::Type::group, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 9, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.dregx_opt_pad), new dregx::ast::node::LEFT_CURLY_BRACKET({::dregx::ast::Type::LEFT_CURLY_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Terminal) }), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.dregx_deamerreserved_plus__word__), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.dregx_opt_pad), new dregx::ast::node::RIGHT_CURLY_BRACKET({::dregx::ast::Type::RIGHT_CURLY_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Terminal) }) });
		((*yyvalp).dregx_group) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 1532 "dregx_parser.tab.c"
    break;

  case 19: /* deamerreserved_plus__word__: word  */
#line 358 "./dregx_parser.y"
              {
		auto* const newNode = new dregx::ast::node::deamerreserved_plus__word__({::dregx::ast::Type::deamerreserved_plus__word__, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, { (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.dregx_word) });
		((*yyvalp).dregx_deamerreserved_plus__word__) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 1543 "dregx_parser.tab.c"
    break;

  case 20: /* deamerreserved_plus__word__: word deamerreserved_plus__word__  */
#line 364 "./dregx_parser.y"
                                            {
		auto* const newNode = new dregx::ast::node::deamerreserved_plus__word__({::dregx::ast::Type::deamerreserved_plus__word__, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, { (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.dregx_word), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.dregx_deamerreserved_plus__word__) });
		((*yyvalp).dregx_deamerreserved_plus__word__) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 1554 "dregx_parser.tab.c"
    break;

  case 21: /* or_concat: word opt_pad OR deamerreserved_arrow__word__  */
#line 374 "./dregx_parser.y"
                                                      {
		auto* const newNode = new dregx::ast::node::or_concat({::dregx::ast::Type::or_concat, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.dregx_word), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.dregx_opt_pad), new dregx::ast::node::OR({::dregx::ast::Type::OR, ::deamer::external::cpp::ast::NodeValue::terminal, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Terminal) }), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.dregx_deamerreserved_arrow__word__) });
		((*yyvalp).dregx_or_concat) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 1565 "dregx_parser.tab.c"
    break;

  case 22: /* deamerreserved_arrow__word__: word deamerreserved_star__opt_pad__OR__word__  */
#line 384 "./dregx_parser.y"
                                                       {
		auto* const newNode = new dregx::ast::node::deamerreserved_arrow__word__({::dregx::ast::Type::deamerreserved_arrow__word__, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, { (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.dregx_word), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.dregx_deamerreserved_star__opt_pad__OR__word__) });
		((*yyvalp).dregx_deamerreserved_arrow__word__) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 1576 "dregx_parser.tab.c"
    break;

  case 23: /* deamerreserved_star__opt_pad__OR__word__: opt_pad OR word deamerreserved_star__opt_pad__OR__word__  */
#line 394 "./dregx_parser.y"
                                                                  {
		auto* const newNode = new dregx::ast::node::deamerreserved_star__opt_pad__OR__word__({::dregx::ast::Type::deamerreserved_star__opt_pad__OR__word__, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, { (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.dregx_opt_pad), new dregx::ast::node::OR({::dregx::ast::Type::OR, ::deamer::external::cpp::ast::NodeValue::terminal, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Terminal) }), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.dregx_word), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.dregx_deamerreserved_star__opt_pad__OR__word__) });
		((*yyvalp).dregx_deamerreserved_star__opt_pad__OR__word__) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 1587 "dregx_parser.tab.c"
    break;

  case 24: /* deamerreserved_star__opt_pad__OR__word__: %empty  */
#line 400 "./dregx_parser.y"
           {
		auto* const newNode = new dregx::ast::node::deamerreserved_star__opt_pad__OR__word__({::dregx::ast::Type::deamerreserved_star__opt_pad__OR__word__, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, {  });
		((*yyvalp).dregx_deamerreserved_star__opt_pad__OR__word__) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 1598 "dregx_parser.tab.c"
    break;

  case 25: /* square: capture extension_modifier  */
#line 410 "./dregx_parser.y"
                                    {
		auto* const newNode = new dregx::ast::node::square({::dregx::ast::Type::square, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.dregx_capture), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.dregx_extension_modifier) });
		((*yyvalp).dregx_square) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 1609 "dregx_parser.tab.c"
    break;

  case 26: /* square: capture PLUS  */
#line 416 "./dregx_parser.y"
                        {
		auto* const newNode = new dregx::ast::node::square({::dregx::ast::Type::square, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.dregx_capture), new dregx::ast::node::PLUS({::dregx::ast::Type::PLUS, ::deamer::external::cpp::ast::NodeValue::terminal, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Terminal) }) });
		((*yyvalp).dregx_square) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 1620 "dregx_parser.tab.c"
    break;

  case 27: /* square: capture STAR  */
#line 422 "./dregx_parser.y"
                        {
		auto* const newNode = new dregx::ast::node::square({::dregx::ast::Type::square, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 2, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.dregx_capture), new dregx::ast::node::STAR({::dregx::ast::Type::STAR, ::deamer::external::cpp::ast::NodeValue::terminal, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Terminal) }) });
		((*yyvalp).dregx_square) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 1631 "dregx_parser.tab.c"
    break;

  case 28: /* square: capture OPTIONAL  */
#line 428 "./dregx_parser.y"
                            {
		auto* const newNode = new dregx::ast::node::square({::dregx::ast::Type::square, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 3, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.dregx_capture), new dregx::ast::node::OPTIONAL({::dregx::ast::Type::OPTIONAL, ::deamer::external::cpp::ast::NodeValue::terminal, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Terminal) }) });
		((*yyvalp).dregx_square) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 1642 "dregx_parser.tab.c"
    break;

  case 29: /* square: capture  */
#line 434 "./dregx_parser.y"
                   {
		auto* const newNode = new dregx::ast::node::square({::dregx::ast::Type::square, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 4, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.dregx_capture) });
		((*yyvalp).dregx_square) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 1653 "dregx_parser.tab.c"
    break;

  case 30: /* capture: opt_pad LEFT_SQUARE_BRACKET_NOT deamerreserved_plus__capture_logic__ RIGHT_SQUARE_BRACKET  */
#line 444 "./dregx_parser.y"
                                                                                                   {
		auto* const newNode = new dregx::ast::node::capture({::dregx::ast::Type::capture, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.dregx_opt_pad), new dregx::ast::node::LEFT_SQUARE_BRACKET_NOT({::dregx::ast::Type::LEFT_SQUARE_BRACKET_NOT, ::deamer::external::cpp::ast::NodeValue::terminal, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Terminal) }), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.dregx_deamerreserved_plus__capture_logic__), new dregx::ast::node::RIGHT_SQUARE_BRACKET({::dregx::ast::Type::RIGHT_SQUARE_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Terminal) }) });
		((*yyvalp).dregx_capture) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 1664 "dregx_parser.tab.c"
    break;

  case 31: /* capture: opt_pad LEFT_SQUARE_BRACKET deamerreserved_plus__capture_logic__ RIGHT_SQUARE_BRACKET  */
#line 450 "./dregx_parser.y"
                                                                                                 {
		auto* const newNode = new dregx::ast::node::capture({::dregx::ast::Type::capture, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.dregx_opt_pad), new dregx::ast::node::LEFT_SQUARE_BRACKET({::dregx::ast::Type::LEFT_SQUARE_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Terminal) }), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.dregx_deamerreserved_plus__capture_logic__), new dregx::ast::node::RIGHT_SQUARE_BRACKET({::dregx::ast::Type::RIGHT_SQUARE_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Terminal) }) });
		((*yyvalp).dregx_capture) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 1675 "dregx_parser.tab.c"
    break;

  case 32: /* deamerreserved_plus__capture_logic__: capture_logic  */
#line 460 "./dregx_parser.y"
                       {
		auto* const newNode = new dregx::ast::node::deamerreserved_plus__capture_logic__({::dregx::ast::Type::deamerreserved_plus__capture_logic__, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, { (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.dregx_capture_logic) });
		((*yyvalp).dregx_deamerreserved_plus__capture_logic__) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 1686 "dregx_parser.tab.c"
    break;

  case 33: /* deamerreserved_plus__capture_logic__: capture_logic deamerreserved_plus__capture_logic__  */
#line 466 "./dregx_parser.y"
                                                              {
		auto* const newNode = new dregx::ast::node::deamerreserved_plus__capture_logic__({::dregx::ast::Type::deamerreserved_plus__capture_logic__, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, { (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.dregx_capture_logic), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.dregx_deamerreserved_plus__capture_logic__) });
		((*yyvalp).dregx_deamerreserved_plus__capture_logic__) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 1697 "dregx_parser.tab.c"
    break;

  case 34: /* capture_logic: capture_range  */
#line 476 "./dregx_parser.y"
                       {
		auto* const newNode = new dregx::ast::node::capture_logic({::dregx::ast::Type::capture_logic, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.dregx_capture_range) });
		((*yyvalp).dregx_capture_logic) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 1708 "dregx_parser.tab.c"
    break;

  case 35: /* capture_logic: capture_special_character  */
#line 482 "./dregx_parser.y"
                                     {
		auto* const newNode = new dregx::ast::node::capture_logic({::dregx::ast::Type::capture_logic, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.dregx_capture_special_character) });
		((*yyvalp).dregx_capture_logic) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 1719 "dregx_parser.tab.c"
    break;

  case 36: /* capture_logic: capture_letter  */
#line 488 "./dregx_parser.y"
                          {
		auto* const newNode = new dregx::ast::node::capture_logic({::dregx::ast::Type::capture_logic, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 2, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.dregx_capture_letter) });
		((*yyvalp).dregx_capture_logic) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 1730 "dregx_parser.tab.c"
    break;

  case 37: /* capture_logic: capture_number  */
#line 494 "./dregx_parser.y"
                          {
		auto* const newNode = new dregx::ast::node::capture_logic({::dregx::ast::Type::capture_logic, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 3, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.dregx_capture_number) });
		((*yyvalp).dregx_capture_logic) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 1741 "dregx_parser.tab.c"
    break;

  case 38: /* capture_logic: capture_whitespace  */
#line 500 "./dregx_parser.y"
                              {
		auto* const newNode = new dregx::ast::node::capture_logic({::dregx::ast::Type::capture_logic, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 4, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.dregx_capture_whitespace) });
		((*yyvalp).dregx_capture_logic) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 1752 "dregx_parser.tab.c"
    break;

  case 39: /* capture_logic: capture_symbols  */
#line 506 "./dregx_parser.y"
                           {
		auto* const newNode = new dregx::ast::node::capture_logic({::dregx::ast::Type::capture_logic, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 5, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.dregx_capture_symbols) });
		((*yyvalp).dregx_capture_logic) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 1763 "dregx_parser.tab.c"
    break;

  case 40: /* capture_symbols: OTHER  */
#line 516 "./dregx_parser.y"
               {
		auto* const newNode = new dregx::ast::node::capture_symbols({::dregx::ast::Type::capture_symbols, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::OTHER({::dregx::ast::Type::OTHER, ::deamer::external::cpp::ast::NodeValue::terminal, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Terminal) }) });
		((*yyvalp).dregx_capture_symbols) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 1774 "dregx_parser.tab.c"
    break;

  case 41: /* capture_symbols: PLUS  */
#line 522 "./dregx_parser.y"
                {
		auto* const newNode = new dregx::ast::node::capture_symbols({::dregx::ast::Type::capture_symbols, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::PLUS({::dregx::ast::Type::PLUS, ::deamer::external::cpp::ast::NodeValue::terminal, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Terminal) }) });
		((*yyvalp).dregx_capture_symbols) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 1785 "dregx_parser.tab.c"
    break;

  case 42: /* capture_symbols: STAR  */
#line 528 "./dregx_parser.y"
                {
		auto* const newNode = new dregx::ast::node::capture_symbols({::dregx::ast::Type::capture_symbols, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 2, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::STAR({::dregx::ast::Type::STAR, ::deamer::external::cpp::ast::NodeValue::terminal, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Terminal) }) });
		((*yyvalp).dregx_capture_symbols) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 1796 "dregx_parser.tab.c"
    break;

  case 43: /* capture_symbols: COMMA  */
#line 534 "./dregx_parser.y"
                 {
		auto* const newNode = new dregx::ast::node::capture_symbols({::dregx::ast::Type::capture_symbols, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 3, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::COMMA({::dregx::ast::Type::COMMA, ::deamer::external::cpp::ast::NodeValue::terminal, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Terminal) }) });
		((*yyvalp).dregx_capture_symbols) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 1807 "dregx_parser.tab.c"
    break;

  case 44: /* capture_symbols: OR  */
#line 540 "./dregx_parser.y"
              {
		auto* const newNode = new dregx::ast::node::capture_symbols({::dregx::ast::Type::capture_symbols, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 4, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::OR({::dregx::ast::Type::OR, ::deamer::external::cpp::ast::NodeValue::terminal, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Terminal) }) });
		((*yyvalp).dregx_capture_symbols) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 1818 "dregx_parser.tab.c"
    break;

  case 45: /* capture_symbols: OPTIONAL  */
#line 546 "./dregx_parser.y"
                    {
		auto* const newNode = new dregx::ast::node::capture_symbols({::dregx::ast::Type::capture_symbols, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 5, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::OPTIONAL({::dregx::ast::Type::OPTIONAL, ::deamer::external::cpp::ast::NodeValue::terminal, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Terminal) }) });
		((*yyvalp).dregx_capture_symbols) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 1829 "dregx_parser.tab.c"
    break;

  case 46: /* capture_whitespace: SPACE  */
#line 556 "./dregx_parser.y"
               {
		auto* const newNode = new dregx::ast::node::capture_whitespace({::dregx::ast::Type::capture_whitespace, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::SPACE({::dregx::ast::Type::SPACE, ::deamer::external::cpp::ast::NodeValue::terminal, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Terminal) }) });
		((*yyvalp).dregx_capture_whitespace) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 1840 "dregx_parser.tab.c"
    break;

  case 47: /* capture_whitespace: TAB  */
#line 562 "./dregx_parser.y"
               {
		auto* const newNode = new dregx::ast::node::capture_whitespace({::dregx::ast::Type::capture_whitespace, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::TAB({::dregx::ast::Type::TAB, ::deamer::external::cpp::ast::NodeValue::terminal, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Terminal) }) });
		((*yyvalp).dregx_capture_whitespace) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 1851 "dregx_parser.tab.c"
    break;

  case 48: /* capture_range: capture_letter_range  */
#line 572 "./dregx_parser.y"
                              {
		auto* const newNode = new dregx::ast::node::capture_range({::dregx::ast::Type::capture_range, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.dregx_capture_letter_range) });
		((*yyvalp).dregx_capture_range) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 1862 "dregx_parser.tab.c"
    break;

  case 49: /* capture_range: capture_number_range  */
#line 578 "./dregx_parser.y"
                                {
		auto* const newNode = new dregx::ast::node::capture_range({::dregx::ast::Type::capture_range, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.dregx_capture_number_range) });
		((*yyvalp).dregx_capture_range) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 1873 "dregx_parser.tab.c"
    break;

  case 50: /* capture_letter_range: any_letter_exclude_underscore MIN any_letter_exclude_underscore  */
#line 588 "./dregx_parser.y"
                                                                         {
		auto* const newNode = new dregx::ast::node::capture_letter_range({::dregx::ast::Type::capture_letter_range, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.dregx_any_letter_exclude_underscore), new dregx::ast::node::MIN({::dregx::ast::Type::MIN, ::deamer::external::cpp::ast::NodeValue::terminal, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Terminal) }), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.dregx_any_letter_exclude_underscore) });
		((*yyvalp).dregx_capture_letter_range) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 1884 "dregx_parser.tab.c"
    break;

  case 51: /* capture_number_range: NUMBER MIN NUMBER  */
#line 598 "./dregx_parser.y"
                           {
		auto* const newNode = new dregx::ast::node::capture_number_range({::dregx::ast::Type::capture_number_range, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::NUMBER({::dregx::ast::Type::NUMBER, ::deamer::external::cpp::ast::NodeValue::terminal, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.Terminal) }), new dregx::ast::node::MIN({::dregx::ast::Type::MIN, ::deamer::external::cpp::ast::NodeValue::terminal, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Terminal) }), new dregx::ast::node::NUMBER({::dregx::ast::Type::NUMBER, ::deamer::external::cpp::ast::NodeValue::terminal, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Terminal) }) });
		((*yyvalp).dregx_capture_number_range) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 1895 "dregx_parser.tab.c"
    break;

  case 52: /* capture_number: any_number  */
#line 608 "./dregx_parser.y"
                    {
		auto* const newNode = new dregx::ast::node::capture_number({::dregx::ast::Type::capture_number, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.dregx_any_number) });
		((*yyvalp).dregx_capture_number) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 1906 "dregx_parser.tab.c"
    break;

  case 53: /* capture_letter: any_letter  */
#line 618 "./dregx_parser.y"
                    {
		auto* const newNode = new dregx::ast::node::capture_letter({::dregx::ast::Type::capture_letter, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.dregx_any_letter) });
		((*yyvalp).dregx_capture_letter) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 1917 "dregx_parser.tab.c"
    break;

  case 54: /* capture_special_character: special_char_any  */
#line 628 "./dregx_parser.y"
                          {
		auto* const newNode = new dregx::ast::node::capture_special_character({::dregx::ast::Type::capture_special_character, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.dregx_special_char_any) });
		((*yyvalp).dregx_capture_special_character) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 1928 "dregx_parser.tab.c"
    break;

  case 55: /* extension_modifier: opt_pad LEFT_BRACKET min_repition opt_pad COMMA max_repition opt_pad RIGHT_BRACKET  */
#line 638 "./dregx_parser.y"
                                                                                            {
		auto* const newNode = new dregx::ast::node::extension_modifier({::dregx::ast::Type::extension_modifier, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-7)].yystate.yysemantics.yyval.dregx_opt_pad), new dregx::ast::node::LEFT_BRACKET({::dregx::ast::Type::LEFT_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-6)].yystate.yysemantics.yyval.Terminal) }), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.dregx_min_repition), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.dregx_opt_pad), new dregx::ast::node::COMMA({::dregx::ast::Type::COMMA, ::deamer::external::cpp::ast::NodeValue::terminal, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.Terminal) }), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.dregx_max_repition), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.dregx_opt_pad), new dregx::ast::node::RIGHT_BRACKET({::dregx::ast::Type::RIGHT_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Terminal) }) });
		((*yyvalp).dregx_extension_modifier) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 1939 "dregx_parser.tab.c"
    break;

  case 56: /* min_repition: opt_pad deamerreserved_plus__NUMBER__  */
#line 648 "./dregx_parser.y"
                                               {
		auto* const newNode = new dregx::ast::node::min_repition({::dregx::ast::Type::min_repition, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.dregx_opt_pad), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.dregx_deamerreserved_plus__NUMBER__) });
		((*yyvalp).dregx_min_repition) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 1950 "dregx_parser.tab.c"
    break;

  case 57: /* deamerreserved_plus__NUMBER__: NUMBER  */
#line 658 "./dregx_parser.y"
                {
		auto* const newNode = new dregx::ast::node::deamerreserved_plus__NUMBER__({::dregx::ast::Type::deamerreserved_plus__NUMBER__, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, { new dregx::ast::node::NUMBER({::dregx::ast::Type::NUMBER, ::deamer::external::cpp::ast::NodeValue::terminal, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Terminal) }) });
		((*yyvalp).dregx_deamerreserved_plus__NUMBER__) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 1961 "dregx_parser.tab.c"
    break;

  case 58: /* deamerreserved_plus__NUMBER__: NUMBER deamerreserved_plus__NUMBER__  */
#line 664 "./dregx_parser.y"
                                                {
		auto* const newNode = new dregx::ast::node::deamerreserved_plus__NUMBER__({::dregx::ast::Type::deamerreserved_plus__NUMBER__, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, { new dregx::ast::node::NUMBER({::dregx::ast::Type::NUMBER, ::deamer::external::cpp::ast::NodeValue::terminal, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Terminal) }), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.dregx_deamerreserved_plus__NUMBER__) });
		((*yyvalp).dregx_deamerreserved_plus__NUMBER__) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 1972 "dregx_parser.tab.c"
    break;

  case 59: /* max_repition: opt_pad deamerreserved_plus__NUMBER__  */
#line 674 "./dregx_parser.y"
                                               {
		auto* const newNode = new dregx::ast::node::max_repition({::dregx::ast::Type::max_repition, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.dregx_opt_pad), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.dregx_deamerreserved_plus__NUMBER__) });
		((*yyvalp).dregx_max_repition) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 1983 "dregx_parser.tab.c"
    break;

  case 60: /* standalone: opt_pad any_letter  */
#line 684 "./dregx_parser.y"
                            {
		auto* const newNode = new dregx::ast::node::standalone({::dregx::ast::Type::standalone, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.dregx_opt_pad), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.dregx_any_letter) });
		((*yyvalp).dregx_standalone) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 1994 "dregx_parser.tab.c"
    break;

  case 61: /* standalone: opt_pad any_number  */
#line 690 "./dregx_parser.y"
                              {
		auto* const newNode = new dregx::ast::node::standalone({::dregx::ast::Type::standalone, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.dregx_opt_pad), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.dregx_any_number) });
		((*yyvalp).dregx_standalone) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2005 "dregx_parser.tab.c"
    break;

  case 62: /* opt_pad: optional_padding  */
#line 700 "./dregx_parser.y"
                          {
		auto* const newNode = new dregx::ast::node::opt_pad({::dregx::ast::Type::opt_pad, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.dregx_optional_padding) });
		((*yyvalp).dregx_opt_pad) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2016 "dregx_parser.tab.c"
    break;

  case 63: /* optional_padding: deamerreserved_star__padding__  */
#line 710 "./dregx_parser.y"
                                        {
		auto* const newNode = new dregx::ast::node::optional_padding({::dregx::ast::Type::optional_padding, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.dregx_deamerreserved_star__padding__) });
		((*yyvalp).dregx_optional_padding) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2027 "dregx_parser.tab.c"
    break;

  case 64: /* deamerreserved_star__padding__: padding deamerreserved_star__padding__  */
#line 720 "./dregx_parser.y"
                                                {
		auto* const newNode = new dregx::ast::node::deamerreserved_star__padding__({::dregx::ast::Type::deamerreserved_star__padding__, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, { (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.dregx_padding), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.dregx_deamerreserved_star__padding__) });
		((*yyvalp).dregx_deamerreserved_star__padding__) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2038 "dregx_parser.tab.c"
    break;

  case 65: /* deamerreserved_star__padding__: %empty  */
#line 726 "./dregx_parser.y"
           {
		auto* const newNode = new dregx::ast::node::deamerreserved_star__padding__({::dregx::ast::Type::deamerreserved_star__padding__, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, {  });
		((*yyvalp).dregx_deamerreserved_star__padding__) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2049 "dregx_parser.tab.c"
    break;

  case 66: /* padding: SPACE  */
#line 736 "./dregx_parser.y"
               {
		auto* const newNode = new dregx::ast::node::padding({::dregx::ast::Type::padding, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::SPACE({::dregx::ast::Type::SPACE, ::deamer::external::cpp::ast::NodeValue::terminal, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Terminal) }) });
		((*yyvalp).dregx_padding) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2060 "dregx_parser.tab.c"
    break;

  case 67: /* padding: TAB  */
#line 742 "./dregx_parser.y"
               {
		auto* const newNode = new dregx::ast::node::padding({::dregx::ast::Type::padding, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::TAB({::dregx::ast::Type::TAB, ::deamer::external::cpp::ast::NodeValue::terminal, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Terminal) }) });
		((*yyvalp).dregx_padding) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2071 "dregx_parser.tab.c"
    break;

  case 68: /* special_char_any: SLASH any  */
#line 752 "./dregx_parser.y"
                   {
		auto* const newNode = new dregx::ast::node::special_char_any({::dregx::ast::Type::special_char_any, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::SLASH({::dregx::ast::Type::SLASH, ::deamer::external::cpp::ast::NodeValue::terminal, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.Terminal) }), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.dregx_any) });
		((*yyvalp).dregx_special_char_any) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2082 "dregx_parser.tab.c"
    break;

  case 69: /* any_number: NUMBER  */
#line 762 "./dregx_parser.y"
                {
		auto* const newNode = new dregx::ast::node::any_number({::dregx::ast::Type::any_number, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::NUMBER({::dregx::ast::Type::NUMBER, ::deamer::external::cpp::ast::NodeValue::terminal, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Terminal) }) });
		((*yyvalp).dregx_any_number) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2093 "dregx_parser.tab.c"
    break;

  case 70: /* any_letter: any_letter_exclude_underscore  */
#line 772 "./dregx_parser.y"
                                       {
		auto* const newNode = new dregx::ast::node::any_letter({::dregx::ast::Type::any_letter, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.dregx_any_letter_exclude_underscore) });
		((*yyvalp).dregx_any_letter) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2104 "dregx_parser.tab.c"
    break;

  case 71: /* any_letter: UNDERSCORE  */
#line 778 "./dregx_parser.y"
                      {
		auto* const newNode = new dregx::ast::node::any_letter({::dregx::ast::Type::any_letter, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::UNDERSCORE({::dregx::ast::Type::UNDERSCORE, ::deamer::external::cpp::ast::NodeValue::terminal, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Terminal) }) });
		((*yyvalp).dregx_any_letter) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2115 "dregx_parser.tab.c"
    break;

  case 72: /* any_letter_exclude_underscore: T_  */
#line 788 "./dregx_parser.y"
            {
		auto* const newNode = new dregx::ast::node::any_letter_exclude_underscore({::dregx::ast::Type::any_letter_exclude_underscore, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::T_({::dregx::ast::Type::T_, ::deamer::external::cpp::ast::NodeValue::terminal, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Terminal) }) });
		((*yyvalp).dregx_any_letter_exclude_underscore) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2126 "dregx_parser.tab.c"
    break;

  case 73: /* any_letter_exclude_underscore: R_  */
#line 794 "./dregx_parser.y"
              {
		auto* const newNode = new dregx::ast::node::any_letter_exclude_underscore({::dregx::ast::Type::any_letter_exclude_underscore, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::R_({::dregx::ast::Type::R_, ::deamer::external::cpp::ast::NodeValue::terminal, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Terminal) }) });
		((*yyvalp).dregx_any_letter_exclude_underscore) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2137 "dregx_parser.tab.c"
    break;

  case 74: /* any_letter_exclude_underscore: N_  */
#line 800 "./dregx_parser.y"
              {
		auto* const newNode = new dregx::ast::node::any_letter_exclude_underscore({::dregx::ast::Type::any_letter_exclude_underscore, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 2, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::N_({::dregx::ast::Type::N_, ::deamer::external::cpp::ast::NodeValue::terminal, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Terminal) }) });
		((*yyvalp).dregx_any_letter_exclude_underscore) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2148 "dregx_parser.tab.c"
    break;

  case 75: /* any_letter_exclude_underscore: B_  */
#line 806 "./dregx_parser.y"
              {
		auto* const newNode = new dregx::ast::node::any_letter_exclude_underscore({::dregx::ast::Type::any_letter_exclude_underscore, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 3, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::B_({::dregx::ast::Type::B_, ::deamer::external::cpp::ast::NodeValue::terminal, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Terminal) }) });
		((*yyvalp).dregx_any_letter_exclude_underscore) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2159 "dregx_parser.tab.c"
    break;

  case 76: /* any_letter_exclude_underscore: V_  */
#line 812 "./dregx_parser.y"
              {
		auto* const newNode = new dregx::ast::node::any_letter_exclude_underscore({::dregx::ast::Type::any_letter_exclude_underscore, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 4, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::V_({::dregx::ast::Type::V_, ::deamer::external::cpp::ast::NodeValue::terminal, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Terminal) }) });
		((*yyvalp).dregx_any_letter_exclude_underscore) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2170 "dregx_parser.tab.c"
    break;

  case 77: /* any_letter_exclude_underscore: A_  */
#line 818 "./dregx_parser.y"
              {
		auto* const newNode = new dregx::ast::node::any_letter_exclude_underscore({::dregx::ast::Type::any_letter_exclude_underscore, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 5, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::A_({::dregx::ast::Type::A_, ::deamer::external::cpp::ast::NodeValue::terminal, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Terminal) }) });
		((*yyvalp).dregx_any_letter_exclude_underscore) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2181 "dregx_parser.tab.c"
    break;

  case 78: /* any_letter_exclude_underscore: LETTER  */
#line 824 "./dregx_parser.y"
                  {
		auto* const newNode = new dregx::ast::node::any_letter_exclude_underscore({::dregx::ast::Type::any_letter_exclude_underscore, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 6, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::LETTER({::dregx::ast::Type::LETTER, ::deamer::external::cpp::ast::NodeValue::terminal, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Terminal) }) });
		((*yyvalp).dregx_any_letter_exclude_underscore) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2192 "dregx_parser.tab.c"
    break;

  case 79: /* any: LEFT_CURLY_BRACKET  */
#line 834 "./dregx_parser.y"
                            {
		auto* const newNode = new dregx::ast::node::any({::dregx::ast::Type::any, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::LEFT_CURLY_BRACKET({::dregx::ast::Type::LEFT_CURLY_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Terminal) }) });
		((*yyvalp).dregx_any) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2203 "dregx_parser.tab.c"
    break;

  case 80: /* any: RIGHT_CURLY_BRACKET  */
#line 840 "./dregx_parser.y"
                               {
		auto* const newNode = new dregx::ast::node::any({::dregx::ast::Type::any, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::RIGHT_CURLY_BRACKET({::dregx::ast::Type::RIGHT_CURLY_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Terminal) }) });
		((*yyvalp).dregx_any) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2214 "dregx_parser.tab.c"
    break;

  case 81: /* any: LEFT_SQUARE_BRACKET  */
#line 846 "./dregx_parser.y"
                               {
		auto* const newNode = new dregx::ast::node::any({::dregx::ast::Type::any, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 2, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::LEFT_SQUARE_BRACKET({::dregx::ast::Type::LEFT_SQUARE_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Terminal) }) });
		((*yyvalp).dregx_any) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2225 "dregx_parser.tab.c"
    break;

  case 82: /* any: RIGHT_SQUARE_BRACKET  */
#line 852 "./dregx_parser.y"
                                {
		auto* const newNode = new dregx::ast::node::any({::dregx::ast::Type::any, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 3, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::RIGHT_SQUARE_BRACKET({::dregx::ast::Type::RIGHT_SQUARE_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Terminal) }) });
		((*yyvalp).dregx_any) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2236 "dregx_parser.tab.c"
    break;

  case 83: /* any: LEFT_BRACKET  */
#line 858 "./dregx_parser.y"
                        {
		auto* const newNode = new dregx::ast::node::any({::dregx::ast::Type::any, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 4, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::LEFT_BRACKET({::dregx::ast::Type::LEFT_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Terminal) }) });
		((*yyvalp).dregx_any) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2247 "dregx_parser.tab.c"
    break;

  case 84: /* any: RIGHT_BRACKET  */
#line 864 "./dregx_parser.y"
                         {
		auto* const newNode = new dregx::ast::node::any({::dregx::ast::Type::any, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 5, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::RIGHT_BRACKET({::dregx::ast::Type::RIGHT_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Terminal) }) });
		((*yyvalp).dregx_any) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2258 "dregx_parser.tab.c"
    break;

  case 85: /* any: COMMA  */
#line 870 "./dregx_parser.y"
                 {
		auto* const newNode = new dregx::ast::node::any({::dregx::ast::Type::any, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 6, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::COMMA({::dregx::ast::Type::COMMA, ::deamer::external::cpp::ast::NodeValue::terminal, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Terminal) }) });
		((*yyvalp).dregx_any) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2269 "dregx_parser.tab.c"
    break;

  case 86: /* any: OR  */
#line 876 "./dregx_parser.y"
              {
		auto* const newNode = new dregx::ast::node::any({::dregx::ast::Type::any, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 7, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::OR({::dregx::ast::Type::OR, ::deamer::external::cpp::ast::NodeValue::terminal, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Terminal) }) });
		((*yyvalp).dregx_any) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2280 "dregx_parser.tab.c"
    break;

  case 87: /* any: MIN  */
#line 882 "./dregx_parser.y"
               {
		auto* const newNode = new dregx::ast::node::any({::dregx::ast::Type::any, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 8, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::MIN({::dregx::ast::Type::MIN, ::deamer::external::cpp::ast::NodeValue::terminal, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Terminal) }) });
		((*yyvalp).dregx_any) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2291 "dregx_parser.tab.c"
    break;

  case 88: /* any: OPTIONAL  */
#line 888 "./dregx_parser.y"
                    {
		auto* const newNode = new dregx::ast::node::any({::dregx::ast::Type::any, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 9, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::OPTIONAL({::dregx::ast::Type::OPTIONAL, ::deamer::external::cpp::ast::NodeValue::terminal, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Terminal) }) });
		((*yyvalp).dregx_any) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2302 "dregx_parser.tab.c"
    break;

  case 89: /* any: UNDERSCORE  */
#line 894 "./dregx_parser.y"
                      {
		auto* const newNode = new dregx::ast::node::any({::dregx::ast::Type::any, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 10, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::UNDERSCORE({::dregx::ast::Type::UNDERSCORE, ::deamer::external::cpp::ast::NodeValue::terminal, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Terminal) }) });
		((*yyvalp).dregx_any) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2313 "dregx_parser.tab.c"
    break;

  case 90: /* any: NOT  */
#line 900 "./dregx_parser.y"
               {
		auto* const newNode = new dregx::ast::node::any({::dregx::ast::Type::any, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 11, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::NOT({::dregx::ast::Type::NOT, ::deamer::external::cpp::ast::NodeValue::terminal, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Terminal) }) });
		((*yyvalp).dregx_any) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2324 "dregx_parser.tab.c"
    break;

  case 91: /* any: NUMBER  */
#line 906 "./dregx_parser.y"
                  {
		auto* const newNode = new dregx::ast::node::any({::dregx::ast::Type::any, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 12, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::NUMBER({::dregx::ast::Type::NUMBER, ::deamer::external::cpp::ast::NodeValue::terminal, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Terminal) }) });
		((*yyvalp).dregx_any) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2335 "dregx_parser.tab.c"
    break;

  case 92: /* any: T_  */
#line 912 "./dregx_parser.y"
              {
		auto* const newNode = new dregx::ast::node::any({::dregx::ast::Type::any, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 13, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::T_({::dregx::ast::Type::T_, ::deamer::external::cpp::ast::NodeValue::terminal, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Terminal) }) });
		((*yyvalp).dregx_any) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2346 "dregx_parser.tab.c"
    break;

  case 93: /* any: N_  */
#line 918 "./dregx_parser.y"
              {
		auto* const newNode = new dregx::ast::node::any({::dregx::ast::Type::any, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 14, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::N_({::dregx::ast::Type::N_, ::deamer::external::cpp::ast::NodeValue::terminal, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Terminal) }) });
		((*yyvalp).dregx_any) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2357 "dregx_parser.tab.c"
    break;

  case 94: /* any: R_  */
#line 924 "./dregx_parser.y"
              {
		auto* const newNode = new dregx::ast::node::any({::dregx::ast::Type::any, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 15, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::R_({::dregx::ast::Type::R_, ::deamer::external::cpp::ast::NodeValue::terminal, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Terminal) }) });
		((*yyvalp).dregx_any) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2368 "dregx_parser.tab.c"
    break;

  case 95: /* any: B_  */
#line 930 "./dregx_parser.y"
              {
		auto* const newNode = new dregx::ast::node::any({::dregx::ast::Type::any, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 16, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::B_({::dregx::ast::Type::B_, ::deamer::external::cpp::ast::NodeValue::terminal, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Terminal) }) });
		((*yyvalp).dregx_any) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2379 "dregx_parser.tab.c"
    break;

  case 96: /* any: V_  */
#line 936 "./dregx_parser.y"
              {
		auto* const newNode = new dregx::ast::node::any({::dregx::ast::Type::any, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 17, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::V_({::dregx::ast::Type::V_, ::deamer::external::cpp::ast::NodeValue::terminal, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Terminal) }) });
		((*yyvalp).dregx_any) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2390 "dregx_parser.tab.c"
    break;

  case 97: /* any: A_  */
#line 942 "./dregx_parser.y"
              {
		auto* const newNode = new dregx::ast::node::any({::dregx::ast::Type::any, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 18, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::A_({::dregx::ast::Type::A_, ::deamer::external::cpp::ast::NodeValue::terminal, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Terminal) }) });
		((*yyvalp).dregx_any) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2401 "dregx_parser.tab.c"
    break;

  case 98: /* any: LETTER  */
#line 948 "./dregx_parser.y"
                  {
		auto* const newNode = new dregx::ast::node::any({::dregx::ast::Type::any, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 19, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::LETTER({::dregx::ast::Type::LETTER, ::deamer::external::cpp::ast::NodeValue::terminal, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Terminal) }) });
		((*yyvalp).dregx_any) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2412 "dregx_parser.tab.c"
    break;

  case 99: /* any: SPACE  */
#line 954 "./dregx_parser.y"
                 {
		auto* const newNode = new dregx::ast::node::any({::dregx::ast::Type::any, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 20, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::SPACE({::dregx::ast::Type::SPACE, ::deamer::external::cpp::ast::NodeValue::terminal, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Terminal) }) });
		((*yyvalp).dregx_any) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2423 "dregx_parser.tab.c"
    break;

  case 100: /* any: TAB  */
#line 960 "./dregx_parser.y"
               {
		auto* const newNode = new dregx::ast::node::any({::dregx::ast::Type::any, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 21, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::TAB({::dregx::ast::Type::TAB, ::deamer::external::cpp::ast::NodeValue::terminal, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Terminal) }) });
		((*yyvalp).dregx_any) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2434 "dregx_parser.tab.c"
    break;

  case 101: /* any: PLUS  */
#line 966 "./dregx_parser.y"
                {
		auto* const newNode = new dregx::ast::node::any({::dregx::ast::Type::any, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 22, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::PLUS({::dregx::ast::Type::PLUS, ::deamer::external::cpp::ast::NodeValue::terminal, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Terminal) }) });
		((*yyvalp).dregx_any) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2445 "dregx_parser.tab.c"
    break;

  case 102: /* any: STAR  */
#line 972 "./dregx_parser.y"
                {
		auto* const newNode = new dregx::ast::node::any({::dregx::ast::Type::any, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 23, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::STAR({::dregx::ast::Type::STAR, ::deamer::external::cpp::ast::NodeValue::terminal, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Terminal) }) });
		((*yyvalp).dregx_any) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2456 "dregx_parser.tab.c"
    break;

  case 103: /* any: OTHER  */
#line 978 "./dregx_parser.y"
                 {
		auto* const newNode = new dregx::ast::node::any({::dregx::ast::Type::any, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 24, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::OTHER({::dregx::ast::Type::OTHER, ::deamer::external::cpp::ast::NodeValue::terminal, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Terminal) }) });
		((*yyvalp).dregx_any) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2467 "dregx_parser.tab.c"
    break;

  case 104: /* any: SLASH  */
#line 984 "./dregx_parser.y"
                 {
		auto* const newNode = new dregx::ast::node::any({::dregx::ast::Type::any, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 25, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::SLASH({::dregx::ast::Type::SLASH, ::deamer::external::cpp::ast::NodeValue::terminal, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.Terminal) }) });
		((*yyvalp).dregx_any) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2478 "dregx_parser.tab.c"
    break;


#line 2482 "dregx_parser.tab.c"

      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yylhsNonterm (yyrule), yyvalp, yylocp);

  return yyok;
# undef yyerrok
# undef YYABORT
# undef YYACCEPT
# undef YYNOMEM
# undef YYERROR
# undef YYBACKUP
# undef yyclearin
# undef YYRECOVERING
}


static void
yyuserMerge (int yyn, YYSTYPE* yy0, YYSTYPE* yy1)
{
  YY_USE (yy0);
  YY_USE (yy1);

  switch (yyn)
    {

      default: break;
    }
}

                              /* Bison grammar-table manipulation.  */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}

/** Number of symbols composing the right hand side of rule #RULE.  */
static inline int
yyrhsLength (yyRuleNum yyrule)
{
  return yyr2[yyrule];
}

static void
yydestroyGLRState (char const *yymsg, yyGLRState *yys)
{
  if (yys->yyresolved)
    yydestruct (yymsg, yy_accessing_symbol (yys->yylrState),
                &yys->yysemantics.yyval);
  else
    {
#if YYDEBUG
      if (yydebug)
        {
          if (yys->yysemantics.yyfirstVal)
            YY_FPRINTF ((stderr, "%s unresolved", yymsg));
          else
            YY_FPRINTF ((stderr, "%s incomplete", yymsg));
          YY_SYMBOL_PRINT ("", yy_accessing_symbol (yys->yylrState), YY_NULLPTR, &yys->yyloc);
        }
#endif

      if (yys->yysemantics.yyfirstVal)
        {
          yySemanticOption *yyoption = yys->yysemantics.yyfirstVal;
          yyGLRState *yyrh;
          int yyn;
          for (yyrh = yyoption->yystate, yyn = yyrhsLength (yyoption->yyrule);
               yyn > 0;
               yyrh = yyrh->yypred, yyn -= 1)
            yydestroyGLRState (yymsg, yyrh);
        }
    }
}

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

/** True iff LR state YYSTATE has only a default reduction (regardless
 *  of token).  */
static inline yybool
yyisDefaultedState (yy_state_t yystate)
{
  return yypact_value_is_default (yypact[yystate]);
}

/** The default reduction for YYSTATE, assuming it has one.  */
static inline yyRuleNum
yydefaultAction (yy_state_t yystate)
{
  return yydefact[yystate];
}

#define yytable_value_is_error(Yyn) \
  0

/** The action to take in YYSTATE on seeing YYTOKEN.
 *  Result R means
 *    R < 0:  Reduce on rule -R.
 *    R = 0:  Error.
 *    R > 0:  Shift to state R.
 *  Set *YYCONFLICTS to a pointer into yyconfl to a 0-terminated list
 *  of conflicting reductions.
 */
static inline int
yygetLRActions (yy_state_t yystate, yysymbol_kind_t yytoken, const short** yyconflicts)
{
  int yyindex = yypact[yystate] + yytoken;
  if (yytoken == YYSYMBOL_YYerror)
    {
      // This is the error token.
      *yyconflicts = yyconfl;
      return 0;
    }
  else if (yyisDefaultedState (yystate)
           || yyindex < 0 || YYLAST < yyindex || yycheck[yyindex] != yytoken)
    {
      *yyconflicts = yyconfl;
      return -yydefact[yystate];
    }
  else if (! yytable_value_is_error (yytable[yyindex]))
    {
      *yyconflicts = yyconfl + yyconflp[yyindex];
      return yytable[yyindex];
    }
  else
    {
      *yyconflicts = yyconfl + yyconflp[yyindex];
      return 0;
    }
}

/** Compute post-reduction state.
 * \param yystate   the current state
 * \param yysym     the nonterminal to push on the stack
 */
static inline yy_state_t
yyLRgotoState (yy_state_t yystate, yysymbol_kind_t yysym)
{
  int yyr = yypgoto[yysym - YYNTOKENS] + yystate;
  if (0 <= yyr && yyr <= YYLAST && yycheck[yyr] == yystate)
    return yytable[yyr];
  else
    return yydefgoto[yysym - YYNTOKENS];
}

static inline yybool
yyisShiftAction (int yyaction)
{
  return 0 < yyaction;
}

static inline yybool
yyisErrorAction (int yyaction)
{
  return yyaction == 0;
}

                                /* GLRStates */

/** Return a fresh GLRStackItem in YYSTACKP.  The item is an LR state
 *  if YYISSTATE, and otherwise a semantic option.  Callers should call
 *  YY_RESERVE_GLRSTACK afterwards to make sure there is sufficient
 *  headroom.  */

static inline yyGLRStackItem*
yynewGLRStackItem (yyGLRStack* yystackp, yybool yyisState)
{
  yyGLRStackItem* yynewItem = yystackp->yynextFree;
  yystackp->yyspaceLeft -= 1;
  yystackp->yynextFree += 1;
  yynewItem->yystate.yyisState = yyisState;
  return yynewItem;
}

/** Add a new semantic action that will execute the action for rule
 *  YYRULE on the semantic values in YYRHS to the list of
 *  alternative actions for YYSTATE.  Assumes that YYRHS comes from
 *  stack #YYK of *YYSTACKP. */
static void
yyaddDeferredAction (yyGLRStack* yystackp, YYPTRDIFF_T yyk, yyGLRState* yystate,
                     yyGLRState* yyrhs, yyRuleNum yyrule)
{
  yySemanticOption* yynewOption =
    &yynewGLRStackItem (yystackp, yyfalse)->yyoption;
  YY_ASSERT (!yynewOption->yyisState);
  yynewOption->yystate = yyrhs;
  yynewOption->yyrule = yyrule;
  if (yystackp->yytops.yylookaheadNeeds[yyk])
    {
      yynewOption->yyrawchar = yychar;
      yynewOption->yyval = yylval;
    }
  else
    yynewOption->yyrawchar = YYEMPTY;
  yynewOption->yynext = yystate->yysemantics.yyfirstVal;
  yystate->yysemantics.yyfirstVal = yynewOption;

  YY_RESERVE_GLRSTACK (yystackp);
}

                                /* GLRStacks */

/** Initialize YYSET to a singleton set containing an empty stack.  */
static yybool
yyinitStateSet (yyGLRStateSet* yyset)
{
  yyset->yysize = 1;
  yyset->yycapacity = 16;
  yyset->yystates
    = YY_CAST (yyGLRState**,
               YYMALLOC (YY_CAST (YYSIZE_T, yyset->yycapacity)
                         * sizeof yyset->yystates[0]));
  if (! yyset->yystates)
    return yyfalse;
  yyset->yystates[0] = YY_NULLPTR;
  yyset->yylookaheadNeeds
    = YY_CAST (yybool*,
               YYMALLOC (YY_CAST (YYSIZE_T, yyset->yycapacity)
                         * sizeof yyset->yylookaheadNeeds[0]));
  if (! yyset->yylookaheadNeeds)
    {
      YYFREE (yyset->yystates);
      return yyfalse;
    }
  memset (yyset->yylookaheadNeeds,
          0,
          YY_CAST (YYSIZE_T, yyset->yycapacity) * sizeof yyset->yylookaheadNeeds[0]);
  return yytrue;
}

static void yyfreeStateSet (yyGLRStateSet* yyset)
{
  YYFREE (yyset->yystates);
  YYFREE (yyset->yylookaheadNeeds);
}

/** Initialize *YYSTACKP to a single empty stack, with total maximum
 *  capacity for all stacks of YYSIZE.  */
static yybool
yyinitGLRStack (yyGLRStack* yystackp, YYPTRDIFF_T yysize)
{
  yystackp->yyerrState = 0;
  yynerrs = 0;
  yystackp->yyspaceLeft = yysize;
  yystackp->yyitems
    = YY_CAST (yyGLRStackItem*,
               YYMALLOC (YY_CAST (YYSIZE_T, yysize)
                         * sizeof yystackp->yynextFree[0]));
  if (!yystackp->yyitems)
    return yyfalse;
  yystackp->yynextFree = yystackp->yyitems;
  yystackp->yysplitPoint = YY_NULLPTR;
  yystackp->yylastDeleted = YY_NULLPTR;
  return yyinitStateSet (&yystackp->yytops);
}


#if YYSTACKEXPANDABLE
# define YYRELOC(YYFROMITEMS, YYTOITEMS, YYX, YYTYPE)                   \
  &((YYTOITEMS)                                                         \
    - ((YYFROMITEMS) - YY_REINTERPRET_CAST (yyGLRStackItem*, (YYX))))->YYTYPE

/** If *YYSTACKP is expandable, extend it.  WARNING: Pointers into the
    stack from outside should be considered invalid after this call.
    We always expand when there are 1 or fewer items left AFTER an
    allocation, so that we can avoid having external pointers exist
    across an allocation.  */
static void
yyexpandGLRStack (yyGLRStack* yystackp)
{
  yyGLRStackItem* yynewItems;
  yyGLRStackItem* yyp0, *yyp1;
  YYPTRDIFF_T yynewSize;
  YYPTRDIFF_T yyn;
  YYPTRDIFF_T yysize = yystackp->yynextFree - yystackp->yyitems;
  if (YYMAXDEPTH - YYHEADROOM < yysize)
    yyMemoryExhausted (yystackp);
  yynewSize = 2*yysize;
  if (YYMAXDEPTH < yynewSize)
    yynewSize = YYMAXDEPTH;
  yynewItems
    = YY_CAST (yyGLRStackItem*,
               YYMALLOC (YY_CAST (YYSIZE_T, yynewSize)
                         * sizeof yynewItems[0]));
  if (! yynewItems)
    yyMemoryExhausted (yystackp);
  for (yyp0 = yystackp->yyitems, yyp1 = yynewItems, yyn = yysize;
       0 < yyn;
       yyn -= 1, yyp0 += 1, yyp1 += 1)
    {
      *yyp1 = *yyp0;
      if (*YY_REINTERPRET_CAST (yybool *, yyp0))
        {
          yyGLRState* yys0 = &yyp0->yystate;
          yyGLRState* yys1 = &yyp1->yystate;
          if (yys0->yypred != YY_NULLPTR)
            yys1->yypred =
              YYRELOC (yyp0, yyp1, yys0->yypred, yystate);
          if (! yys0->yyresolved && yys0->yysemantics.yyfirstVal != YY_NULLPTR)
            yys1->yysemantics.yyfirstVal =
              YYRELOC (yyp0, yyp1, yys0->yysemantics.yyfirstVal, yyoption);
        }
      else
        {
          yySemanticOption* yyv0 = &yyp0->yyoption;
          yySemanticOption* yyv1 = &yyp1->yyoption;
          if (yyv0->yystate != YY_NULLPTR)
            yyv1->yystate = YYRELOC (yyp0, yyp1, yyv0->yystate, yystate);
          if (yyv0->yynext != YY_NULLPTR)
            yyv1->yynext = YYRELOC (yyp0, yyp1, yyv0->yynext, yyoption);
        }
    }
  if (yystackp->yysplitPoint != YY_NULLPTR)
    yystackp->yysplitPoint = YYRELOC (yystackp->yyitems, yynewItems,
                                      yystackp->yysplitPoint, yystate);

  for (yyn = 0; yyn < yystackp->yytops.yysize; yyn += 1)
    if (yystackp->yytops.yystates[yyn] != YY_NULLPTR)
      yystackp->yytops.yystates[yyn] =
        YYRELOC (yystackp->yyitems, yynewItems,
                 yystackp->yytops.yystates[yyn], yystate);
  YYFREE (yystackp->yyitems);
  yystackp->yyitems = yynewItems;
  yystackp->yynextFree = yynewItems + yysize;
  yystackp->yyspaceLeft = yynewSize - yysize;
}
#endif

static void
yyfreeGLRStack (yyGLRStack* yystackp)
{
  YYFREE (yystackp->yyitems);
  yyfreeStateSet (&yystackp->yytops);
}

/** Assuming that YYS is a GLRState somewhere on *YYSTACKP, update the
 *  splitpoint of *YYSTACKP, if needed, so that it is at least as deep as
 *  YYS.  */
static inline void
yyupdateSplit (yyGLRStack* yystackp, yyGLRState* yys)
{
  if (yystackp->yysplitPoint != YY_NULLPTR && yystackp->yysplitPoint > yys)
    yystackp->yysplitPoint = yys;
}

/** Invalidate stack #YYK in *YYSTACKP.  */
static inline void
yymarkStackDeleted (yyGLRStack* yystackp, YYPTRDIFF_T yyk)
{
  if (yystackp->yytops.yystates[yyk] != YY_NULLPTR)
    yystackp->yylastDeleted = yystackp->yytops.yystates[yyk];
  yystackp->yytops.yystates[yyk] = YY_NULLPTR;
}

/** Undelete the last stack in *YYSTACKP that was marked as deleted.  Can
    only be done once after a deletion, and only when all other stacks have
    been deleted.  */
static void
yyundeleteLastStack (yyGLRStack* yystackp)
{
  if (yystackp->yylastDeleted == YY_NULLPTR || yystackp->yytops.yysize != 0)
    return;
  yystackp->yytops.yystates[0] = yystackp->yylastDeleted;
  yystackp->yytops.yysize = 1;
  YY_DPRINTF ((stderr, "Restoring last deleted stack as stack #0.\n"));
  yystackp->yylastDeleted = YY_NULLPTR;
}

static inline void
yyremoveDeletes (yyGLRStack* yystackp)
{
  YYPTRDIFF_T yyi, yyj;
  yyi = yyj = 0;
  while (yyj < yystackp->yytops.yysize)
    {
      if (yystackp->yytops.yystates[yyi] == YY_NULLPTR)
        {
          if (yyi == yyj)
            YY_DPRINTF ((stderr, "Removing dead stacks.\n"));
          yystackp->yytops.yysize -= 1;
        }
      else
        {
          yystackp->yytops.yystates[yyj] = yystackp->yytops.yystates[yyi];
          /* In the current implementation, it's unnecessary to copy
             yystackp->yytops.yylookaheadNeeds[yyi] since, after
             yyremoveDeletes returns, the parser immediately either enters
             deterministic operation or shifts a token.  However, it doesn't
             hurt, and the code might evolve to need it.  */
          yystackp->yytops.yylookaheadNeeds[yyj] =
            yystackp->yytops.yylookaheadNeeds[yyi];
          if (yyj != yyi)
            YY_DPRINTF ((stderr, "Rename stack %ld -> %ld.\n",
                        YY_CAST (long, yyi), YY_CAST (long, yyj)));
          yyj += 1;
        }
      yyi += 1;
    }
}

/** Shift to a new state on stack #YYK of *YYSTACKP, corresponding to LR
 * state YYLRSTATE, at input position YYPOSN, with (resolved) semantic
 * value *YYVALP and source location *YYLOCP.  */
static inline void
yyglrShift (yyGLRStack* yystackp, YYPTRDIFF_T yyk, yy_state_t yylrState,
            YYPTRDIFF_T yyposn,
            YYSTYPE* yyvalp)
{
  yyGLRState* yynewState = &yynewGLRStackItem (yystackp, yytrue)->yystate;

  yynewState->yylrState = yylrState;
  yynewState->yyposn = yyposn;
  yynewState->yyresolved = yytrue;
  yynewState->yypred = yystackp->yytops.yystates[yyk];
  yynewState->yysemantics.yyval = *yyvalp;
  yystackp->yytops.yystates[yyk] = yynewState;

  YY_RESERVE_GLRSTACK (yystackp);
}

/** Shift stack #YYK of *YYSTACKP, to a new state corresponding to LR
 *  state YYLRSTATE, at input position YYPOSN, with the (unresolved)
 *  semantic value of YYRHS under the action for YYRULE.  */
static inline void
yyglrShiftDefer (yyGLRStack* yystackp, YYPTRDIFF_T yyk, yy_state_t yylrState,
                 YYPTRDIFF_T yyposn, yyGLRState* yyrhs, yyRuleNum yyrule)
{
  yyGLRState* yynewState = &yynewGLRStackItem (yystackp, yytrue)->yystate;
  YY_ASSERT (yynewState->yyisState);

  yynewState->yylrState = yylrState;
  yynewState->yyposn = yyposn;
  yynewState->yyresolved = yyfalse;
  yynewState->yypred = yystackp->yytops.yystates[yyk];
  yynewState->yysemantics.yyfirstVal = YY_NULLPTR;
  yystackp->yytops.yystates[yyk] = yynewState;

  /* Invokes YY_RESERVE_GLRSTACK.  */
  yyaddDeferredAction (yystackp, yyk, yynewState, yyrhs, yyrule);
}

#if YYDEBUG

/*----------------------------------------------------------------------.
| Report that stack #YYK of *YYSTACKP is going to be reduced by YYRULE. |
`----------------------------------------------------------------------*/

static inline void
yy_reduce_print (yybool yynormal, yyGLRStackItem* yyvsp, YYPTRDIFF_T yyk,
                 yyRuleNum yyrule)
{
  int yynrhs = yyrhsLength (yyrule);
  int yyi;
  YY_FPRINTF ((stderr, "Reducing stack %ld by rule %d (line %d):\n",
               YY_CAST (long, yyk), yyrule - 1, yyrline[yyrule]));
  if (! yynormal)
    yyfillin (yyvsp, 1, -yynrhs);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YY_FPRINTF ((stderr, "   $%d = ", yyi + 1));
      yy_symbol_print (stderr,
                       yy_accessing_symbol (yyvsp[yyi - yynrhs + 1].yystate.yylrState),
                       &yyvsp[yyi - yynrhs + 1].yystate.yysemantics.yyval                       );
      if (!yyvsp[yyi - yynrhs + 1].yystate.yyresolved)
        YY_FPRINTF ((stderr, " (unresolved)"));
      YY_FPRINTF ((stderr, "\n"));
    }
}
#endif

/** Pop the symbols consumed by reduction #YYRULE from the top of stack
 *  #YYK of *YYSTACKP, and perform the appropriate semantic action on their
 *  semantic values.  Assumes that all ambiguities in semantic values
 *  have been previously resolved.  Set *YYVALP to the resulting value,
 *  and *YYLOCP to the computed location (if any).  Return value is as
 *  for userAction.  */
static inline YYRESULTTAG
yydoAction (yyGLRStack* yystackp, YYPTRDIFF_T yyk, yyRuleNum yyrule,
            YYSTYPE* yyvalp)
{
  int yynrhs = yyrhsLength (yyrule);

  if (yystackp->yysplitPoint == YY_NULLPTR)
    {
      /* Standard special case: single stack.  */
      yyGLRStackItem* yyrhs
        = YY_REINTERPRET_CAST (yyGLRStackItem*, yystackp->yytops.yystates[yyk]);
      YY_ASSERT (yyk == 0);
      yystackp->yynextFree -= yynrhs;
      yystackp->yyspaceLeft += yynrhs;
      yystackp->yytops.yystates[0] = & yystackp->yynextFree[-1].yystate;
      return yyuserAction (yyrule, yynrhs, yyrhs, yystackp, yyk,
                           yyvalp);
    }
  else
    {
      yyGLRStackItem yyrhsVals[YYMAXRHS + YYMAXLEFT + 1];
      yyGLRState* yys = yyrhsVals[YYMAXRHS + YYMAXLEFT].yystate.yypred
        = yystackp->yytops.yystates[yyk];
      int yyi;
      for (yyi = 0; yyi < yynrhs; yyi += 1)
        {
          yys = yys->yypred;
          YY_ASSERT (yys);
        }
      yyupdateSplit (yystackp, yys);
      yystackp->yytops.yystates[yyk] = yys;
      return yyuserAction (yyrule, yynrhs, yyrhsVals + YYMAXRHS + YYMAXLEFT - 1,
                           yystackp, yyk, yyvalp);
    }
}

/** Pop items off stack #YYK of *YYSTACKP according to grammar rule YYRULE,
 *  and push back on the resulting nonterminal symbol.  Perform the
 *  semantic action associated with YYRULE and store its value with the
 *  newly pushed state, if YYFORCEEVAL or if *YYSTACKP is currently
 *  unambiguous.  Otherwise, store the deferred semantic action with
 *  the new state.  If the new state would have an identical input
 *  position, LR state, and predecessor to an existing state on the stack,
 *  it is identified with that existing state, eliminating stack #YYK from
 *  *YYSTACKP.  In this case, the semantic value is
 *  added to the options for the existing state's semantic value.
 */
static inline YYRESULTTAG
yyglrReduce (yyGLRStack* yystackp, YYPTRDIFF_T yyk, yyRuleNum yyrule,
             yybool yyforceEval)
{
  YYPTRDIFF_T yyposn = yystackp->yytops.yystates[yyk]->yyposn;

  if (yyforceEval || yystackp->yysplitPoint == YY_NULLPTR)
    {
      YYSTYPE yyval;

      YYRESULTTAG yyflag = yydoAction (yystackp, yyk, yyrule, &yyval);
      if (yyflag == yyerr && yystackp->yysplitPoint != YY_NULLPTR)
        YY_DPRINTF ((stderr,
                     "Parse on stack %ld rejected by rule %d (line %d).\n",
                     YY_CAST (long, yyk), yyrule - 1, yyrline[yyrule]));
      if (yyflag != yyok)
        return yyflag;
      yyglrShift (yystackp, yyk,
                  yyLRgotoState (yystackp->yytops.yystates[yyk]->yylrState,
                                 yylhsNonterm (yyrule)),
                  yyposn, &yyval);
    }
  else
    {
      YYPTRDIFF_T yyi;
      int yyn;
      yyGLRState* yys, *yys0 = yystackp->yytops.yystates[yyk];
      yy_state_t yynewLRState;

      for (yys = yystackp->yytops.yystates[yyk], yyn = yyrhsLength (yyrule);
           0 < yyn; yyn -= 1)
        {
          yys = yys->yypred;
          YY_ASSERT (yys);
        }
      yyupdateSplit (yystackp, yys);
      yynewLRState = yyLRgotoState (yys->yylrState, yylhsNonterm (yyrule));
      YY_DPRINTF ((stderr,
                   "Reduced stack %ld by rule %d (line %d); action deferred.  "
                   "Now in state %d.\n",
                   YY_CAST (long, yyk), yyrule - 1, yyrline[yyrule],
                   yynewLRState));
      for (yyi = 0; yyi < yystackp->yytops.yysize; yyi += 1)
        if (yyi != yyk && yystackp->yytops.yystates[yyi] != YY_NULLPTR)
          {
            yyGLRState *yysplit = yystackp->yysplitPoint;
            yyGLRState *yyp = yystackp->yytops.yystates[yyi];
            while (yyp != yys && yyp != yysplit && yyp->yyposn >= yyposn)
              {
                if (yyp->yylrState == yynewLRState && yyp->yypred == yys)
                  {
                    yyaddDeferredAction (yystackp, yyk, yyp, yys0, yyrule);
                    yymarkStackDeleted (yystackp, yyk);
                    YY_DPRINTF ((stderr, "Merging stack %ld into stack %ld.\n",
                                 YY_CAST (long, yyk), YY_CAST (long, yyi)));
                    return yyok;
                  }
                yyp = yyp->yypred;
              }
          }
      yystackp->yytops.yystates[yyk] = yys;
      yyglrShiftDefer (yystackp, yyk, yynewLRState, yyposn, yys0, yyrule);
    }
  return yyok;
}

static YYPTRDIFF_T
yysplitStack (yyGLRStack* yystackp, YYPTRDIFF_T yyk)
{
  if (yystackp->yysplitPoint == YY_NULLPTR)
    {
      YY_ASSERT (yyk == 0);
      yystackp->yysplitPoint = yystackp->yytops.yystates[yyk];
    }
  if (yystackp->yytops.yycapacity <= yystackp->yytops.yysize)
    {
      YYPTRDIFF_T state_size = YYSIZEOF (yystackp->yytops.yystates[0]);
      YYPTRDIFF_T half_max_capacity = YYSIZE_MAXIMUM / 2 / state_size;
      if (half_max_capacity < yystackp->yytops.yycapacity)
        yyMemoryExhausted (yystackp);
      yystackp->yytops.yycapacity *= 2;

      {
        yyGLRState** yynewStates
          = YY_CAST (yyGLRState**,
                     YYREALLOC (yystackp->yytops.yystates,
                                (YY_CAST (YYSIZE_T, yystackp->yytops.yycapacity)
                                 * sizeof yynewStates[0])));
        if (yynewStates == YY_NULLPTR)
          yyMemoryExhausted (yystackp);
        yystackp->yytops.yystates = yynewStates;
      }

      {
        yybool* yynewLookaheadNeeds
          = YY_CAST (yybool*,
                     YYREALLOC (yystackp->yytops.yylookaheadNeeds,
                                (YY_CAST (YYSIZE_T, yystackp->yytops.yycapacity)
                                 * sizeof yynewLookaheadNeeds[0])));
        if (yynewLookaheadNeeds == YY_NULLPTR)
          yyMemoryExhausted (yystackp);
        yystackp->yytops.yylookaheadNeeds = yynewLookaheadNeeds;
      }
    }
  yystackp->yytops.yystates[yystackp->yytops.yysize]
    = yystackp->yytops.yystates[yyk];
  yystackp->yytops.yylookaheadNeeds[yystackp->yytops.yysize]
    = yystackp->yytops.yylookaheadNeeds[yyk];
  yystackp->yytops.yysize += 1;
  return yystackp->yytops.yysize - 1;
}

/** True iff YYY0 and YYY1 represent identical options at the top level.
 *  That is, they represent the same rule applied to RHS symbols
 *  that produce the same terminal symbols.  */
static yybool
yyidenticalOptions (yySemanticOption* yyy0, yySemanticOption* yyy1)
{
  if (yyy0->yyrule == yyy1->yyrule)
    {
      yyGLRState *yys0, *yys1;
      int yyn;
      for (yys0 = yyy0->yystate, yys1 = yyy1->yystate,
           yyn = yyrhsLength (yyy0->yyrule);
           yyn > 0;
           yys0 = yys0->yypred, yys1 = yys1->yypred, yyn -= 1)
        if (yys0->yyposn != yys1->yyposn)
          return yyfalse;
      return yytrue;
    }
  else
    return yyfalse;
}

/** Assuming identicalOptions (YYY0,YYY1), destructively merge the
 *  alternative semantic values for the RHS-symbols of YYY1 and YYY0.  */
static void
yymergeOptionSets (yySemanticOption* yyy0, yySemanticOption* yyy1)
{
  yyGLRState *yys0, *yys1;
  int yyn;
  for (yys0 = yyy0->yystate, yys1 = yyy1->yystate,
       yyn = yyrhsLength (yyy0->yyrule);
       0 < yyn;
       yys0 = yys0->yypred, yys1 = yys1->yypred, yyn -= 1)
    {
      if (yys0 == yys1)
        break;
      else if (yys0->yyresolved)
        {
          yys1->yyresolved = yytrue;
          yys1->yysemantics.yyval = yys0->yysemantics.yyval;
        }
      else if (yys1->yyresolved)
        {
          yys0->yyresolved = yytrue;
          yys0->yysemantics.yyval = yys1->yysemantics.yyval;
        }
      else
        {
          yySemanticOption** yyz0p = &yys0->yysemantics.yyfirstVal;
          yySemanticOption* yyz1 = yys1->yysemantics.yyfirstVal;
          while (yytrue)
            {
              if (yyz1 == *yyz0p || yyz1 == YY_NULLPTR)
                break;
              else if (*yyz0p == YY_NULLPTR)
                {
                  *yyz0p = yyz1;
                  break;
                }
              else if (*yyz0p < yyz1)
                {
                  yySemanticOption* yyz = *yyz0p;
                  *yyz0p = yyz1;
                  yyz1 = yyz1->yynext;
                  (*yyz0p)->yynext = yyz;
                }
              yyz0p = &(*yyz0p)->yynext;
            }
          yys1->yysemantics.yyfirstVal = yys0->yysemantics.yyfirstVal;
        }
    }
}

/** Y0 and Y1 represent two possible actions to take in a given
 *  parsing state; return 0 if no combination is possible,
 *  1 if user-mergeable, 2 if Y0 is preferred, 3 if Y1 is preferred.  */
static int
yypreference (yySemanticOption* y0, yySemanticOption* y1)
{
  yyRuleNum r0 = y0->yyrule, r1 = y1->yyrule;
  int p0 = yydprec[r0], p1 = yydprec[r1];

  if (p0 == p1)
    {
      if (yymerger[r0] == 0 || yymerger[r0] != yymerger[r1])
        return 0;
      else
        return 1;
    }
  if (p0 == 0 || p1 == 0)
    return 0;
  if (p0 < p1)
    return 3;
  if (p1 < p0)
    return 2;
  return 0;
}

static YYRESULTTAG
yyresolveValue (yyGLRState* yys, yyGLRStack* yystackp);


/** Resolve the previous YYN states starting at and including state YYS
 *  on *YYSTACKP. If result != yyok, some states may have been left
 *  unresolved possibly with empty semantic option chains.  Regardless
 *  of whether result = yyok, each state has been left with consistent
 *  data so that yydestroyGLRState can be invoked if necessary.  */
static YYRESULTTAG
yyresolveStates (yyGLRState* yys, int yyn,
                 yyGLRStack* yystackp)
{
  if (0 < yyn)
    {
      YY_ASSERT (yys->yypred);
      YYCHK (yyresolveStates (yys->yypred, yyn-1, yystackp));
      if (! yys->yyresolved)
        YYCHK (yyresolveValue (yys, yystackp));
    }
  return yyok;
}

/** Resolve the states for the RHS of YYOPT on *YYSTACKP, perform its
 *  user action, and return the semantic value and location in *YYVALP
 *  and *YYLOCP.  Regardless of whether result = yyok, all RHS states
 *  have been destroyed (assuming the user action destroys all RHS
 *  semantic values if invoked).  */
static YYRESULTTAG
yyresolveAction (yySemanticOption* yyopt, yyGLRStack* yystackp,
                 YYSTYPE* yyvalp)
{
  yyGLRStackItem yyrhsVals[YYMAXRHS + YYMAXLEFT + 1];
  int yynrhs = yyrhsLength (yyopt->yyrule);
  YYRESULTTAG yyflag =
    yyresolveStates (yyopt->yystate, yynrhs, yystackp);
  if (yyflag != yyok)
    {
      yyGLRState *yys;
      for (yys = yyopt->yystate; yynrhs > 0; yys = yys->yypred, yynrhs -= 1)
        yydestroyGLRState ("Cleanup: popping", yys);
      return yyflag;
    }

  yyrhsVals[YYMAXRHS + YYMAXLEFT].yystate.yypred = yyopt->yystate;
  {
    int yychar_current = yychar;
    YYSTYPE yylval_current = yylval;
    yychar = yyopt->yyrawchar;
    yylval = yyopt->yyval;
    yyflag = yyuserAction (yyopt->yyrule, yynrhs,
                           yyrhsVals + YYMAXRHS + YYMAXLEFT - 1,
                           yystackp, -1, yyvalp);
    yychar = yychar_current;
    yylval = yylval_current;
  }
  return yyflag;
}

#if YYDEBUG
static void
yyreportTree (yySemanticOption* yyx, int yyindent)
{
  int yynrhs = yyrhsLength (yyx->yyrule);
  int yyi;
  yyGLRState* yys;
  yyGLRState* yystates[1 + YYMAXRHS];
  yyGLRState yyleftmost_state;

  for (yyi = yynrhs, yys = yyx->yystate; 0 < yyi; yyi -= 1, yys = yys->yypred)
    yystates[yyi] = yys;
  if (yys == YY_NULLPTR)
    {
      yyleftmost_state.yyposn = 0;
      yystates[0] = &yyleftmost_state;
    }
  else
    yystates[0] = yys;

  if (yyx->yystate->yyposn < yys->yyposn + 1)
    YY_FPRINTF ((stderr, "%*s%s -> <Rule %d, empty>\n",
                 yyindent, "", yysymbol_name (yylhsNonterm (yyx->yyrule)),
                 yyx->yyrule - 1));
  else
    YY_FPRINTF ((stderr, "%*s%s -> <Rule %d, tokens %ld .. %ld>\n",
                 yyindent, "", yysymbol_name (yylhsNonterm (yyx->yyrule)),
                 yyx->yyrule - 1, YY_CAST (long, yys->yyposn + 1),
                 YY_CAST (long, yyx->yystate->yyposn)));
  for (yyi = 1; yyi <= yynrhs; yyi += 1)
    {
      if (yystates[yyi]->yyresolved)
        {
          if (yystates[yyi-1]->yyposn+1 > yystates[yyi]->yyposn)
            YY_FPRINTF ((stderr, "%*s%s <empty>\n", yyindent+2, "",
                         yysymbol_name (yy_accessing_symbol (yystates[yyi]->yylrState))));
          else
            YY_FPRINTF ((stderr, "%*s%s <tokens %ld .. %ld>\n", yyindent+2, "",
                         yysymbol_name (yy_accessing_symbol (yystates[yyi]->yylrState)),
                         YY_CAST (long, yystates[yyi-1]->yyposn + 1),
                         YY_CAST (long, yystates[yyi]->yyposn)));
        }
      else
        yyreportTree (yystates[yyi]->yysemantics.yyfirstVal, yyindent+2);
    }
}
#endif

static YYRESULTTAG
yyreportAmbiguity (yySemanticOption* yyx0,
                   yySemanticOption* yyx1)
{
  YY_USE (yyx0);
  YY_USE (yyx1);

#if YYDEBUG
  YY_FPRINTF ((stderr, "Ambiguity detected.\n"));
  YY_FPRINTF ((stderr, "Option 1,\n"));
  yyreportTree (yyx0, 2);
  YY_FPRINTF ((stderr, "\nOption 2,\n"));
  yyreportTree (yyx1, 2);
  YY_FPRINTF ((stderr, "\n"));
#endif

  yyerror (YY_("syntax is ambiguous"));
  return yyabort;
}

/** Resolve the ambiguity represented in state YYS in *YYSTACKP,
 *  perform the indicated actions, and set the semantic value of YYS.
 *  If result != yyok, the chain of semantic options in YYS has been
 *  cleared instead or it has been left unmodified except that
 *  redundant options may have been removed.  Regardless of whether
 *  result = yyok, YYS has been left with consistent data so that
 *  yydestroyGLRState can be invoked if necessary.  */
static YYRESULTTAG
yyresolveValue (yyGLRState* yys, yyGLRStack* yystackp)
{
  yySemanticOption* yyoptionList = yys->yysemantics.yyfirstVal;
  yySemanticOption* yybest = yyoptionList;
  yySemanticOption** yypp;
  yybool yymerge = yyfalse;
  YYSTYPE yyval;
  YYRESULTTAG yyflag;

  for (yypp = &yyoptionList->yynext; *yypp != YY_NULLPTR; )
    {
      yySemanticOption* yyp = *yypp;

      if (yyidenticalOptions (yybest, yyp))
        {
          yymergeOptionSets (yybest, yyp);
          *yypp = yyp->yynext;
        }
      else
        {
          switch (yypreference (yybest, yyp))
            {
            case 0:
              return yyreportAmbiguity (yybest, yyp);
              break;
            case 1:
              yymerge = yytrue;
              break;
            case 2:
              break;
            case 3:
              yybest = yyp;
              yymerge = yyfalse;
              break;
            default:
              /* This cannot happen so it is not worth a YY_ASSERT (yyfalse),
                 but some compilers complain if the default case is
                 omitted.  */
              break;
            }
          yypp = &yyp->yynext;
        }
    }

  if (yymerge)
    {
      yySemanticOption* yyp;
      int yyprec = yydprec[yybest->yyrule];
      yyflag = yyresolveAction (yybest, yystackp, &yyval);
      if (yyflag == yyok)
        for (yyp = yybest->yynext; yyp != YY_NULLPTR; yyp = yyp->yynext)
          {
            if (yyprec == yydprec[yyp->yyrule])
              {
                YYSTYPE yyval_other;
                yyflag = yyresolveAction (yyp, yystackp, &yyval_other);
                if (yyflag != yyok)
                  {
                    yydestruct ("Cleanup: discarding incompletely merged value for",
                                yy_accessing_symbol (yys->yylrState),
                                &yyval);
                    break;
                  }
                yyuserMerge (yymerger[yyp->yyrule], &yyval, &yyval_other);
              }
          }
    }
  else
    yyflag = yyresolveAction (yybest, yystackp, &yyval);

  if (yyflag == yyok)
    {
      yys->yyresolved = yytrue;
      yys->yysemantics.yyval = yyval;
    }
  else
    yys->yysemantics.yyfirstVal = YY_NULLPTR;
  return yyflag;
}

static YYRESULTTAG
yyresolveStack (yyGLRStack* yystackp)
{
  if (yystackp->yysplitPoint != YY_NULLPTR)
    {
      yyGLRState* yys;
      int yyn;

      for (yyn = 0, yys = yystackp->yytops.yystates[0];
           yys != yystackp->yysplitPoint;
           yys = yys->yypred, yyn += 1)
        continue;
      YYCHK (yyresolveStates (yystackp->yytops.yystates[0], yyn, yystackp
                             ));
    }
  return yyok;
}

/** Called when returning to deterministic operation to clean up the extra
 * stacks. */
static void
yycompressStack (yyGLRStack* yystackp)
{
  /* yyr is the state after the split point.  */
  yyGLRState *yyr;

  if (yystackp->yytops.yysize != 1 || yystackp->yysplitPoint == YY_NULLPTR)
    return;

  {
    yyGLRState *yyp, *yyq;
    for (yyp = yystackp->yytops.yystates[0], yyq = yyp->yypred, yyr = YY_NULLPTR;
         yyp != yystackp->yysplitPoint;
         yyr = yyp, yyp = yyq, yyq = yyp->yypred)
      yyp->yypred = yyr;
  }

  yystackp->yyspaceLeft += yystackp->yynextFree - yystackp->yyitems;
  yystackp->yynextFree = YY_REINTERPRET_CAST (yyGLRStackItem*, yystackp->yysplitPoint) + 1;
  yystackp->yyspaceLeft -= yystackp->yynextFree - yystackp->yyitems;
  yystackp->yysplitPoint = YY_NULLPTR;
  yystackp->yylastDeleted = YY_NULLPTR;

  while (yyr != YY_NULLPTR)
    {
      yystackp->yynextFree->yystate = *yyr;
      yyr = yyr->yypred;
      yystackp->yynextFree->yystate.yypred = &yystackp->yynextFree[-1].yystate;
      yystackp->yytops.yystates[0] = &yystackp->yynextFree->yystate;
      yystackp->yynextFree += 1;
      yystackp->yyspaceLeft -= 1;
    }
}

static YYRESULTTAG
yyprocessOneStack (yyGLRStack* yystackp, YYPTRDIFF_T yyk,
                   YYPTRDIFF_T yyposn)
{
  while (yystackp->yytops.yystates[yyk] != YY_NULLPTR)
    {
      yy_state_t yystate = yystackp->yytops.yystates[yyk]->yylrState;
      YY_DPRINTF ((stderr, "Stack %ld Entering state %d\n",
                   YY_CAST (long, yyk), yystate));

      YY_ASSERT (yystate != YYFINAL);

      if (yyisDefaultedState (yystate))
        {
          YYRESULTTAG yyflag;
          yyRuleNum yyrule = yydefaultAction (yystate);
          if (yyrule == 0)
            {
              YY_DPRINTF ((stderr, "Stack %ld dies.\n", YY_CAST (long, yyk)));
              yymarkStackDeleted (yystackp, yyk);
              return yyok;
            }
          yyflag = yyglrReduce (yystackp, yyk, yyrule, yyimmediate[yyrule]);
          if (yyflag == yyerr)
            {
              YY_DPRINTF ((stderr,
                           "Stack %ld dies "
                           "(predicate failure or explicit user error).\n",
                           YY_CAST (long, yyk)));
              yymarkStackDeleted (yystackp, yyk);
              return yyok;
            }
          if (yyflag != yyok)
            return yyflag;
        }
      else
        {
          yysymbol_kind_t yytoken = yygetToken (&yychar);
          const short* yyconflicts;
          const int yyaction = yygetLRActions (yystate, yytoken, &yyconflicts);
          yystackp->yytops.yylookaheadNeeds[yyk] = yytrue;

          for (/* nothing */; *yyconflicts; yyconflicts += 1)
            {
              YYRESULTTAG yyflag;
              YYPTRDIFF_T yynewStack = yysplitStack (yystackp, yyk);
              YY_DPRINTF ((stderr, "Splitting off stack %ld from %ld.\n",
                           YY_CAST (long, yynewStack), YY_CAST (long, yyk)));
              yyflag = yyglrReduce (yystackp, yynewStack,
                                    *yyconflicts,
                                    yyimmediate[*yyconflicts]);
              if (yyflag == yyok)
                YYCHK (yyprocessOneStack (yystackp, yynewStack,
                                          yyposn));
              else if (yyflag == yyerr)
                {
                  YY_DPRINTF ((stderr, "Stack %ld dies.\n", YY_CAST (long, yynewStack)));
                  yymarkStackDeleted (yystackp, yynewStack);
                }
              else
                return yyflag;
            }

          if (yyisShiftAction (yyaction))
            break;
          else if (yyisErrorAction (yyaction))
            {
              YY_DPRINTF ((stderr, "Stack %ld dies.\n", YY_CAST (long, yyk)));
              yymarkStackDeleted (yystackp, yyk);
              break;
            }
          else
            {
              YYRESULTTAG yyflag = yyglrReduce (yystackp, yyk, -yyaction,
                                                yyimmediate[-yyaction]);
              if (yyflag == yyerr)
                {
                  YY_DPRINTF ((stderr,
                               "Stack %ld dies "
                               "(predicate failure or explicit user error).\n",
                               YY_CAST (long, yyk)));
                  yymarkStackDeleted (yystackp, yyk);
                  break;
                }
              else if (yyflag != yyok)
                return yyflag;
            }
        }
    }
  return yyok;
}

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYSTACKP, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  */
static int
yypcontext_expected_tokens (const yyGLRStack* yystackp,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[yystackp->yytops.yystates[0]->yylrState];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}

static int
yy_syntax_error_arguments (const yyGLRStack* yystackp,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  yysymbol_kind_t yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yystackp,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}



static void
yyreportSyntaxError (yyGLRStack* yystackp)
{
  if (yystackp->yyerrState != 0)
    return;
  {
  yybool yysize_overflow = yyfalse;
  char* yymsg = YY_NULLPTR;
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount
    = yy_syntax_error_arguments (yystackp, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    yyMemoryExhausted (yystackp);

  switch (yycount)
    {
#define YYCASE_(N, S)                   \
      case N:                           \
        yyformat = S;                   \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysz
          = yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (YYSIZE_MAXIMUM - yysize < yysz)
          yysize_overflow = yytrue;
        else
          yysize += yysz;
      }
  }

  if (!yysize_overflow)
    yymsg = YY_CAST (char *, YYMALLOC (YY_CAST (YYSIZE_T, yysize)));

  if (yymsg)
    {
      char *yyp = yymsg;
      int yyi = 0;
      while ((*yyp = *yyformat))
        {
          if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
            {
              yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
              yyformat += 2;
            }
          else
            {
              ++yyp;
              ++yyformat;
            }
        }
      yyerror (yymsg);
      YYFREE (yymsg);
    }
  else
    {
      yyerror (YY_("syntax error"));
      yyMemoryExhausted (yystackp);
    }
  }
  yynerrs += 1;
}

/* Recover from a syntax error on *YYSTACKP, assuming that *YYSTACKP->YYTOKENP,
   yylval, and yylloc are the syntactic category, semantic value, and location
   of the lookahead.  */
static void
yyrecoverSyntaxError (yyGLRStack* yystackp)
{
  if (yystackp->yyerrState == 3)
    /* We just shifted the error token and (perhaps) took some
       reductions.  Skip tokens until we can proceed.  */
    while (yytrue)
      {
        yysymbol_kind_t yytoken;
        int yyj;
        if (yychar == YYEOF)
          yyFail (yystackp, YY_NULLPTR);
        if (yychar != YYEMPTY)
          {
            yytoken = YYTRANSLATE (yychar);
            yydestruct ("Error: discarding",
                        yytoken, &yylval);
            yychar = YYEMPTY;
          }
        yytoken = yygetToken (&yychar);
        yyj = yypact[yystackp->yytops.yystates[0]->yylrState];
        if (yypact_value_is_default (yyj))
          return;
        yyj += yytoken;
        if (yyj < 0 || YYLAST < yyj || yycheck[yyj] != yytoken)
          {
            if (yydefact[yystackp->yytops.yystates[0]->yylrState] != 0)
              return;
          }
        else if (! yytable_value_is_error (yytable[yyj]))
          return;
      }

  /* Reduce to one stack.  */
  {
    YYPTRDIFF_T yyk;
    for (yyk = 0; yyk < yystackp->yytops.yysize; yyk += 1)
      if (yystackp->yytops.yystates[yyk] != YY_NULLPTR)
        break;
    if (yyk >= yystackp->yytops.yysize)
      yyFail (yystackp, YY_NULLPTR);
    for (yyk += 1; yyk < yystackp->yytops.yysize; yyk += 1)
      yymarkStackDeleted (yystackp, yyk);
    yyremoveDeletes (yystackp);
    yycompressStack (yystackp);
  }

  /* Pop stack until we find a state that shifts the error token.  */
  yystackp->yyerrState = 3;
  while (yystackp->yytops.yystates[0] != YY_NULLPTR)
    {
      yyGLRState *yys = yystackp->yytops.yystates[0];
      int yyj = yypact[yys->yylrState];
      if (! yypact_value_is_default (yyj))
        {
          yyj += YYSYMBOL_YYerror;
          if (0 <= yyj && yyj <= YYLAST && yycheck[yyj] == YYSYMBOL_YYerror
              && yyisShiftAction (yytable[yyj]))
            {
              /* Shift the error token.  */
              int yyaction = yytable[yyj];
              YY_SYMBOL_PRINT ("Shifting", yy_accessing_symbol (yyaction),
                               &yylval, &yyerrloc);
              yyglrShift (yystackp, 0, yyaction,
                          yys->yyposn, &yylval);
              yys = yystackp->yytops.yystates[0];
              break;
            }
        }
      if (yys->yypred != YY_NULLPTR)
        yydestroyGLRState ("Error: popping", yys);
      yystackp->yytops.yystates[0] = yys->yypred;
      yystackp->yynextFree -= 1;
      yystackp->yyspaceLeft += 1;
    }
  if (yystackp->yytops.yystates[0] == YY_NULLPTR)
    yyFail (yystackp, YY_NULLPTR);
}

#define YYCHK1(YYE)                             \
  do {                                          \
    switch (YYE) {                              \
    case yyok:     break;                       \
    case yyabort:  goto yyabortlab;             \
    case yyaccept: goto yyacceptlab;            \
    case yyerr:    goto yyuser_error;           \
    case yynomem:  goto yyexhaustedlab;         \
    default:       goto yybuglab;               \
    }                                           \
  } while (0)

/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
  int yyresult;
  yyGLRStack yystack;
  yyGLRStack* const yystackp = &yystack;
  YYPTRDIFF_T yyposn;

  YY_DPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY;
  yylval = yyval_default;

  if (! yyinitGLRStack (yystackp, YYINITDEPTH))
    goto yyexhaustedlab;
  switch (YYSETJMP (yystack.yyexception_buffer))
    {
    case 0: break;
    case 1: goto yyabortlab;
    case 2: goto yyexhaustedlab;
    default: goto yybuglab;
    }
  yyglrShift (&yystack, 0, 0, 0, &yylval);
  yyposn = 0;

  while (yytrue)
    {
      /* For efficiency, we have two loops, the first of which is
         specialized to deterministic operation (single stack, no
         potential ambiguity).  */
      /* Standard mode. */
      while (yytrue)
        {
          yy_state_t yystate = yystack.yytops.yystates[0]->yylrState;
          YY_DPRINTF ((stderr, "Entering state %d\n", yystate));
          if (yystate == YYFINAL)
            goto yyacceptlab;
          if (yyisDefaultedState (yystate))
            {
              yyRuleNum yyrule = yydefaultAction (yystate);
              if (yyrule == 0)
                {
                  yyreportSyntaxError (&yystack);
                  goto yyuser_error;
                }
              YYCHK1 (yyglrReduce (&yystack, 0, yyrule, yytrue));
            }
          else
            {
              yysymbol_kind_t yytoken = yygetToken (&yychar);
              const short* yyconflicts;
              int yyaction = yygetLRActions (yystate, yytoken, &yyconflicts);
              if (*yyconflicts)
                /* Enter nondeterministic mode.  */
                break;
              if (yyisShiftAction (yyaction))
                {
                  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
                  yychar = YYEMPTY;
                  yyposn += 1;
                  yyglrShift (&yystack, 0, yyaction, yyposn, &yylval);
                  if (0 < yystack.yyerrState)
                    yystack.yyerrState -= 1;
                }
              else if (yyisErrorAction (yyaction))
                {
                  /* Issue an error message unless the scanner already
                     did. */
                  if (yychar != YYerror)
                    yyreportSyntaxError (&yystack);
                  goto yyuser_error;
                }
              else
                YYCHK1 (yyglrReduce (&yystack, 0, -yyaction, yytrue));
            }
        }

      /* Nondeterministic mode. */
      while (yytrue)
        {
          yysymbol_kind_t yytoken_to_shift;
          YYPTRDIFF_T yys;

          for (yys = 0; yys < yystack.yytops.yysize; yys += 1)
            yystackp->yytops.yylookaheadNeeds[yys] = yychar != YYEMPTY;

          /* yyprocessOneStack returns one of three things:

              - An error flag.  If the caller is yyprocessOneStack, it
                immediately returns as well.  When the caller is finally
                yyparse, it jumps to an error label via YYCHK1.

              - yyok, but yyprocessOneStack has invoked yymarkStackDeleted
                (&yystack, yys), which sets the top state of yys to NULL.  Thus,
                yyparse's following invocation of yyremoveDeletes will remove
                the stack.

              - yyok, when ready to shift a token.

             Except in the first case, yyparse will invoke yyremoveDeletes and
             then shift the next token onto all remaining stacks.  This
             synchronization of the shift (that is, after all preceding
             reductions on all stacks) helps prevent double destructor calls
             on yylval in the event of memory exhaustion.  */

          for (yys = 0; yys < yystack.yytops.yysize; yys += 1)
            YYCHK1 (yyprocessOneStack (&yystack, yys, yyposn));
          yyremoveDeletes (&yystack);
          if (yystack.yytops.yysize == 0)
            {
              yyundeleteLastStack (&yystack);
              if (yystack.yytops.yysize == 0)
                yyFail (&yystack, YY_("syntax error"));
              YYCHK1 (yyresolveStack (&yystack));
              YY_DPRINTF ((stderr, "Returning to deterministic operation.\n"));
              yyreportSyntaxError (&yystack);
              goto yyuser_error;
            }

          /* If any yyglrShift call fails, it will fail after shifting.  Thus,
             a copy of yylval will already be on stack 0 in the event of a
             failure in the following loop.  Thus, yychar is set to YYEMPTY
             before the loop to make sure the user destructor for yylval isn't
             called twice.  */
          yytoken_to_shift = YYTRANSLATE (yychar);
          yychar = YYEMPTY;
          yyposn += 1;
          for (yys = 0; yys < yystack.yytops.yysize; yys += 1)
            {
              yy_state_t yystate = yystack.yytops.yystates[yys]->yylrState;
              const short* yyconflicts;
              int yyaction = yygetLRActions (yystate, yytoken_to_shift,
                              &yyconflicts);
              /* Note that yyconflicts were handled by yyprocessOneStack.  */
              YY_DPRINTF ((stderr, "On stack %ld, ", YY_CAST (long, yys)));
              YY_SYMBOL_PRINT ("shifting", yytoken_to_shift, &yylval, &yylloc);
              yyglrShift (&yystack, yys, yyaction, yyposn,
                          &yylval);
              YY_DPRINTF ((stderr, "Stack %ld now in state %d\n",
                           YY_CAST (long, yys),
                           yystack.yytops.yystates[yys]->yylrState));
            }

          if (yystack.yytops.yysize == 1)
            {
              YYCHK1 (yyresolveStack (&yystack));
              YY_DPRINTF ((stderr, "Returning to deterministic operation.\n"));
              yycompressStack (&yystack);
              break;
            }
        }
      continue;
    yyuser_error:
      yyrecoverSyntaxError (&yystack);
      yyposn = yystack.yytops.yystates[0]->yyposn;
    }

 yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;

 yybuglab:
  YY_ASSERT (yyfalse);
  goto yyabortlab;

 yyabortlab:
  yyresult = 1;
  goto yyreturnlab;

 yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;

 yyreturnlab:
  if (yychar != YYEMPTY)
    yydestruct ("Cleanup: discarding lookahead",
                YYTRANSLATE (yychar), &yylval);

  /* If the stack is well-formed, pop the stack until it is empty,
     destroying its entries as we go.  But free the stack regardless
     of whether it is well-formed.  */
  if (yystack.yyitems)
    {
      yyGLRState** yystates = yystack.yytops.yystates;
      if (yystates)
        {
          YYPTRDIFF_T yysize = yystack.yytops.yysize;
          YYPTRDIFF_T yyk;
          for (yyk = 0; yyk < yysize; yyk += 1)
            if (yystates[yyk])
              {
                while (yystates[yyk])
                  {
                    yyGLRState *yys = yystates[yyk];
                    if (yys->yypred != YY_NULLPTR)
                      yydestroyGLRState ("Cleanup: popping", yys);
                    yystates[yyk] = yys->yypred;
                    yystack.yynextFree -= 1;
                    yystack.yyspaceLeft += 1;
                  }
                break;
              }
        }
      yyfreeGLRStack (&yystack);
    }

  return yyresult;
}

/* DEBUGGING ONLY */
#if YYDEBUG
/* Print *YYS and its predecessors. */
static void
yy_yypstack (yyGLRState* yys)
{
  if (yys->yypred)
    {
      yy_yypstack (yys->yypred);
      YY_FPRINTF ((stderr, " -> "));
    }
  YY_FPRINTF ((stderr, "%d@%ld", yys->yylrState, YY_CAST (long, yys->yyposn)));
}

/* Print YYS (possibly NULL) and its predecessors. */
static void
yypstates (yyGLRState* yys)
{
  if (yys == YY_NULLPTR)
    YY_FPRINTF ((stderr, "<null>"));
  else
    yy_yypstack (yys);
  YY_FPRINTF ((stderr, "\n"));
}

/* Print the stack #YYK.  */
static void
yypstack (yyGLRStack* yystackp, YYPTRDIFF_T yyk)
{
  yypstates (yystackp->yytops.yystates[yyk]);
}

/* Print all the stacks.  */
static void
yypdumpstack (yyGLRStack* yystackp)
{
#define YYINDEX(YYX)                                                    \
  YY_CAST (long,                                                        \
           ((YYX)                                                       \
            ? YY_REINTERPRET_CAST (yyGLRStackItem*, (YYX)) - yystackp->yyitems \
            : -1))

  yyGLRStackItem* yyp;
  for (yyp = yystackp->yyitems; yyp < yystackp->yynextFree; yyp += 1)
    {
      YY_FPRINTF ((stderr, "%3ld. ",
                   YY_CAST (long, yyp - yystackp->yyitems)));
      if (*YY_REINTERPRET_CAST (yybool *, yyp))
        {
          YY_ASSERT (yyp->yystate.yyisState);
          YY_ASSERT (yyp->yyoption.yyisState);
          YY_FPRINTF ((stderr, "Res: %d, LR State: %d, posn: %ld, pred: %ld",
                       yyp->yystate.yyresolved, yyp->yystate.yylrState,
                       YY_CAST (long, yyp->yystate.yyposn),
                       YYINDEX (yyp->yystate.yypred)));
          if (! yyp->yystate.yyresolved)
            YY_FPRINTF ((stderr, ", firstVal: %ld",
                         YYINDEX (yyp->yystate.yysemantics.yyfirstVal)));
        }
      else
        {
          YY_ASSERT (!yyp->yystate.yyisState);
          YY_ASSERT (!yyp->yyoption.yyisState);
          YY_FPRINTF ((stderr, "Option. rule: %d, state: %ld, next: %ld",
                       yyp->yyoption.yyrule - 1,
                       YYINDEX (yyp->yyoption.yystate),
                       YYINDEX (yyp->yyoption.yynext)));
        }
      YY_FPRINTF ((stderr, "\n"));
    }

  YY_FPRINTF ((stderr, "Tops:"));
  {
    YYPTRDIFF_T yyi;
    for (yyi = 0; yyi < yystackp->yytops.yysize; yyi += 1)
      YY_FPRINTF ((stderr, "%ld: %ld; ", YY_CAST (long, yyi),
                   YYINDEX (yystackp->yytops.yystates[yyi])));
    YY_FPRINTF ((stderr, "\n"));
  }
#undef YYINDEX
}
#endif

#undef yylval
#undef yychar
#undef yynerrs

/* Substitute the variable and function names.  */
#define yyparse dregxparse
#define yylex   dregxlex
#define yyerror dregxerror
#define yylval  dregxlval
#define yychar  dregxchar
#define yydebug dregxdebug
#define yynerrs dregxnerrs


#line 994 "./dregx_parser.y"


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
