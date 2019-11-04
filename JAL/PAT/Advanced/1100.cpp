#include<bits/stdc++.h>
using namespace std;
vector<string>v[2] = {
	{"tret","jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"},
	 {"","tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"}};
void EarthToMars(int x){
	if(x == 0){
		cout << "tret" << endl;
		return;
	}
	if(x < 13){
		cout << v[0][x] << endl;
		return;
	}
	if(x % 13 == 0){
		cout << v[1][x/13] << endl;
		return;
	}
	cout << v[1][x/13] << " " << v[0][x%13] << endl;
}
void MarsToEarth(string x, string y = ""){
	if(y != ""){
		size_t a = find(v[1].begin(), v[1].end(), x) - v[1].begin();
		size_t b = find(v[0].begin(), v[0].end(), y) - v[0].begin();
		cout << a*13+b << endl;
	}else{
		size_t a = find(v[1].begin(), v[1].end(), x) - v[1].begin();
		if(a != v[1].size()){
			cout << a * 13 << endl;
		}else{
			size_t b = find(v[0].begin(), v[0].end(), x) - v[0].begin();
			cout << b << endl;
		}
	}
}
int main(){
	int n;
	cin >> n;
	getchar();
	while(n--){
		string s;
		getline(cin, s);
		if(s.find(' ') != string::npos){// 找到了空格
			istringstream iss(s);
			string x, y;
			iss >> x >> y;
			MarsToEarth(x, y);
		}else{
			if(isdigit(s[0])){
				EarthToMars(stoi(s));
			}else{
				MarsToEarth(s);
			}
		}
	}
}