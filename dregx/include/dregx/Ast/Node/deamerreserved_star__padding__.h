#ifndef dregx_AST_NODE_deamerreserved_star__padding___H
#define dregx_AST_NODE_deamerreserved_star__padding___H

#include "dregx/Ast/Node/dregx.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace dregx { namespace ast { namespace node { 

	class deamerreserved_star__padding__ : public dregx<deamerreserved_star__padding__>
	{
	private:
	public:
		deamerreserved_star__padding__(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: dregx<deamerreserved_star__padding__>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // dregx_AST_NODE_deamerreserved_star__padding___H
