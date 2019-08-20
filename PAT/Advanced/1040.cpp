#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	while(getline(cin, s))
	{
		vector<int>dp(s.size(), 1), same(s.size(), 1);
		for(int i = 1; i < s.size(); i++){
			if(s[i] == s[i-1]){
				same[i] = same[i-1] + 1;
			}
			int j = i - dp[i-1] - 1;
			if(j >= 0 and s[j] == s[i]){
				dp[i] = dp[i-1] + 2;
			}else{
				dp[i] = same[i];
			}
		}	
		cout << *max_element(dp.begin(), dp.end()) << endl;
	}
}

/*
123
1223
12223
122223
1222223
12221
1222
1
12
11211
121
11

*/