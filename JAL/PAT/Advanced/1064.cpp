#include<bits/stdc++.h>
using namespace std;
const int N = 1005;
vector<int>a(N), v;
int n;
int pos = 0;
void dfs(int root){
	if(root > n)return;
	dfs(2*root);
	a[root] = v[pos++];
	dfs(2*root+1);
}
int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	dfs(1);
	for(int i = 1; i <= n; i++){
		if(i==1)cout << a[i];
		else cout << " " << a[i];
	}
	cout << endl;
}