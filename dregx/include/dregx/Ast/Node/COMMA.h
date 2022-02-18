#ifndef dregx_AST_NODE_COMMA_H
#define dregx_AST_NODE_COMMA_H

#include "dregx/Ast/Node/dregx.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace dregx { namespace ast { namespace node {

	class COMMA : public dregx<COMMA>
	{
	private:
	public:
		COMMA(deamer::external::cpp::ast::NodeInformation information_)
		: dregx<COMMA>(information_, {}, {})
		{
		}
	};

}}}

#endif // dregx_AST_NODE_COMMA_H
