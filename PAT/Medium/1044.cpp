#include <bits/stdc++.h>

using namespace std;

using ll=long long;

template<typename T=int>
T read(){
	T x;
	cin >> x;
	return x;
}
string a[2][13] = {
	{"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"},
	{"", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"}
};

void f(int x){
	if(x >= 13 and x % 13 == 0){
		cout << a[1][x/13] << endl;
		return;
	}
	if(x/13){
		cout << a[1][x/13] << " ";
	}
	cout << a[0][x%13] << endl;
}
void f2(string s1, string s2){
	int x = find(a[1], a[1]+13, s1) - a[1];
	int y = find(a[0], a[0]+13, s2) - a[0];
	cout << x * 13 + y << endl;
}
void f3(string s){
	auto x = find(a[1], a[1]+13, s) - a[1];
	if(x != 13){
		cout << x *13 << endl;
	}else{
		f2("", s);
	}
}
int main() {
	int n = read();
	cin.get();
	while(n--){
		string s;
		getline(cin, s);
		if(isdigit(s[0])){
			istringstream iss(s);
			int x;
			iss>>x;
			f(x);
		}else{
			auto p = s.find(' ');
			if(p != string::npos){// 两位数
				f2(s.substr(0, p), s.substr(p + 1));
			}else{// 一位数
				f3(s);
			}
		}
	}
	return 0;
}
