#include<bits/stdc++.h>
using namespace std;
template<typename T = int>
T read(){
	T x;
	cin >> x;
	return x;
}
string rev(string s){
	string ret = s;
	for(auto &i: ret){
		if(i == 'C')i = 'P';
		else i = 'C';
	}
	return ret;
}
vector<string>dfs(int k){
	if(k == 1){
		return vector<string>{"CC", "PC"};
	}
	vector<string>v(1<<k);
	vector<string>v2 = dfs(k-1);
	int r = 1<<(k-1);
	for(int i = 0; i < r;i++){
		v[i] = v2[i]+v2[i];
	}
	for(int i = r; i < v.size(); i++){
		v[i] = rev(v2[i-r]) + v2[i-r];
	}
	return v;
}
int main(){
	int t = read();
	while(t--){
		int k = read();
		vector<string>v = dfs(k);
		for(auto i: v){
			cout << i << endl;
		}
	}
}