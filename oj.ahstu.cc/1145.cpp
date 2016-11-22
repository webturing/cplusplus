#include <cstdio>
#include <string>
using namespace std;
int main(int argc, char const *argv[]) {
  // freopen("data.in", "r", stdin);
  char c;
  int f[26] = {0};
  while ((c = getchar()) != -1 && c != '#')
    if (islower(c)) ++f[c - 'a'];
  for (int i = 0; i < 26; i++) printf("%c %d\n", 'a' + i, f[i]);

  return 0;
}