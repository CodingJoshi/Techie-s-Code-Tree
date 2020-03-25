//Binary Search Tree  BST
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

class BinarySearchTree{
	node*rootnode;
public:
	BinarySearchTree(){
		rootnode=NULL;
	}

	node* BuildTree(int data,node* startnode){
			if(startnode==NULL){
				node*nn=new node(data);
				return nn;
			}
			if(data>=startnode->data){
				startnode->right=BuildTree(data,startnode->right);
			}
			else{
				startnode->left=BuildTree(data,startnode->left);
			}
	}

	void BuildTree(int *arr,int n){
		for(int i=0;i<n;i++){
			rootnode=BuildTree(arr[i],rootnode);
		}
	}

	void PreOrderTraversal(node*startnode){
		if(startnode==NULL)return;
		cout<<startnode->data<<" ";
		PreOrderTraversal(startnode->left);
		PreOrderTraversal(startnode->right);
	}
	void PreOrderTraversal(){
		PreOrderTraversal(rootnode);
	}
	bool Search(int d,node*startnode){
		if(startnode==NULL) return false;

		if(startnode->data==d){
			return true;
		}
		if(startnode->data>d){
			return Search(d,startnode->left);
		}
		if(startnode->data<d){
			 return Search(d,startnode->right);
		}
	}
	
	bool Search(int d){
		return Search(d,rootnode);
	}

};
int main(){
	BinarySearchTree bst;
	int n;
	cin>>n;
	int arr[100];
	for(int i=0;i<n;i++)cin>>arr[i];
		bst.BuildTree(arr,n);
		cout<<bst.Search(5)<<endl;
	return 0;
}

/*
8
10 12 8 6 7 9 11 15
*/
