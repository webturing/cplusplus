#include<cstdio>
int T,n,i,x,y,sum;
int main(){
  scanf("%d",&T);
  while(T--){
    scanf("%d",&n);
    sum=0;
    for(i=1;i<=n;i++)scanf("%d",&x),sum^=x;
    for(i=1;i<n;i++)scanf("%d%d",&x,&y);
    puts(sum?"Q":"D");
  }
}