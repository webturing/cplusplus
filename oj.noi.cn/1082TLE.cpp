#include <bits/stdc++.h>

using namespace std;
#define  LOCAL

int findMaxSubString(string s, string t);

int main() {
#ifdef LOCAL
    ifstream cin("input.txt");
    long long start = clock();
#endif
    for (string s, t; cin >> s >> t;) {
        s += s;
        t += t;
        cout << findMaxSubString(s, t) << endl;
    }
#ifdef LOCAL
    long long end = clock();
    cout << end - start << endl;
#endif
}

int findMaxSubString(string s, string t) {
    int m = s.length(), n = t.length();
    for (int j = min(m / 2, n / 2); j >= 1; j--)
        for (int i = 0; i < m - j; i++) {
            string cur = s.substr(i, j);
            for (int k = 0; k <= n - j; k++) {
                string cur2 = t.substr(k, j);
                if (cur == cur2) {
                    return j;
                }
            }
        }
    return 0;
}