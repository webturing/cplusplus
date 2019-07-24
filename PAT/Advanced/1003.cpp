#include <bits/stdc++.h>
using namespace std;
template <typename T = int>
T read() {
  T x;
  cin >> x;
  return x;
}
int ways = 0, best = 0;
int N(read()), M(read()), C1(read()), C2(read());
vector<int> V(N), T(N);
map<pair<int, int>, int> G;

void dfs(int from, int depth) {}

int main() {
  for (int i = 0; i < N; i++) V[i] = i;
  for (int i = 0; i < N; i++) cin >> T[i];
  for (int i = 0; i < M; i++) {
    int p, q, w;
    cin >> p >> q >> w;
    G[make_pair(p, q)] = G[make_pair(q, p)] = w;
  }
  dfs(C1, 0);
  cout << ways << " " << best << endl;
  return 0;
}
/**
Sample Input:
5 6 0 2
1 2 1 5 3
0 1 1
0 2 2
0 3 1
1 2 1
2 4 1
3 4 1
Sample Output:
2 4
*/