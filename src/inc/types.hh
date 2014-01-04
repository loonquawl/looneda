#ifndef LEDA_TYPES_HPP
#define LEDA_TYPES_HPP
#include <cstdlib>
#include "manager.hh"
#include "singleton.hh"
#include "map.hh"
#include "string.hh"
#include "pointer.hh"
#include "named.hh"

namespace LEDA
{
	typedef unsigned int uint;
	typedef double DefaultNumericalType;

	class Base
	{
			void register_instance();

		protected:
			const char* m_classname;

			unsigned int m_instance_number;
			static unsigned int s_instance_number;

		public:
			Base();
			virtual ~Base();

			virtual String get_classname() const
			{
				return m_classname;
			}

			virtual String get_key() const
			{
				return String(m_classname)+"#"+std::to_string(m_instance_number);
			}
	};

	class Named : public Base
	{
		protected:
			String m_name;

		public:
			Named();
			Named(const String& name);

			virtual String get_key() const
			{
				return String(m_classname)+"#"+m_name;
			}

			virtual String get_name() const
			{
				return m_name;
			}
	};

	class HierarchyManager : public Manager<Base,String,UnorderedMap,Pointer>, public Singleton<HierarchyManager> 
	{
		friend class Singleton<HierarchyManager>;

		protected:
			HierarchyManager()
			{}
	};
}

#endif

