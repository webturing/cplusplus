 

#include<iostream>
using namespace std;
const int  MOD=1000000007;
const int MX=MOD-1;

void mult(long long A[2][2],long long B[2][2],long long C[2][2])
{
    C[0][0]=(A[0][0]*B[0][0]%MX+A[0][1]*B[1][0]%MX)%MX;
    C[0][1]=(A[0][0]*B[0][1]%MX+A[0][1]*B[1][1]%MX)%MX;
    C[1][0]=(A[1][0]*B[0][0]%MX+A[1][1]*B[1][0]%MX)%MX;
    C[1][1]=(A[1][0]*B[0][1]%MX+A[1][1]*B[1][1]%MX)%MX;
}
void sq(long long A[2][2],long long B[2][2])
{
    mult(A,A,B);
}
void pow2(long long A[2][2],int n,long long B[2][2])
{
    long long E[2][2],F[2][2];

    if(n==0)
    {
        B[0][0]=B[1][1]=1;
        B[0][1]=B[1][0]=0;
        return;
    }
    if(n%2==0)
    {
        sq(A,E);
        pow2(E,n/2,B);
        return ;
    }
    sq(A,E);
    pow2(E,n/2,F);
    mult(F,A,B);
}
long long mpw(long long a,long long n)
{
    a%=MOD;
    if(n==1||a==0)
        return a%MOD;
    if(n==0)
        return 1;
    if(n%2==0)
        return mpw(a*a%MOD,n/2);
    return mpw(a*a%MOD,n/2)*a%MOD;

}
void solve(int a,int b,int n)
{
    if(n==0)cout<<a%MOD<<endl;
    else if(n==1)cout<<b%MOD<<endl;
    else
    {
        long long B[2][2];
        long long A[2][2]= {{1,1},{1,0}};
        pow2(A,n-2,B);
        long long xn=B[0][0];
        pow2(A,n-1,B);
        long long yn=B[0][0];
        cout<<1LL*mpw(a,xn)*mpw(b,yn)%MOD<<endl;
    }
}
void print(long long A[2][2])
{
    cout<<A[0][0]<<" "<<A[0][1]<<endl;
    cout<<A[1][0]<<" "<<A[1][1]<<endl;
}
int main()
{

    for(int a,b,n; cin>>a>>b>>n;)
        solve(a,b,n);
    return 0;
}
        