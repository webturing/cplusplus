#include<bits/stdc++.h>

using namespace std;
typedef long long LL;

int count(LL n) {
    int tot = 0;
    while (n) {
        int d = n % 10;
        n /= 10;
        if (d == 4 or d == 7)
            ++tot;
    }
    return tot;
}


int main() {
    LL n;
    cin >> n;
    int m = count(n);
    cout << (m == 4 or m == 7 ? "YES" : "NO") << endl;
    return 0;
}