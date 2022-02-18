#ifndef dregx_AST_NODE_group_H
#define dregx_AST_NODE_group_H

#include "dregx/Ast/Node/dregx.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace dregx { namespace ast { namespace node { 

	class group : public dregx<group>
	{
	private:
	public:
		group(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: dregx<group>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // dregx_AST_NODE_group_H
