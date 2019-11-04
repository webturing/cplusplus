#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    for (int n; cin >> n;) {
        map<int, double> m;
        int N = 0;
        for (int i = 0; i < 2; i++) {
            if (i > 0) cin >> n;
            while (n--) {
                int p;
                double f;
                cin >> p >> f;
                m[p] += f;
                if (p > N) N = p;
            }
        }
        int cnt = 0;
        for (auto p : m)
            if (p.second != 0) ++cnt;
        cout << cnt;
        for (int i = N; i >= 0; i--) {
            if (m[i] != 0)
                cout << " " << i << " " << fixed << setprecision(1) << m[i];
        }
        cout << endl;
    }
    return 0;
}
