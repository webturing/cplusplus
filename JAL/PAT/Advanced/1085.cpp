#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
	int n, k;
	cin >> n >> k;
	vector<ll>v(n);
	for(int i = 0; i < n; i++){
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	int best = 0;
	for(int i = 0; i < n; i++){
		ll minimum = v[i];
		ll maximum = minimum*k;
		int j = upper_bound(v.begin(), v.end(), maximum) - v.begin();
		best = max(best, j - i);
	}
	cout << best << endl;
}