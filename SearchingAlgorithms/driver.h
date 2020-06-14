/*
* Author: Daniel Zelfo
* Class: CSCI 140
* Program: Linear Search
* Date: 10/28/2019
* Description: This program implements searching an integer array for one value linearly. Two functions exist to do this: an iterative one and a recursive one.
				Another function in this program is one that gets the highest value in an array linearly
*/

#include <iostream>
using namespace std;


//prototypes
int linearSearch(int arr[], int size, int target);
int highestLinearSearch(int arr[], int size);
int recursiveLinearSearch(int arr[], int size, int target, int index = 0);

int main()
{
	//setting array
	const int maxSize = 10;
	int arr[maxSize] = { 1, 3, 5, 7, 44, 21, 63, 32 };

	//outputting array
	for (int i = 0; i < maxSize; i++)
		cout << arr[i] << " ";
	cout << endl;

	//searching array for values
	cout << "Iterative Linear Search: " << endl
		<< "6 is in the array? " << ((linearSearch(arr, maxSize, 6) != -1) ? "true" : "false") << endl
		<< "3 is in the array? " << ((linearSearch(arr, maxSize, 3) != -1) ? "true" : "false") << endl
		<< "Highest value is array: " << highestLinearSearch(arr, maxSize) << endl << endl
		<< "Recursive Linear Search: " << endl
		<< "2 is in the array? " << ((recursiveLinearSearch(arr, maxSize, 2) != -1) ? "true" : "false") << endl
		<< "21 is in the array? " << ((recursiveLinearSearch(arr, maxSize, 21) != -1) ? "true" : "false") << endl << endl;
}

//the iterative linear search
int linearSearch(int arr[], int size, int target) {
	for (int i = 0; i < size; i++)
		if (arr[i] == target)
			return i;
	return -1;
}

//the highest value iteratiev linear search
int highestLinearSearch(int arr[], int size) {
	int highest = arr[0];
	for (int i = 1; i < size; i++)
		if (arr[i] > highest)
			highest = arr[i];
	return highest;
}

//recursive lienar search
int recursiveLinearSearch(int arr[] , int size, int target, int index) {
	if (index == size)
		return -1;
	if (arr[index] == target)
		return index;
	return recursiveLinearSearch(arr, size, target, index + 1);
}