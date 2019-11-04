//
// Created by jal on 18-6-29.
//

#include <bits/stdc++.h>
using namespace std;
void print(vector<int>v){
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}
int main(){
    ifstream cin("input.txt");
    int n;
    cin >> n;
    vector<int>v(n);
    for(auto &i : v){
        cin >> i;
    }
    int m;
    cin >> m;
    while(m--){
        int op,val;
        cin >> op >> val;
        auto pos = find(v.begin(), v.end(), val);
        v.erase(pos);
        if(op == 0){
            v.push_back(val);
        }
        else if(op == 1){
            print(v);
            v.insert(pos,val);
        }
    }
}