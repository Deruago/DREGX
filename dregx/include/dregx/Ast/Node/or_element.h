#ifndef dregx_AST_NODE_or_element_H
#define dregx_AST_NODE_or_element_H

#include "dregx/Ast/Node/dregx.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace dregx { namespace ast { namespace node { 

	class or_element : public dregx<or_element>
	{
	private:
	public:
		or_element(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: dregx<or_element>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // dregx_AST_NODE_or_element_H
