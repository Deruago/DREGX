#ifndef dregx_AST_NODE_DELETE_ESCAPE_CHARS_H
#define dregx_AST_NODE_DELETE_ESCAPE_CHARS_H

#include "dregx/Ast/Node/dregx.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace dregx { namespace ast { namespace node {

	class DELETE_ESCAPE_CHARS : public dregx<DELETE_ESCAPE_CHARS>
	{
	private:
	public:
		DELETE_ESCAPE_CHARS(deamer::external::cpp::ast::NodeInformation information_)
		: dregx<DELETE_ESCAPE_CHARS>(information_, {}, {})
		{
		}
	};

}}}

#endif // dregx_AST_NODE_DELETE_ESCAPE_CHARS_H
