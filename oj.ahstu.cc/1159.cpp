using namespace std;

int main(int argc, char const *argv[]) {
  for (int n; cin >> n;) {
    vector<float> s(n, 0);
    for (unsigned i = 0; i < n; i++) cin >> s[i];
    sort(s.begin(), s.end());
    float avg = 0;
    for (unsigned i = 1; i < n - 1; i++) avg += s[i] / (n - 2);
    cout << setiosflags(ios::fixed) << setprecision(2) << avg << endl;
  }
  return 0;
}