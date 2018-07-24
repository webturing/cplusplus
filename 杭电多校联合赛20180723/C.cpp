#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
pair<double, double> P(1e9, 1e9);

bool cmp(pair<double, double> a, pair<double, double> b) {
    double ka = (a.second - P.second) / (a.first - P.first);
    double kb = (b.second - P.second) / (b.first - P.first);
    return ka > kb;
}

int main(int argc, char const *argv) {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<pair<double, double>> p(3 * n);
        for (int i = 0; i < 3 * n; i += 3) {
            for (int j = i; j < i + 3; j++) {
                cin >> p[j].first >> p[j].second;
            }
        }
        vector<pair<double, double>> q(p.begin(), p.end());
        sort(p.begin(), p.end(), cmp);
        for (auto pt:p) {
            cout << find(q.begin(), q.end(), pt) - q.begin() + 1 << " ";
        }
        cout << endl;
    }
    return 0;
}
