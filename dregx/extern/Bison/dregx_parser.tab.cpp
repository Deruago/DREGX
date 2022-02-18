/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1


/* Substitute the variable and function names.  */
#define yyparse         dregxparse
#define yylex           dregxlex
#define yyerror         dregxerror
#define yydebug         dregxdebug
#define yynerrs         dregxnerrs
#define yylval          dregxlval
#define yychar          dregxchar

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
#include "dregx/Ast/Node/deamerreserved_plus__any_letter__.h"
#include "dregx/Ast/Node/opt_pad.h"
#include "dregx/Ast/Node/optional_padding.h"
#include "dregx/Ast/Node/deamerreserved_star__padding__.h"
#include "dregx/Ast/Node/padding.h"
#include "dregx/Ast/Node/special_char_any.h"
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

#line 166 "dregx_parser.tab.c"

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
  YYSYMBOL_NUMBER = 18,                    /* NUMBER  */
  YYSYMBOL_T_ = 19,                        /* T_  */
  YYSYMBOL_N_ = 20,                        /* N_  */
  YYSYMBOL_R_ = 21,                        /* R_  */
  YYSYMBOL_B_ = 22,                        /* B_  */
  YYSYMBOL_V_ = 23,                        /* V_  */
  YYSYMBOL_A_ = 24,                        /* A_  */
  YYSYMBOL_LETTER = 25,                    /* LETTER  */
  YYSYMBOL_SPACE = 26,                     /* SPACE  */
  YYSYMBOL_TAB = 27,                       /* TAB  */
  YYSYMBOL_OTHER = 28,                     /* OTHER  */
  YYSYMBOL_DELETE_ESCAPE_CHARS = 29,       /* DELETE_ESCAPE_CHARS  */
  YYSYMBOL_YYACCEPT = 30,                  /* $accept  */
  YYSYMBOL_program = 31,                   /* program  */
  YYSYMBOL_deamerreserved_star__stmt__ = 32, /* deamerreserved_star__stmt__  */
  YYSYMBOL_stmt = 33,                      /* stmt  */
  YYSYMBOL_word = 34,                      /* word  */
  YYSYMBOL_group = 35,                     /* group  */
  YYSYMBOL_deamerreserved_plus__word__ = 36, /* deamerreserved_plus__word__  */
  YYSYMBOL_or_concat = 37,                 /* or_concat  */
  YYSYMBOL_square = 38,                    /* square  */
  YYSYMBOL_capture = 39,                   /* capture  */
  YYSYMBOL_deamerreserved_plus__capture_logic__ = 40, /* deamerreserved_plus__capture_logic__  */
  YYSYMBOL_capture_logic = 41,             /* capture_logic  */
  YYSYMBOL_capture_symbols = 42,           /* capture_symbols  */
  YYSYMBOL_capture_whitespace = 43,        /* capture_whitespace  */
  YYSYMBOL_capture_range = 44,             /* capture_range  */
  YYSYMBOL_capture_letter_range = 45,      /* capture_letter_range  */
  YYSYMBOL_capture_number_range = 46,      /* capture_number_range  */
  YYSYMBOL_capture_letter = 47,            /* capture_letter  */
  YYSYMBOL_capture_special_character = 48, /* capture_special_character  */
  YYSYMBOL_extension_modifier = 49,        /* extension_modifier  */
  YYSYMBOL_min_repition = 50,              /* min_repition  */
  YYSYMBOL_deamerreserved_plus__NUMBER__ = 51, /* deamerreserved_plus__NUMBER__  */
  YYSYMBOL_max_repition = 52,              /* max_repition  */
  YYSYMBOL_standalone = 53,                /* standalone  */
  YYSYMBOL_deamerreserved_plus__any_letter__ = 54, /* deamerreserved_plus__any_letter__  */
  YYSYMBOL_opt_pad = 55,                   /* opt_pad  */
  YYSYMBOL_optional_padding = 56,          /* optional_padding  */
  YYSYMBOL_deamerreserved_star__padding__ = 57, /* deamerreserved_star__padding__  */
  YYSYMBOL_padding = 58,                   /* padding  */
  YYSYMBOL_special_char_any = 59,          /* special_char_any  */
  YYSYMBOL_any_letter = 60,                /* any_letter  */
  YYSYMBOL_any_letter_exclude_underscore = 61, /* any_letter_exclude_underscore  */
  YYSYMBOL_any = 62                        /* any  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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

#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
# define YYCOPY_NEEDED 1
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  15
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   170

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  30
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  33
/* YYNRULES -- Number of rules.  */
#define YYNRULES  101
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  134

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   284


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
      25,    26,    27,    28,    29
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   223,   223,   234,   240,   250,   260,   266,   272,   282,
     288,   294,   300,   306,   312,   318,   324,   330,   336,   342,
     348,   358,   364,   374,   380,   386,   392,   402,   408,   414,
     420,   430,   436,   446,   452,   462,   468,   474,   480,   486,
     496,   502,   508,   514,   520,   530,   536,   546,   552,   562,
     572,   582,   592,   602,   612,   622,   628,   638,   648,   658,
     664,   674,   684,   694,   700,   710,   716,   726,   736,   742,
     752,   758,   764,   770,   776,   782,   788,   798,   804,   810,
     816,   822,   828,   834,   840,   846,   852,   858,   864,   870,
     876,   882,   888,   894,   900,   906,   912,   918,   924,   930,
     936,   942
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

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
  "SLASH", "OR", "MIN", "UNDERSCORE", "NOT", "PLUS", "STAR", "NUMBER",
  "T_", "N_", "R_", "B_", "V_", "A_", "LETTER", "SPACE", "TAB", "OTHER",
  "DELETE_ESCAPE_CHARS", "$accept", "program",
  "deamerreserved_star__stmt__", "stmt", "word", "group",
  "deamerreserved_plus__word__", "or_concat", "square", "capture",
  "deamerreserved_plus__capture_logic__", "capture_logic",
  "capture_symbols", "capture_whitespace", "capture_range",
  "capture_letter_range", "capture_number_range", "capture_letter",
  "capture_special_character", "extension_modifier", "min_repition",
  "deamerreserved_plus__NUMBER__", "max_repition", "standalone",
  "deamerreserved_plus__any_letter__", "opt_pad", "optional_padding",
  "deamerreserved_star__padding__", "padding", "special_char_any",
  "any_letter", "any_letter_exclude_underscore", "any", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-103)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-65)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       8,  -103,  -103,    16,  -103,     8,  -103,  -103,  -103,    86,
    -103,   102,  -103,  -103,    14,  -103,  -103,  -103,  -103,  -103,
       6,    14,   142,   142,  -103,  -103,  -103,  -103,  -103,  -103,
    -103,  -103,  -103,    25,  -103,  -103,    14,    11,    -7,    14,
      14,    -7,  -103,    51,  -103,  -103,  -103,    29,  -103,  -103,
    -103,    36,   142,  -103,  -103,  -103,  -103,  -103,  -103,  -103,
    -103,  -103,    38,    45,  -103,    14,     3,  -103,    41,    83,
      91,     5,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,
    -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,
    -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,    72,  -103,
    -103,    61,  -103,    96,     3,  -103,    14,   120,   122,   124,
      14,  -103,  -103,    14,  -103,  -103,  -103,     7,  -103,  -103,
    -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,    14,
       3,     9,  -103,  -103
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
      64,    65,    66,     0,     2,    64,     5,     6,     7,    30,
       8,     0,    61,    62,    64,     1,     3,    28,    29,    27,
       0,    64,     0,     0,    69,    70,    72,    71,    73,    74,
      75,    76,    58,    59,    68,    63,    64,    64,     6,    64,
      64,     7,    43,     0,    44,    41,    42,     0,    45,    46,
      40,     0,    33,    39,    38,    35,    47,    48,    37,    36,
      52,    51,    68,     0,    60,    64,     0,    22,     0,     0,
       0,     0,    77,    78,    79,    80,    81,    82,    83,   101,
      84,    85,    86,    87,    98,    99,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,   100,    67,     0,    31,
      34,     0,    32,     0,    55,    54,    64,    20,    12,    16,
      64,    50,    49,    64,    56,    23,    24,     0,    18,    17,
      19,    10,     9,    11,    14,    13,    15,    25,    26,    64,
       0,     0,    57,    53
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -103,  -103,   104,  -103,   -15,   -18,    59,  -103,   -17,  -103,
     -16,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,   -83,
    -103,  -102,  -103,  -103,    77,    -9,  -103,    97,  -103,  -103,
       0,   -10,  -103
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     3,     4,     5,     6,     7,    39,    40,     8,     9,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    19,
      65,   105,   129,    10,    32,    11,    12,    13,    14,    60,
      61,    62,    97
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      20,    34,   114,    38,    41,   -64,    37,    63,    -4,   109,
      21,    33,    22,    23,    36,   -21,    15,   110,   133,     1,
       2,   104,    37,    34,   120,   123,   126,    66,   132,    68,
      69,    70,    71,    33,     1,     2,   100,     1,     2,    24,
       1,     2,    98,    99,    25,    26,    27,    28,    29,    30,
      31,   101,   102,   106,    72,    73,   103,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      25,    26,    27,    28,    29,    30,    31,   107,   115,   116,
     111,   112,   127,   128,   -64,   108,    67,   117,    20,    20,
      20,   117,    17,    18,   130,    21,   113,    22,    23,    16,
      64,    35,     1,     2,     0,     0,    24,     0,     0,     0,
     131,    25,    26,    27,    28,    29,    30,    31,   -64,     0,
     -64,     0,   -64,     0,     0,     0,   118,   119,   121,   122,
     124,   125,     0,     0,     0,     0,     1,     2,     1,     2,
       1,     2,    42,    43,    44,     0,    24,     0,    45,    46,
      47,    25,    26,    27,    28,    29,    30,    31,    48,    49,
      50
};

static const yytype_int16 yycheck[] =
{
       9,    11,   104,    21,    21,    12,    21,    23,     0,     4,
       3,    11,     5,     6,     8,     4,     0,    12,     9,    26,
      27,    18,    37,    33,   107,   108,   109,    36,   130,    38,
      39,    40,    41,    33,    26,    27,    52,    26,    27,    14,
      26,    27,    13,     7,    19,    20,    21,    22,    23,    24,
      25,    13,     7,    12,     3,     4,    65,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      19,    20,    21,    22,    23,    24,    25,     4,   106,   106,
      18,   101,   110,   110,     8,     4,    37,   106,   107,   108,
     109,   110,    16,    17,   113,     3,    10,     5,     6,     5,
      33,    14,    26,    27,    -1,    -1,    14,    -1,    -1,    -1,
     129,    19,    20,    21,    22,    23,    24,    25,     8,    -1,
       8,    -1,     8,    -1,    -1,    -1,    16,    17,    16,    17,
      16,    17,    -1,    -1,    -1,    -1,    26,    27,    26,    27,
      26,    27,    10,    11,    12,    -1,    14,    -1,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    26,    27,    31,    32,    33,    34,    35,    38,    39,
      53,    55,    56,    57,    58,     0,    32,    16,    17,    49,
      55,     3,     5,     6,    14,    19,    20,    21,    22,    23,
      24,    25,    54,    60,    61,    57,     8,    34,    35,    36,
      37,    38,    10,    11,    12,    16,    17,    18,    26,    27,
      28,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      59,    60,    61,    40,    54,    50,    55,    36,    55,    55,
      55,    55,     3,     4,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    62,    13,     7,
      40,    13,     7,    55,    18,    51,    12,     4,     4,     4,
      12,    18,    61,    10,    51,    35,    38,    55,    16,    17,
      49,    16,    17,    49,    16,    17,    49,    35,    38,    52,
      55,    55,    51,     9
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    30,    31,    32,    32,    33,    34,    34,    34,    35,
      35,    35,    35,    35,    35,    35,    35,    35,    35,    35,
      35,    36,    36,    37,    37,    37,    37,    38,    38,    38,
      38,    39,    39,    40,    40,    41,    41,    41,    41,    41,
      42,    42,    42,    42,    42,    43,    43,    44,    44,    45,
      46,    47,    48,    49,    50,    51,    51,    52,    53,    54,
      54,    55,    56,    57,    57,    58,    58,    59,    60,    60,
      61,    61,    61,    61,    61,    61,    61,    62,    62,    62,
      62,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    62
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     1,     1,     1,     1,     6,
       6,     6,     5,     6,     6,     6,     5,     6,     6,     6,
       5,     1,     2,     4,     4,     4,     4,     2,     2,     2,
       1,     4,     4,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       3,     1,     1,     8,     2,     1,     2,     2,     2,     1,
       2,     1,     1,     2,     0,     1,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        YY_LAC_DISCARD ("YYBACKUP");                              \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
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

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


/* Given a state stack such that *YYBOTTOM is its bottom, such that
   *YYTOP is either its top or is YYTOP_EMPTY to indicate an empty
   stack, and such that *YYCAPACITY is the maximum number of elements it
   can hold without a reallocation, make sure there is enough room to
   store YYADD more elements.  If not, allocate a new stack using
   YYSTACK_ALLOC, copy the existing elements, and adjust *YYBOTTOM,
   *YYTOP, and *YYCAPACITY to reflect the new capacity and memory
   location.  If *YYBOTTOM != YYBOTTOM_NO_FREE, then free the old stack
   using YYSTACK_FREE.  Return 0 if successful or if no reallocation is
   required.  Return YYENOMEM if memory is exhausted.  */
static int
yy_lac_stack_realloc (YYPTRDIFF_T *yycapacity, YYPTRDIFF_T yyadd,
#if YYDEBUG
                      char const *yydebug_prefix,
                      char const *yydebug_suffix,
#endif
                      yy_state_t **yybottom,
                      yy_state_t *yybottom_no_free,
                      yy_state_t **yytop, yy_state_t *yytop_empty)
{
  YYPTRDIFF_T yysize_old =
    *yytop == yytop_empty ? 0 : *yytop - *yybottom + 1;
  YYPTRDIFF_T yysize_new = yysize_old + yyadd;
  if (*yycapacity < yysize_new)
    {
      YYPTRDIFF_T yyalloc = 2 * yysize_new;
      yy_state_t *yybottom_new;
      /* Use YYMAXDEPTH for maximum stack size given that the stack
         should never need to grow larger than the main state stack
         needs to grow without LAC.  */
      if (YYMAXDEPTH < yysize_new)
        {
          YYDPRINTF ((stderr, "%smax size exceeded%s", yydebug_prefix,
                      yydebug_suffix));
          return YYENOMEM;
        }
      if (YYMAXDEPTH < yyalloc)
        yyalloc = YYMAXDEPTH;
      yybottom_new =
        YY_CAST (yy_state_t *,
                 YYSTACK_ALLOC (YY_CAST (YYSIZE_T,
                                         yyalloc * YYSIZEOF (*yybottom_new))));
      if (!yybottom_new)
        {
          YYDPRINTF ((stderr, "%srealloc failed%s", yydebug_prefix,
                      yydebug_suffix));
          return YYENOMEM;
        }
      if (*yytop != yytop_empty)
        {
          YYCOPY (yybottom_new, *yybottom, yysize_old);
          *yytop = yybottom_new + (yysize_old - 1);
        }
      if (*yybottom != yybottom_no_free)
        YYSTACK_FREE (*yybottom);
      *yybottom = yybottom_new;
      *yycapacity = yyalloc;
    }
  return 0;
}

/* Establish the initial context for the current lookahead if no initial
   context is currently established.

   We define a context as a snapshot of the parser stacks.  We define
   the initial context for a lookahead as the context in which the
   parser initially examines that lookahead in order to select a
   syntactic action.  Thus, if the lookahead eventually proves
   syntactically unacceptable (possibly in a later context reached via a
   series of reductions), the initial context can be used to determine
   the exact set of tokens that would be syntactically acceptable in the
   lookahead's place.  Moreover, it is the context after which any
   further semantic actions would be erroneous because they would be
   determined by a syntactically unacceptable token.

   YY_LAC_ESTABLISH should be invoked when a reduction is about to be
   performed in an inconsistent state (which, for the purposes of LAC,
   includes consistent states that don't know they're consistent because
   their default reductions have been disabled).  Iff there is a
   lookahead token, it should also be invoked before reporting a syntax
   error.  This latter case is for the sake of the debugging output.

   For parse.lac=full, the implementation of YY_LAC_ESTABLISH is as
   follows.  If no initial context is currently established for the
   current lookahead, then check if that lookahead can eventually be
   shifted if syntactic actions continue from the current context.
   Report a syntax error if it cannot.  */
#define YY_LAC_ESTABLISH                                                \
do {                                                                    \
  if (!yy_lac_established)                                              \
    {                                                                   \
      YYDPRINTF ((stderr,                                               \
                  "LAC: initial context established for %s\n",          \
                  yysymbol_name (yytoken)));                            \
      yy_lac_established = 1;                                           \
      switch (yy_lac (yyesa, &yyes, &yyes_capacity, yyssp, yytoken))    \
        {                                                               \
        case YYENOMEM:                                                  \
          YYNOMEM;                                                      \
        case 1:                                                         \
          goto yyerrlab;                                                \
        }                                                               \
    }                                                                   \
} while (0)

/* Discard any previous initial lookahead context because of Event,
   which may be a lookahead change or an invalidation of the currently
   established initial context for the current lookahead.

   The most common example of a lookahead change is a shift.  An example
   of both cases is syntax error recovery.  That is, a syntax error
   occurs when the lookahead is syntactically erroneous for the
   currently established initial context, so error recovery manipulates
   the parser stacks to try to find a new initial context in which the
   current lookahead is syntactically acceptable.  If it fails to find
   such a context, it discards the lookahead.  */
#if YYDEBUG
# define YY_LAC_DISCARD(Event)                                           \
do {                                                                     \
  if (yy_lac_established)                                                \
    {                                                                    \
      YYDPRINTF ((stderr, "LAC: initial context discarded due to "       \
                  Event "\n"));                                          \
      yy_lac_established = 0;                                            \
    }                                                                    \
} while (0)
#else
# define YY_LAC_DISCARD(Event) yy_lac_established = 0
#endif

/* Given the stack whose top is *YYSSP, return 0 iff YYTOKEN can
   eventually (after perhaps some reductions) be shifted, return 1 if
   not, or return YYENOMEM if memory is exhausted.  As preconditions and
   postconditions: *YYES_CAPACITY is the allocated size of the array to
   which *YYES points, and either *YYES = YYESA or *YYES points to an
   array allocated with YYSTACK_ALLOC.  yy_lac may overwrite the
   contents of either array, alter *YYES and *YYES_CAPACITY, and free
   any old *YYES other than YYESA.  */
static int
yy_lac (yy_state_t *yyesa, yy_state_t **yyes,
        YYPTRDIFF_T *yyes_capacity, yy_state_t *yyssp, yysymbol_kind_t yytoken)
{
  yy_state_t *yyes_prev = yyssp;
  yy_state_t *yyesp = yyes_prev;
  /* Reduce until we encounter a shift and thereby accept the token.  */
  YYDPRINTF ((stderr, "LAC: checking lookahead %s:", yysymbol_name (yytoken)));
  if (yytoken == YYSYMBOL_YYUNDEF)
    {
      YYDPRINTF ((stderr, " Always Err\n"));
      return 1;
    }
  while (1)
    {
      int yyrule = yypact[+*yyesp];
      if (yypact_value_is_default (yyrule)
          || (yyrule += yytoken) < 0 || YYLAST < yyrule
          || yycheck[yyrule] != yytoken)
        {
          /* Use the default action.  */
          yyrule = yydefact[+*yyesp];
          if (yyrule == 0)
            {
              YYDPRINTF ((stderr, " Err\n"));
              return 1;
            }
        }
      else
        {
          /* Use the action from yytable.  */
          yyrule = yytable[yyrule];
          if (yytable_value_is_error (yyrule))
            {
              YYDPRINTF ((stderr, " Err\n"));
              return 1;
            }
          if (0 < yyrule)
            {
              YYDPRINTF ((stderr, " S%d\n", yyrule));
              return 0;
            }
          yyrule = -yyrule;
        }
      /* By now we know we have to simulate a reduce.  */
      YYDPRINTF ((stderr, " R%d", yyrule - 1));
      {
        /* Pop the corresponding number of values from the stack.  */
        YYPTRDIFF_T yylen = yyr2[yyrule];
        /* First pop from the LAC stack as many tokens as possible.  */
        if (yyesp != yyes_prev)
          {
            YYPTRDIFF_T yysize = yyesp - *yyes + 1;
            if (yylen < yysize)
              {
                yyesp -= yylen;
                yylen = 0;
              }
            else
              {
                yyesp = yyes_prev;
                yylen -= yysize;
              }
          }
        /* Only afterwards look at the main stack.  */
        if (yylen)
          yyesp = yyes_prev -= yylen;
      }
      /* Push the resulting state of the reduction.  */
      {
        yy_state_fast_t yystate;
        {
          const int yylhs = yyr1[yyrule] - YYNTOKENS;
          const int yyi = yypgoto[yylhs] + *yyesp;
          yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyesp
                     ? yytable[yyi]
                     : yydefgoto[yylhs]);
        }
        if (yyesp == yyes_prev)
          {
            yyesp = *yyes;
            YY_IGNORE_USELESS_CAST_BEGIN
            *yyesp = YY_CAST (yy_state_t, yystate);
            YY_IGNORE_USELESS_CAST_END
          }
        else
          {
            if (yy_lac_stack_realloc (yyes_capacity, 1,
#if YYDEBUG
                                      " (", ")",
#endif
                                      yyes, yyesa, &yyesp, yyes_prev))
              {
                YYDPRINTF ((stderr, "\n"));
                return YYENOMEM;
              }
            YY_IGNORE_USELESS_CAST_BEGIN
            *++yyesp = YY_CAST (yy_state_t, yystate);
            YY_IGNORE_USELESS_CAST_END
          }
        YYDPRINTF ((stderr, " G%d", yystate));
      }
    }
}

/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yy_state_t *yyesa;
  yy_state_t **yyes;
  YYPTRDIFF_T *yyes_capacity;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;

  int yyx;
  for (yyx = 0; yyx < YYNTOKENS; ++yyx)
    {
      yysymbol_kind_t yysym = YY_CAST (yysymbol_kind_t, yyx);
      if (yysym != YYSYMBOL_YYerror && yysym != YYSYMBOL_YYUNDEF)
        switch (yy_lac (yyctx->yyesa, yyctx->yyes, yyctx->yyes_capacity, yyctx->yyssp, yysym))
          {
          case YYENOMEM:
            return YYENOMEM;
          case 1:
            continue;
          default:
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = yysym;
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
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


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
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
       In the first two cases, it might appear that the current syntax
       error should have been detected in the previous state when yy_lac
       was invoked.  However, at that time, there might have been a
       different syntax error that discarded a different initial context
       during error recovery, leaving behind the current lookahead.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      YYDPRINTF ((stderr, "Constructing syntax error message\n"));
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else if (yyn == 0)
        YYDPRINTF ((stderr, "No expected tokens.\n"));
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.  In order to see if a particular token T is a
   valid looakhead, invoke yy_lac (YYESA, YYES, YYES_CAPACITY, YYSSP, T).

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store or if
   yy_lac returned YYENOMEM.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
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
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
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
  return 0;
}


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


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

    yy_state_t yyesa[20];
    yy_state_t *yyes = yyesa;
    YYPTRDIFF_T yyes_capacity = 20 < YYMAXDEPTH ? 20 : YYMAXDEPTH;

  /* Whether LAC context is established.  A Boolean.  */
  int yy_lac_established = 0;
  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    {
      YY_LAC_ESTABLISH;
      goto yydefault;
    }
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      YY_LAC_ESTABLISH;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  YY_LAC_DISCARD ("shift");
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  {
    int yychar_backup = yychar;
    switch (yyn)
      {
  case 2: /* program: deamerreserved_star__stmt__  */
#line 223 "./dregx_parser.y"
                                     {
		auto* const newNode = new dregx::ast::node::program({::dregx::ast::Type::program, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (yyvsp[0].dregx_deamerreserved_star__stmt__) });
		(yyval.dregx_program) = newNode;

		// Ignored, Deleted, tokens are deleted
		outputTree = new ::deamer::external::cpp::ast::Tree(newNode);
	}
#line 1840 "dregx_parser.tab.c"
    break;

  case 3: /* deamerreserved_star__stmt__: stmt deamerreserved_star__stmt__  */
#line 234 "./dregx_parser.y"
                                          {
		auto* const newNode = new dregx::ast::node::deamerreserved_star__stmt__({::dregx::ast::Type::deamerreserved_star__stmt__, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, { (yyvsp[-1].dregx_stmt), (yyvsp[0].dregx_deamerreserved_star__stmt__) });
		(yyval.dregx_deamerreserved_star__stmt__) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 1851 "dregx_parser.tab.c"
    break;

  case 4: /* deamerreserved_star__stmt__: %empty  */
#line 240 "./dregx_parser.y"
           {
		auto* const newNode = new dregx::ast::node::deamerreserved_star__stmt__({::dregx::ast::Type::deamerreserved_star__stmt__, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, {  });
		(yyval.dregx_deamerreserved_star__stmt__) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 1862 "dregx_parser.tab.c"
    break;

  case 5: /* stmt: word  */
#line 250 "./dregx_parser.y"
              {
		auto* const newNode = new dregx::ast::node::stmt({::dregx::ast::Type::stmt, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (yyvsp[0].dregx_word) });
		(yyval.dregx_stmt) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 1873 "dregx_parser.tab.c"
    break;

  case 6: /* word: group  */
#line 260 "./dregx_parser.y"
               {
		auto* const newNode = new dregx::ast::node::word({::dregx::ast::Type::word, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (yyvsp[0].dregx_group) });
		(yyval.dregx_word) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 1884 "dregx_parser.tab.c"
    break;

  case 7: /* word: square  */
#line 266 "./dregx_parser.y"
                  {
		auto* const newNode = new dregx::ast::node::word({::dregx::ast::Type::word, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (yyvsp[0].dregx_square) });
		(yyval.dregx_word) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 1895 "dregx_parser.tab.c"
    break;

  case 8: /* word: standalone  */
#line 272 "./dregx_parser.y"
                      {
		auto* const newNode = new dregx::ast::node::word({::dregx::ast::Type::word, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 2, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (yyvsp[0].dregx_standalone) });
		(yyval.dregx_word) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 1906 "dregx_parser.tab.c"
    break;

  case 9: /* group: opt_pad LEFT_CURLY_BRACKET or_concat opt_pad RIGHT_CURLY_BRACKET STAR  */
#line 282 "./dregx_parser.y"
                                                                               {
		auto* const newNode = new dregx::ast::node::group({::dregx::ast::Type::group, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (yyvsp[-5].dregx_opt_pad), new dregx::ast::node::LEFT_CURLY_BRACKET({::dregx::ast::Type::LEFT_CURLY_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[-4].Terminal) }), (yyvsp[-3].dregx_or_concat), (yyvsp[-2].dregx_opt_pad), new dregx::ast::node::RIGHT_CURLY_BRACKET({::dregx::ast::Type::RIGHT_CURLY_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[-1].Terminal) }), new dregx::ast::node::STAR({::dregx::ast::Type::STAR, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[0].Terminal) }) });
		(yyval.dregx_group) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 1917 "dregx_parser.tab.c"
    break;

  case 10: /* group: opt_pad LEFT_CURLY_BRACKET or_concat opt_pad RIGHT_CURLY_BRACKET PLUS  */
#line 288 "./dregx_parser.y"
                                                                                 {
		auto* const newNode = new dregx::ast::node::group({::dregx::ast::Type::group, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (yyvsp[-5].dregx_opt_pad), new dregx::ast::node::LEFT_CURLY_BRACKET({::dregx::ast::Type::LEFT_CURLY_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[-4].Terminal) }), (yyvsp[-3].dregx_or_concat), (yyvsp[-2].dregx_opt_pad), new dregx::ast::node::RIGHT_CURLY_BRACKET({::dregx::ast::Type::RIGHT_CURLY_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[-1].Terminal) }), new dregx::ast::node::PLUS({::dregx::ast::Type::PLUS, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[0].Terminal) }) });
		(yyval.dregx_group) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 1928 "dregx_parser.tab.c"
    break;

  case 11: /* group: opt_pad LEFT_CURLY_BRACKET or_concat opt_pad RIGHT_CURLY_BRACKET extension_modifier  */
#line 294 "./dregx_parser.y"
                                                                                               {
		auto* const newNode = new dregx::ast::node::group({::dregx::ast::Type::group, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 2, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (yyvsp[-5].dregx_opt_pad), new dregx::ast::node::LEFT_CURLY_BRACKET({::dregx::ast::Type::LEFT_CURLY_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[-4].Terminal) }), (yyvsp[-3].dregx_or_concat), (yyvsp[-2].dregx_opt_pad), new dregx::ast::node::RIGHT_CURLY_BRACKET({::dregx::ast::Type::RIGHT_CURLY_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[-1].Terminal) }), (yyvsp[0].dregx_extension_modifier) });
		(yyval.dregx_group) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 1939 "dregx_parser.tab.c"
    break;

  case 12: /* group: opt_pad LEFT_CURLY_BRACKET or_concat opt_pad RIGHT_CURLY_BRACKET  */
#line 300 "./dregx_parser.y"
                                                                            {
		auto* const newNode = new dregx::ast::node::group({::dregx::ast::Type::group, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 3, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (yyvsp[-4].dregx_opt_pad), new dregx::ast::node::LEFT_CURLY_BRACKET({::dregx::ast::Type::LEFT_CURLY_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[-3].Terminal) }), (yyvsp[-2].dregx_or_concat), (yyvsp[-1].dregx_opt_pad), new dregx::ast::node::RIGHT_CURLY_BRACKET({::dregx::ast::Type::RIGHT_CURLY_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[0].Terminal) }) });
		(yyval.dregx_group) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 1950 "dregx_parser.tab.c"
    break;

  case 13: /* group: opt_pad LEFT_CURLY_BRACKET square opt_pad RIGHT_CURLY_BRACKET STAR  */
#line 306 "./dregx_parser.y"
                                                                              {
		auto* const newNode = new dregx::ast::node::group({::dregx::ast::Type::group, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 4, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (yyvsp[-5].dregx_opt_pad), new dregx::ast::node::LEFT_CURLY_BRACKET({::dregx::ast::Type::LEFT_CURLY_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[-4].Terminal) }), (yyvsp[-3].dregx_square), (yyvsp[-2].dregx_opt_pad), new dregx::ast::node::RIGHT_CURLY_BRACKET({::dregx::ast::Type::RIGHT_CURLY_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[-1].Terminal) }), new dregx::ast::node::STAR({::dregx::ast::Type::STAR, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[0].Terminal) }) });
		(yyval.dregx_group) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 1961 "dregx_parser.tab.c"
    break;

  case 14: /* group: opt_pad LEFT_CURLY_BRACKET square opt_pad RIGHT_CURLY_BRACKET PLUS  */
#line 312 "./dregx_parser.y"
                                                                              {
		auto* const newNode = new dregx::ast::node::group({::dregx::ast::Type::group, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 5, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (yyvsp[-5].dregx_opt_pad), new dregx::ast::node::LEFT_CURLY_BRACKET({::dregx::ast::Type::LEFT_CURLY_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[-4].Terminal) }), (yyvsp[-3].dregx_square), (yyvsp[-2].dregx_opt_pad), new dregx::ast::node::RIGHT_CURLY_BRACKET({::dregx::ast::Type::RIGHT_CURLY_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[-1].Terminal) }), new dregx::ast::node::PLUS({::dregx::ast::Type::PLUS, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[0].Terminal) }) });
		(yyval.dregx_group) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 1972 "dregx_parser.tab.c"
    break;

  case 15: /* group: opt_pad LEFT_CURLY_BRACKET square opt_pad RIGHT_CURLY_BRACKET extension_modifier  */
#line 318 "./dregx_parser.y"
                                                                                            {
		auto* const newNode = new dregx::ast::node::group({::dregx::ast::Type::group, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 6, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (yyvsp[-5].dregx_opt_pad), new dregx::ast::node::LEFT_CURLY_BRACKET({::dregx::ast::Type::LEFT_CURLY_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[-4].Terminal) }), (yyvsp[-3].dregx_square), (yyvsp[-2].dregx_opt_pad), new dregx::ast::node::RIGHT_CURLY_BRACKET({::dregx::ast::Type::RIGHT_CURLY_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[-1].Terminal) }), (yyvsp[0].dregx_extension_modifier) });
		(yyval.dregx_group) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 1983 "dregx_parser.tab.c"
    break;

  case 16: /* group: opt_pad LEFT_CURLY_BRACKET square opt_pad RIGHT_CURLY_BRACKET  */
#line 324 "./dregx_parser.y"
                                                                         {
		auto* const newNode = new dregx::ast::node::group({::dregx::ast::Type::group, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 7, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (yyvsp[-4].dregx_opt_pad), new dregx::ast::node::LEFT_CURLY_BRACKET({::dregx::ast::Type::LEFT_CURLY_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[-3].Terminal) }), (yyvsp[-2].dregx_square), (yyvsp[-1].dregx_opt_pad), new dregx::ast::node::RIGHT_CURLY_BRACKET({::dregx::ast::Type::RIGHT_CURLY_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[0].Terminal) }) });
		(yyval.dregx_group) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 1994 "dregx_parser.tab.c"
    break;

  case 17: /* group: opt_pad LEFT_CURLY_BRACKET deamerreserved_plus__word__ opt_pad RIGHT_CURLY_BRACKET STAR  */
#line 330 "./dregx_parser.y"
                                                                                                   {
		auto* const newNode = new dregx::ast::node::group({::dregx::ast::Type::group, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 8, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (yyvsp[-5].dregx_opt_pad), new dregx::ast::node::LEFT_CURLY_BRACKET({::dregx::ast::Type::LEFT_CURLY_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[-4].Terminal) }), (yyvsp[-3].dregx_deamerreserved_plus__word__), (yyvsp[-2].dregx_opt_pad), new dregx::ast::node::RIGHT_CURLY_BRACKET({::dregx::ast::Type::RIGHT_CURLY_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[-1].Terminal) }), new dregx::ast::node::STAR({::dregx::ast::Type::STAR, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[0].Terminal) }) });
		(yyval.dregx_group) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2005 "dregx_parser.tab.c"
    break;

  case 18: /* group: opt_pad LEFT_CURLY_BRACKET deamerreserved_plus__word__ opt_pad RIGHT_CURLY_BRACKET PLUS  */
#line 336 "./dregx_parser.y"
                                                                                                   {
		auto* const newNode = new dregx::ast::node::group({::dregx::ast::Type::group, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 9, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (yyvsp[-5].dregx_opt_pad), new dregx::ast::node::LEFT_CURLY_BRACKET({::dregx::ast::Type::LEFT_CURLY_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[-4].Terminal) }), (yyvsp[-3].dregx_deamerreserved_plus__word__), (yyvsp[-2].dregx_opt_pad), new dregx::ast::node::RIGHT_CURLY_BRACKET({::dregx::ast::Type::RIGHT_CURLY_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[-1].Terminal) }), new dregx::ast::node::PLUS({::dregx::ast::Type::PLUS, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[0].Terminal) }) });
		(yyval.dregx_group) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2016 "dregx_parser.tab.c"
    break;

  case 19: /* group: opt_pad LEFT_CURLY_BRACKET deamerreserved_plus__word__ opt_pad RIGHT_CURLY_BRACKET extension_modifier  */
#line 342 "./dregx_parser.y"
                                                                                                                 {
		auto* const newNode = new dregx::ast::node::group({::dregx::ast::Type::group, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 10, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (yyvsp[-5].dregx_opt_pad), new dregx::ast::node::LEFT_CURLY_BRACKET({::dregx::ast::Type::LEFT_CURLY_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[-4].Terminal) }), (yyvsp[-3].dregx_deamerreserved_plus__word__), (yyvsp[-2].dregx_opt_pad), new dregx::ast::node::RIGHT_CURLY_BRACKET({::dregx::ast::Type::RIGHT_CURLY_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[-1].Terminal) }), (yyvsp[0].dregx_extension_modifier) });
		(yyval.dregx_group) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2027 "dregx_parser.tab.c"
    break;

  case 20: /* group: opt_pad LEFT_CURLY_BRACKET deamerreserved_plus__word__ opt_pad RIGHT_CURLY_BRACKET  */
#line 348 "./dregx_parser.y"
                                                                                              {
		auto* const newNode = new dregx::ast::node::group({::dregx::ast::Type::group, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 11, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (yyvsp[-4].dregx_opt_pad), new dregx::ast::node::LEFT_CURLY_BRACKET({::dregx::ast::Type::LEFT_CURLY_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[-3].Terminal) }), (yyvsp[-2].dregx_deamerreserved_plus__word__), (yyvsp[-1].dregx_opt_pad), new dregx::ast::node::RIGHT_CURLY_BRACKET({::dregx::ast::Type::RIGHT_CURLY_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[0].Terminal) }) });
		(yyval.dregx_group) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2038 "dregx_parser.tab.c"
    break;

  case 21: /* deamerreserved_plus__word__: word  */
#line 358 "./dregx_parser.y"
              {
		auto* const newNode = new dregx::ast::node::deamerreserved_plus__word__({::dregx::ast::Type::deamerreserved_plus__word__, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, { (yyvsp[0].dregx_word) });
		(yyval.dregx_deamerreserved_plus__word__) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2049 "dregx_parser.tab.c"
    break;

  case 22: /* deamerreserved_plus__word__: word deamerreserved_plus__word__  */
#line 364 "./dregx_parser.y"
                                            {
		auto* const newNode = new dregx::ast::node::deamerreserved_plus__word__({::dregx::ast::Type::deamerreserved_plus__word__, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, { (yyvsp[-1].dregx_word), (yyvsp[0].dregx_deamerreserved_plus__word__) });
		(yyval.dregx_deamerreserved_plus__word__) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2060 "dregx_parser.tab.c"
    break;

  case 23: /* or_concat: group opt_pad OR group  */
#line 374 "./dregx_parser.y"
                                {
		auto* const newNode = new dregx::ast::node::or_concat({::dregx::ast::Type::or_concat, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (yyvsp[-3].dregx_group), (yyvsp[-2].dregx_opt_pad), new dregx::ast::node::OR({::dregx::ast::Type::OR, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[-1].Terminal) }), (yyvsp[0].dregx_group) });
		(yyval.dregx_or_concat) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2071 "dregx_parser.tab.c"
    break;

  case 24: /* or_concat: group opt_pad OR square  */
#line 380 "./dregx_parser.y"
                                   {
		auto* const newNode = new dregx::ast::node::or_concat({::dregx::ast::Type::or_concat, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (yyvsp[-3].dregx_group), (yyvsp[-2].dregx_opt_pad), new dregx::ast::node::OR({::dregx::ast::Type::OR, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[-1].Terminal) }), (yyvsp[0].dregx_square) });
		(yyval.dregx_or_concat) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2082 "dregx_parser.tab.c"
    break;

  case 25: /* or_concat: square opt_pad OR group  */
#line 386 "./dregx_parser.y"
                                   {
		auto* const newNode = new dregx::ast::node::or_concat({::dregx::ast::Type::or_concat, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 2, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (yyvsp[-3].dregx_square), (yyvsp[-2].dregx_opt_pad), new dregx::ast::node::OR({::dregx::ast::Type::OR, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[-1].Terminal) }), (yyvsp[0].dregx_group) });
		(yyval.dregx_or_concat) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2093 "dregx_parser.tab.c"
    break;

  case 26: /* or_concat: square opt_pad OR square  */
#line 392 "./dregx_parser.y"
                                    {
		auto* const newNode = new dregx::ast::node::or_concat({::dregx::ast::Type::or_concat, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 3, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (yyvsp[-3].dregx_square), (yyvsp[-2].dregx_opt_pad), new dregx::ast::node::OR({::dregx::ast::Type::OR, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[-1].Terminal) }), (yyvsp[0].dregx_square) });
		(yyval.dregx_or_concat) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2104 "dregx_parser.tab.c"
    break;

  case 27: /* square: capture extension_modifier  */
#line 402 "./dregx_parser.y"
                                    {
		auto* const newNode = new dregx::ast::node::square({::dregx::ast::Type::square, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (yyvsp[-1].dregx_capture), (yyvsp[0].dregx_extension_modifier) });
		(yyval.dregx_square) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2115 "dregx_parser.tab.c"
    break;

  case 28: /* square: capture PLUS  */
#line 408 "./dregx_parser.y"
                        {
		auto* const newNode = new dregx::ast::node::square({::dregx::ast::Type::square, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (yyvsp[-1].dregx_capture), new dregx::ast::node::PLUS({::dregx::ast::Type::PLUS, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[0].Terminal) }) });
		(yyval.dregx_square) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2126 "dregx_parser.tab.c"
    break;

  case 29: /* square: capture STAR  */
#line 414 "./dregx_parser.y"
                        {
		auto* const newNode = new dregx::ast::node::square({::dregx::ast::Type::square, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 2, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (yyvsp[-1].dregx_capture), new dregx::ast::node::STAR({::dregx::ast::Type::STAR, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[0].Terminal) }) });
		(yyval.dregx_square) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2137 "dregx_parser.tab.c"
    break;

  case 30: /* square: capture  */
#line 420 "./dregx_parser.y"
                   {
		auto* const newNode = new dregx::ast::node::square({::dregx::ast::Type::square, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 3, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (yyvsp[0].dregx_capture) });
		(yyval.dregx_square) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2148 "dregx_parser.tab.c"
    break;

  case 31: /* capture: opt_pad LEFT_SQUARE_BRACKET_NOT deamerreserved_plus__capture_logic__ RIGHT_SQUARE_BRACKET  */
#line 430 "./dregx_parser.y"
                                                                                                   {
		auto* const newNode = new dregx::ast::node::capture({::dregx::ast::Type::capture, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (yyvsp[-3].dregx_opt_pad), new dregx::ast::node::LEFT_SQUARE_BRACKET_NOT({::dregx::ast::Type::LEFT_SQUARE_BRACKET_NOT, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[-2].Terminal) }), (yyvsp[-1].dregx_deamerreserved_plus__capture_logic__), new dregx::ast::node::RIGHT_SQUARE_BRACKET({::dregx::ast::Type::RIGHT_SQUARE_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[0].Terminal) }) });
		(yyval.dregx_capture) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2159 "dregx_parser.tab.c"
    break;

  case 32: /* capture: opt_pad LEFT_SQUARE_BRACKET deamerreserved_plus__capture_logic__ RIGHT_SQUARE_BRACKET  */
#line 436 "./dregx_parser.y"
                                                                                                 {
		auto* const newNode = new dregx::ast::node::capture({::dregx::ast::Type::capture, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (yyvsp[-3].dregx_opt_pad), new dregx::ast::node::LEFT_SQUARE_BRACKET({::dregx::ast::Type::LEFT_SQUARE_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[-2].Terminal) }), (yyvsp[-1].dregx_deamerreserved_plus__capture_logic__), new dregx::ast::node::RIGHT_SQUARE_BRACKET({::dregx::ast::Type::RIGHT_SQUARE_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[0].Terminal) }) });
		(yyval.dregx_capture) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2170 "dregx_parser.tab.c"
    break;

  case 33: /* deamerreserved_plus__capture_logic__: capture_logic  */
#line 446 "./dregx_parser.y"
                       {
		auto* const newNode = new dregx::ast::node::deamerreserved_plus__capture_logic__({::dregx::ast::Type::deamerreserved_plus__capture_logic__, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, { (yyvsp[0].dregx_capture_logic) });
		(yyval.dregx_deamerreserved_plus__capture_logic__) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2181 "dregx_parser.tab.c"
    break;

  case 34: /* deamerreserved_plus__capture_logic__: capture_logic deamerreserved_plus__capture_logic__  */
#line 452 "./dregx_parser.y"
                                                              {
		auto* const newNode = new dregx::ast::node::deamerreserved_plus__capture_logic__({::dregx::ast::Type::deamerreserved_plus__capture_logic__, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, { (yyvsp[-1].dregx_capture_logic), (yyvsp[0].dregx_deamerreserved_plus__capture_logic__) });
		(yyval.dregx_deamerreserved_plus__capture_logic__) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2192 "dregx_parser.tab.c"
    break;

  case 35: /* capture_logic: capture_range  */
#line 462 "./dregx_parser.y"
                       {
		auto* const newNode = new dregx::ast::node::capture_logic({::dregx::ast::Type::capture_logic, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (yyvsp[0].dregx_capture_range) });
		(yyval.dregx_capture_logic) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2203 "dregx_parser.tab.c"
    break;

  case 36: /* capture_logic: capture_special_character  */
#line 468 "./dregx_parser.y"
                                     {
		auto* const newNode = new dregx::ast::node::capture_logic({::dregx::ast::Type::capture_logic, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (yyvsp[0].dregx_capture_special_character) });
		(yyval.dregx_capture_logic) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2214 "dregx_parser.tab.c"
    break;

  case 37: /* capture_logic: capture_letter  */
#line 474 "./dregx_parser.y"
                          {
		auto* const newNode = new dregx::ast::node::capture_logic({::dregx::ast::Type::capture_logic, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 2, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (yyvsp[0].dregx_capture_letter) });
		(yyval.dregx_capture_logic) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2225 "dregx_parser.tab.c"
    break;

  case 38: /* capture_logic: capture_whitespace  */
#line 480 "./dregx_parser.y"
                              {
		auto* const newNode = new dregx::ast::node::capture_logic({::dregx::ast::Type::capture_logic, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 3, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (yyvsp[0].dregx_capture_whitespace) });
		(yyval.dregx_capture_logic) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2236 "dregx_parser.tab.c"
    break;

  case 39: /* capture_logic: capture_symbols  */
#line 486 "./dregx_parser.y"
                           {
		auto* const newNode = new dregx::ast::node::capture_logic({::dregx::ast::Type::capture_logic, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 4, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (yyvsp[0].dregx_capture_symbols) });
		(yyval.dregx_capture_logic) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2247 "dregx_parser.tab.c"
    break;

  case 40: /* capture_symbols: OTHER  */
#line 496 "./dregx_parser.y"
               {
		auto* const newNode = new dregx::ast::node::capture_symbols({::dregx::ast::Type::capture_symbols, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::OTHER({::dregx::ast::Type::OTHER, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[0].Terminal) }) });
		(yyval.dregx_capture_symbols) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2258 "dregx_parser.tab.c"
    break;

  case 41: /* capture_symbols: PLUS  */
#line 502 "./dregx_parser.y"
                {
		auto* const newNode = new dregx::ast::node::capture_symbols({::dregx::ast::Type::capture_symbols, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::PLUS({::dregx::ast::Type::PLUS, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[0].Terminal) }) });
		(yyval.dregx_capture_symbols) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2269 "dregx_parser.tab.c"
    break;

  case 42: /* capture_symbols: STAR  */
#line 508 "./dregx_parser.y"
                {
		auto* const newNode = new dregx::ast::node::capture_symbols({::dregx::ast::Type::capture_symbols, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 2, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::STAR({::dregx::ast::Type::STAR, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[0].Terminal) }) });
		(yyval.dregx_capture_symbols) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2280 "dregx_parser.tab.c"
    break;

  case 43: /* capture_symbols: COMMA  */
#line 514 "./dregx_parser.y"
                 {
		auto* const newNode = new dregx::ast::node::capture_symbols({::dregx::ast::Type::capture_symbols, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 3, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::COMMA({::dregx::ast::Type::COMMA, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[0].Terminal) }) });
		(yyval.dregx_capture_symbols) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2291 "dregx_parser.tab.c"
    break;

  case 44: /* capture_symbols: OR  */
#line 520 "./dregx_parser.y"
              {
		auto* const newNode = new dregx::ast::node::capture_symbols({::dregx::ast::Type::capture_symbols, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 4, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::OR({::dregx::ast::Type::OR, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[0].Terminal) }) });
		(yyval.dregx_capture_symbols) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2302 "dregx_parser.tab.c"
    break;

  case 45: /* capture_whitespace: SPACE  */
#line 530 "./dregx_parser.y"
               {
		auto* const newNode = new dregx::ast::node::capture_whitespace({::dregx::ast::Type::capture_whitespace, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::SPACE({::dregx::ast::Type::SPACE, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[0].Terminal) }) });
		(yyval.dregx_capture_whitespace) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2313 "dregx_parser.tab.c"
    break;

  case 46: /* capture_whitespace: TAB  */
#line 536 "./dregx_parser.y"
               {
		auto* const newNode = new dregx::ast::node::capture_whitespace({::dregx::ast::Type::capture_whitespace, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::TAB({::dregx::ast::Type::TAB, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[0].Terminal) }) });
		(yyval.dregx_capture_whitespace) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2324 "dregx_parser.tab.c"
    break;

  case 47: /* capture_range: capture_letter_range  */
#line 546 "./dregx_parser.y"
                              {
		auto* const newNode = new dregx::ast::node::capture_range({::dregx::ast::Type::capture_range, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (yyvsp[0].dregx_capture_letter_range) });
		(yyval.dregx_capture_range) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2335 "dregx_parser.tab.c"
    break;

  case 48: /* capture_range: capture_number_range  */
#line 552 "./dregx_parser.y"
                                {
		auto* const newNode = new dregx::ast::node::capture_range({::dregx::ast::Type::capture_range, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (yyvsp[0].dregx_capture_number_range) });
		(yyval.dregx_capture_range) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2346 "dregx_parser.tab.c"
    break;

  case 49: /* capture_letter_range: any_letter_exclude_underscore MIN any_letter_exclude_underscore  */
#line 562 "./dregx_parser.y"
                                                                         {
		auto* const newNode = new dregx::ast::node::capture_letter_range({::dregx::ast::Type::capture_letter_range, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (yyvsp[-2].dregx_any_letter_exclude_underscore), new dregx::ast::node::MIN({::dregx::ast::Type::MIN, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[-1].Terminal) }), (yyvsp[0].dregx_any_letter_exclude_underscore) });
		(yyval.dregx_capture_letter_range) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2357 "dregx_parser.tab.c"
    break;

  case 50: /* capture_number_range: NUMBER MIN NUMBER  */
#line 572 "./dregx_parser.y"
                           {
		auto* const newNode = new dregx::ast::node::capture_number_range({::dregx::ast::Type::capture_number_range, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::NUMBER({::dregx::ast::Type::NUMBER, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[-2].Terminal) }), new dregx::ast::node::MIN({::dregx::ast::Type::MIN, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[-1].Terminal) }), new dregx::ast::node::NUMBER({::dregx::ast::Type::NUMBER, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[0].Terminal) }) });
		(yyval.dregx_capture_number_range) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2368 "dregx_parser.tab.c"
    break;

  case 51: /* capture_letter: any_letter  */
#line 582 "./dregx_parser.y"
                    {
		auto* const newNode = new dregx::ast::node::capture_letter({::dregx::ast::Type::capture_letter, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (yyvsp[0].dregx_any_letter) });
		(yyval.dregx_capture_letter) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2379 "dregx_parser.tab.c"
    break;

  case 52: /* capture_special_character: special_char_any  */
#line 592 "./dregx_parser.y"
                          {
		auto* const newNode = new dregx::ast::node::capture_special_character({::dregx::ast::Type::capture_special_character, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (yyvsp[0].dregx_special_char_any) });
		(yyval.dregx_capture_special_character) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2390 "dregx_parser.tab.c"
    break;

  case 53: /* extension_modifier: opt_pad LEFT_BRACKET min_repition opt_pad COMMA max_repition opt_pad RIGHT_BRACKET  */
#line 602 "./dregx_parser.y"
                                                                                            {
		auto* const newNode = new dregx::ast::node::extension_modifier({::dregx::ast::Type::extension_modifier, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (yyvsp[-7].dregx_opt_pad), new dregx::ast::node::LEFT_BRACKET({::dregx::ast::Type::LEFT_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[-6].Terminal) }), (yyvsp[-5].dregx_min_repition), (yyvsp[-4].dregx_opt_pad), new dregx::ast::node::COMMA({::dregx::ast::Type::COMMA, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[-3].Terminal) }), (yyvsp[-2].dregx_max_repition), (yyvsp[-1].dregx_opt_pad), new dregx::ast::node::RIGHT_BRACKET({::dregx::ast::Type::RIGHT_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[0].Terminal) }) });
		(yyval.dregx_extension_modifier) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2401 "dregx_parser.tab.c"
    break;

  case 54: /* min_repition: opt_pad deamerreserved_plus__NUMBER__  */
#line 612 "./dregx_parser.y"
                                               {
		auto* const newNode = new dregx::ast::node::min_repition({::dregx::ast::Type::min_repition, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (yyvsp[-1].dregx_opt_pad), (yyvsp[0].dregx_deamerreserved_plus__NUMBER__) });
		(yyval.dregx_min_repition) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2412 "dregx_parser.tab.c"
    break;

  case 55: /* deamerreserved_plus__NUMBER__: NUMBER  */
#line 622 "./dregx_parser.y"
                {
		auto* const newNode = new dregx::ast::node::deamerreserved_plus__NUMBER__({::dregx::ast::Type::deamerreserved_plus__NUMBER__, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, { new dregx::ast::node::NUMBER({::dregx::ast::Type::NUMBER, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[0].Terminal) }) });
		(yyval.dregx_deamerreserved_plus__NUMBER__) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2423 "dregx_parser.tab.c"
    break;

  case 56: /* deamerreserved_plus__NUMBER__: NUMBER deamerreserved_plus__NUMBER__  */
#line 628 "./dregx_parser.y"
                                                {
		auto* const newNode = new dregx::ast::node::deamerreserved_plus__NUMBER__({::dregx::ast::Type::deamerreserved_plus__NUMBER__, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, { new dregx::ast::node::NUMBER({::dregx::ast::Type::NUMBER, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[-1].Terminal) }), (yyvsp[0].dregx_deamerreserved_plus__NUMBER__) });
		(yyval.dregx_deamerreserved_plus__NUMBER__) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2434 "dregx_parser.tab.c"
    break;

  case 57: /* max_repition: opt_pad deamerreserved_plus__NUMBER__  */
#line 638 "./dregx_parser.y"
                                               {
		auto* const newNode = new dregx::ast::node::max_repition({::dregx::ast::Type::max_repition, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (yyvsp[-1].dregx_opt_pad), (yyvsp[0].dregx_deamerreserved_plus__NUMBER__) });
		(yyval.dregx_max_repition) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2445 "dregx_parser.tab.c"
    break;

  case 58: /* standalone: opt_pad deamerreserved_plus__any_letter__  */
#line 648 "./dregx_parser.y"
                                                   {
		auto* const newNode = new dregx::ast::node::standalone({::dregx::ast::Type::standalone, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (yyvsp[-1].dregx_opt_pad), (yyvsp[0].dregx_deamerreserved_plus__any_letter__) });
		(yyval.dregx_standalone) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2456 "dregx_parser.tab.c"
    break;

  case 59: /* deamerreserved_plus__any_letter__: any_letter  */
#line 658 "./dregx_parser.y"
                    {
		auto* const newNode = new dregx::ast::node::deamerreserved_plus__any_letter__({::dregx::ast::Type::deamerreserved_plus__any_letter__, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, { (yyvsp[0].dregx_any_letter) });
		(yyval.dregx_deamerreserved_plus__any_letter__) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2467 "dregx_parser.tab.c"
    break;

  case 60: /* deamerreserved_plus__any_letter__: any_letter deamerreserved_plus__any_letter__  */
#line 664 "./dregx_parser.y"
                                                        {
		auto* const newNode = new dregx::ast::node::deamerreserved_plus__any_letter__({::dregx::ast::Type::deamerreserved_plus__any_letter__, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, { (yyvsp[-1].dregx_any_letter), (yyvsp[0].dregx_deamerreserved_plus__any_letter__) });
		(yyval.dregx_deamerreserved_plus__any_letter__) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2478 "dregx_parser.tab.c"
    break;

  case 61: /* opt_pad: optional_padding  */
#line 674 "./dregx_parser.y"
                          {
		auto* const newNode = new dregx::ast::node::opt_pad({::dregx::ast::Type::opt_pad, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (yyvsp[0].dregx_optional_padding) });
		(yyval.dregx_opt_pad) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2489 "dregx_parser.tab.c"
    break;

  case 62: /* optional_padding: deamerreserved_star__padding__  */
#line 684 "./dregx_parser.y"
                                        {
		auto* const newNode = new dregx::ast::node::optional_padding({::dregx::ast::Type::optional_padding, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (yyvsp[0].dregx_deamerreserved_star__padding__) });
		(yyval.dregx_optional_padding) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2500 "dregx_parser.tab.c"
    break;

  case 63: /* deamerreserved_star__padding__: padding deamerreserved_star__padding__  */
#line 694 "./dregx_parser.y"
                                                {
		auto* const newNode = new dregx::ast::node::deamerreserved_star__padding__({::dregx::ast::Type::deamerreserved_star__padding__, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, { (yyvsp[-1].dregx_padding), (yyvsp[0].dregx_deamerreserved_star__padding__) });
		(yyval.dregx_deamerreserved_star__padding__) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2511 "dregx_parser.tab.c"
    break;

  case 64: /* deamerreserved_star__padding__: %empty  */
#line 700 "./dregx_parser.y"
           {
		auto* const newNode = new dregx::ast::node::deamerreserved_star__padding__({::dregx::ast::Type::deamerreserved_star__padding__, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, {  });
		(yyval.dregx_deamerreserved_star__padding__) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2522 "dregx_parser.tab.c"
    break;

  case 65: /* padding: SPACE  */
#line 710 "./dregx_parser.y"
               {
		auto* const newNode = new dregx::ast::node::padding({::dregx::ast::Type::padding, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::SPACE({::dregx::ast::Type::SPACE, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[0].Terminal) }) });
		(yyval.dregx_padding) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2533 "dregx_parser.tab.c"
    break;

  case 66: /* padding: TAB  */
#line 716 "./dregx_parser.y"
               {
		auto* const newNode = new dregx::ast::node::padding({::dregx::ast::Type::padding, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::TAB({::dregx::ast::Type::TAB, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[0].Terminal) }) });
		(yyval.dregx_padding) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2544 "dregx_parser.tab.c"
    break;

  case 67: /* special_char_any: SLASH any  */
#line 726 "./dregx_parser.y"
                   {
		auto* const newNode = new dregx::ast::node::special_char_any({::dregx::ast::Type::special_char_any, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::SLASH({::dregx::ast::Type::SLASH, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[-1].Terminal) }), (yyvsp[0].dregx_any) });
		(yyval.dregx_special_char_any) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2555 "dregx_parser.tab.c"
    break;

  case 68: /* any_letter: any_letter_exclude_underscore  */
#line 736 "./dregx_parser.y"
                                       {
		auto* const newNode = new dregx::ast::node::any_letter({::dregx::ast::Type::any_letter, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (yyvsp[0].dregx_any_letter_exclude_underscore) });
		(yyval.dregx_any_letter) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2566 "dregx_parser.tab.c"
    break;

  case 69: /* any_letter: UNDERSCORE  */
#line 742 "./dregx_parser.y"
                      {
		auto* const newNode = new dregx::ast::node::any_letter({::dregx::ast::Type::any_letter, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::UNDERSCORE({::dregx::ast::Type::UNDERSCORE, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[0].Terminal) }) });
		(yyval.dregx_any_letter) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2577 "dregx_parser.tab.c"
    break;

  case 70: /* any_letter_exclude_underscore: T_  */
#line 752 "./dregx_parser.y"
            {
		auto* const newNode = new dregx::ast::node::any_letter_exclude_underscore({::dregx::ast::Type::any_letter_exclude_underscore, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::T_({::dregx::ast::Type::T_, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[0].Terminal) }) });
		(yyval.dregx_any_letter_exclude_underscore) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2588 "dregx_parser.tab.c"
    break;

  case 71: /* any_letter_exclude_underscore: R_  */
#line 758 "./dregx_parser.y"
              {
		auto* const newNode = new dregx::ast::node::any_letter_exclude_underscore({::dregx::ast::Type::any_letter_exclude_underscore, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::R_({::dregx::ast::Type::R_, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[0].Terminal) }) });
		(yyval.dregx_any_letter_exclude_underscore) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2599 "dregx_parser.tab.c"
    break;

  case 72: /* any_letter_exclude_underscore: N_  */
#line 764 "./dregx_parser.y"
              {
		auto* const newNode = new dregx::ast::node::any_letter_exclude_underscore({::dregx::ast::Type::any_letter_exclude_underscore, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 2, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::N_({::dregx::ast::Type::N_, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[0].Terminal) }) });
		(yyval.dregx_any_letter_exclude_underscore) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2610 "dregx_parser.tab.c"
    break;

  case 73: /* any_letter_exclude_underscore: B_  */
#line 770 "./dregx_parser.y"
              {
		auto* const newNode = new dregx::ast::node::any_letter_exclude_underscore({::dregx::ast::Type::any_letter_exclude_underscore, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 3, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::B_({::dregx::ast::Type::B_, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[0].Terminal) }) });
		(yyval.dregx_any_letter_exclude_underscore) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2621 "dregx_parser.tab.c"
    break;

  case 74: /* any_letter_exclude_underscore: V_  */
#line 776 "./dregx_parser.y"
              {
		auto* const newNode = new dregx::ast::node::any_letter_exclude_underscore({::dregx::ast::Type::any_letter_exclude_underscore, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 4, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::V_({::dregx::ast::Type::V_, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[0].Terminal) }) });
		(yyval.dregx_any_letter_exclude_underscore) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2632 "dregx_parser.tab.c"
    break;

  case 75: /* any_letter_exclude_underscore: A_  */
#line 782 "./dregx_parser.y"
              {
		auto* const newNode = new dregx::ast::node::any_letter_exclude_underscore({::dregx::ast::Type::any_letter_exclude_underscore, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 5, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::A_({::dregx::ast::Type::A_, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[0].Terminal) }) });
		(yyval.dregx_any_letter_exclude_underscore) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2643 "dregx_parser.tab.c"
    break;

  case 76: /* any_letter_exclude_underscore: LETTER  */
#line 788 "./dregx_parser.y"
                  {
		auto* const newNode = new dregx::ast::node::any_letter_exclude_underscore({::dregx::ast::Type::any_letter_exclude_underscore, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 6, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::LETTER({::dregx::ast::Type::LETTER, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[0].Terminal) }) });
		(yyval.dregx_any_letter_exclude_underscore) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2654 "dregx_parser.tab.c"
    break;

  case 77: /* any: LEFT_CURLY_BRACKET  */
#line 798 "./dregx_parser.y"
                            {
		auto* const newNode = new dregx::ast::node::any({::dregx::ast::Type::any, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::LEFT_CURLY_BRACKET({::dregx::ast::Type::LEFT_CURLY_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[0].Terminal) }) });
		(yyval.dregx_any) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2665 "dregx_parser.tab.c"
    break;

  case 78: /* any: RIGHT_CURLY_BRACKET  */
#line 804 "./dregx_parser.y"
                               {
		auto* const newNode = new dregx::ast::node::any({::dregx::ast::Type::any, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::RIGHT_CURLY_BRACKET({::dregx::ast::Type::RIGHT_CURLY_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[0].Terminal) }) });
		(yyval.dregx_any) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2676 "dregx_parser.tab.c"
    break;

  case 79: /* any: LEFT_SQUARE_BRACKET  */
#line 810 "./dregx_parser.y"
                               {
		auto* const newNode = new dregx::ast::node::any({::dregx::ast::Type::any, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 2, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::LEFT_SQUARE_BRACKET({::dregx::ast::Type::LEFT_SQUARE_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[0].Terminal) }) });
		(yyval.dregx_any) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2687 "dregx_parser.tab.c"
    break;

  case 80: /* any: RIGHT_SQUARE_BRACKET  */
#line 816 "./dregx_parser.y"
                                {
		auto* const newNode = new dregx::ast::node::any({::dregx::ast::Type::any, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 3, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::RIGHT_SQUARE_BRACKET({::dregx::ast::Type::RIGHT_SQUARE_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[0].Terminal) }) });
		(yyval.dregx_any) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2698 "dregx_parser.tab.c"
    break;

  case 81: /* any: LEFT_BRACKET  */
#line 822 "./dregx_parser.y"
                        {
		auto* const newNode = new dregx::ast::node::any({::dregx::ast::Type::any, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 4, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::LEFT_BRACKET({::dregx::ast::Type::LEFT_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[0].Terminal) }) });
		(yyval.dregx_any) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2709 "dregx_parser.tab.c"
    break;

  case 82: /* any: RIGHT_BRACKET  */
#line 828 "./dregx_parser.y"
                         {
		auto* const newNode = new dregx::ast::node::any({::dregx::ast::Type::any, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 5, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::RIGHT_BRACKET({::dregx::ast::Type::RIGHT_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[0].Terminal) }) });
		(yyval.dregx_any) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2720 "dregx_parser.tab.c"
    break;

  case 83: /* any: COMMA  */
#line 834 "./dregx_parser.y"
                 {
		auto* const newNode = new dregx::ast::node::any({::dregx::ast::Type::any, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 6, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::COMMA({::dregx::ast::Type::COMMA, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[0].Terminal) }) });
		(yyval.dregx_any) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2731 "dregx_parser.tab.c"
    break;

  case 84: /* any: OR  */
#line 840 "./dregx_parser.y"
              {
		auto* const newNode = new dregx::ast::node::any({::dregx::ast::Type::any, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 7, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::OR({::dregx::ast::Type::OR, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[0].Terminal) }) });
		(yyval.dregx_any) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2742 "dregx_parser.tab.c"
    break;

  case 85: /* any: MIN  */
#line 846 "./dregx_parser.y"
               {
		auto* const newNode = new dregx::ast::node::any({::dregx::ast::Type::any, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 8, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::MIN({::dregx::ast::Type::MIN, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[0].Terminal) }) });
		(yyval.dregx_any) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2753 "dregx_parser.tab.c"
    break;

  case 86: /* any: UNDERSCORE  */
#line 852 "./dregx_parser.y"
                      {
		auto* const newNode = new dregx::ast::node::any({::dregx::ast::Type::any, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 9, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::UNDERSCORE({::dregx::ast::Type::UNDERSCORE, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[0].Terminal) }) });
		(yyval.dregx_any) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2764 "dregx_parser.tab.c"
    break;

  case 87: /* any: NOT  */
#line 858 "./dregx_parser.y"
               {
		auto* const newNode = new dregx::ast::node::any({::dregx::ast::Type::any, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 10, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::NOT({::dregx::ast::Type::NOT, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[0].Terminal) }) });
		(yyval.dregx_any) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2775 "dregx_parser.tab.c"
    break;

  case 88: /* any: NUMBER  */
#line 864 "./dregx_parser.y"
                  {
		auto* const newNode = new dregx::ast::node::any({::dregx::ast::Type::any, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 11, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::NUMBER({::dregx::ast::Type::NUMBER, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[0].Terminal) }) });
		(yyval.dregx_any) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2786 "dregx_parser.tab.c"
    break;

  case 89: /* any: T_  */
#line 870 "./dregx_parser.y"
              {
		auto* const newNode = new dregx::ast::node::any({::dregx::ast::Type::any, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 12, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::T_({::dregx::ast::Type::T_, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[0].Terminal) }) });
		(yyval.dregx_any) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2797 "dregx_parser.tab.c"
    break;

  case 90: /* any: N_  */
#line 876 "./dregx_parser.y"
              {
		auto* const newNode = new dregx::ast::node::any({::dregx::ast::Type::any, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 13, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::N_({::dregx::ast::Type::N_, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[0].Terminal) }) });
		(yyval.dregx_any) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2808 "dregx_parser.tab.c"
    break;

  case 91: /* any: R_  */
#line 882 "./dregx_parser.y"
              {
		auto* const newNode = new dregx::ast::node::any({::dregx::ast::Type::any, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 14, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::R_({::dregx::ast::Type::R_, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[0].Terminal) }) });
		(yyval.dregx_any) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2819 "dregx_parser.tab.c"
    break;

  case 92: /* any: B_  */
#line 888 "./dregx_parser.y"
              {
		auto* const newNode = new dregx::ast::node::any({::dregx::ast::Type::any, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 15, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::B_({::dregx::ast::Type::B_, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[0].Terminal) }) });
		(yyval.dregx_any) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2830 "dregx_parser.tab.c"
    break;

  case 93: /* any: V_  */
#line 894 "./dregx_parser.y"
              {
		auto* const newNode = new dregx::ast::node::any({::dregx::ast::Type::any, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 16, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::V_({::dregx::ast::Type::V_, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[0].Terminal) }) });
		(yyval.dregx_any) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2841 "dregx_parser.tab.c"
    break;

  case 94: /* any: A_  */
#line 900 "./dregx_parser.y"
              {
		auto* const newNode = new dregx::ast::node::any({::dregx::ast::Type::any, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 17, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::A_({::dregx::ast::Type::A_, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[0].Terminal) }) });
		(yyval.dregx_any) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2852 "dregx_parser.tab.c"
    break;

  case 95: /* any: LETTER  */
#line 906 "./dregx_parser.y"
                  {
		auto* const newNode = new dregx::ast::node::any({::dregx::ast::Type::any, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 18, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::LETTER({::dregx::ast::Type::LETTER, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[0].Terminal) }) });
		(yyval.dregx_any) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2863 "dregx_parser.tab.c"
    break;

  case 96: /* any: SPACE  */
#line 912 "./dregx_parser.y"
                 {
		auto* const newNode = new dregx::ast::node::any({::dregx::ast::Type::any, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 19, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::SPACE({::dregx::ast::Type::SPACE, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[0].Terminal) }) });
		(yyval.dregx_any) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2874 "dregx_parser.tab.c"
    break;

  case 97: /* any: TAB  */
#line 918 "./dregx_parser.y"
               {
		auto* const newNode = new dregx::ast::node::any({::dregx::ast::Type::any, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 20, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::TAB({::dregx::ast::Type::TAB, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[0].Terminal) }) });
		(yyval.dregx_any) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2885 "dregx_parser.tab.c"
    break;

  case 98: /* any: PLUS  */
#line 924 "./dregx_parser.y"
                {
		auto* const newNode = new dregx::ast::node::any({::dregx::ast::Type::any, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 21, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::PLUS({::dregx::ast::Type::PLUS, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[0].Terminal) }) });
		(yyval.dregx_any) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2896 "dregx_parser.tab.c"
    break;

  case 99: /* any: STAR  */
#line 930 "./dregx_parser.y"
                {
		auto* const newNode = new dregx::ast::node::any({::dregx::ast::Type::any, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 22, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::STAR({::dregx::ast::Type::STAR, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[0].Terminal) }) });
		(yyval.dregx_any) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2907 "dregx_parser.tab.c"
    break;

  case 100: /* any: OTHER  */
#line 936 "./dregx_parser.y"
                 {
		auto* const newNode = new dregx::ast::node::any({::dregx::ast::Type::any, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 23, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::OTHER({::dregx::ast::Type::OTHER, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[0].Terminal) }) });
		(yyval.dregx_any) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2918 "dregx_parser.tab.c"
    break;

  case 101: /* any: SLASH  */
#line 942 "./dregx_parser.y"
                 {
		auto* const newNode = new dregx::ast::node::any({::dregx::ast::Type::any, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 24, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::SLASH({::dregx::ast::Type::SLASH, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[0].Terminal) }) });
		(yyval.dregx_any) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2929 "dregx_parser.tab.c"
    break;


#line 2933 "dregx_parser.tab.c"

        default: break;
      }
    if (yychar_backup != yychar)
      YY_LAC_DISCARD ("yychar change");
  }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yyesa, &yyes, &yyes_capacity, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        if (yychar != YYEMPTY)
          YY_LAC_ESTABLISH;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  /* If the stack popping above didn't lose the initial context for the
     current lookahead token, the shift below will for sure.  */
  YY_LAC_DISCARD ("error recovery");

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yyes != yyesa)
    YYSTACK_FREE (yyes);
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 952 "./dregx_parser.y"


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
