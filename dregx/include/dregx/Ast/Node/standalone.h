#ifndef dregx_AST_NODE_standalone_H
#define dregx_AST_NODE_standalone_H

#include "dregx/Ast/Node/dregx.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace dregx { namespace ast { namespace node { 

	class standalone : public dregx<standalone>
	{
	private:
	public:
		standalone(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: dregx<standalone>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // dregx_AST_NODE_standalone_H
