#ifndef dregx_AST_NODE_program_H
#define dregx_AST_NODE_program_H

#include "dregx/Ast/Node/dregx.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace dregx { namespace ast { namespace node { 

	class program : public dregx<program>
	{
	private:
	public:
		program(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: dregx<program>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // dregx_AST_NODE_program_H
