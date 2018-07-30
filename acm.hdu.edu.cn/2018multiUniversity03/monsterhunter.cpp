#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstdlib>
using namespace std;
typedef long long ll;
const int N=100010;
int T,n,i,x,y,g[N],v[N<<1],nxt[N<<1],ed,f[N],vis[N],del[N],pos;
struct P{
  ll a,b;//- a then + b
  P(){}
  P(ll _a,ll _b){a=_a,b=_b;}
  bool operator<(const P&o)const{//true means bigger
    int sgn1=a<b,sgn2=o.a<o.b;
    if(sgn1!=sgn2)return sgn1<sgn2;
    if(a<b)return a>o.a;
    return b<o.b;
  }
  void operator+=(const P&o){
    ll na=max(a,a-b+o.a),nb=b+o.b-a-o.a+na;
    a=na,b=nb;
  }
}a[N];
typedef pair<int,int>PI;
typedef pair<P,PI>PII;
priority_queue<PII>q;
inline void add(int x,int y){v[++ed]=y;nxt[ed]=g[x];g[x]=ed;}
void dfs(int x,int y){
  f[x]=y;
  for(int i=g[x];i;i=nxt[i])if(v[i]!=y)dfs(v[i],x);
}
int F(int x){return del[f[x]]?f[x]=F(f[x]):f[x];}
int main(){
  int size=64<<20;//64MB
  char *p=(char*)std::malloc(size)+size;
  __asm__("movl %0, %%esp\n"::"r"(p));
  scanf("%d",&T);
  while(T--){
    scanf("%d",&n);
    for(ed=pos=i=0;i<=n;i++)vis[i]=del[i]=g[i]=0;
    a[1]=P(0,0);
    for(i=2;i<=n;i++)scanf("%lld%lld",&a[i].a,&a[i].b);
    for(i=1;i<n;i++)scanf("%d%d",&x,&y),add(x,y),add(y,x);
    dfs(1,0);
    for(i=2;i<=n;i++)q.push(PII(a[i],PI(0,i)));
    while(!q.empty()){
      PII t=q.top();
      q.pop();
      x=t.second.second;
      if(del[x])continue;
      if(t.second.first!=vis[x])continue;
      del[x]=1;
      y=F(x);
      a[y]+=a[x];
      if(y>1)q.push(PII(a[y],PI(vis[y]=++pos,y)));
    }
    printf("%lld\n",a[1].a);
  }
}