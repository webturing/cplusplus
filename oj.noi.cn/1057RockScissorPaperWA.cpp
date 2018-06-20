#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
#define LOCAL
map<pair<char, char>, char> f;

void game(vector<vector<char> > &v);

void fill();

int main(int argc, char const *argv[]) {
    std::ios::sync_with_stdio(false);
#ifdef LOCAL
    ifstream cin("input.txt");
    //ofstream cout("output.txt");
    assert(cin);
    LL start = clock();
#endif
    fill();
    int r, c, n;
    cin >> r >> c >> n;
    vector<vector<char> > v(r, vector<char>(c));
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> v[i][j];
    while (n--)game(v);
    for (int i = 0; i < r; i++) {
        copy(v[i].begin(), v[i].end(), ostream_iterator<char>(cout, ""));
        cout << endl;
    }
#ifdef LOCAL
    LL end = clock();
    printf("%.3f\n", (double) (end - start) / CLOCKS_PER_SEC);
#endif
    return 0;
}

void game(vector<vector<char> > &v) {
    for (int i = 0; i < v.size(); i++)
        for (int j = 0; j < v[i].size(); j++) {
            if (i > 0) { v[i][j] = v[i - 1][j] = f[make_pair(v[i][j], v[i - 1][j])]; }
            if (i < v.size() - 1) { v[i][j] = v[i + 1][j] = f[make_pair(v[i][j], v[i + 1][j])]; }
            if (j > 0) { v[i][j] = v[i][j - 1] = f[make_pair(v[i][j], v[i][j - 1])]; }
            if (j < v[i].size() - 1) { v[i][j] = v[i][j + 1] = f[make_pair(v[i][j], v[i][j + 1])]; }
        }

}

void fill() {
    string a = "RSP";
    for (int i = 0; i < a.length(); i++)
        for (int j = 0; j < a.length(); j++) {
            if (i == j)f[make_pair(a[i], a[j])] = a[i];
            else if ((i - j + 3) % 3 == 1)
                f[make_pair(a[i], a[j])] = a[j];
            else
                f[make_pair(a[i], a[j])] = a[i];
        }
#ifdef LOCAL
    for (auto i:f)
        cout << i.first.first << ":" << i.first.second << "=" << i.second << endl;
#endif
}