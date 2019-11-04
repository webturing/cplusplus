#include <bits/stdc++.h>
using namespace std;
using LL = long long;
inline LL check(LL k) {
  if (k == 1) return 1;  // bug
  LL L = 1;
  while (L < k) L *= 10;
  for (int n = 1; n < 10; n++) {
    LL s = n * k * k;
    if (s % L == k) {
      return n;
    }
  }
  return 0;
}
int main() {
  LL M, N, K;
  for (cin >> M; M-- and cin >> K;) {
    N = check(K);
    if (N > 0) {
      cout << N << " " << 1LL * N * K * K << endl;
    } else {
      cout << "No" << endl;
    }
  }

  return 0;
}