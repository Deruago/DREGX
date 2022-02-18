#ifndef dregx_AST_NODE_capture_whitespace_H
#define dregx_AST_NODE_capture_whitespace_H

#include "dregx/Ast/Node/dregx.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace dregx { namespace ast { namespace node { 

	class capture_whitespace : public dregx<capture_whitespace>
	{
	private:
	public:
		capture_whitespace(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: dregx<capture_whitespace>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // dregx_AST_NODE_capture_whitespace_H
