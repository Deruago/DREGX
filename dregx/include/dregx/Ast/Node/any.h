#ifndef dregx_AST_NODE_any_H
#define dregx_AST_NODE_any_H

#include "dregx/Ast/Node/dregx.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace dregx { namespace ast { namespace node { 

	class any : public dregx<any>
	{
	private:
	public:
		any(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: dregx<any>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // dregx_AST_NODE_any_H
