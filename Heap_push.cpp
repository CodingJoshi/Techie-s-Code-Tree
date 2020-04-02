#include<iostream>
#include<vector>
using namespace std;


class maxheap
{
	vector<int>V;
public:
	maxheap(){
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
		while(i>1&&V[parent]<V[i]){
			swap(V[parent],V[i]);
			i=parent;
			parent=i/2;
		}
	}
	
};
int main(){

	#ifndef Techies
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
		maxheap m;
		int n;
		cin>>n;
		for(int i=0;i<n;i++){
			int d;cin>>d;
			m.Push(d);
		}
		
		m.Print();
	return 0;
}
