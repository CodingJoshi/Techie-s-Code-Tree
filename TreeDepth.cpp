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
	int depth(node*start,int k,int lvl){
			if(start==NULL)return -1;
			if(start->data==k) return lvl;
			int temp=depth(start->left,k,lvl+1);
			if(temp!=-1)return temp;
			else return depth(start->right,k,lvl+1);
	}
	int depth(int k){
		return depth(rootnode,k,0);
	}	

};
int main(){
	BinaryTree bt;
	bt.BulidTree();
	cout<<bt.depth(9)<<endl;
	return 0;
}

/*
5 6 8 4 -1 -1 3 -1 -1 -1 7 9 -1 -1 6 -1 -1 
*/
