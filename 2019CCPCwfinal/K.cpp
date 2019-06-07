//
// Created by jal on 2019-06-04.
//

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    if(n % 4 != 0 or m % 4 != 0){
        cout << "no response" << endl;
    }else{
        vector<string>v = {"1113", "2133", "2243", "2444"};
        n /= 4;
        m /= 4;
        for(int i = 1; i <= n; i++){
            for(int k = 0; k < v.size(); k++){
                for(int j = 1; j <= m; j++){
                    cout << v[k];
                }
                cout << endl;
            }
        }
    }
}