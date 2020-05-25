# HuffmanCoding
C++ HuffmanCoding Program

This program includes a HuffmanCoding class, which can construct a Huffman Coding tree and generate codes for each character in the input text file
The constructor of the StandardTrie class reads one character at a time and puts together an array with all the characters and their frequencies
The characters are added to a priority queue, using their frequencies to compare them
The HuffmanCoding algorithm puts together a Huffman coding binary tree from the bottom up by creating a new node to represent the parent of the two nodes with the minimum frequencies, having their summed frequency, and pushing the parent node to the priority queue

[![Run on Repl.it](https://repl.it/badge/github/danielzelfo/HuffmanCoding)](https://repl.it/github/danielzelfo/HuffmanCoding)