//
// Created by jal on 2019-05-22.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main(){
//    ifstream cin("input.txt");
    LL h;
    int n;
    cin >> h >> n;
    vector<LL>v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    vector<LL>sum(n);
    partial_sum(v.begin(), v.end(), sum.begin());
    LL cnt = 0;
    LL MIN = v[0];
    for(int i = 1; i < n; i++){
        if(sum[i] < MIN){
            MIN = sum[i];
        }
    }
    if(sum[n-1] >= 0 && h + MIN > 0){
        cout << -1 << endl;
        return 0;
    }
    cnt = ceil(1.0*(h+MIN) / (-sum[n-1]));
    if((h+MIN) < 0)cnt = 0;
    h += sum[n-1]*cnt;
    cnt *= n;
    for(int i = 0; i < n; i++){
        if(h + sum[i] <= 0){
            cnt += i+1;
            cout << cnt << endl;
            break;
        }
    }
}