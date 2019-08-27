#include<bits/stdc++.h>
using namespace std;
struct Node
{
	int addr, val, next;
};
int main(){
	int startAddr, n, k;
	scanf("%d %d %d", &startAddr, &n, &k);
	map<int, Node>M;
	for(int i = 0; i < n; i++){
		int addr, val, next;
		cin >> addr >> val >> next;
		M[addr] = {addr, val, next};
	}
	vector<Node>v;
	while(~startAddr){
		v.push_back(M[startAddr]);
		startAddr = M[startAddr].next;
	}
	int first = k-1;
	if(k > v.size())first = 0;
	startAddr = v[first].addr;
	for(int i = 0; i+1 < v.size()/k*k; i++){
		v[i+1].next = v[i].addr;
	}
	if(v.size()%k==0){
		for(int i = 0; i+2*k-1 < v.size(); i+=k)
			v[i].next = v[i+2*k-1].addr;
		v[v.size()-k].next = -1;
	}else{
		for(int i = 0; i+2*k-1 < v.size(); i+= k){
			v[i].next = v[i+2*k-1].addr;
		}
		v[v.size()/k*k-k].next = v[v.size()/k*k].addr;

	}
	M.clear();
	for(int i = 0; i < v.size(); i++){
		M[v[i].addr] = v[i];
	}
	while(1){
		if(M[startAddr].next==-1){
			printf("%05d %d -1\n", startAddr, M[startAddr].val);
			break;
		}else{
			printf("%05d %d %05d\n", startAddr, M[startAddr].val, M[startAddr].next);
		}
		startAddr = M[startAddr].next;
	}
}