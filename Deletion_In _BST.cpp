#include<iostream>
#include<queue>
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
		cout<<"Post-Order Traversal: \n";
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
		cout<<"In-Order Traversal: \n";
		INOrderTraversal(rootnode);
		cout<<endl;
	}
	void LevelorderTraversal(){
		queue<node*>q;
		cout<<" Level-order Traversal "<<endl;
		q.push(rootnode);
		q.push(NULL);
		while(!q.empty()){
			node*temp=q.front();
			q.pop();
			if(temp==NULL){
					cout<<endl;
					if(!q.empty())q.push(NULL);
			}
			else{
				cout<<temp->data<<" ";
			if(temp->left!=NULL)	q.push(temp->left);
			if(temp->right!=NULL)	q.push(temp->right);
			}
		}
	}

	node* find(node*startnode){

		while(startnode->right!=NULL){
				startnode=startnode->right;
		}
		return startnode;

	}

	node* deleteNode(node*startnode,int d){
		if(d>startnode->data){
			startnode->right=deleteNode(startnode->right,d);
			return startnode;
		}
		if(d<startnode->data){
			startnode->left=deleteNode(startnode->left,d);
			return startnode;
		}

		if(d==startnode->data){
			if(startnode->left==NULL&&startnode->right==NULL){
				delete startnode;
				return NULL;
			}
			if(startnode->left==NULL){
				node*temp=startnode->right;
				delete startnode;
				return temp;
			}
			if(startnode->right==NULL){
				node*temp=startnode->left;
				delete startnode;
				return temp;
			}
			//find the left ka rightmost elelment
			node* temp=find(startnode->left);
			swap(startnode->data,temp->data);
			startnode->left=deleteNode(startnode->left,temp->data);
		}
	}

	void deleteNode(int d){
		rootnode=deleteNode(rootnode,d);
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
	t.PostOrderTraversal();
	t.INOrderTraversal();
	t.LevelorderTraversal();
	int d;cin>>d;
	t.deleteNode(d);
	t.PreOrderTraversal();
	t.PostOrderTraversal();
	t.INOrderTraversal();
	t.LevelorderTraversal();
	return 0;
}
/*
11
8 3 10 1 6 14 7 4 12 13 11
*/
