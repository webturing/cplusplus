#include <bits/stdc++.h>

using namespace std;

double rp() {
    string s;
    cin >> s;
    if (s == "+")return rp() + rp();
    if (s == "-")return rp() - rp();
    if (s == "*")return rp() * rp();
    if (s == "/")return rp() / rp();
    istringstream sin(s);
    double t;
    sin >> t;
    return t;
}

int main() {
    cout << fixed << setprecision(6) << rp() << endl;
    return 0;
}