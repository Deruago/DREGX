#ifndef dregx_AST_NODE_NUMBER_H
#define dregx_AST_NODE_NUMBER_H

#include "dregx/Ast/Node/dregx.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace dregx { namespace ast { namespace node {

	class NUMBER : public dregx<NUMBER>
	{
	private:
	public:
		NUMBER(deamer::external::cpp::ast::NodeInformation information_)
		: dregx<NUMBER>(information_, {}, {})
		{
		}
	};

}}}

#endif // dregx_AST_NODE_NUMBER_H
