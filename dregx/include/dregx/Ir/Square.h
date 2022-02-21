#ifndef DREGX_IR_SQUARE_H
#define DREGX_IR_SQUARE_H

#include "dregx/Ir/Capture.h"

namespace dregx::ir
{
	class Square : public Capture
	{
	public:
		Square();

	public:
		std::string GetFormattedRegex() override;
	};
}

#endif // DREGX_IR_SQUARE_H
