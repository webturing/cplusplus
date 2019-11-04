//
// Created by jal on 18-6-30.
//

#include <bits/stdc++.h>
using namespace std;
const int N = 310;
int a[N][N];
int b[N];
int sum[N];
int main(){
    ifstream cin("input.txt");
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    int max_sum = 0;
    for(int i = 0; i < n; i++){
        memset(b,0,sizeof(b));
        for(int j = i; j < n; j++){
            int sum = 0;
            for(int k = 0; k < n; k++){
                b[k] += a[j][k];
                if(sum <= 0){
                    sum = b[k];
                }
                else{
                    sum += b[k];
                    max_sum = max(max_sum, sum);
                }
            }
        }
    }
    cout << max_sum << endl;
}