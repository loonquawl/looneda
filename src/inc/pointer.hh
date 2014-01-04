#ifndef LEDA_POINTER_HH
#define LEDA_POINTER_HH
#include <memory>

namespace LEDA
{
	template<typename T>
	class Pointer
	{
		protected:
			T* mp_instance;

		public:
			Pointer()
			: mp_instance(nullptr)
			{}

			Pointer(T* ptr)
			: mp_instance(ptr)
			{}

			operator T*()
			{
				return mp_instance;
			}

			T* operator->()
			{
				return mp_instance;
			}

			T& operator*()
			{
				return *mp_instance;
			}

			T* get()
			{
				return mp_instance;
			}
	};
}

#endif

