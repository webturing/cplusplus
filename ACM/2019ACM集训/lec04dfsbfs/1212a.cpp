#include<bits/stdc++.h>

using namespace std;
int main() //n!
{
    int a[]= {0,1,2,3,4,5,6,7};
    do
    {
        bool ok=true;
        for(int i=0; i<8; i++)
            for(int j=i+1; j<8; j++)
                if(abs(a[i]-a[j])==j-i)
                    ok=false;
        if(ok)
            cout<<a[0]<<a[1]<<a[2]<<a[3]<<a[4]<<a[5]<<a[6]<<a[7]<<endl;
    }
    while(next_permutation(a,a+8));

    return 0;
}
