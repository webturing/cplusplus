#include<bits/stdc++.h>

using namespace std;
template<typename T = int>
T read(){
	T x;
	cin >> x;
	return x;
}
int main(){
	int n = read();
	map<int, int>M;
	vector<int>v(n);
	for(int i = 0; i < n; i++){
		v[i] = read();
		M[v[i]]++;
	}
	for(int i = 0; i < n; i++){
		if(M[v[i]] == 1){
			cout << v[i] << endl;
			return 0;
		}
	}
	cout << "None" << endl;
}