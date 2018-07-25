#include <bits/stdc++.h>

using namespace std;


vector<int> v;
vector<pair<int, int>> Q;

int inc(int &x) { ++x; }

bool check() {
    for (auto q:Q) {
        int left = q.first, right = q.second;
        vector<int> dup(v.begin() + left, v.begin() + right + 1);
        sort(dup.begin(), dup.end());
        if (unique(dup.begin(), dup.end()) != dup.end())
            return false;
    }
    return true;

}

int main(int argc, char const *argv) {
    ifstream cin("input.txt");
    int T;
    cin >> T;
    while (T--) {
        int n, q;
        cin >> n >> q;
        v.resize(n + 1);
        fill(v.begin(), v.end(), 1);
        Q.resize(q);
        for (auto &e:Q)cin >> e.first >> e.second;
        sort(Q.begin(), Q.end());
        for (auto e:Q) {
            int left = e.first, right = e.second;
            for (int i = left; i <= right; i++)
                v[i] = i - left + 1;
            while (!check(left, right))
                for_each(v.begin() + left, v.begin() + right + 1, inc);

        }

        for (int i = 1; i <= n; i++)
            cout << v[i] << " ";
        cout << endl;

    }
    return 0;
}
