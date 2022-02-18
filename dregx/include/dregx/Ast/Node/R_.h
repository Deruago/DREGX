#ifndef dregx_AST_NODE_R__H
#define dregx_AST_NODE_R__H

#include "dregx/Ast/Node/dregx.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace dregx { namespace ast { namespace node {

	class R_ : public dregx<R_>
	{
	private:
	public:
		R_(deamer::external::cpp::ast::NodeInformation information_)
		: dregx<R_>(information_, {}, {})
		{
		}
	};

}}}

#endif // dregx_AST_NODE_R__H
