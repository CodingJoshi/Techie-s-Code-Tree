#include<iostream>
using namespace std;
class node{
public:
	int data;
	node*left,*right;
	node(int d){
		data=d;
		left=NULL;
		right=NULL;
	}
};
class BST
{
	node*rootnode;
public:
	BST(){
		rootnode=NULL;
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

	node* insertnode(int d,node*startnode){
		if(startnode==NULL){
			node*nn=new node(d);
			return nn;
		}

		if(startnode->data>d){
			startnode->left=insertnode(d,startnode->left);
		}

		else{
			startnode->right=insertnode(d,startnode->right);
		}
	}
	void BuildTree(int *arr,int n){
			for(int i=0;i<n;i++){
				rootnode=insertnode(arr[i],rootnode);
			}
	}
};
int main(){
	BST t;
	int n;
	cin>>n;
	int arr[1000];
	for(int i=0;i<n;i++)cin>>arr[i];
	t.BuildTree(arr,n);
	t.PreOrderTraversal();
	return 0;
}
/*
8
5 3 2 1 7 8 9 6
*/