#include<bits/stdc++.h>
using namespace std;
template <typename T = int>
T read(){
	T x;
	cin >> x;
	return x;
}
const int n = read();
vector<vector<int>>v(n+1);
vector<int>book(n+1), M(n+1);
void dfs(int u){
	book[u] = 1;
	for(auto i: v[u]){
		if(!book[i]){
			dfs(i);
		}
	}
}
void dfs(int root, int u, int step){
	book[u] = 1;
	for(auto i: v[u]){
		if(!book[i]){
			dfs(root, i, step+1);
		}
	}
	M[u] = max(M[u], step);
	M[root] = max(M[root], step);
}
int main(){
	for(int i = 0; i < n - 1; i++){
		int x = read(), y = read();
		v[x].push_back(y);
		v[y].push_back(x);
	}
	int cnt = 0;
	for(int i = 1; i <= n; i++){
		if(!book[i]){
			dfs(i);
			cnt++;
		}
	}
	if(cnt > 1){
		cout << "Error: " << cnt << " components" << endl;
	}else{
		for(int i = 1; i <= n; i++){
			if(v[i].size() == 1){
				fill(book.begin(), book.end(), 0);
				dfs(i, i, 1);
			}
		}
		int MAX = *max_element(M.begin(), M.end());
		for(int i = 1; i <= n; i++){
			if(M[i] == MAX){
				cout << i << endl;
			}
		}
	}
}
/*
5
1 2
1 3
1 4
2 5

8
1 2
2 3
3 4
2 6
2 5
5 7
6 8
*/