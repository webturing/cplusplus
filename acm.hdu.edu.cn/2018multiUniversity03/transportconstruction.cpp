#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll,int>E;
const int N=100010;
const ll inf=1LL<<60;
int T,n,i,j,k,m,c[N],q[N],st[N],en[N],qx[N],qk[N],stq[N],enq[N],tmp[N];
int hull[N],on[N],f[N];
E e[N];
ll ans;
struct P{int x,y;}a[N];
inline bool cmpc(int x,int y){return c[x]<c[y];}
inline bool cmpx(int x,int y){
  if(a[x].x!=a[y].x)return a[x].x<a[y].x;
  if(a[x].y!=a[y].y)return a[x].y<a[y].y;
  return c[x]<c[y];
}
inline bool cmpk(int x,int y){return 1LL*a[x].y*a[y].x<1LL*a[y].y*a[x].x;}
inline ll dot(const P&a,const P&b){return 1LL*a.x*b.x+1LL*a.y*b.y;}
inline void work(int A,int B){//update B with A's hull
  int l1=stq[A],r1=enq[A];
  int l2=stq[B],r2=enq[B];
  int t=0,i,j,x,cnt=0;
  for(i=l1;i<=r1;i++){
    if(i>l1&&a[qx[i]].x==a[qx[i-1]].x)continue;
    //while(t>1&&slope(tmp[t],tmp[t-1])>slope(qx[i],tmp[t]))t--;
    while(t>1&&1LL*(a[tmp[t]].y-a[tmp[t-1]].y)*(a[qx[i]].x-a[tmp[t]].x)>1LL*(a[qx[i]].y-a[tmp[t]].y)*(a[tmp[t]].x-a[tmp[t-1]].x))t--;
    tmp[++t]=qx[i];
  }
  for(i=1;i<=t;i++){
    if(i==1||i==t)hull[++cnt]=i;
    //else if(slope(tmp[i],tmp[i-1])!=slope(tmp[i+1],tmp[i]))hull[++cnt]=i;
    else if(1LL*(a[tmp[i]].y-a[tmp[i-1]].y)*(a[tmp[i+1]].x-a[tmp[i]].x)!=1LL*(a[tmp[i+1]].y-a[tmp[i]].y)*(a[tmp[i]].x-a[tmp[i-1]].x))hull[++cnt]=i;
  }
  for(i=1;i<cnt;i++){
    on[i]=c[tmp[hull[i]]];
    for(j=hull[i];j<=hull[i+1];j++)on[i]=min(on[i],c[tmp[j]]);
  }
  for(i=1;i<=cnt;i++)hull[i]=tmp[hull[i]];
  for(i=l2,j=1;i<=r2;i++){
    x=qk[i];
    while(j<cnt&&dot(a[x],a[hull[j]])>dot(a[x],a[hull[j+1]]))j++;
    ll now=dot(a[x],a[hull[j]]);
    if(j<cnt&&now==dot(a[x],a[hull[j+1]]))e[c[x]]=min(e[c[x]],E(now,on[j]));
    else e[c[x]]=min(e[c[x]],E(now,c[hull[j]]));
  }
}
void solve(int l,int r){
  if(l==r){
    stq[l]=stq[l]=enq[l-1]+1;
    int cur=enq[l-1];
    for(int i=st[l];i<=en[l];i++){
      qx[++cur]=q[i];
      qk[cur]=q[i];
    }
    enq[l]=cur;
    sort(qx+stq[l],qx+cur+1,cmpx);
    sort(qk+stq[l],qk+cur+1,cmpk);
    return;
  }
  int mid=(l+r)>>1;
  solve(l,mid);
  solve(mid+1,r);
  work(l,mid+1);
  work(mid+1,l);
  int l1=stq[l],r1=enq[l];
  int l2=stq[mid+1],r2=enq[mid+1];
  int k=l1-1;
  while(l1<=r1&&l2<=r2)tmp[++k]=cmpx(qx[l1],qx[l2])?qx[l1++]:qx[l2++];
  while(l1<=r1)tmp[++k]=qx[l1++];
  while(l2<=r2)tmp[++k]=qx[l2++];
  for(int i=stq[l];i<=k;i++)qx[i]=tmp[i];
  l1=stq[l],r1=enq[l];
  l2=stq[mid+1],r2=enq[mid+1];
  k=l1-1;
  while(l1<=r1&&l2<=r2)tmp[++k]=cmpk(qk[l1],qk[l2])?qk[l1++]:qk[l2++];
  while(l1<=r1)tmp[++k]=qk[l1++];
  while(l2<=r2)tmp[++k]=qk[l2++];
  for(int i=stq[l];i<=k;i++)qk[i]=tmp[i];
  enq[l]=r2;
}
int F(int x){return f[x]==x?x:f[x]=F(f[x]);}
inline void merge(int x,int y,ll z){if(F(x)!=F(y))ans+=z,f[f[x]]=f[y];}
int main(){
  scanf("%d",&T);
  while(T--){
    scanf("%d",&n);
    for(i=1;i<=n;i++){
      scanf("%d%d",&a[i].x,&a[i].y);
      c[i]=q[i]=i;
    }
    ans=0;
    while(1){
      sort(q+1,q+n+1,cmpc);
      for(m=0,i=1;i<=n;i=j){
        for(j=i;j<=n&&c[q[i]]==c[q[j]];j++);
        m++;
        for(k=i;k<j;k++)c[q[k]]=m;
      }
      if(m==1)break;
      for(i=1;i<=n;i++)en[c[q[i]]]=i;
      for(i=n;i;i--)st[c[q[i]]]=i;
      for(i=1;i<=m;i++)e[i]=E(inf,0);
      solve(1,m);
      for(i=1;i<=m;i++)f[i]=i;
      for(i=1;i<=m;i++)merge(i,e[i].second,e[i].first);
      for(i=1;i<=n;i++)c[i]=F(c[i]);
    }
    printf("%lld\n",ans);
  }
}