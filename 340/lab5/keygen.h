class keygen{
	private:
		string key;
		node * root;
		void makeKey(node*,string);

	public:
		keygen(node*);
};
keygen::keygen(node* root){
	using namespace std;
	root = root;
	key = "";
	makeKey(root,"");
	cout<<key<<endl;
};
void keygen::makeKey(node* root, string coded){
	if(root->checkLeaf() == true){
		char val = root->getVal();
		key = key + val + " " + coded + "\n";
	}
	if(root->hasLeft()){
		makeKey(root->getLeft(),coded+"0");
	}
	if(root->hasRight()){
		makeKey(root->getRight(),coded+"1");
	}
};
