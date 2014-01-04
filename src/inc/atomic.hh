#ifndef LEDA_ATOMIC_HPP
#define LEDA_ATOMIC_HPP
#include <atomic>

namespace LEDA
{
	template<typename T>
	using Atomic=std::atomic<T>;
}

#endif

