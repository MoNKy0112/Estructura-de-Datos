#ifndef Treenode_h
#define Treenode_h


#include <iostream>
#include <vector>

using namespace std;

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


#endif 
