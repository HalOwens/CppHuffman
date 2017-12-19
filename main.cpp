#include <fstream>
#include <string>
#include "list.h"
using namespace std;

vector <byteData*> bytes_;

string readFile(string); //Reads in the target textfile

/*
 * ********************************************************************
 * *IF YOU FAIL TO MAINTAIN THE HEAD THE WHOLE STRUCTURE WILL NOT WORK*
 * ********************************************************************
 */ 

int main(int argc, char **argv)
{
    string file = readFile("/home/halowens/Documents/cpp/Huffman/source.txt");
    Node* front = createList(file);
    bytes_ = createBinReferences(front);
    printList(front); 
    Node * head = createTree(front);
    string bin;
    createCompressors(bytes_, head, bin);
    bin = createBinary(file, bytes_);
    cout << "File Size: " << file.length() << " bytes" << endl;
    cout << "Compressed File Size: " << bin.length()/8 << " bytes" << endl;
    cout << "Compression Ratio: " << ((float)bin.length()/8)/(float)file.length() << endl;
    return 0;
}


string readFile(string path)
{
    string buffer = "";
    string text = "";
    ifstream myfile; 
    myfile.open(path);
    if(myfile.is_open())
    {
        while(getline(myfile, buffer))
        {
            text = text + buffer + "\n";
        }
        myfile.close();
    }
    cout << "File Size: " << text.length() << " bytes" << endl;
    return text;
}