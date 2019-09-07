#include<bits/stdc++.h>
using namespace std;
int n;
struct Node
{
	int val;
	int end = 1;
};
map<int, Node>M;
void insert(int root, int x){
	if(M[root].end){
		M[root].val = x;
		M[root].end = 0;
		M[2*root].end = 1;
		M[2*root+1].end = 1;
		return;
	}
	if(x <= M[root].val){
		insert(2*root, x);
	}else{
		insert(2*root+1, x);
	}
}
int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		insert(1, x);
	}
	queue<pair<int, int>>Q;
	Q.push({1, 1});
	map<int, int>C;
	while(Q.size()){
		pair<int, int>head = Q.front();
		C[head.first]++;
		Q.pop();
		if(!M[2*head.second].end){
			Q.push({head.first+1, 2*head.second});
		}
		
		if(!M[2*head.second+1].end){
			Q.push({head.first+1, 2*head.second+1});
		}
		
	}
	int len = C.size();
	cout << C[len] << " + " << C[len-1] << " = " << C[len] + C[len-1] << endl;
	return 0;
}