/*
Takes a text and the root of the Huffman tree and returns the encoded string.
For the finial result this will need to print the encoded string to a file.
*/


#include "node.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;
class encoder{
	private:
		string encodedString;

	public:
		encoder();
		void genCode(char, node*, string);
		string incode(node*);
};

encoder::encoder(){
	encodedString = "";
};
void encoder::genCode(char cur, node * root, string coded){// This will generate the code recursively.
	using namespace std;
	if(root->checkLeaf() == true){
		if(root->getVal() == cur){
			encodedString = encodedString + coded;
		}
	}
	if(root->hasLeft()){
		genCode(cur,root->getLeft(),coded+"0");
	}
	if(root->hasRight()){
		genCode(cur,root->getRight(),coded+"1");
	}
};
using namespace std;
string encoder::incode(node *root){
	using namespace std;
	ifstream text;
	text.open("TextFile.txt");// this needs to be overwritten with a prompt.
	string coded;
	while(text){
		string line;
		getline(text, line);
		int length = line.length();
		for(int i = 0; i <length; i++){
			char currentletter = line[i];
			string coded = "";
			genCode(currentletter,root,coded);
		}
	}
	return encodedString;
};

