#include<bits/stdc++.h>
using namespace std;
int get_length(int n,int a){
	if(n<a||n%a!=0)return 0;
	return get_length(n/a,a+1)+1;
}
int main(){
	ios::sync_with_stdio(false);
	int n;cin>>n;
	int a=2,b=get_length(n,2);
	for(int i=3;i*i<=n;i++){
		int k=get_length(n,i);
		if(k>b){
			a=i;
			b=k;
		}
	}
	cout<<b<<endl;
	cout<<a;
	for(int i=1;i<b;i++)
		cout<<"*"<<(a+i);
	cout<<endl;
		return 0;
	
}