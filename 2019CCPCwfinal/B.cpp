//
// Created by jal on 2019-06-03.
//

#include <bits/stdc++.h>
using namespace std;
using LL = unsigned long long;
int main(){
    LL n;
    while(cin >> n) {
        LL s = n * (n + 1) / 2, s2 = s;
        map<LL, int> M;
        int i = 2;
        bool flag = false;
        while (i <= s / i) {
            if(s % i == 0){
                flag = true;
                break;
            }
            i++;
        }
       cout << s / i << endl;
    }
}