#include <bits/stdc++.h>

using namespace std;

int main() {
    double a, b, C;
    cin >> a >> b >> C;
    double c = sqrt(a * a + b * b - 2 * a * b * cos(C / 180.0 * acos(-1)));
    double s = (a + b + c) / 2;
    double S = sqrt(s * (s - a) * (s - b) * (s - c));
    double L = a + b + c;
    double h = S * 2 / a;
    cout << fixed << setprecision(8) << S << endl << L << endl << h << endl;
    return 0;
}