#include<bits/stdc++.h>
using namespace std;
vector<int>prime{2, 3};
void initPrime(int n){
	for(int i = prime.back()+2; i <= n; i+=2){
		bool flag = true;
		for(auto j: prime){
			if(i % j == 0){
				flag = false;
				break;
			}
		}
		if(flag){
			prime.push_back(i);
		}
	}
}
bool isprime(int n){
    if(n == 2 || n == 3)return true;
    if(n % 2 == 0 || n <= 1)return false;
    for(int i = 3; i * i <= n; i+= 2){
        if(n % i == 0)return false;
    }
    return true;
}
int main(){
	int n;
	cin >> n;
	if(isprime(n) || n == 1){
		cout << n << "=" << n << endl;
		return 0;
	}
	int r = sqrt(n);
	initPrime(r);
	int m = n;
	map<int, int>M;
	int i = 0;
	while(m != 1 and i < prime.size()){
		while(m % prime[i] == 0){
			m /= prime[i];
			M[prime[i]]++;
		}
		i++;
	}
	if(m!=1){
		M[m]++;
	}
	cout << n << "=";
	vector<pair<int, int>>v(M.begin(), M.end());
	for(int i = 0; i < v.size(); i++){
		if(i)cout << "*" << v[i].first;
		else cout << v[i].first;
		if(v[i].second>1)cout << "^"<<v[i].second;
	}
}