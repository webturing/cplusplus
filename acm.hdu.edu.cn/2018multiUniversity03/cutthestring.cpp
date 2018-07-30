#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=100010,S=26;
int T,n,m,i,j,len,x,y,ca,cb,ans;char s[N];
struct AP{
  int s,d,r,f;
  //k*d+s 0<=k<=r
  AP(){}
  AP(int _s,int _d,int _r,int _f){s=_s,d=_d,r=_r,f=_f;}
}a[N],b[N];
struct DS{
  int all,son[N][S],fail[N],len[N],diff[N],top[N],text[N],last,tot,f[N];
  int newnode(int l){
    for(int i=0;i<S;i++)son[tot][i]=0;
    fail[tot]=diff[tot]=top[tot]=0,len[tot]=l;
    return tot++;
  }
  void init(){
    last=tot=all=0;
    newnode(0),newnode(-1);
    text[0]=-1,fail[0]=1;
  }
  int getfail(int x){
    while(text[all-len[x]-1]!=text[all])x=fail[x];
    return x;
  }
  void add(int w){
    w-='a';
    text[++all]=w;
    int x=getfail(last);
    if(!son[x][w]){
      int y=newnode(len[x]+2);
      int z=son[getfail(fail[x])][w];
      son[x][w]=y;
      fail[y]=z;
      diff[y]=len[y]-len[z];
      if(diff[y]!=diff[z]||len[z]<1)top[y]=y;else top[y]=top[z];
    }
    last=son[x][w];
    f[all]=last;
  }
  void get(int x,AP q[],int&cnt){
    cnt=0;
    x=f[x];
    while(len[x]>0){
      int y=top[x];
      q[++cnt]=AP(len[y],diff[x],(len[x]-len[y])/diff[x],len[x]);
      //printf("! %d %d %d\n",len[y],len[x],diff[x]);
      x=fail[y];
    }
  }
}pre,suf;
ll exgcd(ll a,ll b,ll&x,ll&y){
  if(!b)return x=1,y=0,a;
  ll d=exgcd(b,a%b,x,y),t=x;
  return x=y,y=t-a/b*y,d;
}
inline ll solve(ll a,ll b,ll c,ll xl,ll xr,ll yl,ll yr){
  if(xl>xr)return 0;
  if(yl>yr)return 0;
  if(!a&&!b){
    if(c)return 0;
    return (xr-xl+1)*(yr-yl+1);
  }
  if(!b){
    swap(a,b);
    swap(xl,yl);
    swap(xr,yr);
  }
  if(!a){
    if(c%b)return 0;
    ll y=-c/b;
    if(y<yl||y>yr)return 0;
    return xr-xl+1;
  }
  ll x,y,d=exgcd((a%abs(b)+abs(b))%abs(b),abs(b),x,y);
  if(c%d)return 0;
  x=(x%abs(b)+abs(b))%abs(b)*((((-c)%abs(b))+abs(b))%abs(b)/d)%abs(b/d);
  d=abs(b/d);
  ll kl=(xl-x)/d-3,kr=(xr-x)/d+3;
  while(x+kl*d<xl)kl++;
  while(x+kr*d>xr)kr--;
  ll A=(-yl*b-a*x-c)/(a*d),B=(-yr*b-a*x-c)/(a*d);
  if(A>B)swap(A,B);
  kl=max(kl,A-3);
  kr=min(kr,B+3);
  while(kl<=kr){
    ll y=(-c-a*x-a*d*kl)/b;
    if(yl<=y&&y<=yr)break;
    kl++;
  }
  while(kl<=kr){
    ll y=(-c-a*x-a*d*kr)/b;
    if(yl<=y&&y<=yr)break;
    kr--;
  }
  if(kl>kr)return 0;
  return kr-kl+1;
}
int main(){
  scanf("%d",&T);
  while(T--){
    scanf("%d%d%s",&n,&m,s+1);
    pre.init();
    suf.init();
    for(i=1;i<=n;i++)pre.add(s[i]);
    for(i=n;i;i--)suf.add(s[i]);
    while(m--){
      scanf("%d%d",&x,&y);
      len=y-x+1;
      pre.get(y,a,ca);
      suf.get(n-x+1,b,cb);
      ans=0;
      for(i=1;i<=ca;i++)for(j=1;j<=cb;j++){
        if(a[i].s+b[j].s>len)continue;
        if(a[i].f+b[j].f<len)continue;
        ans+=solve(a[i].d,b[j].d,a[i].s+b[j].s-len,0,a[i].r,0,b[j].r);
      }
      printf("%d\n",ans);
    }
  }
}