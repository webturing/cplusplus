#include<bits/stdc++.h>
using namespace std;
template<typename T = int>
T read(){
	T x;
	cin >> x;
	return x;
}
vector<int>T(100);
vector<pair<int, int>>v[100];
vector<int>out;
int n, m, S;
void dfs(int root, int sum){
	if(v[root].empty()){
		if(sum == S){
			for(int i = 0; i < out.size(); i++){
				if(i)cout << " " << out[i];
				else cout << out[i];
			}
			cout << endl;
		}
		return;
	}
	if(sum >= S)return;
	for(auto i: v[root]){
		out.push_back(i.second);
		dfs(i.first, sum + i.second);
		out.pop_back();
	}
}
int main(){
	n = read(), m = read(), S = read();
	for(int i = 0; i < n; i++){
		T[i] = read();
	}
	for(int i = 0; i < m; i++){
		int id = read(), k = read();
		while(k--){
			int j =read();
			v[id].push_back({j, T[j]});
		}
		sort(v[id].begin(), v[id].end(), [](pair<int, int> a, pair<int, int> b)->bool{return a.second > b.second;});
	}
	vector<int>res;
	out.push_back(T[0]);
	dfs(0, T[0]);
}