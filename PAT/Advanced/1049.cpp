#include<bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
int n;
vector<int>v;
void init(){
	while(n){
		v.push_back(n%10);
		n/=10;
	}
	reverse(v.begin(), v.end());
}
ll pow(int a, int n){
	ll ret = 1;
	for(int i = 1; i <= n; i++){
		ret *= a;
	}
	return ret;
}
ll dp[10][10][2];
ll dfs(int pos, int val, int limit){
	// cerr << "pos = "<<pos << ", val = " << val << ", limit = " << limit << ", height = " << height << ", dp[pos][val][limit] = " << dp[pos][val][limit] << endl;
	if(dp[pos][val][limit])return dp[pos][val][limit];
	if(pos == v.size()-1){
		if(val==1)return dp[pos][val][limit] = 1;
		return dp[pos][val][limit] = 0;
	}
	ll ret = 0;
	if(val == 1){
		if(!limit)
			ret += pow(10, v.size() - pos - 1);
		else {
			ll posLimitSum = 0;
			for(int i = pos+1; i < v.size(); i++){
				posLimitSum = posLimitSum*10+v[i];
			}
			posLimitSum++;
			ret += posLimitSum;
		}
	}
	int up = limit? v[pos+1]: 9;
	for(int i = 0; i <= up; i++){
		ret += dfs(pos+1, i, limit and i == up);
	}
	// cerr << "ret = " << ret << endl;
	return dp[pos][val][limit] = ret;
}
int main(){
	cin >> n;
	init();
	ll cnt = 0;
	for(int i = 0; i <= v.front(); i++){
		// cerr << "0, i = " << i << " i==v.front():" << (i == v.front()) << " height = " << height << endl;
		cnt += dfs(0, i, i == v.front());
		// cerr << "cnt = " << cnt << endl;
	}
	cout << cnt << endl;;
}