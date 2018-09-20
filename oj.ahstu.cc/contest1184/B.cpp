#include <cstdio>
#include <algorithm>

int main() {
  std::vector<int> v(10, 0);
  for (auto &&e : v) scanf("%d", &e);
  printf("%d\n", *std::max_element(v.begin(), v.end()));
  return 0;
}