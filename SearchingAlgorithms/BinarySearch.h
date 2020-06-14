/*
* Author: Daniel Zelfo
* Class: CSCI 140
* Program: BInary Search
* Date: 10/28/2019
* Description: This program implements the binary search algorithm in two functions: an iterative one and a recursive one.
*/

#include <iostream>
using namespace std;

//prototypes
int binarySearch(int arr[], int size, int target);
int recursiveBinarySearch(int arr[], int size, int target, int l = 0);

void binarySearchMain()
{
	//setting array
	const int maxsize = 5;
	int target = 0;
	int arr[maxsize] = { 1, 3, 5, 7, 9 };

	//testing iterative binary search
	cout << "Iterative Binary Search: " << endl;
	for(; target < 2*maxsize; target++)
		cout << target << " is is the array? " << (binarySearch(arr, maxsize, target) == -1 ? "false" : "true") << endl;
	cout << endl;

	//testing recursive binary search
	cout << "Recursive Binary Search: " << endl;
	for (target = 0; target < 2 * maxsize; target++)
		cout << target << " is is the array? " << (recursiveBinarySearch(arr, maxsize, target) == -1 ? "false" : "true") << endl;
	cout << endl << endl;
}

//the iterative linear search program
int binarySearch(int arr[], int size, int target) {
	int l = 0, r = size-1, mid;

	while (l <= r) {
		mid = (l + r) / 2;
		if (target == arr[mid])
			return mid;

		if (target > arr[mid])
			l = mid + 1 ;
		else
			r = mid - 1;
	}
	return -1;
}

//teh recursive binary serach program
int recursiveBinarySearch(int sortedArray[], int r, int target, int l) {

	if (l <= r) {
		int mid = (l + r) / 2;  // compute mid point.
		if (target == sortedArray[mid])
			return mid;   // found it.
		else if (target < sortedArray[mid])
			return recursiveBinarySearch(sortedArray, mid - 1, target, l);
		
		return recursiveBinarySearch(sortedArray, r, target, mid + 1);
	}
	return -1;    // failed to find target
}