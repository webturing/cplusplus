#include <bits/stdc++.h>
using namespace std;
#define LOWBIT(x) ((x) & ((x) ^ ((x) - 1)))
#define CLR(x, k) memset((x), (k), sizeof(x))
#define CPY(t, s) memcpy((t), (s), sizeof(s))
#define SC(t, s) static_cast<t>(s)
#define LEN(s) static_cast<int>(strlen((s)))
#define SZ(s) static_cast<int>((s).size())
typedef double LF;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef pair<double, double> PDD;
typedef vector<int> VI;
typedef vector<char> VC;
typedef vector<double> VF;
typedef vector<string> VS;
template <typename T> T sqa(const T &x) { return x * x; }
template <typename T> T ll(const T &x) { return x << 1; }
template <typename T> T rr(const T &x) { return x << 1 | 1; }
template <typename T> T gcd(T a, T b) {
  if (!a || !b) {
    return max(a, b);
  }
  T t;
  while (t = a % b) {
    a = b;
    b = t;
  }
  return b;
};
const int INF_INT = 0x3f3f3f3f;
const LL INF_LL = 0x7fffffffffffffffLL; // 15f
const double oo = 10e9;
const double eps = 10e-7;
const double PI = acos(-1.0);
#define ONLINE_JUDGE
const int MAXV = 10004;
const int MAXN = 200004;
int test, n;
struct Node {
  Node *next[2];
  bool end_sign;
} trie[MAXN], *const root = trie;
int ncnt;
VI G[MAXV];
bool hs[MAXV];
void initTrie() {
  ncnt = 1;
  for (int i = 0; i < 2; ++i) {
    root->next[i] = NULL;
  }
  root->end_sign = false;
  return;
}
Node *createNode() {
  for (int i = 0; i < 2; ++i) {
    trie[ncnt].next[i] = NULL;
  }
  trie[ncnt].end_sign = false;
  return &trie[ncnt++];
}
bool insertTrie(const string &str) {
  Node *ptr = root;
  int len = SC(int, str.length());
  for (int i = 0; i < len; ++i) {
    int t = str[i] - '0';
    if (NULL == ptr->next[t]) {
      ptr->next[t] = createNode();
    }
    ptr = ptr->next[t];
  }
  if (ptr->end_sign) {
    return false;
  }
  ptr->end_sign = true;
  return true;
}
void addEdge(int u, int v) {
  G[u].push_back(v);
  return;
}
void search(int u, int state) {
  hs[u] = true;
  for (VI::iterator it = G[u].begin(); it != G[u].end(); ++it) {
    int v = *it;
    if ((1 << v) & state) {
      if (!hs[v]) {
        search(v, state);
      }
    }
  }
  return;
}
bool connectedJudge(int state) {
  CLR(hs, false);
  for (int i = 0; i < n; ++i) {
    if ((1 << i) & state) {
      search(i, state);
      break;
    }
  }
  for (int i = 0; i < n; ++i) {
    if ((1 << i) & state) {
      if (!hs[i]) {
        return false;
      }
    }
  }
  return true;
}
string dfs(int u, string str, int state) {
  VS vs;
  hs[u] = true;
  for (VI::iterator it = G[u].begin(); it != G[u].end(); ++it) {
    int v = *it;
    if ((1 << v) & state) {
      if (!hs[v]) {
        vs.push_back(dfs(v, "0", state) + "1");
      }
    }
  }
  sort(vs.begin(), vs.end());
  for (VS::iterator it = vs.begin(); it != vs.end(); ++it) {
    str += *it;
  }
  return str;
}
bool insertJudge(int state) {
  bool sign = false;
  for (int u = 0; u < n; ++u) {
    if ((1 << u) & state) {
      CLR(hs, false);
      if (insertTrie(dfs(u, "", state))) {
        sign = true;
      }
    }
  }
  return sign;
}
void ace() {
  int cas = 1;
  int u, v;
  int res;
  for (scanf("%d", &test); test--; ++cas) {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      G[i].clear();
    }
    initTrie();
    for (int i = 0; i < n - 1; ++i) {
      scanf("%d %d", &u, &v);
      addEdge(u, v);
      addEdge(v, u);
    }
    res = 0;
    for (int state = 1; state < (1 << n); ++state) {
      if (!connectedJudge(state)) {
        continue;
      }
      if (insertJudge(state)) {
        ++res;
      }
    }
    printf("Case #%d: %d\n", cas, res);
  }
  return;
}
int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  ace();
  return 0;
}
