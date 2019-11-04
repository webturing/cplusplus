
#include <bits/stdc++.h>

using namespace std;
//按照1,2,...,n-1,n的顺序入栈，问可以得到多少种出栈序列
typedef unsigned long long LL;

LL h(int n) {
    if (n <= 1)
        return 1;
    return
            h(n - 1) * (4 * n - 2) / (n + 1);
}

int main() {
    int n;
    cin >> n;
    cout << h(n) << endl;
    return 0;
}