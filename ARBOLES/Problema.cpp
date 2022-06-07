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
		vector <TreeNode<T>* > nxt;
};

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


//----------------------------------ARBOL----------------------------------------------------------------------//

template <class T>
struct Arbol{
	private:
	TreeNode<T> *raiz;
	TreeNode<T>* buscar(TreeNode<T>* ,T);
	int profundidad(TreeNode<T>* , int );
	public:
	Arbol();
	Arbol(TreeNode<T>*);
	
	void setRaiz(T);
	TreeNode<T> *getRaiz();
	TreeNode<T> *buscar(T);
	void insertar(T,T);
	void levelOrder();
	int cantidad();
	int profundidad(int );
};


template <typename T>
Arbol<T>::Arbol(){
	raiz = NULL;
}

template <typename T>
Arbol<T>::Arbol(TreeNode<T>* raiz){
	this->raiz = raiz;
}

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
			for(int i=0;i<nodo->nxt.size();i++){
				temp = buscar(nodo->nxt[i],dato);
				if(temp!=NULL) {
					return temp;		
				}
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
void Arbol<T>::insertar(T padre, T hijo){
	TreeNode<T> *newTN =new TreeNode<T> (hijo);
	buscar(padre)->nxt.push_back(newTN);
	//cout<<padre<<" - "<<hijo<<endl;
}
//print
template <typename T>
void Arbol<T>::levelOrder(){
	Queue<TreeNode<T>* > *cola=new Queue<TreeNode<T>* >();
	cola->put(this->raiz);
	
	while(!cola->isEmpty()){
		TreeNode<T> *nodo = cola->getFront()->Data;
		cola->remove();
		
		//cout<<nodo->data<<" - "<<profundidad(nodo->data)<<endl;
		
		for(int i=0;i<nodo->nxt.size();i++){
			cola->put(nodo->nxt[i]);
		}
	}
	cout<<"FIN"<<endl;
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
		
		for(int i=0;i<nodo->nxt.size();i++){
			cola->put(nodo->nxt[i]);
		}
	}
	return cant;
}

template <typename T>
int Arbol<T>::profundidad(TreeNode<T> *nodo, int dato){
	if(nodo==NULL){
		return -1;
	}
	int dist=-1;
	for(int i=0;i<nodo->nxt.size();i++){
		if( (dist = profundidad(nodo->nxt[i], dato)) >= 0 )	return dist + 1;		
	} 
	if((nodo->data == dato)){
		return dist + 1;
	}
	return dist;
}

template <typename T>
int Arbol<T>::profundidad(int dato){
	profundidad(this->raiz,dato);
}



//--------------------------------------FUNCIONES PROBLEMA-----------------------------------------------------//

vector<int> stToArr(string a,string del=" "){
	vector<int> arr;
	int start = 0,num;
	int end = a.find(del);
	    while (end != -1) {
	    	if(a.substr(start, end - start)=="null"){
	    		arr.push_back(-1);
	    		start = end + del.size();
		        end = a.find(del, start);
			}else{
		    	stringstream intTicket(a.substr(start, end - start));
		    	intTicket>>num;
				arr.push_back(num);
		        start = end + del.size();
		        end = a.find(del, start);
			}
	    }
	if(a.substr(start, end - start)=="null"){
		arr.push_back(-1);
	}else{
	    stringstream intTicket(a.substr(start, end - start));
	    intTicket>>num;
		arr.push_back(num);
	}
	return arr;
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
	vector<int> arr;
	
	
	a="[1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]";

	
	a.erase(0,1);a.erase(a.size()-1,a.size());
	
	arr = stToArr(a,",");	
	
	arb = arrToTree(arr);
	
	vector<vector<int> > vect(5);
	//crear maxima profundidad para saber cuantas filas debeb ser
	//vect[rows][.pushback]

	
	int num=0;
	for(int i=0;i<arr.size();i++){
		if(arr[i]!=-1){
			num=arr[i];
			vect[ arb->profundidad(num) ].push_back(num);
			//cout<<num<<endl;
		}
	}
	
	cout<<"[";
	for(int i=0;i<vect.size();i++){
		cout<<"[";
		for(int j=0;j<vect[i].size()-1;j++){
			cout<<vect[i][j]<<",";
		}
		cout<<vect[i][vect[i].size()-1]<<"]";
		if(i!=vect.size()-1){
			cout<<",";
		}
	}
	cout<<"]";
	
	
	//arb->levelOrder();
	
	
		
	

	
}

//--------------------------------------------------------------------------------------------------------------------------//
