//
// Created by jal on 18-6-28.
//

#include <bits/stdc++.h>
using namespace std;
int main(){
    ifstream cin("input.txt");
    int n;
    cin >> n;
    vector<int>v(n);
    for(auto &i:v){
        cin >> i;
    }
    int m = 0;
    int sum = 0;
    for(int i = 0; i < n; i++){
        if(sum + v[i] > 0){
            sum += v[i];
            m = max(m, sum);
        }
        else{
            sum = 0;
        }
    }
    cout << m << endl;
}