#ifndef dregx_AST_NODE_capture_symbols_H
#define dregx_AST_NODE_capture_symbols_H

#include "dregx/Ast/Node/dregx.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace dregx { namespace ast { namespace node { 

	class capture_symbols : public dregx<capture_symbols>
	{
	private:
	public:
		capture_symbols(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: dregx<capture_symbols>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // dregx_AST_NODE_capture_symbols_H
