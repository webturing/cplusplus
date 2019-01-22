#include<bits/stdc++.h>

using namespace std;

int cnr(int n, int r) {
    if (r == 0 || n == r)return 1;
    return cnr(n - 1, r - 1) + cnr(n - 1, r);
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cout << cnr(i, j) << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}
