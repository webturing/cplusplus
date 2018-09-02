
//
// Created by jal on 18-9-2.
//
#include <bits/stdc++.h>
using namespace std;
int a[50][50];
int book[50][50];
int end_x, end_y;
int result = 0x7fffffff;
int dir[4][2] = {0,1,0,-1,1,0,-1,0};
int n,m;
void dfs(int x, int y, int step){
    if(x == end_x && y == end_y){
        result = min(result, step);
        return;
    }
    for(int k = 0; k < 4; k++){
        int tx = x + dir[k][0];
        int ty = y + dir[k][1];
        if(tx >= n || ty >= m || tx < 0 || ty < 0 || a[tx][ty] == 1)continue;
        a[tx][ty] = 1;
        dfs(tx,ty,step+1);
        a[tx][ty] = 0;
    }
}
int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    int x,y;
    cin >> x >> y >> end_x >> end_y;
    dfs(x, y, 0);
    cout << result << endl;
}
