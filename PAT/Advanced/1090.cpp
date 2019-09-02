#include<bits/stdc++.h>
using namespace std;
using pr = pair<int, int>;
int main(){
	int n,root;
	double p, r;
	cin >> n >> p >> r;
	vector<vector<int>>G(n);
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		if(x == -1){
			root = i;
			continue;
		}
		G[x].push_back(i);
	}
	vector<int>book(n);
	queue<pr>Q;
	int maxStep = 0, maxCnt = 1;
	Q.push({0, root});
	book[root] = 1;
	while(Q.size()){
		pr head = Q.front();
		Q.pop();
		for(auto i: G[head.second]){
			if(book[i])continue;
			book[i] = 1;
			if(maxStep < head.first + 1){
				maxStep = head.first + 1;
				maxCnt = 1;
			}else if(maxStep == head.first + 1){
				maxCnt++;
			}
			Q.push({head.first+1, i});
		}
	}
	printf("%.2f %d\n", p*pow(1+r/100.0, maxStep), maxCnt);
}