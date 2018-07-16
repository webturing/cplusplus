//
// Created by jal on 18-7-14.
//

#include<bits/stdc++.h>

using namespace std;

long long C(int n, int m) {
    long long ret = 1;
    for (int i = 1; i <= m; i++) {
        ret *= n - i + 1;
        ret /= i;
    }
    return ret;
}

int main() {
    ifstream cin("input.txt");
    int n;
    cin >> n;
    cout << C(2 * n, n) / (n + 1) << endl;
}