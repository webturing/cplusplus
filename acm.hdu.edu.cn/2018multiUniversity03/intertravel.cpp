#include<cstdio>
#include<algorithm>
using namespace std;
const int N=200010;
int T,n,t,i,f[N];bool must[N];
struct P{int x,y,p;}a[N],q[N];
inline bool cmp(const P&a,const P&b){
  if(a.x!=b.x)return a.x<b.x;
  if(a.y!=b.y)return a.y>b.y;
  return a.p<b.p;
}
int main(){
  scanf("%d",&T);
  while(T--){
    scanf("%d",&n);
    for(i=1;i<=n;i++){
      scanf("%d%d",&a[i].x,&a[i].y);
      a[i].p=i;
    }
    sort(a+1,a+n+1,cmp);
    for(t=0,i=1;i<=n;i++){
      if(i>1&&a[i].x==a[i-1].x)continue;
      while(t>1&&1LL*(q[t].y-q[t-1].y)*(a[i].x-q[t].x)<1LL*(a[i].y-q[t].y)*(q[t].x-q[t-1].x))t--;
      q[++t]=a[i];
    }
    for(i=1;i<=t;i++)must[i]=0;
    must[1]=must[t]=1;
    for(i=2;i<t;i++)if(1LL*(q[i].y-q[i-1].y)*(q[i+1].x-q[i].x)!=1LL*(q[i+1].y-q[i].y)*(q[i].x-q[i-1].x))must[i]=1;
    for(i=t;i;i--)if(must[i])f[i]=q[i].p;else f[i]=min(f[i+1],q[i].p);
    for(i=1;i<t;i++)if(f[i]==q[i].p)printf("%d ",f[i]);
    printf("%d\n",f[t]);
  }
}