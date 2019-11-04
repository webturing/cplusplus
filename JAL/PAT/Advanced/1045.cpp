#include<bits/stdc++.h>
using namespace std;
template<typename T = int>
T read(){
	T x;
	cin >> x;
	return x;
}
int main(){
	int n =read(), m = read();
	vector<int>v(m), book(n+1);
	vector<vector<int>>check(n+1);
	for(auto &i: check){
		i.resize(n+1);
	}
	for(int i = 0; i < m; i++){
		v[i] = read();
		book[v[i]] = 1;
		for(int j = 0; j < i; j++){
			check[v[i]][v[j]] = -1;
			check[v[j]][v[i]] = 1;
		}
	}
	vector<int>a, dp;
	int l = read();
	for(int i = 0; i < l; i++){
		int x = read();
		if(!book[x])continue;
		int y = 1;
		for(int j = 0; j < a.size(); j++){
			if(check[a[j]][x] != -1){
				y = max(y, dp[j]+1);
			}
		}
		a.push_back(x);
		dp.push_back(y);
	}
	cout << *max_element(dp.begin(), dp.end()) << endl;
}
/*
3
3 1 2 3
6 1 2 2 2 1 3
*/