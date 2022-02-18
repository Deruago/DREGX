#ifndef dregx_AST_NODE_dregx_H
#define dregx_AST_NODE_dregx_H

#include <Deamer/External/Cpp/Ast/TemplateNodeBase.h>

namespace dregx { namespace ast { namespace node {

	template<typename Derived>
	class dregx : public ::deamer::external::cpp::ast::TemplateNodeBase<dregx<Derived>, Derived>
	{
	private:
		
	public:
		dregx() = default;
		
		dregx(deamer::external::cpp::ast::NodeInformation information_, std::vector<deamer::external::cpp::ast::Node*> nodes_ = {}, std::vector<size_t> baseValues_ = {})
		: deamer::external::cpp::ast::TemplateNodeBase<dregx<Derived>, Derived>(information_, nodes_, baseValues_)
		{
		}
	};

}}}

#endif // dregx_AST_NODE_dregx_H
