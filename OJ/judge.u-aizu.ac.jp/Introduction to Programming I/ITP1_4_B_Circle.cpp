#include <bits/stdc++.h>

using namespace std;

int main() {
    double r;
    cin >> r;
    const double pi = acos(-1);
    double area = pi * r * r;
    double perimeter = 2 * pi * r;
    cout << fixed << setprecision(5) << area << " " << perimeter << endl;
    return 0;
}