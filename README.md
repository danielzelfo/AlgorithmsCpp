# PatternMatching
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

[![Run on Repl.it](https://repl.it/badge/github/danielzelfo/PatternMatching)](https://repl.it/github/danielzelfo/PatternMatching)