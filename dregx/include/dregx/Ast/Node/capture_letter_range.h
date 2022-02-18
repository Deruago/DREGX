#ifndef dregx_AST_NODE_capture_letter_range_H
#define dregx_AST_NODE_capture_letter_range_H

#include "dregx/Ast/Node/dregx.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace dregx { namespace ast { namespace node { 

	class capture_letter_range : public dregx<capture_letter_range>
	{
	private:
	public:
		capture_letter_range(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: dregx<capture_letter_range>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // dregx_AST_NODE_capture_letter_range_H
