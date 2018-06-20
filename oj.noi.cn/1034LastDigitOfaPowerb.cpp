#include <bits/stdc++.h>

using namespace std;


int main(int argc, char const *argv[]) {
    int a, b;
    cin >> a >> b;
    a %= 10;
    if (b == 0 || a == 1) {
        cout << 1 << endl;
        return 0;
    }
    b %= 4;
    if (b == 0)b += 4;
    int t = 1;
    while (b--) { t *= a; }
    cout << t % 10 << endl;
    return 0;
}