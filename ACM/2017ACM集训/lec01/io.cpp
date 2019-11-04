#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
    char n[100];
    cin>>n;
    char *p=strtok(n," ");
    while(p!=NULL)
    {
        cout<<p<<endl;
        p=strtok(NULL," ");
    }
    return 0;
}
