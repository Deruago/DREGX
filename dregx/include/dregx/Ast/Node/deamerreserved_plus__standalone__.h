#ifndef dregx_AST_NODE_deamerreserved_plus__standalone___H
#define dregx_AST_NODE_deamerreserved_plus__standalone___H

#include "dregx/Ast/Node/dregx.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace dregx { namespace ast { namespace node { 

	class deamerreserved_plus__standalone__ : public dregx<deamerreserved_plus__standalone__>
	{
	private:
	public:
		deamerreserved_plus__standalone__(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: dregx<deamerreserved_plus__standalone__>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // dregx_AST_NODE_deamerreserved_plus__standalone___H
