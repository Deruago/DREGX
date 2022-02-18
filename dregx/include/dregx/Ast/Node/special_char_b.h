#ifndef dregx_AST_NODE_special_char_b_H
#define dregx_AST_NODE_special_char_b_H

#include "dregx/Ast/Node/dregx.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace dregx { namespace ast { namespace node { 

	class special_char_b : public dregx<special_char_b>
	{
	private:
	public:
		special_char_b(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: dregx<special_char_b>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // dregx_AST_NODE_special_char_b_H
