#include<bits/stdc++.h>
using namespace std;
template<typename T = int>
T read(){
	T x;
	cin >> x;
	return x;
}
struct Node
{
	int u, d, c;
	bool operator<(const Node& that)const{
		if(d != that.d){
			return d > that.d;
		}
		return c > that.c;
	}
};
int main(){
	int n = read(), m = read(), start = read(), destination = read();
	vector<vector<Node>>g(n);
	int x, y, p, q;
	for(int i = 0; i < m; i++){
		x = read(), y = read(), p = read(), q = read();
		g[x].push_back({y, p, q});
		g[y].push_back({x, p, q});
	}
	vector<Node>Dij(n);
	for(int i = 0; i < n; i++){
		Dij[i] = {INT_MAX/2, INT_MAX/2, i};
	}
	Dij[start] = {0, 0, start};
	vector<int>book(n), F(n, -1);
	priority_queue<Node>Q;
	for(auto i: g[start]){
		Dij[i.u] = i;
		Q.push(Dij[i.u]);
		F[i.u] = start;
	}
	Q.push(Dij[start]);
	while(Q.size()){
		Node head = Q.top();
		Q.pop();
		if(book[head.u])continue;
		book[head.u] = 1;
		for(auto node: g[head.u]){
			if(Dij[node.u].d > Dij[head.u].d + node.d){
				Dij[node.u].d = Dij[head.u].d + node.d;
				Dij[node.u].c = Dij[head.u].c + node.c;
				F[node.u] = head.u;
				Q.push(Dij[node.u]);
			}else if(Dij[node.u].d == Dij[head.u].d + node.d and Dij[node.u].c > Dij[head.u].c + node.c){
				Dij[node.u].c = Dij[head.u].c + node.c;
				F[node.u] = head.u;
				Q.push(Dij[node.u]);
			}
		}
	}
	int d1 = destination;
	vector<int>path;
	path.push_back(d1);
	while(~F[d1]){
		d1 = F[d1];
		path.push_back(d1);
	}
	for(auto i = path.rbegin(); i < path.rend(); i++){
		cout << *i << ' ';
	}
	cout << Dij[destination].d << " " << Dij[destination].c << endl;
}