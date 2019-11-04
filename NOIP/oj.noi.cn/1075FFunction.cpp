#include<bits/stdc++.h>

using namespace std;

double f(double x, int n) {
    if (n == 1)
        return sqrt(1 + 2 + sqrt(x));
    return sqrt(n + f(x, n - 1));
}

int main(void) {
    double x, n;
    cin >> x >> n;
    cout << setiosflags(ios::fixed) << setprecision(2) << f(x, n) << endl;
    return 0;
}