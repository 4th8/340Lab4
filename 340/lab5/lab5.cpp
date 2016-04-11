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
		cout<<"making node with: "<<hh<<" "<<weight<<endl;
		
	}
	return array;

}
binaryTree buildTree(my_da_array<node> array){
	node * low1;
	node * low2;
	while(array.getRemaining()!=1){
		node * min1 = array.find_maxmin(false);// finds the 2 lowest weighted nodes.
		node * min2 = array.find_maxmin(false);
		cout<<"Current min1: "<<min1->getWeight()<<endl;
		cout<<"Current min2: "<<min2->getWeight()<<endl;
		node * head = new node((min1->getWeight() + min2->getWeight()), min1, min2); //Creates a new node that connects the 2 lowest nodes that
																					 //has the weight of the 2 lowest nodes combined.
		array.da_push(*head);// Adds the new node to the list of all of the nodes.
		cout<<"Remainder: "<<array.getRemaining()<<endl;
		
	}
	binaryTree tree = binaryTree(array.find_maxmin(false));
	return tree;
}

string incode(binaryTree tree,my_da_array<node> weights){
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
			double weight;
			for(int i = 0; i < weights.get_size(); i++){
				if(currentletter == weights.get_elem(i).getVal()){
					weight = weights.get_elem(i).getWeight();
					break;
				}
			}
			cout<<"Current Letter weight: "<<weight<<endl;
			cout<<"Current Node weight: "<<tree.rightWeight()<<endl;
			bool found = false;
			while(!found){
				if(tree.leftWeight() >= weight){
					tree.goLeft();
					cout<<"Gone Left"<<endl;
					coded += "0";
					if(tree.isLeaf()){
					if(tree.getVal() == currentletter){
						cout<<"Found"<<endl;
						found = true;
						tree.reset();
					}
					}
				}
				else{
					tree.goRight();
					cout<<"Gone Right"<<endl;
					coded += "1";
					if(tree.isLeaf() && tree.getVal() == currentletter){
						found = true;
						cout<<"Found"<<endl;
						tree.reset();
					}
				}
			}
		}
	}
	return coded;
}



int main(){
	my_da_array<node> weights = readWeights();
	binaryTree tree = buildTree(weights);
	string coded = incode(tree,weights);
	cout<<coded<<endl;
	return 0;

}
