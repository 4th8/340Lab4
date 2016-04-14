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
	text.open("coded.txt");// this needs to be overwritten with a prompt.
	string coded;
	while(text){
		string line;
		getline(text, line);
		incodedText += line;
	}
	while(pos<=incodedText.length()){
		char c = incodedText[pos];
		genText(c,root);
		pos--;
	}
};

void decoder::genText(char c, node* n){
	pos = pos +1;
	cout<<c<< endl;
	if (n->checkLeaf()){
		decodedString += n->getVal();
	}
	else if(c == char('0')){
		c=incodedText[pos];
		genText(c, n->getLeft());
	}
	else if(c == char('1')){
		c=incodedText[pos];
		genText(c, n->getRight());
	}
	else if(c== NULL){
		pos = 99999;
	}
};

string decoder::getText(){
	return decodedString;
};
