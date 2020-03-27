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
class binaryTree
{
	node*rootnode;
public:
	binaryTree(){
		rootnode=NULL;
	}	
	
	node* buildTree( int *preorder,int si1,int ei1,int *inorder,int si2,int ei2){
			/// BASE cASE:
			if(si1>ei1)return NULL;

			/// Recursive Case :
				int i;
			for( i=si2;i<ei2;i++){
				if(inorder[i]==preorder[si1])break;
			}
			int len=i-si2;
			node* startnode=new node(preorder[si1]);
			startnode->left=buildTree(preorder,si1+1,si1+len,inorder,si2,i-1);
			startnode->right=buildTree(preorder,si1+len+1,ei1,inorder,i+1,ei2);
			return startnode;

	}



	void buildTree(int *preorder,int *inorder,int n){
		rootnode=buildTree(preorder,0,n-1,inorder,0,n-1);
	}
	


void PrintLevelOrder(){
        cout<<"LevelOrder:"<<endl;
        if (rootnode==NULL) return;
        queue<node*> q;
        q.push(rootnode);
        q.push(NULL);
        while (!q.empty()){
            node* f=q.front();
            q.pop();
            if (f==NULL){
                cout<<endl;
                if (!q.empty()) q.push(NULL);
            } else {
                cout<<f->data<<" ";
                if (f->left!=NULL) q.push(f->left);
                if (f->right!=NULL) q.push(f->right);
            }
        }
        cout<<endl;
    }


};

int main(){
	binaryTree bt;
	int n;
	cin>>n;
	int preorder[100],inorder[100];
	for(int i=0;i<n;i++)cin>>preorder[i];
	for(int i=0;i<n;i++)cin>>inorder[i];
	bt.buildTree(preorder,inorder,n);
	bt.PrintLevelOrder();
	return 0;
}














/*
9
1 3 4 6 7 8 10 13 14
8 3 1 6 4 7 10 14 13
*/
