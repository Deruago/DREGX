#ifndef DREGX_IR_ORGROUP_H
#define DREGX_IR_ORGROUP_H

#include "dregx/Ir/Capture.h"

namespace dregx::ir
{
	class OrGroup : public Capture
	{
	public:
		OrGroup();

	public:
		std::string GetFormattedRegex() override;
	};
}

#endif // DREGX_IR_ORGROUP_H
