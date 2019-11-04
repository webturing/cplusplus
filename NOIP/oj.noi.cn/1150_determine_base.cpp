//
// Created by jal on 18-7-4.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

bool suitable(string a, int B);

LL tran(string a, int B);

int main(){
    ifstream cin("input.txt");
    string a,b,c;
    cin >> a >> b >> c;
    bool find = false;
    for(int B = 2; B <= 16; B++){
        if(!suitable(a,B))continue;
        if(!suitable(b,B))continue;
        if(!suitable(c,B))continue;
        if(tran(a,B)*tran(b,B)==tran(c,B)){
            cout << B << endl;
            find = true;
            break;
        }
    }
    if(!find)cout<<0<<endl;
}

LL tran(string a, int B) {
    LL ret = 0;
    for(auto i:a){
        ret = ret*B + i-'0';
    }
    return ret;
}

bool suitable(string a, int B) {
    for (auto i:a){
        if(i-'0' >=B)return false;
    }
    return true;
}