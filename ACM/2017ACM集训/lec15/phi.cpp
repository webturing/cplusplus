#include <stdio.h>

const int maxn = 1e3;
int phi[maxn];

int phi1(int n) //基本方法
{
    int rea = n;
    for (int i=2; i<=n; i++) {
        if (n % i == 0) {
            rea = rea - rea / i;
            do {
                n /= i;
            }while (n % i == 0);
        }
    }
    return rea;
}

int phi2(int n) //优化
{
    int rea = n;
    for (int i=2; i*i<=n; i++) {
        if (n % i == 0) {
            rea = rea - rea / i;
            do {
                n /= i;
            }while (n % i == 0);
        }
    }
    if (n > 1)
        rea = rea - rea / n;
    return rea;
}

int phi3() //打表
{
    for (int i=1; i<=maxn; i++) phi[i] = i;
    for (int i=2; i<=maxn; i+=2) phi[i] /= 2;
    for (int i=3; i<=maxn; i+=2)
    if (phi[i] == i) {
        for (int j=i; j<=maxn; j+=i) {
            phi[j] = phi[j] / i * (i - 1);
        }
    }
}

int main()
{
    return 0;
}
