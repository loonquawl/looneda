#ifndef LEDA_MAP_HPP
#define LEDA_MAP_HPP
#include <unordered_map>

namespace LEDA
{
	template<typename Key, typename Value>
	using UnorderedMap=std::unordered_map<Key,Value>;
	
	template<typename Key, typename Value>
	using Multimap=std::multimap<Key,Value>;

	template<typename Key, typename Value>
	using Map=std::map<Key,Value>;
}

#endif

