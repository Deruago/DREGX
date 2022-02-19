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

#line 168 "dregx_parser.tab.c"

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
  YYSYMBOL_deamerreserved_arrow__word__ = 38, /* deamerreserved_arrow__word__  */
  YYSYMBOL_deamerreserved_star__opt_pad__OR__word__ = 39, /* deamerreserved_star__opt_pad__OR__word__  */
  YYSYMBOL_square = 40,                    /* square  */
  YYSYMBOL_capture = 41,                   /* capture  */
  YYSYMBOL_deamerreserved_plus__capture_logic__ = 42, /* deamerreserved_plus__capture_logic__  */
  YYSYMBOL_capture_logic = 43,             /* capture_logic  */
  YYSYMBOL_capture_symbols = 44,           /* capture_symbols  */
  YYSYMBOL_capture_whitespace = 45,        /* capture_whitespace  */
  YYSYMBOL_capture_range = 46,             /* capture_range  */
  YYSYMBOL_capture_letter_range = 47,      /* capture_letter_range  */
  YYSYMBOL_capture_number_range = 48,      /* capture_number_range  */
  YYSYMBOL_capture_letter = 49,            /* capture_letter  */
  YYSYMBOL_capture_special_character = 50, /* capture_special_character  */
  YYSYMBOL_extension_modifier = 51,        /* extension_modifier  */
  YYSYMBOL_min_repition = 52,              /* min_repition  */
  YYSYMBOL_deamerreserved_plus__NUMBER__ = 53, /* deamerreserved_plus__NUMBER__  */
  YYSYMBOL_max_repition = 54,              /* max_repition  */
  YYSYMBOL_standalone = 55,                /* standalone  */
  YYSYMBOL_deamerreserved_plus__any_letter__ = 56, /* deamerreserved_plus__any_letter__  */
  YYSYMBOL_opt_pad = 57,                   /* opt_pad  */
  YYSYMBOL_optional_padding = 58,          /* optional_padding  */
  YYSYMBOL_deamerreserved_star__padding__ = 59, /* deamerreserved_star__padding__  */
  YYSYMBOL_padding = 60,                   /* padding  */
  YYSYMBOL_special_char_any = 61,          /* special_char_any  */
  YYSYMBOL_any_letter = 62,                /* any_letter  */
  YYSYMBOL_any_letter_exclude_underscore = 63, /* any_letter_exclude_underscore  */
  YYSYMBOL_any = 64                        /* any  */
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
#define YYLAST   190

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  30
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  97
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  129

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
       0,   229,   229,   240,   246,   256,   266,   272,   278,   288,
     294,   300,   306,   312,   318,   324,   330,   340,   346,   356,
     366,   376,   382,   392,   398,   404,   410,   420,   426,   436,
     442,   452,   458,   464,   470,   476,   486,   492,   498,   504,
     510,   520,   526,   536,   542,   552,   562,   572,   582,   592,
     602,   612,   618,   628,   638,   648,   654,   664,   674,   684,
     690,   700,   706,   716,   726,   732,   742,   748,   754,   760,
     766,   772,   778,   788,   794,   800,   806,   812,   818,   824,
     830,   836,   842,   848,   854,   860,   866,   872,   878,   884,
     890,   896,   902,   908,   914,   920,   926,   932
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
  "deamerreserved_plus__word__", "or_concat",
  "deamerreserved_arrow__word__",
  "deamerreserved_star__opt_pad__OR__word__", "square", "capture",
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

#define YYPACT_NINF (-94)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-61)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       8,   -94,   -94,    14,   -94,     8,   -94,   -94,   -94,    24,
     -94,   124,   -94,   -94,   -16,   -94,   -94,   -94,   -94,   -94,
       7,   -16,   143,   143,   -94,   -94,   -94,   -94,   -94,   -94,
     -94,   -94,   -94,   158,   -94,   -94,   -16,    -2,   -16,   -16,
     -94,    49,   -94,   -94,   -94,     3,   -94,   -94,   -94,    11,
     143,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,
      10,    13,   -94,   -16,    20,    -2,   -94,   101,    22,    35,
     -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,
     -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,
     -94,   -94,   -94,   -94,   -94,   -94,    25,   -94,   -94,   165,
     -94,    32,    20,   -94,   -16,    82,   125,   -94,   -94,   -16,
     -94,    -5,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -16,
      20,   -94,    34,    38,   -94,   -16,   -94,    -5,   -94
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
      60,    61,    62,     0,     2,    60,     5,     6,     7,    26,
       8,     0,    57,    58,    60,     1,     3,    24,    25,    23,
       0,    60,     0,     0,    65,    66,    68,    67,    69,    70,
      71,    72,    54,    55,    64,    59,    60,    60,    60,    60,
      39,     0,    40,    37,    38,     0,    41,    42,    36,     0,
      29,    35,    34,    31,    43,    44,    33,    32,    48,    47,
      64,     0,    56,    60,     0,    60,    18,     0,     0,     0,
      73,    74,    75,    76,    77,    78,    79,    97,    80,    81,
      82,    83,    94,    95,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    96,    63,     0,    27,    30,     0,
      28,     0,    51,    50,    60,    16,    12,    46,    45,    60,
      52,    22,    19,    14,    13,    15,    10,     9,    11,    60,
       0,    20,     0,     0,    53,    60,    49,    22,    21
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -94,   -94,    39,   -94,   -20,   -94,    27,   -94,   -94,   -78,
     -94,   -94,   -14,   -94,   -94,   -94,   -94,   -94,   -94,   -94,
     -94,   -93,   -94,   -83,   -94,   -94,    45,    -9,   -94,    65,
     -94,   -94,   -17,   -19,   -94
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     3,     4,     5,     6,     7,    66,    39,   112,   121,
       8,     9,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    19,    63,   103,   119,    10,    32,    11,    12,    13,
      14,    58,    33,    34,    95
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      20,    37,   -17,    60,    60,    59,    59,   -60,    -4,    61,
       1,     2,   115,   118,    15,    36,    96,    65,    97,   110,
     100,     1,     2,    99,     1,     2,   105,    64,    67,    68,
      69,    60,   -60,    59,     1,     2,    98,   124,   102,   106,
      17,    18,   109,   107,    16,    65,   125,   126,    38,   128,
       1,     2,    70,    71,   101,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    62,    35,
     108,     0,     0,     0,   111,     0,     0,     0,     0,     0,
     -60,     0,     0,     0,     0,     0,    20,    20,   113,   114,
     120,     0,   122,     0,    21,   127,    22,    23,     1,     2,
     123,     0,     0,   104,     0,    24,     0,     0,   122,     0,
      25,    26,    27,    28,    29,    30,    31,    21,     0,    22,
      23,     0,     0,   -60,     0,     0,     0,     0,    24,     0,
       0,   116,   117,    25,    26,    27,    28,    29,    30,    31,
       0,     1,     2,    40,    41,    42,     0,    24,     0,    43,
      44,    45,    25,    26,    27,    28,    29,    30,    31,    46,
      47,    48,    24,     0,     0,     0,     0,    25,    26,    27,
      28,    29,    30,    31,    25,    26,    27,    28,    29,    30,
      31
};

static const yytype_int8 yycheck[] =
{
       9,    21,     4,    22,    23,    22,    23,    12,     0,    23,
      26,    27,   105,   106,     0,     8,    13,    37,     7,   102,
       7,    26,    27,    13,    26,    27,     4,    36,    37,    38,
      39,    50,     8,    50,    26,    27,    50,   120,    18,     4,
      16,    17,    10,    18,     5,    65,    12,     9,    21,   127,
      26,    27,     3,     4,    63,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    33,    14,
      99,    -1,    -1,    -1,   104,    -1,    -1,    -1,    -1,    -1,
       8,    -1,    -1,    -1,    -1,    -1,   105,   106,    16,    17,
     109,    -1,   111,    -1,     3,   125,     5,     6,    26,    27,
     119,    -1,    -1,    12,    -1,    14,    -1,    -1,   127,    -1,
      19,    20,    21,    22,    23,    24,    25,     3,    -1,     5,
       6,    -1,    -1,     8,    -1,    -1,    -1,    -1,    14,    -1,
      -1,    16,    17,    19,    20,    21,    22,    23,    24,    25,
      -1,    26,    27,    10,    11,    12,    -1,    14,    -1,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    14,    -1,    -1,    -1,    -1,    19,    20,    21,
      22,    23,    24,    25,    19,    20,    21,    22,    23,    24,
      25
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    26,    27,    31,    32,    33,    34,    35,    40,    41,
      55,    57,    58,    59,    60,     0,    32,    16,    17,    51,
      57,     3,     5,     6,    14,    19,    20,    21,    22,    23,
      24,    25,    56,    62,    63,    59,     8,    34,    36,    37,
      10,    11,    12,    16,    17,    18,    26,    27,    28,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    61,    62,
      63,    42,    56,    52,    57,    34,    36,    57,    57,    57,
       3,     4,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    64,    13,     7,    42,    13,
       7,    57,    18,    53,    12,     4,     4,    18,    63,    10,
      53,    34,    38,    16,    17,    51,    16,    17,    51,    54,
      57,    39,    57,    57,    53,    12,     9,    34,    39
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    30,    31,    32,    32,    33,    34,    34,    34,    35,
      35,    35,    35,    35,    35,    35,    35,    36,    36,    37,
      38,    39,    39,    40,    40,    40,    40,    41,    41,    42,
      42,    43,    43,    43,    43,    43,    44,    44,    44,    44,
      44,    45,    45,    46,    46,    47,    48,    49,    50,    51,
      52,    53,    53,    54,    55,    56,    56,    57,    58,    59,
      59,    60,    60,    61,    62,    62,    63,    63,    63,    63,
      63,    63,    63,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    64
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     1,     1,     1,     1,     6,
       6,     6,     5,     6,     6,     6,     5,     1,     2,     4,
       2,     4,     0,     2,     2,     2,     1,     4,     4,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     3,     1,     1,     8,
       2,     1,     2,     2,     2,     1,     2,     1,     1,     2,
       0,     1,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1
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
#line 229 "./dregx_parser.y"
                                     {
		auto* const newNode = new dregx::ast::node::program({::dregx::ast::Type::program, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (yyvsp[0].dregx_deamerreserved_star__stmt__) });
		(yyval.dregx_program) = newNode;

		// Ignored, Deleted, tokens are deleted
		outputTree = new ::deamer::external::cpp::ast::Tree(newNode);
	}
#line 1844 "dregx_parser.tab.c"
    break;

  case 3: /* deamerreserved_star__stmt__: stmt deamerreserved_star__stmt__  */
#line 240 "./dregx_parser.y"
                                          {
		auto* const newNode = new dregx::ast::node::deamerreserved_star__stmt__({::dregx::ast::Type::deamerreserved_star__stmt__, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, { (yyvsp[-1].dregx_stmt), (yyvsp[0].dregx_deamerreserved_star__stmt__) });
		(yyval.dregx_deamerreserved_star__stmt__) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 1855 "dregx_parser.tab.c"
    break;

  case 4: /* deamerreserved_star__stmt__: %empty  */
#line 246 "./dregx_parser.y"
           {
		auto* const newNode = new dregx::ast::node::deamerreserved_star__stmt__({::dregx::ast::Type::deamerreserved_star__stmt__, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, {  });
		(yyval.dregx_deamerreserved_star__stmt__) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 1866 "dregx_parser.tab.c"
    break;

  case 5: /* stmt: word  */
#line 256 "./dregx_parser.y"
              {
		auto* const newNode = new dregx::ast::node::stmt({::dregx::ast::Type::stmt, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (yyvsp[0].dregx_word) });
		(yyval.dregx_stmt) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 1877 "dregx_parser.tab.c"
    break;

  case 6: /* word: group  */
#line 266 "./dregx_parser.y"
               {
		auto* const newNode = new dregx::ast::node::word({::dregx::ast::Type::word, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (yyvsp[0].dregx_group) });
		(yyval.dregx_word) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 1888 "dregx_parser.tab.c"
    break;

  case 7: /* word: square  */
#line 272 "./dregx_parser.y"
                  {
		auto* const newNode = new dregx::ast::node::word({::dregx::ast::Type::word, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (yyvsp[0].dregx_square) });
		(yyval.dregx_word) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 1899 "dregx_parser.tab.c"
    break;

  case 8: /* word: standalone  */
#line 278 "./dregx_parser.y"
                      {
		auto* const newNode = new dregx::ast::node::word({::dregx::ast::Type::word, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 2, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (yyvsp[0].dregx_standalone) });
		(yyval.dregx_word) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 1910 "dregx_parser.tab.c"
    break;

  case 9: /* group: opt_pad LEFT_CURLY_BRACKET or_concat opt_pad RIGHT_CURLY_BRACKET STAR  */
#line 288 "./dregx_parser.y"
                                                                               {
		auto* const newNode = new dregx::ast::node::group({::dregx::ast::Type::group, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (yyvsp[-5].dregx_opt_pad), new dregx::ast::node::LEFT_CURLY_BRACKET({::dregx::ast::Type::LEFT_CURLY_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[-4].Terminal) }), (yyvsp[-3].dregx_or_concat), (yyvsp[-2].dregx_opt_pad), new dregx::ast::node::RIGHT_CURLY_BRACKET({::dregx::ast::Type::RIGHT_CURLY_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[-1].Terminal) }), new dregx::ast::node::STAR({::dregx::ast::Type::STAR, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[0].Terminal) }) });
		(yyval.dregx_group) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 1921 "dregx_parser.tab.c"
    break;

  case 10: /* group: opt_pad LEFT_CURLY_BRACKET or_concat opt_pad RIGHT_CURLY_BRACKET PLUS  */
#line 294 "./dregx_parser.y"
                                                                                 {
		auto* const newNode = new dregx::ast::node::group({::dregx::ast::Type::group, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (yyvsp[-5].dregx_opt_pad), new dregx::ast::node::LEFT_CURLY_BRACKET({::dregx::ast::Type::LEFT_CURLY_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[-4].Terminal) }), (yyvsp[-3].dregx_or_concat), (yyvsp[-2].dregx_opt_pad), new dregx::ast::node::RIGHT_CURLY_BRACKET({::dregx::ast::Type::RIGHT_CURLY_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[-1].Terminal) }), new dregx::ast::node::PLUS({::dregx::ast::Type::PLUS, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[0].Terminal) }) });
		(yyval.dregx_group) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 1932 "dregx_parser.tab.c"
    break;

  case 11: /* group: opt_pad LEFT_CURLY_BRACKET or_concat opt_pad RIGHT_CURLY_BRACKET extension_modifier  */
#line 300 "./dregx_parser.y"
                                                                                               {
		auto* const newNode = new dregx::ast::node::group({::dregx::ast::Type::group, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 2, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (yyvsp[-5].dregx_opt_pad), new dregx::ast::node::LEFT_CURLY_BRACKET({::dregx::ast::Type::LEFT_CURLY_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[-4].Terminal) }), (yyvsp[-3].dregx_or_concat), (yyvsp[-2].dregx_opt_pad), new dregx::ast::node::RIGHT_CURLY_BRACKET({::dregx::ast::Type::RIGHT_CURLY_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[-1].Terminal) }), (yyvsp[0].dregx_extension_modifier) });
		(yyval.dregx_group) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 1943 "dregx_parser.tab.c"
    break;

  case 12: /* group: opt_pad LEFT_CURLY_BRACKET or_concat opt_pad RIGHT_CURLY_BRACKET  */
#line 306 "./dregx_parser.y"
                                                                            {
		auto* const newNode = new dregx::ast::node::group({::dregx::ast::Type::group, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 3, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (yyvsp[-4].dregx_opt_pad), new dregx::ast::node::LEFT_CURLY_BRACKET({::dregx::ast::Type::LEFT_CURLY_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[-3].Terminal) }), (yyvsp[-2].dregx_or_concat), (yyvsp[-1].dregx_opt_pad), new dregx::ast::node::RIGHT_CURLY_BRACKET({::dregx::ast::Type::RIGHT_CURLY_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[0].Terminal) }) });
		(yyval.dregx_group) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 1954 "dregx_parser.tab.c"
    break;

  case 13: /* group: opt_pad LEFT_CURLY_BRACKET deamerreserved_plus__word__ opt_pad RIGHT_CURLY_BRACKET STAR  */
#line 312 "./dregx_parser.y"
                                                                                                   {
		auto* const newNode = new dregx::ast::node::group({::dregx::ast::Type::group, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 4, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (yyvsp[-5].dregx_opt_pad), new dregx::ast::node::LEFT_CURLY_BRACKET({::dregx::ast::Type::LEFT_CURLY_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[-4].Terminal) }), (yyvsp[-3].dregx_deamerreserved_plus__word__), (yyvsp[-2].dregx_opt_pad), new dregx::ast::node::RIGHT_CURLY_BRACKET({::dregx::ast::Type::RIGHT_CURLY_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[-1].Terminal) }), new dregx::ast::node::STAR({::dregx::ast::Type::STAR, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[0].Terminal) }) });
		(yyval.dregx_group) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 1965 "dregx_parser.tab.c"
    break;

  case 14: /* group: opt_pad LEFT_CURLY_BRACKET deamerreserved_plus__word__ opt_pad RIGHT_CURLY_BRACKET PLUS  */
#line 318 "./dregx_parser.y"
                                                                                                   {
		auto* const newNode = new dregx::ast::node::group({::dregx::ast::Type::group, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 5, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (yyvsp[-5].dregx_opt_pad), new dregx::ast::node::LEFT_CURLY_BRACKET({::dregx::ast::Type::LEFT_CURLY_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[-4].Terminal) }), (yyvsp[-3].dregx_deamerreserved_plus__word__), (yyvsp[-2].dregx_opt_pad), new dregx::ast::node::RIGHT_CURLY_BRACKET({::dregx::ast::Type::RIGHT_CURLY_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[-1].Terminal) }), new dregx::ast::node::PLUS({::dregx::ast::Type::PLUS, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[0].Terminal) }) });
		(yyval.dregx_group) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 1976 "dregx_parser.tab.c"
    break;

  case 15: /* group: opt_pad LEFT_CURLY_BRACKET deamerreserved_plus__word__ opt_pad RIGHT_CURLY_BRACKET extension_modifier  */
#line 324 "./dregx_parser.y"
                                                                                                                 {
		auto* const newNode = new dregx::ast::node::group({::dregx::ast::Type::group, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 6, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (yyvsp[-5].dregx_opt_pad), new dregx::ast::node::LEFT_CURLY_BRACKET({::dregx::ast::Type::LEFT_CURLY_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[-4].Terminal) }), (yyvsp[-3].dregx_deamerreserved_plus__word__), (yyvsp[-2].dregx_opt_pad), new dregx::ast::node::RIGHT_CURLY_BRACKET({::dregx::ast::Type::RIGHT_CURLY_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[-1].Terminal) }), (yyvsp[0].dregx_extension_modifier) });
		(yyval.dregx_group) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 1987 "dregx_parser.tab.c"
    break;

  case 16: /* group: opt_pad LEFT_CURLY_BRACKET deamerreserved_plus__word__ opt_pad RIGHT_CURLY_BRACKET  */
#line 330 "./dregx_parser.y"
                                                                                              {
		auto* const newNode = new dregx::ast::node::group({::dregx::ast::Type::group, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 7, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (yyvsp[-4].dregx_opt_pad), new dregx::ast::node::LEFT_CURLY_BRACKET({::dregx::ast::Type::LEFT_CURLY_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[-3].Terminal) }), (yyvsp[-2].dregx_deamerreserved_plus__word__), (yyvsp[-1].dregx_opt_pad), new dregx::ast::node::RIGHT_CURLY_BRACKET({::dregx::ast::Type::RIGHT_CURLY_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[0].Terminal) }) });
		(yyval.dregx_group) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 1998 "dregx_parser.tab.c"
    break;

  case 17: /* deamerreserved_plus__word__: word  */
#line 340 "./dregx_parser.y"
              {
		auto* const newNode = new dregx::ast::node::deamerreserved_plus__word__({::dregx::ast::Type::deamerreserved_plus__word__, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, { (yyvsp[0].dregx_word) });
		(yyval.dregx_deamerreserved_plus__word__) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2009 "dregx_parser.tab.c"
    break;

  case 18: /* deamerreserved_plus__word__: word deamerreserved_plus__word__  */
#line 346 "./dregx_parser.y"
                                            {
		auto* const newNode = new dregx::ast::node::deamerreserved_plus__word__({::dregx::ast::Type::deamerreserved_plus__word__, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, { (yyvsp[-1].dregx_word), (yyvsp[0].dregx_deamerreserved_plus__word__) });
		(yyval.dregx_deamerreserved_plus__word__) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2020 "dregx_parser.tab.c"
    break;

  case 19: /* or_concat: word opt_pad OR deamerreserved_arrow__word__  */
#line 356 "./dregx_parser.y"
                                                      {
		auto* const newNode = new dregx::ast::node::or_concat({::dregx::ast::Type::or_concat, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (yyvsp[-3].dregx_word), (yyvsp[-2].dregx_opt_pad), new dregx::ast::node::OR({::dregx::ast::Type::OR, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[-1].Terminal) }), (yyvsp[0].dregx_deamerreserved_arrow__word__) });
		(yyval.dregx_or_concat) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2031 "dregx_parser.tab.c"
    break;

  case 20: /* deamerreserved_arrow__word__: word deamerreserved_star__opt_pad__OR__word__  */
#line 366 "./dregx_parser.y"
                                                       {
		auto* const newNode = new dregx::ast::node::deamerreserved_arrow__word__({::dregx::ast::Type::deamerreserved_arrow__word__, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, { (yyvsp[-1].dregx_word), (yyvsp[0].dregx_deamerreserved_star__opt_pad__OR__word__) });
		(yyval.dregx_deamerreserved_arrow__word__) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2042 "dregx_parser.tab.c"
    break;

  case 21: /* deamerreserved_star__opt_pad__OR__word__: opt_pad OR word deamerreserved_star__opt_pad__OR__word__  */
#line 376 "./dregx_parser.y"
                                                                  {
		auto* const newNode = new dregx::ast::node::deamerreserved_star__opt_pad__OR__word__({::dregx::ast::Type::deamerreserved_star__opt_pad__OR__word__, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, { (yyvsp[-3].dregx_opt_pad), new dregx::ast::node::OR({::dregx::ast::Type::OR, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[-2].Terminal) }), (yyvsp[-1].dregx_word), (yyvsp[0].dregx_deamerreserved_star__opt_pad__OR__word__) });
		(yyval.dregx_deamerreserved_star__opt_pad__OR__word__) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2053 "dregx_parser.tab.c"
    break;

  case 22: /* deamerreserved_star__opt_pad__OR__word__: %empty  */
#line 382 "./dregx_parser.y"
           {
		auto* const newNode = new dregx::ast::node::deamerreserved_star__opt_pad__OR__word__({::dregx::ast::Type::deamerreserved_star__opt_pad__OR__word__, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, {  });
		(yyval.dregx_deamerreserved_star__opt_pad__OR__word__) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2064 "dregx_parser.tab.c"
    break;

  case 23: /* square: capture extension_modifier  */
#line 392 "./dregx_parser.y"
                                    {
		auto* const newNode = new dregx::ast::node::square({::dregx::ast::Type::square, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (yyvsp[-1].dregx_capture), (yyvsp[0].dregx_extension_modifier) });
		(yyval.dregx_square) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2075 "dregx_parser.tab.c"
    break;

  case 24: /* square: capture PLUS  */
#line 398 "./dregx_parser.y"
                        {
		auto* const newNode = new dregx::ast::node::square({::dregx::ast::Type::square, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (yyvsp[-1].dregx_capture), new dregx::ast::node::PLUS({::dregx::ast::Type::PLUS, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[0].Terminal) }) });
		(yyval.dregx_square) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2086 "dregx_parser.tab.c"
    break;

  case 25: /* square: capture STAR  */
#line 404 "./dregx_parser.y"
                        {
		auto* const newNode = new dregx::ast::node::square({::dregx::ast::Type::square, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 2, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (yyvsp[-1].dregx_capture), new dregx::ast::node::STAR({::dregx::ast::Type::STAR, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[0].Terminal) }) });
		(yyval.dregx_square) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2097 "dregx_parser.tab.c"
    break;

  case 26: /* square: capture  */
#line 410 "./dregx_parser.y"
                   {
		auto* const newNode = new dregx::ast::node::square({::dregx::ast::Type::square, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 3, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (yyvsp[0].dregx_capture) });
		(yyval.dregx_square) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2108 "dregx_parser.tab.c"
    break;

  case 27: /* capture: opt_pad LEFT_SQUARE_BRACKET_NOT deamerreserved_plus__capture_logic__ RIGHT_SQUARE_BRACKET  */
#line 420 "./dregx_parser.y"
                                                                                                   {
		auto* const newNode = new dregx::ast::node::capture({::dregx::ast::Type::capture, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (yyvsp[-3].dregx_opt_pad), new dregx::ast::node::LEFT_SQUARE_BRACKET_NOT({::dregx::ast::Type::LEFT_SQUARE_BRACKET_NOT, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[-2].Terminal) }), (yyvsp[-1].dregx_deamerreserved_plus__capture_logic__), new dregx::ast::node::RIGHT_SQUARE_BRACKET({::dregx::ast::Type::RIGHT_SQUARE_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[0].Terminal) }) });
		(yyval.dregx_capture) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2119 "dregx_parser.tab.c"
    break;

  case 28: /* capture: opt_pad LEFT_SQUARE_BRACKET deamerreserved_plus__capture_logic__ RIGHT_SQUARE_BRACKET  */
#line 426 "./dregx_parser.y"
                                                                                                 {
		auto* const newNode = new dregx::ast::node::capture({::dregx::ast::Type::capture, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (yyvsp[-3].dregx_opt_pad), new dregx::ast::node::LEFT_SQUARE_BRACKET({::dregx::ast::Type::LEFT_SQUARE_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[-2].Terminal) }), (yyvsp[-1].dregx_deamerreserved_plus__capture_logic__), new dregx::ast::node::RIGHT_SQUARE_BRACKET({::dregx::ast::Type::RIGHT_SQUARE_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[0].Terminal) }) });
		(yyval.dregx_capture) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2130 "dregx_parser.tab.c"
    break;

  case 29: /* deamerreserved_plus__capture_logic__: capture_logic  */
#line 436 "./dregx_parser.y"
                       {
		auto* const newNode = new dregx::ast::node::deamerreserved_plus__capture_logic__({::dregx::ast::Type::deamerreserved_plus__capture_logic__, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, { (yyvsp[0].dregx_capture_logic) });
		(yyval.dregx_deamerreserved_plus__capture_logic__) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2141 "dregx_parser.tab.c"
    break;

  case 30: /* deamerreserved_plus__capture_logic__: capture_logic deamerreserved_plus__capture_logic__  */
#line 442 "./dregx_parser.y"
                                                              {
		auto* const newNode = new dregx::ast::node::deamerreserved_plus__capture_logic__({::dregx::ast::Type::deamerreserved_plus__capture_logic__, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, { (yyvsp[-1].dregx_capture_logic), (yyvsp[0].dregx_deamerreserved_plus__capture_logic__) });
		(yyval.dregx_deamerreserved_plus__capture_logic__) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2152 "dregx_parser.tab.c"
    break;

  case 31: /* capture_logic: capture_range  */
#line 452 "./dregx_parser.y"
                       {
		auto* const newNode = new dregx::ast::node::capture_logic({::dregx::ast::Type::capture_logic, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (yyvsp[0].dregx_capture_range) });
		(yyval.dregx_capture_logic) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2163 "dregx_parser.tab.c"
    break;

  case 32: /* capture_logic: capture_special_character  */
#line 458 "./dregx_parser.y"
                                     {
		auto* const newNode = new dregx::ast::node::capture_logic({::dregx::ast::Type::capture_logic, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (yyvsp[0].dregx_capture_special_character) });
		(yyval.dregx_capture_logic) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2174 "dregx_parser.tab.c"
    break;

  case 33: /* capture_logic: capture_letter  */
#line 464 "./dregx_parser.y"
                          {
		auto* const newNode = new dregx::ast::node::capture_logic({::dregx::ast::Type::capture_logic, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 2, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (yyvsp[0].dregx_capture_letter) });
		(yyval.dregx_capture_logic) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2185 "dregx_parser.tab.c"
    break;

  case 34: /* capture_logic: capture_whitespace  */
#line 470 "./dregx_parser.y"
                              {
		auto* const newNode = new dregx::ast::node::capture_logic({::dregx::ast::Type::capture_logic, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 3, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (yyvsp[0].dregx_capture_whitespace) });
		(yyval.dregx_capture_logic) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2196 "dregx_parser.tab.c"
    break;

  case 35: /* capture_logic: capture_symbols  */
#line 476 "./dregx_parser.y"
                           {
		auto* const newNode = new dregx::ast::node::capture_logic({::dregx::ast::Type::capture_logic, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 4, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (yyvsp[0].dregx_capture_symbols) });
		(yyval.dregx_capture_logic) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2207 "dregx_parser.tab.c"
    break;

  case 36: /* capture_symbols: OTHER  */
#line 486 "./dregx_parser.y"
               {
		auto* const newNode = new dregx::ast::node::capture_symbols({::dregx::ast::Type::capture_symbols, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::OTHER({::dregx::ast::Type::OTHER, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[0].Terminal) }) });
		(yyval.dregx_capture_symbols) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2218 "dregx_parser.tab.c"
    break;

  case 37: /* capture_symbols: PLUS  */
#line 492 "./dregx_parser.y"
                {
		auto* const newNode = new dregx::ast::node::capture_symbols({::dregx::ast::Type::capture_symbols, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::PLUS({::dregx::ast::Type::PLUS, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[0].Terminal) }) });
		(yyval.dregx_capture_symbols) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2229 "dregx_parser.tab.c"
    break;

  case 38: /* capture_symbols: STAR  */
#line 498 "./dregx_parser.y"
                {
		auto* const newNode = new dregx::ast::node::capture_symbols({::dregx::ast::Type::capture_symbols, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 2, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::STAR({::dregx::ast::Type::STAR, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[0].Terminal) }) });
		(yyval.dregx_capture_symbols) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2240 "dregx_parser.tab.c"
    break;

  case 39: /* capture_symbols: COMMA  */
#line 504 "./dregx_parser.y"
                 {
		auto* const newNode = new dregx::ast::node::capture_symbols({::dregx::ast::Type::capture_symbols, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 3, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::COMMA({::dregx::ast::Type::COMMA, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[0].Terminal) }) });
		(yyval.dregx_capture_symbols) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2251 "dregx_parser.tab.c"
    break;

  case 40: /* capture_symbols: OR  */
#line 510 "./dregx_parser.y"
              {
		auto* const newNode = new dregx::ast::node::capture_symbols({::dregx::ast::Type::capture_symbols, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 4, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::OR({::dregx::ast::Type::OR, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[0].Terminal) }) });
		(yyval.dregx_capture_symbols) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2262 "dregx_parser.tab.c"
    break;

  case 41: /* capture_whitespace: SPACE  */
#line 520 "./dregx_parser.y"
               {
		auto* const newNode = new dregx::ast::node::capture_whitespace({::dregx::ast::Type::capture_whitespace, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::SPACE({::dregx::ast::Type::SPACE, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[0].Terminal) }) });
		(yyval.dregx_capture_whitespace) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2273 "dregx_parser.tab.c"
    break;

  case 42: /* capture_whitespace: TAB  */
#line 526 "./dregx_parser.y"
               {
		auto* const newNode = new dregx::ast::node::capture_whitespace({::dregx::ast::Type::capture_whitespace, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::TAB({::dregx::ast::Type::TAB, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[0].Terminal) }) });
		(yyval.dregx_capture_whitespace) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2284 "dregx_parser.tab.c"
    break;

  case 43: /* capture_range: capture_letter_range  */
#line 536 "./dregx_parser.y"
                              {
		auto* const newNode = new dregx::ast::node::capture_range({::dregx::ast::Type::capture_range, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (yyvsp[0].dregx_capture_letter_range) });
		(yyval.dregx_capture_range) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2295 "dregx_parser.tab.c"
    break;

  case 44: /* capture_range: capture_number_range  */
#line 542 "./dregx_parser.y"
                                {
		auto* const newNode = new dregx::ast::node::capture_range({::dregx::ast::Type::capture_range, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (yyvsp[0].dregx_capture_number_range) });
		(yyval.dregx_capture_range) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2306 "dregx_parser.tab.c"
    break;

  case 45: /* capture_letter_range: any_letter_exclude_underscore MIN any_letter_exclude_underscore  */
#line 552 "./dregx_parser.y"
                                                                         {
		auto* const newNode = new dregx::ast::node::capture_letter_range({::dregx::ast::Type::capture_letter_range, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (yyvsp[-2].dregx_any_letter_exclude_underscore), new dregx::ast::node::MIN({::dregx::ast::Type::MIN, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[-1].Terminal) }), (yyvsp[0].dregx_any_letter_exclude_underscore) });
		(yyval.dregx_capture_letter_range) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2317 "dregx_parser.tab.c"
    break;

  case 46: /* capture_number_range: NUMBER MIN NUMBER  */
#line 562 "./dregx_parser.y"
                           {
		auto* const newNode = new dregx::ast::node::capture_number_range({::dregx::ast::Type::capture_number_range, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::NUMBER({::dregx::ast::Type::NUMBER, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[-2].Terminal) }), new dregx::ast::node::MIN({::dregx::ast::Type::MIN, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[-1].Terminal) }), new dregx::ast::node::NUMBER({::dregx::ast::Type::NUMBER, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[0].Terminal) }) });
		(yyval.dregx_capture_number_range) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2328 "dregx_parser.tab.c"
    break;

  case 47: /* capture_letter: any_letter  */
#line 572 "./dregx_parser.y"
                    {
		auto* const newNode = new dregx::ast::node::capture_letter({::dregx::ast::Type::capture_letter, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (yyvsp[0].dregx_any_letter) });
		(yyval.dregx_capture_letter) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2339 "dregx_parser.tab.c"
    break;

  case 48: /* capture_special_character: special_char_any  */
#line 582 "./dregx_parser.y"
                          {
		auto* const newNode = new dregx::ast::node::capture_special_character({::dregx::ast::Type::capture_special_character, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (yyvsp[0].dregx_special_char_any) });
		(yyval.dregx_capture_special_character) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2350 "dregx_parser.tab.c"
    break;

  case 49: /* extension_modifier: opt_pad LEFT_BRACKET min_repition opt_pad COMMA max_repition opt_pad RIGHT_BRACKET  */
#line 592 "./dregx_parser.y"
                                                                                            {
		auto* const newNode = new dregx::ast::node::extension_modifier({::dregx::ast::Type::extension_modifier, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (yyvsp[-7].dregx_opt_pad), new dregx::ast::node::LEFT_BRACKET({::dregx::ast::Type::LEFT_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[-6].Terminal) }), (yyvsp[-5].dregx_min_repition), (yyvsp[-4].dregx_opt_pad), new dregx::ast::node::COMMA({::dregx::ast::Type::COMMA, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[-3].Terminal) }), (yyvsp[-2].dregx_max_repition), (yyvsp[-1].dregx_opt_pad), new dregx::ast::node::RIGHT_BRACKET({::dregx::ast::Type::RIGHT_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[0].Terminal) }) });
		(yyval.dregx_extension_modifier) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2361 "dregx_parser.tab.c"
    break;

  case 50: /* min_repition: opt_pad deamerreserved_plus__NUMBER__  */
#line 602 "./dregx_parser.y"
                                               {
		auto* const newNode = new dregx::ast::node::min_repition({::dregx::ast::Type::min_repition, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (yyvsp[-1].dregx_opt_pad), (yyvsp[0].dregx_deamerreserved_plus__NUMBER__) });
		(yyval.dregx_min_repition) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2372 "dregx_parser.tab.c"
    break;

  case 51: /* deamerreserved_plus__NUMBER__: NUMBER  */
#line 612 "./dregx_parser.y"
                {
		auto* const newNode = new dregx::ast::node::deamerreserved_plus__NUMBER__({::dregx::ast::Type::deamerreserved_plus__NUMBER__, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, { new dregx::ast::node::NUMBER({::dregx::ast::Type::NUMBER, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[0].Terminal) }) });
		(yyval.dregx_deamerreserved_plus__NUMBER__) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2383 "dregx_parser.tab.c"
    break;

  case 52: /* deamerreserved_plus__NUMBER__: NUMBER deamerreserved_plus__NUMBER__  */
#line 618 "./dregx_parser.y"
                                                {
		auto* const newNode = new dregx::ast::node::deamerreserved_plus__NUMBER__({::dregx::ast::Type::deamerreserved_plus__NUMBER__, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, { new dregx::ast::node::NUMBER({::dregx::ast::Type::NUMBER, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[-1].Terminal) }), (yyvsp[0].dregx_deamerreserved_plus__NUMBER__) });
		(yyval.dregx_deamerreserved_plus__NUMBER__) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2394 "dregx_parser.tab.c"
    break;

  case 53: /* max_repition: opt_pad deamerreserved_plus__NUMBER__  */
#line 628 "./dregx_parser.y"
                                               {
		auto* const newNode = new dregx::ast::node::max_repition({::dregx::ast::Type::max_repition, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (yyvsp[-1].dregx_opt_pad), (yyvsp[0].dregx_deamerreserved_plus__NUMBER__) });
		(yyval.dregx_max_repition) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2405 "dregx_parser.tab.c"
    break;

  case 54: /* standalone: opt_pad deamerreserved_plus__any_letter__  */
#line 638 "./dregx_parser.y"
                                                   {
		auto* const newNode = new dregx::ast::node::standalone({::dregx::ast::Type::standalone, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (yyvsp[-1].dregx_opt_pad), (yyvsp[0].dregx_deamerreserved_plus__any_letter__) });
		(yyval.dregx_standalone) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2416 "dregx_parser.tab.c"
    break;

  case 55: /* deamerreserved_plus__any_letter__: any_letter  */
#line 648 "./dregx_parser.y"
                    {
		auto* const newNode = new dregx::ast::node::deamerreserved_plus__any_letter__({::dregx::ast::Type::deamerreserved_plus__any_letter__, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, { (yyvsp[0].dregx_any_letter) });
		(yyval.dregx_deamerreserved_plus__any_letter__) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2427 "dregx_parser.tab.c"
    break;

  case 56: /* deamerreserved_plus__any_letter__: any_letter deamerreserved_plus__any_letter__  */
#line 654 "./dregx_parser.y"
                                                        {
		auto* const newNode = new dregx::ast::node::deamerreserved_plus__any_letter__({::dregx::ast::Type::deamerreserved_plus__any_letter__, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, { (yyvsp[-1].dregx_any_letter), (yyvsp[0].dregx_deamerreserved_plus__any_letter__) });
		(yyval.dregx_deamerreserved_plus__any_letter__) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2438 "dregx_parser.tab.c"
    break;

  case 57: /* opt_pad: optional_padding  */
#line 664 "./dregx_parser.y"
                          {
		auto* const newNode = new dregx::ast::node::opt_pad({::dregx::ast::Type::opt_pad, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (yyvsp[0].dregx_optional_padding) });
		(yyval.dregx_opt_pad) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2449 "dregx_parser.tab.c"
    break;

  case 58: /* optional_padding: deamerreserved_star__padding__  */
#line 674 "./dregx_parser.y"
                                        {
		auto* const newNode = new dregx::ast::node::optional_padding({::dregx::ast::Type::optional_padding, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (yyvsp[0].dregx_deamerreserved_star__padding__) });
		(yyval.dregx_optional_padding) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2460 "dregx_parser.tab.c"
    break;

  case 59: /* deamerreserved_star__padding__: padding deamerreserved_star__padding__  */
#line 684 "./dregx_parser.y"
                                                {
		auto* const newNode = new dregx::ast::node::deamerreserved_star__padding__({::dregx::ast::Type::deamerreserved_star__padding__, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, { (yyvsp[-1].dregx_padding), (yyvsp[0].dregx_deamerreserved_star__padding__) });
		(yyval.dregx_deamerreserved_star__padding__) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2471 "dregx_parser.tab.c"
    break;

  case 60: /* deamerreserved_star__padding__: %empty  */
#line 690 "./dregx_parser.y"
           {
		auto* const newNode = new dregx::ast::node::deamerreserved_star__padding__({::dregx::ast::Type::deamerreserved_star__padding__, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::translation }}, {  });
		(yyval.dregx_deamerreserved_star__padding__) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2482 "dregx_parser.tab.c"
    break;

  case 61: /* padding: SPACE  */
#line 700 "./dregx_parser.y"
               {
		auto* const newNode = new dregx::ast::node::padding({::dregx::ast::Type::padding, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::SPACE({::dregx::ast::Type::SPACE, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[0].Terminal) }) });
		(yyval.dregx_padding) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2493 "dregx_parser.tab.c"
    break;

  case 62: /* padding: TAB  */
#line 706 "./dregx_parser.y"
               {
		auto* const newNode = new dregx::ast::node::padding({::dregx::ast::Type::padding, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::TAB({::dregx::ast::Type::TAB, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[0].Terminal) }) });
		(yyval.dregx_padding) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2504 "dregx_parser.tab.c"
    break;

  case 63: /* special_char_any: SLASH any  */
#line 716 "./dregx_parser.y"
                   {
		auto* const newNode = new dregx::ast::node::special_char_any({::dregx::ast::Type::special_char_any, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::SLASH({::dregx::ast::Type::SLASH, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[-1].Terminal) }), (yyvsp[0].dregx_any) });
		(yyval.dregx_special_char_any) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2515 "dregx_parser.tab.c"
    break;

  case 64: /* any_letter: any_letter_exclude_underscore  */
#line 726 "./dregx_parser.y"
                                       {
		auto* const newNode = new dregx::ast::node::any_letter({::dregx::ast::Type::any_letter, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { (yyvsp[0].dregx_any_letter_exclude_underscore) });
		(yyval.dregx_any_letter) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2526 "dregx_parser.tab.c"
    break;

  case 65: /* any_letter: UNDERSCORE  */
#line 732 "./dregx_parser.y"
                      {
		auto* const newNode = new dregx::ast::node::any_letter({::dregx::ast::Type::any_letter, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::UNDERSCORE({::dregx::ast::Type::UNDERSCORE, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[0].Terminal) }) });
		(yyval.dregx_any_letter) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2537 "dregx_parser.tab.c"
    break;

  case 66: /* any_letter_exclude_underscore: T_  */
#line 742 "./dregx_parser.y"
            {
		auto* const newNode = new dregx::ast::node::any_letter_exclude_underscore({::dregx::ast::Type::any_letter_exclude_underscore, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::T_({::dregx::ast::Type::T_, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[0].Terminal) }) });
		(yyval.dregx_any_letter_exclude_underscore) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2548 "dregx_parser.tab.c"
    break;

  case 67: /* any_letter_exclude_underscore: R_  */
#line 748 "./dregx_parser.y"
              {
		auto* const newNode = new dregx::ast::node::any_letter_exclude_underscore({::dregx::ast::Type::any_letter_exclude_underscore, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::R_({::dregx::ast::Type::R_, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[0].Terminal) }) });
		(yyval.dregx_any_letter_exclude_underscore) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2559 "dregx_parser.tab.c"
    break;

  case 68: /* any_letter_exclude_underscore: N_  */
#line 754 "./dregx_parser.y"
              {
		auto* const newNode = new dregx::ast::node::any_letter_exclude_underscore({::dregx::ast::Type::any_letter_exclude_underscore, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 2, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::N_({::dregx::ast::Type::N_, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[0].Terminal) }) });
		(yyval.dregx_any_letter_exclude_underscore) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2570 "dregx_parser.tab.c"
    break;

  case 69: /* any_letter_exclude_underscore: B_  */
#line 760 "./dregx_parser.y"
              {
		auto* const newNode = new dregx::ast::node::any_letter_exclude_underscore({::dregx::ast::Type::any_letter_exclude_underscore, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 3, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::B_({::dregx::ast::Type::B_, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[0].Terminal) }) });
		(yyval.dregx_any_letter_exclude_underscore) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2581 "dregx_parser.tab.c"
    break;

  case 70: /* any_letter_exclude_underscore: V_  */
#line 766 "./dregx_parser.y"
              {
		auto* const newNode = new dregx::ast::node::any_letter_exclude_underscore({::dregx::ast::Type::any_letter_exclude_underscore, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 4, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::V_({::dregx::ast::Type::V_, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[0].Terminal) }) });
		(yyval.dregx_any_letter_exclude_underscore) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2592 "dregx_parser.tab.c"
    break;

  case 71: /* any_letter_exclude_underscore: A_  */
#line 772 "./dregx_parser.y"
              {
		auto* const newNode = new dregx::ast::node::any_letter_exclude_underscore({::dregx::ast::Type::any_letter_exclude_underscore, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 5, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::A_({::dregx::ast::Type::A_, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[0].Terminal) }) });
		(yyval.dregx_any_letter_exclude_underscore) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2603 "dregx_parser.tab.c"
    break;

  case 72: /* any_letter_exclude_underscore: LETTER  */
#line 778 "./dregx_parser.y"
                  {
		auto* const newNode = new dregx::ast::node::any_letter_exclude_underscore({::dregx::ast::Type::any_letter_exclude_underscore, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 6, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::LETTER({::dregx::ast::Type::LETTER, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[0].Terminal) }) });
		(yyval.dregx_any_letter_exclude_underscore) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2614 "dregx_parser.tab.c"
    break;

  case 73: /* any: LEFT_CURLY_BRACKET  */
#line 788 "./dregx_parser.y"
                            {
		auto* const newNode = new dregx::ast::node::any({::dregx::ast::Type::any, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 0, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::LEFT_CURLY_BRACKET({::dregx::ast::Type::LEFT_CURLY_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[0].Terminal) }) });
		(yyval.dregx_any) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2625 "dregx_parser.tab.c"
    break;

  case 74: /* any: RIGHT_CURLY_BRACKET  */
#line 794 "./dregx_parser.y"
                               {
		auto* const newNode = new dregx::ast::node::any({::dregx::ast::Type::any, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 1, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::RIGHT_CURLY_BRACKET({::dregx::ast::Type::RIGHT_CURLY_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[0].Terminal) }) });
		(yyval.dregx_any) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2636 "dregx_parser.tab.c"
    break;

  case 75: /* any: LEFT_SQUARE_BRACKET  */
#line 800 "./dregx_parser.y"
                               {
		auto* const newNode = new dregx::ast::node::any({::dregx::ast::Type::any, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 2, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::LEFT_SQUARE_BRACKET({::dregx::ast::Type::LEFT_SQUARE_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[0].Terminal) }) });
		(yyval.dregx_any) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2647 "dregx_parser.tab.c"
    break;

  case 76: /* any: RIGHT_SQUARE_BRACKET  */
#line 806 "./dregx_parser.y"
                                {
		auto* const newNode = new dregx::ast::node::any({::dregx::ast::Type::any, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 3, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::RIGHT_SQUARE_BRACKET({::dregx::ast::Type::RIGHT_SQUARE_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[0].Terminal) }) });
		(yyval.dregx_any) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2658 "dregx_parser.tab.c"
    break;

  case 77: /* any: LEFT_BRACKET  */
#line 812 "./dregx_parser.y"
                        {
		auto* const newNode = new dregx::ast::node::any({::dregx::ast::Type::any, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 4, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::LEFT_BRACKET({::dregx::ast::Type::LEFT_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[0].Terminal) }) });
		(yyval.dregx_any) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2669 "dregx_parser.tab.c"
    break;

  case 78: /* any: RIGHT_BRACKET  */
#line 818 "./dregx_parser.y"
                         {
		auto* const newNode = new dregx::ast::node::any({::dregx::ast::Type::any, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 5, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::RIGHT_BRACKET({::dregx::ast::Type::RIGHT_BRACKET, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[0].Terminal) }) });
		(yyval.dregx_any) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2680 "dregx_parser.tab.c"
    break;

  case 79: /* any: COMMA  */
#line 824 "./dregx_parser.y"
                 {
		auto* const newNode = new dregx::ast::node::any({::dregx::ast::Type::any, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 6, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::COMMA({::dregx::ast::Type::COMMA, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[0].Terminal) }) });
		(yyval.dregx_any) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2691 "dregx_parser.tab.c"
    break;

  case 80: /* any: OR  */
#line 830 "./dregx_parser.y"
              {
		auto* const newNode = new dregx::ast::node::any({::dregx::ast::Type::any, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 7, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::OR({::dregx::ast::Type::OR, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[0].Terminal) }) });
		(yyval.dregx_any) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2702 "dregx_parser.tab.c"
    break;

  case 81: /* any: MIN  */
#line 836 "./dregx_parser.y"
               {
		auto* const newNode = new dregx::ast::node::any({::dregx::ast::Type::any, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 8, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::MIN({::dregx::ast::Type::MIN, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[0].Terminal) }) });
		(yyval.dregx_any) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2713 "dregx_parser.tab.c"
    break;

  case 82: /* any: UNDERSCORE  */
#line 842 "./dregx_parser.y"
                      {
		auto* const newNode = new dregx::ast::node::any({::dregx::ast::Type::any, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 9, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::UNDERSCORE({::dregx::ast::Type::UNDERSCORE, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[0].Terminal) }) });
		(yyval.dregx_any) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2724 "dregx_parser.tab.c"
    break;

  case 83: /* any: NOT  */
#line 848 "./dregx_parser.y"
               {
		auto* const newNode = new dregx::ast::node::any({::dregx::ast::Type::any, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 10, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::NOT({::dregx::ast::Type::NOT, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[0].Terminal) }) });
		(yyval.dregx_any) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2735 "dregx_parser.tab.c"
    break;

  case 84: /* any: NUMBER  */
#line 854 "./dregx_parser.y"
                  {
		auto* const newNode = new dregx::ast::node::any({::dregx::ast::Type::any, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 11, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::NUMBER({::dregx::ast::Type::NUMBER, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[0].Terminal) }) });
		(yyval.dregx_any) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2746 "dregx_parser.tab.c"
    break;

  case 85: /* any: T_  */
#line 860 "./dregx_parser.y"
              {
		auto* const newNode = new dregx::ast::node::any({::dregx::ast::Type::any, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 12, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::T_({::dregx::ast::Type::T_, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[0].Terminal) }) });
		(yyval.dregx_any) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2757 "dregx_parser.tab.c"
    break;

  case 86: /* any: N_  */
#line 866 "./dregx_parser.y"
              {
		auto* const newNode = new dregx::ast::node::any({::dregx::ast::Type::any, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 13, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::N_({::dregx::ast::Type::N_, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[0].Terminal) }) });
		(yyval.dregx_any) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2768 "dregx_parser.tab.c"
    break;

  case 87: /* any: R_  */
#line 872 "./dregx_parser.y"
              {
		auto* const newNode = new dregx::ast::node::any({::dregx::ast::Type::any, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 14, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::R_({::dregx::ast::Type::R_, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[0].Terminal) }) });
		(yyval.dregx_any) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2779 "dregx_parser.tab.c"
    break;

  case 88: /* any: B_  */
#line 878 "./dregx_parser.y"
              {
		auto* const newNode = new dregx::ast::node::any({::dregx::ast::Type::any, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 15, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::B_({::dregx::ast::Type::B_, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[0].Terminal) }) });
		(yyval.dregx_any) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2790 "dregx_parser.tab.c"
    break;

  case 89: /* any: V_  */
#line 884 "./dregx_parser.y"
              {
		auto* const newNode = new dregx::ast::node::any({::dregx::ast::Type::any, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 16, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::V_({::dregx::ast::Type::V_, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[0].Terminal) }) });
		(yyval.dregx_any) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2801 "dregx_parser.tab.c"
    break;

  case 90: /* any: A_  */
#line 890 "./dregx_parser.y"
              {
		auto* const newNode = new dregx::ast::node::any({::dregx::ast::Type::any, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 17, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::A_({::dregx::ast::Type::A_, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[0].Terminal) }) });
		(yyval.dregx_any) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2812 "dregx_parser.tab.c"
    break;

  case 91: /* any: LETTER  */
#line 896 "./dregx_parser.y"
                  {
		auto* const newNode = new dregx::ast::node::any({::dregx::ast::Type::any, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 18, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::LETTER({::dregx::ast::Type::LETTER, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[0].Terminal) }) });
		(yyval.dregx_any) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2823 "dregx_parser.tab.c"
    break;

  case 92: /* any: SPACE  */
#line 902 "./dregx_parser.y"
                 {
		auto* const newNode = new dregx::ast::node::any({::dregx::ast::Type::any, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 19, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::SPACE({::dregx::ast::Type::SPACE, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[0].Terminal) }) });
		(yyval.dregx_any) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2834 "dregx_parser.tab.c"
    break;

  case 93: /* any: TAB  */
#line 908 "./dregx_parser.y"
               {
		auto* const newNode = new dregx::ast::node::any({::dregx::ast::Type::any, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 20, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::TAB({::dregx::ast::Type::TAB, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[0].Terminal) }) });
		(yyval.dregx_any) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2845 "dregx_parser.tab.c"
    break;

  case 94: /* any: PLUS  */
#line 914 "./dregx_parser.y"
                {
		auto* const newNode = new dregx::ast::node::any({::dregx::ast::Type::any, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 21, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::PLUS({::dregx::ast::Type::PLUS, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[0].Terminal) }) });
		(yyval.dregx_any) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2856 "dregx_parser.tab.c"
    break;

  case 95: /* any: STAR  */
#line 920 "./dregx_parser.y"
                {
		auto* const newNode = new dregx::ast::node::any({::dregx::ast::Type::any, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 22, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::STAR({::dregx::ast::Type::STAR, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[0].Terminal) }) });
		(yyval.dregx_any) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2867 "dregx_parser.tab.c"
    break;

  case 96: /* any: OTHER  */
#line 926 "./dregx_parser.y"
                 {
		auto* const newNode = new dregx::ast::node::any({::dregx::ast::Type::any, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 23, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::OTHER({::dregx::ast::Type::OTHER, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[0].Terminal) }) });
		(yyval.dregx_any) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2878 "dregx_parser.tab.c"
    break;

  case 97: /* any: SLASH  */
#line 932 "./dregx_parser.y"
                 {
		auto* const newNode = new dregx::ast::node::any({::dregx::ast::Type::any, ::deamer::external::cpp::ast::NodeValue::nonterminal, { 24, ::deamer::external::cpp::ast::ProductionRuleType::user }}, { new dregx::ast::node::SLASH({::dregx::ast::Type::SLASH, ::deamer::external::cpp::ast::NodeValue::terminal, (yyvsp[0].Terminal) }) });
		(yyval.dregx_any) = newNode;

		// Ignored, Deleted, tokens are deleted
	}
#line 2889 "dregx_parser.tab.c"
    break;


#line 2893 "dregx_parser.tab.c"

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

#line 942 "./dregx_parser.y"


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
