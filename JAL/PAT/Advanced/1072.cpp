#include<bits/stdc++.h>
using namespace std;
struct Station
{
	double minn, ave;
	int id;
};
int main(){
	int N, M, K, D;
	cin >> N >> M >> K >> D;
	vector<vector<double>>G(N+M+1);
	for(int i = 1; i < G.size(); i++){
		G[i].resize(N+M+1);
		for(int j = 1; j < G[i].size(); j++){
			G[i][j] = INT_MAX/2;
		}
	}
	for(int i = 1; i < G.size(); i++){
		G[i][i] = 0;
	}
	for(int i = 0; i < K; i++){
		string p1, p2;
		double d;
		cin >> p1 >> p2 >> d;
		int x, y;
		if(p1[0]=='G')x = N+stoi(p1.substr(1));
		else x = stoi(p1);
		if(p2[0]=='G')y = N+stoi(p2.substr(1));
		else y = stoi(p2);
		G[x][y] = d;
		G[y][x] = d;
	}
	vector<Station>station;
	for(int source = N+1; source <= N+M; source++){
		vector<int>book(N+M+1);
		vector<double>dis(N+M+1);
		priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>>Q;
		for(int i = 1; i <= N+M; i++){
			dis[i] = G[source][i];
			Q.push({dis[i], i});
		}
		book[source] = true;
		while(Q.size()){
			pair<double, int>head = Q.top();
			Q.pop();
			if(book[head.second])continue;
			book[head.second] = true;
			for(int i = 1; i <= N+M; i++){
				if(dis[i] > head.first + G[head.second][i]){
					dis[i] = head.first + G[head.second][i];
					Q.push({dis[i], i});
				}
			}
		}
		double minn = *min_element(dis.begin()+1, dis.begin()+N+1);
		double sum = accumulate(dis.begin()+1, dis.begin()+N+1, 0);
		double ave = sum / N;
		double maxn = *max_element(dis.begin()+1, dis.begin()+N+1);
		if(maxn <= D)
			station.push_back({minn, ave, source-N});
	}
	if(station.empty()){
		cout << "No Solution" << endl;
		return 0;
	}
	sort(station.begin(), station.end(), [](Station a, Station b)->bool{
		if(a.minn != b.minn)return a.minn > b.minn;
		if(a.ave != b.ave)return a.ave < b.ave;
		return a.id < b.id;
	});
	cout << "G"<<station.front().id << endl;
	cout << fixed << setprecision(1)<< station.front().minn+0.05 << " " << station.front().ave+0.05 << endl;
	return 0;
}
/*
4 3 11 5
1 2 2
1 4 2
1 G1 4
1 G2 3
2 3 2
2 G2 1
3 4 2
3 G3 2
4 G1 3
G2 G1 1
G3 G2 2
*/