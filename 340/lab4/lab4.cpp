// Team members: Nathanael Woodhaed, Sophia Therriault, Mikaela Goldrich, maddy ernesto
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
			node<T> *oldHead = head;
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
			node<T> *temp = new node<T>;
			temp->info = content;
		    temp->next = head;
			head = temp;
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
		void removeElement(int index){
			int current = head->index;
			node<T> cur = *head;
			while(current != index){
				cur = *cur.next;
				current = cur.index;
			}
			node<T> *last = cur.prev;
			node<T> *n = cur.next;
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
		int getTimes(){
			for(int i = 0; i<numStops; i++){
				int time = arrivalTimes.getElement(i);
			}
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
		}
		void loadStops(ifstream &file){	
			string line;
			while(file){
				getline(file, line);
				stops.push(line);
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
