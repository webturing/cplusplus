//
// Created by jal on 18-6-28.
//
#include <bits/stdc++.h>
using namespace std;
int main(){
    ifstream cin("input.txt");
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<int>v(n);
    for(auto &i: v){
        cin >> i;
    }

    while(m--){
        int x;
        cin >> x;
        if(x < v[0]){
            cout << "-1" << endl;
            continue;
        }
        if(x >= *v.rbegin()){
            cout <<*v.rbegin()<<endl;
            continue;
        }
        int left = 0, right = n-1;
        while(left <= right){
            int mid = (left + right) >> 1;
            if(x >= v[mid]){
                left = mid+1;
            }
            else{
                right = mid-1;
            }
        }
        cout << v[left-1] <<endl;
    }
}
