#ifndef dregx_AST_NODE_extension_H
#define dregx_AST_NODE_extension_H

#include "dregx/Ast/Node/dregx.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace dregx { namespace ast { namespace node { 

	class extension : public dregx<extension>
	{
	private:
	public:
		extension(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: dregx<extension>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // dregx_AST_NODE_extension_H
