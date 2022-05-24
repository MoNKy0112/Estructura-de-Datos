#include <stdlib.h>
#include "Node.h"

template <typename T>
Node<T>::Node()
{
	data= NULL;
	nxt= NULL;
}

template <typename T>
Node<T>::Node(T newData)
{
	data= newData;
	nxt= NULL;
}

template <typename T>
void Node<T>::Delete()
{
	free(this);
}

/*
void Node<int>::add(int cant)
{
	data = data + cant;
}*/


