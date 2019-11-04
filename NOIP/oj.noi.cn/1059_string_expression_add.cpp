//
// Created by jal on 18-7-9.
//

#include <bits/stdc++.h>
using namespace std;
int main(){
    ifstream cin("input.txt");
    string str;
    cin >> str;
    int sum = 0;
    int t = 0;
    int pos = 0;
    for(; pos < str.size(); pos++){
        if(str[pos]!='+'){
            t = t* 10 + str[pos]-'0';
        }
        else{
            sum+=t;
            t= 0;
        }
    }
    sum+=t;
    cout << sum<<endl;
}