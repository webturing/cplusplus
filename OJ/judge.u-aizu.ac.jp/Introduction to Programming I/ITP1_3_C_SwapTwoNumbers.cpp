#include <bits/stdc++.h>

using namespace std;

int main() {
    for (int a, b; cin >> a >> b;) {
        if (a == 0 && b == 0) break;
        if (a > b) swap(a, b);
        cout << a << " " << b << endl;
    }
    return 0;
}