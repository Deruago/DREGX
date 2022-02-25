#ifndef dregx_AST_NODE_OPTIONAL_H
#define dregx_AST_NODE_OPTIONAL_H

#include "dregx/Ast/Node/dregx.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace dregx { namespace ast { namespace node {

	class OPTIONAL : public dregx<OPTIONAL>
	{
	private:
	public:
		OPTIONAL(deamer::external::cpp::ast::NodeInformation information_)
		: dregx<OPTIONAL>(information_, {}, {})
		{
		}
	};

}}}

#endif // dregx_AST_NODE_OPTIONAL_H
