using namespace std;

class decoder{
	private:
		string decodedString;
		int pos;
		string incodedString;
	public:
		decoder();
		void genText(char, node*);
		string getText();
};

decoder::decoder(){
	decodedString="";
	incodedString = "";
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
	}
};



