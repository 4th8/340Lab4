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
			tail = &tail;	
		}


};
class team{
	private:
		queue<int> arrivalTimes;
		int mins(){
			return rand() % 1440 + 300;
		}

	public:
		string name;
		team(){};
		team(int numOfStops,string n){
			for(int i = 0; i<numOfStops; i++){
				int time = mins();
				arrivalTimes.push(time);
			}
			name = n;
		}
		~team(){};
		string getName(){
			return name;
		}
		int getTime(){
			return(arrivalTimes.pop());
		}

};

class game{
	private:
		int numberOfStops;
		queue<string> stops;
		team *teams;
		int numberOfTeams;



		void addTeam(team teamname){
			int new_size = numberOfTeams + 1;
			team *newarr  = new team[new_size];
			for(int i = 0; i < numberOfTeams; i++){
				newarr[i] = teams[i];
			}
			newarr[numberOfTeams] = teamname;
			teams = newarr;
		}
		void removeTeam(team teamname){
			int new_size = numberOfTeams - 1;
			team *newarr = new team[new_size];
			int skiped;
			for (int i = 0; i < numberOfTeams; i++){
				if (teams[i].getName() == teamname.getName()){
					skiped = i;
					break;
				}
			}
			for(int i = 0; i < skiped; i++){
				newarr[i] = teams[i];
			}
			for (int i = skiped; i< numberOfTeams; i++){
				newarr[i] = teams[i];
			}
			delete[] teams;
			teams = newarr;
		}

	public:
		game(){
			teams = new team();
			string filename;
			numberOfTeams = 0;
			numberOfStops = 0;
			cout<<"Please enter the filename for the stops."<<endl;
			cin>>filename;
			cout<<"Thank you"<<endl;
			ifstream inputFile;
			inputFile.open(filename.c_str(),ios::in);
			cin.ignore();
			string line;
			while(inputFile){
				getline(inputFile, line);
				stops.push(line);
				numberOfStops++;
			}
			cout<<"Please enter the filename for the teams."<<endl;
			cin>>filename;
			cout<<"Thank you"<<endl;
			cout<<"I am done with you."<<endl;
			ifstream inputFile1;
			inputFile1.open(filename.c_str(),ios::in);
			cin.ignore();
			while(inputFile1){
				getline(inputFile1, line);
				cout<< line << endl;
				team temp = team(numberOfStops, line);
				cout << temp.getName() << endl;
				addTeam(temp);
				numberOfTeams++;
			}

		}
		void takeTurn(){
			if(!stops.checkEmpty()){
				string city = stops.pop();
				string loser;
				int time = 0;
				for(int i =0; i<numberOfTeams;i++){
					team temp = teams[i];
					int thisTime = temp.getTime();
					if(thisTime > time){
						time = thisTime;
						loser = temp.getName();	
					}
				}



			}
		}
};

int main(){
game();


}
