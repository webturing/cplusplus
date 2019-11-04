//
// Created by ubuntu on 18-7-9.
//

#include <bits/stdc++.h>

using namespace std;
const int N = 21;
int n;
int book[N];
int out[N];
int cnt = 0;
bool fin = false;
bool f[N * 2];

bool isPrime(int n) {
    if (n == 1)return false;
    if (n == 2)return true;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

void prime() {
    for (int i = 1; i <= 2 * n; i++) {
        if (isPrime(i)) {
            f[i] = true;
        } else {
            f[i] = false;
        }
    }
}

void dfs(int step) {
    if (fin)return;
    if (step >= n) {
        if (f[out[step - 1] + out[0]]) {
            copy(out, out + n, ostream_iterator<int>(cout, " "));
            fin = true;
        }
        return;
    }
    for (int i = 2; i <= n; i++) {
        if (!book[i] && f[out[step - 1] + i]) {
            out[step] = i;
            book[i] = true;
            dfs(step + 1);
            book[i] = false;
        }
    }
}

int main() {
    ifstream cin("input.txt");
    cin >> n;
    if (n & 1) {
        cout << -1 << endl;
        return 0;
    }
    prime();
    book[1] = 1;
    out[0] = 1;
    dfs(1);
    if (!fin) {
        cout << -1 << endl;
    }
}