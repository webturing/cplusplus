#include<iostream>
#include<cstdio>
using namespace std;
class s
{
private:
    double d;
public:
    void print()
    {
        while(cin>>d)
            printf("%.2f\n",d>0?d:-d);
    }
};
int main()
{
    s t;
    t.print();
    return 0;
}
