#ifndef dregx_AST_NODE_max_repition_H
#define dregx_AST_NODE_max_repition_H

#include "dregx/Ast/Node/dregx.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace dregx { namespace ast { namespace node { 

	class max_repition : public dregx<max_repition>
	{
	private:
	public:
		max_repition(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: dregx<max_repition>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // dregx_AST_NODE_max_repition_H
