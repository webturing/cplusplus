
#include <bits/stdc++.h>

using namespace std;

const int len = 1e4;
const int maxn = 100;
int ans[maxn];

void multi() {
    int i, last = 0;
    for (i = 1; i <= ans[0]; i++) {
        ans[i] = ans[i] * 2 + last;
        last = ans[i] / len, ans[i] %= len;
    }
    if (last) ans[++ans[0]] = last;
}

int main() {
    int n, i;
    scanf("%d", &n);
    ans[0] = 1, ans[1] = 2;
    for (i = 1; i <= n; i++) multi();
    ans[1] -= 2;
    printf("%d", ans[ans[0]]);
    for (i = ans[0] - 1; i >= 1; i--) printf("%04d", ans[i]);
    return 0;
}
/**
7、Hanoi 双塔问题(Noip2007)
【问题描述】
给定 A、B、C 三根足够长的细柱，在 A 柱上放有 2n 个中间有孔的圆盘，共有 n
个不同的尺寸，每个尺
寸都有两个相同的圆盘，注意这两个圆盘是不加区分的（下图为 n=3
的情形）。现要将这些圆盘移到 C 柱上，
在移动过程中可放在 B 柱上暂存。要求：
（1）每次只能移动一个圆盘；
（2）A、B、C 三根细柱上的圆盘都要保持上小下大的顺序；
任务：设An为 2n个圆盘完成上述任务所需的最少移动次数，对于输入的n，输出An。
*/