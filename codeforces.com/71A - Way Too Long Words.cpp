#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream cin("input.txt");
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        if (s.size() <= 10) { cout << s << endl; }
        else {
            cout << s[0] << s.substr(1, s.size() - 2).size() << s.back() << endl;
        }
    }
    return 0;
}