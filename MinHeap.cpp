#include<iostream>
#include<vector>
using namespace std;


class minheap
{
	vector<int>V;
public:
	minheap(){
		V.push_back(-1);
	}

	void Print(){
		for(int i=1;i<V.size();i++)cout<<V[i]<<" ";
			cout<<endl;
	}
	void Push(int d){
		V.push_back(d);
		int i=V.size()-1;
		int parent=i/2;
		while(i>1&&V[parent]>V[i]){
			swap(V[parent],V[i]);
			i=parent;
			parent=i/2;
		}
	}

	void heapify(int i){
		int left=2*i;
		int right=2*i+1;
		int smallest=i;
		if(left<V.size()&&V[smallest]>V[left]){
			smallest=left;
		}
		if(right<V.size()&&V[smallest]>V[right]){
			smallest=right;
		}
		if(smallest==i)return;
		swap(V[smallest],V[i]);
		heapify(smallest);
	}

	void Pop(){
		if(V.size()==1)return;
		if(V.size()==2)V.pop_back();
		swap(V[1],V[V.size()-1]);
		V.pop_back();
		heapify(1);
	}

	int front(){
		return V[1];
	}
	
};
int main(){
/*
	#ifndef Techies
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
  */
		minheap m;
		int n;cin>>n;
		for(int i=0;i<n;i++){
			int d;cin>>d;
			m.Push(d);
		}
	m.Print();
	cout<<m.front()<<endl;
	m.Pop();
	m.Print();
	return 0;
}
