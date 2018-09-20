#include <bits/stdc++.h>
using namespace std;
template <typename T> void print(list<T> L) {
  bool first = true;
  for (auto p : L) {
    if (first)
      first = false;
    else {
      cout << " ";
    }
    cout << p;
  }
  cout << endl;
}
int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  list<int> L;
  while (n--) {
    string cmd;
    int x;
    cin >> cmd;
    if (cmd == "insert") {
      cin >> x;
      L.push_front(x);
    } else if (cmd == "delete") {
      cin >> x;
      auto it = find(L.begin(), L.end(), x);
      if (it != L.end())
        L.erase(it);
    } else if (cmd == "deleteFirst") {
      if (L.size())
        L.pop_front();
    } else if (cmd == "deleteLast") {
      if (L.size())
        L.pop_back();
    }
  }
  print(L);
  return 0;
}
