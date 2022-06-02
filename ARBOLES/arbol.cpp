#include <string>
#include <sstream>

#include "arbol.h"
#include "queue.cpp"

using namespace std;

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
}
//print
template <typename T>
void Arbol<T>::levelOrder(){
	Queue<TreeNode<T>* > *cola=new Queue<TreeNode<T>* >();
	cola->put(this->raiz);
	
	while(!cola->isEmpty()){
		TreeNode<T> *nodo = cola->getFront()->Data;
		cola->remove();
		
		cout<<nodo->data<<" - "<<profundidad(nodo->data)<<endl;
		
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

int main(){
	Arbol<int> *arb=new Arbol<int> ();
	string a;
	vector<int> arr;
	
	
	a="[1,null,2,3,4,5,null,null,6,7,null,8,null,9,null,10,null,null,11,null,12,null,13,null,14]";

	
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
			cout<<num<<endl;
		}
	}
	
	for(int i=0;i<vect.size();i++){
		cout<<"[";
		for(int j=0;j<vect[i].size();j++){
			cout<<vect[i][j]<<",";
		}
	}
	
	
	
	arb->levelOrder();
	
	
		
	

	
}
