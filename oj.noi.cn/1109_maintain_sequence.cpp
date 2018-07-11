//
// Created by jal on 18-7-11.
//

#include <bits/stdc++.h>
using namespace std;
int main(){
    ifstream cin("input.txt");
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0;i < n; i++){
        cin >> a[i];
    }
    int m;
    cin >> m;
    int op,x,y;
    while(m--){
        cin >> op >> x;
        if( op == 1){
            cout << a[x-1] << endl;
        }
        else if(op == 2){
            cin >> y;
            a.insert(a.begin()+x-1,y);
        }
        else if(op == 3){
            a.erase(a.begin()+x-1);
        }
    }
}