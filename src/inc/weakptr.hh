#ifndef LEDA_WEAKPTR_HH
#define LEDA_WEAKPTR_HH
#include <memory>

namespace LEDA
{
	template<typename T>
	using WeakPtr = std::weak_ptr<T>;
}

#endif

