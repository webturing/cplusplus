#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    string r;
    cin >> r;
    int mx = 0;
    int bcnt = count(r.begin(), r.end(), 'b');
    int rcnt = count(r.begin(), r.end(), 'r');
    if (rcnt <= 1 || bcnt <= 1) {
        cout << n << endl;
        return 0;
    }
    for (int i = 0; i < n; i++) {
        string s = r.substr(i) + r.substr(0, i);
        int left = 0, right = 0;
        while (*(s.begin() + left) == 'w') ++left;
        while (*(s.rbegin() + right) == 'w') ++right;
        char cleft = *(s.begin() + left), cright = *(s.rbegin() + right);
        while (*(s.begin() + left) == 'w' || *(s.begin() + left) == cleft) ++left;
        while (*(s.rbegin() + right) == 'w' || *(s.rbegin() + right) == cright)
            ++right;
        mx = max(left + right, mx);
    }
    cout << min(mx, n) << endl;
    return EXIT_SUCCESS;
}