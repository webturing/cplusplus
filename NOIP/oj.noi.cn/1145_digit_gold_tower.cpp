//
// Created by jal on 18-6-29.
//

#include <bits/stdc++.h>
using namespace std;
int main(){
    ifstream cin("input.txt");
    int n;
    cin >> n;
    vector<vector<int>>v(n,vector<int>(n,0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            cin >> v[i][j];
        }
    }
    int dp[n][n];
    memset(dp,0,sizeof(dp));
    dp[0][0] = v[0][0];
    for(int i = 1; i < n; i++){
        dp[i][0] = dp[i-1][0] + v[i][0];
    }
    for(int i = 1; i < n; i++){
        for(int j = 1; j < n; j++){
            dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]) + v[i][j];
        }
    }
    cout << *max_element(dp[n-1],dp[n-1]+n) << endl;
}