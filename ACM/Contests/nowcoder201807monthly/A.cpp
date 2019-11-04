#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int sum = 0;
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        while (x % 2 == 0) {
            x /= 2;
            sum++;
        }
    }
    cout << sum << endl;
    return 0;
}