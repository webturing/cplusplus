#include <bits/stdc++.h>

using namespace std;
//可能数据错误，一直WA

int main() {
    // ifstream cin("input.txt");
    vector<int> f(2);
    f[0] = 4, f[1] = 3;
    int n;
    cin >> n;
    while (true) {
        int t = *f.rbegin() + *(f.rbegin() + 1);
        f.push_back(t);
        if (t > n)
            break;
    }
    for (auto p = f.rbegin(); p != f.rend() - 3; ++p) {
        n %= *p;
    }
    cout << "1234567123"[(n + 9) % 10] << endl;

    return 0;
}
