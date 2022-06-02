#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include "multiverse.h"



using namespace std;

//Crear de multiverso Default --Crea Universos iniciales--
Multiverse::Multiverse(){
	Universe *newU = new Universe(616);	
	
	this->act = newU;
	this->act->setNext();
	this->act->getNext(0)->setNext();
	this->act->getNext(0)->getNext(0)->setNext(act);
	this->cant=3;
}

//revisar, posible error cuando universos ya tengan conexiones
Multiverse::Multiverse(Universe* a,Universe* b,Universe* c){
	this->act = a;
	this->act->setNext(b,0);
	this->act->getNext(0)->setNext(c,0);
	this->act->getNext(0)->getNext(0)->setNext(act,0);
	this->cant=3;
}

//Crea universo aleatorio y lo adhiere al multiverso --Posicion aleatoria--
void Multiverse::addConn(){
	
	Queue<Universe*> *colaAux = new Queue<Universe*>();
	
	colaAux->put(this->act);
	
	while(!colaAux->isEmpty()){
		Universe *uni = colaAux->getFront()->Data ;
		if(uni->possNxt() ){
			uni->setNext();
			this->cant++;
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

//Adhiere universo existente al multiverso --Posicion aleatoria--
void Multiverse::addConn(Universe* nxtUni){
	
	if(!nxtUni->possPrev())return;
	
	Queue<Universe*> *colaAux = new Queue<Universe*>();
	
	colaAux->put(this->act);
	
	while(!colaAux->isEmpty()){
		Universe *uni = colaAux->getFront()->Data ;
		if(uni->possNxt() ){
			uni->setNext(nxtUni);
			this->cant++;
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

//Adhiere conexion entre dos universos (Usar con universos ya anhidados al multiverso)
void Multiverse::addConn(Universe* nxtUni,Universe* prevUni){
	
	if(!nxtUni->possPrev() || !prevUni->possPrev())return;
	
	prevUni->setNext(nxtUni);
	this->cant++;
	
	return;
}

//Encuentra una posible conexion Nxt al Universo
Universe* Multiverse::findNext(Universe *universe){
	
	if(!universe->possNxt())return NULL;
	
	Queue<Universe*> *colaAux = new Queue<Universe*>();
	bool add=true;
	int cont=1;
	
	colaAux->put(this->act);
	vector <Universe* > arr;
	arr.push_back(this->act);
	
	while(!colaAux->isEmpty()){
		Universe *uni = colaAux->getFront()->Data;
		colaAux->remove();
		if(uni->possPrev() && uni->canBeNxt(universe)){
			//universe->setNext(uni);
			return uni;
		}else{
			if(cont!=this->cantidad()){
				for(int i=0;i<6;i++){
					add=true;
					if(uni->getNext(i)!=NULL){
						for(int j=0;j<arr.size();j++){
							if(arr[j]==uni->getNext(i))add=false;
						}
						if(add){
							arr.push_back(uni->getNext(i));
							colaAux->put(uni->getNext(i));
							cont++;	
						}
					}
				}
			}
		}
	}
	cout<<"N No es posible"<<endl;
	return NULL;
}

//Encuentra posible conexion Prev al Universo
Universe* Multiverse::findPrev(Universe *universe){
	
	if(!universe->possPrev())return NULL;
	
	Queue<Universe*> *colaAux = new Queue<Universe*>();
	bool add=true;
	int cont=1;
	
	colaAux->put(this->act);
	vector <Universe* > arr;
	arr.push_back(this->act);
	
	while(!colaAux->isEmpty()){
		Universe *uni = colaAux->getFront()->Data ;
		colaAux->remove();
		if(uni->possNxt() && universe->canBeNxt(uni)){
			//uni->setNext(universe);
			return uni;
		}else{
			if(cont!=this->cantidad()){
				for(int i=0;i<6;i++){
					add=true;
					if(uni->getNext(i)!=NULL){
						for(int j=0;j<arr.size();j++){
							if(arr[j]==uni->getNext(i))add=false;
						}
						if(add){
							arr.push_back(uni->getNext(i));
							colaAux->put(uni->getNext(i));
							cont++;	
						}
					}
				}
			}
		}
	}
	cout<<"P No es posible"<<endl;
	return NULL;
}

//Añade universo --posicion aleatoria--
void Multiverse::addUniv(Universe* uni){
	
	if(this->findPrev(uni)!=NULL && this->findNext(uni)!=NULL){
		this->findPrev(uni)->setNext(uni);
		uni->setNext(this->findNext(uni));
	}
	this->cant++;
	return;
}

//Añade universo -- con cierta conexion establecida --(aun no implementada)
void Multiverse::addUniv(Universe* uni,Universe* prev,Universe* nxt=NULL){
	
	if(prev->possNxt() && prev->canBeNxt(uni)){
		if(nxt==NULL && this->findNext(uni)!=NULL){
			prev->setNext(uni);
			uni->setNext(this->findNext(uni));
		}else if(nxt!=NULL && nxt->possPrev() ){
			prev->setNext(uni);
			uni->setNext(nxt);
		}
	}
	this->cant++;
	return;
}

//elimina un universo, los universos 
void Multiverse::clearUniverse(Universe* uni){
	Universe *prev = uni->possDelPrevError();
	Universe *nxt = uni->possDelNxtError();
	
	if(this->cantidad()>3){	
		while(nxt!=NULL || prev!=NULL){
			if(nxt==NULL && prev!=NULL){
				this->findNext(prev);
			}
			if(nxt!=NULL && prev==NULL){
				this->findPrev(nxt);
			}
			if(nxt!=NULL && prev!=NULL){
				clearConn(nxt,prev);
				prev->setNext(nxt);
			}
			
			
			prev = uni->possDelPrevError();
			nxt = uni->possDelNxtError();
		}
		uni->deleteUniverse();
		this->cant--;
		
		return;
	}
	cout<<"EL MULTIVERSO ES DEMASIADO PEQUEÑO PARA ELIMINAR UN UNIVERSO"<<endl;
}

//elimina cierta conexion de One hacia Two
void Multiverse::clearConn(Universe* one,Universe* two){
	for(int i=0;i<6;i++){
		if(one->Nxt[i]==two){
			one->Nxt[i]=NULL;
		}
		if(two->Prev[i]==one){
			two->Prev[i]=NULL;
		}
	}
}

//Viaja a un universo siguiente -- aleatoriamente o al establecido (siempre sea posible y exista una conexion en dicha ranura Nxt[])
void Multiverse::travel(int num=-1){
	if(num==-1){
		int random;
		do{
			random=rand()%6;
		}while(this->actual()->getNext(random)->getNumber()<1);
		this->act=this->actual()->getNext(random);
		return;
	}else if(this->actual()->getNext(num)->getNumber()>=1){
		this->act=this->actual()->getNext(num);
		return;
	}
	cout<<"NO FUE POSIBLE REALIZAR EL VIAJE"<<endl;
}

//Realiza impresion del multiverso, universo por universo con sus conexiones
void Multiverse::print(){
	Queue<Universe*> *colaAux = new Queue<Universe*>();
	bool add=true;
	int cont=1;
	colaAux->put(this->act);
	
	vector <Universe* > arr;
	arr.push_back(this->act);
	
	while(!colaAux->isEmpty()){
		Universe *uni = colaAux->getFront()->Data;
		
		colaAux->remove();
		cout<<"universo: "<<uni->getNumber()<<endl;
		for(int i=0;i<6;i++){
			if(uni->getNext(i)!=NULL)cout<<i<<" - "<<uni->getNext(i)->getNumber()<<endl;
		}
		if(cont!=this->cantidad()){
			for(int i=0;i<6;i++){
				add=true;
				if(uni->getNext(i)!=NULL){
					for(int j=0;j<arr.size();j++){
						if(arr[j]==uni->getNext(i))add=false;
					}
					if(add){
						arr.push_back(uni->getNext(i));
						colaAux->put(uni->getNext(i));
						cont++;	
					}
				}
			}
		}
	}
}

Universe* Multiverse::actual(){
	return this->act;
}

int Multiverse::cantidad(){
	return this->cant;
}

int main(){
	
	
	
	Universe *newU = new Universe(5); 
	
	Universe *secU = new Universe(7);
		
	Universe *ejU = new Universe(9);
	
	//EJEMPLO DE PRUEBA
	//creamos el multiverso
	Multiverse *a = new Multiverse();
	
	//añadimos universo
	a->addUniv(ejU);

	cout<<"cantidad: "<<a->cantidad()<<endl;
	
	cout<<"--------------PRIMER PRINT---------"<<endl;
	a->print();
	
	cout<<"---------------ELIMINAMOS UNIVESO------------------"<<endl;
	
	//eliminamos universo importante -saltaran posibles errores de conexiones al eliminar este
	//se corrigen cambiando conexiones entre los restantes
	
	a->clearUniverse(a->actual()->getNext(0)->getNext(0));
	cout<<"cantidad: "<<a->cantidad()<<endl;
	
	cout<<"--------------SEGUNDO PRINT---------"<<endl;
	a->print();
	
	//añadimos universo con conexiones especificas
	a->addUniv(secU,a->actual(),a->actual()->getNext(1)->getNext(0));
	cout<<"--------------TERCER PRINT---------"<<endl;
	a->print();

	cout<<"cantidad: "<<a->cantidad()<<endl;
	
	
}
