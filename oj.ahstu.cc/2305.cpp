#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

string fmt(const double exp, int scale = 6) {
    ostringstream os;
    os << setiosflags(ios::fixed) << exp;
    return os.str();
}

#define LOCAL

int main(int argc, char const *argv[]) {
    std::ios::sync_with_stdio(false);
#ifdef LOCAL
    ifstream cin("input.txt");
    assert(cin);
    LL start = clock();
#endif
    vector<int> v(10);
    for (auto &i:v) { cin >> i; }
    int k;
    cin >> k;
    auto pos = binary_search(v.begin(), v.end(), k);
    if (pos == NULL) {
        cout << "Not exist!" << endl;
    } else {
        cout << lower_bound(v.begin(), v.end(), k) - v.begin() << endl;
    }
#ifdef LOCAL
    LL end = clock();
    cerr << "Elapsed(s):" << fmt((double) (end - start) / CLOCKS_PER_SEC) << endl;
#endif
    return 0;
}
