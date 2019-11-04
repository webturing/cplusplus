//
// Created by jal on 18-7-9.
//

#include <bits/stdc++.h>
using namespace std;
bool check(int a, int b){
    while(a){
        if(a % 10 >= b){
            return false;
        }
        a /= 10;
    }
    return true;
}
int than(int a, int b){
    int ret = 0;
    while(a){
        ret = ret * b + a % 10;
        a/= 10;
    }
    int r = 0;
    while(ret){
        r = r * b + ret%b;
        ret /=b;
    }
    return r;
}
int main(){
    ifstream cin("input.txt");
    int a,b,c;
    cin>> a>>b>>c;
    for(int i = 2; i <= 16; i++){
        if(!check(a,i))continue;
        if(!check(b,i))continue;
        if(!check(c,i))continue;
        int a_value = than(a, i);
        int b_value = than(b, i);
        int c_value = than(c, i);
        if(a_value * b_value == c_value){
            cout << i << endl;
            return 0;
        }
    }
    cout << 0 << endl;
}