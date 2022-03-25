#ifndef dregx_AST_NODE_capture_structure_H
#define dregx_AST_NODE_capture_structure_H

#include "dregx/Ast/Node/dregx.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace dregx { namespace ast { namespace node { 

	class capture_structure : public dregx<capture_structure>
	{
	private:
	public:
		capture_structure(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: dregx<capture_structure>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // dregx_AST_NODE_capture_structure_H
