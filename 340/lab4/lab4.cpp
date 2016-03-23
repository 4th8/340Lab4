// Team members: Nathanael Woodhaed, Sophia Therriault, Mikaela Goldrich, maddy ernesto
#include <sstream>
#include <fstream>
#include <iostream>
#include <istream>
#include <string>
#include <stdlib.h>  
using namespace std;
template <typename T>
class queue{
	private:
		struct node {
			T info;
			node *prev;
			node *next;
		};

		node *head;
		node *tail;
		bool isempty;

	public:
		queue(){
			node h;
			node t;
			head = &h;
			tail = &t;
			isempty = true;
		}

		void push(T x){
			if(isempty){
				isempty = false;
			}
			node *newnode = new node;
			newnode->info = x;
			newnode->next = tail;
			newnode->prev = NULL;
			tail->prev = newnode;
			tail = newnode;
		}

		T pop(){
			if(isempty){
				exit (EXIT_FAILURE);		
			}
			T top = head->info;
			node *oldHead = head;
			head = head->prev;
			if(head == NULL){
				isempty = true;
			}
			return top;
		}
		bool checkEmpty(){
			return isempty;
		}
};
template <typename T>
class list{
	private:
		struct listNode{
			int index;
			T info;
			listNode *prev;
			listNode *next;
		};
		listNode *head;
		listNode *tail;

	public:
		list(){
			head = NULL;
			tail = NULL;
		}
		list(T content){
			listNode temp;
			temp.info = content;
			temp.index = 0;
			temp.prev = NULL;
			head = &temp;
			tail = head;
		}
		void add(T content){
			listNode temp;
			temp.info = content;
			temp.index = tail->index + 1;
		       	temp.prev = tail;
			temp.next = NULL;
			tail->next = &temp;
		//	tail = &tail;	
		}
		T getElement(int index){
			int current = head->index;
			listNode cur = *head;
			while(current != index){
				cur = *cur.next;
				current = cur.index;
			}
			return cur.info;
		}
		void removeElement(int index){
			int current = head->index;
			listNode cur = *head;
			while(current != index){
				cur = *cur.next;
				current = cur.index;
			}
			listNode *last = cur.prev;
			listNode *n = cur.next;
			last->next = cur.next;
			n->prev = cur.prev;
			delete cur;
		}







};
class team{
	private:
		list<int> arrivalTimes;
		int numStops;
	public:
		string name;
		team(){};
		team(string n){
			name = n;
			numStops = 0;
		}
		void addTimes(int time){
				arrivalTimes.add(time);
				numStops++;
		}
		~team(){};
		string getName(){
			return name;
		}
		int printTimes(){
			cout<< name<< "     ";
			for(int i = 0; i<numStops; i++){
				int time = arrivalTimes.getElement(i);
				cout<< "     " << time;
			}
			cout<<"\n";
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
			teamList->add(team);
		}
		void dequeue(){
			teamTracker->pop();
		}
		
		int createTime(){
			return(rand() % 24 + 5);
		}
	public:
		game(){
			teamTracker = new queue<team>;
			teamList = new list<team>;	
		}
		void loadStops(ifstream &file){	
			string line;
			while(file){
				getline(file, line);
				cout<< line << endl;
				stops.push(line);
				numberOfStops++;
			}
			cout<< "DONE ADDING STOPS" << endl;
		}
		void loadTeams(ifstream &file){
			string line;
			while(file){
				getline(file, line);
				cout<< line << endl;
				team temp = team(line);
				addTeam(temp);
				numberOfTeams++;
			}
			cout << "DONE ADDING TEAMS" << endl;
		}
		void takeTurn(){
			if(!stops.checkEmpty()){
				string city = stops.pop();
				string loser;
				for(int i=0; i<numberOfStops; i++){
					team temp = teamTracker->pop();
					int time = createTime();
					temp.addTimes(time);
						
				}
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
	game* theGame = new game();
	theGame->loadStops(inputCities);
	theGame->loadTeams(inputTeams);

}
