//Binary Tree 
#include<iostream>
#include<climits>
#include<queue>
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


	bool isBst(node*startnode,int start,int end){
			if(startnode==NULL)return true;
			if(startnode->data<start||startnode->data>end) return false;
			bool ans=isBst(startnode->left,start,startnode->data);
			if(ans==false)return ans;
			return isBst(startnode->right,startnode->data,end);
	}
	
	bool isBst(){
		return isBst(rootnode,INT_MIN,INT_MAX);
	}

};
int main(){
	BinaryTree bt;
	bt.BulidTree();
	cout<<bt.isBst()<<endl;
	return 0;
}

/*
8 3 1 -1 -1 6 4 -1 -1 7 -1 -1 10 -1 14 13 -1 -1 -1 

1 2 4 12 -1 -1 5 7 -1 8 -1 -1 -1 3 -1 6 10 -1 -1 9  11 -1 -1 -1 13 -1 -1
*/
