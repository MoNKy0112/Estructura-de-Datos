#include <iostream>
#include <stdlib.h>

using namespace std;


//Declaracion estructura Nodo
template <class T>

struct Node{
	T Data;
	Node* Nxt;
};
//Declaracion funciones Nodo
template <typename T>
Node<T> createNode(T data);

template <typename T>
void deleteNode(Node<T> Node);

//Creacion funciones Nodo
template <typename T>
Node<T> createNode(T data){
	Node<T> node = (Node<T>) malloc(sizeof(Node<T>));
	node->Data= data;
	node->Nxt=NULL;
}

template <class T>
void deleteNode(Node<T> Node){
	Node->Data=NULL;
	Node->Nxt=NULL;
	free(Node);
}

//Declaracion estructura Cola
template <class T>

struct Queue{
	Node<T> front;
	Node<T> rear;
};
//Declaracion funciones Cola

template <class T>
Queue<T> cQueue();
template <class T>
void deleteQueue(Queue<T> Queue);

template <class T>
void put(Queue<T> queue,T data);
template <class T>
T getFront(Queue<T> queue);
template <class T>
T getRear(Queue<T> queue);
template <class T>
Node<T> remove(Queue<T> queue);

//creacion funciones Cola
template <typename T>::
Queue<T> cQueue(){
	Queue<T> queue = (Queue<T>) malloc(sizeof(Queue<T>));
	queue->front=queue->rear=NULL;
	return queue;
}

template <class T>
void deleteQueue(Queue<T> queue){
	while(queue->front) remove(queue);
	free(queue);
}


template <class T>
void put(Queue<T> queue,T data){
	Node<T> node = createNode(data);
	if(!queue->front){
		queue->front=node;
		queue->rear=node;
	} else {
		queue->rear->Nxt=node;
		queue->rear=node;
	}
}

template <class T>
T getFront(Queue<T> queue){
	if(queue->front){
		return queue->front->Data;
	}else{
		return NULL;
	}
}

template <class T>
T getRear(Queue<T> queue){
	if(queue->front){
		return queue->rear->Data;
	}else{
		return NULL;
	}
}

template <class T>
Node<T> remove(Queue<T> queue){
	if(queue->front){
		Node<T> deleted = queue->front;
		queue->front=queue->front->Nxt;
		deleteNode(deleted);
		if(!queue->front) queue->rear=NULL;
	}else{
		return NULL;
	}
}

int main(){
	
	
	
}


