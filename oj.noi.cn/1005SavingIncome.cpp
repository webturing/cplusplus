#include<bits/stdc++.h>

using namespace std;

int main() {
    double r, x, p;
    cin >> r >> x >> p;
    double y = x * pow((100 + r) / 100, p);
    cout << setiosflags(ios::fixed) << setprecision(2) << y << endl;
    return 0;
}