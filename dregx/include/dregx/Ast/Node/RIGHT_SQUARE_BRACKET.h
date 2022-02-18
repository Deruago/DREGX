#ifndef dregx_AST_NODE_RIGHT_SQUARE_BRACKET_H
#define dregx_AST_NODE_RIGHT_SQUARE_BRACKET_H

#include "dregx/Ast/Node/dregx.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace dregx { namespace ast { namespace node {

	class RIGHT_SQUARE_BRACKET : public dregx<RIGHT_SQUARE_BRACKET>
	{
	private:
	public:
		RIGHT_SQUARE_BRACKET(deamer::external::cpp::ast::NodeInformation information_)
		: dregx<RIGHT_SQUARE_BRACKET>(information_, {}, {})
		{
		}
	};

}}}

#endif // dregx_AST_NODE_RIGHT_SQUARE_BRACKET_H
