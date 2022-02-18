#ifndef dregx_AST_NODE_NOT_H
#define dregx_AST_NODE_NOT_H

#include "dregx/Ast/Node/dregx.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace dregx { namespace ast { namespace node {

	class NOT : public dregx<NOT>
	{
	private:
	public:
		NOT(deamer::external::cpp::ast::NodeInformation information_)
		: dregx<NOT>(information_, {}, {})
		{
		}
	};

}}}

#endif // dregx_AST_NODE_NOT_H
