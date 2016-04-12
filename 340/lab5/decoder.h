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
	while(pos<incodedText.length()){
		char c = incodedText[pos];
		genText(c,root);
	}
};

void decoder::genText(char c, node* n){
	cout<<c<<endl;
	if (n->checkLeaf()){
		decodedString += n->getVal();
		pos++;
	}
	else if(c == char('0')){
		cout<<"here"<<endl;
		pos++;
		c=incodedText[pos];
		genText(c, n->getLeft());
	}
	else if(c == char('1')){
		pos++;
		c=incodedText[pos];
		genText(c, n->getRight());
	}
	else{
		cout<<"you messed up"<<endl;
		pos = 99999999999;
	}
};

string decoder::getText(){
	return decodedString;
};
