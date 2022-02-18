#ifndef dregx_AST_NODE_A__H
#define dregx_AST_NODE_A__H

#include "dregx/Ast/Node/dregx.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace dregx { namespace ast { namespace node {

	class A_ : public dregx<A_>
	{
	private:
	public:
		A_(deamer::external::cpp::ast::NodeInformation information_)
		: dregx<A_>(information_, {}, {})
		{
		}
	};

}}}

#endif // dregx_AST_NODE_A__H
