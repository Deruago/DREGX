#ifndef dregx_AST_NODE_SPACE_H
#define dregx_AST_NODE_SPACE_H

#include "dregx/Ast/Node/dregx.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace dregx { namespace ast { namespace node {

	class SPACE : public dregx<SPACE>
	{
	private:
	public:
		SPACE(deamer::external::cpp::ast::NodeInformation information_)
		: dregx<SPACE>(information_, {}, {})
		{
		}
	};

}}}

#endif // dregx_AST_NODE_SPACE_H
