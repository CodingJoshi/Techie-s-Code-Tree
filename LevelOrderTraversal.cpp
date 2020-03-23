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
	void LevelOrderTraversal(){
		queue<node*>q;
		q.push(rootnode);
		while(!q.empty()){
			node*temp=q.front();
			cout<<temp->data<<" , ";
			q.pop();
		if(temp->left!=NULL)	q.push(temp->left);
		if(temp->right!=NULL)	q.push(temp->right);
		}
		cout<<endl;
	}

};
int main(){
	BinaryTree bt;
	bt.BulidTree();
	bt.LevelOrderTraversal();
	return 0;
}

/*
5 6 8 4 -1 -1 3 -1 -1 -1 7 9 -1 -1 6 -1 -1 
*/
