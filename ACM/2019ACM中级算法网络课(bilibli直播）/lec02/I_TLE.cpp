#include<bits/stdc++.h>

using namespace std;

bool is_prime(int n) {//O(sqrt(n)/2)
    if (n == 2)return true;
    if (n % 2 == 0)return false;//n是>2的偶数
    if (n == 1)return false;//patch
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0)//发现一个证据：i是n的一个非平凡因子
            return false;
    }
    return true;
}

int main() {
    int l = 2, r = 11;
    cin >> l >> r;
    int tot = 0;
    for (int i = l; i <= r; i++)
        if (is_prime(i))++tot;
    cout << tot << endl;
    return 0;
}