#include<iostream>

using namespace std;

int main() {
    int n;
    for (cin >> n; n != 1;)
        if (n % 2 == 0) {
            cout << n << "/2=" << n / 2 << endl;
            n >>= 1;
        }
        else {
            cout << n << "*3+1=" << 3 * n + 1 << endl;
            n = 3 * n + 1;
        }
    return 0;
}
