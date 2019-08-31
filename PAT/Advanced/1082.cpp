#include<bits/stdc++.h>
using namespace std;
int main(){
	vector<string>v1{"Ge", "Shi", "Bai", "Qian", "Wan", "Yi"};
	vector<string>v2{"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
	int n;
	cin >> n;
	if(n == 0){
		cout << "ling" << endl;
		return 0;
	}
	string s = to_string(n);
	reverse(s.begin(), s.end());
	int last = 0;
	vector<string> res;
	for(int i = 0; i < s.size(); i++){
		if(s[i] == '-'){
			res.push_back("Fu");
			break;
		}
		if(i == 4 and n % 100000000 / 10000){
			res.push_back(v1[4]);
		}
		if(i == 8 and n / 100000000){
			res.push_back(v1[5]);
		}
		if(s[i] == '0'){
			if(i and s[i-1] != '0'){
				res.push_back(v2[0]);
			}
		}else{
			int x = i%4;
			if(x!=0){
				res.push_back(v1[x]);
			}
			res.push_back(v2[s[i]-'0']);
			
		}
	}
	reverse(res.begin(), res.end());
	for(int i = 0; i < res.size(); i++){
		if(i){
			cout << " " << res[i];
		}else{
			cout << res[i];
		}
	}
	cout << endl;
}