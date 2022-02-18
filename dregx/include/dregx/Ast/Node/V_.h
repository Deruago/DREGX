#ifndef dregx_AST_NODE_V__H
#define dregx_AST_NODE_V__H

#include "dregx/Ast/Node/dregx.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace dregx { namespace ast { namespace node {

	class V_ : public dregx<V_>
	{
	private:
	public:
		V_(deamer::external::cpp::ast::NodeInformation information_)
		: dregx<V_>(information_, {}, {})
		{
		}
	};

}}}

#endif // dregx_AST_NODE_V__H
