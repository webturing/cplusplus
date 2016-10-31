#include <iostream>

using namespace std;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int lcm(int a, int b) { return a / gcd(a, b) * b; }

int main() {
    int n, i, j;
    for (cin >> n; n-- && cin >> i >> j; cout << gcd(i, j) << " " << lcm(i, j) << endl);
    return 0;
}