#include<bits/stdc++.h>
using namespace std;
vector<int>P{2};
void init(int n){
	for(int i = P.back()+1; i <= n; i+=2){
		bool f = true;
		for(auto j: P){
			if(i % j == 0){
				f = false;
				break;
			}
		}
		if(f){
			P.push_back(i);
		}
	}
}
int main(){
	int M, N;
	cin >> M >> N;
	if(M == 1)M++;
	init(M);
	if(P.back() != M){
		for(int i = M+1; ; i++){
			bool f = true;
			for(auto j: P){
				if(i % j == 0){
					f = false;
					break;
				}
			}
			if(f){
				P.push_back(i);
				break;
			}
		}
		M = P.back();
	}
	vector<int>v(N), hash(M);
	for(int i = 0; i < N; i++){
		int x;
		cin >> x;
		if(hash[x%M] == 0){
			hash[x%M] = x;
			v[i] = x % M;
		}else{
			bool f = true;
			for(int j = 1; j < M; j++){
				int y = x + j*j;
				if(hash[y%M] == 0){
					hash[y%M] = x;
                    v[i] = y%M;
					f = false;
					break;
				}
			}
			if(f)
				v[i] = -1;
		}
	}
	for(int i = 0; i < N; i++){
		if(i){
			if(v[i]==-1){
				cout << " -";
			}else{
				cout << " " << v[i];
			}
		}else{
			if(v[i]==-1){
				cout << "-";
			}else{
				cout << v[i];
			}
		}
	}
	cout << endl;
}