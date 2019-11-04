#include<bits/stdc++.h>
using namespace std;
<<<<<<< HEAD
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
=======
int main(){
	int n;
	cin >> n;
	int max = 0, m = sqrt(n);// 注意此时m = sqrt(n)
	pair<int, int>res;
	for(int i = 2; i <= m; i++){// 如果此时写成i*i<=n，则最后一组数据无法通过，因为两个刚好大于sqrt(n)的值相乘超过了int范围，变成了负数，还能符合i*i<=n,造成了死循环，所以运行超时。
		if(n % i == 0){// i 为因子
			int a = n, b = i;// 从i开始，看连续的因子能有多长
			while(a % b == 0){
				a/=b;
				b++;
			}
			if(b - i > max){ // 是否能更新长度和结果
				max = b - i;
				res = {i, max};
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
>>>>>>> 3dfe033571a96e885ac0681301dd2ee14e1aba6e
