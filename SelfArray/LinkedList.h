#ifndef list_h
#define list_h

#include <iostream>
#include "Node.h"
#include "Node.cpp"

using namespace std;

template <class T>

class LinkedList
{
	
	public:
		LinkedList();
		void push_front(T);
		void push_end(T);
		void push_in(int,T);
		void replace(int,T);
		void pop_front();
		void pop_end();
		void pop_in(int);
		
		/* TODO (#1#): funciones eliminar */
		void pop_data(T);
		/* TODO (#2#): funciones de orden y busqueda */
		void sort_htl();
		void sort_lth();
		int search_key(T);
		T search_index(int);
		int size();
		void add_to(int,T);
		
		void print();
		
		
	private:
		Node<T> *head;
		int NumNodes;
	
};

#endif
