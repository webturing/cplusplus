#include<bits/stdc++.h>
using namespace std;
struct Node
{
	int id, dis, val, sum, num, minDis;
	bool operator<(const Node& that)const{
		if(dis != that.dis)return dis > that.dis;
		if(sum != that.sum)return sum < that.sum;
		return num > that.num;
	}
};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, k;
	string s1;
	cin >> n >> k >> s1;
	map<string, int>M;
	int cnt = 0;
	M[s1] = cnt++;
	vector<int>Value(n);
	for(int i = 1; i < n; i++){
		string s;
		int x;
		cin >> s >> x;
		M[s] = cnt++;
		Value[M[s]] = x;
	}
	int D = M["ROM"];
	vector<int>G[n];
	for(int i = 0; i < n; i++){
		G[i].resize(n);
		for(int j = 0; j < n; j++){
			if(i != j){
				G[i][j] = INT_MAX/2;
			}
		}
	}
	for(int i = 0; i < k; i++){
		string s1, s2;
		int x;
		cin >> s1 >> s2 >> x;
		G[M[s1]][M[s2]] = min(x, G[M[s1]][M[s2]]);
		G[M[s2]][M[s1]] = min(x, G[M[s2]][M[s1]]);
	}
	vector<int>book(n), dis(n), sum(n), num(n), Path(n), minDis(n);
	priority_queue<Node>Q;
	for(int i = 1; i < n; i++){
		dis[i] = G[0][i];
		sum[i] = Value[i];
		num[i] = 1;
		minDis[i] = 1;
		Q.push({i, dis[i], Value[i], sum[i], num[i], minDis[i]});
	}
	book[0] = true;
	while(Q.size()){
		Node head = Q.top();
		Q.pop();
		if(book[head.id])continue;
		book[head.id] = true;
		for(int i = 0; i < n; i++){
			if(i == head.id || book[i] || G[head.id][i] >= INT_MAX/2)continue;
			if(dis[i] > G[head.id][i] + head.dis){
				dis[i] = G[head.id][i] + head.dis;
				sum[i] = Value[i] + head.sum;
				num[i] = head.num + 1;
				Path[i] = head.id;
				minDis[i] = head.minDis;
				Q.push({i, dis[i], Value[i], sum[i], num[i], minDis[i]});
			}else if(dis[i] == G[head.id][i] + head.dis){
				minDis[i]+=head.minDis;
				if(sum[i] < Value[i] + head.sum){
					sum[i] = Value[i] + head.sum;
					num[i] = head.num + 1;
					Path[i] = head.id;
					Q.push({i, dis[i], Value[i], sum[i], num[i], minDis[i]});
				}else if(sum[i] == Value[i] + head.sum and num[i] > head.num+1){
					num[i] = head.num + 1;
					Path[i] = head.id;
					Q.push({i, dis[i], Value[i], sum[i], num[i], minDis[i]});
				}
			} 
		}
	}
	cout << minDis[D] << " " << dis[D] << " " << sum[D] <<" "<< sum[D]/num[D] << endl;
	vector<int>res;
	while(D!=0){
		res.push_back(D);
		D = Path[D];
	}
	reverse(res.begin(), res.end());
	map<int, string>M1;
	for(auto i: M){
		M1[i.second] = i.first;
	}
	cout << M1[0];
	for(auto i: res){
		cout << "->" << M1[i];
	}
	cout << endl;
}