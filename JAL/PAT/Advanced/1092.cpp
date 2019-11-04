#include<bits/stdc++.h>
using namespace std;
int main(){
	string s1, s2;
	cin >> s1 >> s2;
	map<char, int>M1, M2;
	for(auto i: s1){
		M1[i]++;
	}
	for(auto i: s2){
		M2[i]++;
	}
	int cnt = 0;
	for(auto i: M2){
		if(i.second > M1[i.first])
			cnt += i.second - M1[i.first];
	}
	if(cnt == 0){
		cout << "Yes " << s1.size() - s2.size() << endl;
	}else{
		cout << "No " << cnt << endl;
	}
}