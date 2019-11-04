#include<bits/stdc++.h>

using namespace std;
int a[21];
int used[21];
int n;
int tot=0;
bool flag=false;
void dfs(int k){
    if(flag)return ;
    if(k==n){
        int sum=0;
        for(int i=0;i<k;i++){
            if(used[i])sum+=a[i];
        }
        if(sum==tot)flag=true;
        return ;
    }
    used[k]=false;
    dfs(k+1);
    used[k]=true;
    dfs(k+1);
}

int main()
{
   while(cin>>n)
    {
        fill(used,used+n,false);
        flag=false;
        tot=0;
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
            tot+=a[i];
        }
        if(tot%2==0)
        {
            tot/=2;
            dfs(0);
        }
        if(flag)
            cout<<"Of course,I can!"<<endl;
        else
            cout<<"Sorry,I can't!"<<endl;

    }
    return 0;
}
