/*  Program: Longest Common Subsequence Algorithm
 *	Author: Daniel Zelfo
 *	Class: CSCI 230
 *	Date: 4/27/2020
 *	Description: This program includes the lcs function, which takes two strings as paramters
 *               The lcs function returns the length of the longest common subsequence(lcs) and print the lcs using a dynamic programming approach
 *
 * I certify that the code below is my own work.
 *
 *	Exception(s): N/A
 *
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int lcs(string t, string p);

int main()
{
    string x, y;
    cout << "Enter string 1: ";
    cin >> x;
    cout << "Enter string 2: ";
    cin >> y;
    cout << "Longest Common Subsequence Length: " << lcs(x, y) << endl;
}


int lcs(string x, string y)
{
    int m = x.size(), n = y.size();

    //m+1 x n+1 matrix initialized with 0's
    vector < vector<int> > L(m+1, vector<int>(n+1, 0));
    int i, j;
    string lcs = "";

    //going through each combination of characters 
    for (i = 1; i <= m; i++) {
        for (j = 1; j <= n; j++) {

            //if the charcters at i-1 and j-1 match, the cell at i, j will be equal to the cell at i-1, j-1 plus one
            if (x[i - 1] == y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
            //otherwise, the cell at i, j will be the maximum of the cells i - 1, j and i,j - 1
            else
                L[i][j] = (L[i - 1][j] > L[i][j - 1] ? L[i - 1][j] : L[i][j - 1]);

        }
    }
    
    //starting at the cell m, n
    i = m; j = n;
    while (i > 0 && j > 0) {
        //if characters i-1 and j-1 match, we will add that character to the longest common subsequence
        if (x[i - 1] == y[j - 1])
        {
            lcs = x[i - 1] + lcs;
            i--; j--;
        }

        //no match

        //if the cell at i - 1, j is greater than the cell at i, j - 1, we decrement i
        else if (L[i - 1][j] > L[i][j - 1])
            i--;
        //otherwise we decrement j
        else
            j--;
    }

    cout << "Longest Common Subsequence: " << lcs << endl;

    return L[m][n];
}