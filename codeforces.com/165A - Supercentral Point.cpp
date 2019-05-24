#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; i++)cin >> x[i] >> y[i];
    int sc = 0;
    for (int i = 0; i < n; i++) {
        int up = 0, down = 0, left = 0, right = 0;
        for (int j = 0; j < n; j++) {
            if (x[j] == x[i] && y[j] < y[i])up = 1;
            if (x[j] == x[i] && y[j] > y[i])down = 1;
            if (x[j] > x[i] && y[j] == y[i])left = 1;
            if (x[j] < x[i] && y[j] == y[i])right = 1;
        }
        sc += up * down * left * right;
    }
    cout << sc << endl;
    return 0;
}