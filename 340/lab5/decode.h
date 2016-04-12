using namespace std;

class decoder{
	private:
		string decodedString;
		int pos;
	public:
		decoder();
		void genText(char, node*);
		string getText();
};

decoder::decoder(){
	decodedString="";
	pos = 0;
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
