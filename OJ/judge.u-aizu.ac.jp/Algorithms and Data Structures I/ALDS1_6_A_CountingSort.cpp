#include <bits/stdc++.h>
using namespace std;
int a[20000000];
int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  sort(a, a + n);
  cout << a[0];
  for (int i = 1; i < n; i++)
    cout << " " << a[i];
  cout << endl;
  return 0;
}
