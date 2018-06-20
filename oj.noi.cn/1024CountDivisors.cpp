#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    unsigned n;
    cin >> n;
    int tot = 0, t = 1, m = sqrt(n);
    for (; t <= m; t++)//O(sqrt(n))
        if (n % t == 0)
            tot += 2;
    if (m * m == n)
        --tot;
    cout << tot << endl;

    return 0;
}
