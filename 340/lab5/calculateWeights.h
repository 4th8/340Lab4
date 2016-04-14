class calculateWeights{
		struct character{
			char c;
			double count;
		};
	private:
		int curLen;
		double total;
			
		character * characters;
	public:
		calculateWeights();
		void print();
		void checkCharacters(char);
};
calculateWeights::calculateWeights(){
	curLen = 0;
	total = 0;
	characters = new character[127];//One slot for each of the 127 characters in ascii.
	ifstream text;
	text.open("InFile.txt");// this needs to be overwritten with a prompt.
	string coded;
	while(text){
		string line;
		getline(text, line);
		for(int i = 0; i < line.length(); i++){
			checkCharacters(line[i]);
			total++;
		}
	}
	print();
};
void calculateWeights::checkCharacters(char x){
	if (curLen == 0)
		curLen = 1;
	bool found = false;
	for(int i = 0; i<curLen; i++){
		if (x == characters[i].c){
			characters[i].count++;
			found = true;
		}
	}
	if(!found){
		characters[curLen-1].c = x;
		characters[curLen-1].count = 1;
		curLen++;
	}
};
void calculateWeights::print(){
	ofstream weightfile;
	weightfile.open("weights.txt");
	for(int i = 0; i < curLen-1; i++){
		string text;
		text = characters[i].c;
		text += " ";
		double z = characters[i].count/total;
		weightfile<<text<<z<<endl;
	}
};
