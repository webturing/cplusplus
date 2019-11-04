//
// Created by jal on 18-6-30.
//

#include <bits/stdc++.h>
using namespace std;
const int MAXN = 110;
int a[MAXN][MAXN],b[MAXN][MAXN],c[MAXN][MAXN];
int main(){
    ifstream cin("input.txt");
    int n,m,k;
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= k; j++){
            cin >> b[i][j];
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= k; j++){
            for(int r = 1; r <= m; r++){
                c[i][j] += a[i][r] * b[r][j];
            }
        }
    }
    for(int i = 1; i <= n; i++){
        copy(c[i]+1,c[i]+k+1, ostream_iterator<int>(cout," "));
        cout << endl;
    }
}