#include <bits/stdc++.h>

using namespace std;

int main() {
    for (int n; cin >> n and n != 0;) {
        vector<double> S(n);
        for (auto &e:S)cin >> e;
        double m = accumulate(S.begin(), S.end(), 0.0);
        double sd = 0;
        for (auto e:S) sd += (n * e - m) * (n * e - m);
        cout << fixed << setprecision(8) << sqrt(sd / n) / n << endl;
    }

    return 0;
}