//
// Created by jal on 18-9-8.
//
#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    int w = 0, b = 0;
    for (auto c : s) {
        if (c == 'w') {
            w++;
        } else {
            b++;
        }
    }
    int t = min(w, b) * 2;
    if (s.size() > t)t++;
    cout << t << endl;
}