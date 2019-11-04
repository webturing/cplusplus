#include <bits/stdc++.h>
using namespace std;
struct Node {
  string address;
  int data;
  string next;
};

int main() {
  ifstream cin("input.txt");
  string start;
  cin >> start;
  int n, k;
  cin >> n >> k;
  vector<Node> L(n);
  for (int i = 0; i < n; i++) cin >> L[i].address >> L[i].data >> L[i].next;

  for (int k = 0; k < n; k++) {
    int j = k;
    for (; j < n; j++) {
      if (L[j].address == start) {
        break;
      }
    }
    if (j < n and j != k) {
      swap(L[j], L[k]);
      start = L[k].next;
    }
  }

  for (int j = 0; j + k < n; j += k) {
    reverse(L.begin() + j, L.begin() + j + k);
  }
  for (int i = 0; i < n / k * k; i++)
    L[i].next = i + 1 == n ? "-1" : L[(i + 1)].address;
  for (auto e : L) {
    cout << e.address << " " << e.data << " " << e.next << endl;
  }
  return 0;
}