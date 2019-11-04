#include<bits/stdc++.h>
using namespace std;
vector<int>F;
int getF(int u){
	return F[u] != u? F[u] = getF(F[u]): u;
}
void Merge(int u, int v){
	int fu = getF(u);
	int fv = getF(v);
	if(fu != fv){
		F[fu] = v;
	}
}
int main(){
	int n;
	cin >> n;
	F.resize(n+1);
	for(int i = 1; i <= n; i++){
		F[i] = i;
	}
	map<int, vector<int>>M;
	for(int i = 1; i <= n; i++){
		int k,x;
		scanf("%d: %d", &k, &x);
		M[x].push_back(i);
		for(int j = 1; j < k; j++){
			scanf("%d", &x);
			M[x].push_back(i);
		}
	}
	for(auto i: M){
		if(i.second.size()<=1)continue;
		for(int j = 0; j < i.second.size(); j++){
			for(int k = j+1; k < i.second.size(); k++){
				Merge(i.second[j], i.second[k]);
			}
		}
	}
	map<int, int>res;
	for(int i = 1; i <= n; i++){
		F[i] = getF(i);
		res[F[i]]++;
	}
	vector<int>a;
	for(auto i: res){
		a.push_back(i.second);
	}
	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());
	cout << a.size() << endl;
	for(int i = 0; i < a.size(); i++){
		if(i)cout << " " << a[i];
		else cout << a[i];
	}
	return 0;
}