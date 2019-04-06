#include <bits/stdc++.h>

using namespace std;

const double PI = atan(1.0) * 4.0;

int main(int argc, char const *argv[]) {
    double r, h;
    cin >> r >> h;
    auto area = 2 * PI * r * r + 2 * PI * r * h;
    cout << "Area=" << fixed << setprecision(3) << area << endl;
    return 0;
}