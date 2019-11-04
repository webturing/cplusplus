#include<bits/stdc++.h>

using namespace std;
typedef long long LL;

int main() {
    ifstream cin("A.in");//代码洁癖
    LL a, b, c;
    char op, eq;
    int tot = 0;
    while (cin >> a >> op >> b >> eq >> c) {//ok
        if (op == '+') {
            if (a + b == c)++tot;
        } else if (op == '-') {
            if (a - b == c)++tot;
        }
    }
    cout << "RIGHT:" << tot << endl;

    return 0;
}