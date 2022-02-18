#ifndef dregx_AST_NODE_MIN_H
#define dregx_AST_NODE_MIN_H

#include "dregx/Ast/Node/dregx.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace dregx { namespace ast { namespace node {

	class MIN : public dregx<MIN>
	{
	private:
	public:
		MIN(deamer::external::cpp::ast::NodeInformation information_)
		: dregx<MIN>(information_, {}, {})
		{
		}
	};

}}}

#endif // dregx_AST_NODE_MIN_H
