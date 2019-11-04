//
// Created by jal on 18-6-29.
//

#include <bits/stdc++.h>
using namespace std;
struct JAL{
    int val;
    string name;
};
int main(){
    ifstream cin("input.txt");
    int n,q;
    cin >> n >> q;
    vector<JAL>v(n+1);
    for(int i = 1; i<= n; i++){
        cin >> v[i].val;
    }
    for(int i = 1; i<= n; i++){
        cin >> v[i].name;
    }
    while(q--){
        int sum = 0;
        string name;
        int left,right;
        cin >> name >> left >> right;
        for(int i= left; i <= right; i++){
            if(v[i].name == name){
                sum += v[i].val;
            }
        }
        cout << sum << endl;
    }
}