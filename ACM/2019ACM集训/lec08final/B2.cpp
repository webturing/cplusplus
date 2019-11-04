
#include<bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> Point;

#define rep(i, a, b) for(int i=a;i<=b;i++)
#define per(i, a, b) for(int i=a;i>=b;i--)

inline int read_int() {
    int x;
    scanf("%d", &x);
    return x;
}

int num[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int day[2][13] = {
        {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
        {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

inline bool leap(int y) { return y % 4 == 0 && y % 100 != 0 || y % 400 == 0; }

inline bool check(int y, int m, int d) {
    if (m < 1 || m > 12)return false;
    if (d < 0 || d > day[leap(y)][m])return false;
    return true;
}

inline int YMD(int y, int m, int d) { return y * 10000 + m * 100 + d; }

inline int count(int n) {
    return n < 10 ? num[n] : num[n % 10] + count(n / 10);
}

inline int solve(int Y, int M, int D, int sticks) {
    int dif = 0;
    rep(y, Y, 2999)
        rep(m, 1, 12)
            rep(d, 1, 31) {
                if (!check(y, m, d))continue;
                if (YMD(y, m, d) < YMD(Y, M, D))continue;
                if (count(YMD(y, m, d)) == sticks) {
                    return dif;
                }
                ++dif;
            }
    return -1;
}

int main() {
    int T = read_int();
    while (T--) {
        int ymd = read_int();
        int Y = ymd / 10000, M = ymd / 100 % 100, D = ymd % 100;
        int sticks = read_int();
        assert(Y <= 2999 && M <= 12 && D <= 31);
        cout << solve(Y, M, D, sticks) << endl;
    }

    return 0;
}