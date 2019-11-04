#include<bits/stdc++.h>

using namespace std;
long long n, m, p;
long long a[711][711];
int v[711][711];
long long gcd[711][711];
long long tmp[30];

void f(long long x, long long y) {
    long long xx = x, yy = y;
    int c = 0;
    long long tt;
    while (y > 0) {
        c++;
        tt = x % y;
        x = y;
        y = tt;
    }
    a[xx][yy] = c * x * x;
    v[xx][yy] = c;
    gcd[xx][yy] = x;
}

void init(void) {
    for (int j = 1; j <= 670; j++) {
        for (int i = 1; i <= 670; i++) {
            //  cout << i << " " << j << endl;
            f(i, j);
        }
    }
}

int main() {
    init();
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%lld%lld%lld", &n, &m, &p);
        long long ans = 0;
        for (long long j = 1; j <= m; j++) {
            for (long long i = 1; i <= j; i++) {
                long long tot = 0;
                int c = v[i][j];
                long long g = gcd[i][j];///i,j的gcd
                long long tt0 = n / j;
                if (i <= (n % j)) tt0++; ///计算这个c有多少个
                long long tt = tt0 / c; ///有多少组
                long long sum = 0; ///循环节基数的和
                for (int k = 0; k < c; k++) {
                    tmp[k] = (i + j * k) * j / a[i][j];
                    tmp[k] %= p;
                    sum += tmp[k];
                    sum %= p;
                }
                tot += sum * tt % p;
                tot %= p;
                // long long ss=a[c*j][j]%p;
                long long ss = j * j / g / g; ///后者的
                tot += tt * (tt - 1) / 2 % p * c % p * ss % p;
                tot %= p;
                for (int k = 0; k < tt0 - tt * c; k++) {
                    tot += tmp[k];
                    tot %= p;
                    tot += tt * ss % p;
                    tot %= p;
                }
                /*            cout << "i=" << i << " j=" << j << " c=" << c
                            << " tt0=" << tt0 << " tt=" << tt <<
                            " ss=" << ss <<" sum=" << sum <<" tot=" <<tot <<endl;
                            for(int k=0;k<c;k++)
                                cout << tmp[k] << " ";
                            cout << endl;*/
                ans += tot;
                ans %= p;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}