#include<iostream>
using namespace std;
long long cnr(int n,int r){
	if(r>n/2)r=n-r;
	long long ret=1;
	for(int i=0;i<r;i++)ret*=n-i;
	for(int i=2;i<=r;i++)ret/=i;
	return ret;
}
int main() {
    for(int n,r;cin>>n>>r;cout<<cnr(n,r)<<endl);
    return 0;
}
