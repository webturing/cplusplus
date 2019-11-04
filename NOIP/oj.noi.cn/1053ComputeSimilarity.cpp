#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int m, n;
    cin >> m >> n;
    vector<int> A(m * n), B(m * n);
    for (auto &i:A)cin >> i;
    for (auto &i:B)cin >> i;
    int s = 0;
    for (int i = 0; i < m * n; i++)
        if (A[i] == B[i])++s;
    cout << setiosflags(ios::fixed) << setprecision(2) << (100.0 * s / (m * n)) << endl;
    return 0;
}