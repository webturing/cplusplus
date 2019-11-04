#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	scanf("%d", &n);
	vector<string>v;
	getchar();
	while(n--){
		string s;
		getline(cin, s);
		reverse(s.begin(), s.end());
		v.push_back(s);
	}
	int pos = 0;
	while(1){
		bool f = true;
		if(pos >= v[0].size()){
			break;
		}
		for(int i = 1; i < v.size(); i++){
			if(pos >= v[i].size() || v[i][pos] != v[0][pos]){
				f = false;
				break;
			}
		}
		if(!f){
			break;
		}
		pos++;
		
	}
	if(!pos){
		cout << "nai" << endl;
		return 0;
	}
	string res(v[0].substr(0, pos));
	reverse(res.begin(), res.end());
	cout << res << endl;
}