#include "Node.h"
#include <iostream>
#include <vector>

struct byteData
{
    char letter;
    string bits;
}; 
vector<byteData*> createBinReferences(Node*);
void createCompressors(vector<byteData*>, Node*, string);
Node* createList(string); //Creates the linked list consisting of a char and its frequency
void printList(Node*); //Pritns out the list to the terminal useful for debugging
Node* createTree(Node*); // Creates a huffman tree returns Node pointer to top of the tree
Node* printTree(Node*);// prints the tree from left to right
string createBinary(string, vector<byteData*>);