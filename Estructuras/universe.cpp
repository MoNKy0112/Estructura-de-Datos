#include <stdlib.h>
#include "universe.h"

Universe::Universe(){
	this->Number = 0;
	
	for(int i=0;i<6;i++){
		this->Nxt[i] = NULL;
		this->Prev[i] = NULL;
	}
}

Universe::Universe(int num){
	this->Number = num;
	
	for(int i=0;i<6;i++){
		this->Nxt[i] = NULL;
		this->Prev[i] = NULL;
	}
}

void Universe::setNumber(int num){
	this->Number=num;
}
	
void Universe::setNext(Universe *universes[] , bool rewrite){
	
		for(int i=0;i<6;i++){
			//cout<<i<<endl;
			//cout<<universes[i]->getNumber()<<endl;
			
			
			Nxt[i] = universes[i];
		}
	
	
}

void Universe::setPrev(Universe* universes[],bool rewrite){
	if(rewrite){
		for(int i=0;i<6;i++){
			this->Prev[i] = universes[i];
		}
	}else{
		//actual = this->getPrev();
		for(int i=0;i<6;i++){
			this->Prev[i] = universes[i];
		}
	}
}

int Universe::getNumber(){
	if(this != NULL)
	return this->Number;
}

Universe* Universe::getNext(int i){
	return this->Nxt[i];	
}

Universe* Universe::getPrev(int i){
	return this->Prev[i];
}

