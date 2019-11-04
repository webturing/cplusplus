#include<bits/stdc++.h>

using namespace std;
int main() //2^4 0000~1111
{
    int A[]={3,4,7,9},M=20;
    int a, b, c, d;
    for(a=0; a<=1; a++)
        for(b=0; b<=1; b++)
            for(c=0; c<=1; c++)
                for(d=0; d<=1; d++)
                {
                    //cout<<a<<b<<c<<d<<endl;
                    if(a*A[0]+b*A[1]+c*A[2]+d*A[3]==M){
                        cout<<a<<b<<c<<d;
                        return 0;
                    }
                }


    return 0;
}
