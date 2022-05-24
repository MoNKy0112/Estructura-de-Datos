#ifndef universe_h
#define universe_h

#include <iostream>
#include "Node.cpp"

using namespace std;


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
		void setNext(Universe*[],bool);
		void setPrev(Universe*[],bool);
		//getters
		int getNumber();
		Universe* getNext(int);
		Universe* getPrev(int);
		//void deleteUniverse();
	
	
};


#endif 


