#include <bits/stdc++.h>

using namespace std;
char s[1000000 + 1];
int N, x, y, busy, idle;

int main() {
    int left = 0x3fffff, right = 0;
    for (cin >> N; N-- && cin >> x >> y;) {
        for (int k = x; k < y; k++) {
            s[k] = 1;
        }
        left = min(left, x);
        right = max(right, y);
    }
    int gbusy = 0, gidle = 0;
    int tbusy = 0, tidle = 0;
    for (int i = left; i < right;) {
        tbusy = 0, tidle = 0;
        while (i < right && s[i] == 1) ++tbusy, ++i;
        while (i < right && s[i] == 0) ++tidle, ++i;
        gidle = max(tidle, gidle);
        gbusy = max(tbusy, gbusy);
    }
    cout << gbusy << " " << gidle << endl;
    return EXIT_SUCCESS;
}