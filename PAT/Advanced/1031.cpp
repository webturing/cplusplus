#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin >> s;
	int n = s.size() + 2;
	int n1 = n / 3, n2 = n / 3 + n % 3;
	for(int i = 0; i < n1-1; i++){
		cout << s[i];
		for(int j = 1; j < n2-1; j++){
			cout << ' ';
		}
		cout << s[s.size() - i - 1] << endl;
	}
	for(int i = 0; i < n2; i++){
		cout << s[n1-1 + i];
	}
	cout << endl;
}