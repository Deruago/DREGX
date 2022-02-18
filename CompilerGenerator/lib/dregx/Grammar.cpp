/* 
 * This file is auto-generated and auto-maintained by DLDL
 * Do not change code in this as it can be overwritten.
 *
 * For more information see the DLDL repo: https://github.com/Deruago/DLDL
 * For more information about Deamer: https://github.com/Deruago/theDeamerProject
 */

#include "dregx/Grammar.h"
#include "dregx/Language.h"

dregx::Grammar::Grammar(dregx::Language* language)
			:	::deamer::language::generator::definition::property::user::Grammar<
					dregx::Language>(language)
{
}

void dregx::Grammar::GenerateObjects()
{
	// Non-Terminal initialization
	program.Set(::deamer::language::type::definition::object::main::NonTerminal("program", { program_deamerreserved_star__stmt__.Pointer() } , ::deamer::language::type::definition::object::main::NonTerminalAbstraction::Standard , false));
deamerreserved_star__stmt__.Set(::deamer::language::type::definition::object::main::NonTerminal("deamerreserved_star__stmt__", { deamerreserved_star__stmt___stmt_deamerreserved_star__stmt__.Pointer(),deamerreserved_star__stmt___EMPTY.Pointer() } , ::deamer::language::type::definition::object::main::NonTerminalAbstraction::Standard , true));
stmt.Set(::deamer::language::type::definition::object::main::NonTerminal("stmt", { stmt_word.Pointer() } , ::deamer::language::type::definition::object::main::NonTerminalAbstraction::Standard , false));
word.Set(::deamer::language::type::definition::object::main::NonTerminal("word", { word_group.Pointer(),word_square.Pointer(),word_standalone.Pointer() } , ::deamer::language::type::definition::object::main::NonTerminalAbstraction::Standard , false));
group.Set(::deamer::language::type::definition::object::main::NonTerminal("group", { group_opt_pad_LEFT_CURLY_BRACKET_or_concat_opt_pad_RIGHT_CURLY_BRACKET_STAR.Pointer(),group_opt_pad_LEFT_CURLY_BRACKET_or_concat_opt_pad_RIGHT_CURLY_BRACKET_PLUS.Pointer(),group_opt_pad_LEFT_CURLY_BRACKET_or_concat_opt_pad_RIGHT_CURLY_BRACKET_extension_modifier.Pointer(),group_opt_pad_LEFT_CURLY_BRACKET_or_concat_opt_pad_RIGHT_CURLY_BRACKET.Pointer(),group_opt_pad_LEFT_CURLY_BRACKET_square_opt_pad_RIGHT_CURLY_BRACKET_STAR.Pointer(),group_opt_pad_LEFT_CURLY_BRACKET_square_opt_pad_RIGHT_CURLY_BRACKET_PLUS.Pointer(),group_opt_pad_LEFT_CURLY_BRACKET_square_opt_pad_RIGHT_CURLY_BRACKET_extension_modifier.Pointer(),group_opt_pad_LEFT_CURLY_BRACKET_square_opt_pad_RIGHT_CURLY_BRACKET.Pointer(),group_opt_pad_LEFT_CURLY_BRACKET_deamerreserved_plus__word___opt_pad_RIGHT_CURLY_BRACKET_STAR.Pointer(),group_opt_pad_LEFT_CURLY_BRACKET_deamerreserved_plus__word___opt_pad_RIGHT_CURLY_BRACKET_PLUS.Pointer(),group_opt_pad_LEFT_CURLY_BRACKET_deamerreserved_plus__word___opt_pad_RIGHT_CURLY_BRACKET_extension_modifier.Pointer(),group_opt_pad_LEFT_CURLY_BRACKET_deamerreserved_plus__word___opt_pad_RIGHT_CURLY_BRACKET.Pointer() } , ::deamer::language::type::definition::object::main::NonTerminalAbstraction::Standard , false));
deamerreserved_plus__word__.Set(::deamer::language::type::definition::object::main::NonTerminal("deamerreserved_plus__word__", { deamerreserved_plus__word___word.Pointer(),deamerreserved_plus__word___word_deamerreserved_plus__word__.Pointer() } , ::deamer::language::type::definition::object::main::NonTerminalAbstraction::Standard , true));
or_concat.Set(::deamer::language::type::definition::object::main::NonTerminal("or_concat", { or_concat_group_opt_pad_OR_group.Pointer(),or_concat_group_opt_pad_OR_square.Pointer(),or_concat_square_opt_pad_OR_group.Pointer(),or_concat_square_opt_pad_OR_square.Pointer() } , ::deamer::language::type::definition::object::main::NonTerminalAbstraction::Standard , false));
square.Set(::deamer::language::type::definition::object::main::NonTerminal("square", { square_capture_extension_modifier.Pointer(),square_capture_PLUS.Pointer(),square_capture_STAR.Pointer(),square_capture.Pointer() } , ::deamer::language::type::definition::object::main::NonTerminalAbstraction::Standard , false));
capture.Set(::deamer::language::type::definition::object::main::NonTerminal("capture", { capture_opt_pad_LEFT_SQUARE_BRACKET_NOT_deamerreserved_plus__capture_logic___RIGHT_SQUARE_BRACKET.Pointer(),capture_opt_pad_LEFT_SQUARE_BRACKET_deamerreserved_plus__capture_logic___RIGHT_SQUARE_BRACKET.Pointer() } , ::deamer::language::type::definition::object::main::NonTerminalAbstraction::Standard , false));
deamerreserved_plus__capture_logic__.Set(::deamer::language::type::definition::object::main::NonTerminal("deamerreserved_plus__capture_logic__", { deamerreserved_plus__capture_logic___capture_logic.Pointer(),deamerreserved_plus__capture_logic___capture_logic_deamerreserved_plus__capture_logic__.Pointer() } , ::deamer::language::type::definition::object::main::NonTerminalAbstraction::Standard , true));
capture_logic.Set(::deamer::language::type::definition::object::main::NonTerminal("capture_logic", { capture_logic_capture_range.Pointer(),capture_logic_capture_special_character.Pointer(),capture_logic_capture_letter.Pointer(),capture_logic_capture_whitespace.Pointer(),capture_logic_capture_symbols.Pointer() } , ::deamer::language::type::definition::object::main::NonTerminalAbstraction::Standard , false));
capture_symbols.Set(::deamer::language::type::definition::object::main::NonTerminal("capture_symbols", { capture_symbols_OTHER.Pointer(),capture_symbols_PLUS.Pointer(),capture_symbols_STAR.Pointer(),capture_symbols_COMMA.Pointer(),capture_symbols_OR.Pointer() } , ::deamer::language::type::definition::object::main::NonTerminalAbstraction::Standard , false));
capture_whitespace.Set(::deamer::language::type::definition::object::main::NonTerminal("capture_whitespace", { capture_whitespace_SPACE.Pointer(),capture_whitespace_TAB.Pointer() } , ::deamer::language::type::definition::object::main::NonTerminalAbstraction::Standard , false));
capture_range.Set(::deamer::language::type::definition::object::main::NonTerminal("capture_range", { capture_range_capture_letter_range.Pointer(),capture_range_capture_number_range.Pointer() } , ::deamer::language::type::definition::object::main::NonTerminalAbstraction::Standard , false));
capture_letter_range.Set(::deamer::language::type::definition::object::main::NonTerminal("capture_letter_range", { capture_letter_range_any_letter_exclude_underscore_MIN_any_letter_exclude_underscore.Pointer() } , ::deamer::language::type::definition::object::main::NonTerminalAbstraction::Standard , false));
capture_number_range.Set(::deamer::language::type::definition::object::main::NonTerminal("capture_number_range", { capture_number_range_NUMBER_MIN_NUMBER.Pointer() } , ::deamer::language::type::definition::object::main::NonTerminalAbstraction::Standard , false));
capture_letter.Set(::deamer::language::type::definition::object::main::NonTerminal("capture_letter", { capture_letter_any_letter.Pointer() } , ::deamer::language::type::definition::object::main::NonTerminalAbstraction::Standard , false));
capture_special_character.Set(::deamer::language::type::definition::object::main::NonTerminal("capture_special_character", { capture_special_character_special_char_any.Pointer() } , ::deamer::language::type::definition::object::main::NonTerminalAbstraction::Standard , false));
extension_modifier.Set(::deamer::language::type::definition::object::main::NonTerminal("extension_modifier", { extension_modifier_opt_pad_LEFT_BRACKET_min_repition_opt_pad_COMMA_max_repition_opt_pad_RIGHT_BRACKET.Pointer() } , ::deamer::language::type::definition::object::main::NonTerminalAbstraction::Standard , false));
min_repition.Set(::deamer::language::type::definition::object::main::NonTerminal("min_repition", { min_repition_opt_pad_deamerreserved_plus__NUMBER__.Pointer() } , ::deamer::language::type::definition::object::main::NonTerminalAbstraction::Standard , false));
deamerreserved_plus__NUMBER__.Set(::deamer::language::type::definition::object::main::NonTerminal("deamerreserved_plus__NUMBER__", { deamerreserved_plus__NUMBER___NUMBER.Pointer(),deamerreserved_plus__NUMBER___NUMBER_deamerreserved_plus__NUMBER__.Pointer() } , ::deamer::language::type::definition::object::main::NonTerminalAbstraction::Standard , true));
max_repition.Set(::deamer::language::type::definition::object::main::NonTerminal("max_repition", { max_repition_opt_pad_deamerreserved_plus__NUMBER__.Pointer() } , ::deamer::language::type::definition::object::main::NonTerminalAbstraction::Standard , false));
standalone.Set(::deamer::language::type::definition::object::main::NonTerminal("standalone", { standalone_opt_pad_deamerreserved_plus__any_letter__.Pointer() } , ::deamer::language::type::definition::object::main::NonTerminalAbstraction::Standard , false));
deamerreserved_plus__any_letter__.Set(::deamer::language::type::definition::object::main::NonTerminal("deamerreserved_plus__any_letter__", { deamerreserved_plus__any_letter___any_letter.Pointer(),deamerreserved_plus__any_letter___any_letter_deamerreserved_plus__any_letter__.Pointer() } , ::deamer::language::type::definition::object::main::NonTerminalAbstraction::Standard , true));
opt_pad.Set(::deamer::language::type::definition::object::main::NonTerminal("opt_pad", { opt_pad_optional_padding.Pointer() } , ::deamer::language::type::definition::object::main::NonTerminalAbstraction::Standard , false));
optional_padding.Set(::deamer::language::type::definition::object::main::NonTerminal("optional_padding", { optional_padding_deamerreserved_star__padding__.Pointer() } , ::deamer::language::type::definition::object::main::NonTerminalAbstraction::Standard , false));
deamerreserved_star__padding__.Set(::deamer::language::type::definition::object::main::NonTerminal("deamerreserved_star__padding__", { deamerreserved_star__padding___padding_deamerreserved_star__padding__.Pointer(),deamerreserved_star__padding___EMPTY.Pointer() } , ::deamer::language::type::definition::object::main::NonTerminalAbstraction::Standard , true));
padding.Set(::deamer::language::type::definition::object::main::NonTerminal("padding", { padding_SPACE.Pointer(),padding_TAB.Pointer() } , ::deamer::language::type::definition::object::main::NonTerminalAbstraction::Standard , false));
special_char_any.Set(::deamer::language::type::definition::object::main::NonTerminal("special_char_any", { special_char_any_SLASH_any.Pointer() } , ::deamer::language::type::definition::object::main::NonTerminalAbstraction::Standard , false));
any_letter.Set(::deamer::language::type::definition::object::main::NonTerminal("any_letter", { any_letter_any_letter_exclude_underscore.Pointer(),any_letter_UNDERSCORE.Pointer() } , ::deamer::language::type::definition::object::main::NonTerminalAbstraction::Standard , false));
any_letter_exclude_underscore.Set(::deamer::language::type::definition::object::main::NonTerminal("any_letter_exclude_underscore", { any_letter_exclude_underscore_T_.Pointer(),any_letter_exclude_underscore_R_.Pointer(),any_letter_exclude_underscore_N_.Pointer(),any_letter_exclude_underscore_B_.Pointer(),any_letter_exclude_underscore_V_.Pointer(),any_letter_exclude_underscore_A_.Pointer(),any_letter_exclude_underscore_LETTER.Pointer() } , ::deamer::language::type::definition::object::main::NonTerminalAbstraction::Standard , false));
any.Set(::deamer::language::type::definition::object::main::NonTerminal("any", { any_LEFT_CURLY_BRACKET.Pointer(),any_RIGHT_CURLY_BRACKET.Pointer(),any_LEFT_SQUARE_BRACKET.Pointer(),any_RIGHT_SQUARE_BRACKET.Pointer(),any_LEFT_BRACKET.Pointer(),any_RIGHT_BRACKET.Pointer(),any_COMMA.Pointer(),any_OR.Pointer(),any_MIN.Pointer(),any_UNDERSCORE.Pointer(),any_NOT.Pointer(),any_NUMBER.Pointer(),any_T_.Pointer(),any_N_.Pointer(),any_R_.Pointer(),any_B_.Pointer(),any_V_.Pointer(),any_A_.Pointer(),any_LETTER.Pointer(),any_SPACE.Pointer(),any_TAB.Pointer(),any_PLUS.Pointer(),any_STAR.Pointer(),any_OTHER.Pointer(),any_SLASH.Pointer() } , ::deamer::language::type::definition::object::main::NonTerminalAbstraction::Standard , false));


	// Production-Rule initialization
	deamerreserved_star__stmt___stmt_deamerreserved_star__stmt__.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->stmt.Pointer(),Language->deamerreserved_star__stmt__.Pointer() }));
deamerreserved_star__stmt___EMPTY.Set(::deamer::language::type::definition::object::main::ProductionRule());
program_deamerreserved_star__stmt__.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->deamerreserved_star__stmt__.Pointer() }));
stmt_word.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->word.Pointer() }));
word_group.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->group.Pointer() }));
word_square.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->square.Pointer() }));
word_standalone.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->standalone.Pointer() }));
group_opt_pad_LEFT_CURLY_BRACKET_or_concat_opt_pad_RIGHT_CURLY_BRACKET_STAR.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->opt_pad.Pointer(),Language->LEFT_CURLY_BRACKET.Pointer(),Language->or_concat.Pointer(),Language->opt_pad.Pointer(),Language->RIGHT_CURLY_BRACKET.Pointer(),Language->STAR.Pointer() }));
group_opt_pad_LEFT_CURLY_BRACKET_or_concat_opt_pad_RIGHT_CURLY_BRACKET_PLUS.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->opt_pad.Pointer(),Language->LEFT_CURLY_BRACKET.Pointer(),Language->or_concat.Pointer(),Language->opt_pad.Pointer(),Language->RIGHT_CURLY_BRACKET.Pointer(),Language->PLUS.Pointer() }));
group_opt_pad_LEFT_CURLY_BRACKET_or_concat_opt_pad_RIGHT_CURLY_BRACKET_extension_modifier.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->opt_pad.Pointer(),Language->LEFT_CURLY_BRACKET.Pointer(),Language->or_concat.Pointer(),Language->opt_pad.Pointer(),Language->RIGHT_CURLY_BRACKET.Pointer(),Language->extension_modifier.Pointer() }));
group_opt_pad_LEFT_CURLY_BRACKET_or_concat_opt_pad_RIGHT_CURLY_BRACKET.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->opt_pad.Pointer(),Language->LEFT_CURLY_BRACKET.Pointer(),Language->or_concat.Pointer(),Language->opt_pad.Pointer(),Language->RIGHT_CURLY_BRACKET.Pointer() }));
group_opt_pad_LEFT_CURLY_BRACKET_square_opt_pad_RIGHT_CURLY_BRACKET_STAR.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->opt_pad.Pointer(),Language->LEFT_CURLY_BRACKET.Pointer(),Language->square.Pointer(),Language->opt_pad.Pointer(),Language->RIGHT_CURLY_BRACKET.Pointer(),Language->STAR.Pointer() }));
group_opt_pad_LEFT_CURLY_BRACKET_square_opt_pad_RIGHT_CURLY_BRACKET_PLUS.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->opt_pad.Pointer(),Language->LEFT_CURLY_BRACKET.Pointer(),Language->square.Pointer(),Language->opt_pad.Pointer(),Language->RIGHT_CURLY_BRACKET.Pointer(),Language->PLUS.Pointer() }));
group_opt_pad_LEFT_CURLY_BRACKET_square_opt_pad_RIGHT_CURLY_BRACKET_extension_modifier.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->opt_pad.Pointer(),Language->LEFT_CURLY_BRACKET.Pointer(),Language->square.Pointer(),Language->opt_pad.Pointer(),Language->RIGHT_CURLY_BRACKET.Pointer(),Language->extension_modifier.Pointer() }));
group_opt_pad_LEFT_CURLY_BRACKET_square_opt_pad_RIGHT_CURLY_BRACKET.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->opt_pad.Pointer(),Language->LEFT_CURLY_BRACKET.Pointer(),Language->square.Pointer(),Language->opt_pad.Pointer(),Language->RIGHT_CURLY_BRACKET.Pointer() }));
deamerreserved_plus__word___word.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->word.Pointer() }));
deamerreserved_plus__word___word_deamerreserved_plus__word__.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->word.Pointer(),Language->deamerreserved_plus__word__.Pointer() }));
group_opt_pad_LEFT_CURLY_BRACKET_deamerreserved_plus__word___opt_pad_RIGHT_CURLY_BRACKET_STAR.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->opt_pad.Pointer(),Language->LEFT_CURLY_BRACKET.Pointer(),Language->deamerreserved_plus__word__.Pointer(),Language->opt_pad.Pointer(),Language->RIGHT_CURLY_BRACKET.Pointer(),Language->STAR.Pointer() }));
group_opt_pad_LEFT_CURLY_BRACKET_deamerreserved_plus__word___opt_pad_RIGHT_CURLY_BRACKET_PLUS.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->opt_pad.Pointer(),Language->LEFT_CURLY_BRACKET.Pointer(),Language->deamerreserved_plus__word__.Pointer(),Language->opt_pad.Pointer(),Language->RIGHT_CURLY_BRACKET.Pointer(),Language->PLUS.Pointer() }));
group_opt_pad_LEFT_CURLY_BRACKET_deamerreserved_plus__word___opt_pad_RIGHT_CURLY_BRACKET_extension_modifier.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->opt_pad.Pointer(),Language->LEFT_CURLY_BRACKET.Pointer(),Language->deamerreserved_plus__word__.Pointer(),Language->opt_pad.Pointer(),Language->RIGHT_CURLY_BRACKET.Pointer(),Language->extension_modifier.Pointer() }));
group_opt_pad_LEFT_CURLY_BRACKET_deamerreserved_plus__word___opt_pad_RIGHT_CURLY_BRACKET.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->opt_pad.Pointer(),Language->LEFT_CURLY_BRACKET.Pointer(),Language->deamerreserved_plus__word__.Pointer(),Language->opt_pad.Pointer(),Language->RIGHT_CURLY_BRACKET.Pointer() }));
or_concat_group_opt_pad_OR_group.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->group.Pointer(),Language->opt_pad.Pointer(),Language->OR.Pointer(),Language->group.Pointer() }));
or_concat_group_opt_pad_OR_square.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->group.Pointer(),Language->opt_pad.Pointer(),Language->OR.Pointer(),Language->square.Pointer() }));
or_concat_square_opt_pad_OR_group.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->square.Pointer(),Language->opt_pad.Pointer(),Language->OR.Pointer(),Language->group.Pointer() }));
or_concat_square_opt_pad_OR_square.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->square.Pointer(),Language->opt_pad.Pointer(),Language->OR.Pointer(),Language->square.Pointer() }));
square_capture_extension_modifier.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->capture.Pointer(),Language->extension_modifier.Pointer() }));
square_capture_PLUS.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->capture.Pointer(),Language->PLUS.Pointer() }));
square_capture_STAR.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->capture.Pointer(),Language->STAR.Pointer() }));
square_capture.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->capture.Pointer() }));
deamerreserved_plus__capture_logic___capture_logic.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->capture_logic.Pointer() }));
deamerreserved_plus__capture_logic___capture_logic_deamerreserved_plus__capture_logic__.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->capture_logic.Pointer(),Language->deamerreserved_plus__capture_logic__.Pointer() }));
capture_opt_pad_LEFT_SQUARE_BRACKET_NOT_deamerreserved_plus__capture_logic___RIGHT_SQUARE_BRACKET.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->opt_pad.Pointer(),Language->LEFT_SQUARE_BRACKET_NOT.Pointer(),Language->deamerreserved_plus__capture_logic__.Pointer(),Language->RIGHT_SQUARE_BRACKET.Pointer() }));
capture_opt_pad_LEFT_SQUARE_BRACKET_deamerreserved_plus__capture_logic___RIGHT_SQUARE_BRACKET.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->opt_pad.Pointer(),Language->LEFT_SQUARE_BRACKET.Pointer(),Language->deamerreserved_plus__capture_logic__.Pointer(),Language->RIGHT_SQUARE_BRACKET.Pointer() }));
capture_logic_capture_range.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->capture_range.Pointer() }));
capture_logic_capture_special_character.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->capture_special_character.Pointer() }));
capture_logic_capture_letter.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->capture_letter.Pointer() }));
capture_logic_capture_whitespace.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->capture_whitespace.Pointer() }));
capture_logic_capture_symbols.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->capture_symbols.Pointer() }));
capture_symbols_OTHER.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->OTHER.Pointer() }));
capture_symbols_PLUS.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->PLUS.Pointer() }));
capture_symbols_STAR.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->STAR.Pointer() }));
capture_symbols_COMMA.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->COMMA.Pointer() }));
capture_symbols_OR.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->OR.Pointer() }));
capture_whitespace_SPACE.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->SPACE.Pointer() }));
capture_whitespace_TAB.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->TAB.Pointer() }));
capture_range_capture_letter_range.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->capture_letter_range.Pointer() }));
capture_range_capture_number_range.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->capture_number_range.Pointer() }));
capture_letter_range_any_letter_exclude_underscore_MIN_any_letter_exclude_underscore.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->any_letter_exclude_underscore.Pointer(),Language->MIN.Pointer(),Language->any_letter_exclude_underscore.Pointer() }));
capture_number_range_NUMBER_MIN_NUMBER.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->NUMBER.Pointer(),Language->MIN.Pointer(),Language->NUMBER.Pointer() }));
capture_letter_any_letter.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->any_letter.Pointer() }));
capture_special_character_special_char_any.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->special_char_any.Pointer() }));
extension_modifier_opt_pad_LEFT_BRACKET_min_repition_opt_pad_COMMA_max_repition_opt_pad_RIGHT_BRACKET.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->opt_pad.Pointer(),Language->LEFT_BRACKET.Pointer(),Language->min_repition.Pointer(),Language->opt_pad.Pointer(),Language->COMMA.Pointer(),Language->max_repition.Pointer(),Language->opt_pad.Pointer(),Language->RIGHT_BRACKET.Pointer() }));
deamerreserved_plus__NUMBER___NUMBER.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->NUMBER.Pointer() }));
deamerreserved_plus__NUMBER___NUMBER_deamerreserved_plus__NUMBER__.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->NUMBER.Pointer(),Language->deamerreserved_plus__NUMBER__.Pointer() }));
min_repition_opt_pad_deamerreserved_plus__NUMBER__.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->opt_pad.Pointer(),Language->deamerreserved_plus__NUMBER__.Pointer() }));
max_repition_opt_pad_deamerreserved_plus__NUMBER__.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->opt_pad.Pointer(),Language->deamerreserved_plus__NUMBER__.Pointer() }));
deamerreserved_plus__any_letter___any_letter.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->any_letter.Pointer() }));
deamerreserved_plus__any_letter___any_letter_deamerreserved_plus__any_letter__.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->any_letter.Pointer(),Language->deamerreserved_plus__any_letter__.Pointer() }));
standalone_opt_pad_deamerreserved_plus__any_letter__.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->opt_pad.Pointer(),Language->deamerreserved_plus__any_letter__.Pointer() }));
opt_pad_optional_padding.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->optional_padding.Pointer() }));
deamerreserved_star__padding___padding_deamerreserved_star__padding__.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->padding.Pointer(),Language->deamerreserved_star__padding__.Pointer() }));
deamerreserved_star__padding___EMPTY.Set(::deamer::language::type::definition::object::main::ProductionRule());
optional_padding_deamerreserved_star__padding__.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->deamerreserved_star__padding__.Pointer() }));
padding_SPACE.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->SPACE.Pointer() }));
padding_TAB.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->TAB.Pointer() }));
special_char_any_SLASH_any.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->SLASH.Pointer(),Language->any.Pointer() }));
any_letter_any_letter_exclude_underscore.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->any_letter_exclude_underscore.Pointer() }));
any_letter_UNDERSCORE.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->UNDERSCORE.Pointer() }));
any_letter_exclude_underscore_T_.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->T_.Pointer() }));
any_letter_exclude_underscore_R_.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->R_.Pointer() }));
any_letter_exclude_underscore_N_.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->N_.Pointer() }));
any_letter_exclude_underscore_B_.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->B_.Pointer() }));
any_letter_exclude_underscore_V_.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->V_.Pointer() }));
any_letter_exclude_underscore_A_.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->A_.Pointer() }));
any_letter_exclude_underscore_LETTER.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->LETTER.Pointer() }));
any_LEFT_CURLY_BRACKET.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->LEFT_CURLY_BRACKET.Pointer() }));
any_RIGHT_CURLY_BRACKET.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->RIGHT_CURLY_BRACKET.Pointer() }));
any_LEFT_SQUARE_BRACKET.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->LEFT_SQUARE_BRACKET.Pointer() }));
any_RIGHT_SQUARE_BRACKET.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->RIGHT_SQUARE_BRACKET.Pointer() }));
any_LEFT_BRACKET.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->LEFT_BRACKET.Pointer() }));
any_RIGHT_BRACKET.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->RIGHT_BRACKET.Pointer() }));
any_COMMA.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->COMMA.Pointer() }));
any_OR.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->OR.Pointer() }));
any_MIN.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->MIN.Pointer() }));
any_UNDERSCORE.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->UNDERSCORE.Pointer() }));
any_NOT.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->NOT.Pointer() }));
any_NUMBER.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->NUMBER.Pointer() }));
any_T_.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->T_.Pointer() }));
any_N_.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->N_.Pointer() }));
any_R_.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->R_.Pointer() }));
any_B_.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->B_.Pointer() }));
any_V_.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->V_.Pointer() }));
any_A_.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->A_.Pointer() }));
any_LETTER.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->LETTER.Pointer() }));
any_SPACE.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->SPACE.Pointer() }));
any_TAB.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->TAB.Pointer() }));
any_PLUS.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->PLUS.Pointer() }));
any_STAR.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->STAR.Pointer() }));
any_OTHER.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->OTHER.Pointer() }));
any_SLASH.Set(::deamer::language::type::definition::object::main::ProductionRule({ Language->SLASH.Pointer() }));


	// Unknown references
	

	// Add object calls
	// AddObject(...)
	AddObject(program);
AddObject(deamerreserved_star__stmt__);
AddObject(stmt);
AddObject(word);
AddObject(group);
AddObject(deamerreserved_plus__word__);
AddObject(or_concat);
AddObject(square);
AddObject(capture);
AddObject(deamerreserved_plus__capture_logic__);
AddObject(capture_logic);
AddObject(capture_symbols);
AddObject(capture_whitespace);
AddObject(capture_range);
AddObject(capture_letter_range);
AddObject(capture_number_range);
AddObject(capture_letter);
AddObject(capture_special_character);
AddObject(extension_modifier);
AddObject(min_repition);
AddObject(deamerreserved_plus__NUMBER__);
AddObject(max_repition);
AddObject(standalone);
AddObject(deamerreserved_plus__any_letter__);
AddObject(opt_pad);
AddObject(optional_padding);
AddObject(deamerreserved_star__padding__);
AddObject(padding);
AddObject(special_char_any);
AddObject(any_letter);
AddObject(any_letter_exclude_underscore);
AddObject(any);


	AddObject(deamerreserved_star__stmt___stmt_deamerreserved_star__stmt__);
AddObject(deamerreserved_star__stmt___EMPTY);
AddObject(program_deamerreserved_star__stmt__);
AddObject(stmt_word);
AddObject(word_group);
AddObject(word_square);
AddObject(word_standalone);
AddObject(group_opt_pad_LEFT_CURLY_BRACKET_or_concat_opt_pad_RIGHT_CURLY_BRACKET_STAR);
AddObject(group_opt_pad_LEFT_CURLY_BRACKET_or_concat_opt_pad_RIGHT_CURLY_BRACKET_PLUS);
AddObject(group_opt_pad_LEFT_CURLY_BRACKET_or_concat_opt_pad_RIGHT_CURLY_BRACKET_extension_modifier);
AddObject(group_opt_pad_LEFT_CURLY_BRACKET_or_concat_opt_pad_RIGHT_CURLY_BRACKET);
AddObject(group_opt_pad_LEFT_CURLY_BRACKET_square_opt_pad_RIGHT_CURLY_BRACKET_STAR);
AddObject(group_opt_pad_LEFT_CURLY_BRACKET_square_opt_pad_RIGHT_CURLY_BRACKET_PLUS);
AddObject(group_opt_pad_LEFT_CURLY_BRACKET_square_opt_pad_RIGHT_CURLY_BRACKET_extension_modifier);
AddObject(group_opt_pad_LEFT_CURLY_BRACKET_square_opt_pad_RIGHT_CURLY_BRACKET);
AddObject(deamerreserved_plus__word___word);
AddObject(deamerreserved_plus__word___word_deamerreserved_plus__word__);
AddObject(group_opt_pad_LEFT_CURLY_BRACKET_deamerreserved_plus__word___opt_pad_RIGHT_CURLY_BRACKET_STAR);
AddObject(group_opt_pad_LEFT_CURLY_BRACKET_deamerreserved_plus__word___opt_pad_RIGHT_CURLY_BRACKET_PLUS);
AddObject(group_opt_pad_LEFT_CURLY_BRACKET_deamerreserved_plus__word___opt_pad_RIGHT_CURLY_BRACKET_extension_modifier);
AddObject(group_opt_pad_LEFT_CURLY_BRACKET_deamerreserved_plus__word___opt_pad_RIGHT_CURLY_BRACKET);
AddObject(or_concat_group_opt_pad_OR_group);
AddObject(or_concat_group_opt_pad_OR_square);
AddObject(or_concat_square_opt_pad_OR_group);
AddObject(or_concat_square_opt_pad_OR_square);
AddObject(square_capture_extension_modifier);
AddObject(square_capture_PLUS);
AddObject(square_capture_STAR);
AddObject(square_capture);
AddObject(deamerreserved_plus__capture_logic___capture_logic);
AddObject(deamerreserved_plus__capture_logic___capture_logic_deamerreserved_plus__capture_logic__);
AddObject(capture_opt_pad_LEFT_SQUARE_BRACKET_NOT_deamerreserved_plus__capture_logic___RIGHT_SQUARE_BRACKET);
AddObject(capture_opt_pad_LEFT_SQUARE_BRACKET_deamerreserved_plus__capture_logic___RIGHT_SQUARE_BRACKET);
AddObject(capture_logic_capture_range);
AddObject(capture_logic_capture_special_character);
AddObject(capture_logic_capture_letter);
AddObject(capture_logic_capture_whitespace);
AddObject(capture_logic_capture_symbols);
AddObject(capture_symbols_OTHER);
AddObject(capture_symbols_PLUS);
AddObject(capture_symbols_STAR);
AddObject(capture_symbols_COMMA);
AddObject(capture_symbols_OR);
AddObject(capture_whitespace_SPACE);
AddObject(capture_whitespace_TAB);
AddObject(capture_range_capture_letter_range);
AddObject(capture_range_capture_number_range);
AddObject(capture_letter_range_any_letter_exclude_underscore_MIN_any_letter_exclude_underscore);
AddObject(capture_number_range_NUMBER_MIN_NUMBER);
AddObject(capture_letter_any_letter);
AddObject(capture_special_character_special_char_any);
AddObject(extension_modifier_opt_pad_LEFT_BRACKET_min_repition_opt_pad_COMMA_max_repition_opt_pad_RIGHT_BRACKET);
AddObject(deamerreserved_plus__NUMBER___NUMBER);
AddObject(deamerreserved_plus__NUMBER___NUMBER_deamerreserved_plus__NUMBER__);
AddObject(min_repition_opt_pad_deamerreserved_plus__NUMBER__);
AddObject(max_repition_opt_pad_deamerreserved_plus__NUMBER__);
AddObject(deamerreserved_plus__any_letter___any_letter);
AddObject(deamerreserved_plus__any_letter___any_letter_deamerreserved_plus__any_letter__);
AddObject(standalone_opt_pad_deamerreserved_plus__any_letter__);
AddObject(opt_pad_optional_padding);
AddObject(deamerreserved_star__padding___padding_deamerreserved_star__padding__);
AddObject(deamerreserved_star__padding___EMPTY);
AddObject(optional_padding_deamerreserved_star__padding__);
AddObject(padding_SPACE);
AddObject(padding_TAB);
AddObject(special_char_any_SLASH_any);
AddObject(any_letter_any_letter_exclude_underscore);
AddObject(any_letter_UNDERSCORE);
AddObject(any_letter_exclude_underscore_T_);
AddObject(any_letter_exclude_underscore_R_);
AddObject(any_letter_exclude_underscore_N_);
AddObject(any_letter_exclude_underscore_B_);
AddObject(any_letter_exclude_underscore_V_);
AddObject(any_letter_exclude_underscore_A_);
AddObject(any_letter_exclude_underscore_LETTER);
AddObject(any_LEFT_CURLY_BRACKET);
AddObject(any_RIGHT_CURLY_BRACKET);
AddObject(any_LEFT_SQUARE_BRACKET);
AddObject(any_RIGHT_SQUARE_BRACKET);
AddObject(any_LEFT_BRACKET);
AddObject(any_RIGHT_BRACKET);
AddObject(any_COMMA);
AddObject(any_OR);
AddObject(any_MIN);
AddObject(any_UNDERSCORE);
AddObject(any_NOT);
AddObject(any_NUMBER);
AddObject(any_T_);
AddObject(any_N_);
AddObject(any_R_);
AddObject(any_B_);
AddObject(any_V_);
AddObject(any_A_);
AddObject(any_LETTER);
AddObject(any_SPACE);
AddObject(any_TAB);
AddObject(any_PLUS);
AddObject(any_STAR);
AddObject(any_OTHER);
AddObject(any_SLASH);


	


	// Place higher level operations here.
	// ReplaceObject(..., ...)
	// DeleteObject(..., ...)
	
}
