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
/*
	bool IsBalancedBT(node* startnode){
		/// Base Case:
		if(startnode==NULL)return true;
		/// Recursive Case:
		if(abs(Height(startnode->left)-Height(startnode->right))<=1){
			bool ans=IsBalancedBT(startnode->left);
			if(ans==false)return false;
			return IsBalancedBT(startnode->right);
		}
		else return false;
	}
*/
	pair<int,bool> IsBalancedBT(node*startnode){
			pair<int,bool>ans;
			// base case:
			if(startnode==NULL){
				ans.first=-1;
				ans.second=true;
				return ans;
			}

			//recursive Case:
			pair<int,int>lans,rans;
			lans=IsBalancedBT(startnode->left);
			rans=IsBalancedBT(startnode->right);
			if(abs(lans.first-rans.first)<=1&&lans.second&&rans.second)ans.second=true;
			else ans.second=false;

			ans.first=max(lans.first,rans.first)+1;

			return ans;
	}

	bool IsBalancedBT(){
		pair<int,bool>ans;
		ans= IsBalancedBT(rootnode);
		return ans.second;
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
