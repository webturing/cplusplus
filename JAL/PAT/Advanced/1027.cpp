#include<bits/stdc++.h>
using namespace std;
template<typename T=int>
T read(){
	T x;
	cin >> x;
	return x;
}
int main(){
	int r = read(), g = read(), b = read();
	string s = "0123456789ABC";
	cout << "#" << s[r / 13] << s[r % 13] << s[g / 13] << s[g % 13] << s[b / 13] << s[b % 13] << endl;
}