/*  Program: Set Operations
 *	Author: Daniel Zelfo
 *	Class: CSCI 230
 *	Date: 4/13/2020
 *	Description: This program includes the class Set, which represents an unordered set.
 *               It can be constructed using a C++ STL list, removing any duplicates.
 *               It includes the set operations union, intersection, and difference, which merge two sets into one.
 *				 The union function returns a set that is the union of two sets.
 *				 The intersection function returns a set that is the intersection of two sets.
 *				 The difference function returns a set that is the difference in the two sets.
 *
 * I certify that the code below is my own work.
 *
 *	Exception(s): N/A
 *
 */

#include <iostream>
#include <list>


#include "Set.hpp"

using namespace std;

template <typename T> void printSet(Set<T>);

void setOperationsMain()
{
    //two lists
    list<int> a{ 1, 3, 5, 5, 7, 9 };
    list<int> b{ 3, 6, 6, 9, 12, 12, 5 };
    //outputting the lists
    cout << "Original Lists: " << endl;
    for (auto const& i : a)
        cout << i << " ";
    cout << endl;
    for (auto const& i : b)
        cout << i << " ";
    cout << "\n\n";

    //creating two sets using the lists
    Set<int> s1(a), s2(b);
    //outputting the sets
    cout << "Original Sets: " << endl;
    printSet(s1);
    printSet(s2);
    cout << endl;

    //outputting the union of the sets
    cout << "Union of The Sets: " << endl;
    printSet(s1.set_union(s2));
    cout << endl;

    //outputting the intersection of the sets
    cout << "Intersection of The Sets: " << endl;
    printSet(s1.set_intersection(s2));
    cout << endl;

    //outputting the difference in the sets
    cout << "Difference of The Sets: " << endl;
    printSet(s1.set_difference(s2));
    cout << endl;

}

//function to output a given set
template <typename T>
void printSet(Set<T> l) {
    for (typename Set<T>::Iterator it = l.begin(); it != l.end(); ++it)
        cout << *it << " ";
    cout << endl;
}