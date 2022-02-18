#ifndef dregx_AST_NODE_RIGHT_CURLY_BRACKET_H
#define dregx_AST_NODE_RIGHT_CURLY_BRACKET_H

#include "dregx/Ast/Node/dregx.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace dregx { namespace ast { namespace node {

	class RIGHT_CURLY_BRACKET : public dregx<RIGHT_CURLY_BRACKET>
	{
	private:
	public:
		RIGHT_CURLY_BRACKET(deamer::external::cpp::ast::NodeInformation information_)
		: dregx<RIGHT_CURLY_BRACKET>(information_, {}, {})
		{
		}
	};

}}}

#endif // dregx_AST_NODE_RIGHT_CURLY_BRACKET_H
