#include <bits/stdc++.h>

using namespace std;

int main() {
    for (int a, b; cin >> a >> b;) {
        int c = a + b;
        ostringstream oss;
        oss << c;
        string s = oss.str();
        int k = 0;
        if (s[0] == '-') {
            cout << '-';
            k++;
        }
        for (int i = k; i < s.length(); i++) {
            cout << s[i];
            if (i != s.length() - 1 && (s.length() - 1 - i) % 3 == 0) cout << ',';
        }
        cout << endl;
    }
    return 0;
}
