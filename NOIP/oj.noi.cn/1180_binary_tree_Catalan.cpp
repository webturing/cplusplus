//
// Created by jal on 18-6-27.
//
#include <bits/stdc++.h>
using namespace std;
long long C(int m, int n){
    long long ret = 1;
    for(int i = 1; i <= n; i++){
        ret *= (m + 1 - i)/i;
    }

    return ret;
}
int main(){
    ifstream cin("input.txt");
    int n;
    cin >> n;
    cout << C(2*n,n)/(n+1)<<endl;
}
/*
 * C(2n,n)/(n+1);
 */
