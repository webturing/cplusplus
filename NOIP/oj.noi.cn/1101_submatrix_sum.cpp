//
// Created by jal on 18-6-29.
//

#include <bits/stdc++.h>
using namespace std;
int main(){
    ifstream cin("input.txt");
    int n,m;
    cin >> n >> m;
    vector<vector<int>>v(n+1, vector<int>(m+1, 0));
    for(int i = 1; i <= n; i ++ ){
        for(int j = 1; j <= m; j++){
            cin >> v[i][j];
        }
    }
    vector<vector<int>>sum(n+1,vector<int>(m+1,0));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            sum[i][j] = sum[i][j-1] + sum[i-1][j] + v[i][j] - sum[i-1][j-1];
        }
    }
    int q;
    cin >> q;
    while(q--){
        int sx,sy,ex,ey;
        cin >> sx >> sy >> ex >> ey;
        cout << sum[ex][ey] - sum[sx-1][ey] - sum[ex][sy-1] + sum[sx-1][sy-1] << endl;
    }
}