#include<bits/stdc++.h>
using namespace std;
template<typename T = int>
T read(){
	T x;
	cin >> x;
	return x;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n = read(), k = read();
	map<string, set<int>>M;
	for(int i = 0; i < k; i++){
		int x = read(), m = read();
		for(int i = 0; i < m; i++){
			string name = read<string>();
			M[name].insert(x);
		}
	}
	for(int i = 0; i < n; i++){
		string name = read<string>();
		cout << name << " " << M[name].size();
		for(auto j: M[name]){
			cout << " " << j;
		}
		cout << endl;
	}
}