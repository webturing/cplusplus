#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	string a, b;
	cin >> n >> a >> b;
	int firstNotZero = 0;
	for(int i = 0; i < a.size(); i++){
		if(a[i] != '0'){
			firstNotZero = i;
			break;
		}
	}
	if(a[firstNotZero]=='.'){
		firstNotZero--;
	}
	a = a.substr(firstNotZero);
	firstNotZero = 0;
	for(int i = 0; i < b.size(); i++){
		if(b[i] != '0'){
			firstNotZero = i;
			break;
		}
	}
	if(b[firstNotZero]=='.'){
		firstNotZero--;
	}
	b = b.substr(firstNotZero);
	string s1="0.", s2="0.";
	int t1 = 0, t2 = 0, cnt = 0;
	int p = 2;
	if(a.substr(0, 2) == "0."){
		while(a[p]=='0')p++;
	}else p = 0;
	for(int i = p; i < a.size(); i++){
		if(cnt >= n){
			break;
		}
		if(a[i] == '.'){
			continue;
		}
		s1.push_back(a[i]);
		cnt++;
		
	}
	for(int i = cnt+1; i <= n; i++){
		s1.push_back('0');
	}
	if(a.substr(0, 2) == "0."){
		t1 = 0;
		int p = 2;
		while(a[p]=='0'){t1--;p++;}
	}else{
		for(int i = 0; i < a.size(); i++){
			if(a[i] == '.')break;
			t1++;
		}
	}
	s1 += "*10^" + to_string(t1);
	

	cnt = 0;
	p = 2;
	if(b.substr(0, 2) == "0."){
		while(b[p]=='0')p++;
	}else p = 0;
	for(int i = p; i < b.size(); i++){
		if(cnt >= n){
			break;
		}
		if(b[i] == '.'){
			continue;
		}
		s2.push_back(b[i]);
		cnt++;
		
	}
	for(int i = cnt+1; i <= n; i++){
		s2.push_back('0');
	}
	if(b.substr(0, 2) == "0."){
		t2 = 0;
		int p = 2;
		while(b[p]=='0'){p++;t2--;}
	}else{
		for(int i = 0; i < b.size(); i++){
			if(b[i] == '.')break;
			t2++;
		}
	}
	s2 += "*10^" + to_string(t2);
	if(s1 == s2){
		cout << "YES " << s1 << endl;
	}else{
		cout << "NO " << s1 << " " << s2 << endl;
	}
}