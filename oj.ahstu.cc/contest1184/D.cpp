#include <cstdio>
inline bool prime(int n) {
  if (n == 2) return true;
  if (n < 2 || n % 2 == 0) return false;
  for (int c = 3; c * c <= n; c += 2)
    if (n % c == 0) return false;
  return true;
}
int main() {
  for (int n = 100; n <= 200; n++)
    if (prime(n)) printf("%d\n", n);
  return 0;
}