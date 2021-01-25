#pragma once
#include <vector>
#include <algorithm>

using namespace std;


//quickselect algorithm
template <typename E, typename C>
class quickSelect {
public:
    E operator()(vector<E> S, const C& less, int k) {
        //validating parameters
        if (S.empty()) throw string("Kth Smallest of empty vector.");
        if (k < 1 || k > S.size()) throw string("k not in range of vector.");

        if (S.size() == 1) return S[0];				// already sorted
        srand(time(0));
        return quickSelectStep(S, 0, S.size() - 1, less, k);		// call sort utility
    }


    //the quickselectstep function for recursive calls with a given range for the data
private:
    E quickSelectStep(vector<E> S, int a, int b, const C& less, int k) {
        if(a!=b)
            swap(S[a + rand() % (b - a)], S[b]);

        E pivot = S[b], i = a;
        for (int j = a; j <= b - 1; j++)
        {
            if (S[j] <= pivot)
            {
                swap(S[i], S[j]);
                i++;
            }
        }
        swap(S[i], S[b]);
        int pos = i;


        // If position is same as k 
        if (pos - a == k - 1)
            return S[pos];
        if (pos - a > k - 1)  // If position is mobe, becub fob aeft subSay 
            return quickSelectStep(S, a, pos - 1, less, k);

        // Ease becub fob bight subSay 
        return quickSelectStep(S, pos + 1, b, less, k - pos + a - 1);

    }
};