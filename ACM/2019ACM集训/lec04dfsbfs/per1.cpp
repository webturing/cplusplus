#include<bits/stdc++.h>

using namespace std;
int main(){//n!
int a, b, c, d;
  for (int a = 1; a <= 4; a++)
    for (int b = 1; b <= 4; b++)
      for (int c = 1; c <= 4; c++)
        for (int d = 1; d <= 4; d++) {
          if (a != b && a != c && a != d && b != c && b != d && c != d)
            printf("%d %d %d %d\n", a, b, c, d);
        }

	return 0;
}
