#include<bits/stdc++.h>
using namespace std;
struct Node
{
	int id, dis, time;
	bool operator<(const Node& that)const{
		if(dis != that.dis){
			return dis > that.dis;
		}
		return time > that.time;
	}
};
struct Node2
{
	int id, dis, time;
	bool operator<(const Node2& that)const{
		if(time != that.time){
			return time > that.time;
		}
		return dis > that.dis;
	}
};
int main(){
	int n, m;
	cin >> n >> m;
	vector<vector<int>>Gd(n), Gt(n);
	for(int i = 0; i < n; i++){
		Gd[i].resize(n);
		Gt[i].resize(n);
		for(int j = 0; j < n; j++){
			if(i !=j)Gd[i][j] = Gt[i][j] = INT_MAX/2;
			else Gd[i][j] = Gt[i][j] = 0;
		}
	}
	for(int i = 0; i < m; i++){
		int x, y, one_way, d, t;
		cin >> x >> y >> one_way >> d >> t;
		Gd[x][y] = min(d, Gd[x][y]);
		Gt[x][y] = min(t, Gt[x][y]);
		if(!one_way){
			Gd[y][x] = min(d, Gd[y][x]);
			Gt[y][x] = min(t, Gt[y][x]);
		}
	}
	int s, t;
	cin >> s >> t;
	vector<Node>dis(n);
	vector<int>book(n), path(n, -1);
	priority_queue<Node>Q;
	for(int i = 0; i < n; i++){
		dis[i] = {i, Gd[s][i], Gt[s][i]};
		path[i] = s;
		Q.push(dis[i]);
	}
	path[s] = -1;
	while(Q.size()){
		Node head = Q.top();
		Q.pop();
		if(book[head.id])continue;
		book[head.id]=1;
		for(int i = 0; i < n; i++){
			if(i == head.id)continue;
			if(dis[i].dis > head.dis + Gd[head.id][i]){
				dis[i].dis = head.dis + Gd[head.id][i];
				dis[i].time = head.time + Gt[head.id][i];
				path[i] = head.id;
				Q.push({i, dis[i].dis, dis[i].time});
			}else if(dis[i].dis == head.dis + Gd[head.id][i] and dis[i].time > head.time + Gt[head.id][i]){
				dis[i].time = head.time + Gt[head.id][i];
				path[i] = head.id;
				Q.push({i, dis[i].dis, dis[i].time});
			}
		}
	}
	vector<int>f1;
	int p = t;
	while(p != -1){
		f1.push_back(p);
		p = path[p];
	}
	int resDis = dis[t].dis;
	reverse(f1.begin(), f1.end());

	priority_queue<Node2>Q2;
	vector<Node2>dis2(n);
	book.resize(n);
	path.resize(n);
	for(auto &i:path)i = -1;
	for(int i = 0; i < n; i++){
		dis2[i] = {i, 1, Gt[s][i]};
		path[i] = s;
		book[i] = 0;
		Q2.push(dis2[i]);
	}
	path[s] = -1;
	while(Q2.size()){
		Node2 head = Q2.top();
		Q2.pop();
		if(book[head.id])continue;
		book[head.id]=1;
		for(int i = 0; i < n; i++){
			if(i == head.id)continue;
			if(dis2[i].time > head.time + Gt[head.id][i]){
				dis2[i].time = head.time + Gt[head.id][i];
				dis2[i].dis = head.dis +1;
				path[i] = head.id;
				Q2.push({i, dis2[i].dis, dis2[i].time});
			}else if(dis2[i].time == head.time + Gt[head.id][i] and dis2[i].dis > head.dis + Gd[head.id][i]){
				dis2[i].dis = head.dis +1;
				path[i] = head.id;
				Q2.push({i, dis2[i].dis, dis2[i].time});
			}
		}
	}
	vector<int>f2;
	p = t;
	while(p != -1){
		f2.push_back(p);
		p = path[p];
	}
	int resTime = dis2[t].time;
	reverse(f2.begin(), f2.end());
	if(f1 == f2){
		cout << "Distance = " << resDis << "; Time = " << resTime << ": "<< f1.front();
		for(int i = 1; i < f1.size(); i++){
			cout << " -> " << f1[i];
		}
		cout << endl;
	}else{
		cout << "Distance = " << resDis << ": " << f1.front();
		for(int i = 1; i < f1.size(); i++){
			cout << " -> " << f1[i];
		}
		cout << endl;
		cout << "Time = " << resTime << ": " << f2.front();
		for(int i = 1; i < f2.size(); i++){
			cout << " -> " << f2[i];
		}
		cout << endl;
	}
	return 0;
}