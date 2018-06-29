//
// Created by jal on 18-6-29.
//

#include <bits/stdc++.h>
using namespace std;
const int MOD = 10007;
const int N = 1001;
int main(){
    ifstream cin("input.txt");
    int dp[N][N];
    for(int i = 1; i < N; i++ ){
        dp[i][1] = 1;
        dp[i][i] = 1;
    }
    for(int i = 2; i < N; i++){
        for(int j = 2; j < i; j++){
            dp[i][j] = (dp[i-1][j] + dp[i-1][j-1]) % MOD;
        }
    }
    int n;
    cin >> n;
    while(n--){
        int a,b;
        cin >> a>>b;
        a++;b++;
        cout << dp[a][b]<<endl;
    }
}