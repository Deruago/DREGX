#ifndef dregx_AST_NODE_T__H
#define dregx_AST_NODE_T__H

#include "dregx/Ast/Node/dregx.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace dregx { namespace ast { namespace node {

	class T_ : public dregx<T_>
	{
	private:
	public:
		T_(deamer::external::cpp::ast::NodeInformation information_)
		: dregx<T_>(information_, {}, {})
		{
		}
	};

}}}

#endif // dregx_AST_NODE_T__H
