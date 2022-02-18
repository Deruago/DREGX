#ifndef dregx_AST_NODE_any_letter_H
#define dregx_AST_NODE_any_letter_H

#include "dregx/Ast/Node/dregx.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace dregx { namespace ast { namespace node { 

	class any_letter : public dregx<any_letter>
	{
	private:
	public:
		any_letter(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: dregx<any_letter>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // dregx_AST_NODE_any_letter_H
