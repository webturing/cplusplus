#include<iostream>
#include<cstdio>
#include<cstring>
int main()
{
    char *buf=new char[1000];
    while(gets(buf))
    {
        char *p=strtok(buf," ");
        int a,b;
        sscanf(p,"%d",&a);
        p=strtok(NULL," ");
        sscanf(p,"%d",&b);
        if(a==0 &&b==0)
            break;
        printf("%d\n",a+b);
    }
    return 0;
}
