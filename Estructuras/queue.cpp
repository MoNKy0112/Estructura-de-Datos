#include <iostream>
#include <stdlib.h>
#include <string>
#include <sstream>

using namespace std;


//Declaracion estructura Nodo
template <class T>

class Node{
	public:
		//Declaracion funciones Nodo
		Node();
		Node(T);
		void deleteNode();
		T Data;
		Node *Nxt;
};


//Creacion funciones Nodo
template <typename T>
Node<T>::Node()
{
	Data = NULL;
	Nxt = NULL;
}

template <typename T>
Node<T>::Node(T data){
	Data=data;
	Nxt=NULL;
}

template <typename T>
void Node<T>::deleteNode(){
	Data=NULL;
	Nxt=NULL;
	free(this);
}

//Declaracion estructura Cola
template <class T>

class Queue{
	public:
		//Declaracion funciones Cola
		Queue();
		void deleteQueue();
		
		bool isEmpty();
		void put(T);
		Node<T>* getFront();
		Node<T>* getRear();
		Node<T>* getNode(int);
		void remove();
	private:
		Node<T> *front;
		Node<T> *rear;
};

//creacion funciones Cola
template <typename T>::
Queue<T>::Queue(){
	front=NULL;
	rear=NULL;
}

template <typename T>
void Queue<T>::deleteQueue(){
	while(front) {
		remove(this);
	}
	free(this);
}

template <typename T>
bool Queue<T>::isEmpty(){
	return (!front);
}
	
template <typename T>
void Queue<T>::put(T data){
	Node<T> *node = new Node<T> (data);
	if(!front)
	{
		front=node;
		rear=node;
	} else 
	{
		rear->Nxt=node;
		rear=node;
	}
}

template <typename T>
Node<T>* Queue<T>::getFront(){
	if(front){
		return front;
	}else{
		return NULL;
	}
}

template <typename T>
Node<T>* Queue<T>::getRear(){
	if(front){
		return rear;
	}else{
		return NULL;
	}
}

template <typename T>
Node<T>* Queue<T>::getNode(int n){
	if(front){
		Node<T> *temp = front;
		int pos=0;
		while(temp->Nxt && pos<n){
			temp = temp->Nxt;
			pos++;
		}
		if(pos==n){
			return temp;
		}
	}
	
	return NULL;
	
}


template <typename T>
void Queue<T>::remove(){
	if(front){
		Node<T> *deleted = front;
		front=front->Nxt;
		deleted->deleteNode();
		if(!front) rear=NULL;
	}
}
/*
Queue<int> strToQueue(string s,Queue<int> q,string del = " "){
	int start = 0,num;
    int end = s.find(del);
    while (end != -1) {
    	stringstream intTicket(s.substr(start, end - start));
    	intTicket>>num;
		q.put(num);
        start = end + del.size();
        end = s.find(del, start);
    }
    stringstream intTicket(s.substr(start, end - start));
    intTicket>>num;
	q.put(num);
	return q;
}
*/

/*
int main(){
	
	Queue<int> a;
	string st;
	int x=0;
	cin>>st;
	st.erase(0,1);
	st.erase(st.size()-1);
	a=strToQueue(st,a,",");
	cin>>x;
	Node<int> *def;
	def = a.getNode(x);

	

	
	bool flag=false;
	int y=0;
	while(flag==false && a.isEmpty()==false){
		Node<int> *temp = a.getFront();
		if(temp->Data-1!=0){
			a.put(temp->Data-1);
		}
		if(temp==def){
			if(def->Data>1){
				def=a.getRear();
			}else{
				flag=true;
			}	
		}
		a.remove();
		y++;
		//system("pause");			
	}
	cout<<y<<endl;
	
	/*cout<<"valor nodo original: "<<a.getNode(x)->Data<<endl;
	Node<int> *temp = a.getNode(x);
	a.getNode(x)->Data=a.getNode(x)->Data-1;
	cout<<"valor nodo copia: "<<temp->Data;
	
	return 0;
}

*/

