#include "my_da_array.cpp"
#include "encoder.h"
#include <sstream> // Needed for stringstream
#include <stdlib.h>
#include "keygen.h"
#include "decoder.h"
#include "calculateWeights.h"
using namespace std;

my_da_array<node*> readWeights(){
	my_da_array<node*> array;
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
		array.da_push(currentNode);
	}
	return array;
}
node * buildTree(my_da_array<node*> array){ //I think that we might need to deal with the nodes of the tree directly. So I am changing this
												// to return the head node. Not a tree. The binary tree class may just go away...
	while(array.getRemaining()!=1){
		node * min1 = array.find_maxmin(false);// finds the 2 lowest weighted nodes.
		node * min2 = array.find_maxmin(false);
		double weight;
		weight = min1->getWeight() + min2->getWeight();
		node * head = new node(weight, min1, min2); //Creates a new node that connects the 2 lowest nodes that
		//has the weight of the 2 lowest nodes combined.
		array.da_push(head);// Adds the new node to the list of all of the nodes.
	}
	node * root = array.find_maxmin(false);
	return root;
}	

int main(){
	calculateWeights();
	cout<<"Done with calculateWeights"<<endl;
	my_da_array<node*> weights = readWeights();
	cout<<"Done with readWeights"<<endl;
	node * root = buildTree(weights);
	cout<<"Done with buildTree"<<endl;
	encoder encode = encoder();
	cout<<"Done with encoder"<<endl;
	keygen k = keygen(root);
	cout<<"Done with keygen"<<endl;
	string key = k.getKey();
	string encoded = encode.incode(root);
	cout<<"Done with incode(root)"<<endl;
	cout<<encoded<<endl;
	decoder d = decoder(root);
	cout<<"Done with decoder"<<endl;
	string decoded = d.getText();
	cout<<decoded<<endl;
	
	return 0;

}
