#ifndef dregx_AST_NODE_B__H
#define dregx_AST_NODE_B__H

#include "dregx/Ast/Node/dregx.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace dregx { namespace ast { namespace node {

	class B_ : public dregx<B_>
	{
	private:
	public:
		B_(deamer::external::cpp::ast::NodeInformation information_)
		: dregx<B_>(information_, {}, {})
		{
		}
	};

}}}

#endif // dregx_AST_NODE_B__H
