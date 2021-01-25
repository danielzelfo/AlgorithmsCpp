// AlgorithmsCpp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "MemoryManagement/driver.hpp"
#include "PatternMatching/driver.hpp"
#include "LongestCommonSubsequence/driver.hpp"
#include "SetOperations/driver.hpp"
#include "QuickSelect/driver.hpp"
#include "IntegerBucketSort/driver.hpp"
#include "HuffmanCoding/driver.hpp"
#include "SearchingAlgorithms/driver.hpp"

using namespace std;

int main()
{
    int option;
    string options = "Please enter the number for the program to run\n";
           options += "0. To Exit\n";
           options += "1. HuffmanCoding\n";
           options += "2. IntegerBucketSort\n";
           options += "3. LongestCommonSubsequence\n";
           options += "4. MemoryManagement\n";
           options += "5. PatternMatching\n";
           options += "6. QuickSelect\n";
           options += "7. SearchingAlgorithms\n";
           options += "8. SetOperations\n";

    cout << options << ">";
    cin >> option;

    while (option != 0) {
        switch (option) {
        case 1:
            huffmanCodingMain();
            break;
        case 2:
            integerBucketSortMain();
            break;
        case 3:
            longestCommonSubsequenceMain();
            break;
        case 4:
            memoryManagementMain();
            break;
        case 5:
            patternMatchingMain();
            break;
        case 6:
            quickSelectMain();
            break;
        case 7:
            searchingAlgorithmsMain();
            break;
        case 8:
            setOperationsMain();
            break;
        default:
            cout << "Invalid Option (" << option << ")\n";
            break;
        }

        cout << "End.\n\n";

        cout << options << ">";
        cin >> option;
    }

}