#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
void judge(int n)
{
    cout<<"int"<<endl;
}
void judge(double n)
{
    cout<<"double"<<endl;
}
void judge(char n)
{
    cout<<"char"<<endl;
}
int main()
{
    int a=2;
    judge(a);
    char b;
    judge(b);
    return 0;
}
