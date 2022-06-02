#ifndef multiverse_h
#define multiverse_h

#include <iostream>
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
		void addConn();
		void addConn(Universe*);
		void addConn(Universe*,Universe*);
		Universe* findNext(Universe*);
		Universe* findPrev(Universe*);
		void addUniv(Universe*);
		void addUniv(Universe*,Universe*,Universe*);
		
		void clearUniverse(Universe*);
		void clearConn(Universe*,Universe*);
		
		void print();
		
		void travel(int);
		
		Universe* actual();
		int cantidad();
};


#endif 
