#include<bits/stdc++.h>
using namespace std;
struct Frac
{
	int num, den;
	Frac(){}
	Frac(int num, int den):num(num), den(den){}
	Frac operator+(const Frac& that)const {
		Frac ret = Frac(num*that.den + den*that.num, den*that.den);
		return ret;
	}
};
int gcd(int a, int b){
	return b == 0? a: gcd(b, a%b);
}
int main(){
	int n;
	cin >> n;
	vector<Frac>v(n);
	Frac ret;
	scanf("%d/%d", &ret.num, &ret.den);
	for(int i = 1; i < n; i++){
		Frac f;
		scanf("%d/%d", &f.num, &f.den);
		ret = ret + f;
	}
	if(ret.num==0){
		cout << 0 << endl;return 0;
	}
	int g = gcd(ret.num, ret.den);
	ret.num /= g;
	ret.den /= g;
	int integer = ret.num / ret.den;
	ret.num %= ret.den;
	if(ret.den<0){
		ret.num*=-1;
		ret.den*=-1;
	}
	int f = 0;
	if(integer)
		{
			cout << integer;
			f = 1;
		}
	if(ret.num)
	{
		if(f)
		cout << " ";
		cout << ret.num << "/" << ret.den << endl;
	}
}