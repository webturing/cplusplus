#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
typedef long long LL;

#define LOCAL

int main() {
#ifdef LOCAL
  ifstream cin("G.in");
  ofstream cout("G.out");
  LL start = clock();
#endif
  ios::sync_with_stdio(false);
  int a[] = {1, 2, 3};
  cout << a[0] << a[1] << endl;
  int mn = min_element(a, a + 3) - a;
  swap(a[0], a[mn]);
  cout << a[0] << a[1] << endl;
#ifdef LOCAL
  LL end = clock();
  cerr << 1.0 * (end - start) / CLOCKS_PER_SEC << endl;
#endif
  return 0;
}

/**
1006 rect 題解

這題是一個求最小值的問題，使用貪心法來解決。以下給出一個思路：

最短的線段一定是這個點跟矩形四個邊平行/垂直的四個線段中最短的那一條。
貪心的把每個點都選擇最短的線段，因為題目保證 xxx 跟 yyy
座標彼此不重複，所以這些線段彼此不會交叉。
因此答案即為 ∑i=1Nmin(xi,MX−xi,yi,MY−yi)\sum_{i=1}^N \min(x_i, MX-x_i, y_i,
MY-y_i)∑​i=1​N​​min(x​i​​,MX−x​i​​,y​i​​,MY−y​i​​)。

題目中輸出的部分寫明答案為整數，可以做為一個小提示。

整體的時間複雜度為 O(N)O(N)O(N)。*/