//
// Created by jal on 18-7-14.
//

#include<bits/stdc++.h>

using namespace std;
int n;
const int N = 12;
int mx = 0;
int out[N], book[N];

int dist() {
    int ret = 0;
    for (int i = 1; i < n; i++) {
        ret += abs(out[i - 1] - out[i]) * abs(out[i - 1] - out[i]);
    }
    ret += abs(out[n - 1] - out[0]) * abs(out[n - 1] - out[0]);
    return ret;
}

void dfs(int step) {
    if (step >= n) {
        int dis = dist();
        if (dis > mx) {
            mx = dis;
        }
        return;
    }
    for (int i = 2; i <= n; i++) {
        if (book[i] == 0) {
            book[i] = 1;
            out[step] = i;
            dfs(step + 1);
            book[i] = 0;
        }
    }
}

int main() {
    ifstream cin("input.txt");
    cin >> n;
    book[0] = 1;
    out[0] = 1;
    dfs(1);
    cout << mx;
}