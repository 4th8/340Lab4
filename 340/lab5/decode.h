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
	ifstream text;
	text.open("TextFile.txt");// this needs to be overwritten with a prompt.
	string coded;
	while(text){
		string line;
		getline(text, line);
		int length = line.length();
		for(int i = 0; i <length; i++){
			char currentletter = line[i];
			string coded = "";
			genCode(currentletter,root,coded);
		}
	}
	return encodedString;

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



