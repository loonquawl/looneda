#ifndef LEDA_SINGLETON_HPP
#define LEDA_SINGLETON_HPP

namespace LEDA
{
	template<typename T>
	class Singleton
	{
		protected:
			static T* sp_instance;

			Singleton()
			{}

			virtual ~Singleton()
			{}

		public:
			static T& inst()
			{
				if (sp_instance==nullptr)
					sp_instance=new T;
				return *sp_instance;
			}

			static void destroy()
			{
				delete sp_instance;
			}
	};
}

#endif

