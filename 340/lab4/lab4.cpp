// Team members: Nathanael Woodhaed the Great, Sophia Therriault, Mikaela Goldrich, maddy ernesto
#include <sstream>
#include <fstream>
#include <iostream>
#include <istream>
#include <string>
#include <stdlib.h>  
using namespace std;
template <typename T>
struct node{
	T info;
	node *prev;
	node *next;
	int index;
};

template <typename T>
class queue{
	private:
		struct node<T> *head;
		struct node<T> *tail;
		bool isempty;

	public:
		queue(){
			node<T> h;
			node<T> t;
			head = &h;
			tail = &t;
			isempty = true;
		}

		void push(T x){
			if(isempty){
				isempty = false;
			}
			node<T> *newnode = new node<T>;
			newnode->info = x;
			cout << "Set content" << endl;
			newnode->next = NULL;
			newnode->prev = tail;
			cout << "HERE" << endl;
			tail->next= newnode;
			tail = newnode;
		}

		T pop(){
			if(isempty){
				exit (EXIT_FAILURE);		
			}
			T top = head->info;
			node<T> *oldHead = head;
			head = head->prev;
			if(head == NULL){
				isempty = true;
			}
			return top;
		}
		T peak(){
			return head->info;
		}

		bool checkEmpty(){
			return isempty;
		}

		T getTail(){
			T bottom = tail->info;
			return bottom;
		}
};
template <typename T>
class list{
	private:
		node<T> *head;
		node<T> *tail;
		int size;

	public:
		list(){
			head = NULL;
			tail = NULL;
		}
		list(T content){
			node<T> temp;
			temp.info = content;
			temp.prev = NULL;
			head = &temp;
			tail = head;
		}
		void add(T content){
			node<T> temp;
			if(head == NULL || tail == NULL){
				head = &temp;
				tail = &temp;
			}
			cout<<"Here in add."<<endl;
			temp.info = content;
			temp.next = tail;
			tail = &temp;
			size++;
		}
		T getElement(int index){
			if (index == 0){
				return head->info;	
			} else if(index == size -1){
				return tail->info;
			} else{
				node<T> *current = head;
				for(int i=0; i < index; i++){
					current = current->next;
				}
				return current->info;
			}
		}
		T getLastElement(){
			return tail->info;
		}
};

class team{
	private:
		list<int> arrivalTimes;
		int numStops;
		bool isOut;
	public:
		string name;
		team(){};
		team(string n){
			name = n;
			numStops = 0;
			isOut = false;
		}
		void addTimes(int time){
			arrivalTimes.add(time);
			numStops++;
		}
		~team(){};
		string getName(){
			return name;
		}
		bool checkout(){
			return isOut;
		}
		void makeOut(){
			isOut = true;
		}
		int getTimes(){
			for(int i = 0; i<numStops; i++){
				int time = arrivalTimes.getElement(i);
			}
		}
		list<int> getLastTime(int length){
			return arrivalTimes;
		}
		int getCurrentTime(){
			return arrivalTimes.getLastElement();
		}
};

class game{
	private:
		int numberOfStops;
		queue<string> stops;
		queue<team>* teamTracker;
		list<team>* teamList;
		int numberOfTeams;

		void addTeam(team team){
			cout<<"Here in add Team."<<endl;
			teamList->add(team);
		}
		void dequeue(){
			teamTracker->pop();
		}

	public:
		game(){
		numberOfStops = 0;
		numberOfTeams = 0;
		
		}
		void loadStops(ifstream &file){	
			string line;
			while(file){
				getline(file, line);
				stops.push(line);
				cout<< "passed push"<< endl;
				numberOfStops++;
			}
		}
		void loadTeams(ifstream &file){
			teamList = new list<team>;	
			string line;
			while(file){
				getline(file, line);
				team temp = team(line);
				addTeam(temp);
				numberOfTeams++;
			}
		}
		int generateTime(){
			return(rand() % 24 + 5);
		}

		team getMin(){
			team min;
			int minTime=0;
			team currTeam;
			for(int i=0; i < numberOfTeams; i++){
				currTeam = teamList->getElement(i);
				if(!currTeam.checkout()){
					if(minTime == 0){
						minTime = currTeam.getCurrentTime();
						min = currTeam;
					} else if(currTeam.getCurrentTime() < minTime){
						minTime = currTeam.getCurrentTime();
						min = currTeam;
					}
				}
			}
			return min;
		}
		team getMin(int n){
			team min;
			team currTeam;
			int minTime=0;
			for(int i=0; i < numberOfTeams; i++){
				currTeam = teamList->getElement(i);
				if(!currTeam.checkout()){
					if(minTime == 0){
						minTime = currTeam.getCurrentTime();
						min = currTeam;
					}
					else if(currTeam.getCurrentTime() < minTime && currTeam.getCurrentTime() > n){
						minTime = currTeam.getCurrentTime();
						min = currTeam;
					}
				} 
			}
			return min;
		}

		queue<team> sort(){
			queue<team> *city = new queue<team>;
			int curTime;
			int min=0;
			team minTeam = getMin();
			min = minTeam.getCurrentTime();
			city->push(minTeam);
			for(int i=1; i<numberOfTeams; i++){
				team tempMin = getMin(min);
				min = tempMin.getCurrentTime();
				city->push(tempMin);
			}
			return *city;
		}
		void printResults(){
			string city;
			for(int i =0; i< numberOfStops; i++){
				cout<<stops.pop();
				for(int j=0; j<numberOfTeams; j++){
					team team = teamTracker->getTail();
					cout<< team.getName() << " was the last team to reach " << city << endl;
				}
			}
			cout<< "Teams\t\t";
			for(int i=1; i<numberOfStops; i++){
				cout<< "Round " << i << "\t";

			} cout<<endl;
			team  currTeam;
			for (int i=0; i <numberOfTeams; i++){
				currTeam = teamList->getElement(i);
				cout<< currTeam.getName()<<"\t"<<currTeam.getTimes()<<endl;
			}
		}
		void run(){
				cout<<"Here in run."<<endl;
				cout<<numberOfStops<<endl;
			for(int i = 0; i < numberOfStops; i++){
				queue<team> thisCity = sort();
				cout<<"The "<<thisCity.getTail().getName()<<" was the last to get to "<<stops.pop()<<"."<<endl;
				thisCity.getTail().makeOut();
			}
		}
};

int main(){
	string filename;
	cout<<"Please enter the filename for the cities."<<endl;
	cin>>filename;
	ifstream inputCities;
	inputCities.open(filename.c_str(),ios::in);
	cout<<"Please enter the filename for the teams." <<endl;
	cin>>filename;
	ifstream inputTeams;
	inputTeams.open(filename.c_str(),ios::in);
	cin.ignore();
	game theGame;
	cout <<"MADE GAME" << endl;
	theGame.loadStops(inputCities);
	cout<<"Load Stops Works"<<endl;
	theGame.loadTeams(inputTeams);
	cout << "ALL LOADED IN" << endl;
	theGame.run();
	return 0;
}
