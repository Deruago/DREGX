#ifndef dregx_AST_NODE_any_number_H
#define dregx_AST_NODE_any_number_H

#include "dregx/Ast/Node/dregx.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace dregx { namespace ast { namespace node { 

	class any_number : public dregx<any_number>
	{
	private:
	public:
		any_number(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: dregx<any_number>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // dregx_AST_NODE_any_number_H
