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
    vector<int> f(26, 0);
    for (int i = 0; i < 4; i++) {
        getline(cin, s);
        for (auto c:s) {
            if (isalpha(c))
                f[toupper(c) - 'A']++;
        }
    }
    int max = *max_element(f.begin(), f.end());
    vector<vector<char> > g(max, vector<char>(26, ' '));
    for (int i = 0; i < 26; i++)
        for (int j = 0; j < f[i]; j++)
            g[max - 1 - j][i] = '*';
    for (int i = 0; i < g.size(); i++) {
        copy(g[i].begin(), g[i].end(), ostream_iterator<char>(cout, " "));
        cout << endl;
    }
    cout << "A B C D E F G H I J K L M N O P Q R S T U V W X Y Z " << endl;

#ifdef LOCAL
    LL end = clock();
    printf("%.3f\n", (double) (end - start) / CLOCKS_PER_SEC);
#endif
    return 0;
}
