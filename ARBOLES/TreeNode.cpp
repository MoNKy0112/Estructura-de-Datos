#include <stdlib.h>
#include "TreeNode.h"

template <typename T>
TreeNode<T>::TreeNode()
{
	data= NULL;
	
}

template <typename T>
TreeNode<T>::TreeNode(T newData)
{
	data = newData;
}

template <typename T>
void TreeNode<T>::Delete()
{
	for(int i=0;i<nxt.size();i++){
		nxt[i] = NULL;
	}
	free(this);
}

/*
void Node<int>::add(int cant)
{
	data = data + cant;
}*/


