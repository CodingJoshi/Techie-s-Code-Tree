//Binary Tree 
#include<iostream>
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
	void Problem1(node* start){
			if(start==NULL)return;

			if(start->left==NULL&&start->right==NULL){
				cout<<start->data<<" ";
				return;
			}

			Problem1(start->left);
			Problem1(start->right);
	}
	void Problem1(){
		Problem1(rootnode);
	}

};
int main(){
	BinaryTree bt;
	bt.BulidTree();
	bt.Problem1();
	return 0;
}

/*
8 3 1 -1 -1 6 4 -1 -1 7 -1 -1 10 -1 14 13 -1 -1 -1 

1 2 4 12 -1 -1 5 7 -1 8 -1 -1 -1 3 -1 6 10 -1 -1 9  11 -1 -1 -1 13 -1 -1
*/
