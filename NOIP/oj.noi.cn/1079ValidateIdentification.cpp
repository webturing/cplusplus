#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
#define LOCAL

bool ok(string s) {
    if (s[0] != '_' && !isalpha(s[0]))
        return false;
    for (int i = 1; i < s.length(); i++)
        if (s[i] != '_' && !isalnum(s[i]))
            return false;
    return true;
}

int main(int argc, char const *argv[]) {
    std::ios::sync_with_stdio(false);
#ifdef LOCAL
    ifstream cin("input.txt");
    //ofstream cout("output.txt");
    assert(cin);
    LL start = clock();
#endif
    string s;
    cin >> s;
    cout << (ok(s) ? "yes" : "no") << endl;

#ifdef LOCAL
    LL end = clock();
    printf("%.3f\n", (double) (end - start) / CLOCKS_PER_SEC);
#endif
    return 0;
}
