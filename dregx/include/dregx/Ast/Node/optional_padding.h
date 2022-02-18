#ifndef dregx_AST_NODE_optional_padding_H
#define dregx_AST_NODE_optional_padding_H

#include "dregx/Ast/Node/dregx.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace dregx { namespace ast { namespace node { 

	class optional_padding : public dregx<optional_padding>
	{
	private:
	public:
		optional_padding(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: dregx<optional_padding>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // dregx_AST_NODE_optional_padding_H
