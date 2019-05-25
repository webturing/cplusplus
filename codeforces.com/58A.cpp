//
// Created by jal on 2019-05-23.
//

#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    stack<char>S;
    string s2 = "hello";
    int j = 0;
    for(int i = 0; i < s.size(); i++){
        if( j < s2.size() and S.size() <= j and s[i] == s2[j]){
            S.push(s2[j]);
            j++;
        }
    }
    if(S.size() == s2.size()){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
}