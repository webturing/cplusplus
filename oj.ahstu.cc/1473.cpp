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
    int n;
    cin >> hex >> n;
    cout << setiosflags(ios::uppercase) << hex << n << " "
         << dec << n << " "
         << oct << n << endl;

#ifdef LOCAL
    LL end = clock();
    cout << "Elapsed " << fmt((double) (end - start) / CLOCKS_PER_SEC) << endl;
#endif
    return 0;
}
