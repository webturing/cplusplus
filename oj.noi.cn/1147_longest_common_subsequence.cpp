//
// Created by jal on 18-7-3.
//

#include <bits/stdc++.h>
using namespace std;
const int MAX = 5001;
int dp[MAX][MAX];
int main(){
    ifstream cin("input.txt");
    string a,b;
    cin >> a >> b;
    for(int i = 0; i < a.size(); i++){
        if(a[i] == b[0])
            dp[i][0] = 1;
    }
    for(int i = 0; i < b.size(); i++){
        if(a[0] == b[i]){
            dp[0][i] = 1;
        }
    }
    for(int i = 1; i < a.size(); i++){
        for(int j = 1; j < b.size(); j++){
            if(a[i] == b[j]){
                dp[i][j] = dp[i-1][j-1]+1;
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    cout << dp[a.size()-1][b.size()-1] << endl;
}