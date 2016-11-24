using namespace std;

int main() {
  for (int m; cin >> m;) {
    vector<int> v(1, 1);
    for (int i = 2, cs = 0; i <= m; i++) {
      for (int j = 0; j < v.size(); j++)
        cs += v[j] * i, v[j] = cs % 10, cs /= 10;
      for (; cs > 0; cs /= 10) v.push_back(cs % 10);
    }
    for (vector<int>::reverse_iterator it = v.rbegin(); it != v.rend(); ++it)
      cout << *it;
    cout << endl;
  }

  return 0;
}