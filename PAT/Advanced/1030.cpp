#include <bits/stdc++.h>
using namespace std;
template<typename T = int>
T read(){
	T x;
	cin >> x;
	return x;
}
struct Node
{
	int d, c, u;
	bool operator<(const Node& that)const{
		if(d != that.d)return d > that.d;
		return c > that.c;
	}
};
int main(){
	int n = read(), m = read(), start = read(), destination = read();
	int a[n][n], b[n][n];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(i != j){
				a[i][j] = b[i][j] = INT_MAX/2;
			}else{
				a[i][j] = b[i][j] = 0;
			}
		}
	}
	for(int i = 0; i < m; i++){
		int x = read(), y = read(), d = read(), c = read();
		a[x][y] = min(a[x][y], d);
		a[y][x] = min(a[y][x], d);
		b[x][y] = min(b[x][y], c);
		b[y][x] = min(b[y][x], c);
	}
	priority_queue<Node>Q;
	vector<int>dis(n), cos(n), book(n), f(n, -1);
	for(int i = 0; i < n; i++){
		dis[i] = a[start][i];
		cos[i] = b[start][i];
		Q.push({dis[i], cos[i], i});
		f[i] = start;
	}
	while(Q.size()){
		Node head = Q.top();
		Q.pop();
		if(book[head.u])continue;
		book[head.u] = 1;
		for(int i = 0; i < n; i++){
			if(dis[i] > dis[head.u] + a[head.u][i]){
				dis[i] = dis[head.u] + a[head.u][i];
				cos[i] = cos[head.u] + b[head.u][i];
				f[i] = head.u;
				Q.push({dis[i], cos[i], i});
			}else if(dis[i] == dis[head.u] + a[head.u][i] and cos[i] > cos[head.u] + b[head.u][i]){
				cos[i] = cos[head.u] + b[head.u][i];
				f[i] = head.u;
				Q.push({dis[i], cos[i], i});
			}
		}
	}
	vector<int>path;
	int d = destination;
	while(d != start){
		path.push_back(d);
		d = f[d];
	}
	path.push_back(start);
	reverse(path.begin(), path.end());
	for(auto i: path){
		cout << i << ' ';
	}
	cout << dis[destination] << ' ' << cos[destination] << endl;
}