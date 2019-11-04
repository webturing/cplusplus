#include <bits/stdc++.h>
using namespace std;

/**
 * C++ qsort 采用快速排序，非稳定排序
 * C++ stable_sort采用归并排序 是快速的稳定排序，首选
 */

int main() {
    int n;
    cin >> n;
    string k;
    cin >> k;
    char c = k[0];
    vector<string> S(n);
    for (auto &s:S)cin >> s;
    int q;
    cin >> q;
    while (q--) {
        int left, right, type;
        cin >> left >> right >> type;
        --left;
        vector<string> T(S.begin() + left, S.begin() + right);
        if (type == 0) {
            stable_sort(T.begin(), T.end(), [](string a, string b) -> bool { return a.length() > b.length(); });
        } else if (type == 1) {
            sort(T.begin(), T.end(), [](string a, string b) { return a > b; });
        } else if (type == 2) {
            auto ff = [c](string s) -> int { return count(s.begin(), s.end(), c); };
            stable_sort(T.begin(), T.end(), [ff](string a, string b) -> bool { return ff(a) > ff(b); });
        }
        cout << *T.begin() << endl;
    }

    return 0;
}