#include<bits/stdc++.h>
using namespace std;
template<typename T=int>
T read(){
	T x;
	cin >> x;
	return x;
}
bool palindromic(string s){
	string r(s.rbegin(), s.rend());
	return s == r;
}
string f(string s){
	string r(s.rbegin(), s.rend());
	string t;
	int c = 0;
	for(int i = 0; i < s.size(); i++){
		t.push_back(s[i] - '0' + r[i] - '0' + c);
		c = t.back() / 10;
		t.back() %= 10;
		t.back() += '0';
	}
	if(c)t.push_back(c + '0');
	reverse(t.begin(), t.end());
	return t;
}
int main(){
	string n = read<string>();
	int k = read();
	string res(n);
	int cnt = 0;
	while(!palindromic(res) and cnt < k){
		res = f(res);
		cnt++;
	}
	cout << res << endl << cnt << endl;
}