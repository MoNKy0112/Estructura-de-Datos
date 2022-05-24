#include <iostream>
#include <stdlib.h>
#include <string>
#include "universe.cpp"

using namespace std;

class Multiverse
{
	public:
		Universe *act;
	public:
		void addConn(int[]);
		
};




void Multiverse::addConn(int num[]){
	for(int i=0;i<6;i++){
		Universe *newUniverse = new Universe(num[i]);
		
	}
	
	newUniverse->setNext();
}

int main(){
	
	
	
	Universe *newU = new Universe(5); 
	
	Universe *secU = new Universe(7);
		
	Universe *ejU = new Universe(9);
	
	Universe *arr[6] = {NULL};
	
	arr[0]=ejU;
	arr[4]=ejU;	
	//cout<<arr[0]->getNumber();
	
	secU->setNext(arr,true);
	
	//secU->getNext(0);
	

	for(int i=0;i<6;i++){
		cout<<i<<" - "<<secU->getNext(i)->getNumber()<<endl;
	}
	cout<<"fin"<<endl;
	
	
}
