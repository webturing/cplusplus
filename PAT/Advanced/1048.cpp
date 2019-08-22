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
	vector<int>v;
	for(int i = 0; i < n; i++){
		v.push_back(read());
	}
	sort(v.begin(), v.end());
	for(int i = 0; i < n and 2*v[i] <= m; i++){
		int y = m - v[i];
		int p = *lower_bound(v.begin()+i+1, v.end(), y);
		if(y == p){
			cout << v[i] << " " << y << endl;
			return 0;
		}
	}
	cout << "No Solution" << endl;
}