#include <bits/stdc++.h>

using namespace std;

int main() {
    unsigned int x;
    cin >> x;
    bitset<32> b(x);
    cout << b << endl;
    b.flip();
    cout << b << endl;
    b.flip();
    b <<= 1;
    cout << b << endl;
    b >>= 2;
    cout << b << endl;
    return 0;
}