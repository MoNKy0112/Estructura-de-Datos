#ifndef universe_h
#define universe_h

#include <iostream>

using namespace std;

//Universe sigue la idea de un Nodo pero fue creado para facilitar el movimiento entre siguientes y previos
//No se utiliza la calse llamada Node porque crea inconvenientes con Queue que a falta de tiempo no pude arreglar =)
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
		void setNext(Universe*,int);
		
		void setPrev(Universe*);
		//getters
		int getNumber();
		Universe* getNext(int);
		Universe* getPrev(int);
		//Delete
		void deleteUniverse();
		//AYUDAS
		bool canBeNxt(Universe*);
		bool possPrev();
		bool possNxt();
		
		Universe* possDelPrevError();
		Universe* possDelNxtError();
		
	
	
};


#endif 


