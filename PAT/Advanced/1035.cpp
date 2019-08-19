#include<bits/stdc++.h>
using namespace std;
template <typename T = int>
T read(){
	T x;
	cin >> x;
	return x;
}
int main(){
	int n = read();
	vector<pair<string, string>>v;
	for(int i = 0; i < n; i++){
		string s1 = read<string>(), s2 = read<string>();
		bool f = false;
		for(auto &c: s2){
			if(c == '1'){
				c = '@';
				f = true;
			}else if(c == '0'){
				c = '%';
				f = true;
			}else if(c == 'l'){
				c = 'L';
				f = true;
			}else if(c == 'O'){
				c = 'o';
				f = true;
			}
		}
		if(f){
			v.push_back({s1, s2});
		}
	}
	if(v.size() == 0){
		if(n == 1)
			cout << "There is 1 account and no account is modified" << endl;
		else
			cout << "There are " << n << " accounts and no account is modified" << endl;
	}else{
		cout << v.size() << endl;
		for(auto i: v){
			cout << i.first << ' ' << i.second << endl;
		}
	}
}