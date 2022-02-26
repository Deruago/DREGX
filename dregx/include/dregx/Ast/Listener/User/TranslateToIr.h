#ifndef DREGX_AST_LISTENER_USER_TRANSLATETOIR_H
#define DREGX_AST_LISTENER_USER_TRANSLATETOIR_H

#include "dregx/Ast/Listener/EnterExitListener.h"
#include "dregx/Ast/Reference/Access.h"
#include "dregx/Ir/Capture.h"
#include "dregx/Ir/CaptureRange.h"
#include "dregx/Ir/Character.h"
#include "dregx/Ir/EscapeCharacter.h"
#include "dregx/Ir/Extension.h"
#include "dregx/Ir/Group.h"
#include "dregx/Ir/OrGroup.h"
#include "dregx/Ir/Square.h"
#include "dregx/Ir/Word.h"
#include <memory>

namespace dregx::ast::listener::user
{
	class TranslateToIr : public EnterExitListener
	{
	public:
		TranslateToIr() = default;

		void Dispatch(const deamer::external::cpp::ast::Node* node) override
		{
			AddCapture(new ir::Group());
			EnterExitListener::Dispatch(node);
		}

	private:
		std::size_t groupFlavor = 0;
		std::size_t orGroupFlavor = 0;
		std::size_t squareFlavor = 0;
		std::size_t wordFlavor = 0;
		std::vector<ir::Capture*> captureStack; // vector used as stack

		void ListenEntry(const dregx::ast::node::group* node) override
		{
			groupFlavor++;
			AddCapture(new ir::Group());

			if (node->GetNodes().size() >= 6)
			{
				reference::Access_if<::dregx::ast::node::PLUS>(
					node->GetIndex(5), [&](reference::Access<::dregx::ast::node::PLUS>) {
						GetCurrentCapture()->SetExtension({1, 1, true});
					});
				reference::Access_if<::dregx::ast::node::STAR>(
					node->GetIndex(5), [&](reference::Access<::dregx::ast::node::STAR>) {
						GetCurrentCapture()->SetExtension({0, 0, true});
					});
				reference::Access_if<::dregx::ast::node::OPTIONAL>(
					node->GetIndex(5), [&](reference::Access<::dregx::ast::node::OPTIONAL>) {
						GetCurrentCapture()->SetExtension({0, 1, false});
					});
			}
		}
		void ListenExit(const dregx::ast::node::group* node) override
		{
			groupFlavor--;
			PopCapture();
		}

		void ListenEntry(const dregx::ast::node::or_concat* node) override
		{
			orGroupFlavor++;
			AddCapture(new ir::OrGroup());
		}
		void ListenExit(const dregx::ast::node::or_concat* node) override
		{
			orGroupFlavor--;
			PopCapture();
		}

		void ListenEntry(const dregx::ast::node::square* node) override
		{
			squareFlavor++;
			AddCapture(new ir::Square());

			if (node->GetNodes().size() >= 2)
			{
				reference::Access_if<::dregx::ast::node::PLUS>(
					node->GetIndex(1), [&](reference::Access<::dregx::ast::node::PLUS>) {
						GetCurrentCapture()->SetExtension({1, 1, true});
					});
				reference::Access_if<::dregx::ast::node::STAR>(
					node->GetIndex(1), [&](reference::Access<::dregx::ast::node::STAR>) {
						GetCurrentCapture()->SetExtension({0, 0, true});
					});
				reference::Access_if<::dregx::ast::node::OPTIONAL>(
					node->GetIndex(1), [&](reference::Access<::dregx::ast::node::OPTIONAL>) {
						GetCurrentCapture()->SetExtension({0, 1, false});
					});
			}
		}
		void ListenExit(const dregx::ast::node::square* node) override
		{
			squareFlavor--;
			PopCapture();
		}

		void ListenEntry(const dregx::ast::node::standalone* node) override
		{
			wordFlavor++;
			auto* newWord = new ir::Word();
			AddCapture(newWord);

			const std::string padding = reference::Access<::dregx::ast::node::standalone>(node)
											.opt_pad()
											.GetContent()[0]
											->GetText();
			std::string word;
			reference::Access<::dregx::ast::node::standalone>(node).any_letter().for_all(
				[&](reference::Access<::dregx::ast::node::any_letter> letter) {
					word += letter.GetContent()[0]->GetText();
				});
			reference::Access<::dregx::ast::node::standalone>(node).any_number().for_all(
				[&](reference::Access<::dregx::ast::node::any_number> number) {
					word += number.GetContent()[0]->GetText();
				});
			newWord->SetWord(padding + word);
		}
		void ListenExit(const dregx::ast::node::standalone* node) override
		{
			wordFlavor--;
			PopCapture();
		}

		void ListenEntry(const dregx::ast::node::capture_range* node) override
		{
			// 0->0 is minimal
			// 0->1 is MIN character used as separator
			// 0->2 is maximum
			auto* newRangeCapture = new ir::CaptureRange(node->GetIndex(0)->GetIndex(0)->GetText(),
														 node->GetIndex(0)->GetIndex(2)->GetText());
			AddCapture(newRangeCapture);
		}
		void ListenExit(const dregx::ast::node::capture_range* node) override
		{
			PopCapture();
		}

		void ListenEntry(const dregx::ast::node::capture_special_character* node) override
		{
			auto* newEscapeCharacterCapture = new ir::EscapeCharacter(
				reference::Access(node).special_char_any().any().GetContent()[0]->GetText());
			AddCapture(newEscapeCharacterCapture);
		}
		void ListenExit(const dregx::ast::node::capture_special_character* node) override
		{
			PopCapture();
		}

		void ListenEntry(const dregx::ast::node::extension_modifier* node) override
		{
			const auto minRepetition =
				reference::Access(node).min_repition().GetContent()[0]->GetText();
			const auto maxRepetition =
				reference::Access(node).max_repition().GetContent()[0]->GetText();

			const ir::Extension ext(std::stoul(minRepetition), std::stoul(maxRepetition), false);
			GetCurrentCapture()->SetExtension(ext);
		}

		void ListenEntry(const dregx::ast::node::capture_letter* node) override
		{
			auto* newCharacterCapture = new ir::Character(node->GetText());
			AddCapture(newCharacterCapture);
		}
		void ListenExit(const dregx::ast::node::capture_letter* node) override
		{
			PopCapture();
		}

		void ListenEntry(const dregx::ast::node::capture_number* node) override
		{
			auto* newCharacterCapture = new ir::Character(node->GetText());
			AddCapture(newCharacterCapture);
		}
		void ListenExit(const dregx::ast::node::capture_number* node) override
		{
			PopCapture();
		}

		void ListenEntry(const dregx::ast::node::capture_whitespace* node) override
		{
			auto* newCharacterCapture = new ir::Character(node->GetText());
			AddCapture(newCharacterCapture);
		}
		void ListenExit(const dregx::ast::node::capture_whitespace* node) override
		{
			PopCapture();
		}

		void ListenEntry(const dregx::ast::node::capture_symbols* node) override
		{
			auto* newCharacterCapture = new ir::Character(node->GetText());
			AddCapture(newCharacterCapture);
		}
		void ListenExit(const dregx::ast::node::capture_symbols* node) override
		{
			PopCapture();
		}

		ir::Capture* GetCurrentCapture() const
		{
			if (captureStack.empty())
			{
				return nullptr;
			}

			return captureStack[captureStack.size() - 1];
		}

		void AddCapture(ir::Capture* capture)
		{
			if (GetCurrentCapture() != nullptr)
			{
				GetCurrentCapture()->AddSubCapture(capture);
			}
			captureStack.push_back(capture);
		}

		void PopCapture()
		{
			captureStack.pop_back();
		}

	public:
		std::unique_ptr<ir::Capture> GetOutput()
		{
			std::unique_ptr<ir::Capture> result(GetCurrentCapture());
			PopCapture(); // ensure there is no top element anymore
			return result;
		}
	};
}

#endif // DREGX_AST_LISTENER_USER_TRANSLATETOIR_H
