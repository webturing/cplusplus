#include <bits/stdc++.h>
using namespace std;
int main(){
	string x;
	cin >> x;
	vector<int>v1, v2;
	for(auto i = x.rbegin(); i < x.rend(); i++){
		v1.push_back(*i-'0');
	}
	int c = 0;
	for(int i = 0; i < v1.size(); i++){
		v2.push_back(v1[i] * 2 + c);
		c = v2.back() / 10;
		v2.back() %= 10;
	}
	if(c)v2.push_back(c);
	string res;
	for(auto i = v2.rbegin(); i < v2.rend(); i++){
		res.push_back((char)(*i + '0'));
	}
	bool f = true;
	if(v2.size() != v1.size()){
		f = false;
	}else{
		sort(v1.begin(), v1.end());
		sort(v2.begin(), v2.end());
		for(int i = 0; i < v1.size(); i++){
			if(v1[i] != v2[i]){
				f = false;
				break;
			}
		}
	}
	cout << (f ? "Yes": "No") << endl;
	cout << res << endl;
}