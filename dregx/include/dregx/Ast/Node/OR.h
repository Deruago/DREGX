#ifndef dregx_AST_NODE_OR_H
#define dregx_AST_NODE_OR_H

#include "dregx/Ast/Node/dregx.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace dregx { namespace ast { namespace node {

	class OR : public dregx<OR>
	{
	private:
	public:
		OR(deamer::external::cpp::ast::NodeInformation information_)
		: dregx<OR>(information_, {}, {})
		{
		}
	};

}}}

#endif // dregx_AST_NODE_OR_H
