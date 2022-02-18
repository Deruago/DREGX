#ifndef dregx_AST_NODE_special_char_n_H
#define dregx_AST_NODE_special_char_n_H

#include "dregx/Ast/Node/dregx.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace dregx { namespace ast { namespace node { 

	class special_char_n : public dregx<special_char_n>
	{
	private:
	public:
		special_char_n(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: dregx<special_char_n>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // dregx_AST_NODE_special_char_n_H
