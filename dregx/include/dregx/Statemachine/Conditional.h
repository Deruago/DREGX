#ifndef DREGX_STATEMACHINE_CONDITIONAL_H
#define DREGX_STATEMACHINE_CONDITIONAL_H

#include <string>

namespace dregx::statemachine
{
	struct Conditional
	{
	private:
		const std::string character;

	public:
		Conditional(const std::string& character_);
		~Conditional() = default;

	public:
		std::string GetCharacter() const;

		bool operator==(const Conditional& rhs) const noexcept;
	};
}

#endif // DREGX_STATEMACHINE_CONDITIONAL_H
