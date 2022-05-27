#include <iostream>
#include <stdlib.h>
#include <string>
#include "universe.cpp"
#include "queue.cpp"



using namespace std;

class Multiverse
{
	public:
		Universe *act;
		int cant;
	public:
		Multiverse();
		Multiverse(Universe*,Universe*,Universe*);
		void addConn(int[]);
		void findNext(Universe*);
};

Multiverse::Multiverse(){
	Universe *newU = new Universe(616);	
	
	this->act = newU;
	this->act->setNext();
	this->act->getNext(0)->setNext();
	this->act->getNext(0)->getNext(0)->setNext(act);
}

//revisar, posible error cuando universos ya tengan conexiones
Multiverse::Multiverse(Universe* a,Universe* b,Universe* c){
	this->act = a;
	this->act->setNext(b,false,0);
	this->act->getNext(0)->setNext(c,false,0);
	this->act->getNext(0)->getNext(0)->setNext(act,false,0);
}

void Multiverse::addConn(int num[]){
	Universe *arr[6] = {NULL};
	for(int i=0;i<6;i++){
		Universe *newUniverse = new Universe(num[i]);
		
		arr[i] = newUniverse;
	}
	
	this->act->setNext(arr,true);
}

void Multiverse::findNext(Universe *universe){
	
	if(!universe->possNxt())return;
	
	Queue<Universe*> *colaAux = new Queue<Universe*>();
	
	colaAux->put(this->act);
	
	while(!colaAux->isEmpty()){
		Universe *uni = colaAux->getFront()->Data ;
		if(uni->possPrev() && uni->canBeNxt(universe)){
			universe->setNext(uni);
			return;
		}else{
			for(int i=0;i<6;i++){
				if(uni->getNext(i)!=NULL)colaAux->put(uni->getNext(i));
			}
		}
	}
	cout<<"No es posible"<<endl;
	return;
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
	a->act->getNext(0)->setNext(ejU);
	cout<<a->act->getNumber()<<endl;
	for(int i=0;i<6;i++){
		if(a->act->getNext(i)!=NULL)
		cout<<i<<" - "<<a->act->getNext(i)->getNumber()<<endl;
	}
	cout<<a->act->getNext(0)->getNumber()<<endl;	
	for(int i=0;i<6;i++){
		if(a->act->getNext(0)->getNext(i)!=NULL)
		cout<<i<<" - "<<a->act->getNext(0)->getNext(i)->getNumber()<<endl;
	}
	cout<<a->act->getNext(0)->getNext(0)->getNumber()<<endl;
	for(int i=0;i<6;i++){
		if(a->act->getNext(0)->getNext(0)->getNext(i)!=NULL)
		cout<<i<<" - "<<a->act->getNext(0)->getNext(0)->getNext(i)->getNumber()<<endl;
	}
	cout<<ejU->getNumber()<<endl;
	a->findNext(ejU);
	for(int i=0;i<6;i++){
		if(ejU->getNext(i)!=NULL)
		cout<<i<<" - "<<ejU->getNext(i)->getNumber()<<endl;
	}
	a->findNext(a->act);
	cout<<a->act->getNumber()<<endl;
	for(int i=0;i<6;i++){
		if(a->act->getNext(i)!=NULL)
		cout<<i<<" - "<<a->act->getNext(i)->getNumber()<<endl;
	}
	
	/*
	for(int i=0;i<6;i++){
		if(secU->getNext(i)==NULL)cout<<"null"<<endl;
		cout<<i<<" - "<<secU->getNext(i)->getNumber()<<endl;
		
	}
	cout<<"fin"<<endl;*/
	
	
}
