#ifndef dregx_AST_NODE_deamerreserved_arrow__or_element___H
#define dregx_AST_NODE_deamerreserved_arrow__or_element___H

#include "dregx/Ast/Node/dregx.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace dregx { namespace ast { namespace node { 

	class deamerreserved_arrow__or_element__ : public dregx<deamerreserved_arrow__or_element__>
	{
	private:
	public:
		deamerreserved_arrow__or_element__(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: dregx<deamerreserved_arrow__or_element__>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // dregx_AST_NODE_deamerreserved_arrow__or_element___H
