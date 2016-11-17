#include<iostream>
using namespace std;
int main() {
   int a[4][3],mi=0,mj=0,i,j;
   for(i=0;i<4;i++)for(j=0;j<3;j++)cin>>a[i][j];
   for(i=0;i<4;i++)for(j=0;j<3;j++)if(a[i][j]>a[mi][mj])mi=i,mj=j;
   cout<<a[mi][mj]<<" "<<mi<<" "<<mj<<endl;
   return 0;
}
