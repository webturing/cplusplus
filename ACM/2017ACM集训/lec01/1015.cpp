#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
class s
{
private:
    char d[1000];
public:
    void print();
};

void s::print()
{
    while(cin>>d)
    {
        int len=strlen(d);
        for(int i=0; i<len; i++)
        {
            if(d[i]>='A'&&d[i]<='Z')
                d[i]=d[i]-'A'+'a';
            cout<<d[i];
        }
        cout<<endl;

    }
}

int main()
{
    s t;
    t.print();
    return 0;
}
