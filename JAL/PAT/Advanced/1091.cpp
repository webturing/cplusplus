#include<bits/stdc++.h>
using namespace std;
int next_dir[6][3] = {
	{0, 0, -1},
	{0, 0, 1},
	{0, -1, 0},
	{0, 1, 0},
	{-1, 0, 0},
	{1, 0, 0},
};
struct Node
{
	int x, y, z;
};
int main(){
	int n, m, l, t;
	scanf("%d %d %d %d", &n, &m, &l, &t);
	vector<vector<vector<int>>>G(l), book(l);
	for(int i = 0; i < l; i++){
		G[i].resize(n);
		book[i].resize(n);
		for(int j = 0; j < n; j++){
			G[i][j].resize(m);
			book[i][j].resize(m);
			for(int k = 0; k < m; k++){
				scanf("%d", &G[i][j][k]);
			}
		}
	}
	int cnt = 0;
	for(int i = 0; i < l; i++){
		for(int j = 0; j < n; j++){
			for(int k = 0; k < m; k++){
				if(book[i][j][k] || G[i][j][k] == 0)continue;
				int sum = 0;
				queue<Node>Q;
				Q.push({i, j, k});
				book[i][j][k] = 1;
				while(Q.size()){
					Node head = Q.front();
					Q.pop();
					sum++;
					for(int p = 0; p < 6; p++){
						int tx = head.x + next_dir[p][0];
						int ty = head.y + next_dir[p][1];
						int tz = head.z + next_dir[p][2];
						if(tx < 0 || ty < 0 || tz < 0 || tx >= l || ty >= n || tz >= m || book[tx][ty][tz] || !G[tx][ty][tz])continue;
						Q.push({tx, ty, tz});
						book[tx][ty][tz] = 1;
					}
				}
				if(sum >= t)cnt+=sum;
			}
		}
	}
	cout << cnt << endl;
}