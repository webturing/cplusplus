#include<cstdio>
#define rep(i) for(int i=0;i<n;i++)
const int N=55,M=105,inf=1000000000;
int T,n,m,x,y,q,K,A,B,z,g[N][N],d[N][N],f[N][N],a[M][N][N],b[M][N][N];
inline void up(int&a,int b){if(a>b)a=b;}
inline void mul(int a[][N],int b[][N],int c[][N]){
  static int f[N][N];
  rep(i)rep(j){
    f[i][j]=inf;
    rep(k)up(f[i][j],a[i][k]+b[k][j]);
  }
  rep(i)rep(j)c[i][j]=f[i][j];
}
int main(){
  scanf("%d",&T);
  while(T--){
    scanf("%d%d",&n,&m);
    rep(i)rep(j)g[i][j]=inf;
    while(m--){
      scanf("%d%d%d",&x,&y,&z);
      x--,y--;
      up(g[x][y],z);
    }
    rep(i)rep(j)a[0][i][j]=b[0][i][j]=i==j?0:inf;
    for(int i=1;i<M;i++)mul(a[i-1],g,a[i]);
    for(int i=1;i<M;i++)mul(b[i-1],a[100],b[i]);
    rep(i)rep(j)d[i][j]=i==j?0:g[i][j];
    rep(k)rep(i)rep(j)up(d[i][j],d[i][k]+d[k][j]);
    for(x=0;x<M;x++){
      rep(i)rep(j)f[i][j]=inf;
      rep(i)rep(j)rep(k)up(f[i][j],b[x][i][k]+d[k][j]);
      rep(i)rep(j)b[x][i][j]=f[i][j];
    }
    scanf("%d",&q);
    while(q--){
      scanf("%d%d%d",&x,&y,&K);
      x--,y--;
      A=K%100,B=K/100;
      z=inf;
      rep(i)up(z,a[A][x][i]+b[B][i][y]);
      if(z>=inf)z=-1;
      printf("%d\n",z);
    }
  }
}