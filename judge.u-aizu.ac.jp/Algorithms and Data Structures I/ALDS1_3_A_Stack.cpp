#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
  stack<int> S;
  for (string s; cin >> s;) {
    if (s == "+" || s == "-" || s == "*" || s == "/") {
      int b = S.top();
      S.pop();
      int a = S.top();
      S.pop();
      int ans;
      switch (s[0]) {
      case '+':
        ans = a + b;
        break;
      case '-':
        ans = a - b;
        break;
      case '*':
        ans = a * b;
        break;
      case '/':
        ans = a / b;
        break;
      }
      S.push(ans);
    } else {
      istringstream iss(s);
      int c;
      iss >> c;
      S.push(c);
    }
  }
  cout << S.top() << endl;
  return 0;
}
