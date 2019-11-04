//
// Created by ubuntu on 18-7-1.
//

#include <bits/stdc++.h>

using namespace std;

string rp() {
    string s;
    cin >> s;
    if (s == "+") {
        string s1 = rp();
        string s2 = rp();
        return s1 + " " + s2 + " +";
    }
    if (s == "-") {
        string s1 = rp();
        string s2 = rp();
        return s1 + " " + s2 + " -";
    }
    return s;
}

int main() {
    cout << rp() << endl;
    return 0;
}