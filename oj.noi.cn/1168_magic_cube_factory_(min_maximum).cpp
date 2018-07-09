//
// Created by jal on 18-7-7.
//

#include <bits/stdc++.h>
using namespace std;
const int N = 101,M = 5001;
int a[N];
int sum,n,best = sum;
int s = 0;
void dfs(int step){
    if(step >= n) {
        best = max(best, s);
        return;
    }
    for(int i = 0; i <=1; i++){
        if(s + a[step]*i > sum/2){
            continue;
        }
        s += a[step] * i;
        dfs(step + 1);
        s -= a[step] * i;
    }
}
int main(){
    ifstream cin("input.txt");
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sum = accumulate(a,a+n,0);
    dfs(0);
    best = max(best, sum - best);
    cout << best << endl;
}