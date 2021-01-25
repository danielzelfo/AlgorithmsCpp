#pragma once
#include "Merge.hpp"

template <typename E>					// set intersection
class IntersectMerge : public Merge<E> {
protected:
    typedef typename Merge<E>::List List;
    virtual void fromA(const E& a, List& C)
    { } 						// ignore
    virtual void fromBoth(const E& a, const E& b, List& C)
    {
        C.push_back(a);
    }				// add a only 
    virtual void fromB(const E& b, List& C)
    { } 						// ignore
};