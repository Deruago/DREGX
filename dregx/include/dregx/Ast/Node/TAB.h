#ifndef dregx_AST_NODE_TAB_H
#define dregx_AST_NODE_TAB_H

#include "dregx/Ast/Node/dregx.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace dregx { namespace ast { namespace node {

	class TAB : public dregx<TAB>
	{
	private:
	public:
		TAB(deamer::external::cpp::ast::NodeInformation information_)
		: dregx<TAB>(information_, {}, {})
		{
		}
	};

}}}

#endif // dregx_AST_NODE_TAB_H
