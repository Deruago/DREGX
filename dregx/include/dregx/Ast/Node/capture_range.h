#ifndef dregx_AST_NODE_capture_range_H
#define dregx_AST_NODE_capture_range_H

#include "dregx/Ast/Node/dregx.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace dregx { namespace ast { namespace node { 

	class capture_range : public dregx<capture_range>
	{
	private:
	public:
		capture_range(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: dregx<capture_range>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // dregx_AST_NODE_capture_range_H
