#ifndef dregx_AST_NODE_extension_modifier_H
#define dregx_AST_NODE_extension_modifier_H

#include "dregx/Ast/Node/dregx.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace dregx { namespace ast { namespace node { 

	class extension_modifier : public dregx<extension_modifier>
	{
	private:
	public:
		extension_modifier(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: dregx<extension_modifier>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // dregx_AST_NODE_extension_modifier_H
