/*  Program: Huffman Coding
 *	Author: Daniel Zelfo
 *	Class: CSCI 230
 *	Date: 5/11/2020
 *	Description: This program includes a HuffmanCoding class, which can construct a Huffman Coding tree and generate codes for each character in the input text file
 *               The constructor of the StandardTrie class reads one character at a time and puts together an array with all the characters and their frequencies
 *               The characters are added to a priority queue, using their frequencies to compare them
 *               The HuffmanCoding algorithm puts together a Huffman coding binary tree from the bottom up by creating a new node to represent the parent of the two nodes with the minimum frequencies, having their summed frequency, and pushing the parent node to the priority queue
 *
 * I certify that the code below is my own work.
 *
 *	Exception(s): N/A
 *
 */


#include <iostream>
#include "HuffmanCoding.h"

int main() {
    //Huffman coding tree with input and output file
    HuffmanCoding hc("moneyIn.txt", "moneyOut.txt");
}
