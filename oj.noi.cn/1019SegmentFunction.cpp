#include <bits/stdc++.h>

using namespace std;


double f(double x) {
    if (x < 5)return x + 2.5;
    if (x < 10)return 2 - 1.5 * (x - 3) * (x - 3);
    return x / 2 - 1.5;
}

int main(int argc, char const *argv[]) {
    double x;
    cin >> x;
    cout << setiosflags(ios::fixed) << setprecision(3) << f(x) << endl;

    return 0;
}