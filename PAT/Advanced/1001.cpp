#include <bits/stdc++.h>

using namespace std;

int main() {
    for (int a, b; cin >> a >> b;) {
        int c = a + b;
        if (c == 0) {
            cout << 0 << endl;
            continue;
        }
        if (c < 0) {
            cout << "-";
            c *= -1;
        }
        vector<int> d;
        for (; c; c = c / 1000) d.push_back(c % 1000);

        for (int i = d.size() - 1; i >= 0; i--) {
            if (i < d.size() - 1)
                cout << setw(3) << setfill('0') << d[i];
            else
                cout << d[i];
            if (i > 0) cout << ",";
        }
        cout << endl;
    }
    return 0;
}
