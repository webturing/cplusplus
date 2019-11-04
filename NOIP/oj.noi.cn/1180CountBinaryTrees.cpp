#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long LL;

string fmt(const double exp, int scale = 6) {
    ostringstream os;
    os << setiosflags(ios::fixed) << setprecision(scale) << exp;
    return os.str();
}

LL C(int n) {
    if (n == 1)
        return 1;
    return C(n - 1) * (4 * n - 2) / (n + 1);
}

//#define LOCAL

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
#ifdef LOCAL
    ifstream cin("input.txt");
    assert(cin);
    LL start = clock();
#endif
    int n;
    cin >> n;
    cout << C(n) << endl;

#ifdef LOCAL
    LL end = clock();
    cout << "Elapsed " << fmt((double) (end - start) / CLOCKS_PER_SEC) << endl;
#endif
    return 0;
}