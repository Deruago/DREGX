#ifndef dregx_AST_NODE_STAR_H
#define dregx_AST_NODE_STAR_H

#include "dregx/Ast/Node/dregx.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace dregx { namespace ast { namespace node {

	class STAR : public dregx<STAR>
	{
	private:
	public:
		STAR(deamer::external::cpp::ast::NodeInformation information_)
		: dregx<STAR>(information_, {}, {})
		{
		}
	};

}}}

#endif // dregx_AST_NODE_STAR_H
