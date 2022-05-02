#include "linkedList.h"

template <typename T>
LinkedList<T>::LinkedList()
{
	head= NULL;
	NumNodes= 0;
}

/*Añadir parte delantera
*Cabeza -> nuevo nodo
*Siguiente del nuevo nodo -> Antigua cabeza
*/
template <typename T>
void LinkedList<T>::push_front(T NewData)
{
	Node<T> *NewNode = new Node<T> (NewData);
	
	if(!head)
	{
		head = NewNode;
	}else
	{
		NewNode -> nxt = head;
		head = NewNode;
	}
	NumNodes++;
	//REVISAR IF & ELSE (POSIBLE ELIMINAR PARTE IF)
}

/*Añadir final de lista
*Se busca el primer nodo donde nxt->null
*para que este nodo nxt->nuevo nodo
*si la lista esta vacia cabeza->nuevo nodo
*/
template <typename T>
void LinkedList<T>::push_end(T NewData)
{
	Node<T> *NewNode = new Node<T> (NewData);
	
	if(head == NULL)
	{	
		head = NewNode;
	}else
	{
		Node<T> *punt = head;
		
		while(punt->nxt){
			punt = punt->nxt;
		}
		punt -> nxt = NewNode;
	}
	NumNodes++;
}

template <typename T>
void LinkedList<T>::push_in(int n,T NewData)
{
	Node<T> *NewNode = new Node<T> (NewData);
	if(head == NULL){	
		head = NewNode;
	}else if(n==0){
		NewNode -> nxt = head;
		head = NewNode;
	}else{
		Node<T> *punt = head;
		int pos = 1;
		while(pos < n && punt->nxt){
			punt = punt->nxt;
			pos++;
		}
		NewNode->nxt = punt->nxt;
		punt->nxt = NewNode;
		
	}
	NumNodes++;	
}

template <typename T>
void LinkedList<T>::replace(int n,const T NewData)
{
	Node<T> *punt = head;
	int pos = 0;
	while(pos < n){
		punt = punt->nxt;
		pos++;
	}
	punt->data = NewData;
}

/*
void LinkedList<int>::add_to(int n,T cant)
{
	Node<T> *punt = head;
	int pos = 0;
	while(pos < n){
		punt = punt->nxt;
		pos++;
	}
	punt->add(cant);
}*/

template <typename T>
void LinkedList<T>::pop_front()
{
	if(head){
		Node<T> *deleted = head;
		head = head->nxt;
		deleted->Delete();
		NumNodes--;
	}
}

template <typename T>
void LinkedList<T>::pop_end()
{
	if(head){
		if(head->nxt){
			Node<T> *punt = head;
			while(punt->nxt->nxt){
				punt = punt->nxt;
			}
			Node<T> *deleted = punt->nxt;
			punt->nxt=NULL;
			deleted->Delete();
		}else{
			Node<T> *deleted = head;
			head = NULL;
			deleted->Delete();		
		}
		NumNodes--;
	}
}

template <typename T>
void LinkedList<T>::pop_in(int n)
{
	if(head){
		if(n == 0){
			Node<T> *deleted = head;
			head = head->nxt;
			deleted->Delete();
			NumNodes--;	
		}else if(n < NumNodes){
			Node<T> *punt = head;
			int pos = 1;
			while(pos < n){
				punt = punt -> nxt;
				pos++;
			}
			Node<T> *deleted = punt->nxt;
			punt->nxt = deleted->nxt;
			deleted->Delete();
			NumNodes--;	
		}
	}	
}



template <typename T>
void LinkedList<T>::pop_data(T Data)
{
	if(head)
	{
		if(head->data == Data){
			Node<T> *deleted = head;
			head = head->nxt;
			deleted->Delete();
			NumNodes--;		
		}else{
			Node<T> *punt = head;
			while(punt->nxt->data != Data)
			{
				punt = punt->nxt;
			}
			Node<T> *deleted = punt->nxt;
			punt->nxt = deleted->nxt;
			deleted->Delete();
			NumNodes--;
		}		
	}
}

 
template <typename T>
void LinkedList<T>::sort_lth()
{
	T temp_data;
	Node<T> *frst = head;
	Node<T> *sec = frst;
	while(frst){
		sec = frst;
		while(sec->nxt){
			sec = sec->nxt;
			if(frst->data > sec->data ){
				temp_data = frst->data;
				frst->data = sec->data;
				sec->data = temp_data;
			}
		}
		
		frst = frst->nxt;
	}
	
}

template <typename T>
void LinkedList<T>::sort_htl(){
	T temp_data;
	Node<T> *frst = head;
	Node<T> *sec = frst;
	while(frst){
		sec = frst;
		while(sec->nxt){
			sec = sec->nxt;
			if(frst->data < sec->data ){
				temp_data = frst->data;
				frst->data = sec->data;
				sec->data = temp_data;
			}
		}
		
		frst = frst->nxt;
	}
	
}


template <typename T>
int LinkedList<T>::search_key(T Data){
	Node<T> *temp = head;
	int pos = 0;
	while(temp->data != Data){
		temp = temp->nxt;
		pos++;
	}	
	return pos;
}


template <typename T>
T LinkedList<T>::search_index(int n){
	Node<T> *temp = head;
	int pos = 0;
	while(pos < n){
		temp = temp->nxt;
		pos++;
	}
	return temp->data;
}

template <typename T>
int LinkedList<T>::size()
{
	return NumNodes;
}

template <typename T>
void LinkedList<T>::print()
{
	Node<T> *temp = head;
	
		if(!head){
			cout<<"Lista vacia"<<endl;
		}else{
			while(temp){
				cout<<temp->data<<endl;
				if(!temp->nxt) cout<<"Fin Lista"<<endl;
				temp = temp->nxt;
			}
		}
}

