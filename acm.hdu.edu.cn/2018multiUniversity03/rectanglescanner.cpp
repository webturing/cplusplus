#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100010,M=1000010,E=262150,inf=~0U>>1;
int T,n,m,K,i,a[N],b[N],vma[E],vmi[E],vprod[E];
int xl[M],xr[M],yl[M],yr[M],ansma[M],ansmi[M],ansprod[M],q[M],pool[M],e[M];
int A,B,U,C,D;
inline bool cmpl(int x,int y){return xl[x]>xl[y];}
inline bool cmpr(int x,int y){return xr[x]<xr[y];}
inline void umax(int&a,int b){a<b?(a=b):0;}
inline void umin(int&a,int b){a>b?(a=b):0;}
void dfs(int x,int a,int b){
  if(!vma[x])return;
  vma[x]=0,vmi[x]=inf,vprod[x]=1;
  if(a==b)return;
  int mid=(a+b)>>1;
  dfs(x<<1,a,mid),dfs(x<<1|1,mid+1,b);
}
void add(int x,int a,int b){
  umax(vma[x],D);
  umin(vmi[x],D);
  vprod[x]=1LL*vprod[x]*D%K;
  if(a==b)return;
  int mid=(a+b)>>1;
  if(C<=mid)add(x<<1,a,mid);else add(x<<1|1,mid+1,b);
}
void ask(int x,int a,int b){
  if(C<=a&&b<=D){
    umax(A,vma[x]);
    umin(B,vmi[x]);
    U=1LL*U*vprod[x]%K;
    return;
  }
  int mid=(a+b)>>1;
  if(C<=mid)ask(x<<1,a,mid);
  if(D>mid)ask(x<<1|1,mid+1,b);
}
void solve(int l,int r,int L,int R){
  if(l>r||L>R)return;
  int mid=(l+r)>>1,i,j,k,cL=L-1,cR=R+1,ce=0;
  for(i=L;i<=R;i++){
    j=q[i];
    if(xr[j]<mid)pool[++cL]=j;
    else if(xl[j]>mid)pool[--cR]=j;
    else e[++ce]=j;
  }
  for(i=L;i<=R;i++)q[i]=pool[i];
  sort(e+1,e+ce+1,cmpl);
  for(i=1,j=mid;i<=ce;i++){
    k=e[i];
    while(j>=xl[k]){
      C=a[j],D=b[j];
      add(1,1,n);
      j--;
    }
    C=yl[k],D=yr[k],A=ansma[k],B=ansmi[k],U=ansprod[k];
    ask(1,1,n);
    ansma[k]=A,ansmi[k]=B,ansprod[k]=U;
  }
  dfs(1,1,n);
  sort(e+1,e+ce+1,cmpr);
  for(i=1,j=mid+1;i<=ce;i++){
    k=e[i];
    while(j<=xr[k]){
      C=a[j],D=b[j];
      add(1,1,n);
      j++;
    }
    C=yl[k],D=yr[k],A=ansma[k],B=ansmi[k],U=ansprod[k];
    ask(1,1,n);
    ansma[k]=A,ansmi[k]=B,ansprod[k]=U;
  }
  dfs(1,1,n);
  solve(l,mid-1,L,cL);
  solve(mid+1,r,cR,R);
}
int main(){
  for(i=0;i<E;i++)vmi[i]=inf,vprod[i]=1;
  scanf("%d",&T);
  while(T--){
    scanf("%d",&n);
    for(i=1;i<=n;i++)scanf("%d%d",&a[i],&b[i]);
    int a0,b0,c0,d0,pp,qq,rr,P;
    scanf("%d%d%d%d%d%d%d%d%d%d",&m,&a0,&b0,&c0,&d0,&pp,&qq,&rr,&P,&K);
    for(i=1;i<=m;i++){
      int na=(1LL*pp*a0+1LL*qq*b0+rr)%P;
      int nb=(1LL*pp*b0+1LL*qq*a0+rr)%P;
      int nc=(1LL*pp*c0+1LL*qq*d0+rr)%P;
      int nd=(1LL*pp*d0+1LL*qq*c0+rr)%P;
      xl[i]=min(na%n+1,nb%n+1);
      xr[i]=max(na%n+1,nb%n+1);
      yl[i]=min(nc%n+1,nd%n+1);
      yr[i]=max(nc%n+1,nd%n+1);
      a0=na,b0=nb,c0=nc,d0=nd;
      q[i]=i;
      ansma[i]=0;
      ansmi[i]=inf;
      ansprod[i]=1;
    }
    solve(1,n,1,m);
    long long fin=0;
    for(i=1;i<=m;i++)if(ansma[i])fin+=ansprod[i]^ansma[i]^ansmi[i];
    printf("%lld\n",fin);
  }
}