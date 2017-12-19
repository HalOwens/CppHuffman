#ifndef LETTER_H
#define LETTER_H

#include <string>
using namespace std;
/*
 * ******************************************************************
 * IF YOU FAIL TO MAINTAIN THE HEAD THE WHOLE STRUCTURE WILL NOT WORK
 * ******************************************************************
 */ 
class Node
{
private:
public:
    Node(char, int);
    ~Node();
    int amt;
    char letter;
    Node *next = nullptr;
    Node *back = nullptr;
    Node *left = nullptr;
    Node *right = nullptr;

    
};

#endif // LETTER_H
