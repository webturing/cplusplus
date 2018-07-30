#include<cstdio>
const int N=10000010;
int T,n,m,k,P,Q,R,MOD,i,a[N],q[N],h,t;long long A,B;
int main(){
  scanf("%d",&T);
  while(T--){
    scanf("%d%d%d%d%d%d%d",&n,&m,&k,&P,&Q,&R,&MOD);
    for(i=1;i<=k;i++)scanf("%d",&a[i]);
    for(i=k+1;i<=n;i++)a[i]=(1LL*P*a[i-1]+1LL*Q*i+R)%MOD;
    for(h=1,t=A=B=0,i=n;i;i--){
      while(h<=t&&a[q[t]]<=a[i])t--;
      q[++t]=i;
      if(i+m-1<=n){
        while(q[h]>=i+m)h++;
        A+=i^a[q[h]];
        B+=i^(t-h+1);
      }
    }
    printf("%lld %lld\n",A,B);
  }
}