#ifndef dregx_AST_NODE_or_concat_H
#define dregx_AST_NODE_or_concat_H

#include "dregx/Ast/Node/dregx.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace dregx { namespace ast { namespace node { 

	class or_concat : public dregx<or_concat>
	{
	private:
	public:
		or_concat(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: dregx<or_concat>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // dregx_AST_NODE_or_concat_H
