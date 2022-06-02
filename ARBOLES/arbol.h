#ifndef arbol_h
#define arbol_h

#include "TreeNode.cpp"

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


#endif 
