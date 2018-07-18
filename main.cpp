
#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long LL;

LL h(int n) {
    if (n <= 1)
        return 1;
    return h(n - 1) * (4 * n - 2) / (n + 1);
}

LL factorial(int n) {
    return n <= 1 ? 1LL : factorial(n - 1) * n;
}

int main() {
    int n;
    cin >> n;
    cout << h(n) * factorial(n) * factorial(n) << endl;
    return 0;
}