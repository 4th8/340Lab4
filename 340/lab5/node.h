#include "data.h"
using namespace std;
class node{
	
	private:
		data d;
		node *left;
		node *right;
		bool isLeaf;
		bool used;

	public:

		node(){}

		node(char x, double w){
			d = data(x,w);
			left = NULL;
			right = NULL;
			isLeaf = true;
		}

		node(double weight, node *l, node *r){
			d = data(weight);
			left = l;
			right = r;
			isLeaf = false;
		}

		bool hasLeft(){
			if(left){
				return true;
			}
			return false;
		}
		bool hasRight(){
			if(right){
				return true;
			}
			return false;
		}

		bool checkLeaf(){
			cout<<"Is leaf: "<<isLeaf<<endl;
			return isLeaf;
		}
		char getVal(){
			return d.getVal();
		}
		
		node* getRight(){
			return right;
		}
		
		node* getLeft(){
			return left;
		}
		void use(){
			used = true;
		}
		bool getused(){
			return used;
		};
		double getWeight(){
			return d.getWeight();
		}
};
