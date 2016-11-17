#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;

int main() {
	freopen("data.in","r",stdin);
  	vector<bool> prime(1000001,true);
  	prime[0]=prime[1]=false;
  	for(int i=2;i*i<prime.size();i++)
  		if(prime[i])
  			for(int j=i*i;j<prime.size();j+=i)
  				prime[j]=0;
  	for(int n;cin>>n;){
  		for(int p=(n%4)?n/2:n/2-1;p>=3;p-=2)
  			if(prime[p]&&prime[n-p]){
  				cout<<p<<" "<<n-p<<endl;
  				break;
  			}
  	}

    return 0;
}