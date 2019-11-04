#include<bits/stdc++.h>

using namespace std;
typedef long long LL;

int main() {
    freopen("A.in", "r", stdin);
    LL a, b, c;
    char op;
    int tot = 0;
    while (~scanf("%lld%c%lld=%lld", &a, &op, &b, &c)) {
        if (op == '+') {
            if (a + b == c)++tot;
        } else if (op == '-') {
            if (a - b == c)++tot;
        }
    }
    cout << "RIGHT:" << tot << endl;

    return 0;
}