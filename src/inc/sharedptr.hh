#ifndef LEDA_SHAREDPTR_HPP
#define LEDA_SHAREDPTR_HPP
#include <memory>

namespace LEDA
{
	template<typename T>
	using SharedPtr=std::shared_ptr<T>;
}

#endif

