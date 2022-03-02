#ifndef DREGX_IR_CAPTURE_H
#define DREGX_IR_CAPTURE_H

#include "dregx/Ir/CaptureType.h"
#include "dregx/Ir/Extension.h"
#include <set>
#include <vector>

namespace dregx::ir
{
	class Capture
	{
	private:
		const CaptureType captureType; // Represents subtype
		Extension extension;
		std::vector<Capture*> subGroups;
		std::set<std::string> flavors;

	public:
		Capture(CaptureType captureType_);
		virtual ~Capture();

	public:
		void SetExtension(Extension extension_);
		void AddSubCapture(Capture* subGroup_);
		void ClearSubGroups();

		CaptureType GetCaptureType() const;
		Extension GetExtension() const;
		std::vector<Capture*> GetSubGroups() const;

		virtual std::string GetFormattedRegex();

		void AddFlavor(const std::string& flavor);
		void RemoveFlavor(const std::string& flavor);
		std::set<std::string> GetFlavors() const;

	private:
	};
}

#endif // DREGX_IR_CAPTURE_H
