#include <bits/stdc++.h>

using namespace std;

/**
 * 带比较函数的max_element /min_element的写法
 * @return
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
        auto start = S.begin() + left - 1, end = S.begin() + right;
        if (type == 0) {
            cout << *min_element(start, end, [](string a, string b) -> bool { return a.length() > b.length(); })
                 << endl;
        } else if (type == 1) {
            cout << *min_element(start, end, [](string a, string b) { return a > b; }) << endl;
        } else if (type == 2) {
            auto ff = [c](string s) -> int { return count(s.begin(), s.end(), c); };
            cout << *min_element(start, end, [ff](string a, string b) -> bool { return ff(a) > ff(b); }) << endl;
        }
    }

    return 0;
}