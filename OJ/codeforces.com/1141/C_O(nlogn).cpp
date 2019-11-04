//
// Created by jal on 2019-05-21.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main(){
//    ifstream cin("input.txt");
    int n;
    cin >> n;
    LL s1 = 1LL*n * (n+1)/2;
    vector<LL>p(n),q(n-1);
    for(auto &i : q){
        cin >> i;
    }
    int flag = 0;
    int left = 1, right = n;
    while(left <= right){
        p[0] = (left + right )>>1;
        LL sum = p[0];
        for(int i = 1; i < n; i++){
            p[i] = p[i-1] + q[i-1];
            sum += p[i];
        }
        if(sum == s1){
            flag = 1;
            map<int,int>mp;
            for(auto i:p){
                mp[i]++;
            }
            for(int i = 1; i <= n; i++){
                if(mp[i] != 1){
                    flag = 0;
                    break;
                }
            }
            if(flag){
                for(auto i: p){
                    cout << i << " ";
                }
                cout << endl;
            }
            break;
        }
        if(sum > s1){
            right = p[0]-1;
        }else{
            left = p[0]+1;
        }
    }
    if(flag == 0){
        cout << -1 << endl;
    }
}