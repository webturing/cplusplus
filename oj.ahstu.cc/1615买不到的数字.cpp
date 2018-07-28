#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

string fmt(const double exp, int scale = 6) {
    ostringstream os;
    os << fixed << setprecision(scale) << exp;
    return os.str();
}

#define LOCAL

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
#ifdef LOCAL
    ifstream cin("input.txt");
    assert(cin);
    LL start = clock();
#endif
    int a, b;
    cin >> a >> b;
    vector<int> v(2 * a * b + 1, false);
    for (int i = 0; i <= b; i++)
        for (int j = 0; j <= a; j++) {
            v[i * a + j * b] = true;
        }
    v.resize(a * b);
    for (int m = a * b - 1; m >= 0; m--) {
        if (!v[m]) {
            cout << m << endl;
            break;
        }
    }


#ifdef LOCAL
    LL end = clock();
    cout << "Elapsed " << fmt((double) (end - start) / CLOCKS_PER_SEC) << endl;
#endif
    return 0;
}
