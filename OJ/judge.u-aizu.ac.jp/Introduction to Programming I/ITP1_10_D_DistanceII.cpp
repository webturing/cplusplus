#include <bits/stdc++.h>

using namespace std;

double f(const vector<double> &v, int p) {
    double s = 0;
    for (int i = 0; i < v.size(); i++) s += pow(v[i], p);
    return pow(s, 1.0 / p);
}

int main() {
    int n;
    cin >> n;
    vector<double> x(n, 0);
    vector<double> y(n, 0);
    for (int i = 0; i < n; i++) cin >> x[i];
    for (int i = 0; i < n; i++) cin >> y[i];
    vector<double> z(n);
    for (int i = 0; i < n; i++) z[i] = abs(x[i] - y[i]);
    cout << fixed << setprecision(6) << f(z, 1) << endl;
    cout << fixed << setprecision(6) << f(z, 2) << endl;
    cout << fixed << setprecision(6) << f(z, 3) << endl;
    cout << fixed << setprecision(6) << *max_element(z.begin(), z.end()) << endl;
    return 0;
}