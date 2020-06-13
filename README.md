# AlgorithmsCpp
A Collection of Algorithms in C++

[![Run on Repl.it](https://repl.it/badge/github/danielzelfo/AlgorithmsCpp)](https://repl.it/github/danielzelfo/AlgorithmsCpp)

## MemoryManagement
Memory Management Simulation in C++

This program includes the MemoryManagement class, which allows us to run simulations of memory allocation heuristics
It includes the first fit and best fit algorithms
The simulation outputs the average unused memory after 100 runs and the total running time for each algorithms


## PatternMatching
Pattern Matching Algorithms in C++

This program includes the Boyer–Moore (BM) and Knuth–Morris–Pratt (KMP) pattern matching algorithms
The BMmatch function uses the Boyer–Moore pattern matching algorithm and the KMPmatch function uses the Knuth–Morris–Pratt pattern matching algorithm.
The pattern matching functions returns -1 if the pattern string is not in the given text and the index of the first character in the text in which the match occurs otherwise.
The BM algorithm uses buildLastFunction function to build a vector of ints that is the size of the alphabet, filling it with the index of the last character in pattern at the index that is its ascii value in the vector
The BM algorithm then finds any matches by making alignments from left to right and checking characters from right to left (looking-glass heuristic)
The BM algorithm also uses last function to implement the character-jump heuristic
The KMP algorithm uses the computeFailFunction to build a vector of ints that is the size of the pattern, filling it with the the length of the longest prefix which is a suffix
The KMP algorithm makes alignments from left to right and checks character comparisons from left to right
The KMP algorithm uses the fial vector to know where in the pattern to start comparison the next time when a mismatch is found


## LongestCommonSubsequence
C++ Longest Common Subsequence Program

This program includes the lcs function, which takes two strings as paramters
The lcs function returns the length of the longest common subsequence(lcs) and print the lcs using a dynamic programming approach


## SetOperations
Set Merge Operations Program in C++

This program includes the class Set, which represents an unordered set
It can be constructed using a list, removing any duplicates
It includes the set opeations union, intersection, and difference, which merge two sets into one
The union function returns a set that is the union of two sets
The intersection function returns a set that is the intersection of two sets
The difference function returns a set that is the difference in the two sets


## QuickSelect
C++ Program for the QuickSelect Algorithm

This program includes a function that find the kth smallest element using a variation of the randomized quicksort algorithm
This algorithm can find the the kth smallest element in a linear worst case running time
This is done by using the prune-and search design pattern which gets rid of the portion of the data being observed in each recusive call based on the value of k


## IntegerBucketSort
C++ Bucket Sort Program for Integers

This program includes the bucketsort algorithm for integers. It uses the bucketsort function to sort a vector of 100 random values.
The bucketsort algorithm for integers increments a vector with a size equal to the range of the values being sorted
We then extract the values in sorted order by looking at all the nonzero values in the array we incremented


## HuffmanCoding
C++ HuffmanCoding Program

This program includes a HuffmanCoding class, which can construct a Huffman Coding tree and generate codes for each character in the input text file
The constructor of the StandardTrie class reads one character at a time and puts together an array with all the characters and their frequencies
The characters are added to a priority queue, using their frequencies to compare them
The HuffmanCoding algorithm puts together a Huffman coding binary tree from the bottom up by creating a new node to represent the parent of the two nodes with the minimum frequencies, having their summed frequency, and pushing the parent node to the priority queue


## Searching Algorithms
C++ Sequential and Binary Search

This program implements the binary search algorithm in two functions: an iterative one and a recursive one.

This program implements searching an integer array for one value linearly. Two functions exist to do this: an iterative one and a recursive one.
Another function in this program is one that gets the highest value in an array linearly

