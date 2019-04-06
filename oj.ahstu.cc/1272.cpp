#include <bits/stdc++.h>

using namespace std;

inline int reverse(int n) {
    auto ans = 0;
    while (n) {
        ans = ans * 10 + (n % 10);
        n /= 10;
    }
    return ans;
}

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    cout << reverse(n) << endl;
    return 0;
}