#ifndef dregx_AST_NODE_special_char_v_H
#define dregx_AST_NODE_special_char_v_H

#include "dregx/Ast/Node/dregx.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace dregx { namespace ast { namespace node { 

	class special_char_v : public dregx<special_char_v>
	{
	private:
	public:
		special_char_v(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: dregx<special_char_v>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // dregx_AST_NODE_special_char_v_H
