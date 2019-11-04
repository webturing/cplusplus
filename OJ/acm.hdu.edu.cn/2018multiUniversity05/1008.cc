#include <bits/stdc++.h>

using namespace std;
const double pi = acos(-1);

int main() {
    ifstream cin("input.txt");
    int T;
    cin >> T;
    while (T--) {
        int n;
        double R;
        cin >> n >> R;
        double X = 0, Y = 0;
        double r, x, y;
        double L = 2 * pi * R;
        for (int i = 0; i < n; i++) {
            cin >> x >> y >> r;
            double a = hypot(x - X, y - Y);
            if (a >= r + R || a < abs(R - r)) continue;
            if (a == R - r) {
                L += 2 * pi * r;
                continue;
            }
            double s = acos((a * a + r * r - R * R) / (2 * a * r));
            double t = acos((a * a + R * R - r * r) / (2 * a * R));
            if (R < r && a <= abs(R - r)) t = pi - t;
            L += 2 * s * r - 2 * t * R;
        }
        cout << L << endl;
    }
    return 0;
}
