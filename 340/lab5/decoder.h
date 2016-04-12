using namespace std;

class decoder{
	private:
		string decodedString;
		int pos;
		string incodedText;
		node * root;
	public:
		decoder(node*);
		void genText(char, node*);
		string getText();
};

decoder::decoder(node* root){
	decodedString="";
	incodedText = "";
	root = root;
	pos = 0;
	ifstream text;
	text.open("TextFile.txt");// this needs to be overwritten with a prompt.
	string coded;
	while(text){
		string line;
		getline(text, line);
		incodedText += line+"\n";
	}
	for(int i = 0; i<incodedText.length(); i++){
		char c = incodedText[i];
		genText(c,root);
	}
};

void decoder::genText(char c, node* n){
	if (n->checkLeaf()){
		decodedString += n->getVal();
		pos++;
	}
	else if(c == '0'){
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

string decoder::getText(){
	return decodedString;
};
