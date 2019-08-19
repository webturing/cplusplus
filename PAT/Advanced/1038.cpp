#include<bits/stdc++.h>
using namespace std;
template<typename T = int>
T read(){
	T x;
	cin >> x;
	return x;
}
int main(){
	int n = read();
	vector<string>v;
	for(int i = 0; i < n; i++){
		v.push_back(read<string>());
	}
	sort(v.begin(), v.end(), [](string a, string b)->bool{
		return a+b < b+a;
	});
	string s;
	for(auto i: v){
		s += i;
	}
	int i = 0;
	while(i < s.size() - 1 and s[i] == '0')i++;
	cout << s.substr(i) << endl;
}