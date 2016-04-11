#include "my_da_array.cpp"
#include "binaryTree.h"
#include <fstream>
#include <iostream>
#include <sstream> // Needed for stringstream
#include <string>
#include <stdlib.h>

using namespace std;

my_da_array<node> createWeights(){
	my_da_array<node> array;
	ifstream textfile;
	textfile.open("TextFile.txt"); // this will need to be a input later.
	while(textfile){
	}
}

my_da_array<node> readWeights(){
	my_da_array<node> array;
	ifstream weightsFile;
	weightsFile.open("weights.txt"); // This will need to be an input later.
	while(weightsFile){
		stringstream ss;
		string line;
		char hh;
		double weight;
		getline(weightsFile, line);
		if (line == ""){// This if statement is needed to catch when it grabs an empty string from the end of the file.
			break;
		}
		int length = line.length();
		hh = line[0];
		line = line.substr(1,length);
		ss << line; //gives the string to the stringstream
		ss >> weight; //gets the double out of the stringstream
		node * currentNode = new node(hh,weight);
		array.da_push(*currentNode);
		//cout<<"making node with: "<<hh<<" "<<weight<<endl;

	}
	return array;
}


node * buildTree(my_da_array<node> array){ //I think that we might need to deal with the nodes of the tree directly. So I am changing this
												// to return the head node. Not a tree. The binary tree class may just go away...
	node * low1;
	node * low2;
	while(array.getRemaining()!=1){
		node * min1 = array.find_maxmin(false);// finds the 2 lowest weighted nodes.
		node * min2 = array.find_maxmin(false);
		//cout<<"Current min1: "<<min1->getWeight()<<endl;
		//cout<<"Current min2: "<<min2->getWeight()<<endl;
		double weight;
		weight = min1->getWeight() + min2->getWeight();
		node * head = new node(weight, min1, min2); //Creates a new node that connects the 2 lowest nodes that
		//has the weight of the 2 lowest nodes combined.
		//cout<<"Making new node with:\n\tWeight: "<<weight<<endl;
		array.da_push(*head);// Adds the new node to the list of all of the nodes.
		//cout<<"Remainder: "<<array.getRemaining()<<endl;

	}
	node * root = array.find_maxmin(false);
	//binaryTree tree = binaryTree(array.find_maxmin(false));
	return root;
}	


void genCode(char cur, node * root, string coded){// This will generate the code recursively.
	if(root->checkLeaf()){
		if(root->getVal() == cur){
			cout<<"Found "<<cur<<"!\nPath: "<<coded<<endl;
		}
	}
	if(root->hasLeft()){
		genCode(cur,root->getLeft(),coded+"0");
	}
	if(root->hasRight()){
		genCode(cur,root->getRight(),coded+"1");
	}
}
string incode(node *root){
	ifstream text;
	text.open("TextFile.txt");// this needs to be overwritten with a prompt.
	string coded;
	while(text){
		string line;
		getline(text, line);
		int length = line.length();
		for(int i = 0; i <length; i++){
			char currentletter = line[i];
			cout<<"Current Letter: "<<currentletter<<endl;
			string coded = "";
			genCode(currentletter,root,coded);
		}
	}
	return coded;
}




int main(){
	my_da_array<node> weights = readWeights();
	//binaryTree tree = buildTree(weights);
	node * root = buildTree(weights);
	incode(root);
	//string coded = incode(tree,weights);
	return 0;

}
