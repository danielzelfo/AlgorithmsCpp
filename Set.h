#pragma once
#include <list>
#include <map>

#include "UnionMerge.h"
#include "IntersectMerge.h"
#include "SubtractMerge.h"

template <typename E>
class Set {
	//a list to hold the data
	std::list<E> set;

public:
	typedef typename std::list<E>::iterator Iterator;

	//constructor with a list argument
	Set(std::list<E>);

	Iterator begin() { return set.begin(); }
	Iterator end() { return set.end(); }

	//the three merge functions
	Set<E> set_union(Set<E>) const;
	Set<E> set_intersection(Set<E>) const;
	Set<E> set_difference(Set<E>) const;

	friend class std::list<E>;
};

//the constructor from a list
template <typename E>
Set<E>::Set(std::list<E> l) {
	//using a hashmap to find any duplicates
	std::map<int, bool> m;
	for (auto const& i : l) {
		if (m.find(i) == m.end()) {
			set.push_back(i);
			m[i] = true;
		}
	}
}

//the union function
template <typename E>
Set<E> Set<E>::set_union(Set<E> s) const {
	UnionMerge<E> um;
	std::list<E> a = set, b = s.set, result;
	um.merge(a, b, result);
	return Set(result);
}

//the intersection function
template <typename E>
Set<E> Set<E>::set_intersection(Set<E> s) const {
	IntersectMerge<E> im;
	std::list<E> a = set, b = s.set, result;
	im.merge(a, b, result);
	return Set(result);
}

//the difference function
template <typename E>
Set<E> Set<E>::set_difference(Set<E> s) const {
	SubtractMerge<E> sm;
	std::list<E> a = set, b = s.set, result;
	sm.merge(a, b, result);
	return Set(result);
}