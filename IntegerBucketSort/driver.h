/*  Program: BucketSort
 *	Author: Daniel Zelfo
 *	Class: CSCI 230
 *	Date: 3/30/2020
 *	Description: This program includes the bucketsort algorithm for integers. It uses the bucketsort function to sort a vector of 100 random values.
 *               The bucketsort algorithm for integers increments a vector with a size equal to the range of the values being sorted.
 *               We then extract the values in sorted order by looking at all the nonzero values in the array we incremented.
 *
 * I certify that the code below is my own work.
 *
 *	Exception(s): N/A
 *
 */

#include <iostream>
#include <vector>
#include <time.h>

#include "BucketSort.h"

using namespace std;


void integerBucketSortMain()
{
    const int arrSize = 100;
    const int range = 1000;
    vector<int> arr(arrSize);
    srand(time(0));


    //populating and outputting the vector
    cout << "Original array: \n";
    for (int i = 0; i < arrSize; ++i) {
        arr[i] = rand() % range;
        cout << arr[i] << " ";
    }

    //sorting the vector
    cout << "\n\nBucket Sorting Array...\n\n";
    bucketSort(arr);


    //outputting the sorted vector
    cout << "Sorted array: \n";
    for (int i = 0; i < arrSize; ++i)
        cout << arr[i] << " ";

    cout << endl;

}
