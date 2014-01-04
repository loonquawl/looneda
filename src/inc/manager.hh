#ifndef LEDA_MANAGER_HPP
#define LEDA_MANAGER_HPP
#include <algorithm>
#include <stdexcept>
#include "function.hh"
#include "atomic.hh"
#include "string.hh"
#include "pair.hh"
#include "macros.hh"

namespace LEDA
{
	template<typename T, typename Key,
		template<typename Key, typename Value> class MapImpl,
		template<typename T> class PointerType>
	class Manager
	{
		public:			
			typedef PointerType<T> CntValType;
			typedef MapImpl<Key,CntValType> Container;
			typedef typename Container::value_type PredicateFuncArg;
			typedef Function<bool(PredicateFuncArg)> PredicateFunc;

		protected:
			Container m_container;

		public:
			virtual void add_instance(T* p_inst)
			{
				ASSERT(p_inst!=nullptr);
				CntValType ptr(p_inst);
				Key keyval=p_inst->get_key();
				m_container.insert(Pair<Key,CntValType>(keyval,ptr));
			}
			
			virtual void remove_instances(PredicateFunc predicate)
			{
				typename Container::iterator iter=m_container.begin();
				for(; iter!=m_container.end(); iter++)
				{
					// iterators don't get invalidated
					// in case of Map implementations
					// from standard library
					if (predicate(*iter))
						m_container.erase(iter);
				}
			}

			virtual void remove_instance(T* p_inst)
			{
				remove_instances(
					[&](PredicateFuncArg arg) -> bool
					{
						return arg.second.get()==p_inst;
					}
				);
			}

			virtual void remove_instances(const Key& key)
			{
				remove_instances(
					[&](PredicateFuncArg arg) -> bool
					{
						return arg.second.get()->get_key()==key;
					}
				);
			}

			/*
			 *	@descr	Returns copy of PointerType class which points to stored object.
			 *		Automatically increments reference count of associated shared
			 *		pointer before actual use of an instance.
			 */
			virtual CntValType operator[](const Key& key)
			{
				return m_container[key];
			}
	};
}

#endif

