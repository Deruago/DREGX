#ifndef dregx_AST_NODE_LEFT_SQUARE_BRACKET_H
#define dregx_AST_NODE_LEFT_SQUARE_BRACKET_H

#include "dregx/Ast/Node/dregx.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace dregx { namespace ast { namespace node {

	class LEFT_SQUARE_BRACKET : public dregx<LEFT_SQUARE_BRACKET>
	{
	private:
	public:
		LEFT_SQUARE_BRACKET(deamer::external::cpp::ast::NodeInformation information_)
		: dregx<LEFT_SQUARE_BRACKET>(information_, {}, {})
		{
		}
	};

}}}

#endif // dregx_AST_NODE_LEFT_SQUARE_BRACKET_H
