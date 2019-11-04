#include<bits/stdc++.h>

using namespace std;

bool check(int n) {
    while (n > 0) {
        int k = n % 10;
        if (k != 4 and k != 7)return false;
        n /= 10;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    bool flag = false;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0 and (check(i) or check(n / i))) {
            flag = true;
            break;
        }
    }
    if (flag)cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}

