#pragma once
#include <vector>
#include <algorithm>

using namespace std;

//function to find the minimum value in a vecotor of integers
int min_value(vector<int> arr) {
	int min = arr[0];
	for (int i = 1; i < arr.size(); ++i)
		if (arr[i] < min)
			min = arr[i];
	return min;
}

//function to find the maximum value in a vecotor of integers
int max_value(vector<int> arr) {
	int max = arr[0];
	for (int i = 1; i < arr.size(); ++i)
		if (arr[i] > max)
			max = arr[i];
	return max;
}

//function to sort a vector of intgers using the bucket sort alorithm
void bucketSort(vector<int>& arr) {
	//getting the minimum and maximum values
	int min = min_value(arr), max = max_value(arr);
	//creating a vector with that range
	vector<int> A(max - min + 1, 0);
	vector<int> sortedArr;

	//incrementing the index of the A array equal to the value of each element in the vector being sorted
	for (int i = 0; i < arr.size(); ++i)
		//subtracting the minimum value to start at 0
		++A[arr[i] - min];

	//adding each non-zero index plus the minmum value to the sorted vector
	for(int i = 0; i < A.size(); ++i)
		while (A[i] > 0) {
			sortedArr.push_back(i+min);
			--A[i];
		}
	
	arr = sortedArr;
}
