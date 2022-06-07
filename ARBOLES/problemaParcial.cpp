#include <iostream>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

//-----------------------------------------COLA--------------------------------------------------------------------//
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

//-------------------------------------TREE NODE------------------------------------------------------------------------//
template <class T>
class TreeNode
{
	
	public:
		TreeNode();
		TreeNode(T);
		void Delete();
		
		T data;
		TreeNode *left, *right;
};

template <typename T>
TreeNode<T>::TreeNode()
{
	data= NULL;
	left=NULL;
	right=NULL;
}

template <typename T>
TreeNode<T>::TreeNode(T newData)
{
	data = newData;
	left=NULL;
	right=NULL;
}

template <typename T>
void TreeNode<T>::Delete()
{
	left=NULL;
	right=NULL;
	free(this);
}




//----------------------------------ARBOL----------------------------------------------------------------------//

template <class T>
struct Arbol{
	private:
	TreeNode<T> *raiz;
	TreeNode<T>* buscar(TreeNode<T>* ,T);
	int profundidad(TreeNode<T>* , int );
	void insertar(TreeNode<T>*,int,T);
	
	public:
	Arbol();
	Arbol(TreeNode<T>*);
	
	void setRaiz(T);
	TreeNode<T> *getRaiz();
	TreeNode<T> *buscar(T);
	
	void insertar(int,T);
	void insertarHijo(T,T);
	void levelOrder();
	int cantidad();
	int profundidad(int );
};

//constructors
template <typename T>
Arbol<T>::Arbol(){
	raiz = NULL;
}

template <typename T>
Arbol<T>::Arbol(TreeNode<T>* raiz){
	this->raiz = raiz;
}
//raiz
template <typename T>
void Arbol<T>::setRaiz(T dato){
	TreeNode<T> *newTN=new TreeNode<T>(dato);
	this->raiz=newTN;
}

template <typename T>
TreeNode<T> *Arbol<T>::getRaiz(){
	TreeNode<T> *newTN=this->raiz;
	return newTN;
}

//buscar private
template <typename T>
TreeNode<T> *Arbol<T>::buscar(TreeNode<T>* nodo,T dato){
	TreeNode<T> *temp = NULL;
	
	if(nodo!=NULL){
		if(nodo->data==dato){
			return nodo;
		}else{
			
			temp = buscar(nodo->left,dato);
			if(temp!=NULL) {
				return temp;		
			}
			temp = buscar(nodo->right,dato);
			if(temp!=NULL) {
				return temp;		
			}
			
			return NULL;
		}	
	}
}
//buscar publico
template <typename T>
TreeNode<T> *Arbol<T>::buscar(T dato){
	return this->buscar(this->raiz,dato);
}
//insertar dato
template <typename T>
void Arbol<T>::insertar(TreeNode<T>* nodo,int prof,T dato){
	TreeNode<T> *newTN =new TreeNode<T> (dato);
	if(this->profundidad(nodo->data)==prof - 1){
		if(nodo){
			if(nodo->left != NULL) nodo->right=newTN;
			else nodo->left=newTN;
		}	
	}else{
		if(nodo->right != NULL){
			insertar(nodo->right,prof,dato);
		} else {
			insertar(nodo->left,prof,dato);
		}
	}
}

template <typename T>
void Arbol<T>::insertar(int prof,T dato){
	insertar(this->raiz,prof,dato);
}

template <typename T>
void Arbol<T>::insertarHijo(T padre, T hijo){
	TreeNode<T> *newTN =new TreeNode<T> (hijo);
	TreeNode<T> *nodoPadre = buscar(padre);
	if(nodoPadre->left==NULL){
		nodoPadre->left=newTN;
	} else {
		nodoPadre->right=newTN;
	}
	//cout<<padre<<" - "<<hijo<<endl;
}
//print
template <typename T>
void Arbol<T>::levelOrder(){
	Queue<TreeNode<T>* > *cola=new Queue<TreeNode<T>* >();
	cola->put(this->raiz);
	cout<<"[";
	while(!cola->isEmpty()){
		TreeNode<T> *nodo = cola->getFront()->Data;
		cola->remove();
		if(nodo==NULL && cola->isEmpty()){
			break;
		}
		if(nodo != this->raiz){
			cout<<",";
		}
		if(nodo==NULL){
			cout<<"null";	
		}else{
			cout<<nodo->data;
		}
		
		if(nodo != NULL && nodo->left!=NULL){
			cola->put(nodo->left);
			cola->put(nodo->right);
		}
	}
	cout<<"]"<<endl;
}

template <typename T>
int Arbol<T>::cantidad(){
	Queue<TreeNode<T>* > *cola=new Queue<TreeNode<T>* >();
	cola->put(this->raiz);
	int cant=0;
	while(!cola->isEmpty()){
		TreeNode<T> *nodo = cola->getFront()->Data;
		cola->remove();
		
		cant++;
		
		cola->put(nodo->left);
		cola->put(nodo->right);
	}
	return cant;
}

template <typename T>
int Arbol<T>::profundidad(TreeNode<T> *nodo, int dato){
	
	if(nodo==NULL){
		return -1;
	}
	
	int dist=-1;
	
	if( (dist = profundidad(nodo->left, dato)) >= 0 )	return dist + 1;		
	
	
	if( (dist = profundidad(nodo->right, dato)) >= 0 )	return dist + 1;
	
	
	if((nodo->data == dato)){
		return dist + 1;
		
	}
	return dist;
}

template <typename T>
int Arbol<T>::profundidad(int dato){
	return profundidad(this->raiz,dato);
}



//--------------------------------------FUNCIONES PROBLEMA-----------------------------------------------------//



Arbol<int>* stToTree(string a,string del=" "){
	Arbol< int > *arb=new Arbol<int> ();
	int start = 0,num;
	int end = a.find(del);
	
	int cont=0;
	    while (end != -1) {
	    	if(end - start == 0){
	    		cont++;
			} else {
				stringstream intTicket(a.substr(start, end - start));
				intTicket>>num;
				if(cont==0){
					arb->setRaiz(num);
				}else{	
					arb->insertar(cont,num);
					//cout<<a.substr(start, end - start)<<" -> "<<cont<<endl;
				}
				cont=1;
				
				
					
				
			}
			
	        start = end + del.size();
	        end = a.find(del, start);
	    }

    stringstream intTicket(a.substr(start, end - start));
    intTicket>>num;
    arb->insertar(cont,num);
	//cout<<a.substr(start, end - start)<<" -> "<<cont<<endl;
	return arb;
	
}

Arbol<int> * arrToTree(vector<int> arr){
	Arbol<int> *arb=new Arbol<int> ();
	Queue< int > *cola=new Queue<int> ();
	
	arb->setRaiz(arr[0]);
	cola->put(arb->getRaiz()->data);
	
	int temp;
	arr.erase(arr.begin());
	
	for(int i=0;i<arr.size();i++){
		if(arr[i]!=-1){
			arb->insertar(temp,arr[i]);
			cola->put(arr[i]);
		}	
		else{
			temp=cola->getFront()->Data;
			cola->remove();
		}
	}
	
	return arb;
}


//-------------------------------------MAIN------------------------------------------------------------------------//

int main(){
	Arbol<int> *arb=new Arbol<int> ();
	string a;	
	
	//a="'1-2--3---4-5--6---7'";
	cin>>a;
	
	a.erase(0,1);a.erase(a.size()-1,a.size());
	
	arb = stToTree(a,"-");	

	arb->levelOrder();
}

//--------------------------------------------------------------------------------------------------------------------------//
