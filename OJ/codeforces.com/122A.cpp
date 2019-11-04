//
// Created by jal on 2019-05-23.
//

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int flag = 0;
    vector<int>v = {4, 7, 47, 74, 444, 447, 477, 744, 747, 774, 777};
    for(int i = 0; i < v.size(); i++){
        if(n % v[i] == 0){
            flag = 1;
            break;
        }
    }
    cout << (flag ? "YES" : "NO") << endl;
}