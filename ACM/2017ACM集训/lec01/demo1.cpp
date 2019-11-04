#include<iostream>
#include<stdio.h>
namespace stdd
{
    class osin
    {
    public:
        inline osin & operator >>(int& a)
        {
            scanf("%d",&a);
            return *this;
        }
    };
    template<class T>
    class osout
    {
    public:
        inline osout& operator<<(T &a)
        {
            printf("%d",a);
            return *this;
        }
    };
    osin cin;
    osout<int> cout;
}
using namespace stdd;
int main()
{
    int a,b;
    cin>>a>>b;
    cout<<a<<b;
    return 0;
}
