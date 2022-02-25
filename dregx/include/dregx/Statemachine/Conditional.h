#ifndef DREGX_STATEMACHINE_CONDITIONAL_H
#define DREGX_STATEMACHINE_CONDITIONAL_H

#include <string>

namespace dregx::statemachine
{
	struct Conditional
	{
	private:
		std::string character;

	public:
		Conditional(const std::string& character_);
		~Conditional() = default;

	public:
		std::string GetCharacter() const;

		bool operator==(const Conditional& rhs) const noexcept;
		bool operator<(const Conditional& rhs) const noexcept;
		bool operator>(const Conditional& rhs) const noexcept;
		Conditional& operator=(const Conditional& rhs);
	};
}

#endif // DREGX_STATEMACHINE_CONDITIONAL_H
