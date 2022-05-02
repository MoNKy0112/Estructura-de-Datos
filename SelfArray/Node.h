#ifndef node_h
#define node_h

#include <iostream>

using namespace std;

template <class T>
class Node
{
	
	public:
		Node();
		Node(T);
		void Delete();
		
		T data;
		Node *nxt;
};


#endif 
