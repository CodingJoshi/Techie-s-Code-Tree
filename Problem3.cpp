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
	void PreOrderTraversal(node*start){
			// base case:
				if(start==NULL)return;	

			//Recursive Case:
			cout<<start->data<<" ";
			PreOrderTraversal(start->left);
			PreOrderTraversal(start->right);
	}
	void PreOrderTraversal(){
		cout<<"Pre-Order Traversal: \n";
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


	node* deleteLeaves(node* startnode){
		/// Base case:
		if(startnode==NULL)return NULL;
		if(startnode->left==NULL&&startnode->right==NULL){
			delete startnode;
			return NULL;
		}

		/// Recusive case:
		startnode->left=deleteLeaves(startnode->left);
		startnode->right=deleteLeaves(startnode->right);
	}
	void deleteLeaves(){
		deleteLeaves(rootnode);
	}

};
int main(){
	BinaryTree bt;
	bt.BulidTree();
	bt.PreOrderTraversal();
	bt.PostOrderTraversal();
	bt.INOrderTraversal();
	bt.LevelorderTraversal();
	bt.deleteLeaves();
	bt.PreOrderTraversal();
	bt.PostOrderTraversal();
	bt.INOrderTraversal();
	bt.LevelorderTraversal();
	return 0;
}

/*
1 2 3 -1 -1 4 8 -1 -1 9 -1 -1 5 6 -1 -1 7 10 -1 11 -1 -1 -1
*/
