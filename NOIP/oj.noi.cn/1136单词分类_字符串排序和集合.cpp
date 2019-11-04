#include<bits/stdc++.h>

using namespace std;
#define LOCAL

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    ifstream cin("input.txt");
    assert(cin);
    long long start = clock();
#endif

    int n;
    cin >> n;
    set<string> S;
    for (string s; n-- && cin >> s;) {
        sort(s.begin(), s.end());
        S.insert(s);
    }
    cout << S.size() << endl;

#ifdef LOCAL
    long long end = clock();
    cerr << (end - start) / CLOCKS_PER_SEC << endl;
#endif

    return 0;
}