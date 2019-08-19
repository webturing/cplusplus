//
// Created by jal on 2019-06-03.
//

#include<bits/stdc++.h>
using namespace std;
int main(){
    int t = 1;
    for(int i = 1; i <= 10; i++){
        ostringstream oss;
        oss << i;
        istringstream iss(oss.str());
        string s;
        iss >> s;
        s = "data" + s + ".in";
        ofstream cout(s);
        cout << t << endl;
        t *= 10;
    }

}