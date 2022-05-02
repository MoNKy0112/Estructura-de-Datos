#include <iostream>
#include <stdlib.h>
#include <string>
#include <sstream>

using namespace std;

template <class T>
class Node{
	public:
		Node();
		Node(T);
		void deleteNode();
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
void Node<T>::deleteNode(){
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
		int size();
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
		this->lenght--;
	}
}

template <typename T>
void Stack<T>::print(){
	Node<T> *temp =this->top;
	while(temp!=NULL){
		cout<<temp->data<<endl;
		temp=temp->nxt;
	}
}

template <typename T>
int Stack<T>::size(){
	return this->lenght;
}

Stack<int> strToStack(string s,string del = " "){
	Stack<int> temp,st;
	int size;
	int start = 0,num;
    int end = s.find(del);
    while (end != -1) {
    	stringstream intTicket(s.substr(start, end - start));
    	intTicket>>num;
		temp.push(num);
        start = end + del.size();
        end = s.find(del, start);
    }
    stringstream intTicket(s.substr(start, end - start));
    intTicket>>num;
	temp.push(num);
	size=temp.size();
	for(int i=0;i<size;i++){
		st.push(temp.peek());
		temp.pop();
	}
	return st;
}

int main(){
	Stack<int> pila,temp,resp;
	
	/*pila.push(9);
	pila.push(11);
	pila.push(5);
	pila.push(8);
	pila.push(6);
	pila.push(10);*/
	string st;
	cin>>st;
	st.erase(0,1);
	st.erase(st.size()-1);
	pila=strToStack(st,",");
	cout<<"[";
	int max=0,act=0,sig=0,cant=0,len=0,leninit=pila.size();
	for (int i = 0;i < leninit;i++){
		len=pila.size();
		//cout<<"tamano pila: "<<pila.size()<<endl;
		act=pila.peek();
		pila.pop();
		for(int j = 1;j < len;j++){
			temp.push(pila.peek());
			sig=pila.peek();
			if(act>max && sig>max){
				max=sig;
				cant++;
				//cout<<"add: "<<pila.peek()<<endl;
			}
			pila.pop();
		}
		/*cout<<"///temp"<<endl;
		temp.print();
		cout<<"///"<<endl;*/
		for(int j = 0;j<len-1;j++){
			pila.push(temp.peek());
			temp.pop();
		}
		/*cout<<"///pila"<<endl;
		pila.print();
		cout<<"///"<<endl;*/
		if(cant==0)cout<<cant;
		else cout<<cant<<", ";
		resp.push(cant);
		cant=max=0;
	}
	cout<<"]";
	return 0;
}



