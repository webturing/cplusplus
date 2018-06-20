#include <bits/stdc++.h>

void solve(int x);

using namespace std;

int main(int argc, char const *argv[]) {

    int x;
    cin >> x;
    solve(x);

    return 0;
}

void solve(int x) {
    for (int i = 1; i <= x; i++) {
        for (int j = 1; j <= x - i; j++)
            cout << " ";
        for (int j = 1; j <= 2 * i - 1; j++)
            cout << j;
        cout << endl;
    }
    for (int i = x - 1; i >= 1; i--) {
        for (int j = 1; j <= x - i; j++)
            cout << " ";
        for (int j = 1; j <= 2 * i - 1; j++)
            cout << j;
        cout << endl;
    }
}
