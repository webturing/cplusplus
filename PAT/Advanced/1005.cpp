#include <bits/stdc++.h>

using namespace std;
map<int, string> D;

void init() {
    D[0] = "zero";
    D[1] = "one";
    D[2] = "two";
    D[3] = "three";
    D[4] = "four";
    D[5] = "five";
    D[6] = "six";
    D[7] = "seven";
    D[8] = "eight";
    D[9] = "nine";
}

int main() {
    init();
    for (string s; cin >> s;) {
        int sum = 0;
        for (auto c : s) sum += c - '0';
        ostringstream oss;
        oss << sum;
        string t = oss.str();
        for (auto i = 0u; i < t.size(); i++) {
            if (i) cout << " ";
            cout << D[t[i] - '0'];
        }
        cout << endl;
    }
    return 0;
}