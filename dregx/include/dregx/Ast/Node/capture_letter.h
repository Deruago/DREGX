#ifndef dregx_AST_NODE_capture_letter_H
#define dregx_AST_NODE_capture_letter_H

#include "dregx/Ast/Node/dregx.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace dregx { namespace ast { namespace node { 

	class capture_letter : public dregx<capture_letter>
	{
	private:
	public:
		capture_letter(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: dregx<capture_letter>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // dregx_AST_NODE_capture_letter_H
