//
// Created by jal on 2019-07-29.
//

#include <bits/stdc++.h>
using namespace std;
template<typename T = int>
T read(){
    T x;
    cin >> x;
    return x;
}
template <typename T = int>
void OO(vector<T>v, string s=""){
    cerr<<s <<":"<< endl;
    for(auto i: v){
        cerr << i << ' ';
    }
    cerr << endl;
}
typedef unsigned long long ll;
const int N = 1001;
int v[N][N];
int vis[N];
int n;
void dfs(int u){
    vis[u] = 1;
    for(int i = 1; i <= n; i++){
        if(v[u][i] and !vis[i]){
            dfs(i);
        }
    }
}
int main(){
    freopen("input.txt", "r", stdin);
    n = read();
    int m = read(), k = read();
    for(int i = 0; i < m; i++){
        int x = read(), y = read();
        v[x][y] = v[y][x] = 1;
    }
    for(int i = 0; i < k; i++){
        fill(vis+1, vis+n+1, 0);
        vis[read()] = 1;
        int cnt = 0;
        for(int j = 1; j <= n; j++){
            if(!vis[j]){
                cnt++;
                dfs(j);
            }
        }
        cout << cnt - 1 << endl;
    }
}