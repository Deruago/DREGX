#ifndef dregx_AST_NODE_OTHER_H
#define dregx_AST_NODE_OTHER_H

#include "dregx/Ast/Node/dregx.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace dregx { namespace ast { namespace node {

	class OTHER : public dregx<OTHER>
	{
	private:
	public:
		OTHER(deamer::external::cpp::ast::NodeInformation information_)
		: dregx<OTHER>(information_, {}, {})
		{
		}
	};

}}}

#endif // dregx_AST_NODE_OTHER_H
