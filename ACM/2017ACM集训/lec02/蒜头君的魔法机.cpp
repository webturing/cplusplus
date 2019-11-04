/**
蒜头君有一台神奇的魔法机，它能将输入的序列进行一系列复杂的变换，输出原序列的另一种排列方式。蒜头君十分好奇魔法机的工作原理，终于有一天他尝试着把魔法机拆开研究了。
通过一系列复杂的演算，蒜头君终于发现了魔法机的工作原理：其实魔法机就是一个栈，根据栈先进后出的性质，每次一个数字进栈或将栈顶元素弹出，由此可以产生不同的出栈序列，出栈序列就是原序列的另一种排列啦。
在研究完原理后，蒜头君凭借记忆很快就把魔法机组装好了。现在蒜头君想测试下魔法机在组装完成后是否出现问题。
首先他将 11 到 NN 这 NN
个数字依次输入魔法机里，然后随机写下一组序列a，现在他想知道能否通过魔法机得到序列a，聪明的你能帮蒜头君算一算吗？
输入格式
输入有两行，第一行是一个正整数 N (1 \leq N \leq
100)N(1≤N≤100)，表示输入魔法机序列的长度，第二行是序列a，共有 NN
个整数，表示要得到的目标序列。
序列为 11 到 NN 的排列，即序列a长度为 NN，保证序列中的整数都不相同，且整数在区间
[11, NN] 内。
输出格式
输出一行，如果能通过魔法机得到序列a，则输出YES，否则输出NO。
样例输入
5
2 1 5 4 3
样例输出
YES
*/
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (auto &p : v) cin >> p;
  stack<int> s;
  int cnt = 1, flag = 1;
  for (auto p : v) {
    if (s.empty())
      for (; cnt <= p; ++cnt) s.push(cnt);
    if (s.top() == p) {
      s.pop();
    } else if (s.top() > p) {
      flag = 0;
      break;
    }
  }
  if (flag)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}