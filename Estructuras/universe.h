#ifndef universe_h
#define universe_h

#include <iostream>

using namespace std;

//Universe sigue la idea de un Nodo pero fue creado para facilitar el movimiento entre siguientes y previos 
class Universe{
	public:
		int Number;
		Universe *Prev[6];
		Universe *Nxt[6];
	public:
		//Metodos
		//Creacion
		Universe();
		Universe(int);
		//setters
		void setNumber(int);
		void setNext();
		void setNext(Universe*,bool,int);
		void setNext(Universe*[],bool);
		
		void setPrev(Universe*);
		void setPrev(Universe*[],bool);
		//getters
		int getNumber();
		Universe* getNext(int);
		Universe* getPrev(int);
		//void deleteUniverse();
		bool canBeNxt(Universe*);
		bool possPrev();
		bool possNxt();
		
	
	
};


#endif 


