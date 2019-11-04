#include<bits/stdc++.h>
using namespace std;
template<typename T = int>
T read(){
	T x;
	cin >> x;
	return x;
}
using ll = long long;
int main(){
	int Nc = read();
	vector<ll>v1, v2;// v1 是Nc的负数集合， v2是正数集合
	for(int i = 0; i < Nc; i++){
		ll x = read<ll>();
		if(x > 0){
			v2.push_back(x);
		}else{
			v1.push_back(x);
		}
	}
	int Np = read();
	vector<ll>u1, u2; // u1是Np的负数集合，u2是Np的正数集合
	for(int i = 0; i < Np; i++){
		ll x = read<ll>();
		if(x > 0){
			u2.push_back(x);
		}else{
			u1.push_back(x);
		}
	}
	sort(v1.begin(), v1.end());
	sort(u1.begin(), u1.end());
	sort(v2.begin(), v2.end());
	reverse(v2.begin(), v2.end());
	sort(u2.begin(), u2.end(), [](int a, int b)->bool{
		return a > b;
	});
	ll sum = 0;
	// 负数大的乘大的，小的乘小的
	for(int i = 0; i < min(v1.size(), u1.size()); i++){
		sum += v1[i] * u1[i];
	}
	for(int i = 0; i < min(v2.size(), u2.size()); i++){
		sum += v2[i] * u2[i];
	}
	cout << sum << endl;
	return 0;
}