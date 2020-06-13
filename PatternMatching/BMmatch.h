#pragma once
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> buildLastFunction(const string& pattern);

static int dummy_bmcomparisons;
int BMmatch(const string& text, const string& pattern, int& comparisons = dummy_bmcomparisons) {
    vector<int> last = buildLastFunction(pattern);
    int n = text.size();
    int m = pattern.size();
    int i = m - 1;
    if (i > n - 1)				// pattern longer than text?
        return -1;				// ...then no match
    int j = m - 1;
    do {
        if (pattern[j] == text[i])
            if (j == 0) return i;			// found a match
            else {					// looking-glass heuristic
                i--; j--;				// proceed right-to-left
            }
        else {					// character-jump heuristic
            i = i + m - min(j, 1 + last[text[i]]);
            j = m - 1;
        }
        comparisons++;
    } while (i <= n - 1);
    return -1;					// no match
}
// construct function last
vector<int> buildLastFunction(const string& pattern) {
    const int N_ASCII = 128;			// number of ASCII characters
    int i;
    vector<int> last(N_ASCII, -1);		// assume ASCII character set and initialize array

    for (i = 0; i < pattern.size(); i++) {
        last[pattern[i]] = i;			// (implicit cast to ASCII code)
    }
    return last;
}