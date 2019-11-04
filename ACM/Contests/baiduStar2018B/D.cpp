#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
typedef long long LL;

#define LOCAL

int main() {
#ifdef LOCAL
  ifstream cin("D.in");
  ofstream cout("D.out");
  LL start = clock();
#endif
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &i : v) cin >> i;
    sort(v.begin(), v.end());
    int left = v[0], right = v[n - 1];
    int result = -1;
    while (left < right) {
      int mid = (left + right) / 2;
      int add = 0, sub = 0;
      for (auto e : v) {
        if (e > mid) {
          add += (e - mid) / 2;
        } else {
          sub += mid - e;
        }
        if (add <= sub) {
          result = max(result, mid);
          left = mid + 1;
        } else {
          right = mid - 1;
        }
      }
    }
    cout << result << endl;
  }
#ifdef LOCAL
  LL end = clock();
  cerr << 1.0 * (end - start) / CLOCKS_PER_SEC << endl;
#endif
  return 0;
}
/**
1004 p1m2 題解

這題可以使用二分搜尋的技術來尋找最大值。在這個題解裡，我們用 min(A)\min(A)min(A)
來表示一個陣列 AAA 中元素的最小值，max(A)\max(A)max(A) 來表示最大值。當
0≤min(A)0 \le \min(A)0≤min(A) 且 max(A)−min(A)≤1\max(A) - \min(A) \le
1max(A)−min(A)≤1 時，我們稱陣列 AAA 為穩定的。我們只討論 N>1N > 1N>1 的狀況。
二分搜尋

給定一個初始陣列 AAA，可以證明本題的答案 VVV 一定存在。這個 VVV 滿足：

    min(A)≤V\min(A) \le Vmin(A)≤V。
    對於任意的整數 0≤v≤V0 \le v \le V0≤v≤V 都可以找到一個可由 AAA 到達的穩定陣列
A′A'A​′​​ 使得 min(A′)=v\min(A') = vmin(A​′​​)=v。
    對於任意的整數 V<vV < vV<v，不存在任何可由 AAA 到達的穩定陣列
A′′A''A​′′​​ 使得 min(A′′)=v\min(A'') =
vmin(A​′′​​)=v。

因此，我們可以透過這個性質來對答案二分搜！
判斷答案 vvv 有沒有辦法達成

對於原始陣列裡面的每個 >v>v>v 的元素 xix_ix​i​​，都可以貢獻
⌊(xi−v)/2⌋\lfloor(x_i - v) / 2\rfloor⌊(x​i​​−v)/2⌋
次的減法機會，而對於每一個 <v<v<v 的元素，都需要 v−xiv - x_iv−x​i​​
次的加法。只要需要的加法的次數比減法的機會少 (或相等)，那 vvv 就可以被達成。
但是還有沒有用完的減法次數怎麼辦呢

如果還有沒有用完的減法次數，我們會達到一個可能不穩定的
A′A'A​′​​，配合上面的第 1. 點，已知此 A′A'A​′​​ 會有一個至少為
min(A′)=v\min(A') = vmin(A​′​​)=v 的答案 V′V'V​′​​，再配合上面的第
2. 點，此 A′A'A​′​​ 一定可以達到答案為 vvv
的穩定的陣列。
證明答案 VVV 一定存在且 min(A)≤V\min(A) \le Vmin(A)≤V

如果原始陣列 AAA
不穩定的話，持續進行把最大的數減二，並且把最小的數加一的動作。這樣的操作不會讓最大值上升，也不會讓最小值下降，因此最後一定會收斂到一個至少為
min(A)\min(A)min(A) 的答案。
證明對於小於答案 VVV 的非負整數 vvv 都可以被達成

以下證明：對於一個穩定的陣列 AAA 並且 min(A)>0\min(A) >
0min(A)>0，一定可以達成一個穩定的陣列 A′A'A​′​​，並且
min(A′)=min(A)−1\min(A') = \min(A) -
1min(A​′​​)=min(A)−1。在這個證明中我們簡寫 min(A)\min(A)min(A) 為
mmm。

首先考慮對於固定的兩個元素，分別各加減一次，結果會是這兩個元素各自被減一。

    對於偶數的 NNN，我們可以把 AAA 的元素兩個一組，每個都減一，就可以達成目標。
    對於奇數的 NNN，AAA 中的元素兩兩一組相減後，至多會留下一個元素其值為
m+1m+1m+1，也至少會有一個元素其值為 m−1m-1m−1，這時把前者減二後者加一，就變為
m−1m - 1m−1 以及 mmm，也可以達成目標。

整體時間複雜度為 O(Nlogmax(X))O(N\log\max(X))O(Nlogmax(X))，其中的 XXX
為原始給定的陣列。*/