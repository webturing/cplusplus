#include<bits/stdc++.h>
using namespace std;
template<typename T = int>
T read(){
	T x;
	cin >> x;
	return x;
}
int main(){
	int m = read(), n = read(), t = read();
	while(t--){
		vector<int>v(n), stk;
		for(auto &i: v){
			i = read();
		}
		bool f = true;
		int t = 1;
		for(int i = 0; i < n; i++){
			while(stk.empty() || stk.back() != v[i]){
				if(t > n || stk.size() >= m){f = false;break;}
				stk.push_back(t++);
			}
			if(!f){
				break;
			}
			stk.pop_back();
		}
		if(f){
			cout << "YES" << endl;
		}else{
			cout << "NO" << endl;
		}
	}
}