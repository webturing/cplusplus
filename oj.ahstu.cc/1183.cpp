#include<iostream>

using namespace std;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int main() {
    int n, i, j;
    for (cin >> n; n-- && cin >> i >> j; cout << gcd(i, j) << " " << i * j / gcd(i, j) << endl);
    return 0;
}
