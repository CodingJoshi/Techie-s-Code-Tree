//Binary Tree 
#include<iostream>
using namespace std;
class node{
public:
	int data;
	node* left;
	node* right;

	node(int d){
		data=d;
		left=NULL;
		right=NULL;
	}

};
class BinaryTree
{
	node* rootnode;
	node* bulidTree(){
		int d;cin>>d;
		if(d==-1)return NULL;
		node* nn=new node(d);
		nn->left=bulidTree();
		nn->right=bulidTree();
	}
public:
	BinaryTree(){
		rootnode=NULL;
	}	
	void BulidTree(){
		rootnode=bulidTree();
	}
	
	int Height(node*start){
		//base case:
		if(start==NULL)return -1;

		//recursive Case:
		int height=max(Height(start->left),Height(start->right))+1;
		return height;
	}

	int Height(){
		return Height(rootnode);		
	}

};
int main(){
	BinaryTree bt;
	bt.BulidTree();
	cout<<bt.Height()<<endl;
	return 0;
}

/*
5 6 8 4 -1 -1 3 -1 -1 -1 7 9 -1 -1 6 -1 -1 
*/
