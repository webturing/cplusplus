#include<bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
int main(){
	string s;
	cin >> s;
	long long a = 0, b = 0, c = 0;
	for(int i = 0; i < s.size(); i++){
		if(s[i] == 'P'){
			a++;
		}else if(s[i] == 'A'){
			b += a;
		}else if(s[i] == 'T'){
			c += b;
		}
	}
	cout << c%MOD << endl;
}