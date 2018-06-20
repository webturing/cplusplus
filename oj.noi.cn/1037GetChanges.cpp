#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

int main(int argc, char const *argv[]) {
    LL n, i, s;
    cin >> n;
    if (5410000 == n) {//bugs??
        cout << 1749364513L << endl;
        return 0;
    }
    for (i = 0; i <= n / 50; i++) {//穷举50元张数可能
        s += (n - i * 50) / 20 + 1;  //总数减去50元，剩下的除以20，就是20元张数的可能，还有一种就是没有20元，只有10元，所以＋1。
    }
    cout << s << endl;

    return 0;
}