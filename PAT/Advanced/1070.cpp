#include<bits/stdc++.h>
using namespace std;
struct Node
{
	double D, P, S;
};
int main(){
	int n;
	double m;
	cin >> n >> m;
	vector<Node>v(n);
	for(int i = 0; i < n; i++){
		cin >> v[i].D;
	}
	for(int i = 0; i < n; i++){
		cin >>v[i].P;
		v[i].S = v[i].P / v[i].D;
	}
	sort(v.begin(), v.end(), [](Node a, Node b)->bool{
		return a.S > b.S;
	});
	double sum = 0;
	for(int i = 0; i < n; i++){
		if(m==0)break;
		sum += v[i].S * min(v[i].D, m);
		m -= min(v[i].D, m);
	}
	printf("%.2f\n", sum);
}