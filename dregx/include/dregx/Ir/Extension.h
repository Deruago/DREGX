#ifndef DREGX_IR_EXTENSIONTYPE_H
#define DREGX_IR_EXTENSIONTYPE_H

#include <string>

namespace dregx::ir
{
	class Extension
	{
	private:
		std::size_t lowerBound = 0;
		std::size_t upperBound = 0;
		bool infiniteUpperBound = false;

	public:
		Extension(std::size_t lowerBound_, std::size_t upperBound_, bool infiniteUpperBound_);

	public:
		std::size_t GetLowerBound() const;
		std::size_t GetUpperBound() const;
		bool IsUpperBoundInfinite() const;

		std::string GetFormattedRegex() const;

	private:
	};
}

#endif // DREGX_IR_EXTENSIONTYPE_H
