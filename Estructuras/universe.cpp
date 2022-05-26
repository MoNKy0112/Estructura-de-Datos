#include <stdlib.h>
#include "universe.h"
#include <cstdlib>

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

//setNext
void Universe::setNext(){
	Universe* newU = new Universe(0);
	
	int number;
	do{
		number = rand() %2000000 + 999;	
		newU->setNumber(number);	
	}while(!canBeNxt(newU));
	
	newU->setPrev(this);
	this->Nxt[0]=newU;
	return;
		
}

void Universe::setNext(Universe* universe,bool rewrite,int number=-1){
	if(canBeNxt(universe)){
		if(rewrite){
			
			//rewrite incompleto - reanidar los universos enlazados
			if(number==-1){
				Nxt[rand()%6] = universe;
			}else{
				this->Nxt[number] = universe;
			}
			return;
		}else{
			if(number==-1){
				for(int i=0;i<6;i++){
					if(Nxt[i]==NULL){
						universe->setPrev(this);
						Nxt[i] = universe;
						return;
					}
				}
			}else if(this->Nxt[number]==NULL){
				universe->setPrev(this);
				this->Nxt[number] = universe;
				return;
			}	
		}
	}
	cout<<"NO DISPONIBLE PARA CONEXION"<<endl;
	return;
}
	
//FUNCION INCOMPLETA
void Universe::setNext(Universe *universes[] , bool rewrite){
		
		for(int i=0;i<6;i++){
			
		}
		
		for(int i=0;i<6;i++){
			//cout<<i<<endl;
			//cout<<universes[i]->getNumber()<<endl;
			
			
			Nxt[i] = universes[i];
		}
	
	
}

void Universe::setPrev(Universe *universe){
	for(int i=0;i<6;i++){
		if(this->Prev[i]==NULL){
			Prev[i]=universe;	
			return;
		}
	}
	cout<<"NO HAY ESPACIO PARA CONECTAR"<<endl;
	return;
}

//FUNCION INCOMPLETA
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

bool Universe::canBeNxt(Universe* uni){
	for(int i=0;i<6;i++){
		if(this->Prev[i]==uni)return false;
	}
	for(int i=0;i<6;i++){
		if(this->Nxt[i]==uni)return false;
	}
	return true;
}

bool Universe::possPrev(){
	for(int i=0;i<6;i++){
		if(this->Prev[i]==NULL)return true;
	}
	return false;
}

bool Universe::possNxt(){
	for(int i=0;i<6;i++){
		if(this->Nxt[i]==NULL)return true;
	}
	return false;
}

