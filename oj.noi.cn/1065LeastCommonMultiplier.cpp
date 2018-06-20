#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int lcm(int a, int b) { return a / gcd(a, b) * b; }

int main(int argc, char const *argv[]) {
    int n, m;
    cin >> n >> m;
    cout << lcm(n, m) << endl;
    return 0;
}