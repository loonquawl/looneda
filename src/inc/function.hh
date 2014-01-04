#ifndef LEDA_FUNCTION_HPP
#define LEDA_FUNCTION_HPP
#include <functional>

namespace LEDA
{
	template<typename T>
	using Function=std::function<T>;
}

#endif

