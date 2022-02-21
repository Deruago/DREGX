#ifndef DREGX_IR_GROUP_H
#define DREGX_IR_GROUP_H

#include "dregx/Ir/Capture.h"

namespace dregx::ir
{
	class Group : public Capture
	{
	public:
		Group();

	public:
		std::string GetFormattedRegex() override;
	};
}

#endif // DREGX_IR_GROUP_H
