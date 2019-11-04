#include <bits/stdc++.h>

using namespace std;

inline int read_int() {
    int x;
    cin >> x;
    return x;
}

inline int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T = read_int();
    while (T--) {
        int n = read_int();
        cout << '[';
        for (int i = 0; i < n; i++)cout << '>';
        for (int i = 0; i < 100 - n; i++)cout << ' ';
        cout << ']';
        cout << setw(2) << setfill('0') << n << '%';
        cout << endl;

    }
    return 0;
}