#include<bits/stdc++.h>
using namespace std;
vector<pair<int, int>>v;
vector<int>preorder, a;
map<int, int>M;
int n;
void dfs(int root){
	if(root == -1)return;
	dfs(v[root].first);
	preorder.push_back(root);
	dfs(v[root].second);
}
int main(){
	cin >> n;
	v.resize(n);
	for(int i = 0; i < n; i++){
		cin >> v[i].first >> v[i].second;
	}
	a.resize(n);
	for(auto &i: a){
		cin >> i;
	}
	sort(a.begin(), a.end());
	dfs(0);
	assert(preorder.size() == n);

	for(int i = 0; i < n; i++){
		M[preorder[i]] = a[i];
	}
	
	queue<int>Q;
	Q.push(0);
	vector<int>res;
	while(Q.size()){
		int head = Q.front();
		res.push_back(M[head]);
		Q.pop();
		if(v[head].first != -1)
		Q.push(v[head].first);
		if(v[head].second != -1)
		Q.push(v[head].second);
	}
	for(int i = 0; i < res.size(); i++){
		if(i)cout << " " << res[i];
		else cout << res[i];
	}
	cout << endl;
}