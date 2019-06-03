//
// Created by jal on 2019-06-03.
//

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    double s = 0;
    for(int i = 0; i < n; i++){
        double x;
        cin >> x;
        if(s >= 100  && s < 150){
            s += x * 0.8;
        }else if(s >= 150 && s < 400){
            s += x * 0.5;
        }else{
            s += x;
        }
    }
    cout << fixed << setprecision(2) << s << endl;
    return 0;
}