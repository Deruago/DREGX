#ifndef dregx_AST_NODE_min_repition_H
#define dregx_AST_NODE_min_repition_H

#include "dregx/Ast/Node/dregx.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace dregx { namespace ast { namespace node { 

	class min_repition : public dregx<min_repition>
	{
	private:
	public:
		min_repition(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: dregx<min_repition>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // dregx_AST_NODE_min_repition_H
