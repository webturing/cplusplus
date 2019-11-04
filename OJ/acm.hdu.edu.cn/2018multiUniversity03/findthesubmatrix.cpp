#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=10010;
const ll inf=1LL<<60;
int T,n,m,X,Y,i,j,k,pool[N];ll a[N],f[4][2][N],g[4][2][N],ans;
inline void up(ll&a,ll b){a<b?(a=b):0;}
inline void clr(){
  for(i=0;i<=Y;i++)for(j=0;j<2;j++)for(k=0;k<=X;k++)g[i][j][k]=-inf;
}
inline void nxt(){
  for(i=0;i<=Y;i++)for(j=0;j<2;j++)for(k=0;k<=X;k++)f[i][j][k]=g[i][j][k];
}
void solve1(int o,int l,int r,int dl,int dr){
  int mid=(l+r)>>1,dm=dl;
  ll ret=-inf;
  for(int i=dl;i<=dr&&i<=mid;i++){
    ll now=f[o][0][i];
    if(mid-i<=m)now+=a[mid-i];
    if(now>ret)ret=now,dm=i;
  }
  up(g[o][0][mid],ret);
  if(l<mid)solve1(o,l,mid-1,dl,dm);
  if(r>mid)solve1(o,mid+1,r,dm,dr);
}
void solve2(int o,int l,int r,int dl,int dr){
  int mid=(l+r)>>1,dm=dl;
  ll ret=-inf;
  for(int i=dl;i<=dr&&i<=mid;i++){
    ll now=f[o][1][i];
    if(mid-i<=m)now+=a[mid-i];
    if(now>ret)ret=now,dm=i;
  }
  up(g[o+1][0][mid],ret);
  if(l<mid)solve2(o,l,mid-1,dl,dm);
  if(r>mid)solve2(o,mid+1,r,dm,dr);
}
int main(){
  scanf("%d",&T);
  while(T--){
    scanf("%d%d%d%d",&n,&m,&X,&Y);
    clr();
    nxt();
    f[0][1][0]=0;
    while(n--){
      for(i=1;i<=m;i++)scanf("%d",&pool[i]);
      sort(pool+1,pool+m+1);
      a[0]=0;
      for(i=1;i<=m;i++)a[0]+=pool[i];
      for(i=1;i<=m;i++)a[i]=a[i-1]-pool[i];
      clr();
      for(i=0;i<=Y;i++)solve1(i,0,X,0,X);
      for(i=0;i<Y;i++)solve2(i,0,X,0,X);
      for(i=0;i<=Y;i++)for(k=0;k<=X;k++){
        up(g[i][1][k],f[i][0][k]);
        up(g[i][1][k],f[i][1][k]);
      }
      nxt();
    }
    /*
    j<k j is greater than k
    d[j]>=d[k]
    [           ]
    for()
    f[i][j][0][k]表示考虑前i行，选了完整的j个区间，换了k次，第i行选
    f[i][j][1][k]表示考虑前i行，选了完整的j个区间，换了k次，第i行不选
    
    f[0][0][0][1]=0
    
    f[i][j][0][k]
    i+1选：
    up(f[i+1][j][0][k+x],f[i][j][0][k]+a[i+1][x])
    i+1不选
    up(f[i+1][j][1][k],f[i][j][0][k])
    
    f[i][j][1][k]
    i+1选：
    up(f[i+1][j+1][0][k+x],f[i][j][1][k]+a[i+1][x])
    i+1不选：
    up(f[i+1][j][1][k],f[i][j][1][k])
    */
    ans=0;
    for(i=0;i<=Y;i++)for(j=0;j<2;j++)for(k=0;k<=X;k++)up(ans,f[i][j][k]);
    printf("%lld\n",ans);
  }
}