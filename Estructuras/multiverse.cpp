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
		Multiverse();
		Multiverse(Universe*,Universe*,Universe*);
		void addConn(int[]);
		
};

Multiverse::Multiverse(){
	Universe *newU = new Universe(616);	
	
	this->act = newU;
	this->act->setNext();
	this->act->getNext(0)->setNext();
	
}

//revisar, posible error cuando universos ya tengan conexiones
Multiverse::Multiverse(Universe* a,Universe* b,Universe* c){
	this->act = a;
	this->act->setNext(b,false,0);
	this->act->getNext(0)->setNext(c,false,0);
}


void Multiverse::addConn(int num[]){
	Universe *arr[6] = {NULL};
	for(int i=0;i<6;i++){
		Universe *newUniverse = new Universe(num[i]);
		
		arr[i] = newUniverse;
	}
	
	this->act->setNext(arr,true);
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
	
	//secU->setNext();
	
	
	Multiverse *a = new Multiverse();
	for(int i=0;i<6;i++){
		if(a->act->getNext(i)==NULL)cout<<"null: ";
		cout<<i<<" - "<<a->act->getNext(i)->getNumber()<<endl;
	}
	for(int i=0;i<6;i++){
		if(a->act->getNext(0)->getNext(i)==NULL)cout<<"null: ";
		cout<<i<<" - "<<a->act->getNext(0)->getNext(i)->getNumber()<<endl;
	}
	
	/*
	for(int i=0;i<6;i++){
		if(secU->getNext(i)==NULL)cout<<"null"<<endl;
		cout<<i<<" - "<<secU->getNext(i)->getNumber()<<endl;
		
	}
	cout<<"fin"<<endl;*/
	
	
}
