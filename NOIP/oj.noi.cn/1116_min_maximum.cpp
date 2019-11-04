//
// Created by jal on 18-7-8.
//

#include <bits/stdc++.h>
using namespace std;
const int N = 100001, M = 100001;
int a[N];
int main(){
    ifstream cin("input.txt");
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int left = *max_element(a, a+n);
    int right = accumulate(a, a+n, 0);
    int best = right;
    while(left < right){
        int mid = (left + right) >> 1;
        int s = a[0];
        int t = 1;
        for(int i = 1; i < n; i++){
            if(s + a[i] > mid){
                s = a[i];
                t++;
            }else{
                s += a[i];
            }
            if(t > m){
                break;
            }
        }
        if(t > m){
            left = mid+1;
        }
        else{
            right = mid;
            if(t == m)best = min(best, mid);
        }
    }
    cout << best << endl;
}