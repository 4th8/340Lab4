#include "node.h"
class binaryTree{
	public:	
		binaryTree(){
		}
		binaryTree(node *h);
		void reset();
		void goLeft();
		void goRight();
		bool rightLeaf();
		bool leftLeaf();
		bool isLeaf();
		char getVal();
		char checkRight();
		char checkLeft();
		double rightWeight();
		double leftWeight();
		double getWeight();

	private:
		node *head;
		node *current;
};
void binaryTree::reset(){
	current = head;
}

char binaryTree::checkLeft(){
	return current->getLeft()->getVal();
}
bool binaryTree::rightLeaf(){
	return current->getRight()->checkLeaf();
}
bool binaryTree::leftLeaf(){
	return current->getLeft()->checkLeaf();
}
bool binaryTree::isLeaf(){
	return current->checkLeaf();
}

void binaryTree::goLeft(){
	current = current->getLeft();
}
void binaryTree::goRight(){
	current = current->getRight();
}
binaryTree::binaryTree(node  * h){
	head = h;
	current = h;
}
char binaryTree::getVal(){
	return current->getVal();
}
char binaryTree::checkRight(){
	return current->getRight()->getVal();
}
double binaryTree::rightWeight(){
	return current->getRight()->getWeight();
}
double binaryTree::leftWeight(){
	return current->getLeft()->getWeight();
}
double binaryTree::getWeight(){
	return current->getWeight();
}
