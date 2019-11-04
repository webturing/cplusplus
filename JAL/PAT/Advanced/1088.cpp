#include<bits/stdc++.h>
#define int long long
using namespace std;

int gcd(int a,int b){
	return b == 0? a: gcd(b, a%b);
}
struct Node
{
	int a,b;
	Node operator+(const Node Y)const{
		Node Z;
		Z.a = a * Y.b + b * Y.a;
		Z.b = b * Y.b;
		return Z;
	}
	Node operator-(const Node Y)const{
		Node Z;
		Z.a = a * Y.b - b * Y.a;
		Z.b = b * Y.b;
		return Z;
	}
	Node operator*(const Node Y)const{
		Node Z;
		Z.a = a*Y.a;
		Z.b = b * Y.b;
		return Z;
	}
	Node operator/(const Node Y)const{
		Node Z;
		Z.a = a*Y.b;
		Z.b = b * Y.a;
		return Z;
	}
	string toString(){
		Node Z = {a, b};
		if(Z.b == 0)return "Inf";
		if(Z.a == 0)return "0";
		int c = gcd(Z.a, Z.b);
		Z.a /= c; Z.b /= c;
		if(Z.b < 0)Z.a *= -1, Z.b *= -1;
		bool f = false;
		if(Z.a < 0)f = true, Z.a*=-1;
		int I = Z.a/Z.b;
		Z.a %= Z.b;
		ostringstream oss;
		if(f)oss << "(-";
		if(I)
		oss << I;
		if(I and Z.a)oss << " ";
		if(Z.a){
			if(Z.b != 1)
				oss << Z.a << "/" << Z.b;
			else
				oss << Z.a;
		}
		if(f)oss << ")";
		return oss.str();
	}
};
signed main(){
	Node X, Y;
	scanf("%lld/%lld %lld/%lld", &X.a, &X.b, &Y.a, &Y.b);
	Node Z = X+Y;
	printf("%s + %s = %s\n", X.toString().c_str(), Y.toString().c_str(), Z.toString().c_str());
	Z = X-Y;
	printf("%s - %s = %s\n", X.toString().c_str(), Y.toString().c_str(), Z.toString().c_str());
	Z = X*Y;
	printf("%s * %s = %s\n", X.toString().c_str(), Y.toString().c_str(), Z.toString().c_str());
	Z = X/Y;
	printf("%s / %s = %s\n", X.toString().c_str(), Y.toString().c_str(), Z.toString().c_str());

}