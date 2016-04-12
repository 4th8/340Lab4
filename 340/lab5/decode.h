using namespace std;

class decoder{
	private:
		string decodedString;
		int pos;
		string incodedString;
		node * root;
	public:
		decoder(node*);
		void genText(char, node*);
		string getText();
};

decoder::decoder(node* root){
	decodedString="";
	incodedString = "";
	root = root;
	pos = 0;
	ifstream text;
	text.open("TextFile.txt");// this needs to be overwritten with a prompt.
	string coded;
	while(text){
		string line;
		getline(text, line);
		incodedString += line+"\n";
	}
	return incodedString;

};

void decoder::genText(char c, node* n){
	if (n->isLeaf()){
		decodedString += n->getVal();
		pos++;
	}
	else if(c == "0"){
		pos++;
		c=incodedText[pos];
		genText(c, n->getLeft());
	}
	else{
		pos++;
		c=incodedText[pos];
		genText(c, n->getRight());
	}
};

string getText(){
	return decodedString;
};
