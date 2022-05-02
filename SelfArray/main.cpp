#include <iostream>
#include <string>
#include "LinkedList.h"
#include "LinkedList.cpp"

using namespace std;

int main(){
	LinkedList<int> list,resultado;
	
	string num="001011";
	char dig;
	
	for(int i;i<num.length();i++){
		dig=num[i];	
		list.push_end(int(dig-'0'));
		resultado.push_end(0);
	}
	
	for(int i=0;i<list.size();i++){
		for(int j=0;j<list.size();j++){
			if(list.search_index(j)==1){
				resultado.replace(i,resultado.search_index(i)+abs(i-j));
			}	
		}	
	}
	
	list.print();
	resultado.print();
	
	/*
	int a,b,c,d,e,f;
	
	a=1;
	b=2;
	c=3;
	d=4;
	e=5;
	f=6;
	//31542
	/*list.push_front(a);
	list.push_front(b);
	list.push_end(c);
	list.push_end(f);//
	list.push_front(a);
	list.push_front(c);
	list.push_end(e);
	list.push_end(d);
	list.push_in(11,b);
	/*list.sort_htl();
	list.pop_front();
	list.pop_end();
	list.pop_in(1);
	list.pop_data(4);
	list.print();
	list.sort_lth();//
	cout<<list.search_index(4)<<endl;
	list.replace(4,'a');
	
	cout<<list.search_index(4)<<endl;
	
	
	list.print();*/
	
	
	
}
