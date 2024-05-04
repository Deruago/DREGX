#ifndef DREGX_IR_NOTCAPTURE_H
#define DREGX_IR_NOTCAPTURE_H

#include "dregx/Ir/Capture.h"
#include <string>
#include <vector>
#include <memory>

namespace dregx::ir
{
	class NotCapture : public Capture
	{
	private:
		mutable std::vector<std::unique_ptr<dregx::ir::Capture>> newSubGroupsOwned;
		mutable std::vector<dregx::ir::Capture*> newSubGroups;

	public:
		NotCapture();

	public:
		std::string GetFormattedRegex() override;

		std::set<char> GetCapturedCharacters() const override;

		std::vector<Capture*> GetSubGroups() const override;

	private:
	};
}

#endif // DREGX_IR_NOTCAPTURE_H
