#include <bits/stdc++.h>

using namespace std;

inline int read_int() {
    int x;
    cin >> x;
    return x;
}

inline string read_str() {
    string s;
    cin >> s;
    return s;
}

int main() {
    string s = read_str();
    for (int q = read_int(); q--;) {
        string op = read_str();
        int a = read_int(), b = read_int();
        if (op == "replace") {
            string p = read_str();
            string head(s.begin(), s.begin() + a);
            string tail(s.begin() + b + 1, s.end());
            s = head + p + tail;
        } else if (op == "reverse") {
            reverse(s.begin() + a, s.begin() + b + 1);
        } else if (op == "print") {
            copy(s.begin() + a, s.begin() + b + 1, ostream_iterator<char>(cout, ""));
            cout << endl;
        }
    }

    return 0;
}