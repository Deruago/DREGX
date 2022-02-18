#ifndef dregx_AST_NODE_PLUS_H
#define dregx_AST_NODE_PLUS_H

#include "dregx/Ast/Node/dregx.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace dregx { namespace ast { namespace node {

	class PLUS : public dregx<PLUS>
	{
	private:
	public:
		PLUS(deamer::external::cpp::ast::NodeInformation information_)
		: dregx<PLUS>(information_, {}, {})
		{
		}
	};

}}}

#endif // dregx_AST_NODE_PLUS_H
