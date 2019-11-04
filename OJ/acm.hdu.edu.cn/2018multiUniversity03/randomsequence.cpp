#include<cstdio>
const int N=110,M=1500,P=1000000007;
int T,n,m,i,j,k,x,y,cnt,gcd[N][N],v[N],a[N],id[N][N][N],g[M][N],w[M][N],f[N][M],ans;
int getgcd(int a,int b){return b?getgcd(b,a%b):a;}
int po(int a,int b){int t=1;for(;b;b>>=1,a=1LL*a*a%P)if(b&1)t=1LL*t*a%P;return t;}
inline void up(int&a,int b){a=a+b<P?a+b:a+b-P;}
int main(){
  scanf("%d",&T);
  while(T--){
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)scanf("%d",&a[i]);
    for(i=1;i<=m;i++)scanf("%d",&v[i]);
    for(i=1;i<=m;i++)for(j=1;j<=m;j++)gcd[i][j]=getgcd(i,j);
    cnt=0;
    for(i=1;i<=m;i++)for(j=i;j<=m;j+=i)for(k=j;k<=m;k+=j)id[i][j][k]=++cnt;
    for(i=1;i<=m;i++)for(j=i;j<=m;j+=i)for(k=j;k<=m;k+=j){
      x=id[i][j][k];
      for(y=1;y<=m;y++){
        g[x][y]=id[gcd[j][y]][gcd[k][y]][y];
        w[x][y]=v[gcd[i][y]];
      }
    }
    for(i=1;i<=n;i++)for(j=1;j<=cnt;j++)f[i][j]=0;
    for(i=1;i<=m;i++)for(j=1;j<=m;j++)for(k=1;k<=m;k++){
      if(a[1]&&i!=a[1])continue;
      if(a[2]&&j!=a[2])continue;
      if(a[3]&&k!=a[3])continue;
      up(f[3][id[gcd[gcd[i][j]][k]][gcd[j][k]][k]],1);
    }
    for(i=3;i<n;i++)for(j=1;j<=cnt;j++)if(f[i][j])for(k=1;k<=m;k++){
      if(a[i+1]&&k!=a[i+1])continue;
      up(f[i+1][g[j][k]],1LL*f[i][j]*w[j][k]%P);
    }
    ans=0;
    for(j=1;j<=cnt;j++)up(ans,f[n][j]);
    for(i=1;i<=n;i++)if(!a[i])ans=1LL*ans*po(m,P-2)%P;
    printf("%d\n",ans);
  }
}