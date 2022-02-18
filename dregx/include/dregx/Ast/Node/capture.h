#ifndef dregx_AST_NODE_capture_H
#define dregx_AST_NODE_capture_H

#include "dregx/Ast/Node/dregx.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace dregx { namespace ast { namespace node { 

	class capture : public dregx<capture>
	{
	private:
	public:
		capture(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: dregx<capture>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // dregx_AST_NODE_capture_H
