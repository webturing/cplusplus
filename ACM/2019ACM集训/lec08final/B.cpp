#include<bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f3f;
int num[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int day[15] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int y, m, d;
int t, s;

bool isr(int y) {
    if (y % 400 == 0 || (y % 100 != 0 && y % 4 == 0))
        return true;
    return false;
}

int Get(int a, int b, int c) {
    if (b < 10)
        b *= 10;
    if (c < 10)
        c *= 10;
    int res = 0;
    while (a) {
        res += num[a % 10];
        a /= 10;
    }
    while (b) {
        res += num[b % 10];
        b /= 10;
    }
    while (c) {
        res += num[c % 10];
        c /= 10;
    }
    return res;
}

int Solve() {
    int res = 0;
    int flag = 0;
    while (y <= 2999 && m <= 12 && d <= 31) {
        if (Get(y, m, d) == s) {
            flag = 1;
            break;
        }
        d++;
        if (isr(y) && m == 2) {
            if (d > 29) {
                d = 1;
                m++;
            }
        } else {
            if (d > day[m]) {
                d = 1;
                m++;
            }
            if (m > 12) {
                m = 1;
                y++;
            }
        }
        res++;
    }
    if (flag == 1)
        return res;
    else
        return -1;
}

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%4d%2d%2d", &y, &m, &d);
        //cout << Get(y, m, d) << endl;
        scanf("%d", &s);
        printf("%d\n", Solve());
    }

    return 0;
}