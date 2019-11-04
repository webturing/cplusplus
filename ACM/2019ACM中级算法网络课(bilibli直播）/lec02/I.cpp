#include<bits/stdc++.h>

using namespace std;

vector<int> primes = {2, 3,};

void fill(int m) {
    for (int k = primes.back() + 2; k <= m; k += 2) {
        bool flag = true;
        for (int p:primes) {
            if (p * p > k)break;
            if (k % p == 0) {
                flag = false;
                break;
            }
        }
        if (flag)primes.push_back(k);
    }
}

int main() {
    int l = 2100000000, r = 2101000000;
    int m = sqrt(r) + 1;
    fill(m);//把 1~sqrt(r)素数都放在数组primes里
    if (l < 2)l = 2;//小技巧
    bool B[r - l + 1];// x+L 是合数 则把 B[x]=false 区间筛法
    fill(B, B + r - l + 1, true);
    for (auto p:primes) {
        for (int x = (l + p - 1) / p * p; x <= r; x += p) {
            if (x % p == 0 and x > p)//p是x的非平凡因子
            {
                B[x - l] = false;//映射
            }
        }
    }
    int tot = 0;
    for (int x = l; x <= r; x++)
        if (B[x - l])++tot;
    cout << tot << endl;
    return 0;
}