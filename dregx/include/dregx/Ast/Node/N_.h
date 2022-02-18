#ifndef dregx_AST_NODE_N__H
#define dregx_AST_NODE_N__H

#include "dregx/Ast/Node/dregx.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace dregx { namespace ast { namespace node {

	class N_ : public dregx<N_>
	{
	private:
	public:
		N_(deamer::external::cpp::ast::NodeInformation information_)
		: dregx<N_>(information_, {}, {})
		{
		}
	};

}}}

#endif // dregx_AST_NODE_N__H
