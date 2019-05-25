#include<bits/stdc++.h>

using namespace std;
typedef long long LL;

int main() {
    int n, m;
    cin >> n >> m;
    int tot = m * n;
    int k = 0;
    while (tot > 0) {
        tot -= m + n - 1;
        m--, n--;
        k++;
    }
    if (k & 1)cout << "Akshat" << endl;
    else cout << "Malvika" << endl;

    return 0;
}
