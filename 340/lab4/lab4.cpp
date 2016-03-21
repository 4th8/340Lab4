// Team members: Nathanael Woodhaed, Sophia Therriault, Mikaela Goldrich, maddy ernesto
#include <sstream>
#include <fstream>
#include <iostream>
#include <istream>
#include <string>
#include <stdlib.h>  
using namespace std;
template <typename T>
class array{
	private: 
		int size;
		T *arr;

	public:
			array(){
				arr = new T[1];
				*size = 0;
		}

		void push(T content){
			int new_size = size + 1;
			T *newarr  = new int[new_size];
			for(int i = 0; i < size; i++){
				newarr[i] = arr[i];
			}
			newarr[size] = content;
			size = new_size;
			delete[] arr;
			arr = newarr;
		}


		//pop removes the last int in the array
		void remove(int i){
			int newsize = size - 1;
			int * newarr  = new int[newsize];
			for(int i = 0; i < newsize; i++){
				newarr[i] = ptr[i];
			}
			size = newsize;
			delete[] arr;
			arr = newarr;
			return content;
		}
};
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
			head = NULL;
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
				return "";
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




class team{
	private:
		queue<int> arrivalTimes;
		int mins(){
			return rand() % 1440 + 300;
		}

	public:
		string name;
		team(int numOfStops){
			for(int i = 0; i<numOfStops; i++){
				int time = mins();
				arrivalTimes.push(time);
			}
		}
};

class game{
	private:
		int numOfTeams = 0; 
		queue<string> stops;
		array teams;
	public:
		game(){
			string filename;
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
				teams.push(line);
				numOfTeams++;
			}

		}
		void takeTurn(){
			if(!stops.checkEmpty()){
				string city = stops.pop();
				string loser;
				int time = 0;
				for(int i =0; i<numOfTeams;i++){
					team temp = teams.pop();
					if(temp.arrivalTimes> time){
						time = temp.arrivalTimes;
						loser = temp.name;	
					}
				}



			}
		}
};

int main(){
}
