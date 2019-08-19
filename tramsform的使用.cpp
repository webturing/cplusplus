//
// Created by jal on 2019-07-25.
//

#include <bits/stdc++.h>

using namespace std;

using ll=long long;


int main() {
    string s="2019-07-25 14:45:23";
    transform(s.begin(),s.end(),s.begin(),[](char c)->char{
       if(string("0123456789").find(c)==string::npos)
           return ' ';
        return c;
    });
    cout<<s<<endl;
    int y,m,d,hh,mm,ss;
    istringstream iss(s);
    iss>>y>>m>>d>>hh>>mm>>ss;
    cout<<y<<endl;
    cout<<m<<endl;
    cout<<d<<endl;
    cout<<hh<<endl;
    cout<<mm<<endl;
    cout<<ss<<endl;
    return 0;
}
