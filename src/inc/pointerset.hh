#ifndef LEDA_POINTERSET_HH
#define LEDA_POINTERSET_HH
#include <set>

namespace LEDA
{
	template<typename PointerType, typename ValueType>
	using Pointerset=std::set<PointerType<ValueType>>;
}

#endif

