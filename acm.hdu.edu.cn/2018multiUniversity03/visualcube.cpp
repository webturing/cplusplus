#include<cstdio>
const int N=200;
int T,a,b,c,n,m,i,j;char f[N][N];
int main(){
  scanf("%d",&T);
  while(T--){
    scanf("%d%d%d",&a,&b,&c);
    n=b*2+c*2+1;
    m=a*2+b*2+1;
    for(i=1;i<=n;i++)for(j=1;j<=m;j++)f[i][j]='.';
    for(i=1;i<=b;i++)for(j=1;j<=a;j++){
      f[i*2-1][j*2+1+b*2-i*2]='+';
      f[i*2-1][j*2+2+b*2-i*2]='-';
      f[i*2-1][j*2+3+b*2-i*2]='+';
      f[i*2][j*2+b*2-i*2]='/';
      f[i*2][j*2+2+b*2-i*2]='/';
    }
    for(i=1;i<=c;i++)for(j=1;j<=a;j++){
      f[i*2+b*2-1][j*2-1]='+';
      f[i*2+b*2-1][j*2]='-';
      f[i*2+b*2-1][j*2+1]='+';
      f[i*2+b*2][j*2-1]='|';
      f[i*2+b*2][j*2+1]='|';
      f[i*2+b*2+1][j*2-1]='+';
      f[i*2+b*2+1][j*2]='-';
      f[i*2+b*2+1][j*2+1]='+';
    }
    for(i=1;i<=c;i++)for(j=1;j<=b;j++){
      f[i*2+b*2-j*2][a*2+j*2+1]='|';
      f[i*2+b*2-j*2+1][a*2+j*2+1]='+';
      f[i*2+b*2-j*2+2][a*2+j*2]='/';
    }
    for(i=1;i<=n;i++){
      for(j=1;j<=m;j++)putchar(f[i][j]);
      puts("");
    }
  }
}