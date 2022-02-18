#ifndef dregx_AST_NODE_capture_special_character_H
#define dregx_AST_NODE_capture_special_character_H

#include "dregx/Ast/Node/dregx.h"
#include <Deamer/External/Cpp/Ast/Node.h>

namespace dregx { namespace ast { namespace node { 

	class capture_special_character : public dregx<capture_special_character>
	{
	private:
	public:
		capture_special_character(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_)
		: dregx<capture_special_character>(information_, nodes_, {})
		{
		}
	};

}}}

#endif // dregx_AST_NODE_capture_special_character_H
