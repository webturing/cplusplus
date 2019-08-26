#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	vector<int>a(n);
	int cnt = 0, r = 0;
	for(int i = 0; i < n; i++){
		int t;
		cin >> t;
		a[t] = i;
	}
	for(int i = 0; i < n; i++){
		if(a[i] != i){
			while(a[0] != 0){
				swap(a[0], a[a[0]]);
				cnt++;
			}
			if(a[i] != i){
				swap(a[0], a[i]);
				cnt++;
			}
		}
	}
	cout << cnt << endl;
}