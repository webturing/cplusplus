//
// Created by jal on 18-7-12.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream cin("input.txt");
    int n, m;
    cin >> n >> m;
    vector<int> w;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        if (t == m) {
            cout << m << endl;
            return 0;
        }
        if (t < m)w.push_back(t);
    }

    sort(w.begin(), w.end());
    int b1 = *w.rbegin();

    vector<int>ww;
    for(auto i : w){
        for(auto j: w){
            if(i + j == m){
                cout << m << endl;
                return 0;
            }
            if(i + j < m){
                ww.push_back(i+j);
            }
        }
    }

    sort(ww.begin(), ww.end());
    int b2 = *ww.rbegin();

    int b3 = 0;
    vector<int>www;
    for(auto i:w){
        int y = m - i;
        int pos = lower_bound(ww.begin(), ww.end(), y) - ww.begin();
        if(ww[pos] == y){
            cout << m << endl;
            return 0;
        }
        else{
            b3 = max(b3, ww[pos-1] + i);
        }
    }

    int b4 = 0;
    vector<int>wwww;
    for(auto i : ww){
        int y = m - i;
        int pos = lower_bound(ww.begin(), ww.end(), y) - ww.begin();
        if(ww[pos] == y){
            cout << m << endl;
            return 0;
        }
        else{
            b4 = max(b4, ww[pos-1] + i);
        }
    }

    int MAX = 0;
    MAX = max(MAX, b1);
    MAX = max(MAX, b2);
    MAX = max(MAX, b3);
    MAX = max(MAX, b4);
    cout << MAX << endl;
}