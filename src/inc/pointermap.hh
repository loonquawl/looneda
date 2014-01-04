#ifndef LEDA_POINTERMAP_HH
#define LEDA_POINTERMAP_HH
#include "map.hh"
#include "sharedptr.hh"

namespace LEDA
{
	template<typename Key, typename PointerType, typename ValueType>
	using PointerMap=Map<Key,PointerType<ValueType>>;
}

#endif

