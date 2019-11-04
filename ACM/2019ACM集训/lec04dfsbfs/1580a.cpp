#include<bits/stdc++.h>

using namespace std;
bool check(int a[],int n){
    int sum=accumulate(a,a+n,0);
    if(sum&1)return false;
    for(int b=0;b<(1<<n);b++){
        bitset<21> B(b);
        int tot=0;
        for(int i=0;i<n;i++)
            if(B.test(i))tot+=a[i];
        if(tot==sum/2)
            return true;
    }
    return false;
}
int main()
{
    for(int n; cin>>n;)
    {
        int a[n];
        for(int i=0; i<n; i++)cin>>a[i];
        if(check(a,n))
            cout<<"Of course,I can!"<<endl;
        else
            cout<<"Sorry,I can't!"<<endl;

    }
    return 0;
}
