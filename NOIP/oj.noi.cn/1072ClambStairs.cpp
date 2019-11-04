#include<bits/stdc++.h>

using namespace std;

long long f(int n) {
    if (n == 1)
        return 1LL;
    if (n == 2)return 2LL;
    return f(n - 1) + f(n - 2);
}


int main(void) {
    for (int n; cin >> n;) {
        cout << f(n) << endl;
    }
    return 0;
}