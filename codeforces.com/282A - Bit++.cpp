#include <bits/stdc++.h>

using namespace std;

int main() {
    int x = 0, T;
    cin >> T;
    for (string s; T-- and cin >> s;) {
        if (s == "++X" or s == "X++")++x;
        else if (s == "--X" or s == "X--")--x;
    }
    cout << x << endl;
    return 0;
}