#ifndef dregx_AST_NODE_UNDERSCORE_H
#define dregx_AST_NODE_UNDERSCORE_H

#include "dregx/Ast/Node/dregx.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace dregx { namespace ast { namespace node {

	class UNDERSCORE : public dregx<UNDERSCORE>
	{
	private:
	public:
		UNDERSCORE(deamer::external::cpp::ast::NodeInformation information_)
		: dregx<UNDERSCORE>(information_, {}, {})
		{
		}
	};

}}}

#endif // dregx_AST_NODE_UNDERSCORE_H
