#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	vector<set<int>>v(n+1);
	for(int i = 1; i <= n; i++){
		int m;
		cin >> m;
		while(m--){
			int x;
			cin >> x;
			v[i].insert(x);
		}
	}
	int k;
	cin >> k;
	while(k--){
		int x, y;
		cin >> x >> y;
		int Nc = 0, Nt = v[x].size();
		for(auto i: v[y]){
			if(v[x].count(i))Nc++;// 共同的数
			else Nt++; // 总数增加
		}
		printf("%.1f%%\n", 100.0*Nc/Nt);
	}
}