//
// Created by jal on 2019-06-03.
//

#include<bits/stdc++.h>
using namespace std;
using LL = unsigned long long;
int main(){
    for(int i = 1; i <= 10; i++){
        ostringstream oss;
        oss << i;
        istringstream iss(oss.str());
        string s;
        iss >> s;
        string in = "data" + s + ".in", out = "data" + s + ".out";
        ifstream cin(in);
        ofstream cout(out);

        /******make output data************/
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
        /*****************/
    }

}