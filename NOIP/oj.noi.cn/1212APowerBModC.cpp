#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

LL pow(LL a, LL b, LL c) {
    a %= c;
    if (a == 1 || b == 0)
        return 1LL;
    if (a == 0 || b == 1)
        return a % c;
    if (b & 1) {
        return (pow(a * a % c, b >> 1, c) * a) % c;
    }
    return pow(a * a % c, b >> 1, c);
}

int main(int argc, char const *argv[]) {
    LL a, b, c;
    cin >> a >> b >> c;
    cout << pow(a, b, c) << endl;
    return 0;
}