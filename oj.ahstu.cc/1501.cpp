#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 32676;
vector<bool> prime(MAXN, true);
void fill() {
  prime[0] = prime[1] = false;
  for (int i = 2; i * i <= MAXN; i++)
    if (prime[i])
      for (int j = i * i; j < MAXN; j += i) prime[j] = false;
}
int main() {
  ifstream cin("d:\\data\\1090\\sample.in");
  fill();
  for (int n; cin >> n;) {
    int count = 0;
    for (int p = 3; p <= n / 2; p += 2)
      if (prime[p] && prime[n - p]) ++count;
    cout << count << endl;
  }
  return 0;
}