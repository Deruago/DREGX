#ifndef DREGX_IR_CAPTURETYPE_H
#define DREGX_IR_CAPTURETYPE_H

namespace dregx::ir
{
	enum class CaptureType
	{
		unknown,

		group,
		square,
		word,
		character,
		escapecharacter,
		capturerange,
		orgroup,
		notcapture,
	};
}

#endif // DREGX_IR_CAPTURETYPE_H
