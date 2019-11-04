#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
class add
{
public:
    int a;
    int operator + (add b)
    {
        return this->a*b.a;
    }
};
int main()
{
    add a,b;
    a.a=2;
    b.a=3;
    cout<<a+b<<endl;
    return 0;
}
