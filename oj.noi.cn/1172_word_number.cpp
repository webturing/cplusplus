//
// Created by ubuntu on 18-7-9.
//

#include <bits/stdc++.h>

using namespace std;

int main() {

    ifstream cin("input.txt");
    string str;
    cin >> str;
    int r = 1;
    for (auto c :str) {
        r = (r * (c - 'a' + 1)) % 10007;
    }
    cout << r << endl;
}