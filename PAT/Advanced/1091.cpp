#include<bits/stdc++.h>
using namespace std;
int cnt = 0, sum = 0;
const int L = 61, N = 1290, M = 130;
int n, m, l, t;
int G[L][N][M], book[L][N][M];
int next_dir[6][3] = {
	{0, 0, -1},
	{0, 0, 1},
	{0, -1, 0},
	{0, 1, 0},
	{-1, 0, 0},
	{1, 0, 0},
};
void dfs(int x, int y, int z){
	sum++;
	book[x][y][z] = 1;
	for(int i = 0; i < 6; i++){
		int tx = x + next_dir[i][0];
		int ty = y + next_dir[i][1];
		int tz = z + next_dir[i][2];
		if(tx < 0 || ty < 0 || tz < 0 || tx >= l || ty >= n || tz >= m || G[tx][ty][tz]==0||book[tx][ty][tz])continue;
		dfs(tx, ty, tz);
	}
}
int main(){
	scanf("%d %d %d %d", &n, &m, &l, &t);
	for(int i = 0; i < l; i++){
		for(int j = 0; j < n; j++){
			for(int k = 0; k < m; k++){
				scanf("%d", &G[i][j][k]);
			}
		}
	}
	for(int i = 0; i < l; i++){
		for(int j = 0; j < n; j++){
			for(int k = 0; k < m; k++){
				if(book[i][j][k] || G[i][j][k] == 0)continue;
				sum = 0;
				dfs(i, j, k);
				if(sum >= t)cnt+=sum;
			}
		}
	}
	cout << cnt << endl;
}