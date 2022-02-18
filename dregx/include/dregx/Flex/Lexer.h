#ifndef dregx_FLEX_LEXER_H
#define dregx_FLEX_LEXER_H

#include <Deamer/External/Cpp/Lexer/Interface/Lexer.h>

namespace dregx { namespace lexer {

	class Lexer : public deamer::external::cpp::lexer::Lexer
	{
	public:
		Lexer() = default;
		~Lexer() override = default;
	public:
		std::vector<const deamer::external::cpp::lexer::TerminalObject*> Tokenize(const std::string& text) const override;
	};

}}

#endif // dregx_FLEX_LEXER_H
