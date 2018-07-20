#include <bits/stdc++.h>

using namespace std;
int n;
int a[2001];
int p[2001][2001];

int foo(int left, int right) {
    if (p[left][right]) return p[left][right];
    int day = n + left - right;
    if (left == right) return p[left][right] = day * a[left];
    return p[left][right] = max(foo(left + 1, right) + day * a[left], foo(left, right - 1) + day * a[right]);
}

int main() {
    ifstream cin("input.txt");
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << foo(0, n - 1) << endl;
    return 0;
}
