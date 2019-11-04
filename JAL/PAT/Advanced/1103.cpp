#include<bits/stdc++.h>
using namespace std;
int n, k, p;
vector<int>out, res;
vector<int>container;
int pown(int a, int n){
	int ret = 1;
	for(int i = 1; i <= n; i++)ret *= a;
	return ret;
}
int sum = 0;
int f = false;
void dfs(int step){
	if(step >= k){
		if(sum == n){
			f = true;
			if(accumulate(res.begin(), res.end(), 0) < accumulate(out.begin(), out.end(), 0)){
				res = out;
			}else if(accumulate(res.begin(), res.end(), 0) == accumulate(out.begin(), out.end(), 0) and res < out){
				res = out;
			}
		}
		return;
	}
	for(int i = 0; i < container.size(); i++){
		if(step > 0 and container[i] > out[step-1])continue;
		out[step] = container[i];
		int pw = pown(container[i], p);
		if(sum + pw > n)continue;
		sum += pw;
		dfs(step+1);
		sum -= pw;
	}
}
int main(){
	cin >> n >> k >> p;
	out.resize(k);
	res.resize(k);
	for(int i = sqrt(n); i >= 1; i--){
		container.push_back(i);
	}
	dfs(0);
	if(!f){
		cout << "Impossible" << endl;
	}else{
		cout << n << " = ";
		for(int i = 0; i < res.size(); i++){
			if(i){
				cout << " + " << res[i] << "^" << p;
			}else{
				cout << res[i] << "^" << p;
			}
		}
		cout << endl;
	}
}