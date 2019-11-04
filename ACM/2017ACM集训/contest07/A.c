#include<stdio.h>
void in(int *a)
{
    char ch;
    while((ch = getchar())&&(ch<'0'||ch>'9'));
    for(*a=0; ch>='0'&&ch<='9'; ch = getchar())
        *a = (*a<<3)+(*a<<1)+ch-'0';


}


int main()
{
    int i,t,n,s,a;
    in(&t);
    while(t--)
    {
        in(&n);
        s=0;
        for(i=0; i<n; i++)
        {
            in(&a);
            s^=a;
        }
        puts(s==0?"HRDV":"PIAOYI");
    }
    return 0;
}
