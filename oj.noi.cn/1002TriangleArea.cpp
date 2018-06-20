#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    double a, b, c;
    cin >> a >> b >> c;
    double s = (a + b + c) / 2;
    double area = sqrt(s * (s - a) * (s - b) * (s - c));
    cout << setiosflags(ios::fixed) << setprecision(4) << area << endl;
    return 0;
}