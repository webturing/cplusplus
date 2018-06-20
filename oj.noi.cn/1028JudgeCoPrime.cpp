#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int main(int argc, char const *argv[]) {
    int a, b;
    cin >> a >> b;
    cout << (gcd(a, b) == 1 ? "Yes" : "No") << endl;
    return 0;
}
