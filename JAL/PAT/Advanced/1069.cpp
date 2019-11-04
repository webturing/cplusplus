#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	string S = to_string(n);
	int t = 4-S.size();
	for(int i = 0; i < t; i++){
		S = "0" + S; 
	}
	sort(S.begin(), S.end(), [](char a, char b)->bool{return a > b;});
	if(S.back() == S.front()){
		cout << S <<" - "<<S<<" = 0000" << endl;
	}else{
		int a, b, c;
		do{
			cout << S << " - ";
			a = stoi(S);
			reverse(S.begin(), S.end());
			b =  stoi(S);
			cout << S << " = ";
			c = a - b;
			S = to_string(c);
			int t = 4-S.size();
			for(int i = 0; i < t; i++){
				S = "0" + S; 
			}
			cout << S << endl;
			sort(S.begin(), S.end(), [](char a, char b)->bool{return a > b;});
		}while( c != 6174);
	}
}