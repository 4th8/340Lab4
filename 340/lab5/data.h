class data{	
	public:
		data(){}
		data(char c, double w){
			value = c;
			weight = w;
		}
		
		data(double w){

			weight = w;
		}
		double getWeight(){
			return weight;
		}
		char getVal(){
			return value;
		}


	private:
		char value;
		double weight;
};
