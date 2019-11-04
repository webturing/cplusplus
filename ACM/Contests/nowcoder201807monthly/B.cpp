#include <bits/stdc++.h>

using namespace std;

int main() {
    double x, y;
    while (cin >> x >> y) {
        double a = y * log(x);
        double b = x * log(y);
        cout << a << " " << b << endl;
        if (abs(a - b) < 0.00000000001) {
            cout << "=" << endl;
        } else if (a < b) {
            cout << "<" << endl;
        } else {
            cout << ">" << endl;
        }
    }
    return 0;
}