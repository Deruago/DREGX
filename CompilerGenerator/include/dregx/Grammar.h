/* 
 * This file is auto-generated and auto-maintained by DLDL
 * Do not change code in this as it can be overwritten.
 *
 * For more information see the DLDL repo: https://github.com/Deruago/DLDL
 * For more information about Deamer: https://github.com/Deruago/theDeamerProject
 */

#ifndef DREGX_GRAMMAR_H
#define DREGX_GRAMMAR_H

#include "Deamer/Language/Generator/Definition/Property/User/Main/Grammar.h"
#include "Deamer/Language/Type/Definition/Object/Special/Uninitialized.h"

namespace dregx
{
	class Language;

	/*!	\class Grammar
	 *
	 *	\brief This contains the grammar LPD of the language dregx
	 *
	 *	\note This is auto-generated via the DLDL definition.
	 */
	class Grammar : public ::deamer::language::generator::definition::property::user::Grammar<
								::dregx::Language>
	{
	public:
		// Non-Terminal declarations
		::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::NonTerminal> program;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::NonTerminal> deamerreserved_star__stmt__;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::NonTerminal> stmt;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::NonTerminal> word;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::NonTerminal> group;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::NonTerminal> deamerreserved_plus__word__;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::NonTerminal> or_concat;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::NonTerminal> deamerreserved_arrow__or_element__;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::NonTerminal> deamerreserved_star__opt_pad__OR__or_element__;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::NonTerminal> or_element;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::NonTerminal> square;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::NonTerminal> capture;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::NonTerminal> deamerreserved_star__capture_logic__;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::NonTerminal> capture_logic;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::NonTerminal> capture_symbols;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::NonTerminal> capture_whitespace;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::NonTerminal> capture_range;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::NonTerminal> capture_letter_range;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::NonTerminal> capture_number_range;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::NonTerminal> capture_number;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::NonTerminal> capture_letter;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::NonTerminal> capture_special_character;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::NonTerminal> extension_modifier;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::NonTerminal> min_repition;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::NonTerminal> deamerreserved_plus__NUMBER__;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::NonTerminal> max_repition;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::NonTerminal> standalone;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::NonTerminal> opt_pad;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::NonTerminal> optional_padding;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::NonTerminal> deamerreserved_star__padding__;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::NonTerminal> padding;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::NonTerminal> special_char_any;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::NonTerminal> any_number;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::NonTerminal> any_letter;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::NonTerminal> any_letter_exclude_underscore;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::NonTerminal> capture_structure;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::NonTerminal> any;

	
		// Production-Rule declarations
		::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> deamerreserved_star__stmt___stmt_deamerreserved_star__stmt__;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> deamerreserved_star__stmt___EMPTY;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> program_deamerreserved_star__stmt___opt_pad;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> stmt_word;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> word_group;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> word_square;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> word_standalone;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> group_opt_pad_LEFT_CURLY_BRACKET_or_concat_opt_pad_RIGHT_CURLY_BRACKET_OPTIONAL;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> group_opt_pad_LEFT_CURLY_BRACKET_or_concat_opt_pad_RIGHT_CURLY_BRACKET_STAR;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> group_opt_pad_LEFT_CURLY_BRACKET_or_concat_opt_pad_RIGHT_CURLY_BRACKET_PLUS;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> group_opt_pad_LEFT_CURLY_BRACKET_or_concat_opt_pad_RIGHT_CURLY_BRACKET_extension_modifier;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> group_opt_pad_LEFT_CURLY_BRACKET_or_concat_opt_pad_RIGHT_CURLY_BRACKET;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> deamerreserved_plus__word___word;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> deamerreserved_plus__word___word_deamerreserved_plus__word__;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> group_opt_pad_LEFT_CURLY_BRACKET_deamerreserved_plus__word___opt_pad_RIGHT_CURLY_BRACKET_OPTIONAL;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> group_opt_pad_LEFT_CURLY_BRACKET_deamerreserved_plus__word___opt_pad_RIGHT_CURLY_BRACKET_STAR;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> group_opt_pad_LEFT_CURLY_BRACKET_deamerreserved_plus__word___opt_pad_RIGHT_CURLY_BRACKET_PLUS;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> group_opt_pad_LEFT_CURLY_BRACKET_deamerreserved_plus__word___opt_pad_RIGHT_CURLY_BRACKET_extension_modifier;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> group_opt_pad_LEFT_CURLY_BRACKET_deamerreserved_plus__word___opt_pad_RIGHT_CURLY_BRACKET;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> deamerreserved_arrow__or_element___or_element_deamerreserved_star__opt_pad__OR__or_element__;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> deamerreserved_star__opt_pad__OR__or_element___opt_pad_OR_or_element_deamerreserved_star__opt_pad__OR__or_element__;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> deamerreserved_star__opt_pad__OR__or_element___EMPTY;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> or_concat_or_element_opt_pad_OR_deamerreserved_arrow__or_element__;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> or_element_deamerreserved_plus__word__;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> square_capture_extension_modifier;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> square_capture_PLUS;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> square_capture_STAR;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> square_capture_OPTIONAL;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> square_capture;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> deamerreserved_star__capture_logic___capture_logic_deamerreserved_star__capture_logic__;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> deamerreserved_star__capture_logic___EMPTY;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> capture_opt_pad_LEFT_SQUARE_BRACKET_NOT_deamerreserved_star__capture_logic___RIGHT_SQUARE_BRACKET;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> capture_opt_pad_LEFT_SQUARE_BRACKET_deamerreserved_star__capture_logic___RIGHT_SQUARE_BRACKET;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> capture_logic_capture_range;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> capture_logic_capture_special_character;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> capture_logic_capture_letter;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> capture_logic_capture_number;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> capture_logic_capture_whitespace;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> capture_logic_capture_symbols;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> capture_logic_capture_structure;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> capture_symbols_OTHER;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> capture_symbols_PLUS;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> capture_symbols_STAR;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> capture_symbols_COMMA;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> capture_symbols_OR;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> capture_symbols_OPTIONAL;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> capture_whitespace_SPACE;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> capture_whitespace_TAB;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> capture_range_capture_letter_range;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> capture_range_capture_number_range;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> capture_letter_range_any_letter_exclude_underscore_MIN_any_letter_exclude_underscore;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> capture_number_range_NUMBER_MIN_NUMBER;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> capture_number_any_number;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> capture_letter_any_letter;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> capture_special_character_special_char_any;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> extension_modifier_opt_pad_LEFT_BRACKET_min_repition_opt_pad_COMMA_max_repition_opt_pad_RIGHT_BRACKET;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> deamerreserved_plus__NUMBER___NUMBER;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> deamerreserved_plus__NUMBER___NUMBER_deamerreserved_plus__NUMBER__;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> min_repition_opt_pad_deamerreserved_plus__NUMBER__;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> max_repition_opt_pad_deamerreserved_plus__NUMBER__;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> standalone_opt_pad_any_letter;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> standalone_opt_pad_any_number;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> opt_pad_optional_padding;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> deamerreserved_star__padding___padding_deamerreserved_star__padding__;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> deamerreserved_star__padding___EMPTY;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> optional_padding_deamerreserved_star__padding__;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> padding_SPACE;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> padding_TAB;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> special_char_any_SLASH_any;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> any_number_NUMBER;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> any_letter_any_letter_exclude_underscore;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> any_letter_UNDERSCORE;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> any_letter_exclude_underscore_T_;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> any_letter_exclude_underscore_R_;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> any_letter_exclude_underscore_N_;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> any_letter_exclude_underscore_B_;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> any_letter_exclude_underscore_V_;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> any_letter_exclude_underscore_A_;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> any_letter_exclude_underscore_LETTER;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> capture_structure_LEFT_CURLY_BRACKET;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> capture_structure_RIGHT_CURLY_BRACKET;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> capture_structure_LEFT_SQUARE_BRACKET;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> capture_structure_LEFT_BRACKET;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> capture_structure_RIGHT_BRACKET;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> any_LEFT_CURLY_BRACKET;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> any_RIGHT_CURLY_BRACKET;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> any_LEFT_SQUARE_BRACKET;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> any_RIGHT_SQUARE_BRACKET;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> any_LEFT_BRACKET;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> any_RIGHT_BRACKET;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> any_COMMA;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> any_OR;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> any_MIN;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> any_OPTIONAL;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> any_UNDERSCORE;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> any_NOT;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> any_NUMBER;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> any_T_;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> any_N_;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> any_R_;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> any_B_;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> any_V_;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> any_A_;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> any_LETTER;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> any_SPACE;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> any_TAB;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> any_PLUS;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> any_STAR;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> any_OTHER;
::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::ProductionRule> any_SLASH;

	
	private:
		// Unknown reference declarations
		
	
	public:
		Grammar(dregx::Language* language);

		void GenerateObjects() override;
	};
}

#endif // DREGX_GRAMMAR_H
