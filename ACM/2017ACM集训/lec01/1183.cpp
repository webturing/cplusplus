#include<iostream>
#include<cstdio>
#include<cstring>
int gcd(int a,int b)
{
    int c;
    while(b)
    {
        c=a%b;
        a=b;
        b=c;
    }
    return a;
}
int main()
{
    char *buf=new char[1000];
    gets(buf);
    int T;
    sscanf(buf,"%d",&T);
    while(T--)
    {
        gets(buf);
        char *p=strtok(buf," ");
        int a,b;
        sscanf(p,"%d",&a);
        p=strtok(NULL," ");
        sscanf(p,"%d",&b);
        if(a==0 &&b==0)
            break;
        int t=gcd(a,b);
        printf("%d %d\n",t,a*b/t);
    }
    return 0;
}
