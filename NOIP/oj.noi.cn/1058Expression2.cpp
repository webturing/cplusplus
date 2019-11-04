#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    string expression;
    getline(cin, expression);
    expression.replace('+', ' ');
    istringstream iss(expression);
    vector<int> nums((istream_iterator<int>(iss)), istream_iterator<int>());
    cout << accumulate(nums.begin(), nums.end(), 0) << endl;

    return 0;
}
/**
 * 题目描述
计算仅含有加法计算的表达式的值。该表达式长度不超过250，中间没有空格与括号，并且计算结果在整数范围内。

输入
输入表达式。

输出
输出表达式的值。

样例输入
12+23+21

样例输出
56
*/