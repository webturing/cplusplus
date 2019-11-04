//
// Created by jal on 18-9-3.
//

#include <bits/stdc++.h>

using namespace std;
int n, m;
int res;

void dfs(int m, int step) {
    if (n == m) {
        res = min(res, step);
    }
    if (step >= 20) {
        return;
    }
    {
        dfs(m + 1, step + 1);
    }
    {
        if (m % 2 == 0)
            dfs(m / 2, step + 1);
    }
}

int main() {
    while (cin >> n >> m) {
        res = 9999;
        dfs(m, 0);
        cout << res << endl;
    }
}
/*
 * 计算器
时间限制：C/C++语言 1000MS；其他语言 3000MS
内存限制：C/C++语言 65536KB；其他语言 589824KB
题目描述：
假设有这样一个计算器，该计算器只有两个按钮，按下第一个按钮能使显示数值减少1，按下第二个按钮能使显示数值乘以2，当前显示数值为N，那么至少要按多少次按钮才能使显示数值变成M？

输入
输入两个整数N和M，1≤N，M≤109。

输出
输出使显示数值变成M的最少按按钮次数。


样例输入
4 5
样例输出
3

 * */