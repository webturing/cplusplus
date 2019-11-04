#include <bits/stdc++.h>

using namespace std;

int main() {
    char endl = '\n';
    ifstream cin("in.txt");
    ios::sync_with_stdio(false);
    set<int> S;
    int q;
    cin >> q;
    while (q--) {
        int op, x;
        cin >> op >> x;
        if (op == 0) {
            S.insert(x);
            cout << S.size() << endl;
        } else if (op == 1) {
            cout << (S.find(x) != S.end()) << endl;
        } else if (op == 2) {
            S.erase(x);
        } else if (op == 3) {
            int L = x;
            int R;
            cin >> R;
            auto left = lower_bound(S.begin(), S.end(), L);
            auto right = upper_bound(S.begin(), S.end(), R);
            for (auto p = left; p != right; p++) {
                cout << *p << endl;
            }
        }
    }

    return 0;
}