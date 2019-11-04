
#include <cmath>
#include <vector>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <algorithm>
#define MIN 999999
#define MAX_Point 501
#define MAX_Edge 251000

using namespace std;

int flag1 = 0;

int arr_list[MAX_Point][MAX_Point];
std::vector<int> b;

struct Edge {
  int point;
  double lowcost;
  int flag;
};
Edge edge[MAX_Edge];

double prim(int n) {
  int i, j, k = 1, flag;
  double min, sum2 = 0;
  j = 1;
  for (i = 1; i <= n; i++) {
    if (i != j) {
      edge[i].point = i;
      edge[i].lowcost = arr_list[j][i];
      edge[i].flag = 0;
    }
  }
  edge[j].lowcost = 0;
  edge[j].flag = 1;
  for (i = 2; i <= n; i++) {
    k = 1;
    min = MIN;
    flag = 0;
    for (j = 2; j <= n; j++) {
      if (edge[j].flag == 0 && edge[j].lowcost < min) {
        k = j;
        min = edge[j].lowcost;
        flag = 1;
      }
    }
    if (!flag) return -1;
    sum2 += min;
    edge[k].flag = 1;
    for (j = 2; j <= n; j++) {
      if (edge[j].flag == 0 && arr_list[k][j] < edge[j].lowcost) {
        edge[j].lowcost = arr_list[k][j];
        edge[j].point = k;
      }
    }
  }
  return sum2;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int v, e;
    cin >> v >> e;
    int x, y, z;
    for (int i = 1; i <= v; i++) {
      for (int j = 1; j <= v; j++) {
        if (i == j)
          arr_list[i][j] = 0;
        else
          arr_list[i][j] = MIN;
      }
    }

    for (int i = 0; i < e; i++) {
      cin >> x >> y >> z;
      arr_list[x][y] = z;
      arr_list[y][x] = z;
    }
    for (int i = 1; i <= v; i++) {
      int r;
      cin >> r;
      b.push_back(r);
    }
    sort(b.begin(), b.end());
    int s = prim(v) + b[0];
    cout << s << endl;
  }
}
