
#include <bits/stdc++.h>
using namespace std;
inline bool left(int p, int q) { return p + 1 == q || p == 5 && q == 0; }
inline bool right(int p, int q) { return left(q, p); }
inline bool near(int p, int q) { return left(p, q) || right(p, q); }
int main(int argc, char const *argv[]) {
  vector<int> v{1, 2, 3, 4, };
  int zhao = 0;
  do {
    int qian = v[0], sun = v[1], li = v[2], zhou = v[3];
    vector<bool> b{near(zhao, qian), left(qian, sun) || left(qian, li),
                   left(sun, qian),  near(sun, li)};
    if (count(b.begin(), b.end(), false) == 4) {
      cout << zhao << qian << sun << li << zhou << endl;
      break;
    }
  } while (next_permutation(v.begin(), v.end()));
  return 0;
}

/**
6.
赵、钱、孙、李、周五人围着一张圆桌吃饭。饭后，周回忆说：“吃饭时，赵坐在钱旁边，钱的左边是if(count(b.begin(),b.end(),false)==b.size())
在孙左边，我挨着孙坐”。结果他们一句也没有说对。请问，他们在怎样坐的？
*/