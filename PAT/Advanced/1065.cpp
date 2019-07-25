#include <bits/stdc++.h>

using namespace std;

inline __int128 read() {
    __int128 x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}

int main() {
    int k;
    scanf("%d", &k);
    for (int i = 1; i <= k; i++) {
        cout << "Case #" << i << ": ";
        __int128 A = read(), B = read(), C = read();

        if (A + B > C)
            cout << "true";
        else
            cout << "false";
        cout << endl;
    }
    return 0;
}
