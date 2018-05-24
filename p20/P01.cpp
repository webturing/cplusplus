#include <bits/stdc++.h>
using namespace std;
// 1.	随机产生一些1—100之间的整数，直到产生的数为50为止。
// 提示：使用<stdlib.h>中rand()以及<time.h>中srand(time(NULL))实现随机化

void solve(int start, int end, int target) {
  vector<int> v(end - start + 1, 0);
  for (auto i = 0u; i < v.size(); i++) v[i] = start + i;
  vector<int> w;
  for (;;) {
    auto curIdx = rand() % v.size();
    w.push_back(v[curIdx]);
    if (v[curIdx] == target) break;
  }
  copy(w.begin(), w.end(), ostream_iterator<int>(cout, " "));
}

int main(int argc, char const *argv[]) {
  srand(time(NULL));
  solve(1, 100, 50);
  return 0;
}