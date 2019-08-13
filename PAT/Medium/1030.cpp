#include<bits/stdc++.h>
using namespace std;
template<typename T=int>
T read(){
	T x;
	cin >> x;
	return x;
}
int main(){
	int n = read(), p = read();
	vector<int>v(n);
	for(auto &i: v){
		i = read();
	}
	sort(v.begin(), v.end());
	int best = 0;
	for(int i = 0; i < n; i++){
		int m = v[i];
		int j = upper_bound(v.begin(), v.end(), 1LL*m*p) - v.begin();
		best = max(best, j - i);
	}
	cout << best << endl;
}