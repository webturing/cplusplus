#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	double sum = 0;
	for(int i = 0; i < n; i++){
		double x;
		cin >> x;
		sum += (i+1) * x * (n-i);
	}
	cout << fixed << setprecision(2) << sum << endl;
}