#ifndef dregx_AST_NODE_LETTER_H
#define dregx_AST_NODE_LETTER_H

#include "dregx/Ast/Node/dregx.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace dregx { namespace ast { namespace node {

	class LETTER : public dregx<LETTER>
	{
	private:
	public:
		LETTER(deamer::external::cpp::ast::NodeInformation information_)
		: dregx<LETTER>(information_, {}, {})
		{
		}
	};

}}}

#endif // dregx_AST_NODE_LETTER_H
