#include <bits/stdc++.h>

using namespace std;

inline int read_int() {
    int x;
    cin >> x;
    return x;
}

int main() {
    for (string s; cin >> s and s != "-";) {
        for (int T = read_int(); T--;) {
            int x = read_int();
            string a(s.begin(), s.begin() + x);
            string b(s.begin() + x, s.end());
            s = b + a;
        }
        cout << s << endl;
    }

    return 0;
}