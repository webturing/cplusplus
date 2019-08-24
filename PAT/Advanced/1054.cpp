#include<bits/stdc++.h>
using namespace std;
template<typename T = int>
T read(){
	T x;
	cin >> x;
	return x;
}
int main(){
	int n = read(), m = read();
	map<int, int>M;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			M[read()]++;
		}
	}
	int res = 0, val = 0;
	for(auto i: M){
		if(val < i.second){
			val = i.second;
			res = i.first;
		}
	}
	cout << res << endl;
}