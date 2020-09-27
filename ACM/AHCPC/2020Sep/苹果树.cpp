#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;
const int MAX = 200000 + 5;
struct each {
    double x, y;
} a[MAX];
double ans;
int n, top = 2, st[MAX];

bool com(each x, each y) {
    return x.y == y.y ? x.x < y.x : x.y < y.y;
}

bool check(int k, int x, int y) {
    return (a[k].y - a[x].y) * (a[x].x - a[y].x) > (a[x].y - a[y].y) * (a[k].x - a[x].x);
}

double dis(each x, each y) {
    return sqrt((x.x - y.x) * (x.x - y.x) + (x.y - y.y) * (x.y - y.y));
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) { scanf("%lf%lf", &a[i].x, &a[i].y); }
    sort(a + 1, a + n + 1, com), st[1] = 1, st[2] = 2;
    for (int i = 3; i <= n; i++) {
        while (top > 1 && !check(i, st[top], st[top - 1])) { --top; }
        st[++top] = i;
    }
    for (int i = 1; i < top; i++) { ans += dis(a[st[i]], a[st[i + 1]]); }
    top = 2, memset(st, 0, sizeof(st)), st[1] = 1, st[2] = 2;
    for (int i = 3; i <= n; i++) {
        while (top > 1 && check(i, st[top], st[top - 1])) { --top; }
        st[++top] = i;
    }
    for (int i = 1; i < top; i++) { ans += dis(a[st[i]], a[st[i + 1]]); }
    printf("%.5f\n", ans);
    return 0;
}
/**
 * 题目名称：苹果树

题目描述
在一望无际的麦田里有一些天然生长的苹果树，alice想要把这些苹果树木用篱笆全部围起来。准确的描述是对于任何一颗苹果树，它都不在篱笆形成的多边形的外部。现在问你，最少需要多少米长的篱笆，输出一个保留5位小数的浮点数。
程序输入说明
首先是一个整数n(0<n<200000)，表示苹果树的数量。 接下来是n行，每行2个整数x，y(0<x<1e9,0<y<1e9)
程序输出说明
一个保留5位小数的浮点数，表示最少需要多少米的篱笆
程序输入样例
4
0 0
0 1
1 1
1 0
程序输出样例
4.00000
*/