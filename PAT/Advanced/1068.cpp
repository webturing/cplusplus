#include<bits/stdc++.h>
using namespace std;
int main(){
	int n, m;
	vector<int>coin;
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		coin.push_back(x);
	}
	sort(coin.begin(), coin.end(), [](int a, int b)->bool{return a > b;});
	vector<int>dp(m+1);
	vector<bool>check[n];
	for(int i = 0; i < n; i++){
		check[i].resize(m+1);
	}
	for(int i = 0; i < n; i++){
		for(int j = m; j >= coin[i]; j--){
			if(dp[j] <= dp[j - coin[i]] + coin[i]){
				dp[j] = dp[j - coin[i]] + coin[i];
				check[i][j] = true;
			}
		}
	}
	if(dp[m] != m){
		cout << "No Solution" << endl;
	}else{
		vector<int>res;
		int i = n-1, j = m;
		while(j > 0){
			if(check[i][j]==true){
				j -= coin[i];
				res.push_back(coin[i]);
			}
			i--;
		}
		for(int i = 0; i < res.size(); i++){
			if(i)cout << " " << res[i];
			else cout << res[i];
		}
		cout << endl;
	}
}