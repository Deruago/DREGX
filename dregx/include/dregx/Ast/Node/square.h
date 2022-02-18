#ifndef dregx_AST_NODE_square_H
#define dregx_AST_NODE_square_H

#include "dregx/Ast/Node/dregx.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace dregx { namespace ast { namespace node { 

	class square : public dregx<square>
	{
	private:
	public:
		square(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: dregx<square>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // dregx_AST_NODE_square_H
