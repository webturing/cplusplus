#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	getline(cin, s);
	transform(s.begin(), s.end(), s.begin(), [](char a)->char{
		if(isalpha(a) or isdigit(a))return tolower(a);
		else return ' ';
	});
	istringstream iss(s);
	string x;
	map<string, int>M;
	while(iss >> x){
		M[x]++;
	}
	int y = 0;
	for(auto i: M){
		if(i.second > y){
			y = i.second;
			x = i.first;
		}
	}
	cout << x <<" " << y << endl;
}