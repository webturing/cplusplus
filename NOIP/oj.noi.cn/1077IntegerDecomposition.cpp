#include <bits/stdc++.h>

using namespace std;
vector<int> s;

void dfs(int n, int start) {
    if (s.size() > 1 && accumulate(s.begin(), s.end(), 0) == n) {
        copy(s.begin(), s.end() - 1, ostream_iterator<int>(cout, "+"));
        cout << *s.rbegin() << endl;
        return;
    }

    for (int k = start; k <= n; k++)
        if (accumulate(s.begin(), s.end(), 0) + k <= n && (s.empty() || k >= *s.rbegin())) {
            s.push_back(k);
            dfs(n, k);
            s.pop_back();
        }
}

int main(int argc, char const *argv[]) {
    int n = 7;

    dfs(n, 1);

    return 0;
}