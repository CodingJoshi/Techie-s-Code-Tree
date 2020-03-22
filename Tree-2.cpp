#include<iostream>
using namespace std;
class node{
public:
	int data;
	int child_Count;
	node **children;
	node(int d,int cc){
		data=d;
		child_Count=cc;
		children=NULL;
	} 
};
class Tree
{
	node* rootnode;
	node* BuildTree(){
		int d;cin>>d;
		int cc;cin>>cc;
		node* nn=new node(d,cc);
		nn->children= new node*[cc];						//int *arr=new int[size];
		for(int i=0;i<cc;i++){
			nn->children[i]=BuildTree();
		}
		return nn;
	}
public:
	Tree(){
		rootnode=NULL;
	}
	void buildTree(){
		rootnode=BuildTree();
	}

};
int main(){
	Tree t;
	t.buildTree();

	return 0;
}
