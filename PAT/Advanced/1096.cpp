#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	int max = 0, m = sqrt(n);
	pair<int, int>res;
	for(int i = 2; i <= m; i++){
		if(n % i == 0){// 因子
			int a = n, b = i;
			while(a % b == 0){
				a/=b;
				b++;
			}
			if(n % a == 0){
				if(b - i > max){
					max = b - i;
					res = {i, max};
				}
			}
		}
	}
	if(!max){
		cout << 1 << endl << n << endl;
		return 0;
	}
	cout << max << endl;
	cout << res.first;
	for(int i = 1; i < res.second; i++){
		cout << "*" << res.first+i;
	}
	cout << endl;
}