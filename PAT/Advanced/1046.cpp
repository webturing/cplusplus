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
	vector<int>v(n);
	int sum = 0;
	for(int i = 0; i < n; i++){
		v[i] = read();
		sum += v[i];
	}
	vector<int>partial(n+1);
	partial_sum(v.begin(), v.end(), partial.begin()+1);
	int m = read();
	while(m--){
		int x = read(), y = read();
		if(y < x)swap(x, y);
		int a = partial[y-1] - partial[x-1];
		int b = sum - a;
		cout << min(a, b) << endl;
	}
}