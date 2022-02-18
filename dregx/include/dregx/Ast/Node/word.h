#ifndef dregx_AST_NODE_word_H
#define dregx_AST_NODE_word_H

#include "dregx/Ast/Node/dregx.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace dregx { namespace ast { namespace node { 

	class word : public dregx<word>
	{
	private:
	public:
		word(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: dregx<word>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // dregx_AST_NODE_word_H
