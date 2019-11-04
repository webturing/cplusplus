#include<iostream>
using namespace std;
struct node
{
    int x;
    inline int operator +(node &a) const
    {
        return x+a.x;
    }
};
int main()
{
    node a,b;
    a.x=b.x=5;
    cout<<a+b<<endl;
    return 0;
}
