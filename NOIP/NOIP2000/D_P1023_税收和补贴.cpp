#include <bits/stdc++.h>

using namespace std;

inline int read() {
    char s;
    int k = 0, base = 1;
    while ((s = getchar()) != '-' && s != EOF && !(s >= '0' && s <= '9'));
    if (s == EOF) exit(0);
    if (s == '-') base = -1, s = getchar();
    while (s >= '0' && s <= '9') {
        k = k * 10 + (s - '0');
        s = getchar();
    }
    return k * base;
}

void write(int x) {
    if (x < 0) {
        putchar('-');
        write(-x);
    } else {
        if (x / 10) write(x / 10);
        putchar(x % 10 + '0');
    }
}

int a[12000], b[12000];
int lx, ly, rx, ry, p, n, py;
int X;
double Min, Max;

int main() {
    p = read();
    n = 1;
    a[1] = read();
    b[1] = read();
    while (true)  //读入
    {
        rx = read();
        ry = read();
        if (rx == -1 && ry == -1) break;
        lx = a[n];
        ly = b[n];
        for (int i = lx + 1; i <= rx; i++)  //全部拆开
        {
            n++;
            a[n] = a[n - 1] + 1;
            b[n] = b[n - 1] + (ry - ly) / (rx - lx);
        }
    }
    X = read();
    if (p >= a[n])  //如果p比最大的要大，就要往后加
    {
        lx = a[n];
        ly = b[n];
        for (int i = lx + 1; i <= p + 1; i++) {
            n++;
            a[n] = a[n - 1] + 1;
            b[n] = b[n - 1] - X;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (a[i] == p) {
            py = b[i];
            break;
        }
    }
    Min = -233333333.0;
    Max = 23333333.0;
    for (int i = 1; i <= n; i++) {  //解不等式，最后范围：Min~Max
        if (py - b[i] > 0) {
            Min = max(Min, (double) ((double) (a[i] - a[1]) * b[i] -
                                     (double) (p - a[1]) * py) /
                           (double) (py - b[i]));
        } else {
            Max = min(Max, (double) ((double) (a[i] - a[1]) * b[i] -
                                     (double) (p - a[1]) * py) /
                           (double) (py - b[i]));
        }
    }
    if (Min > Max)
        printf("NO SOLUTION\n");
    else  //事实证明没有NO的点
    if (Min > 0)
        printf("%.0lf", ceil(Min));
    else  //使绝对值小嘛，向上取整（想一想，为什么）
    if (Max < 0)
        printf("%.0lf", floor(Max));
    else
        printf("0");
    return 0;
}