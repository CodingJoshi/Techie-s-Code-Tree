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

	void PreOrderTraversal(node*start){
			// base case:
				if(start==NULL)return;	

			//Recursive Case:
			cout<<start->data<<" ";
			PreOrderTraversal(start->left);
			PreOrderTraversal(start->right);
	}
	void PreOrderTraversal(){
		PreOrderTraversal(rootnode);
		cout<<endl;
	}

	void PostOrderTraversal(node*start){
			// base case:
				if(start==NULL)return;	

			//Recursive Case:
			
			PostOrderTraversal(start->left);
			PostOrderTraversal(start->right);
			cout<<start->data<<" ";
	}
	void PostOrderTraversal(){
		PostOrderTraversal(rootnode);
		cout<<endl;
	}

	void INOrderTraversal(node*start){
			// base case:
				if(start==NULL)return;	

			//Recursive Case:
			
			INOrderTraversal(start->left);
			cout<<start->data<<" ";
			INOrderTraversal(start->right);
			
	}
	void INOrderTraversal(){
		INOrderTraversal(rootnode);
		cout<<endl;
	}
};
int main(){
	BinaryTree bt;
	bt.BulidTree();
	bt.PreOrderTraversal();
	bt.PostOrderTraversal();
	bt.INOrderTraversal();
	return 0;
}

/*
5 6 8 4 -1 -1 3 -1 -1 -1 7 5 -1 -1 6 -1 -1 
*/
