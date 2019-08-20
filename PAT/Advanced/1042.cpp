#include<bits/stdc++.h>
using namespace std;
template<typename T = int>
T read(){
	T x;
	cin >> x;
	return x;
}
int main(){
	vector<string> Shuffly, Copy;
	string S = "SHCD";
	for(auto c: S)
		for(int i = 1; i <= 13; i++){
			ostringstream oss;
			oss << c << i;
			Shuffly.push_back(oss.str());
		}
	Shuffly.push_back("J1");
	Shuffly.push_back("J2");
	int n = read();
	vector<int>v(Shuffly.size());
	for(int i = 0; i < v.size(); i++){
		v[i] = read();
	}
	Copy.resize(Shuffly.size());
	while(n--){
		for(int i = 0; i < v.size(); i++){
			Copy[v[i]-1] = Shuffly[i];
		}
		Shuffly = Copy;
	}
	for(int i = 0; i < Shuffly.size(); i++){
		if(i){
			cout << " " << Shuffly[i];
		}else{
			cout << Shuffly[i];
		}
	}
}

/*
2
4 2 5 3 1
*/