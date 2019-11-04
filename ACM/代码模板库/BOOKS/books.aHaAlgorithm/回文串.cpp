
//
// Created by jal on 18-9-2.
//
#include <bits/stdc++.h>

using namespace std;

bool f(string s){
    stack<char> stk;
    int len = s.size();
    int mid = len/2;
    for(int i = 0; i < mid; i++){
        stk.push(s[i]);
    }
    if(len&1){
        mid++;
    }
    for(int i = mid; i < len; i++){
        char t = stk.top();
        stk.pop();
        if(t != s[i]){
            return false;
        }
    }
    return true;
}
int main() {
    string s1="123454321";
    string s2="1234554321";

    cout << f(s1) << endl;
    cout << f(s2) << endl;

    string s3="13454321";
    string s4="134554321";
    cout << f(s3) << endl;
    cout << f(s4) << endl;
}
