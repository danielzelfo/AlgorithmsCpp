#pragma once
#include "Merge.hpp"

template <typename E>					// set subtraction
class SubtractMerge : public Merge<E> {
protected:
    typedef typename Merge<E>::List List;
    virtual void fromA(const E& a, List& C)
    {
        C.push_back(a);
    }				// add a
    virtual void fromBoth(const E& a, const E& b, List& C)
    { } 						// ignore
    virtual void fromB(const E& b, List& C)
    { }						// ignore
};