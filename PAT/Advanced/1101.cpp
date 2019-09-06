#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	vector<int>v(n);
	for(auto&i: v){
		cin >> i;
	}
	vector<int>leftMax(n);
	leftMax[0] = INT_MIN;
	for(int i = 1; i < n; i++){
		leftMax[i] = max(leftMax[i-1], v[i-1]);
	}
	vector<int>rightMin(n);
	rightMin[n-1] = INT_MAX;
	for(int i = n-2; i >= 0; i--){
		rightMin[i] = min(rightMin[i+1], v[i+1]);
	}
	vector<int>res;
	for(int i = 0; i < n; i++){
		if(v[i] >= leftMax[i] and v[i] <= rightMin[i]){
			res.push_back(v[i]);
		}
	}
	sort(res.begin(), res.end());
	cout << res.size() << endl;
	for(int i = 0; i < res.size(); i++){
		if(i)cout << " " << res[i];
		else cout << res[i];
	}
	cout << endl;
}