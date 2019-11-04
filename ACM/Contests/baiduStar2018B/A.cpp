#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
typedef long long LL;

#define LOCAL
int main() {
#ifdef LOCAL
  ifstream cin("A.in");
  // ofstream cout("A.out");
  LL start = clock();
#endif
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, m, k;
    cin >> n >> m >> k;
    int C = n - m;
    vector<int> d(n, 0);
    while (m--) {
      int x, y;
      cin >> x >> y;
      d[x]++, d[y]++;
    }
    int mx = *max_element(d.begin(), d.end());
    if (k == 0)
      cout << C + mx - 1 << endl;
    else
      cout << min(n - 1, k + n - m + mx - 1) << endl;
  }
#ifdef LOCAL
  LL end = clock();
  cerr << fixed << setprecision(2) << 1.0 * (end - start) / CLOCKS_PER_SEC
       << " second(s)." << endl;
#endif
  return 0;
}
/**
1001 degree 題解

沒有圈 (cycle) 的簡單圖 (undirected simple graph)，等價於由多顆樹 (tree)
組成的森林 (forest)。這裡用 VVV 代表點的數量，EEE 代表邊的數量 (取代題目中的 NNN
以及 MMM)，CCC 代表森林中樹的數量。
K=0K = 0K=0 的 case

不妨先化簡一下題目，在 K=0K = 0K=0 的狀態下要達到 degree
最大化，可以貪心的把森林中所有樹各自接一條邊到已知 degree 最大的點上。答案是 C +
已知最大的 degree - 1。
K≥0K \ge 0K≥0 的 case

回到原題，題目中規定一定要在添加邊之前把拔邊的操作作完，但是實際上任意調換添加邊以及拔掉邊的順序不會影響最後的結果。
考慮貪心添加完邊的樹，可以多拔掉一條邊再重新接上的效果等價於把答案
+1+1+1，要注意的是如果答案已經到達最大值 V−1V-1V−1
的話，那拔邊再接上並不會影響答案。 所以答案為min(V - 1, K + C + 已知最大的
degree - 1)。
樹的數量 C = V - E

由於給定的圖是面數 (face) 為 111 的平面圖 (planar graph)，所以根據平面圖的公式
V−E+F=C+1V - E + F = C + 1V−E+F=C+1 整理後 C=V−EC =
V-EC=V−E。另外一個證明：圖中每個 connected component
都是由樹所組成，也就是說每個 component 中邊數會是點數 - 1，直接可推得 C=V−EC = V
- EC=V−E。

有了 C=V−EC = V - EC=V−E 後，答案就變成 min(V - 1, K + V - E + 已知最大的 degree
- 1)。也就是，我們其實不用真正的寫出計算 connected component 的算法，只要統計
degree 最大的點有多大就可以計算出答案了。

整體時間複雜度為 O(V)O(V)O(V)，注意這題中有 O(V)=O(E)O(V) = O(E)O(V)=O(E)。
*/