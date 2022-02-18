/* 
 * This file is auto-generated and auto-maintained by DLDL
 * Do not change code in this as it can be overwritten.
 *
 * For more information see the DLDL repo: https://github.com/Deruago/DLDL
 * For more information about Deamer: https://github.com/Deruago/theDeamerProject
 */

#ifndef DREGX_IDENTITY_H
#define DREGX_IDENTITY_H

#include "Deamer/Language/Generator/Definition/Property/User/Special/Identity.h"

namespace dregx
{
	class Language;

	/*!	\class Identity
	 *
	 *	\brief This contains the identity LPD of the language dregx
	 *
	 *	\note This is auto-generated via the DLDL definition.
	 */
	class Identity : public ::deamer::language::generator::definition::property::user::Identity<
								::dregx::Language>
	{
	public:
		::deamer::type::SafeReserve<::deamer::language::type::definition::object::main::Name> name;

	public:
		Identity(::dregx::Language* language)
			:	::deamer::language::generator::definition::property::user::Identity<
					::dregx::Language>(language)
		{
		}

		void GenerateObjects() override
		{
			name.Set(::deamer::language::type::definition::object::main::Name("dregx"));
			
			AddObject(name);

			// Place higher level operations here.
			// ReplaceObject(..., ...)
			// DeleteObject(..., ...)
			
		}
	};
}

#endif // DREGX_IDENTITY_H
