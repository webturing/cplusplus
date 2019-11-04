#include<bits/stdc++.h>
using namespace std;
int main(){
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	map<char, bool>M;
	for(auto i: s2){
		M[i] = true;
	}
	for(auto i: s1){
		if(M[i])continue;
		cout << i;
	}
}