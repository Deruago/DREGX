#ifndef DREGX_STATEMACHINE_CONVERTREGEXTODFA_H
#define DREGX_STATEMACHINE_CONVERTREGEXTODFA_H

#include "dregx/Statemachine/Statemachine.h"
#include <memory>

namespace dregx::ir
{
	class Capture;
	class Group;
	class Square;
	class Word;
	class OrGroup;
}

namespace dregx::statemachine
{
	class ConvertRegexToDFA
	{
	public:
		static std::unique_ptr<Statemachine> ConvertToStatemachine(ir::Capture* capture,
																   bool embed = false);
		static std::unique_ptr<Statemachine> ConvertToStatemachine(ir::Group* group,
																   bool embed = false);
		static std::unique_ptr<Statemachine> ConvertToStatemachine(ir::Square* square,
																   bool embed = false);
		static std::unique_ptr<Statemachine> ConvertToStatemachine(ir::Word* word,
																   bool embed = false);
		static std::unique_ptr<Statemachine> ConvertToStatemachine(ir::OrGroup* orGroup,
																   bool embed = false);
	};
}

#endif // DREGX_STATEMACHINE_CONVERTREGEXTODFA_H
