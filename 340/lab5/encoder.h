/*
Takes a text and the root of the Huffman tree and returns the encoded string.
For the finial result this will need to print the encoded string to a file.
*/

#include "bstream.cpp"
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
<<<<<<< HEAD
		void writeFile(string);
=======
		void stringPrint();
>>>>>>> 60b9b2165220bbf63fcb758c3b98cd48f087284a
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
			stringPrint();//This will be replaced when you get the binary printer working.
		}
	}
	return encodedString;
};
void writeFile(string code){
	const char* codeArray = code.c_str();
	ofbstream binOutput;
	binOutput.open("filename.hzip");
	for(int i=0; i<strlen(codeArray); i++){
		binOutput.writeBit(codeArray[i]);
	}
};
void encoder::stringPrint(){
	ofstream outfile;
	outfile.open("coded.txt");
	outfile<<encodedString;
}
