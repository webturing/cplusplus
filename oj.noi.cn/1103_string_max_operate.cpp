//
// Created by jal on 18-7-11.
//

#include <bits/stdc++.h>

using namespace std;
int strchr1(string a,char k){
    int ret =  0;
    for(auto i:a){
        if(i == k)ret++;
    }
    return ret;
}
int main() {
    ifstream cin("input.txt");
    int n;
    char key;
    string s;
    cin >> n >> s;
    key = s[0];
    string str[n];
    for(int i = 0; i < n; i++){
        cin >> str[i];
    }
    int m;
    cin >> m;
    int q,left,right;
    while(m--){
        cin  >> left >> right >> q;
        if(q == 0){
            cout << *max_element(str+left-1, str+right, [](string a,string b)-> int{return a.size() <b.size();}) << endl;
        }
        else if(q == 1){
            cout << *max_element(str+left-1, str+right, [](string a,string b)-> int{return a<b;}) << endl;
        }
        else if(q == 2){
            cout << *max_element(str+left-1, str+right, [key](string a,string b)-> int{return strchr1(a,key) < strchr1(b,key);})<<endl;
        }
    }
}