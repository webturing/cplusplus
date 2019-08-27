#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin >> s;
	int E = find(s.begin(), s.end(), 'E') - s.begin();
	int e = stoi(s.substr(E+1));
	int p = find(s.begin(), s.end(), '.') - s.begin();
	if(e > 0){// 正指数
		string s2 = s[0]=='-'?s.substr(0, p):s.substr(1, p-1);
		int i = p+1, t = 0;
		while(i < E and t < e){
			s2.push_back(s[i]);
			i++;
			t++;
		}
		if(t == e and i < E){
			s2.push_back('.');
			while(i < E){
				s2.push_back(s[i]);
				i++;
			}
		}
		if(t < e and i == E){
			while(t < e){
				s2.push_back('0');
				t++;
			}
		}
		cout << s2 << endl;
	}else if(e == 0){
		cout << ((s[0]=='-')? s.substr(0, E):s.substr(1, E-1)) << endl;
	}
	else{ // 负指数
		string s2 = s.substr(p+1, E-p-1);
		reverse(s2.begin(), s2.end());
	    s2.push_back(s[p-1]);
		e++;
		e *=-1;
		for(int i = 1; i <= e; i++)s2.push_back('0');
		s2 += ".0";
		if(s[0]=='-')s2.push_back(s[0]);
		reverse(s2.begin(), s2.end());
		cout << s2 << endl;
	}
}