#ifndef dregx_AST_NODE_SLASH_H
#define dregx_AST_NODE_SLASH_H

#include "dregx/Ast/Node/dregx.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace dregx { namespace ast { namespace node {

	class SLASH : public dregx<SLASH>
	{
	private:
	public:
		SLASH(deamer::external::cpp::ast::NodeInformation information_)
		: dregx<SLASH>(information_, {}, {})
		{
		}
	};

}}}

#endif // dregx_AST_NODE_SLASH_H
