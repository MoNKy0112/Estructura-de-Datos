#include <iostream>
#include <stdlib.h>

using namespace std;

template <class T>
class Node{
	public:
		Node();
		Node(T);
		deleteNode();
		T data;
		Node *nxt;
};

template <typename T>
Node<T>::Node(){
	this->data=NULL;
	this->nxt=NULL;
}
template <typename T>
Node<T>::Node(T Data){
	this->data=Data;
	this->nxt=NULL;	
}

template <typename T>
Node<T>::deleteNode(){
	this->data=NULL;
	this->nxt=NULL;
	free(this);
}

template <class T>
class Stack{
	public:
		Stack();
		bool isEmpty();
		T peek();
		void push(T);
		void pop();
		void print();
		int lenght();
	private:
		Node<T> *top;
		int lenght;
};

template <typename T>
Stack<T>::Stack(){
	this->top=NULL;
	this->lenght=0;
}

template <typename T>
bool Stack<T>::isEmpty(){
	return !this->top;
}

template <typename T>
T Stack<T>::peek(){
	return this->top->data;
}

template <typename T>
void Stack<T>::push(T data){
	Node<T> *newNode = new Node<T> (data);
	newNode->nxt=this->top;
	this->top=newNode;
	this->lenght++;
}

template <typename T>
void Stack<T>::pop(){
	if(this->top != NULL){	
		Node<T> *deleted = this->top;
		this->top=this->top->nxt;
		deleted->deleteNode();
	}
}

template <typename T>
void Stack<T>::print(){
	Node<T> *temp =this->top;
	while(temp->data!=NULL){
		cout<<temp->data<<endl;
		temp=temp->nxt;
	}
}

template <typename T>
int Stack<T>::lenght(){
	return this->lenght;
}

int main(){
	Stack<int> pila;
	
	pila.push(9);
	pila.push(11);
	pila.push(5);
	pila.push(8);
	pila.push(6);
	pila.push(10);
	
	pila.print();
	int max=0;
	int act=0;
	int cant=0;
	for (int i = 0;i < pila.lenght();i++){
		act=pila.peek();
		for(int j = i+1;j < pila.lenght();j++){
			
		}
		pila.pop()
		cant=max=0;
	}
	
	return 0;
}



