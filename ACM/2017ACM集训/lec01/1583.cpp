#include<iostream>
#include<stack>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
    char *c=new char[10000];
    stack<char> s;
    while(gets(c))
    {
        int len=strlen(c);
        for(int i=0;i<len;i++)
        {
            if(s.empty())
                s.push(c[i]);
            else
            {
                if(s.top()=='['&&c[i]==']')
                    s.pop();
                else if(s.top()=='{'&&c[i]=='}')
                    s.pop();
                else if(s.top()=='('&&c[i]==')')
                    s.pop();
                else
                    s.push(c[i]);
            }
        }
        if(s.empty())
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
        while(!s.empty())
            s.pop();
    }
    delete[] c;
    return 0;
}
