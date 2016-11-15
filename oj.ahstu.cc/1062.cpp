#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;

int main() {
	freopen("data.in","r",stdin);
	vector<int> a(31,1);
	for(int i=1;i<a.size();i++)
		a[i]=2*a[i-1]+2;
	for(int n;cin>>n;cout<<a[n-1]<<endl);

    return 0;
}