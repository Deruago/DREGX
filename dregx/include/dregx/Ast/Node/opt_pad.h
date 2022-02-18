#ifndef dregx_AST_NODE_opt_pad_H
#define dregx_AST_NODE_opt_pad_H

#include "dregx/Ast/Node/dregx.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace dregx { namespace ast { namespace node { 

	class opt_pad : public dregx<opt_pad>
	{
	private:
	public:
		opt_pad(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: dregx<opt_pad>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // dregx_AST_NODE_opt_pad_H
