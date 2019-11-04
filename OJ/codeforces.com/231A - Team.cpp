#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    int tot = 0;
    while (T--) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a + b + c >= 2)++tot;
    }
    cout << tot << endl;
    return 0;
}