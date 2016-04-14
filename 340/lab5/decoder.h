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
	}
};

void decoder::genText(char c, node* n){
	cout<<c<< endl;
	if (n->checkLeaf()){
		decodedString += n->getVal();
	}
	else if(c == char('0')){
		c=incodedText[pos+1];
		genText(c, n->getLeft());
	}
	else if(c == char('1')){
		c=incodedText[pos+1];
		genText(c, n->getRight());
	}
	else{
		cout<<"you messed up"<<endl;
		pos = 99999;
	}
};

string decoder::getText(){
	return decodedString;
};
