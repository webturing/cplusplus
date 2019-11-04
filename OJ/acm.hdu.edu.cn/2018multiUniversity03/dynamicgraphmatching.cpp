#include<cstdio>
const int N=1<<10,P=1000000007;
int T,n,m,all,i,x,y,S,f[N],cnt[N],ans[N];char op[9];
inline void add(int&a,int b){a=a+b<P?a+b:a+b-P;}
inline void sub(int&a,int b){a=a-b>=0?a-b:a-b+P;}
int main(){
  scanf("%d",&T);
  while(T--){
    scanf("%d%d",&n,&m);
    all=1<<n;
    for(i=0;i<all;i++)f[i]=0,cnt[i]=__builtin_popcount(i);
    f[0]=1;
    while(m--){
      scanf("%s%d%d",op,&x,&y);
      x--,y--;
      S=(1<<x)|(1<<y);
      if(op[0]=='+'){
        for(i=all-1;~i;i--)if(!(i&S))add(f[i^S],f[i]);
      }else{
        for(i=0;i<all;i++)if(!(i&S))sub(f[i^S],f[i]);
      }
      for(i=1;i<=n;i++)ans[i]=0;
      for(i=1;i<all;i++)add(ans[cnt[i]],f[i]);
      for(i=2;i<=n;i+=2)printf("%d%c",ans[i],i<n?' ':'\n');
    }
  }
}