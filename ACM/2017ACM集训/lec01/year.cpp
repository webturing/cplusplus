#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
namespace s
{
    int y;
    void judge()
    {
        if(y%4==0&&y%100!=0||y%400==0)
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;
    }
}

using namespace s;
int main()
{
    while(cin>>y)
    {
        judge();
    }
    return 0;
}
