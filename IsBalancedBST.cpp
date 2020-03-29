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

	bool IsBalancedBT(node*startnode){
			// base case:
			if(startnode==NULL){
				return true;
			}

			//recursive Case:
			bool lans=IsBalancedBT(startnode->left);
			if(lans==false)return false;
			bool rans=IsBalancedBT(startnode->right);
			if(rans==false)return false;
			if(abs(Height(startnode->left)-Height(startnode->right))<=1)return true;
			return false;

	}
	bool IsBalancedBT(){
		return IsBalancedBT(rootnode);
	}


};
int main(){
	BinaryTree bt;
	bt.BulidTree();
	cout<<bt.IsBalancedBT()<<endl;
	return 0;
}

/*
2 7 2 -1 -1 6 5 -1 -1 11 -1 -1 5 10 -1 -1 9 4 -1 -1 -1
	3 1 7 -1 -1 2 -1 -1 5 4 -1 6 -1 -1 -1 
*/



