#include<bits/stdc++.h>
using namespace std;
int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	vector<int>v[n+1];
	for(int i = 0; i < m; i++){
		int id, k;
		scanf("%d %d", &id, &k);
		while(k--){
			int x;
			scanf("%d", &x);
			v[id].push_back(x);
		}
	}
	queue<pair<int, int>>Q;
	Q.push({1, 1});
	vector<int>book(n+1);
	book[1] = 1;
	vector<int>level(n+1);
	while(Q.size()){
		pair<int,int>head = Q.front();
		Q.pop();
		level[head.first]++;
		for(auto i: v[head.second]){
			if(book[i])continue;
			Q.push({head.first + 1, i});
			book[i] = 1;
		}
	}
	int p = max_element(level.begin(), level.end()) - level.begin();
	cout << level[p] << " " << p << endl;
}