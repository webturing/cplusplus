//
// Created by jal on 18-7-8.
//

#include <bits/stdc++.h>
using namespace std;
int n;
int cnt = 0;
//int out[1000][10];out[][i] = c表示第i行放置在c列,
int vis[10];///vis[i] = c表示第i行放置在第c列
bool check(int r, int c){//第r行第c列是否可以放皇后
    for(int i = 0; i < r; i++){
        if(vis[i] == c)return false;
        if(vis[i] - c == i - r || vis[i] - c == r - i)return false;
    }
    return true;
}
void dfs(int r){
    if( r >= n){
        //for(int i = 0; i < n; i++)
        //out[cnt][i] = vis[i];
        cnt++;
    }
    for(int i = 0; i < n; i++){
        if(check(r, i)){
            vis[r] = i;
            dfs(r+1);
            vis[r] = -1;
        }
    }
}
int main(){
    ifstream cin("input.txt");
    cin >> n;
    dfs(0);
    cout << cnt << endl;
}