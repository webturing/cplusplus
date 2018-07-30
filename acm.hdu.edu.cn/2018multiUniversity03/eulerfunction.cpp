#include<cstdio>
int T,k;
int main(){
  scanf("%d",&T);
  while(T--){
    scanf("%d",&k);
    if(k==1)puts("5");else printf("%d\n",5+k);
  }
}