#include "dregx/Bison/Parser.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <iostream>
#include <memory>

class TestParserInput : public testing::Test
{
public:
protected:
	TestParserInput() = default;

	virtual ~TestParserInput() = default;

public:
	dregx::parser::Parser parser;
};

// clang-format off
// #define DEBUG
#ifdef DEBUG
#define TEST_DEBUG_PRINT { std::cout << "under test: \"" << regex << "\"\n"; }
#else
#define TEST_DEBUG_PRINT
#endif
#define TEST_INPUT_SOME_LETTERS(letter) { const auto regex = std::string("[") + #letter + "]"; TEST_DEBUG_PRINT; std::unique_ptr<::deamer::external::cpp::ast::Tree> letter_tree(parser.Parse(regex)); ASSERT_NE(nullptr, letter_tree); }
// clang-format on

TEST_F(TestParserInput, REGEX_WithOne_LETTER)
{
	TEST_INPUT_SOME_LETTERS(a);
	TEST_INPUT_SOME_LETTERS(b);
	TEST_INPUT_SOME_LETTERS(c);
	TEST_INPUT_SOME_LETTERS(d);
	TEST_INPUT_SOME_LETTERS(e);
	TEST_INPUT_SOME_LETTERS(f);
	TEST_INPUT_SOME_LETTERS(g);
	TEST_INPUT_SOME_LETTERS(h);
	TEST_INPUT_SOME_LETTERS(i);
	TEST_INPUT_SOME_LETTERS(j);
	TEST_INPUT_SOME_LETTERS(k);
	TEST_INPUT_SOME_LETTERS(l);
	TEST_INPUT_SOME_LETTERS(m);
	TEST_INPUT_SOME_LETTERS(n);
	TEST_INPUT_SOME_LETTERS(o);
	TEST_INPUT_SOME_LETTERS(p);
	TEST_INPUT_SOME_LETTERS(q);
	TEST_INPUT_SOME_LETTERS(r);
	TEST_INPUT_SOME_LETTERS(s);
	TEST_INPUT_SOME_LETTERS(t);
	TEST_INPUT_SOME_LETTERS(u);
	TEST_INPUT_SOME_LETTERS(v);
	TEST_INPUT_SOME_LETTERS(w);
	TEST_INPUT_SOME_LETTERS(x);
	TEST_INPUT_SOME_LETTERS(y);
	TEST_INPUT_SOME_LETTERS(z);

	TEST_INPUT_SOME_LETTERS(A);
	TEST_INPUT_SOME_LETTERS(B);
	TEST_INPUT_SOME_LETTERS(C);
	TEST_INPUT_SOME_LETTERS(D);
	TEST_INPUT_SOME_LETTERS(E);
	TEST_INPUT_SOME_LETTERS(F);
	TEST_INPUT_SOME_LETTERS(G);
	TEST_INPUT_SOME_LETTERS(H);
	TEST_INPUT_SOME_LETTERS(I);
	TEST_INPUT_SOME_LETTERS(J);
	TEST_INPUT_SOME_LETTERS(K);
	TEST_INPUT_SOME_LETTERS(L);
	TEST_INPUT_SOME_LETTERS(M);
	TEST_INPUT_SOME_LETTERS(N);
	TEST_INPUT_SOME_LETTERS(O);
	TEST_INPUT_SOME_LETTERS(P);
	TEST_INPUT_SOME_LETTERS(Q);
	TEST_INPUT_SOME_LETTERS(R);
	TEST_INPUT_SOME_LETTERS(S);
	TEST_INPUT_SOME_LETTERS(T);
	TEST_INPUT_SOME_LETTERS(U);
	TEST_INPUT_SOME_LETTERS(V);
	TEST_INPUT_SOME_LETTERS(W);
	TEST_INPUT_SOME_LETTERS(X);
	TEST_INPUT_SOME_LETTERS(Y);
	TEST_INPUT_SOME_LETTERS(Z);
}

TEST_F(TestParserInput, REGEX_WithTwoLetters_ShouldCorrectlyParse)
{
	TEST_INPUT_SOME_LETTERS(aa);
	TEST_INPUT_SOME_LETTERS(ab);
	TEST_INPUT_SOME_LETTERS(ac);
	TEST_INPUT_SOME_LETTERS(ad);
	TEST_INPUT_SOME_LETTERS(ae);
	TEST_INPUT_SOME_LETTERS(af);
	TEST_INPUT_SOME_LETTERS(ag);
	TEST_INPUT_SOME_LETTERS(ah);
	TEST_INPUT_SOME_LETTERS(ai);
	TEST_INPUT_SOME_LETTERS(aj);
	TEST_INPUT_SOME_LETTERS(an);
	TEST_INPUT_SOME_LETTERS(at);
	TEST_INPUT_SOME_LETTERS(ar);
}

TEST_F(TestParserInput, Regex_NewlineCharacter_ShouldCorrectlyParse)
{
	std::unique_ptr<::deamer::external::cpp::ast::Tree> tree(parser.Parse("[\\n]"));
	ASSERT_NE(nullptr, tree);
}

TEST_F(TestParserInput, Regex_CarriageReturnCharacter_ShouldCorrectlyParse)
{
	std::unique_ptr<::deamer::external::cpp::ast::Tree> tree(parser.Parse("[\\r]"));
	ASSERT_NE(nullptr, tree);
}

TEST_F(TestParserInput, Regex_TabEscapedCharacter_ShouldCorrectlyParse)
{
	std::unique_ptr<::deamer::external::cpp::ast::Tree> tree(parser.Parse("[\\t]"));
	ASSERT_NE(nullptr, tree);
}

TEST_F(TestParserInput, Regex_BEscapedCharacter_ShouldCorrectlyParse)
{
	std::unique_ptr<::deamer::external::cpp::ast::Tree> tree(parser.Parse("[\\B]"));
	ASSERT_NE(nullptr, tree);
}

TEST_F(TestParserInput, Regex_QEscapedCharacter_ShouldCorrectlyParse)
{
	std::unique_ptr<::deamer::external::cpp::ast::Tree> tree(parser.Parse("[\\Q]"));
	ASSERT_NE(nullptr, tree);
}

TEST_F(TestParserInput, Regex_tab_ShouldCorrectlyParse)
{
	std::unique_ptr<::deamer::external::cpp::ast::Tree> tree(parser.Parse("[	]"));
	ASSERT_NE(nullptr, tree);
}

TEST_F(TestParserInput, Regex_space_ShouldCorrectlyParse)
{
	std::unique_ptr<::deamer::external::cpp::ast::Tree> tree(parser.Parse("[ ]"));
	ASSERT_NE(nullptr, tree);
}

TEST_F(TestParserInput, Regex_not_space_ShouldCorrectlyParse)
{
	std::unique_ptr<::deamer::external::cpp::ast::Tree> tree(parser.Parse("[^ ]"));
	ASSERT_NE(nullptr, tree);
}

TEST_F(TestParserInput, Regex_LEFT_BRACKET_ShouldCorrectlyParse)
{
	std::unique_ptr<::deamer::external::cpp::ast::Tree> tree(parser.Parse("[{]"));
	ASSERT_NE(nullptr, tree);
}

TEST_F(TestParserInput, Regex_RIGHT_BRACKET_ShouldCorrectlyParse)
{
	std::unique_ptr<::deamer::external::cpp::ast::Tree> tree(parser.Parse("[}]"));
	ASSERT_NE(nullptr, tree);
}

TEST_F(TestParserInput, Regex_LEFT_CURLY_BRACKET_ShouldCorrectlyParse)
{
	std::unique_ptr<::deamer::external::cpp::ast::Tree> tree(parser.Parse("[(]"));
	ASSERT_NE(nullptr, tree);
}

TEST_F(TestParserInput, Regex_RIGHT_CURLY_BRACKET_ShouldCorrectlyParse)
{
	std::unique_ptr<::deamer::external::cpp::ast::Tree> tree(parser.Parse("[)]"));
	ASSERT_NE(nullptr, tree);
}

TEST_F(TestParserInput, Regex_LEFT_SQUARE_BRACKET_ShouldCorrectlyParse)
{
	std::unique_ptr<::deamer::external::cpp::ast::Tree> tree(parser.Parse("[[]"));
	ASSERT_NE(nullptr, tree);
}

TEST_F(TestParserInput, Regex_DLDLv1_RegexMatcher_ShouldCorrectlyParse)
{
	// This is a complex but valid regex
	std::unique_ptr<::deamer::external::cpp::ast::Tree> tree(parser.Parse(
		"(([\\[][^\\]]+[\\]\\s\\\\a-zA-Z_0-9\\}\\{\\&\\#\\@\\%\\$]*[\\]](([\\{][\\s]*[0-9]+[\\s]*[,"
		"]["
		"\\s]*[0-9]+[\\s]*[\\}])|([+*]{0,1}))([\\)]*)[|]{0,1})|([\\^]{0,1}[\\(][^\\)]+[\\)\\sa-"
		"zA-Z_0-9\\[\\]\\}\\{\\&\\#\\@\\%\\$]*[\\)][\\]]{0,1}(([\\{][\\s]*[0-9]+[\\s]*[,][\\s]*[0-"
		"9]+"
		"[\\s]*[\\}])|([+*]{0,1}))((([|\\)]*))[+*]{0,1}[$]{0,1}))|([a-zA-Z_0-9]+))+"));
	ASSERT_NE(nullptr, tree);
}

TEST_F(TestParserInput, Regex_NotRightSquareBracket_ShouldCorrectlyParse)
{
	std::unique_ptr<::deamer::external::cpp::ast::Tree> tree(parser.Parse("[^\\]]"));
	ASSERT_NE(nullptr, tree);
}

TEST_F(TestParserInput, Regex_GroupedNegatedRightSquareBracket_ShouldCorrectlyParse)
{
	std::unique_ptr<::deamer::external::cpp::ast::Tree> tree(parser.Parse("([^\\]])"));
	ASSERT_NE(nullptr, tree);
}

TEST_F(TestParserInput, Regex_GroupedRegexConcatenation_RegexA_RegexB_ShouldCorrectlyParse)
{
	std::unique_ptr<::deamer::external::cpp::ast::Tree> tree(parser.Parse("([a][b])"));
	ASSERT_NE(nullptr, tree);
}
TEST_F(TestParserInput, Regex_WithOrSymbol_ShouldCorrectlyParse)
{
	std::unique_ptr<::deamer::external::cpp::ast::Tree> tree(parser.Parse("[|]"));
	ASSERT_NE(nullptr, tree);
}

TEST_F(TestParserInput, Regex_WithCommaSymbol_ShouldCorrectlyParse)
{
	std::unique_ptr<::deamer::external::cpp::ast::Tree> tree(parser.Parse("[,]"));
	ASSERT_NE(nullptr, tree);
}

TEST_F(TestParserInput, Regex_WithPointSymbol_ShouldCorrectlyParse)
{
	std::unique_ptr<::deamer::external::cpp::ast::Tree> tree(parser.Parse("[.]"));
	ASSERT_NE(nullptr, tree);
}

TEST_F(TestParserInput, Regex_WithSlashSlash_ShouldCorrectlyParse)
{
	std::unique_ptr<::deamer::external::cpp::ast::Tree> tree(parser.Parse("[\\\\]"));
	ASSERT_NE(nullptr, tree);
}

TEST_F(TestParserInput, Regex_OrSequence2Elements_ShouldCorrectlyParse)
{
	std::unique_ptr<::deamer::external::cpp::ast::Tree> tree(parser.Parse("(A|B|C|D|E)"));
	ASSERT_NE(nullptr, tree);
}

TEST_F(TestParserInput, Regex_OrSequence5Elements_ShouldCorrectlyParse)
{
	std::unique_ptr<::deamer::external::cpp::ast::Tree> tree(parser.Parse("(A|B|C|D|E)"));
	ASSERT_NE(nullptr, tree);
}

TEST_F(TestParserInput, Regex_GroupSequence3Elements_ShouldCorrectlyParse)
{
	std::unique_ptr<::deamer::external::cpp::ast::Tree> tree(parser.Parse("(A)(B)(C)"));
	ASSERT_NE(nullptr, tree);
}

TEST_F(TestParserInput, Regex_SquareSequence3Elements_ShouldCorrectlyParse)
{
	std::unique_ptr<::deamer::external::cpp::ast::Tree> tree(parser.Parse("[A][B][C]"));
	ASSERT_NE(nullptr, tree);
}

TEST_F(TestParserInput, Regex_SquareAndGroupSequence5Elements_ShouldCorrectlyParse)
{
	std::unique_ptr<::deamer::external::cpp::ast::Tree> tree(parser.Parse("(A)[B][C](D)(E)"));
	ASSERT_NE(nullptr, tree);
}

TEST_F(TestParserInput, Regex_PaddedSquareAndGroupSequence5Elements_ShouldCorrectlyParse)
{
	std::unique_ptr<::deamer::external::cpp::ast::Tree> tree(
		parser.Parse("			(A)		  [B]	 [C]		 (D)+	  (E) "));
	ASSERT_NE(nullptr, tree);
}

TEST_F(TestParserInput, Regex_RegexWithPadding_ShouldCorrectlyParse)
{
	std::unique_ptr<::deamer::external::cpp::ast::Tree> tree(
		parser.Parse(" (   A| B|C   |D|		E )+		 [a] (   A| B|C   |D|		E)+		 [a]"));
	ASSERT_NE(nullptr, tree);
}

TEST_F(TestParserInput, Regex_WordWith1Character_ShouldCorrectlyParse)
{
	std::unique_ptr<::deamer::external::cpp::ast::Tree> tree(parser.Parse("a"));
	ASSERT_NE(nullptr, tree);
}

TEST_F(TestParserInput, Regex_WordWith2Character_ShouldCorrectlyParse)
{
	std::unique_ptr<::deamer::external::cpp::ast::Tree> tree(parser.Parse("ab"));
	ASSERT_NE(nullptr, tree);
}

TEST_F(TestParserInput, Regex_WordWith3Character_ShouldCorrectlyParse)
{
	std::unique_ptr<::deamer::external::cpp::ast::Tree> tree(parser.Parse("abc"));
	ASSERT_NE(nullptr, tree);
}
