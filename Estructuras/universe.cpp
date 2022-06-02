#include <stdlib.h>
#include "universe.h"
#include <cstdlib>


//Universe sigue la idea de un Nodo pero fue creado para facilitar el movimiento entre siguientes y previos
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

//---------------------Setters-------------------------//

void Universe::setNumber(int num){
	this->Number=num;
}

//*****************setNext***************//
void Universe::setNext(){
	Universe* newU = new Universe(0);
	
	int number;
	do{
		number = rand() %2000000 + 999;	
		newU->setNumber(number);	
	}while(!canBeNxt(newU));
	
	for(int i=0;i<6;i++){
		if(Nxt[i]==NULL){
			newU->setPrev(this);
			Nxt[i] = newU;
			return;
		}
	}
		
}

void Universe::setNext(Universe* universe,int number=-1){
	if(canBeNxt(universe)){
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
	cout<<"NO DISPONIBLE PARA CONEXION"<<endl;
	return;
}

//******************setPrev******************//
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

//---------------------Getters-------------------------//
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
//--------------------Delete----------------------------//
void Universe::deleteUniverse(){
	for(int i=0;i<6;i++){
		for(int j=0;j<6;j++){
			if(this->Nxt[i]!=NULL){
				if(this->Nxt[i]->Prev[j]==this)this->Nxt[i]->Prev[i]=NULL;
			}
			if(this->Prev[i]!=NULL){
				if(this->Prev[i]->Nxt[j]==this)this->Prev[i]->Nxt[i]=NULL;
			}
		}
	}
	free(this);
}


//--------------Ayuda para verificar conexiones------//

//Verifica si un Nodo puede ser siguiente de this->universe
bool Universe::canBeNxt(Universe* uni){
	for(int i=0;i<6;i++){
		if(this->Prev[i]==uni){
			return false;
		}
	}
	for(int i=0;i<6;i++){
		if(this->Nxt[i]==uni){
			return false;
		}
	}
	if(this==uni)return false;
	return true;
}

//Verifica si existe espacio en Prev[]
bool Universe::possPrev(){
	for(int i=0;i<6;i++){
		if(this->Prev[i]==NULL)return true;
	}
	return false;
}

//Verifica si hay espacio en Nxt[]
bool Universe::possNxt(){
	for(int i=0;i<6;i++){
		if(this->Nxt[i]==NULL)return true;
	}
	return false;
}

//verifica si la posible destruccion desate un error de universos sin conexiones (universos anteriores)
Universe* Universe::possDelPrevError(){
	int cPrev=0;
	for(int i=0;i<6;i++){
		for(int j=0;j<6;j++){
			if(this->Prev[i]!=NULL){
				if(this->Prev[i]->Nxt[j]!=NULL && this->Prev[i]->Nxt[j]!=this)cPrev++;
			}
		}	
		if(cPrev ==0){
			cout<<"Universo:"<<Prev[i]->getNumber()<<" quedaria sin conexiones Nxt"<<endl;
			return Prev[i];
		}
	}
	return NULL;
}

//verifica si la posible destruccion desate un error de universos sin conexiones (universos posteriores)
Universe* Universe::possDelNxtError(){
	int cNxt=0;
	for(int i=0;i<6;i++){
		for(int j=0;j<6;j++){
			if(this->Nxt[i]!=NULL){
				if(this->Nxt[i]->Prev[j]!=NULL && this->Nxt[i]->Prev[j]!=this)cNxt++;		
			}
		}	
		if(cNxt ==0){
			cout<<"Univesro:"<<Nxt[i]->getNumber()<<" quedaria sin conexiones Prev"<<endl;
			return Nxt[i];
		}
	}
	return NULL;
}


