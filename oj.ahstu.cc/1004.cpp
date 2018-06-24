#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

string fmt(const double exp, int scale = 6) {
    ostringstream os;
    os << setiosflags(ios::fixed) << setprecision(scale) << exp;
    return os.str();
}

#define LOCAL

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
#ifdef LOCAL
    ifstream cin("input.txt");
    assert(cin);
    LL start = clock();
#endif
    vector<int> v(4);
    cin >> v[0] >> v[1] >> v[2] >> v[3];
    sort(v.begin(), v.end(), [](int a, int b) -> bool { return a < b; });
    //copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    for (int i = 0; i < v.size(); i++) {
        vector<int> a(v);
        a.erase(a.begin() + v.size() - 1 - i);
        do {
            cout << a[0] << " " << a[1] << " " << a[2] << endl;
        } while (next_permutation(a.begin(), a.end()));

    }

#ifdef LOCAL
    LL end = clock();
    cout << "Elapsed " << fmt((double) (end - start) / CLOCKS_PER_SEC) << endl;
#endif
    return 0;
}
