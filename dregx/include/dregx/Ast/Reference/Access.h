#ifndef DREGX_AST_REFERENCE_ACCESSTEMPLATEBASE_H
#define DREGX_AST_REFERENCE_ACCESSTEMPLATEBASE_H

#include "dregx/Ast/Relation/NodeEnumToType.h"
#include "dregx/Ast/Relation/NodeTypeToEnum.h"
#include "dregx/Ast/Relation/NodeIsInlined.h"

#include "dregx/Ast/Enum/Type.h"
#include "dregx/Ast/Node/program.h"
#include "dregx/Ast/Node/deamerreserved_star__stmt__.h"
#include "dregx/Ast/Node/stmt.h"
#include "dregx/Ast/Node/word.h"
#include "dregx/Ast/Node/group.h"
#include "dregx/Ast/Node/deamerreserved_plus__word__.h"
#include "dregx/Ast/Node/or_concat.h"
#include "dregx/Ast/Node/deamerreserved_arrow__word__.h"
#include "dregx/Ast/Node/deamerreserved_star__opt_pad__OR__word__.h"
#include "dregx/Ast/Node/square.h"
#include "dregx/Ast/Node/capture.h"
#include "dregx/Ast/Node/deamerreserved_plus__capture_logic__.h"
#include "dregx/Ast/Node/capture_logic.h"
#include "dregx/Ast/Node/capture_symbols.h"
#include "dregx/Ast/Node/capture_whitespace.h"
#include "dregx/Ast/Node/capture_range.h"
#include "dregx/Ast/Node/capture_letter_range.h"
#include "dregx/Ast/Node/capture_number_range.h"
#include "dregx/Ast/Node/capture_number.h"
#include "dregx/Ast/Node/capture_letter.h"
#include "dregx/Ast/Node/capture_special_character.h"
#include "dregx/Ast/Node/extension_modifier.h"
#include "dregx/Ast/Node/min_repition.h"
#include "dregx/Ast/Node/deamerreserved_plus__NUMBER__.h"
#include "dregx/Ast/Node/max_repition.h"
#include "dregx/Ast/Node/standalone.h"
#include "dregx/Ast/Node/opt_pad.h"
#include "dregx/Ast/Node/optional_padding.h"
#include "dregx/Ast/Node/deamerreserved_star__padding__.h"
#include "dregx/Ast/Node/padding.h"
#include "dregx/Ast/Node/special_char_any.h"
#include "dregx/Ast/Node/any_number.h"
#include "dregx/Ast/Node/any_letter.h"
#include "dregx/Ast/Node/any_letter_exclude_underscore.h"
#include "dregx/Ast/Node/any.h"
#include "dregx/Ast/Node/LEFT_CURLY_BRACKET.h"
#include "dregx/Ast/Node/RIGHT_CURLY_BRACKET.h"
#include "dregx/Ast/Node/LEFT_SQUARE_BRACKET_NOT.h"
#include "dregx/Ast/Node/LEFT_SQUARE_BRACKET.h"
#include "dregx/Ast/Node/RIGHT_SQUARE_BRACKET.h"
#include "dregx/Ast/Node/LEFT_BRACKET.h"
#include "dregx/Ast/Node/RIGHT_BRACKET.h"
#include "dregx/Ast/Node/COMMA.h"
#include "dregx/Ast/Node/SLASH.h"
#include "dregx/Ast/Node/OR.h"
#include "dregx/Ast/Node/MIN.h"
#include "dregx/Ast/Node/UNDERSCORE.h"
#include "dregx/Ast/Node/NOT.h"
#include "dregx/Ast/Node/PLUS.h"
#include "dregx/Ast/Node/STAR.h"
#include "dregx/Ast/Node/OPTIONAL.h"
#include "dregx/Ast/Node/NUMBER.h"
#include "dregx/Ast/Node/T_.h"
#include "dregx/Ast/Node/N_.h"
#include "dregx/Ast/Node/R_.h"
#include "dregx/Ast/Node/B_.h"
#include "dregx/Ast/Node/V_.h"
#include "dregx/Ast/Node/A_.h"
#include "dregx/Ast/Node/LETTER.h"
#include "dregx/Ast/Node/SPACE.h"
#include "dregx/Ast/Node/TAB.h"
#include "dregx/Ast/Node/OTHER.h"
#include "dregx/Ast/Node/DELETE_ESCAPE_CHARS.h"


#include <vector>
#include <utility>

namespace dregx { namespace ast { namespace reference { 

	struct AccessBase
	{	
	public:
		AccessBase() = default;

	protected:
		template<::dregx::ast::Type T>
		void Get(std::vector<const ::dregx::ast::relation::NodeEnumToType_t<T>*>& foundNodes, const ::deamer::external::cpp::ast::Node* currentNode)
		{
			for(const auto* const node : currentNode->GetNodes())
			{
				if (node->GetType() == static_cast<::std::size_t>(T))
				{
					foundNodes.push_back(static_cast<const  ::dregx::ast::relation::NodeEnumToType_t<T>*>(node));
				}
				else if (::dregx::ast::relation::NodeIsInlined(static_cast<::dregx::ast::Type>(node->GetType())))
				{
					Get<T>(foundNodes, node);
				}
			}
		}

		template<::dregx::ast::Type T, typename Q>
		inline std::vector<const ::dregx::ast::relation::NodeEnumToType_t<T>*> Get(std::vector<const Q*>& currentNodes)
		{
			std::vector<const ::dregx::ast::relation::NodeEnumToType_t<T>*> foundNodes;

			for (const auto* const currentNode : currentNodes)
			{
				AccessBase::Get<T>(foundNodes, currentNode);
			}

			return foundNodes;
		}
	};

	/*!	\class AccessTemplateBase
	 *
	 *	\brief Used to access AST nodes. It contains various helper functions to ease navigation through AST nodes.
	 *
	 *	\details This class contains the type dependent implementation of Access<T>.
	 *	Refrain from using this class, as there is no backwards compatibility
	 *	guarantee of this implementation class,
	 *	Use Access<T> instead, this is backwards compatible and offers different benefits.
	 *
	 *	\see Access
	 */
	template<typename T>
	struct AccessTemplateBase : public AccessBase
	{
		AccessTemplateBase() = delete;
		~AccessTemplateBase() = delete;
	};

	/*! \class Access
	 *
	 *	\brief Used to access AST nodes. It contains various helper functions to ease navigation through AST nodes.
	 *
	 *	\details Type dispatcher for logic.
	 *
	 *	\see AccessTemplateBase
	 */
	template<typename T>
	struct Access : public AccessTemplateBase<T>
	{
		Access(std::vector<const T*> ts_) : AccessTemplateBase<T>(ts_)
		{
		}

		Access(const T& t) : AccessTemplateBase<T>(t)
		{
		}

		Access(const T* t) : AccessTemplateBase<T>(t)
		{
		}

		Access(const AccessTemplateBase<T>& rhs) : AccessTemplateBase<T>(rhs)
		{
		}

		Access() = default;
	};

	template<>
	struct AccessTemplateBase<::dregx::ast::node::program>;
	template<>
	struct AccessTemplateBase<::dregx::ast::node::deamerreserved_star__stmt__>;
	template<>
	struct AccessTemplateBase<::dregx::ast::node::stmt>;
	template<>
	struct AccessTemplateBase<::dregx::ast::node::word>;
	template<>
	struct AccessTemplateBase<::dregx::ast::node::group>;
	template<>
	struct AccessTemplateBase<::dregx::ast::node::deamerreserved_plus__word__>;
	template<>
	struct AccessTemplateBase<::dregx::ast::node::or_concat>;
	template<>
	struct AccessTemplateBase<::dregx::ast::node::deamerreserved_arrow__word__>;
	template<>
	struct AccessTemplateBase<::dregx::ast::node::deamerreserved_star__opt_pad__OR__word__>;
	template<>
	struct AccessTemplateBase<::dregx::ast::node::square>;
	template<>
	struct AccessTemplateBase<::dregx::ast::node::capture>;
	template<>
	struct AccessTemplateBase<::dregx::ast::node::deamerreserved_plus__capture_logic__>;
	template<>
	struct AccessTemplateBase<::dregx::ast::node::capture_logic>;
	template<>
	struct AccessTemplateBase<::dregx::ast::node::capture_symbols>;
	template<>
	struct AccessTemplateBase<::dregx::ast::node::capture_whitespace>;
	template<>
	struct AccessTemplateBase<::dregx::ast::node::capture_range>;
	template<>
	struct AccessTemplateBase<::dregx::ast::node::capture_letter_range>;
	template<>
	struct AccessTemplateBase<::dregx::ast::node::capture_number_range>;
	template<>
	struct AccessTemplateBase<::dregx::ast::node::capture_number>;
	template<>
	struct AccessTemplateBase<::dregx::ast::node::capture_letter>;
	template<>
	struct AccessTemplateBase<::dregx::ast::node::capture_special_character>;
	template<>
	struct AccessTemplateBase<::dregx::ast::node::extension_modifier>;
	template<>
	struct AccessTemplateBase<::dregx::ast::node::min_repition>;
	template<>
	struct AccessTemplateBase<::dregx::ast::node::deamerreserved_plus__NUMBER__>;
	template<>
	struct AccessTemplateBase<::dregx::ast::node::max_repition>;
	template<>
	struct AccessTemplateBase<::dregx::ast::node::standalone>;
	template<>
	struct AccessTemplateBase<::dregx::ast::node::opt_pad>;
	template<>
	struct AccessTemplateBase<::dregx::ast::node::optional_padding>;
	template<>
	struct AccessTemplateBase<::dregx::ast::node::deamerreserved_star__padding__>;
	template<>
	struct AccessTemplateBase<::dregx::ast::node::padding>;
	template<>
	struct AccessTemplateBase<::dregx::ast::node::special_char_any>;
	template<>
	struct AccessTemplateBase<::dregx::ast::node::any_number>;
	template<>
	struct AccessTemplateBase<::dregx::ast::node::any_letter>;
	template<>
	struct AccessTemplateBase<::dregx::ast::node::any_letter_exclude_underscore>;
	template<>
	struct AccessTemplateBase<::dregx::ast::node::any>;
	template<>
	struct AccessTemplateBase<::dregx::ast::node::LEFT_CURLY_BRACKET>;
	template<>
	struct AccessTemplateBase<::dregx::ast::node::RIGHT_CURLY_BRACKET>;
	template<>
	struct AccessTemplateBase<::dregx::ast::node::LEFT_SQUARE_BRACKET_NOT>;
	template<>
	struct AccessTemplateBase<::dregx::ast::node::LEFT_SQUARE_BRACKET>;
	template<>
	struct AccessTemplateBase<::dregx::ast::node::RIGHT_SQUARE_BRACKET>;
	template<>
	struct AccessTemplateBase<::dregx::ast::node::LEFT_BRACKET>;
	template<>
	struct AccessTemplateBase<::dregx::ast::node::RIGHT_BRACKET>;
	template<>
	struct AccessTemplateBase<::dregx::ast::node::COMMA>;
	template<>
	struct AccessTemplateBase<::dregx::ast::node::SLASH>;
	template<>
	struct AccessTemplateBase<::dregx::ast::node::OR>;
	template<>
	struct AccessTemplateBase<::dregx::ast::node::MIN>;
	template<>
	struct AccessTemplateBase<::dregx::ast::node::UNDERSCORE>;
	template<>
	struct AccessTemplateBase<::dregx::ast::node::NOT>;
	template<>
	struct AccessTemplateBase<::dregx::ast::node::PLUS>;
	template<>
	struct AccessTemplateBase<::dregx::ast::node::STAR>;
	template<>
	struct AccessTemplateBase<::dregx::ast::node::OPTIONAL>;
	template<>
	struct AccessTemplateBase<::dregx::ast::node::NUMBER>;
	template<>
	struct AccessTemplateBase<::dregx::ast::node::T_>;
	template<>
	struct AccessTemplateBase<::dregx::ast::node::N_>;
	template<>
	struct AccessTemplateBase<::dregx::ast::node::R_>;
	template<>
	struct AccessTemplateBase<::dregx::ast::node::B_>;
	template<>
	struct AccessTemplateBase<::dregx::ast::node::V_>;
	template<>
	struct AccessTemplateBase<::dregx::ast::node::A_>;
	template<>
	struct AccessTemplateBase<::dregx::ast::node::LETTER>;
	template<>
	struct AccessTemplateBase<::dregx::ast::node::SPACE>;
	template<>
	struct AccessTemplateBase<::dregx::ast::node::TAB>;
	template<>
	struct AccessTemplateBase<::dregx::ast::node::OTHER>;
	template<>
	struct AccessTemplateBase<::dregx::ast::node::DELETE_ESCAPE_CHARS>;


	
	template<>
	struct AccessTemplateBase<::dregx::ast::node::program> : public AccessBase
	{
	protected:
		std::vector<const ::dregx::ast::node::program*> ts;

	public:
		AccessTemplateBase(std::vector<const ::dregx::ast::node::program*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::program& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::program* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::dregx::ast::node::program>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::dregx::ast::node::program>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::dregx::ast::node::program*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::dregx::ast::node::program*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::dregx::ast::node::deamerreserved_star__stmt__> deamerreserved_star__stmt__();
AccessTemplateBase<::dregx::ast::node::stmt> stmt();
AccessTemplateBase<::dregx::ast::node::opt_pad> opt_pad();


		template<typename FunctionType>
		AccessTemplateBase<::dregx::ast::node::program>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::dregx::ast::node::deamerreserved_star__stmt__> : public AccessBase
	{
	protected:
		std::vector<const ::dregx::ast::node::deamerreserved_star__stmt__*> ts;

	public:
		AccessTemplateBase(std::vector<const ::dregx::ast::node::deamerreserved_star__stmt__*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::deamerreserved_star__stmt__& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::deamerreserved_star__stmt__* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::dregx::ast::node::deamerreserved_star__stmt__>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::dregx::ast::node::deamerreserved_star__stmt__>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::dregx::ast::node::deamerreserved_star__stmt__*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::dregx::ast::node::deamerreserved_star__stmt__*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::dregx::ast::node::deamerreserved_star__stmt__> deamerreserved_star__stmt__();
AccessTemplateBase<::dregx::ast::node::stmt> stmt();


		template<typename FunctionType>
		AccessTemplateBase<::dregx::ast::node::deamerreserved_star__stmt__>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::dregx::ast::node::stmt> : public AccessBase
	{
	protected:
		std::vector<const ::dregx::ast::node::stmt*> ts;

	public:
		AccessTemplateBase(std::vector<const ::dregx::ast::node::stmt*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::stmt& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::stmt* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::dregx::ast::node::stmt>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::dregx::ast::node::stmt>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::dregx::ast::node::stmt*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::dregx::ast::node::stmt*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::dregx::ast::node::word> word();


		template<typename FunctionType>
		AccessTemplateBase<::dregx::ast::node::stmt>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::dregx::ast::node::word> : public AccessBase
	{
	protected:
		std::vector<const ::dregx::ast::node::word*> ts;

	public:
		AccessTemplateBase(std::vector<const ::dregx::ast::node::word*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::word& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::word* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::dregx::ast::node::word>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::dregx::ast::node::word>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::dregx::ast::node::word*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::dregx::ast::node::word*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::dregx::ast::node::group> group();
AccessTemplateBase<::dregx::ast::node::square> square();
AccessTemplateBase<::dregx::ast::node::standalone> standalone();


		template<typename FunctionType>
		AccessTemplateBase<::dregx::ast::node::word>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::dregx::ast::node::group> : public AccessBase
	{
	protected:
		std::vector<const ::dregx::ast::node::group*> ts;

	public:
		AccessTemplateBase(std::vector<const ::dregx::ast::node::group*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::group& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::group* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::dregx::ast::node::group>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::dregx::ast::node::group>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::dregx::ast::node::group*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::dregx::ast::node::group*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::dregx::ast::node::word> word();
AccessTemplateBase<::dregx::ast::node::deamerreserved_plus__word__> deamerreserved_plus__word__();
AccessTemplateBase<::dregx::ast::node::or_concat> or_concat();
AccessTemplateBase<::dregx::ast::node::extension_modifier> extension_modifier();
AccessTemplateBase<::dregx::ast::node::opt_pad> opt_pad();
AccessTemplateBase<::dregx::ast::node::LEFT_CURLY_BRACKET> LEFT_CURLY_BRACKET();
AccessTemplateBase<::dregx::ast::node::RIGHT_CURLY_BRACKET> RIGHT_CURLY_BRACKET();
AccessTemplateBase<::dregx::ast::node::PLUS> PLUS();
AccessTemplateBase<::dregx::ast::node::STAR> STAR();
AccessTemplateBase<::dregx::ast::node::OPTIONAL> OPTIONAL();


		template<typename FunctionType>
		AccessTemplateBase<::dregx::ast::node::group>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::dregx::ast::node::deamerreserved_plus__word__> : public AccessBase
	{
	protected:
		std::vector<const ::dregx::ast::node::deamerreserved_plus__word__*> ts;

	public:
		AccessTemplateBase(std::vector<const ::dregx::ast::node::deamerreserved_plus__word__*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::deamerreserved_plus__word__& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::deamerreserved_plus__word__* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::dregx::ast::node::deamerreserved_plus__word__>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::dregx::ast::node::deamerreserved_plus__word__>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::dregx::ast::node::deamerreserved_plus__word__*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::dregx::ast::node::deamerreserved_plus__word__*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::dregx::ast::node::word> word();
AccessTemplateBase<::dregx::ast::node::deamerreserved_plus__word__> deamerreserved_plus__word__();


		template<typename FunctionType>
		AccessTemplateBase<::dregx::ast::node::deamerreserved_plus__word__>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::dregx::ast::node::or_concat> : public AccessBase
	{
	protected:
		std::vector<const ::dregx::ast::node::or_concat*> ts;

	public:
		AccessTemplateBase(std::vector<const ::dregx::ast::node::or_concat*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::or_concat& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::or_concat* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::dregx::ast::node::or_concat>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::dregx::ast::node::or_concat>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::dregx::ast::node::or_concat*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::dregx::ast::node::or_concat*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::dregx::ast::node::word> word();
AccessTemplateBase<::dregx::ast::node::deamerreserved_arrow__word__> deamerreserved_arrow__word__();
AccessTemplateBase<::dregx::ast::node::deamerreserved_star__opt_pad__OR__word__> deamerreserved_star__opt_pad__OR__word__();
AccessTemplateBase<::dregx::ast::node::opt_pad> opt_pad();
AccessTemplateBase<::dregx::ast::node::OR> OR();


		template<typename FunctionType>
		AccessTemplateBase<::dregx::ast::node::or_concat>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::dregx::ast::node::deamerreserved_arrow__word__> : public AccessBase
	{
	protected:
		std::vector<const ::dregx::ast::node::deamerreserved_arrow__word__*> ts;

	public:
		AccessTemplateBase(std::vector<const ::dregx::ast::node::deamerreserved_arrow__word__*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::deamerreserved_arrow__word__& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::deamerreserved_arrow__word__* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::dregx::ast::node::deamerreserved_arrow__word__>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::dregx::ast::node::deamerreserved_arrow__word__>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::dregx::ast::node::deamerreserved_arrow__word__*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::dregx::ast::node::deamerreserved_arrow__word__*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::dregx::ast::node::word> word();
AccessTemplateBase<::dregx::ast::node::deamerreserved_star__opt_pad__OR__word__> deamerreserved_star__opt_pad__OR__word__();
AccessTemplateBase<::dregx::ast::node::opt_pad> opt_pad();
AccessTemplateBase<::dregx::ast::node::OR> OR();


		template<typename FunctionType>
		AccessTemplateBase<::dregx::ast::node::deamerreserved_arrow__word__>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::dregx::ast::node::deamerreserved_star__opt_pad__OR__word__> : public AccessBase
	{
	protected:
		std::vector<const ::dregx::ast::node::deamerreserved_star__opt_pad__OR__word__*> ts;

	public:
		AccessTemplateBase(std::vector<const ::dregx::ast::node::deamerreserved_star__opt_pad__OR__word__*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::deamerreserved_star__opt_pad__OR__word__& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::deamerreserved_star__opt_pad__OR__word__* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::dregx::ast::node::deamerreserved_star__opt_pad__OR__word__>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::dregx::ast::node::deamerreserved_star__opt_pad__OR__word__>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::dregx::ast::node::deamerreserved_star__opt_pad__OR__word__*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::dregx::ast::node::deamerreserved_star__opt_pad__OR__word__*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::dregx::ast::node::word> word();
AccessTemplateBase<::dregx::ast::node::deamerreserved_star__opt_pad__OR__word__> deamerreserved_star__opt_pad__OR__word__();
AccessTemplateBase<::dregx::ast::node::opt_pad> opt_pad();
AccessTemplateBase<::dregx::ast::node::OR> OR();


		template<typename FunctionType>
		AccessTemplateBase<::dregx::ast::node::deamerreserved_star__opt_pad__OR__word__>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::dregx::ast::node::square> : public AccessBase
	{
	protected:
		std::vector<const ::dregx::ast::node::square*> ts;

	public:
		AccessTemplateBase(std::vector<const ::dregx::ast::node::square*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::square& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::square* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::dregx::ast::node::square>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::dregx::ast::node::square>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::dregx::ast::node::square*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::dregx::ast::node::square*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::dregx::ast::node::capture> capture();
AccessTemplateBase<::dregx::ast::node::extension_modifier> extension_modifier();
AccessTemplateBase<::dregx::ast::node::PLUS> PLUS();
AccessTemplateBase<::dregx::ast::node::STAR> STAR();
AccessTemplateBase<::dregx::ast::node::OPTIONAL> OPTIONAL();


		template<typename FunctionType>
		AccessTemplateBase<::dregx::ast::node::square>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::dregx::ast::node::capture> : public AccessBase
	{
	protected:
		std::vector<const ::dregx::ast::node::capture*> ts;

	public:
		AccessTemplateBase(std::vector<const ::dregx::ast::node::capture*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::capture& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::capture* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::dregx::ast::node::capture>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::dregx::ast::node::capture>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::dregx::ast::node::capture*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::dregx::ast::node::capture*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::dregx::ast::node::deamerreserved_plus__capture_logic__> deamerreserved_plus__capture_logic__();
AccessTemplateBase<::dregx::ast::node::capture_logic> capture_logic();
AccessTemplateBase<::dregx::ast::node::opt_pad> opt_pad();
AccessTemplateBase<::dregx::ast::node::LEFT_SQUARE_BRACKET_NOT> LEFT_SQUARE_BRACKET_NOT();
AccessTemplateBase<::dregx::ast::node::LEFT_SQUARE_BRACKET> LEFT_SQUARE_BRACKET();
AccessTemplateBase<::dregx::ast::node::RIGHT_SQUARE_BRACKET> RIGHT_SQUARE_BRACKET();


		template<typename FunctionType>
		AccessTemplateBase<::dregx::ast::node::capture>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::dregx::ast::node::deamerreserved_plus__capture_logic__> : public AccessBase
	{
	protected:
		std::vector<const ::dregx::ast::node::deamerreserved_plus__capture_logic__*> ts;

	public:
		AccessTemplateBase(std::vector<const ::dregx::ast::node::deamerreserved_plus__capture_logic__*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::deamerreserved_plus__capture_logic__& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::deamerreserved_plus__capture_logic__* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::dregx::ast::node::deamerreserved_plus__capture_logic__>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::dregx::ast::node::deamerreserved_plus__capture_logic__>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::dregx::ast::node::deamerreserved_plus__capture_logic__*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::dregx::ast::node::deamerreserved_plus__capture_logic__*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::dregx::ast::node::deamerreserved_plus__capture_logic__> deamerreserved_plus__capture_logic__();
AccessTemplateBase<::dregx::ast::node::capture_logic> capture_logic();


		template<typename FunctionType>
		AccessTemplateBase<::dregx::ast::node::deamerreserved_plus__capture_logic__>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::dregx::ast::node::capture_logic> : public AccessBase
	{
	protected:
		std::vector<const ::dregx::ast::node::capture_logic*> ts;

	public:
		AccessTemplateBase(std::vector<const ::dregx::ast::node::capture_logic*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::capture_logic& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::capture_logic* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::dregx::ast::node::capture_logic>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::dregx::ast::node::capture_logic>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::dregx::ast::node::capture_logic*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::dregx::ast::node::capture_logic*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::dregx::ast::node::capture_symbols> capture_symbols();
AccessTemplateBase<::dregx::ast::node::capture_whitespace> capture_whitespace();
AccessTemplateBase<::dregx::ast::node::capture_range> capture_range();
AccessTemplateBase<::dregx::ast::node::capture_number> capture_number();
AccessTemplateBase<::dregx::ast::node::capture_letter> capture_letter();
AccessTemplateBase<::dregx::ast::node::capture_special_character> capture_special_character();


		template<typename FunctionType>
		AccessTemplateBase<::dregx::ast::node::capture_logic>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::dregx::ast::node::capture_symbols> : public AccessBase
	{
	protected:
		std::vector<const ::dregx::ast::node::capture_symbols*> ts;

	public:
		AccessTemplateBase(std::vector<const ::dregx::ast::node::capture_symbols*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::capture_symbols& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::capture_symbols* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::dregx::ast::node::capture_symbols>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::dregx::ast::node::capture_symbols>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::dregx::ast::node::capture_symbols*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::dregx::ast::node::capture_symbols*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::dregx::ast::node::COMMA> COMMA();
AccessTemplateBase<::dregx::ast::node::OR> OR();
AccessTemplateBase<::dregx::ast::node::PLUS> PLUS();
AccessTemplateBase<::dregx::ast::node::STAR> STAR();
AccessTemplateBase<::dregx::ast::node::OPTIONAL> OPTIONAL();
AccessTemplateBase<::dregx::ast::node::OTHER> OTHER();


		template<typename FunctionType>
		AccessTemplateBase<::dregx::ast::node::capture_symbols>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::dregx::ast::node::capture_whitespace> : public AccessBase
	{
	protected:
		std::vector<const ::dregx::ast::node::capture_whitespace*> ts;

	public:
		AccessTemplateBase(std::vector<const ::dregx::ast::node::capture_whitespace*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::capture_whitespace& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::capture_whitespace* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::dregx::ast::node::capture_whitespace>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::dregx::ast::node::capture_whitespace>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::dregx::ast::node::capture_whitespace*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::dregx::ast::node::capture_whitespace*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::dregx::ast::node::SPACE> SPACE();
AccessTemplateBase<::dregx::ast::node::TAB> TAB();


		template<typename FunctionType>
		AccessTemplateBase<::dregx::ast::node::capture_whitespace>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::dregx::ast::node::capture_range> : public AccessBase
	{
	protected:
		std::vector<const ::dregx::ast::node::capture_range*> ts;

	public:
		AccessTemplateBase(std::vector<const ::dregx::ast::node::capture_range*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::capture_range& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::capture_range* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::dregx::ast::node::capture_range>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::dregx::ast::node::capture_range>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::dregx::ast::node::capture_range*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::dregx::ast::node::capture_range*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::dregx::ast::node::capture_letter_range> capture_letter_range();
AccessTemplateBase<::dregx::ast::node::capture_number_range> capture_number_range();


		template<typename FunctionType>
		AccessTemplateBase<::dregx::ast::node::capture_range>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::dregx::ast::node::capture_letter_range> : public AccessBase
	{
	protected:
		std::vector<const ::dregx::ast::node::capture_letter_range*> ts;

	public:
		AccessTemplateBase(std::vector<const ::dregx::ast::node::capture_letter_range*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::capture_letter_range& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::capture_letter_range* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::dregx::ast::node::capture_letter_range>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::dregx::ast::node::capture_letter_range>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::dregx::ast::node::capture_letter_range*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::dregx::ast::node::capture_letter_range*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::dregx::ast::node::any_letter_exclude_underscore> any_letter_exclude_underscore();
AccessTemplateBase<::dregx::ast::node::MIN> MIN();


		template<typename FunctionType>
		AccessTemplateBase<::dregx::ast::node::capture_letter_range>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::dregx::ast::node::capture_number_range> : public AccessBase
	{
	protected:
		std::vector<const ::dregx::ast::node::capture_number_range*> ts;

	public:
		AccessTemplateBase(std::vector<const ::dregx::ast::node::capture_number_range*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::capture_number_range& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::capture_number_range* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::dregx::ast::node::capture_number_range>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::dregx::ast::node::capture_number_range>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::dregx::ast::node::capture_number_range*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::dregx::ast::node::capture_number_range*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::dregx::ast::node::MIN> MIN();
AccessTemplateBase<::dregx::ast::node::NUMBER> NUMBER();


		template<typename FunctionType>
		AccessTemplateBase<::dregx::ast::node::capture_number_range>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::dregx::ast::node::capture_number> : public AccessBase
	{
	protected:
		std::vector<const ::dregx::ast::node::capture_number*> ts;

	public:
		AccessTemplateBase(std::vector<const ::dregx::ast::node::capture_number*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::capture_number& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::capture_number* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::dregx::ast::node::capture_number>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::dregx::ast::node::capture_number>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::dregx::ast::node::capture_number*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::dregx::ast::node::capture_number*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::dregx::ast::node::any_number> any_number();


		template<typename FunctionType>
		AccessTemplateBase<::dregx::ast::node::capture_number>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::dregx::ast::node::capture_letter> : public AccessBase
	{
	protected:
		std::vector<const ::dregx::ast::node::capture_letter*> ts;

	public:
		AccessTemplateBase(std::vector<const ::dregx::ast::node::capture_letter*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::capture_letter& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::capture_letter* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::dregx::ast::node::capture_letter>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::dregx::ast::node::capture_letter>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::dregx::ast::node::capture_letter*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::dregx::ast::node::capture_letter*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::dregx::ast::node::any_letter> any_letter();


		template<typename FunctionType>
		AccessTemplateBase<::dregx::ast::node::capture_letter>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::dregx::ast::node::capture_special_character> : public AccessBase
	{
	protected:
		std::vector<const ::dregx::ast::node::capture_special_character*> ts;

	public:
		AccessTemplateBase(std::vector<const ::dregx::ast::node::capture_special_character*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::capture_special_character& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::capture_special_character* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::dregx::ast::node::capture_special_character>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::dregx::ast::node::capture_special_character>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::dregx::ast::node::capture_special_character*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::dregx::ast::node::capture_special_character*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::dregx::ast::node::special_char_any> special_char_any();


		template<typename FunctionType>
		AccessTemplateBase<::dregx::ast::node::capture_special_character>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::dregx::ast::node::extension_modifier> : public AccessBase
	{
	protected:
		std::vector<const ::dregx::ast::node::extension_modifier*> ts;

	public:
		AccessTemplateBase(std::vector<const ::dregx::ast::node::extension_modifier*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::extension_modifier& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::extension_modifier* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::dregx::ast::node::extension_modifier>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::dregx::ast::node::extension_modifier>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::dregx::ast::node::extension_modifier*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::dregx::ast::node::extension_modifier*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::dregx::ast::node::min_repition> min_repition();
AccessTemplateBase<::dregx::ast::node::max_repition> max_repition();
AccessTemplateBase<::dregx::ast::node::opt_pad> opt_pad();
AccessTemplateBase<::dregx::ast::node::LEFT_BRACKET> LEFT_BRACKET();
AccessTemplateBase<::dregx::ast::node::RIGHT_BRACKET> RIGHT_BRACKET();
AccessTemplateBase<::dregx::ast::node::COMMA> COMMA();


		template<typename FunctionType>
		AccessTemplateBase<::dregx::ast::node::extension_modifier>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::dregx::ast::node::min_repition> : public AccessBase
	{
	protected:
		std::vector<const ::dregx::ast::node::min_repition*> ts;

	public:
		AccessTemplateBase(std::vector<const ::dregx::ast::node::min_repition*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::min_repition& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::min_repition* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::dregx::ast::node::min_repition>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::dregx::ast::node::min_repition>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::dregx::ast::node::min_repition*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::dregx::ast::node::min_repition*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::dregx::ast::node::deamerreserved_plus__NUMBER__> deamerreserved_plus__NUMBER__();
AccessTemplateBase<::dregx::ast::node::opt_pad> opt_pad();
AccessTemplateBase<::dregx::ast::node::NUMBER> NUMBER();


		template<typename FunctionType>
		AccessTemplateBase<::dregx::ast::node::min_repition>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::dregx::ast::node::deamerreserved_plus__NUMBER__> : public AccessBase
	{
	protected:
		std::vector<const ::dregx::ast::node::deamerreserved_plus__NUMBER__*> ts;

	public:
		AccessTemplateBase(std::vector<const ::dregx::ast::node::deamerreserved_plus__NUMBER__*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::deamerreserved_plus__NUMBER__& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::deamerreserved_plus__NUMBER__* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::dregx::ast::node::deamerreserved_plus__NUMBER__>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::dregx::ast::node::deamerreserved_plus__NUMBER__>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::dregx::ast::node::deamerreserved_plus__NUMBER__*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::dregx::ast::node::deamerreserved_plus__NUMBER__*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::dregx::ast::node::deamerreserved_plus__NUMBER__> deamerreserved_plus__NUMBER__();
AccessTemplateBase<::dregx::ast::node::NUMBER> NUMBER();


		template<typename FunctionType>
		AccessTemplateBase<::dregx::ast::node::deamerreserved_plus__NUMBER__>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::dregx::ast::node::max_repition> : public AccessBase
	{
	protected:
		std::vector<const ::dregx::ast::node::max_repition*> ts;

	public:
		AccessTemplateBase(std::vector<const ::dregx::ast::node::max_repition*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::max_repition& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::max_repition* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::dregx::ast::node::max_repition>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::dregx::ast::node::max_repition>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::dregx::ast::node::max_repition*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::dregx::ast::node::max_repition*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::dregx::ast::node::deamerreserved_plus__NUMBER__> deamerreserved_plus__NUMBER__();
AccessTemplateBase<::dregx::ast::node::opt_pad> opt_pad();
AccessTemplateBase<::dregx::ast::node::NUMBER> NUMBER();


		template<typename FunctionType>
		AccessTemplateBase<::dregx::ast::node::max_repition>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::dregx::ast::node::standalone> : public AccessBase
	{
	protected:
		std::vector<const ::dregx::ast::node::standalone*> ts;

	public:
		AccessTemplateBase(std::vector<const ::dregx::ast::node::standalone*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::standalone& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::standalone* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::dregx::ast::node::standalone>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::dregx::ast::node::standalone>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::dregx::ast::node::standalone*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::dregx::ast::node::standalone*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::dregx::ast::node::opt_pad> opt_pad();
AccessTemplateBase<::dregx::ast::node::any_number> any_number();
AccessTemplateBase<::dregx::ast::node::any_letter> any_letter();


		template<typename FunctionType>
		AccessTemplateBase<::dregx::ast::node::standalone>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::dregx::ast::node::opt_pad> : public AccessBase
	{
	protected:
		std::vector<const ::dregx::ast::node::opt_pad*> ts;

	public:
		AccessTemplateBase(std::vector<const ::dregx::ast::node::opt_pad*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::opt_pad& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::opt_pad* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::dregx::ast::node::opt_pad>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::dregx::ast::node::opt_pad>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::dregx::ast::node::opt_pad*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::dregx::ast::node::opt_pad*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::dregx::ast::node::optional_padding> optional_padding();


		template<typename FunctionType>
		AccessTemplateBase<::dregx::ast::node::opt_pad>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::dregx::ast::node::optional_padding> : public AccessBase
	{
	protected:
		std::vector<const ::dregx::ast::node::optional_padding*> ts;

	public:
		AccessTemplateBase(std::vector<const ::dregx::ast::node::optional_padding*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::optional_padding& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::optional_padding* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::dregx::ast::node::optional_padding>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::dregx::ast::node::optional_padding>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::dregx::ast::node::optional_padding*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::dregx::ast::node::optional_padding*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::dregx::ast::node::deamerreserved_star__padding__> deamerreserved_star__padding__();
AccessTemplateBase<::dregx::ast::node::padding> padding();


		template<typename FunctionType>
		AccessTemplateBase<::dregx::ast::node::optional_padding>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::dregx::ast::node::deamerreserved_star__padding__> : public AccessBase
	{
	protected:
		std::vector<const ::dregx::ast::node::deamerreserved_star__padding__*> ts;

	public:
		AccessTemplateBase(std::vector<const ::dregx::ast::node::deamerreserved_star__padding__*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::deamerreserved_star__padding__& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::deamerreserved_star__padding__* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::dregx::ast::node::deamerreserved_star__padding__>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::dregx::ast::node::deamerreserved_star__padding__>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::dregx::ast::node::deamerreserved_star__padding__*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::dregx::ast::node::deamerreserved_star__padding__*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::dregx::ast::node::deamerreserved_star__padding__> deamerreserved_star__padding__();
AccessTemplateBase<::dregx::ast::node::padding> padding();


		template<typename FunctionType>
		AccessTemplateBase<::dregx::ast::node::deamerreserved_star__padding__>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::dregx::ast::node::padding> : public AccessBase
	{
	protected:
		std::vector<const ::dregx::ast::node::padding*> ts;

	public:
		AccessTemplateBase(std::vector<const ::dregx::ast::node::padding*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::padding& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::padding* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::dregx::ast::node::padding>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::dregx::ast::node::padding>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::dregx::ast::node::padding*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::dregx::ast::node::padding*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::dregx::ast::node::SPACE> SPACE();
AccessTemplateBase<::dregx::ast::node::TAB> TAB();


		template<typename FunctionType>
		AccessTemplateBase<::dregx::ast::node::padding>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::dregx::ast::node::special_char_any> : public AccessBase
	{
	protected:
		std::vector<const ::dregx::ast::node::special_char_any*> ts;

	public:
		AccessTemplateBase(std::vector<const ::dregx::ast::node::special_char_any*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::special_char_any& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::special_char_any* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::dregx::ast::node::special_char_any>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::dregx::ast::node::special_char_any>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::dregx::ast::node::special_char_any*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::dregx::ast::node::special_char_any*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::dregx::ast::node::any> any();
AccessTemplateBase<::dregx::ast::node::SLASH> SLASH();


		template<typename FunctionType>
		AccessTemplateBase<::dregx::ast::node::special_char_any>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::dregx::ast::node::any_number> : public AccessBase
	{
	protected:
		std::vector<const ::dregx::ast::node::any_number*> ts;

	public:
		AccessTemplateBase(std::vector<const ::dregx::ast::node::any_number*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::any_number& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::any_number* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::dregx::ast::node::any_number>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::dregx::ast::node::any_number>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::dregx::ast::node::any_number*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::dregx::ast::node::any_number*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::dregx::ast::node::NUMBER> NUMBER();


		template<typename FunctionType>
		AccessTemplateBase<::dregx::ast::node::any_number>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::dregx::ast::node::any_letter> : public AccessBase
	{
	protected:
		std::vector<const ::dregx::ast::node::any_letter*> ts;

	public:
		AccessTemplateBase(std::vector<const ::dregx::ast::node::any_letter*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::any_letter& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::any_letter* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::dregx::ast::node::any_letter>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::dregx::ast::node::any_letter>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::dregx::ast::node::any_letter*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::dregx::ast::node::any_letter*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::dregx::ast::node::any_letter_exclude_underscore> any_letter_exclude_underscore();
AccessTemplateBase<::dregx::ast::node::UNDERSCORE> UNDERSCORE();


		template<typename FunctionType>
		AccessTemplateBase<::dregx::ast::node::any_letter>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::dregx::ast::node::any_letter_exclude_underscore> : public AccessBase
	{
	protected:
		std::vector<const ::dregx::ast::node::any_letter_exclude_underscore*> ts;

	public:
		AccessTemplateBase(std::vector<const ::dregx::ast::node::any_letter_exclude_underscore*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::any_letter_exclude_underscore& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::any_letter_exclude_underscore* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::dregx::ast::node::any_letter_exclude_underscore>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::dregx::ast::node::any_letter_exclude_underscore>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::dregx::ast::node::any_letter_exclude_underscore*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::dregx::ast::node::any_letter_exclude_underscore*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::dregx::ast::node::T_> T_();
AccessTemplateBase<::dregx::ast::node::N_> N_();
AccessTemplateBase<::dregx::ast::node::R_> R_();
AccessTemplateBase<::dregx::ast::node::B_> B_();
AccessTemplateBase<::dregx::ast::node::V_> V_();
AccessTemplateBase<::dregx::ast::node::A_> A_();
AccessTemplateBase<::dregx::ast::node::LETTER> LETTER();


		template<typename FunctionType>
		AccessTemplateBase<::dregx::ast::node::any_letter_exclude_underscore>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::dregx::ast::node::any> : public AccessBase
	{
	protected:
		std::vector<const ::dregx::ast::node::any*> ts;

	public:
		AccessTemplateBase(std::vector<const ::dregx::ast::node::any*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::any& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::any* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::dregx::ast::node::any>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::dregx::ast::node::any>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::dregx::ast::node::any*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::dregx::ast::node::any*> GetContent()
		{
			return ts;
		}

	public:
		AccessTemplateBase<::dregx::ast::node::LEFT_CURLY_BRACKET> LEFT_CURLY_BRACKET();
AccessTemplateBase<::dregx::ast::node::RIGHT_CURLY_BRACKET> RIGHT_CURLY_BRACKET();
AccessTemplateBase<::dregx::ast::node::LEFT_SQUARE_BRACKET> LEFT_SQUARE_BRACKET();
AccessTemplateBase<::dregx::ast::node::RIGHT_SQUARE_BRACKET> RIGHT_SQUARE_BRACKET();
AccessTemplateBase<::dregx::ast::node::LEFT_BRACKET> LEFT_BRACKET();
AccessTemplateBase<::dregx::ast::node::RIGHT_BRACKET> RIGHT_BRACKET();
AccessTemplateBase<::dregx::ast::node::COMMA> COMMA();
AccessTemplateBase<::dregx::ast::node::SLASH> SLASH();
AccessTemplateBase<::dregx::ast::node::OR> OR();
AccessTemplateBase<::dregx::ast::node::MIN> MIN();
AccessTemplateBase<::dregx::ast::node::UNDERSCORE> UNDERSCORE();
AccessTemplateBase<::dregx::ast::node::NOT> NOT();
AccessTemplateBase<::dregx::ast::node::PLUS> PLUS();
AccessTemplateBase<::dregx::ast::node::STAR> STAR();
AccessTemplateBase<::dregx::ast::node::OPTIONAL> OPTIONAL();
AccessTemplateBase<::dregx::ast::node::NUMBER> NUMBER();
AccessTemplateBase<::dregx::ast::node::T_> T_();
AccessTemplateBase<::dregx::ast::node::N_> N_();
AccessTemplateBase<::dregx::ast::node::R_> R_();
AccessTemplateBase<::dregx::ast::node::B_> B_();
AccessTemplateBase<::dregx::ast::node::V_> V_();
AccessTemplateBase<::dregx::ast::node::A_> A_();
AccessTemplateBase<::dregx::ast::node::LETTER> LETTER();
AccessTemplateBase<::dregx::ast::node::SPACE> SPACE();
AccessTemplateBase<::dregx::ast::node::TAB> TAB();
AccessTemplateBase<::dregx::ast::node::OTHER> OTHER();


		template<typename FunctionType>
		AccessTemplateBase<::dregx::ast::node::any>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::dregx::ast::node::LEFT_CURLY_BRACKET> : public AccessBase
	{
	protected:
		std::vector<const ::dregx::ast::node::LEFT_CURLY_BRACKET*> ts;

	public:
		AccessTemplateBase(std::vector<const ::dregx::ast::node::LEFT_CURLY_BRACKET*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::LEFT_CURLY_BRACKET& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::LEFT_CURLY_BRACKET* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::dregx::ast::node::LEFT_CURLY_BRACKET>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::dregx::ast::node::LEFT_CURLY_BRACKET>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::dregx::ast::node::LEFT_CURLY_BRACKET*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::dregx::ast::node::LEFT_CURLY_BRACKET*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::dregx::ast::node::LEFT_CURLY_BRACKET>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::dregx::ast::node::RIGHT_CURLY_BRACKET> : public AccessBase
	{
	protected:
		std::vector<const ::dregx::ast::node::RIGHT_CURLY_BRACKET*> ts;

	public:
		AccessTemplateBase(std::vector<const ::dregx::ast::node::RIGHT_CURLY_BRACKET*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::RIGHT_CURLY_BRACKET& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::RIGHT_CURLY_BRACKET* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::dregx::ast::node::RIGHT_CURLY_BRACKET>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::dregx::ast::node::RIGHT_CURLY_BRACKET>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::dregx::ast::node::RIGHT_CURLY_BRACKET*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::dregx::ast::node::RIGHT_CURLY_BRACKET*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::dregx::ast::node::RIGHT_CURLY_BRACKET>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::dregx::ast::node::LEFT_SQUARE_BRACKET_NOT> : public AccessBase
	{
	protected:
		std::vector<const ::dregx::ast::node::LEFT_SQUARE_BRACKET_NOT*> ts;

	public:
		AccessTemplateBase(std::vector<const ::dregx::ast::node::LEFT_SQUARE_BRACKET_NOT*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::LEFT_SQUARE_BRACKET_NOT& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::LEFT_SQUARE_BRACKET_NOT* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::dregx::ast::node::LEFT_SQUARE_BRACKET_NOT>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::dregx::ast::node::LEFT_SQUARE_BRACKET_NOT>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::dregx::ast::node::LEFT_SQUARE_BRACKET_NOT*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::dregx::ast::node::LEFT_SQUARE_BRACKET_NOT*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::dregx::ast::node::LEFT_SQUARE_BRACKET_NOT>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::dregx::ast::node::LEFT_SQUARE_BRACKET> : public AccessBase
	{
	protected:
		std::vector<const ::dregx::ast::node::LEFT_SQUARE_BRACKET*> ts;

	public:
		AccessTemplateBase(std::vector<const ::dregx::ast::node::LEFT_SQUARE_BRACKET*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::LEFT_SQUARE_BRACKET& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::LEFT_SQUARE_BRACKET* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::dregx::ast::node::LEFT_SQUARE_BRACKET>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::dregx::ast::node::LEFT_SQUARE_BRACKET>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::dregx::ast::node::LEFT_SQUARE_BRACKET*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::dregx::ast::node::LEFT_SQUARE_BRACKET*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::dregx::ast::node::LEFT_SQUARE_BRACKET>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::dregx::ast::node::RIGHT_SQUARE_BRACKET> : public AccessBase
	{
	protected:
		std::vector<const ::dregx::ast::node::RIGHT_SQUARE_BRACKET*> ts;

	public:
		AccessTemplateBase(std::vector<const ::dregx::ast::node::RIGHT_SQUARE_BRACKET*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::RIGHT_SQUARE_BRACKET& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::RIGHT_SQUARE_BRACKET* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::dregx::ast::node::RIGHT_SQUARE_BRACKET>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::dregx::ast::node::RIGHT_SQUARE_BRACKET>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::dregx::ast::node::RIGHT_SQUARE_BRACKET*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::dregx::ast::node::RIGHT_SQUARE_BRACKET*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::dregx::ast::node::RIGHT_SQUARE_BRACKET>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::dregx::ast::node::LEFT_BRACKET> : public AccessBase
	{
	protected:
		std::vector<const ::dregx::ast::node::LEFT_BRACKET*> ts;

	public:
		AccessTemplateBase(std::vector<const ::dregx::ast::node::LEFT_BRACKET*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::LEFT_BRACKET& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::LEFT_BRACKET* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::dregx::ast::node::LEFT_BRACKET>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::dregx::ast::node::LEFT_BRACKET>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::dregx::ast::node::LEFT_BRACKET*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::dregx::ast::node::LEFT_BRACKET*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::dregx::ast::node::LEFT_BRACKET>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::dregx::ast::node::RIGHT_BRACKET> : public AccessBase
	{
	protected:
		std::vector<const ::dregx::ast::node::RIGHT_BRACKET*> ts;

	public:
		AccessTemplateBase(std::vector<const ::dregx::ast::node::RIGHT_BRACKET*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::RIGHT_BRACKET& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::RIGHT_BRACKET* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::dregx::ast::node::RIGHT_BRACKET>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::dregx::ast::node::RIGHT_BRACKET>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::dregx::ast::node::RIGHT_BRACKET*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::dregx::ast::node::RIGHT_BRACKET*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::dregx::ast::node::RIGHT_BRACKET>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::dregx::ast::node::COMMA> : public AccessBase
	{
	protected:
		std::vector<const ::dregx::ast::node::COMMA*> ts;

	public:
		AccessTemplateBase(std::vector<const ::dregx::ast::node::COMMA*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::COMMA& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::COMMA* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::dregx::ast::node::COMMA>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::dregx::ast::node::COMMA>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::dregx::ast::node::COMMA*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::dregx::ast::node::COMMA*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::dregx::ast::node::COMMA>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::dregx::ast::node::SLASH> : public AccessBase
	{
	protected:
		std::vector<const ::dregx::ast::node::SLASH*> ts;

	public:
		AccessTemplateBase(std::vector<const ::dregx::ast::node::SLASH*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::SLASH& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::SLASH* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::dregx::ast::node::SLASH>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::dregx::ast::node::SLASH>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::dregx::ast::node::SLASH*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::dregx::ast::node::SLASH*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::dregx::ast::node::SLASH>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::dregx::ast::node::OR> : public AccessBase
	{
	protected:
		std::vector<const ::dregx::ast::node::OR*> ts;

	public:
		AccessTemplateBase(std::vector<const ::dregx::ast::node::OR*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::OR& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::OR* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::dregx::ast::node::OR>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::dregx::ast::node::OR>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::dregx::ast::node::OR*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::dregx::ast::node::OR*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::dregx::ast::node::OR>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::dregx::ast::node::MIN> : public AccessBase
	{
	protected:
		std::vector<const ::dregx::ast::node::MIN*> ts;

	public:
		AccessTemplateBase(std::vector<const ::dregx::ast::node::MIN*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::MIN& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::MIN* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::dregx::ast::node::MIN>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::dregx::ast::node::MIN>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::dregx::ast::node::MIN*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::dregx::ast::node::MIN*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::dregx::ast::node::MIN>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::dregx::ast::node::UNDERSCORE> : public AccessBase
	{
	protected:
		std::vector<const ::dregx::ast::node::UNDERSCORE*> ts;

	public:
		AccessTemplateBase(std::vector<const ::dregx::ast::node::UNDERSCORE*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::UNDERSCORE& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::UNDERSCORE* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::dregx::ast::node::UNDERSCORE>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::dregx::ast::node::UNDERSCORE>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::dregx::ast::node::UNDERSCORE*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::dregx::ast::node::UNDERSCORE*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::dregx::ast::node::UNDERSCORE>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::dregx::ast::node::NOT> : public AccessBase
	{
	protected:
		std::vector<const ::dregx::ast::node::NOT*> ts;

	public:
		AccessTemplateBase(std::vector<const ::dregx::ast::node::NOT*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::NOT& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::NOT* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::dregx::ast::node::NOT>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::dregx::ast::node::NOT>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::dregx::ast::node::NOT*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::dregx::ast::node::NOT*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::dregx::ast::node::NOT>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::dregx::ast::node::PLUS> : public AccessBase
	{
	protected:
		std::vector<const ::dregx::ast::node::PLUS*> ts;

	public:
		AccessTemplateBase(std::vector<const ::dregx::ast::node::PLUS*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::PLUS& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::PLUS* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::dregx::ast::node::PLUS>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::dregx::ast::node::PLUS>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::dregx::ast::node::PLUS*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::dregx::ast::node::PLUS*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::dregx::ast::node::PLUS>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::dregx::ast::node::STAR> : public AccessBase
	{
	protected:
		std::vector<const ::dregx::ast::node::STAR*> ts;

	public:
		AccessTemplateBase(std::vector<const ::dregx::ast::node::STAR*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::STAR& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::STAR* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::dregx::ast::node::STAR>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::dregx::ast::node::STAR>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::dregx::ast::node::STAR*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::dregx::ast::node::STAR*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::dregx::ast::node::STAR>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::dregx::ast::node::OPTIONAL> : public AccessBase
	{
	protected:
		std::vector<const ::dregx::ast::node::OPTIONAL*> ts;

	public:
		AccessTemplateBase(std::vector<const ::dregx::ast::node::OPTIONAL*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::OPTIONAL& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::OPTIONAL* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::dregx::ast::node::OPTIONAL>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::dregx::ast::node::OPTIONAL>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::dregx::ast::node::OPTIONAL*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::dregx::ast::node::OPTIONAL*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::dregx::ast::node::OPTIONAL>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::dregx::ast::node::NUMBER> : public AccessBase
	{
	protected:
		std::vector<const ::dregx::ast::node::NUMBER*> ts;

	public:
		AccessTemplateBase(std::vector<const ::dregx::ast::node::NUMBER*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::NUMBER& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::NUMBER* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::dregx::ast::node::NUMBER>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::dregx::ast::node::NUMBER>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::dregx::ast::node::NUMBER*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::dregx::ast::node::NUMBER*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::dregx::ast::node::NUMBER>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::dregx::ast::node::T_> : public AccessBase
	{
	protected:
		std::vector<const ::dregx::ast::node::T_*> ts;

	public:
		AccessTemplateBase(std::vector<const ::dregx::ast::node::T_*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::T_& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::T_* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::dregx::ast::node::T_>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::dregx::ast::node::T_>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::dregx::ast::node::T_*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::dregx::ast::node::T_*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::dregx::ast::node::T_>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::dregx::ast::node::N_> : public AccessBase
	{
	protected:
		std::vector<const ::dregx::ast::node::N_*> ts;

	public:
		AccessTemplateBase(std::vector<const ::dregx::ast::node::N_*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::N_& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::N_* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::dregx::ast::node::N_>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::dregx::ast::node::N_>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::dregx::ast::node::N_*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::dregx::ast::node::N_*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::dregx::ast::node::N_>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::dregx::ast::node::R_> : public AccessBase
	{
	protected:
		std::vector<const ::dregx::ast::node::R_*> ts;

	public:
		AccessTemplateBase(std::vector<const ::dregx::ast::node::R_*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::R_& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::R_* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::dregx::ast::node::R_>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::dregx::ast::node::R_>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::dregx::ast::node::R_*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::dregx::ast::node::R_*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::dregx::ast::node::R_>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::dregx::ast::node::B_> : public AccessBase
	{
	protected:
		std::vector<const ::dregx::ast::node::B_*> ts;

	public:
		AccessTemplateBase(std::vector<const ::dregx::ast::node::B_*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::B_& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::B_* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::dregx::ast::node::B_>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::dregx::ast::node::B_>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::dregx::ast::node::B_*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::dregx::ast::node::B_*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::dregx::ast::node::B_>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::dregx::ast::node::V_> : public AccessBase
	{
	protected:
		std::vector<const ::dregx::ast::node::V_*> ts;

	public:
		AccessTemplateBase(std::vector<const ::dregx::ast::node::V_*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::V_& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::V_* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::dregx::ast::node::V_>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::dregx::ast::node::V_>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::dregx::ast::node::V_*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::dregx::ast::node::V_*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::dregx::ast::node::V_>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::dregx::ast::node::A_> : public AccessBase
	{
	protected:
		std::vector<const ::dregx::ast::node::A_*> ts;

	public:
		AccessTemplateBase(std::vector<const ::dregx::ast::node::A_*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::A_& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::A_* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::dregx::ast::node::A_>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::dregx::ast::node::A_>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::dregx::ast::node::A_*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::dregx::ast::node::A_*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::dregx::ast::node::A_>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::dregx::ast::node::LETTER> : public AccessBase
	{
	protected:
		std::vector<const ::dregx::ast::node::LETTER*> ts;

	public:
		AccessTemplateBase(std::vector<const ::dregx::ast::node::LETTER*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::LETTER& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::LETTER* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::dregx::ast::node::LETTER>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::dregx::ast::node::LETTER>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::dregx::ast::node::LETTER*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::dregx::ast::node::LETTER*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::dregx::ast::node::LETTER>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::dregx::ast::node::SPACE> : public AccessBase
	{
	protected:
		std::vector<const ::dregx::ast::node::SPACE*> ts;

	public:
		AccessTemplateBase(std::vector<const ::dregx::ast::node::SPACE*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::SPACE& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::SPACE* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::dregx::ast::node::SPACE>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::dregx::ast::node::SPACE>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::dregx::ast::node::SPACE*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::dregx::ast::node::SPACE*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::dregx::ast::node::SPACE>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::dregx::ast::node::TAB> : public AccessBase
	{
	protected:
		std::vector<const ::dregx::ast::node::TAB*> ts;

	public:
		AccessTemplateBase(std::vector<const ::dregx::ast::node::TAB*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::TAB& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::TAB* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::dregx::ast::node::TAB>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::dregx::ast::node::TAB>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::dregx::ast::node::TAB*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::dregx::ast::node::TAB*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::dregx::ast::node::TAB>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::dregx::ast::node::OTHER> : public AccessBase
	{
	protected:
		std::vector<const ::dregx::ast::node::OTHER*> ts;

	public:
		AccessTemplateBase(std::vector<const ::dregx::ast::node::OTHER*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::OTHER& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::OTHER* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::dregx::ast::node::OTHER>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::dregx::ast::node::OTHER>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::dregx::ast::node::OTHER*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::dregx::ast::node::OTHER*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::dregx::ast::node::OTHER>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};

	template<>
	struct AccessTemplateBase<::dregx::ast::node::DELETE_ESCAPE_CHARS> : public AccessBase
	{
	protected:
		std::vector<const ::dregx::ast::node::DELETE_ESCAPE_CHARS*> ts;

	public:
		AccessTemplateBase(std::vector<const ::dregx::ast::node::DELETE_ESCAPE_CHARS*> ts_) : ts(std::move(ts_))
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::DELETE_ESCAPE_CHARS& t) : ts({&t})
		{
		}

		AccessTemplateBase(const ::dregx::ast::node::DELETE_ESCAPE_CHARS* t) : ts({t})
		{
		}

		AccessTemplateBase() = default;

	public:
		AccessTemplateBase<::dregx::ast::node::DELETE_ESCAPE_CHARS>& operator[](::std::size_t index)
		{
			if (index >= ts.size())
			{
				ts.clear();
			}
			else
			{
				const auto* const copy = ts[index];
				ts.clear();
				ts.push_back(copy);
			}

			return *this;
		}

		AccessTemplateBase<::dregx::ast::node::DELETE_ESCAPE_CHARS>& operator()(::std::size_t indexBegin, ::std::size_t indexEnd)
		{
			// swap if the other is larger
			if (indexBegin > indexEnd)
			{
				const auto tmp = indexBegin;
				indexBegin = indexEnd;
				indexEnd = tmp;
			}

			if (indexBegin >= ts.size())
			{
				ts.clear();
			}
			else
			{
				std::vector<const ::dregx::ast::node::DELETE_ESCAPE_CHARS*> temporaries;
				for (auto i = indexBegin; i < ts.size() && i <= indexEnd; i++)
				{
					temporaries.push_back(ts[i]);
				}
				ts.clear();
				ts = temporaries;
			}

			return *this;
		}

		std::vector<const ::dregx::ast::node::DELETE_ESCAPE_CHARS*> GetContent()
		{
			return ts;
		}

	public:
		

		template<typename FunctionType>
		AccessTemplateBase<::dregx::ast::node::DELETE_ESCAPE_CHARS>& for_all(FunctionType function)
		{
			for (const auto* const t : ts)
			{
				function(t);
			}

			return *this;
		}

	public:
		auto begin()
		{
			return ts.begin();
		}
		auto cbegin()
		{
			return ts.cbegin();
		}
		
		auto end()
		{
			return ts.end();
		}
		
		auto cend()
		{
			return ts.cend();
		}
	};


	
		inline AccessTemplateBase<::dregx::ast::node::deamerreserved_star__stmt__> AccessTemplateBase<::dregx::ast::node::program>::deamerreserved_star__stmt__()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::deamerreserved_star__stmt__>(Get<::dregx::ast::Type::deamerreserved_star__stmt__>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::stmt> AccessTemplateBase<::dregx::ast::node::program>::stmt()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::stmt>(Get<::dregx::ast::Type::stmt>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::opt_pad> AccessTemplateBase<::dregx::ast::node::program>::opt_pad()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::opt_pad>(Get<::dregx::ast::Type::opt_pad>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::deamerreserved_star__stmt__> AccessTemplateBase<::dregx::ast::node::deamerreserved_star__stmt__>::deamerreserved_star__stmt__()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::deamerreserved_star__stmt__>(Get<::dregx::ast::Type::deamerreserved_star__stmt__>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::stmt> AccessTemplateBase<::dregx::ast::node::deamerreserved_star__stmt__>::stmt()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::stmt>(Get<::dregx::ast::Type::stmt>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::word> AccessTemplateBase<::dregx::ast::node::stmt>::word()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::word>(Get<::dregx::ast::Type::word>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::group> AccessTemplateBase<::dregx::ast::node::word>::group()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::group>(Get<::dregx::ast::Type::group>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::square> AccessTemplateBase<::dregx::ast::node::word>::square()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::square>(Get<::dregx::ast::Type::square>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::standalone> AccessTemplateBase<::dregx::ast::node::word>::standalone()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::standalone>(Get<::dregx::ast::Type::standalone>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::word> AccessTemplateBase<::dregx::ast::node::group>::word()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::word>(Get<::dregx::ast::Type::word>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::deamerreserved_plus__word__> AccessTemplateBase<::dregx::ast::node::group>::deamerreserved_plus__word__()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::deamerreserved_plus__word__>(Get<::dregx::ast::Type::deamerreserved_plus__word__>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::or_concat> AccessTemplateBase<::dregx::ast::node::group>::or_concat()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::or_concat>(Get<::dregx::ast::Type::or_concat>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::extension_modifier> AccessTemplateBase<::dregx::ast::node::group>::extension_modifier()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::extension_modifier>(Get<::dregx::ast::Type::extension_modifier>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::opt_pad> AccessTemplateBase<::dregx::ast::node::group>::opt_pad()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::opt_pad>(Get<::dregx::ast::Type::opt_pad>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::LEFT_CURLY_BRACKET> AccessTemplateBase<::dregx::ast::node::group>::LEFT_CURLY_BRACKET()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::LEFT_CURLY_BRACKET>(Get<::dregx::ast::Type::LEFT_CURLY_BRACKET>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::RIGHT_CURLY_BRACKET> AccessTemplateBase<::dregx::ast::node::group>::RIGHT_CURLY_BRACKET()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::RIGHT_CURLY_BRACKET>(Get<::dregx::ast::Type::RIGHT_CURLY_BRACKET>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::PLUS> AccessTemplateBase<::dregx::ast::node::group>::PLUS()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::PLUS>(Get<::dregx::ast::Type::PLUS>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::STAR> AccessTemplateBase<::dregx::ast::node::group>::STAR()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::STAR>(Get<::dregx::ast::Type::STAR>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::OPTIONAL> AccessTemplateBase<::dregx::ast::node::group>::OPTIONAL()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::OPTIONAL>(Get<::dregx::ast::Type::OPTIONAL>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::word> AccessTemplateBase<::dregx::ast::node::deamerreserved_plus__word__>::word()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::word>(Get<::dregx::ast::Type::word>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::deamerreserved_plus__word__> AccessTemplateBase<::dregx::ast::node::deamerreserved_plus__word__>::deamerreserved_plus__word__()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::deamerreserved_plus__word__>(Get<::dregx::ast::Type::deamerreserved_plus__word__>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::word> AccessTemplateBase<::dregx::ast::node::or_concat>::word()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::word>(Get<::dregx::ast::Type::word>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::deamerreserved_arrow__word__> AccessTemplateBase<::dregx::ast::node::or_concat>::deamerreserved_arrow__word__()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::deamerreserved_arrow__word__>(Get<::dregx::ast::Type::deamerreserved_arrow__word__>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::deamerreserved_star__opt_pad__OR__word__> AccessTemplateBase<::dregx::ast::node::or_concat>::deamerreserved_star__opt_pad__OR__word__()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::deamerreserved_star__opt_pad__OR__word__>(Get<::dregx::ast::Type::deamerreserved_star__opt_pad__OR__word__>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::opt_pad> AccessTemplateBase<::dregx::ast::node::or_concat>::opt_pad()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::opt_pad>(Get<::dregx::ast::Type::opt_pad>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::OR> AccessTemplateBase<::dregx::ast::node::or_concat>::OR()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::OR>(Get<::dregx::ast::Type::OR>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::word> AccessTemplateBase<::dregx::ast::node::deamerreserved_arrow__word__>::word()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::word>(Get<::dregx::ast::Type::word>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::deamerreserved_star__opt_pad__OR__word__> AccessTemplateBase<::dregx::ast::node::deamerreserved_arrow__word__>::deamerreserved_star__opt_pad__OR__word__()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::deamerreserved_star__opt_pad__OR__word__>(Get<::dregx::ast::Type::deamerreserved_star__opt_pad__OR__word__>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::opt_pad> AccessTemplateBase<::dregx::ast::node::deamerreserved_arrow__word__>::opt_pad()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::opt_pad>(Get<::dregx::ast::Type::opt_pad>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::OR> AccessTemplateBase<::dregx::ast::node::deamerreserved_arrow__word__>::OR()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::OR>(Get<::dregx::ast::Type::OR>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::word> AccessTemplateBase<::dregx::ast::node::deamerreserved_star__opt_pad__OR__word__>::word()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::word>(Get<::dregx::ast::Type::word>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::deamerreserved_star__opt_pad__OR__word__> AccessTemplateBase<::dregx::ast::node::deamerreserved_star__opt_pad__OR__word__>::deamerreserved_star__opt_pad__OR__word__()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::deamerreserved_star__opt_pad__OR__word__>(Get<::dregx::ast::Type::deamerreserved_star__opt_pad__OR__word__>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::opt_pad> AccessTemplateBase<::dregx::ast::node::deamerreserved_star__opt_pad__OR__word__>::opt_pad()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::opt_pad>(Get<::dregx::ast::Type::opt_pad>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::OR> AccessTemplateBase<::dregx::ast::node::deamerreserved_star__opt_pad__OR__word__>::OR()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::OR>(Get<::dregx::ast::Type::OR>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::capture> AccessTemplateBase<::dregx::ast::node::square>::capture()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::capture>(Get<::dregx::ast::Type::capture>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::extension_modifier> AccessTemplateBase<::dregx::ast::node::square>::extension_modifier()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::extension_modifier>(Get<::dregx::ast::Type::extension_modifier>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::PLUS> AccessTemplateBase<::dregx::ast::node::square>::PLUS()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::PLUS>(Get<::dregx::ast::Type::PLUS>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::STAR> AccessTemplateBase<::dregx::ast::node::square>::STAR()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::STAR>(Get<::dregx::ast::Type::STAR>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::OPTIONAL> AccessTemplateBase<::dregx::ast::node::square>::OPTIONAL()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::OPTIONAL>(Get<::dregx::ast::Type::OPTIONAL>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::deamerreserved_plus__capture_logic__> AccessTemplateBase<::dregx::ast::node::capture>::deamerreserved_plus__capture_logic__()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::deamerreserved_plus__capture_logic__>(Get<::dregx::ast::Type::deamerreserved_plus__capture_logic__>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::capture_logic> AccessTemplateBase<::dregx::ast::node::capture>::capture_logic()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::capture_logic>(Get<::dregx::ast::Type::capture_logic>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::opt_pad> AccessTemplateBase<::dregx::ast::node::capture>::opt_pad()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::opt_pad>(Get<::dregx::ast::Type::opt_pad>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::LEFT_SQUARE_BRACKET_NOT> AccessTemplateBase<::dregx::ast::node::capture>::LEFT_SQUARE_BRACKET_NOT()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::LEFT_SQUARE_BRACKET_NOT>(Get<::dregx::ast::Type::LEFT_SQUARE_BRACKET_NOT>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::LEFT_SQUARE_BRACKET> AccessTemplateBase<::dregx::ast::node::capture>::LEFT_SQUARE_BRACKET()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::LEFT_SQUARE_BRACKET>(Get<::dregx::ast::Type::LEFT_SQUARE_BRACKET>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::RIGHT_SQUARE_BRACKET> AccessTemplateBase<::dregx::ast::node::capture>::RIGHT_SQUARE_BRACKET()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::RIGHT_SQUARE_BRACKET>(Get<::dregx::ast::Type::RIGHT_SQUARE_BRACKET>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::deamerreserved_plus__capture_logic__> AccessTemplateBase<::dregx::ast::node::deamerreserved_plus__capture_logic__>::deamerreserved_plus__capture_logic__()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::deamerreserved_plus__capture_logic__>(Get<::dregx::ast::Type::deamerreserved_plus__capture_logic__>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::capture_logic> AccessTemplateBase<::dregx::ast::node::deamerreserved_plus__capture_logic__>::capture_logic()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::capture_logic>(Get<::dregx::ast::Type::capture_logic>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::capture_symbols> AccessTemplateBase<::dregx::ast::node::capture_logic>::capture_symbols()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::capture_symbols>(Get<::dregx::ast::Type::capture_symbols>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::capture_whitespace> AccessTemplateBase<::dregx::ast::node::capture_logic>::capture_whitespace()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::capture_whitespace>(Get<::dregx::ast::Type::capture_whitespace>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::capture_range> AccessTemplateBase<::dregx::ast::node::capture_logic>::capture_range()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::capture_range>(Get<::dregx::ast::Type::capture_range>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::capture_number> AccessTemplateBase<::dregx::ast::node::capture_logic>::capture_number()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::capture_number>(Get<::dregx::ast::Type::capture_number>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::capture_letter> AccessTemplateBase<::dregx::ast::node::capture_logic>::capture_letter()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::capture_letter>(Get<::dregx::ast::Type::capture_letter>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::capture_special_character> AccessTemplateBase<::dregx::ast::node::capture_logic>::capture_special_character()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::capture_special_character>(Get<::dregx::ast::Type::capture_special_character>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::COMMA> AccessTemplateBase<::dregx::ast::node::capture_symbols>::COMMA()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::COMMA>(Get<::dregx::ast::Type::COMMA>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::OR> AccessTemplateBase<::dregx::ast::node::capture_symbols>::OR()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::OR>(Get<::dregx::ast::Type::OR>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::PLUS> AccessTemplateBase<::dregx::ast::node::capture_symbols>::PLUS()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::PLUS>(Get<::dregx::ast::Type::PLUS>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::STAR> AccessTemplateBase<::dregx::ast::node::capture_symbols>::STAR()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::STAR>(Get<::dregx::ast::Type::STAR>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::OPTIONAL> AccessTemplateBase<::dregx::ast::node::capture_symbols>::OPTIONAL()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::OPTIONAL>(Get<::dregx::ast::Type::OPTIONAL>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::OTHER> AccessTemplateBase<::dregx::ast::node::capture_symbols>::OTHER()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::OTHER>(Get<::dregx::ast::Type::OTHER>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::SPACE> AccessTemplateBase<::dregx::ast::node::capture_whitespace>::SPACE()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::SPACE>(Get<::dregx::ast::Type::SPACE>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::TAB> AccessTemplateBase<::dregx::ast::node::capture_whitespace>::TAB()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::TAB>(Get<::dregx::ast::Type::TAB>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::capture_letter_range> AccessTemplateBase<::dregx::ast::node::capture_range>::capture_letter_range()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::capture_letter_range>(Get<::dregx::ast::Type::capture_letter_range>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::capture_number_range> AccessTemplateBase<::dregx::ast::node::capture_range>::capture_number_range()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::capture_number_range>(Get<::dregx::ast::Type::capture_number_range>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::any_letter_exclude_underscore> AccessTemplateBase<::dregx::ast::node::capture_letter_range>::any_letter_exclude_underscore()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::any_letter_exclude_underscore>(Get<::dregx::ast::Type::any_letter_exclude_underscore>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::MIN> AccessTemplateBase<::dregx::ast::node::capture_letter_range>::MIN()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::MIN>(Get<::dregx::ast::Type::MIN>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::MIN> AccessTemplateBase<::dregx::ast::node::capture_number_range>::MIN()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::MIN>(Get<::dregx::ast::Type::MIN>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::NUMBER> AccessTemplateBase<::dregx::ast::node::capture_number_range>::NUMBER()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::NUMBER>(Get<::dregx::ast::Type::NUMBER>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::any_number> AccessTemplateBase<::dregx::ast::node::capture_number>::any_number()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::any_number>(Get<::dregx::ast::Type::any_number>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::any_letter> AccessTemplateBase<::dregx::ast::node::capture_letter>::any_letter()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::any_letter>(Get<::dregx::ast::Type::any_letter>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::special_char_any> AccessTemplateBase<::dregx::ast::node::capture_special_character>::special_char_any()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::special_char_any>(Get<::dregx::ast::Type::special_char_any>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::min_repition> AccessTemplateBase<::dregx::ast::node::extension_modifier>::min_repition()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::min_repition>(Get<::dregx::ast::Type::min_repition>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::max_repition> AccessTemplateBase<::dregx::ast::node::extension_modifier>::max_repition()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::max_repition>(Get<::dregx::ast::Type::max_repition>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::opt_pad> AccessTemplateBase<::dregx::ast::node::extension_modifier>::opt_pad()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::opt_pad>(Get<::dregx::ast::Type::opt_pad>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::LEFT_BRACKET> AccessTemplateBase<::dregx::ast::node::extension_modifier>::LEFT_BRACKET()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::LEFT_BRACKET>(Get<::dregx::ast::Type::LEFT_BRACKET>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::RIGHT_BRACKET> AccessTemplateBase<::dregx::ast::node::extension_modifier>::RIGHT_BRACKET()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::RIGHT_BRACKET>(Get<::dregx::ast::Type::RIGHT_BRACKET>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::COMMA> AccessTemplateBase<::dregx::ast::node::extension_modifier>::COMMA()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::COMMA>(Get<::dregx::ast::Type::COMMA>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::deamerreserved_plus__NUMBER__> AccessTemplateBase<::dregx::ast::node::min_repition>::deamerreserved_plus__NUMBER__()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::deamerreserved_plus__NUMBER__>(Get<::dregx::ast::Type::deamerreserved_plus__NUMBER__>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::opt_pad> AccessTemplateBase<::dregx::ast::node::min_repition>::opt_pad()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::opt_pad>(Get<::dregx::ast::Type::opt_pad>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::NUMBER> AccessTemplateBase<::dregx::ast::node::min_repition>::NUMBER()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::NUMBER>(Get<::dregx::ast::Type::NUMBER>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::deamerreserved_plus__NUMBER__> AccessTemplateBase<::dregx::ast::node::deamerreserved_plus__NUMBER__>::deamerreserved_plus__NUMBER__()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::deamerreserved_plus__NUMBER__>(Get<::dregx::ast::Type::deamerreserved_plus__NUMBER__>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::NUMBER> AccessTemplateBase<::dregx::ast::node::deamerreserved_plus__NUMBER__>::NUMBER()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::NUMBER>(Get<::dregx::ast::Type::NUMBER>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::deamerreserved_plus__NUMBER__> AccessTemplateBase<::dregx::ast::node::max_repition>::deamerreserved_plus__NUMBER__()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::deamerreserved_plus__NUMBER__>(Get<::dregx::ast::Type::deamerreserved_plus__NUMBER__>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::opt_pad> AccessTemplateBase<::dregx::ast::node::max_repition>::opt_pad()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::opt_pad>(Get<::dregx::ast::Type::opt_pad>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::NUMBER> AccessTemplateBase<::dregx::ast::node::max_repition>::NUMBER()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::NUMBER>(Get<::dregx::ast::Type::NUMBER>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::opt_pad> AccessTemplateBase<::dregx::ast::node::standalone>::opt_pad()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::opt_pad>(Get<::dregx::ast::Type::opt_pad>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::any_number> AccessTemplateBase<::dregx::ast::node::standalone>::any_number()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::any_number>(Get<::dregx::ast::Type::any_number>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::any_letter> AccessTemplateBase<::dregx::ast::node::standalone>::any_letter()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::any_letter>(Get<::dregx::ast::Type::any_letter>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::optional_padding> AccessTemplateBase<::dregx::ast::node::opt_pad>::optional_padding()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::optional_padding>(Get<::dregx::ast::Type::optional_padding>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::deamerreserved_star__padding__> AccessTemplateBase<::dregx::ast::node::optional_padding>::deamerreserved_star__padding__()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::deamerreserved_star__padding__>(Get<::dregx::ast::Type::deamerreserved_star__padding__>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::padding> AccessTemplateBase<::dregx::ast::node::optional_padding>::padding()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::padding>(Get<::dregx::ast::Type::padding>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::deamerreserved_star__padding__> AccessTemplateBase<::dregx::ast::node::deamerreserved_star__padding__>::deamerreserved_star__padding__()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::deamerreserved_star__padding__>(Get<::dregx::ast::Type::deamerreserved_star__padding__>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::padding> AccessTemplateBase<::dregx::ast::node::deamerreserved_star__padding__>::padding()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::padding>(Get<::dregx::ast::Type::padding>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::SPACE> AccessTemplateBase<::dregx::ast::node::padding>::SPACE()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::SPACE>(Get<::dregx::ast::Type::SPACE>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::TAB> AccessTemplateBase<::dregx::ast::node::padding>::TAB()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::TAB>(Get<::dregx::ast::Type::TAB>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::any> AccessTemplateBase<::dregx::ast::node::special_char_any>::any()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::any>(Get<::dregx::ast::Type::any>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::SLASH> AccessTemplateBase<::dregx::ast::node::special_char_any>::SLASH()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::SLASH>(Get<::dregx::ast::Type::SLASH>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::NUMBER> AccessTemplateBase<::dregx::ast::node::any_number>::NUMBER()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::NUMBER>(Get<::dregx::ast::Type::NUMBER>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::any_letter_exclude_underscore> AccessTemplateBase<::dregx::ast::node::any_letter>::any_letter_exclude_underscore()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::any_letter_exclude_underscore>(Get<::dregx::ast::Type::any_letter_exclude_underscore>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::UNDERSCORE> AccessTemplateBase<::dregx::ast::node::any_letter>::UNDERSCORE()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::UNDERSCORE>(Get<::dregx::ast::Type::UNDERSCORE>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::T_> AccessTemplateBase<::dregx::ast::node::any_letter_exclude_underscore>::T_()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::T_>(Get<::dregx::ast::Type::T_>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::N_> AccessTemplateBase<::dregx::ast::node::any_letter_exclude_underscore>::N_()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::N_>(Get<::dregx::ast::Type::N_>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::R_> AccessTemplateBase<::dregx::ast::node::any_letter_exclude_underscore>::R_()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::R_>(Get<::dregx::ast::Type::R_>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::B_> AccessTemplateBase<::dregx::ast::node::any_letter_exclude_underscore>::B_()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::B_>(Get<::dregx::ast::Type::B_>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::V_> AccessTemplateBase<::dregx::ast::node::any_letter_exclude_underscore>::V_()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::V_>(Get<::dregx::ast::Type::V_>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::A_> AccessTemplateBase<::dregx::ast::node::any_letter_exclude_underscore>::A_()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::A_>(Get<::dregx::ast::Type::A_>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::LETTER> AccessTemplateBase<::dregx::ast::node::any_letter_exclude_underscore>::LETTER()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::LETTER>(Get<::dregx::ast::Type::LETTER>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::LEFT_CURLY_BRACKET> AccessTemplateBase<::dregx::ast::node::any>::LEFT_CURLY_BRACKET()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::LEFT_CURLY_BRACKET>(Get<::dregx::ast::Type::LEFT_CURLY_BRACKET>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::RIGHT_CURLY_BRACKET> AccessTemplateBase<::dregx::ast::node::any>::RIGHT_CURLY_BRACKET()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::RIGHT_CURLY_BRACKET>(Get<::dregx::ast::Type::RIGHT_CURLY_BRACKET>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::LEFT_SQUARE_BRACKET> AccessTemplateBase<::dregx::ast::node::any>::LEFT_SQUARE_BRACKET()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::LEFT_SQUARE_BRACKET>(Get<::dregx::ast::Type::LEFT_SQUARE_BRACKET>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::RIGHT_SQUARE_BRACKET> AccessTemplateBase<::dregx::ast::node::any>::RIGHT_SQUARE_BRACKET()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::RIGHT_SQUARE_BRACKET>(Get<::dregx::ast::Type::RIGHT_SQUARE_BRACKET>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::LEFT_BRACKET> AccessTemplateBase<::dregx::ast::node::any>::LEFT_BRACKET()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::LEFT_BRACKET>(Get<::dregx::ast::Type::LEFT_BRACKET>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::RIGHT_BRACKET> AccessTemplateBase<::dregx::ast::node::any>::RIGHT_BRACKET()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::RIGHT_BRACKET>(Get<::dregx::ast::Type::RIGHT_BRACKET>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::COMMA> AccessTemplateBase<::dregx::ast::node::any>::COMMA()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::COMMA>(Get<::dregx::ast::Type::COMMA>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::SLASH> AccessTemplateBase<::dregx::ast::node::any>::SLASH()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::SLASH>(Get<::dregx::ast::Type::SLASH>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::OR> AccessTemplateBase<::dregx::ast::node::any>::OR()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::OR>(Get<::dregx::ast::Type::OR>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::MIN> AccessTemplateBase<::dregx::ast::node::any>::MIN()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::MIN>(Get<::dregx::ast::Type::MIN>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::UNDERSCORE> AccessTemplateBase<::dregx::ast::node::any>::UNDERSCORE()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::UNDERSCORE>(Get<::dregx::ast::Type::UNDERSCORE>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::NOT> AccessTemplateBase<::dregx::ast::node::any>::NOT()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::NOT>(Get<::dregx::ast::Type::NOT>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::PLUS> AccessTemplateBase<::dregx::ast::node::any>::PLUS()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::PLUS>(Get<::dregx::ast::Type::PLUS>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::STAR> AccessTemplateBase<::dregx::ast::node::any>::STAR()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::STAR>(Get<::dregx::ast::Type::STAR>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::OPTIONAL> AccessTemplateBase<::dregx::ast::node::any>::OPTIONAL()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::OPTIONAL>(Get<::dregx::ast::Type::OPTIONAL>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::NUMBER> AccessTemplateBase<::dregx::ast::node::any>::NUMBER()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::NUMBER>(Get<::dregx::ast::Type::NUMBER>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::T_> AccessTemplateBase<::dregx::ast::node::any>::T_()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::T_>(Get<::dregx::ast::Type::T_>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::N_> AccessTemplateBase<::dregx::ast::node::any>::N_()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::N_>(Get<::dregx::ast::Type::N_>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::R_> AccessTemplateBase<::dregx::ast::node::any>::R_()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::R_>(Get<::dregx::ast::Type::R_>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::B_> AccessTemplateBase<::dregx::ast::node::any>::B_()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::B_>(Get<::dregx::ast::Type::B_>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::V_> AccessTemplateBase<::dregx::ast::node::any>::V_()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::V_>(Get<::dregx::ast::Type::V_>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::A_> AccessTemplateBase<::dregx::ast::node::any>::A_()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::A_>(Get<::dregx::ast::Type::A_>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::LETTER> AccessTemplateBase<::dregx::ast::node::any>::LETTER()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::LETTER>(Get<::dregx::ast::Type::LETTER>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::SPACE> AccessTemplateBase<::dregx::ast::node::any>::SPACE()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::SPACE>(Get<::dregx::ast::Type::SPACE>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::TAB> AccessTemplateBase<::dregx::ast::node::any>::TAB()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::TAB>(Get<::dregx::ast::Type::TAB>(ts));
		}

		inline AccessTemplateBase<::dregx::ast::node::OTHER> AccessTemplateBase<::dregx::ast::node::any>::OTHER()
		{
			// Optimized search, if it fails continue using unoptimized search.

			// Unoptimized search
			return AccessTemplateBase<::dregx::ast::node::OTHER>(Get<::dregx::ast::Type::OTHER>(ts));
		}


	/*!	\class Access_if
	 *
	 *	\brief Accesses the node if it is of the given type.
	 *
	 *	\note A lambda has to be supplied as second argument with paramater: "Access<T>".
	 */
	template<typename T>
	struct Access_if
	{
		const ::deamer::external::cpp::ast::Node* node;

		template<typename FunctionType>
		Access_if(const ::deamer::external::cpp::ast::Node* node_, FunctionType function) : node(node_)
		{
			if (node->GetType() == static_cast<::std::size_t>(::dregx::ast::relation::NodeTypeToEnum_v<T>))
			{
				function(Access<T>(static_cast<const T*>(node)));
			}
		}
	};

}}}

#endif // DREGX_AST_REFERENCE_ACCESSTEMPLATEBASE_H