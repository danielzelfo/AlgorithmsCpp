#pragma once
#include <string>
#include <fstream>
#include <list>
#include <algorithm>
#include <vector>
#include <queue> 
#include <iostream>

using namespace std;

//alphabet size
const int ALPHABET_SIZE = 128;


//Huffman coding tree node
class Node {
public:
	Node* left;
	Node* right;


	int frequency;
	string code;


	Node(int f) : frequency(f) {
		left = nullptr;
		right = nullptr;
		code = "";
	}


};

//HuffmanCoding class
class HuffmanCoding {

	//array of Huffman coding tree nodes for each character in the alphabet
	Node* chars[ALPHABET_SIZE]{ nullptr };

	//the text that is inputted
	string text;

	//the encoded text
	string textEncoding;

	//node comparator by frequency for priority queue
	struct CompareNode {
		bool operator()(Node* const& n1, Node* const& n2) {
			return n1->frequency > n2->frequency;
		}
	};

	//recursive function to set the codes of all the Huffman coding tree nodes
	void setCode(Node* n) {

		if (n->left != nullptr) {

			n->left->code = n->code + "0";
			setCode(n->left);
		}
		if (n->right != nullptr) {

			n->right->code = n->code + "1";
			setCode(n->right);
		}


	}

public:

	//constructor with input file path and output file path
	HuffmanCoding(const string inFilePath, const string outFilePath) {
		char c;
		ifstream data;
		data.open(inFilePath);

		text = "";

		//inputting a character at a time from the input file
		while (data.get(c)) {
			//adding character to the text
			text += c;
			//checking if the character is seen for the first time
			if (chars[c] == nullptr) {

				//creating a Huffman coding tree node for the character with a frequency of one
					//and adding it to the array of nodes
				Node* n = new Node(1);
				chars[c] = n;
			}
			//repeated char
			else
				chars[c]->frequency++;


		}

		//priority queue for nodes, compared by frequency
		priority_queue <Node*, vector<Node*>, CompareNode> nodes;


		//pushing all seen characters to the priority queue
		for (int i = 0; i < ALPHABET_SIZE; ++i)
			if (chars[i] != nullptr)
				nodes.push(chars[i]);


		//looping until there is one character in the priority queue (the root)
		while (nodes.size() > 1) {

			//popping the left and right nodes
			Node* l = nodes.top();
			nodes.pop();
			Node* r = nodes.top();
			nodes.pop();

			//parent node
			Node* par = new Node(l->frequency + r->frequency);
			par->left = l;
			par->right = r;

			//pushing parent node to priority queue
			nodes.push(par);
		}

		//setting the code for each of the nodes with a recursive function (starting at the root)
		setCode(nodes.top());

		ofstream output;
		output.open(outFilePath);

		//generating the encoded text
		textEncoding = "";
		for (int i = 0; i < text.length(); i++)
			textEncoding += chars[text[i]]->code;

		//outputting each character and its code
		for (int i = 0; i < ALPHABET_SIZE; i++)
			if (chars[i] != nullptr)
				output << (char)i << " " << chars[i]->code << endl;

		//outputting the number of characters
		output << "Number of characters: " << text.length() << endl;

		//outputting the number of bits and the encoded text
		output << "*****" << endl;
		output << "Number of bits: " << textEncoding.length() << endl;
		output << textEncoding << endl;
	}

};
