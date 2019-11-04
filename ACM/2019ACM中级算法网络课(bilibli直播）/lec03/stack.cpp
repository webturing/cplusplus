#include<bits/stdc++.h>

using namespace std;
int Stack[1000], top = -1;

//括号配对 进制转化 递归化简 后缀式计算
int main() {
    stack<int> S;//FILO
    for (int i = 0; i < 10; i++)S.push(i);
    while (not S.empty()) {
        cout << S.top() << endl;
        S.pop();
    }
    return 0;
}