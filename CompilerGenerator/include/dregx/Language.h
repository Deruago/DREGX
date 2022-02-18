/* 
 * This file is auto-generated and auto-maintained by DLDL
 * Do not change code in this as it can be overwritten.
 *
 * For more information see the DLDL repo: https://github.com/Deruago/DLDL
 * For more information about Deamer: https://github.com/Deruago/theDeamerProject
 */

#ifndef DREGX_LANGUAGE_H
#define DREGX_LANGUAGE_H

#include "Deamer/Language/Generator/Definition/Language.h"
#include "dregx/Threat.h"
#include "dregx/Identity.h"
#include "dregx/Generation.h"
#include "dregx/Grammar.h"
#include "dregx/Lexicon.h"


namespace dregx
{
	/*!	\class Language
	 *
	 *	\brief This contains the Language Definition of the language dregx
	 *
	 *	\details The LD initializes all base LPD's with its own pointer (this).
	 *	This allows the LPD's to access other LPD's via the language object.
	 *
	 *	\note This is auto-generated via the DLDL definition.
	 */
	class Language : public ::deamer::language::generator::definition::Language<
						 ::dregx::Language , ::dregx::Threat
, ::dregx::Identity
, ::dregx::Generation
, ::dregx::Grammar
, ::dregx::Lexicon
>
						 , public ::dregx::Threat
, public ::dregx::Identity
, public ::dregx::Generation
, public ::dregx::Grammar
, public ::dregx::Lexicon

	{
	public:
		Language() : ::deamer::language::generator::definition::Language<
						 ::dregx::Language , ::dregx::Threat
, ::dregx::Identity
, ::dregx::Generation
, ::dregx::Grammar
, ::dregx::Lexicon
>()
		, ::dregx::Threat::Threat(this)
, ::dregx::Identity::Identity(this)
, ::dregx::Generation::Generation(this)
, ::dregx::Grammar::Grammar(this)
, ::dregx::Lexicon::Lexicon(this)

		{
		}

		~Language() override = default;
	};
}

#endif // DREGX_LANGUAGE_H
