#ifndef dregx_AST_NODE_capture_number_H
#define dregx_AST_NODE_capture_number_H

#include "dregx/Ast/Node/dregx.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace dregx { namespace ast { namespace node { 

	class capture_number : public dregx<capture_number>
	{
	private:
	public:
		capture_number(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: dregx<capture_number>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // dregx_AST_NODE_capture_number_H
