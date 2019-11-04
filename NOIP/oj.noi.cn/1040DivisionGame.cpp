#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

LL gcd(LL a, LL b) {
    return b ? gcd(b, a % b) : a;
}

int main(int argc, char const *argv[]) {
    LL a, b;
    cin >> a >> b;
    LL c = gcd(a, b);
    b /= c;

    if (c % b == 0)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}