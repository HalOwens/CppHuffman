#include "list.h"

using namespace std;

//Node* createList(string); //Creates the linked list consisting of a char and its frequency
//void printList(Node*); //Pritns out the list to the terminal useful for debugging
//Node* createTree(Node*); // Creates a huffman tree returns Node pointer to top of the tree
//Node* printTree(Node*); //prints the tree from left to right
//void createEncrytptors(vector<byteData*> bytes, Node* head, string binPath) // travels tree recursively then assignes string of compressed bytes at end of leaf
//vector<byteData*> createBinReferences(Node* head) // creates a vector containg a structure with a letter and a spot for its new huffman compression byte scheme


string createBinary(string text, vector<byteData*> bytes)
{
    string binary = "";
    for(unsigned int i = 0; i < text.length(); i ++)
    {
        for(unsigned int j = 0; j < bytes.size(); j ++)
        {
            if(text[i] == bytes.at(j)->letter)
            {
                binary = binary + bytes.at(j)->bits;
            }
        }
    }
    return binary;
}

void createCompressors(vector<byteData*> bytes, Node* head, string binPath)
{
     if(head == nullptr)
    {
        return;
    }
    if(head->left == nullptr && head->right == nullptr)
    {
        for(unsigned int i = 0; i < bytes.size(); i ++)
        {
            if(bytes.at(i)->letter == head->letter)
            {
                bytes.at(i)->bits = binPath;
            }
        }
    }
    
    createCompressors(bytes, head->left, binPath+"0");
    createCompressors(bytes, head->right, binPath+"1");
    return;
}



vector<byteData*> createBinReferences(Node* head)
{
    vector<byteData*> charList;
    byteData* temp;
    while(head->next != nullptr)
    {
        head = head->next;
        temp = new byteData;
        temp->letter = head->letter;
        charList.push_back(temp);
    }
    return charList;
    
}

Node* printTree(Node* head) 
{
    
    if(head == nullptr)
    {
        return nullptr;
    }
    if(head->left == nullptr && head->right == nullptr)
    {
        if(head->letter == (char)10)
        {
            cout << "nl" << ":  " << head->amt << endl;
        }
        else if(head->letter == (char)32)
        {
            cout << "sp" << ":  " << head->amt << endl;
        }
        else if (head->letter != (char)0)
        {
            cout << head->letter << ":  " << head->amt << endl;
        }
    }
    printTree(head->right);
    printTree(head->left);
    return nullptr;
}

Node* createTree(Node* head)
{
    Node* maxNode = new Node((char)0, 32767);
    Node* r_lowest = maxNode;
    Node* l_lowest = maxNode;
    Node* pos = head;
    int len = 0;
    while(pos->next != nullptr)
    {
        len ++;
        pos = pos->next;
        if(pos->amt <= r_lowest->amt)
        {
            l_lowest = r_lowest;
            r_lowest = pos;
        }
        else if(pos->amt <= l_lowest->amt)
        {
            l_lowest = pos;
        }
    }
    if (len <= 1)
    {
        return head;
    }
    else if(len == 2)
    {
        Node* treeTop = new Node((char)0, pos->back->amt + pos->amt);
        treeTop->left = pos;
        treeTop->right = pos->back;
        return treeTop;
    }
    else
    {
        Node* leaf = new Node((char)0, l_lowest->amt + r_lowest->amt);
        leaf->left = l_lowest;
        leaf->right = r_lowest;
        //cout << "MERGING : " << l_lowest->letter << " and " << r_lowest->letter << endl;
        if(pos == r_lowest || pos == l_lowest)
        {
            pos = pos->back;
            if(pos == l_lowest || pos == r_lowest)
            {
                pos = pos->back;
            }
            
        }
        
        l_lowest->back->next = l_lowest->next;
        if(l_lowest->next != nullptr)
        {
            l_lowest->next->back = l_lowest->back;
        }
        r_lowest->back->next = r_lowest->next;
        if(r_lowest->next != nullptr)
        {
            r_lowest->next->back = r_lowest->back;
        }
        pos->next = leaf;
        leaf->back = pos;
        return createTree(head);
    }
    return nullptr;
}


void printList(Node *head)
{
    cout << "*FORWARDS*" << endl;
    while(head->next != nullptr)
    {
        head = head->next;
        if(head->letter == (char)10)
        {
            cout << "nl" << ":  " << head->amt << endl;
        }
        else if(head->letter == (char)32)
        {
            cout << "sp" << ":  " << head->amt << endl;
        }
        else if (head->letter != (char)0)
        {
            cout << head->letter << ":  " << head->amt << endl;
        }
    }
    //cout << "*BACKWARDS*" << endl;
    while(head->back != nullptr && false)
    {
    
        if(head->letter == (char)10)
        {
            cout << "nl" << ":  " << head->amt << endl;
        }
        else if(head->letter == (char)32)
        {
            cout << "sp" << ":  " << head->amt << endl;
        }
        else if (head->letter != (char)0)
        {
            cout << head->letter << ":  " << head->amt << endl;
        }
        head = head->back;
    }
}

Node * createList(string letters)
{
    Node *front = new Node((char)0, 32767);
    Node *pos = front;
    bool found = false;
    for(unsigned int i = 0; i < letters.size(); i ++)
    {
        while(pos->next != nullptr)
        {
            pos = pos->next;
            if(letters[i] == pos->letter && !found)
            {
                pos->amt++;
                found = true;
            }
        }
        if(!found)
        {
            pos->next = new Node(letters[i], 1);
            pos->next->back = pos;
        }
        pos = front;
        found = false;
    }
    return front;
}
