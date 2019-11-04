#include<bits/stdc++.h>
using namespace std;
int n, L, cur, sum;

int main(){
	scanf("%d %d", &n, &L);
	vector<int>M[n+1];
	for(int i = 1; i <= n; i++)M[i].resize(n+1);
	for(int i = 1; i <= n; i++){
		int tot;
		scanf("%d", &tot);
		while(tot--){
			int x;
			scanf("%d", &x);
			M[i][x] = 1;
		}
	}
	int k;
	scanf("%d", &k);
	while(k--){
		scanf("%d", &cur);
		priority_queue<pair<int, int>,vector<pair<int, int>>, greater<pair<int, int>>>Q;
		vector<int>book(n+1);
		book[cur] = 1;
		Q.push({0, cur});
		sum = 0;
		while(Q.size()){
			pair<int, int>head = Q.top();
			Q.pop();
			if(head.first >= L)break;
			for(int i = 1; i <= n; i++){
				if(book[i]==0 and M[i][head.second]){
					Q.push({head.first+1, i});
					sum++;
					book[i] = 1;
				}
			}
		}
		printf("%d\n", sum);
	}
}