/*  Program: QuickSelect
 *	Author: Daniel Zelfo
 *	Class: CSCI 230
 *	Date: 4/6/2020
 *	Description: This program includes a function that finds the kth smallest element using a variation of the randomized quicksort algorithm.
 *               This algorithm can find the kth smallest element in a linear worst-case running time.
 *               This is done by using the prune-and search design pattern which gets rid of the portion of the data being observed in each recursive call based on the value of k.
 *
 * I certify that the code below is my own work.
 *
 *	Exception(s): N/A
 *
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <time.h>

#include "Comparator.hpp"
#include "QuickSelect.hpp"

using namespace std;

void quickSelectMain()
{
    //vectors to hold data
    vector<int> arr10, arr1k, arr100k;
    //the comparator
    Lower<int> c;
    //number to be read in from the file and k
    int number, k;
    //the quickSort object
    quickSelect<int, Lower<int>> quickSelect;

    //filling the array of size 10 with random number in the range 0-9999
    cout << "Array number 1 (n=10)" << endl;
    srand(time(0));
    for (int i = 0; i < 10; i++)
        arr10.push_back(rand() % 10000);

    //outputting the smallest element
    k = 1;
    cout << "#" << k << " smallest: ";
    cout << quickSelect(arr10, c, k) << endl;

    //outputting the median element
    k = arr10.size() / 2;
    cout << "#" << k << " smallest: ";
    cout << quickSelect(arr10, c, k) << endl;

    //outputting the maximum element
    k = arr10.size();
    cout << "#" << k << " smallest: ";
    cout << quickSelect(arr10, c, k) << endl;

    cout << endl;


    //filling the array with 1000 elements from the file
    string filename = "QuickSelect/small1k.txt";
    cout << "Array number 2 from " << filename << endl;
    ifstream myfile(filename);
    if (myfile.is_open()) {
        while (myfile >> number)
            arr1k.push_back(number);
        myfile.close();
    }
    else
        cout << "Unable to open '" << filename << "'" << endl;

    //outputting the median of the array with n=1000
    k = arr1k.size() / 2;
    cout << "median: ";
    cout << quickSelect(arr1k, c, k) << endl;


    cout << endl;

    //filling the array with 100000 elements from the file
    filename = "QuickSelect/large100k.txt";
    cout << "Array number 3 from " << filename << endl;
    myfile.open(filename);
    if (myfile.is_open()) {
        while (myfile >> number)
            arr100k.push_back(number);
        myfile.close();
    }
    else
        cout << "Unable to open '" << filename << "'" << endl;

    //outputting the median of the array with n=100000
    k = arr100k.size() / 2;
    cout << "median: ";
    cout << quickSelect(arr100k, c, k) << endl;

}
