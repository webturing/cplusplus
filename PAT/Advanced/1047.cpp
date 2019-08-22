#include<bits/stdc++.h>
using namespace std;
template<typename T = int>
T read(){
	T x;
	cin >> x;
	return x;
}
int main(){
	int n = read(), k = read();
	vector<string>M[k+1];
	for(int i = 0; i < n; i++){
		string name = read<string>();
		int t = read();
		while(t--){
			M[read()].push_back(name);
		}
	}
	for(int i = 1; i <= k; i++){
		cout << i <<" " << M[i].size() << endl;
		sort(M[i].begin(), M[i].end());
		for(int j = 0; j < M[i].size(); j++){
			printf("%s\n", M[i][j].c_str());
		}
	}
}