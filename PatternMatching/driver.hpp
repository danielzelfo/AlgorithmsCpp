/*  Program: Brute Force Pattern Matching
 *	Author: Daniel Zelfo
 *	Class: CSCI 230
 *	Date: 4/20/2020
 *	Description: This program includes the Boyer–Moore (BM) and Knuth–Morris–Pratt (KMP) pattern matching algorithms.
 *               The BMmatch function uses the Boyer–Moore pattern matching algorithm and the KMPmatch function uses the Knuth–Morris–Pratt pattern matching algorithm.
 *               The pattern matching functions return -1 if the pattern string is not in the given text and the index of the first character in the text in which the match occurs otherwise.
 *				 The BM algorithm uses buildLastFunction function to build a vector of ints that is the size of the alphabet, filling it with the index of the last character in the pattern string at the index that is its ASCII character's decimal value in the last vector.
 *				 The BM algorithm then finds any matches by making alignments from left to right and checking characters from right to left (looking-glass heuristic.)
 *				 The BM algorithm also uses the last function to implement the character-jump heuristic.
 *				 The KMP algorithm uses the computeFailFunction to build a vector of ints that is the size of the pattern, filling it with the length of the longest prefix which is a suffix.
 *				 The KMP algorithm makes alignments from left to right and checks character comparisons from left to right.
 *				 The KMP algorithm uses the fail vector to know where in the pattern to start comparison the next time when a mismatch is found.
 *
 * I certify that the code below is my own work.
 *
 *	Exception(s): N/A
 *
 */


#include <iostream>

#include "KMPmatch.hpp"
#include "BMmatch.hpp"

void outputMatch(string T, string P);

void patternMatchingMain()
{
	

	const string 
		
		T1 = "a pattern matching algorithm",
		P11 = "rithm", P12 = "rithn",

		T2 = "GTTTATGTAGCTTACCTCCTCAAAGCAATACACTGAAAA",
		P21 = "CTGA", P22 = "CTGG";


	outputMatch(T1, P11);
	outputMatch(T1, P12);
	
	outputMatch(T2, P21);
	outputMatch(T2, P22);
	
	
}

void outputMatch(string T, string P) {
	
	int matchIndex, comparisons = 0;

	cout << "Text: " << T << endl;
	cout << "Pattern: " << P << "\n\n";

	cout << "\tKMP Match Algorithm: " << endl;

	matchIndex = KMPmatch(T, P, comparisons);
	
	if (matchIndex != -1)
		cout << "\tMatch at index: " << matchIndex << endl;
	else
		cout << "\tNo match" << endl;

	cout << "\tNumber of comparisons: " << comparisons << "\n\n";

	cout << "\tBM Match Algorithm: " << endl;

	comparisons = 0;
	matchIndex = BMmatch(T, P, comparisons);

	if (matchIndex != -1)
		cout << "\tMatch at index: " << matchIndex << endl;
	else
		cout << "\tNo match" << endl;

	cout << "\tNumber of comparisons: " << comparisons << "\n\n";
}