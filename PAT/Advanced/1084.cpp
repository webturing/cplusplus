#include<bits/stdc++.h>
using namespace std;
int main(){
	string s1, s2;
	cin >> s1 >> s2;
	transform(s1.begin(), s1.end(), s1.begin(), [](char a)->char{
		return toupper(a);
	});
	transform(s2.begin(), s2.end(), s2.begin(), [](char a)->char{
		return toupper(a);
	});
	map<char, int>M;
	string res;
	int i = 0, j = 0;
	while(i < s1.size()){
		while(i < s1.size() and s1[i] != s2[j]){
			if(M[s1[i]]==0){
				res.push_back(s1[i]);
			}
			M[s1[i]]++;
			i++;
		}
		i++;j++;
	}
	cout << res << endl;
}