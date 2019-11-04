#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << '[';
        for (int i = 1; i <= n; i++)
            cout << '>';
        for (int i = 1; i <= 100 - n; i++)
            cout << ' ';
        cout << ']';
        cout << setw(2) << setfill('0') << n << endl;
    }

    return 0;
}