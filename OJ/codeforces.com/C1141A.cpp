#include<bits/stdc++.h>

using namespace std;
typedef long long LL;

int main() {
    LL n, m;
    cin >> n >> m;
    int step = 0;
    if (m % n != 0) {
        step = -1;
    } else {
        LL k = m / n;
        while (k > 1 and (k % 2 == 0 or k % 3 == 0)) {
            if (k % 2 == 0)k /= 2;
            else if (k % 3 == 0)k /= 3;
            ++step;
        }
        if (k != 1)step = -1;
    }
    cout << step << endl;

    return 0;
}
